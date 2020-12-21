


 typedef struct _HIDD_ATTRIBUTES{
  ULONG Size;
  USHORT VendorID;
  USHORT ProductID;
  USHORT VersionNumber;
 } HIDD_ATTRIBUTES, *PHIDD_ATTRIBUTES;

 typedef USHORT USAGE;
 typedef struct _HIDP_CAPS {
  USAGE Usage;
  USAGE UsagePage;
  USHORT InputReportByteLength;
  USHORT OutputReportByteLength;
  USHORT FeatureReportByteLength;
  USHORT Reserved[17];
  USHORT fields_not_used_by_hidapi[10];
 } HIDP_CAPS, *PHIDP_CAPS;
 typedef char* HIDP_PREPARSED_DATA;
 #define HIDP_STATUS_SUCCESS 0x0

 typedef BOOLEAN (__stdcall *HidD_GetAttributes_)(HANDLE device, PHIDD_ATTRIBUTES attrib);
 typedef BOOLEAN (__stdcall *HidD_GetSerialNumberString_)(HANDLE device, PVOID buffer, ULONG buffer_len);
 typedef BOOLEAN (__stdcall *HidD_GetManufacturerString_)(HANDLE handle, PVOID buffer, ULONG buffer_len);
 typedef BOOLEAN (__stdcall *HidD_GetProductString_)(HANDLE handle, PVOID buffer, ULONG buffer_len);
 typedef BOOLEAN (__stdcall *HidD_SetFeature_)(HANDLE handle, PVOID data, ULONG length);
 typedef BOOLEAN (__stdcall *HidD_SetOutputReport_)(HANDLE handle, PVOID data, ULONG length);
 typedef BOOLEAN (__stdcall *HidD_GetFeature_)(HANDLE handle, PVOID data, ULONG length);
 typedef BOOLEAN (__stdcall *HidD_GetIndexedString_)(HANDLE handle, ULONG String_index, PVOID buffer, ULONG buffer_len);
 typedef BOOLEAN (__stdcall *HidD_GetPreparsedData_)(HANDLE handle, HIDP_PREPARSED_DATA **preparsed_data);
 typedef BOOLEAN (__stdcall *HidD_FreePreparsedData_)(HIDP_PREPARSED_DATA *preparsed_data);
 typedef BOOLEAN (__stdcall *HidP_GetCaps_)(HIDP_PREPARSED_DATA *preparsed_data, HIDP_CAPS *caps);

 static HidD_GetAttributes_ HidD_GetAttributes;
 static HidD_GetSerialNumberString_ HidD_GetSerialNumberString;
 static HidD_GetManufacturerString_ HidD_GetManufacturerString;
 static HidD_GetProductString_ HidD_GetProductString;
 static HidD_SetFeature_ HidD_SetFeature;
 static HidD_SetFeature_ HidD_SetOutputReport;
 static HidD_GetFeature_ HidD_GetFeature;
 static HidD_GetIndexedString_ HidD_GetIndexedString;
 static HidD_GetPreparsedData_ HidD_GetPreparsedData;
 static HidD_FreePreparsedData_ HidD_FreePreparsedData;
 static HidP_GetCaps_ HidP_GetCaps;

 static HMODULE lib_handle = NULL;
 static BOOLEAN initialized = FALSE;


HMODULE hDill32;
void loadHIDdill() {
 hDill32 = LoadLibraryW(L"hid.dll");
 if (hDill32) {
#define RESOLVE(x) x = (x##_)GetProcAddress(hDill32, #x); if (!x) return;
  RESOLVE(HidD_GetAttributes);
  RESOLVE(HidD_GetSerialNumberString);
  RESOLVE(HidD_GetManufacturerString);
  RESOLVE(HidD_GetProductString);
  RESOLVE(HidD_SetFeature);
  RESOLVE(HidD_SetOutputReport);
  RESOLVE(HidD_GetFeature);
  RESOLVE(HidD_GetIndexedString);
  RESOLVE(HidD_GetPreparsedData);
  RESOLVE(HidD_FreePreparsedData);
  RESOLVE(HidP_GetCaps);
#undef RESOLVE
 }
} void exitHIDdill() {
 FreeLibrary(hDill32);hDill32 = NULL;
}


HANDLE wyndham;

static HANDLE open_device(const char *path)
{
 HANDLE handle;
 handle = CreateFileA(path,
  GENERIC_WRITE|GENERIC_READ,
  FILE_SHARE_WRITE|FILE_SHARE_READ,
  NULL,
  OPEN_EXISTING,
  FILE_ATTRIBUTE_NORMAL,//FILE_FLAG_OVERLAPPED,//FILE_ATTRIBUTE_NORMAL,
  0);
 if (handle == INVALID_HANDLE_VALUE) {
  //printf("cooked\n");
  handle = CreateFileA(path,
   GENERIC_WRITE |GENERIC_READ,
   FILE_SHARE_READ|FILE_SHARE_WRITE, /*share mode*/
   NULL,
   OPEN_EXISTING,
   FILE_ATTRIBUTE_NORMAL,//FILE_FLAG_OVERLAPPED,//FILE_ATTRIBUTE_NORMAL,
   0);
 }
 return handle;
}

struct hid_device_ {
  HANDLE device_handle;
  //int PID;
  BOOL blocking;
  size_t input_report_length;
  void *last_error_str;
  DWORD last_error_num;
  BOOL read_pending;
  char *read_buf;
  OVERLAPPED ol;
};
typedef struct hid_device_ hid_device;
typedef long NTSTATUS; 

static hid_device *new_hid_device() {
	hid_device *dev = (hid_device*) calloc(1, sizeof(hid_device));
	dev->device_handle = INVALID_HANDLE_VALUE;
	dev->blocking = TRUE;
	dev->input_report_length = 0;
	dev->last_error_str = NULL;
	dev->last_error_num = 0;
	dev->read_pending = FALSE;
	dev->read_buf = NULL;
	memset(&dev->ol, 0, sizeof(dev->ol));
	dev->ol.hEvent = CreateEvent(NULL, FALSE, FALSE /*inital state f=nonsignaled*/, NULL);
	return dev;
}


hid_device * hid_open_path(const char *path) {
 hid_device *dev;
 HIDP_CAPS caps;
 HIDP_PREPARSED_DATA *pp_data = NULL;
 BOOLEAN res;
 NTSTATUS nt_res;

 dev = new_hid_device();
 dev->device_handle = open_device(path);
 if (dev->device_handle == INVALID_HANDLE_VALUE) {
  //wprintf(L"ErroeurCreateFile");
  goto err;
 }
 res = HidD_GetPreparsedData(dev->device_handle, &pp_data);
 if (!res)  goto err;
 nt_res = HidP_GetCaps(pp_data, &caps);
 if (nt_res != HIDP_STATUS_SUCCESS)  goto err_pp_data;
 dev->input_report_length = caps.InputReportByteLength;
 HidD_FreePreparsedData(pp_data);
 dev->read_buf = (char*) malloc(dev->input_report_length);
 return dev;
err_pp_data:
  HidD_FreePreparsedData(pp_data);
err: 
  CloseHandle(dev->device_handle);
  free(dev);
  return NULL;
}

struct hid_device_info {
   char *path;
   unsigned short vendor_id;
   unsigned short product_id;
   wchar_t *serial_number;
   unsigned short release_number;
   wchar_t *manufacturer_String;
   wchar_t *product_String;
   unsigned short usage_page;
   unsigned short usage;
   int interface_number;
   struct hid_device_info *next;
};


int HIDgetPID() {
	return 0x6666;
}

struct hid_device_info * hid_enumerate(unsigned short vendor_id, unsigned short product_id) {
 loadHIDdill();
 
 BOOL res;
 struct hid_device_info *root = NULL; // return object
 struct hid_device_info *cur_dev = NULL;
 
 GUID InterfaceClassGuid = {0x4d1e55b2, 0xf16f, 0x11cf, {0x88, 0xcb, 0x00, 0x11, 0x11, 0x00, 0x00, 0x30} };
 SP_DEVINFO_DATA devinfo_data;
 SP_DEVICE_INTERFACE_DATA device_interface_data;
 SP_DEVICE_INTERFACE_DETAIL_DATA_A *device_interface_detail_data = NULL;
 HDEVINFO device_info_set = INVALID_HANDLE_VALUE;
 int device_index = 0;
 devinfo_data.cbSize = sizeof(SP_DEVINFO_DATA);
 device_interface_data.cbSize = sizeof(SP_DEVICE_INTERFACE_DATA);
 device_info_set = SetupDiGetClassDevsA(&InterfaceClassGuid, NULL, NULL, DIGCF_PRESENT | DIGCF_DEVICEINTERFACE);
 
 for (;;) {
  HANDLE write_handle = INVALID_HANDLE_VALUE;
  DWORD required_size = 0;
  HIDD_ATTRIBUTES attrib;

  res = SetupDiEnumDeviceInterfaces(device_info_set,
   NULL, &InterfaceClassGuid, device_index,
   &device_interface_data);

  if (!res) break; 
  res = SetupDiGetDeviceInterfaceDetailA(device_info_set,
   &device_interface_data, NULL, 0, &required_size,
   NULL);
  device_interface_detail_data = (SP_DEVICE_INTERFACE_DETAIL_DATA_A*) malloc(required_size);
  device_interface_detail_data->cbSize = sizeof(SP_DEVICE_INTERFACE_DETAIL_DATA_A);
  res = SetupDiGetDeviceInterfaceDetailA(device_info_set,
   &device_interface_data, device_interface_detail_data,
   required_size, NULL, NULL);
  if (!res) goto cont;
  //wprintf(L"HandleName: %s\n", device_interface_detail_data->DevicePath);
  write_handle = open_device(device_interface_detail_data->DevicePath);
  if (write_handle == INVALID_HANDLE_VALUE)  goto cont_close;
  attrib.Size = sizeof(HIDD_ATTRIBUTES);
  HidD_GetAttributes(write_handle, &attrib);
  //wprintf(L"Product/Vendor: %x %x\n", attrib.ProductID, attrib.VendorID);
  if ((vendor_id == 0x0 && product_id == 0x0) || 
   (attrib.VendorID == vendor_id && attrib.ProductID == product_id)) {
   #define WSTR_LEN 512
   const char *str;
   struct hid_device_info *tmp;
   HIDP_PREPARSED_DATA *pp_data = NULL;
   HIDP_CAPS caps;
   BOOLEAN res;
   NTSTATUS nt_res;
   wchar_t wstr[WSTR_LEN]; // TODO: Determine Size
   size_t len;
   tmp = (struct hid_device_info*) calloc(1, sizeof(struct hid_device_info));
   if (cur_dev)  cur_dev->next = tmp;
   else root = tmp;
   cur_dev = tmp;
   res = HidD_GetPreparsedData(write_handle, &pp_data);
   if (res) {
    nt_res = HidP_GetCaps(pp_data, &caps);
    if (nt_res == HIDP_STATUS_SUCCESS) {
     cur_dev->usage_page = caps.UsagePage;
     cur_dev->usage = caps.Usage;
    }
    HidD_FreePreparsedData(pp_data);
   }
   cur_dev->next = NULL;
   str = device_interface_detail_data->DevicePath;
   if (str) {
    len = strlen(str);
    cur_dev->path = (char*) calloc(len+1, sizeof(char));
    strncpy(cur_dev->path, str, len+1);
    cur_dev->path[len] = '\0';
   }
   else cur_dev->path = NULL;
   res = HidD_GetSerialNumberString(write_handle, wstr, sizeof(wstr));
   wstr[WSTR_LEN-1] = 0x0000;
   if (res)  cur_dev->serial_number = _wcsdup(wstr);
   res = HidD_GetManufacturerString(write_handle, wstr, sizeof(wstr));
   wstr[WSTR_LEN-1] = 0x0000;
   if (res)  cur_dev->manufacturer_String = _wcsdup(wstr);
   //wprintf(L"Manu: %s\n", cur_dev->manufacturer_String);
   res = HidD_GetProductString(write_handle, wstr, sizeof(wstr));
   wstr[WSTR_LEN-1] = 0x0000;
   if (res)  cur_dev->product_String = _wcsdup(wstr);
   //wprintf(L"Prod: %s\n", cur_dev->manufacturer_String);
   cur_dev->vendor_id = attrib.VendorID;
   cur_dev->product_id = attrib.ProductID;
   cur_dev->release_number = attrib.VersionNumber;
   cur_dev->interface_number = -1;
   if (cur_dev->path) {
    char *interface_component = strstr(cur_dev->path, "&mi_");
    if (interface_component) {
     char *hex_str = interface_component + 4;
     char *endptr = NULL;
     cur_dev->interface_number = strtol(hex_str, &endptr, 16);
     if (endptr == hex_str) {
      /* The parsing failed. Set interface_number to -1. */
      cur_dev->interface_number = -1;
     }
    }
   }
  }
cont_close:
  CloseHandle(write_handle);
cont:
  free(device_interface_detail_data);
  device_index++;
  
 }
  
 SetupDiDestroyDeviceInfoList(device_info_set); 
 return root;
}

void hid_free_enumeration(struct hid_device_info *devs)
{
	// TODO: Merge this with the Linux version. This function is platform-independent.
	struct hid_device_info *d = devs;
	while (d) {
		struct hid_device_info *next = d->next;
		free(d->path);
		free(d->serial_number);
		free(d->manufacturer_String);
		free(d->product_String);
		free(d);
		d = next;
	}
}


hid_device * handhold = NULL;

void Chub::chubCLOZ(){}
bool Chub::chubINIT(){
 handhold = NULL;
 struct hid_device_info *devs, *cur_dev;
 const char *path_to_open = NULL;
 //hid_device *handle = NULL;
 devs = hid_enumerate(0,0);//(0x6666, 0x6666);
 cur_dev = devs;
    
 while (cur_dev) {
  if (cur_dev->vendor_id == 0x6666){
    path_to_open = cur_dev->path;
	gwonzINIT(cur_dev->product_id);
	handhold = hid_open_path(path_to_open);
	hid_free_enumeration(devs);
    return true;
  }
  cur_dev = cur_dev->next;
 }
 gwonzINIT(0);
 hid_free_enumeration(devs);
 return false;
}

static signed char gwonzus[9];
void Chub::chubRUN() {
 DWORD bytes_read = 0;
 BOOL res;
 //HANDLE ev = handhold->ol.hEvent;
 //printf("conk\n");
 while(handhold != NULL) {
  if (chubShouldEnd()) return;
  res = ReadFile(handhold->device_handle, gwonzus, handhold->input_report_length, &bytes_read, NULL);//&handhold->ol);
  if (res) {
   for (int i = 0; i < 8; i++) 
    gwonz[i] = gwonzus[i+1];
   chubCALL();
  }
 } 
}

void Chub::chubSENDATE(unsigned char * rept)  {
 static unsigned char quonz[9]; 
 quonz[0] = 0;
 for (int i = 0; i < 8; i++)
  quonz[i+1] = rept[i];
 while ((handhold != NULL) && (handhold->device_handle)) {
  if (chubShouldEnd()) return;
  BOOL res;
  res = HidD_SetFeature(handhold->device_handle, 
   (PVOID)quonz, 8+1);
  if (res)  return; 
 }
}

void Chub::chubSENDEND()  {
 static unsigned char quonz[9]; 
 static int amountus;
 amountus = 9;
 quonz[0] = 0;
 while ((handhold != NULL) && (handhold->device_handle)) {
  if (chubShouldEnd()) return;
  BOOL res;
  res = HidD_GetFeature(handhold->device_handle, 
   (PVOID)quonz, amountus);
  if (res)  return; 
 }
}

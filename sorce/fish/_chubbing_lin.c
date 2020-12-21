

typedef struct libusb_device_handle *CHUBHANDLE;
#define VENDOR_ID 0x6666
const static int TIMEOUT=5000;
const static int ENDPOINT_INT_IN=0x81;
const static int ENDPOINT_INT_OUT=0x01;
CHUBHANDLE devh = NULL;
#define lodewivipi libusb_open_device_with_vid_pid

bool Chub::chubINIT() {
 devh = 0;
 libusb_init(NULL);
 devh=lodewivipi(NULL, VENDOR_ID, 0x6666); 
 if (devh) {
  gwonzINIT(0x6666);
  libusb_detach_kernel_driver(devh, 0);   
  libusb_set_configuration(devh, 1); 
  libusb_claim_interface(devh, 0); 
  return true;
 }
 devh=lodewivipi(NULL, VENDOR_ID, 0x7777);
 if (devh) {
  gwonzINIT(0x7777);
  libusb_detach_kernel_driver(devh, 0);   
  libusb_set_configuration(devh, 1); 
  libusb_claim_interface(devh, 0); 
  return true;
 }
 gwonzINIT(0);
 return false;
}

void Chub::chubCLOZ() {
 if (!devh) return;
 libusb_release_interface(devh, 0); 
 libusb_close(devh);
 devh = 0;
 libusb_exit(NULL); 
}

libusb_transfer* trance;
void chub_callback(libusb_transfer* te) {
 if (te->user_data==NULL) return;
 static_cast<Chub*>(te->user_data)->chubCALL();
 libusb_submit_transfer(trance);
}

void Chub::chubRUN() { 
 if (!devh) return;
 trance = libusb_alloc_transfer(0);
 libusb_fill_interrupt_transfer(trance,devh,
  ENDPOINT_INT_IN,(unsigned char *)gwonz,
  8,chub_callback,this,TIMEOUT);
 libusb_submit_transfer(trance);
 while(!chubShouldEnd()) 
  libusb_handle_events_completed(NULL,NULL);
}



void Chub::chubSENDATE(unsigned char * rept)  {
 int rc;
 while (devh) {
  if(libusb_control_transfer(devh,0x20,0x09,0,0,rept,8,0)==8)return;
  if (chubShouldEnd()) return;
 }
}

void Chub::chubSENDEND()  {
 static unsigned char edible[8];
 while (devh) {
  if(libusb_control_transfer(devh,0xA0,0x01,0,0,edible,8,0)==8)return;
  if (chubShouldEnd()) return;
 }
}



//static int hotcount = 0;
/*int hotplug_callback(struct libusb_context *ctx, 
struct libusb_device *dev,
libusb_hotplug_event event, 
void *user_data) {
 Chain * c = static_cast<Chain*>(user_data);
 struct libusb_device_descriptor desc;
 int rc;
 libusb_get_device_descriptor(dev, &desc);
 if ((LIBUSB_HOTPLUG_EVENT_DEVICE_ARRIVED == event) 
  && (desc.idVendor==0x6666)) 
  c->matchCallback(dev);
 else if ((LIBUSB_HOTPLUG_EVENT_DEVICE_LEFT == event) 
  && (desc.idVendor==0x6666))
  c->removeCallback(dev); 
 return 0;
}

libusb_hotplug_callback_handle hothandle;

*/


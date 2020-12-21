typedef struct libusb_device_handle *CHUBHANDLE;

typedef struct _CHUBREPORT {
 char * report;
 unsigned int length;
} CHUBREPORT;

 #define VERSION "0.1.0" 
 #define VENDOR_ID 0x6666
 #define PRODUCT_ID 0x6666 
 // HID Class-Specific Requests values. See section 7.2 of the HID specifications 
 #define HID_GET_REPORT                0x01 
 #define HID_GET_IDLE                  0x02 
 #define HID_GET_PROTOCOL              0x03 
 #define HID_SET_REPORT                0x09 
 #define HID_SET_IDLE                  0x0A 
 #define HID_SET_PROTOCOL              0x0B 
 #define HID_REPORT_TYPE_INPUT         0x01 
 #define HID_REPORT_TYPE_OUTPUT        0x02 
 #define HID_REPORT_TYPE_FEATURE       0x03 
 
 const static int PACKET_INT_LEN=6; 
 const static int INTERFACE=0; 
 const static int ENDPOINT_INT_IN=0x81; /* endpoint 0x81 address for IN */ 
 const static int ENDPOINT_INT_OUT=0x01; /* endpoint 1 address for OUT */ 
 const static int TIMEOUT=5000; /* timeout in ms */ 
 CHUBHANDLE devh = NULL;
  CHUBREPORT chuddle;
static signed char gwonz[8];

libusb_transfer* trance;
int grax_countor;
void chub_callback(libusb_transfer* te);
int gwonzIntegral[4];
signed char lastByte;
void chub_callback(libusb_transfer* te) {
 for (int i = 0; i < 4; i++) {
  if (gwonz[i] > 4) {
   gwonzIntegral[i] += gwonz[i] - 4;
   if (gwonzIntegral[i] > 200)  {
    gwonzIntegral[i] = 0;
    fprintf(pipe, "i10%d 0 1\n", i);
   }
  }
 }
 char diff = lastByte^gwonz[7];
 for (int i = 0; i < 8; i++) {
  if (diff & 1<<i) {
   fprintf(pipe, "i1%d 0 1\n", i);
  }
 }
  lastByte = gwonz[7];
 fflush (pipe);
 chuddle.report = (char*)gwonz;
 chuddle.length = 8;

// abstr->chubness(devh,chuddle);
 if (grax_countor++ == 0)  {
  
  //grax_repaint();
 } grax_countor %= 16;
 libusb_submit_transfer(trance);
 
}

void chubSENDATE(unsigned char * rept)  {
 while (devh) 
  if(libusb_control_transfer(devh,0x20,0x09,0,0,rept,8,0)==8)return;
}

void chubSENDEND()  {
 static unsigned char edible[8];
 while (devh) 
  if(libusb_control_transfer(devh,0xA0,0x01,0,0,edible,8,0)==8)return;
}

void chubSEND(unsigned char * rept, int amountus) {
	if (amountus < 8) chubSENDEND();
	else chubSENDATE(rept);
}

void chubSENDz(unsigned char * rept, int amountus) {
 uint8_t bmreq = 0x20; //class out
 uint8_t breq = 0x08 + 0x01; //setreport
 if (amountus < 8) {
  bmreq += 0x80; //class in
  breq -= 0x08; //getreport
  amountus = 8;
 }
 while (devh) {
  int res = libusb_control_transfer(devh,
   bmreq, //bmRequestType
   breq, //bRequest
   0, //wVal = report id
   0, //wInd = interface#
   rept,
   amountus,
   0);
  if (res == amountus) return;
 }
}

void chubRUN() {
 trance = libusb_alloc_transfer(0);
  libusb_fill_interrupt_transfer(trance,devh,
    ENDPOINT_INT_IN,(unsigned char *)gwonz,8,chub_callback,NULL,TIMEOUT);
  libusb_submit_transfer(trance);
 while(1) {
  static timeval timeout = {0,0};
  libusb_handle_events_timeout(NULL,&timeout);
 }
}


void chubOPEN() {
 libusb_init(NULL); 
 devh = libusb_open_device_with_vid_pid(NULL, VENDOR_ID, PRODUCT_ID); 
 if (!devh) return;
 //printf("opend 6666");
 libusb_detach_kernel_driver(devh, 0);   
 libusb_set_configuration(devh, 1); 
 libusb_claim_interface(devh, 0); 
}

//void chubOPEN() {
// open_chub();
//}

void chubCLOZ() {
    libusb_release_interface(devh, 0); 
  //     libusb_reset_device(devh); 
  libusb_close(devh); 
  libusb_exit(NULL); 
}

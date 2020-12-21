#pragma once
#include "stdafx.h"
#include "AbstractChubEngine.h"

#if defined(BILLGATES)

void ChubInit() {
	RAWINPUTDEVICE Rid[1];
	Rid[0].usUsagePage = 0x01; 
	Rid[0].usUsage = 0x05; 
	Rid[0].dwFlags = 0;   
	Rid[0].hwndTarget = 0;
	if (RegisterRawInputDevices(Rid, 1, sizeof(Rid[0])) == FALSE) {}
}	

int chekHedr(HANDLE hdv) {
		RID_DEVICE_INFO devilio;
		devilio.cbSize = sizeof(RID_DEVICE_INFO);
		UINT dwSize = sizeof(RID_DEVICE_INFO);
		int outStringSz;
		UINT otherSzl = 16;
		char name[64];
		GetRawInputDeviceInfo(hdv, RIDI_DEVICEINFO, &devilio, &dwSize);
		outStringSz = GetRawInputDeviceInfoA(hdv, RIDI_DEVICENAME, name, &otherSzl);

		if (devilio.dwType == RIM_TYPEHID) {
			if (devilio.hid.dwVendorId == 26214) {
 				return 1;
			}
		}
			return 0;
	}

void ChubMassage(LPARAM lParam) {
	UINT dwSize;
	GetRawInputData((HRAWINPUT)lParam, RID_INPUT, NULL, &dwSize, sizeof(RAWINPUTHEADER));
	LPBYTE lpb = new BYTE[dwSize];
	//if (lpb == NULL) return 0;
	if (GetRawInputData((HRAWINPUT)lParam, RID_INPUT, lpb, &dwSize, sizeof(RAWINPUTHEADER)) != dwSize )
	OutputDebugString (TEXT("GetRawInputData doesn't return correct size !\n")); 
	RAWINPUT* raw = (RAWINPUT*)lpb;
	
	if (raw->header.dwType == RIM_TYPEHID) {
		if (chekHedr(raw->header.hDevice)) {
			if (raw->data.hid.dwSizeHid > 7) {
				BYTE * tyil;
				tyil = raw->data.hid.bRawData;
				static BYTE chons[8];
				for (int i = 0; i < 8; i++) 
					chons[i] = *(++tyil);

				static CHUBREPORT ripple = {chons, 8 };
				static CHUBHANDLE hondal  = raw->header.hDevice;
				abstr->chubness(hondal,ripple);
			}
		}
	}
	delete[] lpb; 
}

	void chekSituation() {
		RAWINPUTDEVICELIST ridl[100];
		int uiNumDevices;
		UINT uiMemReserved;
 		uiNumDevices = GetRawInputDeviceList(ridl, &uiMemReserved, sizeof(RAWINPUTDEVICELIST));
		const UINT numChars = 100;
			CHAR szDeviceName[numChars];
			UINT cbSize = numChars;
			int outttt;
		for (int o = 0; o < uiNumDevices; o++) {
			
			if (ridl[o].dwType == 2)
   				outttt = GetRawInputDeviceInfoA(ridl[o].hDevice, RIDI_DEVICENAME, szDeviceName, &cbSize);
		}
	}



#elif defined(STEVEJOBS)


static void Handle_IOHIDDeviceIOHIDReportCallback(
												  void *          inContext,          // context from IOHIDDeviceRegisterInputReportCallback
												  IOReturn        inResult,           // completion result for the input report operation
												  void *          inSender,           // IOHIDDeviceRef of the device this report is from
												  IOHIDReportType inType,             // the report type
												  uint32_t        inReportID,         // the report ID
												  uint8_t *       inReport,           // pointer to the report data
												  CFIndex         inReportLength)     // the actual size of the input report
;

static IOHIDManagerRef gIOHIDManagerRef;

void ChubChingLoop() {
	CHUBHANDLE * refs = 0;
	if (gIOHIDManagerRef) {
		CFSetRef devCFSetRef = IOHIDManagerCopyDevices( gIOHIDManagerRef );
		if (devCFSetRef) {
			CFIndex amountus = CFSetGetCount(devCFSetRef);
			refs = (IOHIDDeviceRef*)(malloc(sizeof(IOHIDDeviceRef)*amountus));
			CFSetGetValues(devCFSetRef, (const void**)refs);
			CFIndex idx;
			for ( idx = 0; idx < amountus; idx++ ) {
				CFIndex reportSize = 64;    // note: this should be greater than or equal to the size of the report
				uint8_t * report = (uint8_t*)(malloc(reportSize));
				IOHIDDeviceRegisterInputReportCallback(refs[idx], 
													  report, reportSize, Handle_IOHIDDeviceIOHIDReportCallback,NULL);      
			}
			//abstr->chubching(refs,amountus);
		}
	}	
}



static void Handle_DeviceMatchingCallback( void * inContext, 
	IOReturn inResult, void * inSender, IOHIDDeviceRef inIOHIDDeviceRef ) {
#pragma unused (  inContext, inSender )
	//CFIndex reportSize = 64;    
	// note: this should be greater than or equal to the size of the report
	//uint8_t * report = (uint8_t*)(malloc(reportSize));
	//IOHIDDeviceRegisterInputReportCallback(inIOHIDDeviceRef, 
	//									   report, reportSize, Handle_IOHIDDeviceIOHIDReportCallback,NULL);      
	ChubChingLoop();
}   // Handle_DeviceMatchingCallback

static void Handle_DeviceRemovalCallback( void * inContext, 
	IOReturn inResult, void * inSender, IOHIDDeviceRef inIOHIDDeviceRef ) {
#pragma unused (  inContext, inResult, inSender )
	ChubChingLoop();
}   // Handle_DeviceRemovalCallback

static void Handle_IOHIDDeviceIOHIDReportCallback(
												  void *          inContext,          // context from IOHIDDeviceRegisterInputReportCallback
												  IOReturn        inResult,           // completion result for the input report operation
												  void *          inSender,           // IOHIDDeviceRef of the device this report is from
												  IOHIDReportType inType,             // the report type
												  uint32_t        inReportID,         // the report ID
												  uint8_t *       inReport,           // pointer to the report data
												  CFIndex         inReportLength)     // the actual size of the input report
{
    static CHUBREPORT ripple = { inReport, inReportLength };
	static CHUBHANDLE hondal = (CHUBHANDLE)inSender;
	abstr->chubness(hondal,ripple);
	[view setNeedsDisplay:YES];
}   

static CFMutableDictionaryRef hu_SetUpMatchingDictionary( UInt32 inUsagePage, UInt32 inUsage )
{
	// create a dictionary to add usage page/usages to
	CFMutableDictionaryRef refHIDMatchDictionary = CFDictionaryCreateMutable( kCFAllocatorDefault, 0,
																			 &kCFTypeDictionaryKeyCallBacks, &kCFTypeDictionaryValueCallBacks );
	
	if ( refHIDMatchDictionary ) {
		if ( inUsagePage ) {
			// Add key for device type to refine the matching dictionary.
			CFNumberRef pageCFNumberRef = CFNumberCreate( kCFAllocatorDefault, kCFNumberIntType, &inUsagePage );
			
			if ( pageCFNumberRef ) {
				CFDictionarySetValue( refHIDMatchDictionary,
									 CFSTR( kIOHIDPrimaryUsagePageKey ), pageCFNumberRef );
				CFRelease( pageCFNumberRef );
				
				// note: the usage is only valid if the usage page is also defined
				if ( inUsage ) {
					CFNumberRef usageCFNumberRef = CFNumberCreate( kCFAllocatorDefault, kCFNumberIntType, &inUsage );
					
					if ( usageCFNumberRef ) {
						CFDictionarySetValue( refHIDMatchDictionary,
											 CFSTR( kIOHIDPrimaryUsageKey ), usageCFNumberRef );
						CFRelease( usageCFNumberRef );
					} else {
						fprintf( stderr, "%s: CFNumberCreate( usage ) failed.", __PRETTY_FUNCTION__ );
					}
				}
			} else {
				fprintf( stderr, "%s: CFNumberCreate( usage page ) failed.", __PRETTY_FUNCTION__ );
			}
		}
	} else {
		fprintf( stderr, "%s: CFDictionaryCreateMutable failed.", __PRETTY_FUNCTION__ );
	}
	return refHIDMatchDictionary;
}   // hu_SetUpMatchingDictionary



//static void CFSetApplierFunctionCopyToCFArray(const void *value, void *context)
//{
	// printf( "%s: 0x%08lX\n", __PRETTY_FUNCTION__, (long unsigned int) value );
//	CFArrayAppendValue( ( CFMutableArrayRef ) context, value );
//}	// CFSetApplierFunctionCopyToCFArray



void ChubSetup() {
	gIOHIDManagerRef = IOHIDManagerCreate( kCFAllocatorDefault, kIOHIDOptionsTypeNone );
	IOHIDManagerRegisterDeviceMatchingCallback( gIOHIDManagerRef, Handle_DeviceMatchingCallback, NULL );
	IOHIDManagerRegisterDeviceRemovalCallback( gIOHIDManagerRef, Handle_DeviceRemovalCallback, NULL );	
	if ( gIOHIDManagerRef ) {
		// schedule us with the run loop
		IOHIDManagerScheduleWithRunLoop( gIOHIDManagerRef, CFRunLoopGetCurrent( ), kCFRunLoopDefaultMode );
		// open it
		IOReturn tIOReturn = IOHIDManagerOpen( gIOHIDManagerRef, kIOHIDOptionsTypeNone );
		//CFMutableArrayRef hidMatchingCFMutableArrayRef = NULL;
		CFMutableDictionaryRef hidMatchingCFDictRef = hu_SetUpMatchingDictionary(kHIDPage_GenericDesktop, kHIDUsage_GD_GamePad );
		IOHIDManagerSetDeviceMatching(gIOHIDManagerRef,hidMatchingCFDictRef);
		
	}
}
#elif defined(LINUSTORWALDS)

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
void chub_callback(libusb_transfer* te) {
	//printf("callback");
	chuddle.report = (char*)gwonz;
	chuddle.length = 8;
	abstr->chubness(devh,chuddle);
	if (grax_countor++ == 0)  {
		
		grax_repaint();
	} grax_countor %= 16;
	libusb_submit_transfer(trance);
	
}

void chub_run() {
	static timeval timeout = {0,0};
	libusb_handle_events_timeout(NULL,&timeout);
}

void open_chub() {
     libusb_init(NULL); 
     devh = libusb_open_device_with_vid_pid(NULL, VENDOR_ID, PRODUCT_ID); 
     if (!devh) return;
     libusb_detach_kernel_driver(devh, 0);   
     libusb_set_configuration(devh, 1); 
     libusb_claim_interface(devh, 0); 

	trance = libusb_alloc_transfer(0);
	libusb_fill_interrupt_transfer(trance,devh,
		ENDPOINT_INT_IN,(unsigned char *)gwonz,8,chub_callback,NULL,TIMEOUT);
	libusb_submit_transfer(trance);
}

void chub_closz() {
    libusb_release_interface(devh, 0); 
	 //     libusb_reset_device(devh); 
	 libusb_close(devh); 
 	libusb_exit(NULL); 
}
#endif

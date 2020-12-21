typedef IOHIDDeviceRef CHUBHANDLE;

typedef struct _CHUBREPORT {
 uint8_t * report;
 CFIndex length;
} CHUBREPORT;


IOHIDDeviceRef mydev=NULL;

static void Handle_IOHIDDeviceIOHIDReportCallback(
 void * inContext, IOReturn inResult,  
 void * inSender, IOHIDReportType inType, 
 uint32_t inReportID, uint8_t * inReport, 
 CFIndex inReportLength);

static IOHIDManagerRef gIOHIDManagerRef = NULL;

typedef IOHIDDeviceRef CHUBHANDLE;

void ChubChingLoop() {
 CHUBHANDLE * refs = 0;
	mydev = NULL;
 if (gIOHIDManagerRef) {
  CFSetRef devCFSetRef = IOHIDManagerCopyDevices( gIOHIDManagerRef );
  if (devCFSetRef) {
   CFIndex amountus = CFSetGetCount(devCFSetRef);
   refs = (IOHIDDeviceRef*)(malloc(sizeof(IOHIDDeviceRef)*amountus));
   CFSetGetValues(devCFSetRef, (const void**)refs);
   //CFIndex idx;
   //for ( idx = 0; idx < amountus; idx++ ) {
   if ( amountus>0) {
    //CFIndex reportSize = 8;    
    //uint8_t * report = (uint8_t*)(malloc(reportSize));
    mydev = refs[0];
    IOHIDDeviceOpen(mydev, kIOHIDOptionsTypeNone);
	//IOHIDDeviceScheduleWithRunLoop(mydev, CFRunLoopGetCurrent(), kCFRunLoopDefaultMode );
	//IOHIDDeviceRegisterInputReportCallback(refs[idx], 
	// report, reportSize, Handle_IOHIDDeviceIOHIDReportCallback,NULL);    
   } free(refs);
  }
 } 
}

static void Handle_DeviceMatchingCallback( 
 void * inContext, IOReturn inResult, 
 void * inSender, IOHIDDeviceRef inIOHIDDeviceRef) {  
 printf("devmatch\n");
 ChubChingLoop();
}

static void Handle_DeviceRemovalCallback( void * inContext, 
           IOReturn inResult, void * inSender, IOHIDDeviceRef inIOHIDDeviceRef ) {
#pragma unused (  inContext, inResult, inSender )
 ChubChingLoop();
}

static void Handle_IOHIDDeviceIOHIDReportCallback(
 void * inContext, IOReturn inResult,  
 void * inSender, IOHIDReportType inType, 
 uint32_t inReportID, uint8_t * inReport, 
 CFIndex inReportLength) {
  if (inReportLength)// >= 8) 
	  //for (int i = 0; i < 8; i++) 
	//	  gwonz[i] = inReport[i];
	static_cast<Shnth*>(inContext)->shnthCALL();
}   

void Shnth::shnthSENDATE(uint8_t * outReport)  {
 while (mydev) {
  int returno = IOHIDDeviceSetReport(mydev, kIOHIDReportTypeOutput,
										   0,outReport,8);
  if (returno==kIOReturnSuccess) return; 
    if (shnthShouldEnd()) return;
 }
}
void Shnth::shnthSENDEND()  {
 static uint8_t edible[8];
 CFIndex sizzle = 8;
 while (mydev) {
  int returno = IOHIDDeviceGetReport(mydev, kIOHIDReportTypeFeature,
									 0,edible,&sizzle);
  if (returno==kIOReturnSuccess) return;  
  if (shnthShouldEnd()) return;
 }
}

static CFMutableDictionaryRef hu_SetUpMatchingDictionary( UInt32 inUsagePage, UInt32 inUsage ) {
 // create a dictionary to add usage page/usages to
 CFMutableDictionaryRef refHIDMatchDictionary = CFDictionaryCreateMutable( kCFAllocatorDefault, 0,
                    &kCFTypeDictionaryKeyCallBacks, &kCFTypeDictionaryValueCallBacks );
 if ( refHIDMatchDictionary ) {
  if ( inUsagePage ) {
   // Add key for device type to refine the matching dictionary.
   CFNumberRef pageCFNumberRef = CFNumberCreate( kCFAllocatorDefault, kCFNumberIntType, &inUsagePage );
   if ( pageCFNumberRef ) {
    CFDictionarySetValue( refHIDMatchDictionary,
          CFSTR( kIOHIDDeviceUsagePageKey ), pageCFNumberRef );
    CFRelease( pageCFNumberRef );
   }
  }
  if ( inUsage ) { // note: the usage is only valid if the usage page is also defined
   CFNumberRef usageCFNumberRef = CFNumberCreate( kCFAllocatorDefault, kCFNumberIntType, &inUsage );
   if ( usageCFNumberRef ) {
    CFDictionarySetValue( refHIDMatchDictionary,
          CFSTR( kIOHIDDeviceUsageKey ), usageCFNumberRef );
    CFRelease( usageCFNumberRef );
   }
  } //return refHIDMatchDictionary;
  UInt32 vendor_ID = 0x6666;
  CFNumberRef vidCFNumberRef = CFNumberCreate( kCFAllocatorDefault, kCFNumberIntType, &vendor_ID );
  if ( vidCFNumberRef ) {
   CFDictionarySetValue( refHIDMatchDictionary,
         CFSTR(kIOHIDVendorIDKey), vidCFNumberRef );
   CFRelease( vidCFNumberRef );
  }
  //UInt32 vendor_ID = 0x6666;
  //CFNumberRef vidCFNumberRef = CFNumberCreate( kCFAllocatorDefault, kCFNumberIntType, &vendor_ID );
  if ( vidCFNumberRef ) {
   CFDictionarySetValue( refHIDMatchDictionary,
         CFSTR(kIOHIDProductIDKey), vidCFNumberRef );
   CFRelease( vidCFNumberRef );
  }
  
 }
 return refHIDMatchDictionary;
} 

void Shnth::shnthOPEN() {
 gIOHIDManagerRef = IOHIDManagerCreate( kCFAllocatorDefault, kIOHIDOptionsTypeNone );
 IOHIDManagerRegisterDeviceMatchingCallback( gIOHIDManagerRef, Handle_DeviceMatchingCallback, NULL );
 IOHIDManagerRegisterDeviceRemovalCallback( gIOHIDManagerRef, Handle_DeviceRemovalCallback, NULL ); 
 if ( gIOHIDManagerRef ) {
  IOHIDManagerScheduleWithRunLoop( gIOHIDManagerRef, CFRunLoopGetCurrent( ), kCFRunLoopDefaultMode );
  //IOReturn tIOReturn = 
	 IOHIDManagerOpen( gIOHIDManagerRef, kIOHIDOptionsTypeNone );
  CFMutableDictionaryRef hidMatchingCFDictRef = hu_SetUpMatchingDictionary(kHIDPage_GenericDesktop, kHIDUsage_GD_GamePad );
  IOHIDManagerSetDeviceMatching(gIOHIDManagerRef,hidMatchingCFDictRef);
  ChubChingLoop();
 }
}
void Shnth::shnthCLOZ(){
	if (mydev) IOHIDDeviceClose(mydev,kIOHIDOptionsTypeNone);
	if (gIOHIDManagerRef) IOHIDManagerClose(gIOHIDManagerRef,kIOHIDOptionsTypeNone);
	gIOHIDManagerRef = NULL;
}

void Shnth::shnthRUN() {
	if (!mydev) return;
	IOHIDDeviceScheduleWithRunLoop(mydev, CFRunLoopGetCurrent(), kCFRunLoopDefaultMode );
	IOHIDDeviceRegisterInputReportCallback(mydev, 
	 (uint8_t*)gwonz, 8, Handle_IOHIDDeviceIOHIDReportCallback,this);    
	CFRunLoopRun();

}

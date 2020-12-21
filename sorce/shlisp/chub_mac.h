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

static IOHIDManagerRef gIOHIDManagerRef;

typedef IOHIDDeviceRef CHUBHANDLE;

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
    CFIndex reportSize = 8;    
    uint8_t * report = (uint8_t*)(malloc(reportSize));
    mydev = refs[idx];
    IOHIDDeviceOpen(mydev, kIOHIDOptionsTypeNone);
	//IOHIDDeviceScheduleWithRunLoop(mydev, CFRunLoopGetCurrent(), kCFRunLoopDefaultMode );
	IOHIDDeviceRegisterInputReportCallback(refs[idx], 
	 report, reportSize, Handle_IOHIDDeviceIOHIDReportCallback,NULL);    
   }
  }
 } 
}

static void Handle_DeviceMatchingCallback( 
 void * inContext, IOReturn inResult, 
 void * inSender, IOHIDDeviceRef inIOHIDDeviceRef) {  
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
   printf("%+.3d %+.3d %+.3d %+.3d %+.3d %+.3d %+.3d %+.3d\n",
    (signed char)inReport[0], (signed char)inReport[1],
    (signed char)inReport[2], (signed char)inReport[3],
    (signed char)inReport[4], (signed char)inReport[5],
    (signed char)inReport[6], (signed char)inReport[7]
   );
}   

void chubSENDATE(uint8_t * outReport)  {
 while (mydev) 
  if(IOHIDDeviceSetReport(mydev, kIOHIDReportTypeOutput,
   0,outReport,8)==kIOReturnSuccess) return;
}
void chubSENDEND()  {
 static uint8_t edible[8];
 CFIndex sizzle = 8;
 while (mydev) 
  if(IOHIDDeviceGetReport(mydev, kIOHIDReportTypeFeature,
	0,edible,&sizzle)==kIOReturnSuccess) return;
}

void chubSEND(uint8_t * outReport, int amountus) {
	if (amountus < 8) chubSENDEND();
	else chubSENDATE(outReport);
}
void chubSENDz(uint8_t * outReport, int amountus) {
 
while (mydev) {
	IOReturn res;
  CFIndex reportID = 0;
   CFIndex reportSize = amountus;
   res =IOHIDDeviceSetReport(mydev,
    kIOHIDReportTypeOutput,reportID,
    outReport,reportSize);
  if(res == kIOReturnSuccess) return;
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
//  if ( vidCFNumberRef ) {
//   CFDictionarySetValue( refHIDMatchDictionary,
//         CFSTR(kIOHIDProductIDKey), vidCFNumberRef );
//   CFRelease( vidCFNumberRef );
//  }
  
 }
 return refHIDMatchDictionary;
} 

void chubOPEN() {
 gIOHIDManagerRef = IOHIDManagerCreate( kCFAllocatorDefault, kIOHIDOptionsTypeNone );
 IOHIDManagerRegisterDeviceMatchingCallback( gIOHIDManagerRef, Handle_DeviceMatchingCallback, NULL );
 IOHIDManagerRegisterDeviceRemovalCallback( gIOHIDManagerRef, Handle_DeviceRemovalCallback, NULL ); 
 if ( gIOHIDManagerRef ) {
  IOHIDManagerScheduleWithRunLoop( gIOHIDManagerRef, CFRunLoopGetCurrent( ), kCFRunLoopDefaultMode );
  IOReturn tIOReturn = IOHIDManagerOpen( gIOHIDManagerRef, kIOHIDOptionsTypeNone );
  CFMutableDictionaryRef hidMatchingCFDictRef = hu_SetUpMatchingDictionary(kHIDPage_GenericDesktop, kHIDUsage_GD_GamePad );
  IOHIDManagerSetDeviceMatching(gIOHIDManagerRef,hidMatchingCFDictRef);
  ChubChingLoop();
 }
}

void chubRUN() {
	CFRunLoopRun();
}

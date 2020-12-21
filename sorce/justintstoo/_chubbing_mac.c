


static IOHIDManagerRef gIOHIDManagerRef = NULL;

static CFMutableDictionaryRef huDict(){//( UInt32 inUsagePage, UInt32 inUsage , UInt32 shbo ){
 UInt32 aaa = kHIDPage_GenericDesktop;
 UInt32 bbb = kHIDUsage_GD_GamePad;
 UInt32 ccc = 0x6666;
 CFMutableDictionaryRef refHIDMatchDictionary =
 CFDictionaryCreateMutable( kCFAllocatorDefault, 0, &kCFTypeDictionaryKeyCallBacks, &kCFTypeDictionaryValueCallBacks );
   CFNumberRef pageCFNumberRef = CFNumberCreate( kCFAllocatorDefault, kCFNumberIntType, &aaa);
   if ( pageCFNumberRef ) {
    CFDictionarySetValue( refHIDMatchDictionary, CFSTR( kIOHIDDeviceUsagePageKey ),pageCFNumberRef );
    CFRelease( pageCFNumberRef );

   CFNumberRef usageCFNumberRef = CFNumberCreate( kCFAllocatorDefault, kCFNumberIntType, &bbb );
   if ( usageCFNumberRef ) {
    CFDictionarySetValue( refHIDMatchDictionary, CFSTR( kIOHIDDeviceUsageKey ), usageCFNumberRef );
    CFRelease( usageCFNumberRef );
   }
  } //return refHIDMatchDictionary;
  UInt32 vendor_ID = 0x6666;
  CFNumberRef vidCFNumberRef = CFNumberCreate( kCFAllocatorDefault, kCFNumberIntType, &ccc );
  if ( vidCFNumberRef ) {
   CFDictionarySetValue( refHIDMatchDictionary, CFSTR(kIOHIDVendorIDKey), vidCFNumberRef );
   CFRelease( vidCFNumberRef );
  }
 return refHIDMatchDictionary;
}


static unsigned short getPid(IOHIDDeviceRef device) {
	CFTypeRef ref;
	int32_t value;
	
	ref = IOHIDDeviceGetProperty(device, CFSTR(kIOHIDProductIDKey));
	if (ref) {
		if (CFGetTypeID(ref) == CFNumberGetTypeID()) {
			CFNumberGetValue((CFNumberRef) ref, kCFNumberSInt32Type, &value);
			return value;
		}
	}
	return 0;
}



static void hidCallChusby(
                                                  void * inContext, IOReturn inResult,
                                                  void * inSender, IOHIDReportType inType,
                                                  uint32_t inReportID, uint8_t * inReport,
                                                  CFIndex inReportLength) {
 if (inReportLength)
  static_cast<Chub*>(inContext)->chubCALL();
}

IOHIDDeviceRef mydev=NULL;
typedef IOHIDDeviceRef CHUBHANDLE;
bool Chub::chubINIT() {
  mydev=NULL;
 gIOHIDManagerRef = IOHIDManagerCreate( kCFAllocatorDefault, kIOHIDOptionsTypeNone);
 IOHIDManagerScheduleWithRunLoop( gIOHIDManagerRef, CFRunLoopGetCurrent( ), kCFRunLoopDefaultMode );
 if (! gIOHIDManagerRef ) return false;
 IOHIDManagerOpen( gIOHIDManagerRef, kIOHIDOptionsTypeNone );
 CFMutableDictionaryRef cfarr = huDict();
 IOHIDManagerSetDeviceMatching(gIOHIDManagerRef,cfarr);
 CHUBHANDLE * refs = 0;
 CFSetRef devCFSetRef = IOHIDManagerCopyDevices( gIOHIDManagerRef );
 if (devCFSetRef) {
  CFIndex amountus = CFSetGetCount(devCFSetRef);
  refs = (IOHIDDeviceRef*)(malloc(sizeof(IOHIDDeviceRef)*amountus));
  CFSetGetValues(devCFSetRef, (const void**)refs);
  if ( amountus>0) {
   mydev = refs[0];
   IOHIDDeviceOpen(mydev, kIOHIDOptionsTypeNone);
   gwonzINIT(getPid(mydev));
   return true;
  } free(refs);
  
 }
 gwonzINIT(0);
 return false;
}

void Chub::chubRUN() {
	if (!mydev) return;
	//IOHIDDeviceScheduleWithRunLoop(mydev, CFRunLoopGetCurrent(), kCFRunLoopDefaultMode );
	IOHIDDeviceRegisterInputReportCallback(mydev,(uint8_t*)gwonz, 8, hidCallChusby,this);
	//CFRunLoopRun();
}



void Chub::chubCLOZ() {
 if (mydev) {
  IOHIDDeviceRegisterInputReportCallback(mydev,(uint8_t*)gwonz, 8, NULL,NULL);
  //IOHIDDeviceUnscheduleFromRunLoop(mydev, CFRunLoopGetCurrent(), kCFRunLoopDefaultMode);
  //IOHIDDeviceClose(mydev, kIOHIDOptionsTypeNone);
  IOHIDDeviceClose(mydev,kIOHIDOptionsTypeNone);
  mydev = 0;
 }
  if (gIOHIDManagerRef) IOHIDManagerClose(gIOHIDManagerRef,kIOHIDOptionsTypeNone);
 gIOHIDManagerRef =0;
 }
 

void Chub::chubSENDATE(uint8_t * outReport)  {
 while (mydev) {
  int returno = IOHIDDeviceSetReport(mydev, kIOHIDReportTypeOutput,
                                     0,outReport,8);
  if (returno==kIOReturnSuccess) return;
  if (chubShouldEnd()) return;
 }
}
void Chub::chubSENDEND()  {
 static uint8_t edible[8];
 CFIndex sizzle = 8;
 while (mydev) {
  int returno = IOHIDDeviceGetReport(mydev, kIOHIDReportTypeFeature,
                                     0,edible,&sizzle);
  if (returno==kIOReturnSuccess) return;
  if (chubShouldEnd()) return;
 }
}




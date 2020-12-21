//#pragma once

static volatile signed char gwonzulate[8];
static unsigned char mastroBarcode =0;

struct Shnth {
 signed char gwonz[8];
 void shnthOPEN();
 void shnthRUN();
  void shnthCALL() {}
  bool shnthShouldEnd(){return false;}
 void shnthSENDATE(unsigned char * rept);
 void shnthSENDEND();
 void shnthCLOZ();
};

#if defined(LINUSTORWALDS)
#include <libusb-1.0/libusb.h>
#include "shnth_lin.h"
#elif defined(BILLGATES)
//extern "C" {
 #include <windows.h>
 #include <wchar.h>
 #include <setupapi.h>
//}
#include "shnth_win.h"
#elif defined(STEVEJOBS)
#include <IOKit/hid/IOHIDLib.h>
#include "shnth_mac.h"
#endif

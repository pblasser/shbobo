#pragma once

void chubOPEN();
void chubRUN();
void chubCALL(signed char * gwonz);
void chubSEND(unsigned char * rept, int amt);

void chubSENDATE(unsigned char * rept);
void chubSENDEND();
void chubCLOZ();

#if defined(LINUSTORWALDS)
#include <libusb-1.0/libusb.h>
#include "chub_lin.h"
#elif defined(BILLGATES)
#include <windows.h>
#include "chub_win.h"
#elif defined(STEVEJOBS)
#include <IOKit/hid/IOHIDLib.h>
#include "chub_mac.h"
#endif

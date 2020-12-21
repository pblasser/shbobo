

#if defined(LINUSTORWALDS)
#include <libusb-1.0/libusb.h>
#include "_chubbing_lin.c"
#elif defined(BILLGATES)
//extern "C" {
#include <windows.h>
#include <wchar.h>
#include <setupapi.h>
//}
#include "_chubbing_win.c"
#elif defined(STEVEJOBS)
#include <IOKit/hid/IOHIDLib.h>
#include "_chubbing_mac.c"
#endif

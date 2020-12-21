
#pragma once
 #include <string.h> 
 #include <stdio.h> 


#if defined(BILLGATES)
#define LIZARDBACK 8
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
	#include <stdlib.h>
	#include <malloc.h>
	#include <memory.h>
	#include <tchar.h>
	#include <stdio.h>
	#include <mmreg.h>
	#include <mmsystem.h>
	#include <math.h>
#include <CommDlg.h>
#pragma comment(lib, "winmm.lib")
char * safety_nextoken;
#define strtok(a,b) strtok_s(a,b,&safety_nextoken)

FILE *cont_w_congon;
FILE *congon_fopen(char*f,char*p) {
	fopen_s(&cont_w_congon,f,p);
	return cont_w_congon;
}
#define fopen(f,p) congon_fopen(f,p)

#elif defined(LINUSTORWALDS)
#include <libusb-1.0/libusb.h> //-lusb-1.0
#include <alsa/asoundlib.h> //lasound
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 #include <errno.h> 
 #include <signal.h> 
 #include <string.h> 
 #include <stdio.h> 
 #include <stdlib.h> 
// #include <libusb-1.0/libusb.h> //-lusb-1.0
//#include <X11/extensions/Xdbe.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xos.h>
#include <X11/Xatom.h>
#include <X11/keysym.h> //-lX11
//#define LINUSTORWALDS
#define LIZARDBACK 8
void grax_repaint();




#elif defined(STEVEJOBS)
#define LIZARDBACK 127
#include <IOKit/hid/IOHIDLib.h>
#include <CoreServices/CoreServices.h>
#include <CoreAudio/CoreAudio.h>
#import <Cocoa/Cocoa.h>

#endif






//#include <math.h>

#define URPRIMLIM 256
#define FORI for(int i=0;i<4;i++)
#define FORJ for(int j=0;j<4;j++)
#define RMLIPPER(inn,ott) { \
if((inn>0)&(ott>0)) ott = 0;\
else if (inn>0) ott = 1;\
if((inn<0)&(ott<0)) ott = 0;\
else if (inn<0) ott = -1;\
if(inn==0) ott = 0; \
return 1; }

#define POINTSINRECTAL(p,r,i) \
((p.x>r[i].left)&(p.x<r[i].right)& \
(p.y>r[i].top)&(p.y<r[i].bottom))

#define POINTSINRECTALIS(p,r,i,j) \
((p.x>r[i][j].left)&(p.x<r[i][j].right)& \
(p.y>r[i][j].top)&(p.y<r[i][j].bottom))


#define COPYRECTAL(x,y) \
{x.left = y.left; x.right = y.right; \
x.top = y.top; x.bottom = y.bottom;}

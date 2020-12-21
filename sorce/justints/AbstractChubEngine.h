//this is the core concept which ging
//grax and chub interface with as they
//handle system-specific operations
//Abstract Chub Engine, to be inherited by 
//the main object of th'program deliverable
#pragma once
#include "stdafx.h"

#if defined(BILLGATES)

typedef struct _CHDC {
	HDC hdc;
	int cx;
	int cy;
} CHDC;

typedef HANDLE CHUBHANDLE;

typedef struct _CHUBREPORT {
	BYTE * report;
	UINT length;
} CHUBREPORT;

typedef POINTS MOUSEPOINT;

#elif defined(STEVEJOBS)

typedef struct _CHDC {
	CGContextRef hdc;
	int cx;
	int cy;
} CHDC;

typedef IOHIDDeviceRef CHUBHANDLE;

typedef struct _CHUBREPORT {
	uint8_t * report;
	CFIndex length;
} CHUBREPORT;

typedef NSPoint MOUSEPOINT;

#elif defined(LINUSTORWALDS)

typedef struct _CHDC {
	Display *hdc;
	unsigned int cx;
	unsigned int cy;
} CHDC;

typedef struct libusb_device_handle *CHUBHANDLE;

typedef struct _CHUBREPORT {
	char * report;
	unsigned int length;
} CHUBREPORT;

typedef struct _pointille {
	int x;
	int y;
} MOUSEPOINTREAL, MOUSEPOINT;


#endif

class AbstractChubEngine {
	//private: int nonus;
	public:
	virtual void graxness(CHDC c) =0;
	virtual int * gingness(int i, int bufflen) =0;
	virtual void beging() =0;
	virtual  void chubness(CHUBHANDLE h, CHUBREPORT r)=0;
	virtual  void charactros(unsigned char c)=0;
	virtual  void mouseButt(MOUSEPOINT)=0;
	virtual void textorium_trigger(char * outus)=0;
	virtual void textorium_script(char * innus)=0;
	virtual void dupe_chubbery()=0;
	virtual void dupe_multiplex()=0;
	//virtual void chubching(CHUBHANDLE * h, int a)=0;
	//virtual ~AbstractChubEngine();
};

AbstractChubEngine * abstr; 



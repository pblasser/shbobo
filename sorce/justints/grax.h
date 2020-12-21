#pragma once
#include "stdafx.h"
#include "AbstractChubEngine.h"

#if defined(BILLGATES)

typedef HBRUSH HGRAXBRUSH;

typedef HPEN HGRAXPEN;

static CHDC chdc;


//typedef RECT RECT;

static RECT bounders;

#define FILLRECT(hdc, b,r) FillRect(hdc,&r,b);

HGRAXBRUSH GRAXBRUSHWAND(BYTE r, BYTE g, BYTE b) {
	return CreateSolidBrush((COLORREF)RGB(r,g,b));
} void GRAXBRUSHNIL(HGRAXBRUSH h) {DeleteObject(h);}

HGRAXPEN GRAXPENWAND(BYTE r, BYTE g, BYTE b, int wd) {
	return CreatePen(PS_SOLID,1,RGB(r,g,b));
} void GRAXPENNIL(HGRAXPEN h) { DeleteObject(h);}

#define GRAXPENSET(c,h) SelectObject(c.hdc, h);
#define GRAXPENMOV(c,x,y) MoveToEx(c.hdc, x,y, NULL);
#define GRAXPENLIN(c,x,y) LineTo(c.hdc, x,y); \
	EndPath(c.hdc);
#define GRAXPENEND(c) 

HGRAXBRUSH conk = GRAXBRUSHWAND(0,0,0);

typedef struct _typioHGRAXSPRITE {
	RECT r;
	HBITMAP pieze;
} GRAXSPRITE, *HGRAXSPRITE;

//HGRAXSPRITE GRAXSPRITEWAND(unsigned int * buff, BYTE width, uint32 height) { return 0;}

#define GRAXARGB(a,r,g,b) ((((uint32)(uint8_t)(b))<<24)|(((uint32)(uint8_t)(g))<<16)| \
(((uint32)(uint8_t)(r))<<8)|(((uint32)(uint8_t)(a))))


#define GRAXSPRITER(c,h,xx,yy) \
	h->sizwon.origin.x = xx; \
	h->sizwon.origin.y = yy; \
	CGContextDrawImage (c.hdc, h->sizwon, h->pieze);

//HGRAXSPRITE MAKECERCLE(unsigned int r) {
//	HGRAXSPRITE harold;
//}
				 



//COLORREF song, yong;
//MAKERECT(x-value,y-value,x,y);
//song = RGB((BYTE) rand(),(BYTE) rand(),(BYTE) rand());
//yong = RGB((BYTE) rand(),(BYTE) rand(),(BYTE) rand());
//mong = CreateSolidBrush((COLORREF)song);
//twong = CreateSolidBrush((COLORREF)yong);
//dong = CreatePen(PS_SOLID,1,song);
//shong = CreatePen(PS_SOLID,1,yong);
//MoveToEx(hdc, x+sinn[0], y+coss[0], NULL);
//SelectObject(hdc, tyo[off%sz]);
//LineTo(hdc, x+sinn[off], y+coss[off]);
//EndPath(hdc);

//DeleteObject(dingdong); 
//FORI DeleteObject(maryflag[i]);
	HDC hdc;
	HDC          hdcMem;
	HBITMAP      hbmMem;
	HANDLE       hOld;
	PAINTSTRUCT ps;
	RECT rrrq = {0,0,1800,1600};
	static RECT rcTarget;    // rectangle to receive bitmap  
	//static int cx,cy;
	static int xchub;
	static int ychub;
	


void GraxWMPaintMassage(HWND hWnd) {
	hdc = BeginPaint(hWnd, &ps);
	//cx = //-ps.rcPaint.left;
	//cy = ps.rcPaint.bottom;//-ps.rcPaint.top;
	chdc.cx = ps.rcPaint.right;
	chdc.cy = ps.rcPaint.bottom;
	hdcMem = CreateCompatibleDC(hdc);
	chdc.hdc = hdcMem;
	hbmMem = CreateCompatibleBitmap(hdc, chdc.cx, chdc.cy);
	hOld = SelectObject(hdcMem, hbmMem);
	if (abstr) abstr->graxness(chdc);
	BitBlt(hdc, 0, 0, chdc.cx, chdc.cy, hdcMem, 0, 0, SRCCOPY);
	SelectObject(hdcMem, hOld);
	DeleteObject(hbmMem);
	DeleteDC (hdcMem);
	EndPaint(hWnd, &ps);
}

#elif defined(STEVEJOBS)

NSWindow *window ;

typedef struct _TYPIOGRAXLOBUSH {
	CGFloat red;
	CGFloat green;
	CGFloat blue;
} GRAXBRUSH, *HGRAXBRUSH;

typedef struct _TYPIOGRAXLOPENIS {
	HGRAXBRUSH color;
	float width;
} GRAXPEN, *HGRAXPEN;

static CHDC chdc;


typedef struct _TYPIOGRAXLORECTUM {
	int left;
	int top;
	int right;
	int bottom;
} RECT;

static RECT bounders;

#define FILLRECT(hdc, b,r) {\
CGContextSetRGBFillColor(hdc, (b)->red, (b)->green, (b)->blue, 1);\
CGContextFillRect(hdc,CGRectMake(r.left,r.top,r.right-r.left,r.bottom-r.top));}

HGRAXBRUSH GRAXBRUSHWAND(uint8_t r, uint8_t g, uint8_t b) {
	HGRAXBRUSH handle = (HGRAXBRUSH)malloc(sizeof(GRAXBRUSH));
	handle->red = (float)(int)r/255.9;
	handle->green = (float)(int)g/255.9;
	handle->blue = (float)(int)b/255.9;
						   return handle;
} void GRAXBRUSHNIL(HGRAXBRUSH h) {delete(h);}

HGRAXPEN GRAXPENWAND(uint8_t r, uint8_t g, uint8_t b, int wd) {
	HGRAXPEN handle = (HGRAXPEN)malloc(sizeof(GRAXPEN));
	handle->color = GRAXBRUSHWAND(r,g,b);
	handle->width = (float)wd;
	return handle;
} void GRAXPENNIL(HGRAXPEN h) 
{ GRAXBRUSHNIL(h->color); delete(h);}

//#define HGRAXPEN 
#define GRAXPENSET(c,h) \
	CGContextSetRGBStrokeColor(c.hdc, h->color->red, \
	h->color->green, h->color->blue,1); \
	CGContextSetLineWidth(c.hdc, h->width);
#define GRAXPENMOV(c,x,y) \
	CGContextMoveToPoint(c.hdc,x,y);
#define GRAXPENLIN(c,x,y) \
	CGContextAddLineToPoint(c.hdc, x,y);
#define GRAXPENEND(c) \
	CGContextStrokePath(c.hdc); 

HGRAXBRUSH conk = GRAXBRUSHWAND(0,0,0);

typedef struct _typioHGRAXSPRITE {
	CGRect sizwon;
	CGImageRef pieze;
} GRAXSPRITE, *HGRAXSPRITE;

HGRAXSPRITE GRAXSPRITEWAND(uint32 * buff, uint32 width, uint32 height) {
	CGDataProviderRef prov;
	
	HGRAXSPRITE young = (HGRAXSPRITE)malloc(sizeof(HGRAXSPRITE));
	young->sizwon = CGRectMake(0,0,width,height);
	prov = CGDataProviderCreateWithData(NULL, buff, 4*width*height, NULL);
	
	CGColorSpaceRef space = CGColorSpaceCreateDeviceRGB();
	young->pieze = CGImageCreate(width, height, 
					  8, 32,4*width, space, kCGImageAlphaFirst,
					  prov, NULL, false, kCGRenderingIntentDefault);
	return young;
}

#define GRAXARGB(a,r,g,b) ((((uint32)(uint8_t)(b))<<24)|(((uint32)(uint8_t)(g))<<16)| \
(((uint32)(uint8_t)(r))<<8)|(((uint32)(uint8_t)(a))))


#define GRAXSPRITER(c,h,xx,yy) \
	h->sizwon.origin.x = xx; \
	h->sizwon.origin.y = yy; \
	CGContextDrawImage (c.hdc, h->sizwon, h->pieze);

uint32 * arrio;

HGRAXSPRITE MAKECERCLE(uint32 r) {
	HGRAXSPRITE harold;
		uint32 temp;
	
	uint32 d = r*2;
	
	//uint32 * arrio;
	arrio = (uint32*)malloc(sizeof(uint32)*d*d);
	for(int a=0; a<d; a++) {
		for (int b=0; b<d; b++) {
			if ((((a-r)*(a-r))+((b-r)*(b-r))) < (r*r)) {
				uint32 ins = sqrt((((a-r)*(a-r))+((b-r)*(b-r)))) + 1;
				temp = GRAXARGB(rand(),rand(),0,0); }
			else temp = 0;
			arrio[a+(b*d)] = temp;
		}
	}
	
	harold = GRAXSPRITEWAND(arrio, d, d);
	return harold;
}
				 
NSString* directum;

@interface TestView : NSView <NSWindowDelegate> {}//;;;;'<NSWindowDelegate> { }
-(void)drawRect:(NSRect)rect;
-(BOOL)windowShouldClose:(id)sender;
@end

@implementation TestView


-(void)drawRect:(NSRect)rect {		
	CGContextRef myContext = (CGContextRef)([[NSGraphicsContext // 1
											  currentContext]graphicsPort]);
	CGRect bounds = NSRectToCGRect(rect);
	CGContextTranslateCTM(myContext,1,bounds.size.height);
	CGContextScaleCTM(myContext,1,-1);
	bounders = (RECT){bounds.origin.x, bounds.origin.y,
	 bounds.origin.x+bounds.size.width,
	 bounds.origin.y+bounds.size.height};
	CHDC chiddle = {myContext,bounds.size.width, bounds.size.height}; 
	chdc = chiddle;
	FILLRECT(chiddle.hdc, conk, bounders)
	//CGContextSetRGBFillColor(chiddle.hdc,0,0,rand()%6, 1);
	//CGContextFillRect(chiddle.hdc,bounds);

	
	if (abstr)
		abstr->graxness(chiddle);
}

- (BOOL)acceptsFirstResponder {
    return YES;
}



-(void)mouseDown:(NSEvent *)theEvent {
	NSPoint eventLocation = [theEvent locationInWindow];
    NSPoint center = [self convertPoint:eventLocation fromView:nil];
	center.y = bounders.bottom - center.y;
    //[self setNeedsDisplay:YES];
    if (abstr)
		abstr->mouseButt(center);
}

- (void)keyDown:(NSEvent *)theEvent {
	//printf("open");
    NSString *testor = [theEvent characters];
	unichar gyon = [testor characterAtIndex:0];
	unsigned short timple = [theEvent keyCode];
	if ([theEvent modifierFlags] & NSCommandKeyMask) {
		if ([theEvent modifierFlags] & NSShiftKeyMask) {
			if (gyon=='d')
				abstr->dupe_multiplex();
		} else if (gyon=='d') 
			abstr->dupe_chubbery();
		else if (gyon=='s') {
			int i;
			NSSavePanel* saveDlg = [NSSavePanel savePanel];
			//directum = @"/Desktop";
			[saveDlg setRequiredFileType:@"texte"];
			if ([saveDlg runModalForDirectory:directum file:@"output.texte"] == NSOKButton) {
				NSArray* files = [saveDlg filenames];
				i = 0;
				NSString* fileName = [files objectAtIndex:i];
				char *cString = strdup([fileName UTF8String]);
				//printf("%s\n",cString);
				abstr->textorium_trigger(cString);
				// Do something with the filename.
			}
		} else if ((char)gyon=='o') {
			int i; // Loop counter.
			NSArray *fileTypes = [NSArray arrayWithObject:@"texte"];
			NSOpenPanel* openDlg = [NSOpenPanel openPanel];
			[openDlg setCanChooseFiles:YES];
			[openDlg setRequiredFileType:@"texte"];
			//if ([openDlg runModalForDirectory:nil file:nil] == NSOKButton) 
			[openDlg setAllowsMultipleSelection:NO];
			//[openDlg setDirectoryURL:directum];
			if ( [openDlg runModalForDirectory:nil file:nil types:fileTypes] == NSOKButton ) {
			//	NSArray* files = [openDlg filenames];
			//	i = 0;
					NSString* fileName = [openDlg filename];
					//directum=[openDlg directoryURL];
					char *cString = strdup([fileName UTF8String]);
					//printf("%s\n",cString);
					abstr->textorium_script(cString);
					// Do something with the filename.
				
			}//printf("open\n");
		}
	} else if (abstr)
		abstr->charactros(gyon);
		//if ((char)gyon=='o') printf("open");
}

-(void)didEndOpenSheet:(NSOpenPanel *)openPanel returnCode:(int)returnCode contextInfo:(void *)contextInfo
{
	if (returnCode == NSOKButton){
		//NSString* fileName = [files objectAtIndex:i];
		NSString* fileName =  [openPanel filename];
		char *cString = strdup([fileName UTF8String]);
		//printf("%s\n",cString);
				abstr->textorium_script(cString);
	}
}

-(void)windowWillClose:(NSNotification *)note {
    [[NSApplication sharedApplication] terminate:self];
}
- (BOOL)windowShouldClose:(id)sender { return YES; }

@end

static TestView *view;

#elif defined(LINUSTORWALDS)


Display *dis;
Window win;
XEvent report;
GC green_gc;
XColor green_col;
Colormap colormap;
char green[] = "RoyalBlue4";

typedef XColor GRAXBRUSH, *HGRAXBRUSH;

typedef XColor GRAXPEN, *HGRAXPEN;

static CHDC chdc;

typedef struct _TYPIOGRAXLORECTUM {
	int left;
	int top;
	int right;
	int bottom;
} RECT;

static RECT bounders;

#define FILLRECT(hdc, b,r) {XSetForeground(dis, green_gc, b->pixel); \
	XFillRectangle(dis,win,green_gc,r.left, r.top, r.right-r.left, r.bottom-r.top);}

HGRAXBRUSH GRAXBRUSHWAND(unsigned char r, unsigned char g, unsigned char b) {
	HGRAXBRUSH handhold = (HGRAXBRUSH)malloc(sizeof(GRAXBRUSH));
	handhold->red = r<<8;
	handhold->green = g<<8;	
	handhold->blue = b<<8;
	XAllocColor(dis, colormap, handhold);
	return handhold;
} void GRAXBRUSHNIL(HGRAXBRUSH h) {free(h);}

HGRAXPEN GRAXPENWAND(unsigned char r, unsigned char g, unsigned char b, int wd) {
	return (HGRAXPEN)GRAXBRUSHWAND(r,g,b);
} void GRAXPENNIL(HGRAXPEN h) { free(h);}

int stardus_x, stardus_y;
HGRAXPEN nowus;

#define GRAXPENSET(c,h) XSetForeground(dis, green_gc, h->pixel); 
#define GRAXPENMOV(c,xx,yy) stardus_x = xx; stardus_y = yy;
#define GRAXPENLIN(c,xx,yy) { XDrawLine(dis,win,green_gc,stardus_x,stardus_y,xx,yy); \
	stardus_x = xx; stardus_y = yy; }
#define GRAXPENEND(c) 

void grax_repaint() {
	Window root, parent, *children;
	int x, y;
	unsigned int width, height, border_width, depth, nchildren;
	XGetGeometry(dis,win,&root,&x,&y,&width,&height,&border_width,&depth);
	//printf("%d height, %d width\n",height, width);
	chdc.cx = width;
	chdc.cy = height;
	abstr->graxness(chdc);
	XSetForeground(dis, green_gc, WhitePixel(dis, 0));
	XDrawString(dis, win, green_gc, 10, 10, "just ints", 9);
	XFlush(dis);
}

void open_grax() {
    	dis = XOpenDisplay(NULL);
	win = XCreateSimpleWindow(dis, RootWindow(dis, 0), 1, 1, 500, 500, 0, BlackPixel (dis, 0), BlackPixel(dis, 0));
	
	XStoreName(dis, win, "just ints");
	XMapWindow(dis, win);
	colormap = DefaultColormap(dis, 0);
	green_gc = XCreateGC(dis, win, 0, 0);
	XSelectInput(dis, win, ExposureMask | KeyPressMask | ButtonPressMask);
}

void grax_switchloop() {
	
	if (XCheckMaskEvent(dis, ExposureMask | KeyPressMask | ButtonPressMask, &report)) {
		switch  (report.type) {
        		case Expose:   
 	      			grax_repaint();
				
				//XFlush(dis);
			break;
	 		case KeyPress: {
				
				unsigned char k = XLookupKeysym(&report.xkey, 0);
				if (k=='s') //abstr->textorium_trigger();
				if (report.xkey.state  & ControlMask) {
					char *namae;
					namae = strdup("output.texte");
					abstr->textorium_trigger(namae);
				} else abstr->charactros(k);
				else abstr->charactros(k);
							
			break; } break;
			case ButtonPress:
				XButtonEvent presso = report.xbutton;
				MOUSEPOINT poignant;
				poignant.x = presso.x;
				poignant.y = presso.y;
				//printf ("You pressed button %d %d\n", presso.x, presso.y);
				//FILLRECT(dis,conk,rectum);
				abstr->mouseButt(poignant);
				break;
							
		}
	} 
} 

#endif

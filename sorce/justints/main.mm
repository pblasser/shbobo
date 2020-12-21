//this is the head of the macintosh OSX file
//it is .mm because it contains c++ as well
//as obj-c and c
#define STEVEJOBS

#include "LaceyBanks.h"

int main() { //(int argc, const char *argv[]) {
		char * inputfile;
		//if (argc > 1) inputfile = strdup(argv[1]);

		abstr =  new LaceyBanks();
		//if (inputfile) {
		//	printf("inputfile %s\n", inputfile);
			abstr->textorium_script(inputfile);
		//}

	
	
    NSAutoreleasePool *pool = [NSAutoreleasePool new];
    NSApplication *NSApp = [NSApplication sharedApplication];
	NSMenu * mainMenu = [[NSMenu alloc] initWithTitle:@"MainMenu"];	
	NSMenuItem * item;
	NSMenu * submenu;
	
	item = [mainMenu addItemWithTitle:@"Apple" action:NULL keyEquivalent:@""];
	submenu = [[NSMenu alloc] initWithTitle:@"Apple"];
	NSMenuItem *iitem = [[NSMenuItem alloc] initWithTitle:@"Quit"
												   action:@selector(terminate:)
											keyEquivalent:@"q"];
	[iitem setTarget: NSApp];
	[submenu addItem:iitem];
	[NSApp performSelector:@selector(setAppleMenu:) withObject:submenu];
	[mainMenu setSubmenu:submenu forItem:item];
	[NSApp setMainMenu:mainMenu];
	NSRect frame = NSMakeRect( 100., 100., 300., 300. );
	view = [[TestView alloc]initWithFrame:frame];
    window = [[NSWindow alloc]
						initWithContentRect:frame
						styleMask:NSTitledWindowMask | NSClosableWindowMask | NSMiniaturizableWindowMask | NSResizableWindowMask
						backing:NSBackingStoreBuffered
						defer:false];
    
    [window setTitle:@"JUSTINTS"];
	[window setContentView:view];
	[window setShowsResizeIndicator:YES];
	[window setDelegate:view];
    [window makeKeyAndOrderFront:nil];
	[window makeFirstResponder:view];
	//[[window parentWindow] makeFirstResponder:window];
	//[window orderFront];
	//[window makeKeyAndOrderFront];
	//[super makeFirstResponder:window];
	//abstr = new MultiplexPotentiator();
	ChubSetup();
	//ChubRefresh(0);
	
	CAStartPlayback(2, 512
					);
    
	[NSApp run];
    CAStopPlayback();
	[pool release];
    return(0);
    
    return( EXIT_SUCCESS );
}
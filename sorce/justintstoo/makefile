
DOSFLAGS=/I"C:\SDL2\include" /nologo /O2 /Oi /Oy- /GL  /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_UNICODE" /D "UNICODE" /Gm- /EHsc /MT /GS /Gy /fp:precise /Zc:wchar_t /Zc:forScope  /Gd /D"BILLGATES" /Fe
DOSLINK=/link /SUBSYSTEM:WINDOWS /LIBPATH:"C:\SDL2"
DOSLIB="SDL2.lib" "SDL2main.lib" "advapi32.lib" "oleaut32.lib" "ole32.lib"  "setupapi.lib" "Shell32.lib" "kernel32.lib" "user32.lib" "gdi32.lib" "winmm.lib" "Comdlg32.lib"
STATICLINX= /usr/local/lib/libSDL2.a 
INNCLUDE= -I/usr/local/include/SDL2/
SDLLIBS=  -lobjc -lstdc++ -std=c++11 -lm -liconv  -framework ForceFeedback -framework CoreAudio -framework CoreServices -framework Cocoa -Wall -framework OpenGL -ObjC++ -framework AudioToolbox -framework AudioUnit  -framework IOKit -framework Carbon -framework Foundation  
SDLLIBS=  -lobjc -lstdc++ -std=c++11 -lm -liconv -framework CoreVideo -framework ForceFeedback -framework CoreAudio -framework CoreServices -framework Cocoa -Wall -ObjC++ -framework AudioToolbox -framework AudioUnit  -framework IOKit -framework Carbon -framework Foundation  
flagsDarwin = -D"STEVEJOBS" -m32 $(SDLLIBS) $(INNCLUDE) $(STATICLINX)  -w -o 
LINUXLIBS= -lusb-1.0 -lstdc++ -lm -ldl -lpthread -lsndio

OS:=$(shell uname -s | cut -f1 -d_ )
targetLinux=justintstoo
targetDarwin=justintstoo
targetCYGWIN="justintstoo.exe"
target = $(target$(OS))
compilCYGWIN=cl main.cpp $(DOSLIB) $(DOSFLAGS)$(target) $(DOSLINK) 
compilDarwin=g++ main.cpp -D"STEVEJOBS" $(SDLLIBS) $(INNCLUDE) $(STATICLINX)  -w -o$(target)
compilLinux=g++ main.cpp -D"LINUSTORWALDS" $(LINUXLIBS) $(INNCLUDE) $(STATICLINX) -o$(target)
compil=$(compil$(OS))
deerLinux=_lin
deerDarwin=_mac
deerCYGWIN=_win
deer=$(deer$(OS))

main:
	$(compil) 
	chmod a+x $(target)
ifeq ($(OS),Darwin)
	-@rm -r $(target).app
	-@rm -r ../../$(deer)/$(target).app
	mkdir $(target).app
	mkdir $(target).app/Contents
	mkdir $(target).app/Contents/MacOS
	echo "<plist><dict><key>CFBundleExecutable</key><string>justintstoo</string><key>CFBundlePackageType</key><string>APPL</string><key>NSPrincipalClass</key><string>NSApplication</string></dict></plist>" > $(target).app/Contents/Info.plist
	mv $(target) $(target).app/Contents/MacOS/
	mv $(target).app ../../$(deer)
else
	mv $(target) ../../$(deer)
endif
	-@rm -rf *.app *.exe *.obj *.pdb *.*~ makefile~ *.exp *.lib *.suo
	-@find . -name .\* -delete




DOSFLAGS=/I"C:\Documents and Settings\Computer User\My Documents\SDL2-2.0.0\include" 
LUADOS=/I"C:\Documents and Settings\Computer User\My Documents\lua\include" 
LINK=/link /LIBPATH:"C:\Documents and Settings\Computer User\My Documents\lua" /LIBPATH:"C:\Documents and Settings\Computer User\My Documents\SDL2-2.0.0\lib\x86"
STATICLINX= /usr/local/lib/libSDL2.a /usr/local/lib/liblua.a
INNCLUDE= -I/usr/local/include
SDLLIBS=  -lobjc -lstdc++ -lm -liconv  -framework ForceFeedback -framework CoreVideo -framework CoreAudio -framework CoreServices -framework Cocoa -Wall -framework OpenGL -ObjC++ -framework AudioToolbox -framework AudioUnit  -framework IOKit -framework Carbon -framework Foundation  
OS:=$(shell uname -s | cut -f1 -d_ )
flagsLinux = -DSTDTR -DLINUSTORWALDS $(INNCLUDE) $(STATICLINX) -lstdc++ -lGL -lm -lusb-1.0 -o
flagsDarwin = -D"STEVEJOBS" $(SDLLIBS) $(INNCLUDE) $(STATICLINX)  -w -o 
flagsCYGWIN = /D"BILLGATES" "setupapi.lib" /Fe
flags = $(flags$(OS))
targetLinux=Mikey
targetDarwin=Mikey.mac
targetCYGWIN="Mikey.exe"
target = $(target$(OS))
compilCYGWIN=cl
compilDarwin=g++
compilLinux=g++
compil=$(compil$(OS))


main:

ifeq ($(OS),Darwin)
	$(compil) main.cpp $(flags)$(target)
	chmod a+x $(target)
	-rm -rf *.app ../*.app
	mkdir Mikey.app
	mkdir Mikey.app/Contents
	mkdir Mikey.app/Contents/MacOS
	echo "<plist><dict><key>CFBundleExecutable</key><string>Mikey</string><key>CFBundlePackageType</key><string>APPL</string><key>NSPrincipalClass</key><string>NSApplication</string></dict></plist>" > Mikey.app/Contents/Info.plist
	#mv Mikey.mac Mikey.app/Contents/MacOS/Mikey
	#-rm -r ../../_mac/Mikey.app
	#mv Mikey.app ../../_mac
endif

oldemac:
	$(compil) main.cpp  -DSTDTR -mmacosx-version-min=10.8 $(flags)$(target)
	chmod a+x $(target)
	mkdir Mikey.Olde.app
	mkdir Mikey.Olde.app/Contents
	mkdir Mikey.Olde.app/Contents/MacOS
	echo "<plist><dict><key>CFBundleExecutable</key><string>Mikey</string><key>CFBundlePackageType</key><string>APPL</string><key>NSPrincipalClass</key><string>NSApplication</string></dict></plist>" > Mikey.Olde.app/Contents/Info.plist
	mv Mikey.mac Mikey.Olde.app/Contents/MacOS/Mikey
	mv Mikey.Olde.app ..

windham:	
	-call "%VS100COMNTOOLS%vsvars32.bat"
	cl main.cpp  $(DOSFLAGS) $(LUADOS)  /D"BILLGATES" "setupapi.lib" "kernel32.lib" "openGL32.lib" "user32.lib" "gdi32.lib" "winmm.lib" "Comdlg32.lib" "SDL2.lib" "liblua52.a" /Fe"Mikey.exe" /Zi /nologo /w /O2 /Oi /Oy- /GL /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_UNICODE" /D "UNICODE" /Gm- /EHsc /MT /GS /Gy /fp:precise /Zc:wchar_t /Zc:forScope  /Gd $(LINK) 
	#gcc main.cpp -Lc:\Program Files\Microsoft Visual Studio 10.0\VC\LIB "kernel32.lib" "openGL32.lib" "user32.lib" "gdi32.lib" "winmm.lib" "Comdlg32.lib" "SDL2.lib" "liblua.a" -o"Mikey.exe" 
	mv Mikey.exe ..
	
clean:
	-@rm *~ Mikey *.exe *.obj *.pdb .DS_Store
	cd Opera && rm *~ Mikey *.exe *.obj *.pdb .DS_Store

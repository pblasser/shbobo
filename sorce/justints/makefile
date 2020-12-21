CC=gcc
OS:=$(shell uname -s | cut -f1 -d_)

main:
ifeq ($(OS),Linux)
	$(MAKE) linuks
endif
ifeq ($(OS),Darwin)
	$(MAKE) makintosh
endif
ifeq ($(OS),CYGWIN)
	$(MAKE) windham
endif
	$(MAKE) clean

makintosh:
	-rm -rf *.app ../*.app
	mkdir justints.app
	mkdir justints.app/Contents
	mkdir justints.app/Contents/MacOS
	gcc main.mm -framework CoreAudio -framework CoreServices -framework Cocoa -w -framework Foundation -Wno-import -framework IOKit -ObjC++ -lobjc -lstdc++ -o justints.app/Contents/MacOS/justints
	cp Info.plist justints.app/Contents/
	-rm -r ../../_mac/justints.app
	mv -f justints.app ../../_mac

linuks: main.c
	gcc -xc++ main.c -ojustints -lpthread -lrt -lX11 -lasound -lusb-1.0 -lstdc++ -lm
	chmod a+x justints
	mv justints ../../_lin

windham:	
	-call "%VS100COMNTOOLS%vsvars32.bat"
	cl winmain.cpp  "kernel32.lib" "user32.lib" "gdi32.lib" "winmm.lib" "Comdlg32.lib"  /Fe"justints.exe" /Zi /nologo /W3 /WX- /O2 /Oi /Oy- /GL /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_UNICODE" /D "UNICODE" /Gm- /EHsc /MT /GS /Gy /fp:precise /Zc:wchar_t /Zc:forScope  /Gd 
	mv justints.exe ../../_win
	
clean:
	-@rm -rf *.app *.exe *.obj *.pdb *.*~ makefile~ *.suo

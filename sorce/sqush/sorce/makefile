
CC=gcc 
OS:=$(shell uname -s | cut -f1 -d_ )
flagsLinux = -xc++ -DLINUSTORWALDS -lusb-1.0 -o
flagsDarwin = -DSTEVEJOBS -framework IOKit -framework Foundation -ObjC++ -lstdc++ -o 
flagsCYGWIN = /D"BILLGATES" "setupapi.lib" /Fe
flags = $(flags$(OS))
targetLinux=squish
targetDarwin=$(targetLinux).app
targetCYGWIN="squish.exe"
target = $(target$(OS))
compilCYGWIN=cl
compilDarwin=gcc
compilLinux=gcc
compil=$(compil$(OS))

main:
ifeq ($(OS),CYGWIN)
	$(call "%VS100COMNTOOLS%vsvars32.bat")
endif
	$(compil) main.cpp $(flags)$(target)
	
	chmod a+x $(target)
	mv $(target) ..
	$(MAKE) clean

clean:
	-@rm -rf *.*~ makefile~ *.o *.obj *.exe *.app shlisp lispshlisp 


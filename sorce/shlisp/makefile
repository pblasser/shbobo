




CC=gcc 
OS:=$(shell uname -s | cut -f1 -d_ )
flagsLinux = -xc++ -DLINUSTORWALDS -lusb-1.0 -lm -o
flagsDarwin =  -DSTEVEJOBS -framework IOKit  -framework Foundation -ObjC++ -lstdc++ -o 
flagsCYGWIN = /D"BILLGATES" "setupapi.lib" /Fe
#flagsCYGWIN = -xc++ -DBILLGATES -lsetupapi -o
flags = $(flags$(OS))
targetLinux=shlisp
targetDarwin=shlisp
targetCYGWIN="shlisp.exe"
target = $(target$(OS))
deerLinux=_lin
deerDarwin=_mac
deerCYGWIN=_win
deer=$(deer$(OS))
compilCYGWIN=cl
compilDarwin=gcc
compilLinux=gcc
compil=$(compil$(OS))

#expr.h(14) : warning C4566: character represented by universal-character-name '\
#u3000' cannot be represented in the current code page (1252)
#\xe3\x80\x80

main:
ifeq ($(OS),CYGWIN)
	$(call "%VS100COMNTOOLS%vsvars32.bat")
endif
	$(compil) minilisp.cpp $(flags)$(target)
	chmod a+x $(target)
	mv $(target) ../../$(deer)
	$(MAKE) clean

clean:
	-@rm -rf *.*~ makefile~ *.o *.obj *.exe *.app shlisp lispshlisp 


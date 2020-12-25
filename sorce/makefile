
OS:=$(shell uname -s | cut -f1 -d_ )

main:
ifeq ($(OS),CYGWIN)
	run "C:\Program Files (x86)\Microsoft Visual Studio\2017\Professional\VC\Auxiliary\Build\vcvars32.bat"
endif
	-@cd shmat && $(MAKE) shtar
	-@cd shmat && $(MAKE) shnth
	cd shlisp && $(MAKE)
	cd jish && $(MAKE)
	cd justints && $(MAKE)
	cd justintstoo && $(MAKE)
	cd mikey && $(MAKE)
	zip -r ../../shbobo.zip ../ -x "*.git*" -x "*.DS_Store*"
	$(MAKE) clean
clean:
	-rm -rf *.app *.*~ makefile~ *.o *.exe 

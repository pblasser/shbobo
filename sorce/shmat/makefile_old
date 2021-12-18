
#SHNTH ASSEMBLAGE 
#COPYRIGHT SHBOBO
STUTIL = "/cygdrive/c/Program Files/STMicroelectronics/STM32 ST-LINK Utility/ST-LINK Utility/ST-LINK_CLI.exe"
ST32MAP = -Ttext 0x0 -Tbss 0x20000000
OS:=$(shell uname -s | cut -f1 -d_)
assFlags=-W -mthumb-interwork -mapcs-32 -march=armv7 -mcpu=cortex-m3
lnkFlags=-v $(ST32MAP) -e0 -nostartfiles 
objFlags=-O binary
assLinux=arm-none-eabi-as 
lnkLinux=arm-none-eabi-ld
objLinux=arm-none-eabi-objcopy
assDarwin=arm-none-eabi-as
lnkDarwin=arm-none-eabi-ld
objDarwin=arm-none-eabi-objcopy
assCYGWIN=arm-elf-as
lnkCYGWIN=arm-elf-ld
objCYGWIN=arm-elf-objcopy
export ass = $(ass$(OS)) $(assFlags)
export lnk = $(lnk$(OS)) $(lnkFlags)
export obj = $(obj$(OS)) $(objFlags)
progger = $(OS)

shnth: assFlags += --defsym SHBOBO=0 
shnth: oto=shnth
#--defsym SHNTH=1
shnth: $(progger)
shtar: assFlags += --defsym SHBOBO=1 
shtar: oto=shtar
#--defsym SHTAR=1
shtar: $(progger)

main:
	-$(ass) -o $(oto).o main.s
	-$(lnk) -o $(oto).elf $(oto).o
	-$(obj) $(oto).elf $(oto).bin
	mv $(oto).bin ../../
	-@rm -f *.lst *.o *.elf *.*~ *.bin *.stackdump a.out makefile~

CYGWIN: main
	$(STUTIL) -c SWD UR -OB WRP=0xFFFFFFFF RDP=0
	$(STUTIL) -c SWD UR -ME -P ../$(oto).bin  0x08000000
	$(STUTIL) -c SWD UR -OB WRP=0xFFFF0000 RDP=0
	
Linux: main
	st-flash write ../$(oto).bin 0x8000000

Darwin: main

linuxpreparestflash:
	sudo apt-get install git
	git clone https://github.com/texane/stlink/ stlink.git
	cd stlink.git	
	sudo apt-get install autoconf
	./autogen.sh
	sudo apt-get install libusb-1.0-0-dev
	./confgure
	make
	sudo cp 49-stlinkv2.rules /etc/udev/rules.d/
	sudo udevadm control --reload-rules
	sudo cp st-flash /usr/bin/

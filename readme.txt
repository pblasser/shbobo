SHBOBO README

Shlisp is command line to program shtar or shnth.
Fish is the graphical interface for shlisp.

Orange Light Mode (for emergencies):
-disconnect device USB cord
-turn battery switch 'off'
-hold down orange button on shnth
-hold down top fret on shtar
-reconnect device USB cord
-upload a "safe" patch from examples

Changing cuisine (update opcodes):
in Fish, choose change cuisine, and choose
shtar.bin or shnth.bin as appropriate

to run shlisp, you may need to sudo, or may not.
In a console, find your command, _lin, _win, or _mac
without any arguments it will dump the HID data received from any SHNTH
./shlisp ../examp/vancouver.txt 
with the option -h, it spits out a list of the possible opcodes.
with the option -z, it spits out a list of the possible opcodes in Chinese
with the option -b, followed immediately by a number, it uses this number as the "barcode", eg -b255 inverts all bars.
after these options:
with one argument, it parses the phile as shlisp source, then transmits it to SHNTH.
with another argument, preferably ../wanilla.bin, it will update your synthesis matrix (1-4 minutes)

usb on linux does not connect to device unless you have permission.
you needs to use terminal to go to fish directory and run "sudo fish"
or, you can give permission for shnth by putting a file named "shnth.rules" inside the 
/etc/udev/rules.d/ directory.
the shnth.rules file should contain the following text:
SUBSYSTEM=="usb", ATTR{idVendor}=="6666", ATTR{idProduct}=="6666", MODE="0666"
SUBSYSTEM=="usb", ATTR{idVendor}=="6666", ATTR{idProduct}=="7777", MODE="0666"

JUSTINtS FOR SHNTH
FOUR CARDS TO THE BARRE
JUSTINTS FOR SHTAR
32 DOMINOES TO THE CARRE



Hi!
This is the current work in progress to have a full shlisp interpreter including lisp itself, which is accessed via boat <> and tank [] functionality. 
Also, a new java version of fish. you can try double clicking on “jish.jar”
and if that doesn’t work, cd to this directory and type “java -jar jish.jar”


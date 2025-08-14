# pblasser's shbobo repoman

## programs

 go into your OS-apprpriate directory, such as [_lin](./_lin/),[_mac](./_mac/), or [_win](./_win/),
 and execute the following programs. Remember, pblasser is an unidentified
 (secret) developer, so you may need to right-click and open on macintoshiusieses.

* **Shlisp** is a command line to program your shnth or shtar.
it now has full language support, including barebones
lisp interpreter on host side for scripting and generative
patch algorithms. like the olde program Galaxy for the DX7.
* double click on **fish**. open a file from examp/shnth or
examp/shtar. try "serving" it to the device.
* for **justints** and **justintstoo**, have the shnth or shtar already
plugged in with a USB cord. You can use the keystroke
"command-o" to open an example in examp/justints
* **jish** is a new version of fish, in java. java is the future,
as it is also the past.
it calls the appropriate shlisp command line from _win,
_lin, or _mac. You can run the jish.jar
by double clicking on it (if you're perfectly lucky) or
going to this directory in console and type:

```bash
java -jar jish.jar
```

that is, if you have [java](https://www.java.com/en/download/) installed.

## shlisp options

You can upload a shlisp texte in Fish, or you can use shlisp
on the command line. Jish can upload too and it does by
calling the shlisp command line. changing cuisine is uploading
the whole audio opcode matrix, and only needs doing once.
changing cuisine is like upgrading audio firmware, and also
you could potentially hack the matrix and create new sound opcodes.

* to list all the opcodes: shlisp -h
* to read data from the device for testing: shlisp -g
* to upload a patch: shlisp ../examp/beachlanterns.txt
* to change cuisine give it the appropriate bin and a texte: shlisp -b../shnth.bin ../examp/beachlanterns.txt

## orange light mode

If you happen to upload a bugged or broken shlisp, and your shnth has frozen,
no worries, it's just the audio code spinning out. your shnth is not broken.
you need to recover it with orange light mode:

* disconnect device USB cord
* turn battery switch off, away from USB port
* hold down orange button on shnth, or hold down top fret of shtar
* whilst holding, reconnect USB cord
* upload a "safe" patch from examples

## linux

usb on linux does not connect to device unless you have permission.
you needs to use terminal to go to fish directory and run "sudo fish"
or, you can give permission for shnth by putting a file named "shnth.rules" inside the
/etc/udev/rules.d/ directory.

the shnth.rules file should contain the following text:

```bash
SUBSYSTEM=="usb", ATTR{idVendor}=="6666", ATTR{idProduct}=="6666", MODE="0666"
SUBSYSTEM=="usb", ATTR{idVendor}=="6666", ATTR{idProduct}=="7777", MODE="0666"
```

## sorce

you can make the sorce-level makefile if you want to try compiling
it all for yourself. or you can do each makefile by themselves, i don't care!
all of these may need libusb on linux.

* **fish** is the source for that program, and you'll need JUCE
to compile it. Because it's JUCE there is no makefile, sorry.
* since JUCE is like java, it was natural to end up porting it to
that language as **jish**. you will need JDK
* **justints** was originally made for shnth, using custom ported
libraries. this is the first time i consolidated chub libraries,
which are for reading the shnth in a game-like fashion. **justints**
also only uses ints, and it is a manifesto for integer/fixed-point synthesis.
* **justintstoo** is for the shtar but it actually works with shnth too.
this uses SDL2, so get that installed.

```txt
JUSTINtS FOR SHNTH
FOUR CARDS TO THE BARRE
JUSTINTS FOR SHTAR
32 DOMINOES TO THE CARRE
```

* **mikey** uses SDL2, as well as openGL. it also uses lua for scripting,
so get that installed too. this only compiles on mac
* **shlisp** is a command line, programmed in c, that interprets
lisp based on [rui314's minilisp](https://github.com/rui314/minilisp/tree/nogc).
it has no garbage collector if you look at that link. after it interprets
the lisp it serves shbobo code to your shnth or shtar. it can also
spit out readings from your device. compiler note: it actually
is forced into c++ as they all do just to meet steve's
and bill's requirements for connecting a usb device.
* **shmat** is the source code for the st32f103rct6 chip inside shnth
and shtar. type make shnth or make shtar.
you will need arm-none-eabi or something like it. it will also
try to call st-link or [st-link](https://github.com/stlink-org/stlink) to flash the st chip.

```txt
@ALL ASSEMBLY, NO RULES!
@ACTUALLY THE MAIN RULE IS HOW THE REGISTERS ARE USED
@AND WHERE THE FIXED POINT IS
```

* **sqush** is a simple shred of code to read the shnth
and pipe granular microsound notes to csound.

## thanks

thanks to everyone who works on this or uses it. i pray that
you have a healthy internet and a safe home. note that all the
shbobo code is now open source, including the device initialization
and sexpression of the shmat.

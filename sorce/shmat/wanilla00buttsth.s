@SHLISP "WANILLA" ASSEMBLAGE 
@COPYLEFT SHBOBO PLZ MUTATE

ORIGINATE

.macro SQUISHRAMP
 RAMP
 itt eq
 .ifeq ARAB
 ssateq lispRET, 0x10, lispACC
 .else
 usateq lispRET, 0x10, lispACC @, lsl 1
 .endif
 POPEQE
 SEXY
 mul lispACC, lispACC, lispRET
 .ifeq ARAB
 asr lispACC, lispACC, 0xF
 .else 
 asr lispACC, lispACC, 0x10
 .endif
 POPSEX
 add lispACC, lispACC, lispRET
 SEXTNINER
.endm

.macro HIGHSTATE
 ite ne
 .ifeq ARAB 
 movne lispACC, 0x8000 
 .else
 movne lispACC, 0x10000 
 .endif
.endm

.macro TINES 
 and lispMEX, lispMEX, #15
 SYNTHLOAD workONE, GPIOB_IDR
 ldrh workONE, [workONE]
 mov lispACC, 0x1
 sub lispMEX, 1
 lsl lispACC, lispMEX
 tst workONE, lispACC
 HIGHSTATE
 moveq lispACC, 0
 LISPMULADD
.endm
INSTORG TINES, 0
INSTORG TINES, 4
INSTORG TINES, 8
INSTORG TINES, 0xC


@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@The following comment is for gnu-arm-as assembler
@thus, quoted with the at symbol.  Thanks to XXXXX      
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  
@   @@@@@@@               (((( ))))    at pubes   @                           
@     @@@===================== ))))    0==()      @
@      ======================== ) )   zero balls  @
@       ======================== ))) logicle test @
@    0     0              ==== ))) )  equate cock @
@   0    0  0            ( (    )  )              @
@   0  000   0            ( (  )  ) lisping moon  @
@    000 0000               (  )    parenth pussy @
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@depth of parentheses, and the use of the number 
@zero to denote the empty list NIL and the truth 
@value false. Besides encouraging pornographic 
@programming, giving a special interpretation to 
@the address 0 has caused difficulties in all 
@subsequent implementations. {because 0==() has 
@been the emoticon for pornography since 1958.}
@--In the History of Lisp, John McCarthy
@Explained by Trystan Spangler on stackoverflow.com


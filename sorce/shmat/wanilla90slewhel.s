@SHLISP "WANILLA" ASSEMBLAGE 
@COPYLEFT SHBOBO PLZ MUTATE

ORIGINATE

.macro SLEW
 VAKLORDEIGHT slewVALE
 POPSEX
 mov lispWOR, lispRET
 POPSEX
 RECTARET
 subs workONE, lispWOR, lispACC
 ble 1f
 cmp workONE, lispRET, lsr 8
 it gt 
 addgt lispACC, lispACC, lispRET, lsr 8
 @movle lispACC, lispWOR
 SYNTHLOADER workONE, slewVALE
 strh lispACC, [workONE, lispMEX, LSL 1]
1:
 POPSEX
 RECTARET
 subs workONE, lispACC, lispWOR
 ble 1f
 cmp workONE, lispRET, lsr 8
 it gt
 subgt lispACC, lispACC, lispRET, lsr 8
 @movle lispACC, lispWOR
 SYNTHLOADER workONE, slewVALE
 strh lispACC, [workONE, lispMEX, LSL 1]
1:
 LISPMULADD
.endm
INSTORG SLEW, 0
INSTORG SLEW, 4

.macro WORDPOPERAMP
 RAMP
 itt eq
 .ifdef ARAB
 asreq lispRET, lispACC, 0x10
 .else
 lsreq lispRET, lispACC, 0x10
 .endif
 POPEQE
.endm

.macro WHEEL   @wheelup inn
 and lispMEX, lispMEX, #3
 SYNTHLOADER lispWOR, wheelVALE
 ldr lispACC, [lispWOR, lispMEX, LSL 2]
 
 WORDPOPERAMP
 SEXY
 usat lispRET, 0x10, lispRET
 add lispACC, lispACC, lispRET@, asr 8
 str lispACC, [lispWOR, lispMEX, LSL 2]
 
 WORDPOPERAMP
 SEXY
 usat lispRET, 0x10, lispRET
 sub lispACC, lispACC, lispRET@, asr 8
 str lispACC, [lispWOR, lispMEX, LSL 2]
 
 .ifdef ARAB
 asr lispACC, lispACC, 0x10
 .else
 lsr lispACC, lispACC, 0x10
 .endif
 @ALSERACK
 LISPMULADD
.endm
INSTORG WHEEL, 8
INSTORG WHEEL, 0xC

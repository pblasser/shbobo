@SHLISP "WANILLA" ASSEMBLAGE 
@COPYLEFT SHBOBO PLZ MUTATE

ORIGINATE

soseDEEP .req workTRI

.macro SCANETTO
 mov scanDEEP, 0 @depth
1:
 .rept 4
 ldrb lispRET, [lispCOD], 1
 cmp lispRET, 0
 it eq
 subeq scanDEEP, 1 @un-deeper
 cmp lispRET, 0xFF
 it eq
 addeq scanDEEP, 1 @deeper 
 cmp scanDEEP, 1
 blt 2f
 .endr
 b 1b
.endm

.macro SAUCE
 VAKLORDEIGHT sauceVALE
 POPSEX
 RECTARET
 SYNTHLOADER workONE, saucePOSZ
 ldrb workTWO, [workONE, lispMEX]
 add workTWO, workTWO, 1
 cmp workTWO, lispRET, asr 8
 ittte gt @executo
 movgt workTWO, 0
 strbgt workTWO, [workONE, lispMEX]
 movgt lispACC, 0
 ble 2f
 POPSEX
 mov lispACC, lispRET
 strh lispACC, [lispWOR, lispMEX, lsl 1]
 LISPMULADD
2: @execute sexpressions
 strb workTWO, [workONE, lispMEX]
 SCANETTO 
2:
 LISPMULADD
.endm 
INSTORG SAUCE 0
INSTORG SAUCE 4

.macro SALSA   @sauce per s1 ... sn
 VAKLORDEIGHT salsaVALE
 POPSEX

 TRIG_IDEE_TOO lispRET, workTWO, salsatrig, workTRI
 ite ne
 movne lispACC, 0
 beq 2f
 POPSEX
 mov lispACC, lispRET
 strh lispACC, [lispWOR, lispMEX, lsl 1]
 LISPMULADD
2: @execute sexpressions
 SCANETTO 
2:
 LISPMULADD
.endm 
INSTORG SALSA 8
INSTORG SALSA 0xC

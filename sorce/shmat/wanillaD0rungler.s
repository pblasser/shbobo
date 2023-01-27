@SHLISP "WANILLA" ASSEMBLAGE 
@COPYLEFT SHBOBO PLZ MUTATE

ORIGINATE

.macro RUNGLER
 and lispMEX, lispMEX, 7
 SYNTHLOADER lispWOR,runglerVALES
 .ifeq ARAB 
 ldrsb lispACC, [lispWOR, lispMEX]
 .else
 ldrb lispACC, [lispWOR, lispMEX]
 .endif
 lsl lispACC, 0x8

 POPSEX
 TRIG_IDEE_TOO lispRET, lispWOR, runglertrig, workTRI

 POPSEX
 usat lispRET, 9, lispRET, lsl 8
 cmp lispWOR, 1
 ittt eq
 andeq lispWOR, lispACC, 0x8000
 eoreq lispWOR, lispRET, lispWOR, lsr 7
 orreq lispACC, lispWOR, lispACC, lsl 1

 itttt eq
 lsreq lispWOR, lispACC, 8
 SYNTHLOADEREQ workONE, runglerVALES
 strbeq lispWOR, [workONE, lispMEX]
 
 LISPMULADD
.endm
INSTORG RUNGLER, 0
INSTORG RUNGLER, 4

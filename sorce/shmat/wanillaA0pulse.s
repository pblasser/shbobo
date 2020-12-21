@SHLISP "WANILLA" ASSEMBLAGE 
@COPYLEFT SHBOBO PLZ MUTATE

ORIGINATE

.macro SLAVE   @inn ceremony mul add
 and lispMEX, lispMEX, 7
 SYNTHLOADER lispWOR,slaveVALE
 .ifeq ARAB 
 ldrsb lispACC, [lispWOR, lispMEX]
 .else
 ldrb lispACC, [lispWOR, lispMEX]
 .endif
 lsl lispACC, 0x8
 POPSEX
 TRIG_IDEE_TOO lispRET, workONE, slavetrig, workTRI
 ittt ne
 addne lispACC, 0x100
 asrne workONE, lispACC, 0x8
 strbne workONE, [lispWOR, lispMEX]
 POPSEX
 RECTARET
 cmp lispACC, lispRET
 itttt ge
 .ifeq ARAB 
 mvnge lispACC, lispRET
 @movge lispACC, 0
 .else
 movge lispACC, 0
 .endif
 addge lispACC, lispACC, 1
 asrge workONE, lispACC, 0x8
 strbge workONE, [lispWOR, lispMEX]
 LISPMULADD
.endm
INSTORG SLAVE, 0
INSTORG SLAVE, 4

.macro PULSEDHIGHRAMP
 RAMP
 itttt eq
 .ifeq ARAB
 usateq lispRET, 0x1, lispACC
 lsleq lispRET, lispRET, 0xF 
 ssateq lispRET, 0x10, lispRET
 .else
 usateq lispRET, 0x1, lispACC
 lsleq lispRET, lispRET, 0x10
 usateq lispRET, 0x10, lispRET
 .endif
 POPEQE
.endm


.macro PULSE   @inn ceremony mul add
 and lispMEX, lispMEX, 7
 SYNTHLOADER lispWOR,pulseVALE
 LOADERH lispACC, lispWOR

 @PULSEDHIGHRAMP
 @SEXY
 POPSEX
 TRIG_IDEE_TOO lispRET, workONE, pulsetrig, workTWO
 it ne
 .ifeq ARAB
 movne lispACC, 0x8000
 sub lispACC, lispACC, 4
 usat lispACC, 0xF, lispACC
 .else
 movne lispACC, 0x10000
 sub lispACC, lispACC, 8
 usat lispACC, 0x10, lispACC
 .endif
 strh lispACC, [lispWOR, lispMEX, lsl 1]

 @PULSEDHIGHRAMP
 @SEXY
 POPSEX
 RECTARET
 cmp lispACC, lispRET
 itt gt
 movgt lispACC, lispRET
 strhgt lispACC, [lispWOR, lispMEX, lsl 1]
 LISPMULADD
.endm
INSTORG PULSE, 8
INSTORG PULSE, 0xC

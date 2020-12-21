@SHLISP "WANILLA" ASSEMBLAGE 
@COPYLEFT SHBOBO PLZ MUTATE

ORIGINATE

scanSCAN .req workONE
scanPLAZ .req workTWO
scanDEEP .req workTRI
scanCODE .req workFOR
scanSREF .req workFIV





.macro SCANSOR_IDEE_PREP plazbait
 SYNTHLOADER scanSREF, \plazbait @bytesz
 ldrb scanSCAN, [scanSREF, lispMEX]
.endm

.macro SCANSOR_IDEE_PREPTOO
 mov scanPLAZ, 0 @plaz
 mov scanDEEP, 0 @depth
 mov scanCODE, lispCOD @remember lispCOD
.endm

.macro SCANSOR_TESTICLES
 RAMP
 it eq
 subeq scanDEEP, 1 @un-deeper
 cmp lispRET, 0xFF
 it eq
 addeq scanDEEP, 1 @deeper 
 cmp scanDEEP, 0
.endm

.macro SCANSOR_IDEE_FRONT
1:
 cmp scanPLAZ, scanSCAN @plaz against togoesplaz
 beq 2f @lively
 SCANSOR_TESTICLES
@july nin of 13, test to see if closure then go back
 itttt eq
 addeq scanPLAZ, 1
 ldrbeq lispRET, [lispCOD]
 cmpeq lispRET, 0
 beq 3f
 bgt 1b
.endm

.macro SCANSOR_IDEE_LOOP
 
 @bge 1b
3:
 mov lispCOD, scanCODE
@july nin of 13, test to see if negativ then wrap to end
 tst scanSCAN, (1<<31)
 ite ne
 @movne scanSCAN, scanPLAZ
 subne scanSCAN, scanPLAZ,1
 moveq scanSCAN, 0
 mov scanPLAZ, 0
 strb scanSCAN, [scanSREF, lispMEX]
 beq 2f
 bne 1b
.endm

.macro SCANSOR_IDEE_END 
@assert inside while(1)
@deepak is zeroed
 mov scanDEEP, 0 @depth
1:
 SCANSOR_TESTICLES
 @cmp scanDEEP, 1
 itt lt
 movlt lispRET, lispACC
 POPLTE
 b 1b
.endm


.macro TOGO
 VAKLORDEIGHT togoesVALES
 
 POPSEX
 SCANSOR_IDEE_PREP togoesPLACZ
 TRIG_IDEE_TOO lispRET, scanDEEP, togouptrig, scanCODE
 itt ne 
 addne scanSCAN, scanSCAN, 1
 strbne scanSCAN, [scanSREF, lispMEX]
 
 POPSEX
 SCANSOR_IDEE_PREP togoesPLACZ
 TRIG_IDEE_TOO lispRET, scanDEEP, togodntrig, scanCODE
 itt ne 
 subne scanSCAN, scanSCAN, 1
 strbne scanSCAN, [scanSREF, lispMEX]
 
 SCANSOR_IDEE_PREPTOO
 SCANSOR_IDEE_FRONT
 SCANSOR_IDEE_LOOP
 2: @lively
 POPSEX
 mov lispACC, lispRET
 SYNTHLOADER workONE, togoesVALES
 strh lispRET, [workONE, lispMEX, LSL 1]
 SCANSOR_IDEE_END 
 .ltorg
.endm


 INSTORG TOGO, 0  
 INSTORG TOGO, 4  

.macro TOGGLE
 and lispMEX, lispMEX, #7
 BBTOO lispACC, lispWOR, toglvals, lispMEX
 RAMP
 itt eq
.ifeq ARAB
 lsleq lispRET, lispACC, 0xF
.else 
 lsleq lispRET, lispACC, 0x10
.endif
 POPEQE
 SEXY
 TRIG_IDEE_TOO lispRET, workTWO, togltrig, workTRI
 it ne 
 eorne lispACC, lispACC, 1
 str lispACC, [lispWOR, lispMEX, lsl 2]
 .ifeq ARAB 
 lsl lispACC, lispACC, 0xF
 .else
 lsl lispACC, lispACC, 0x10
 .endif
 LISPMULADD
.endm
INSTORG TOGGLE, 8
INSTORG TOGGLE, 0xC


















.macro SIGNOTRIG from, intr, twoo, trigname, ref
 .ifeq ARAB
 ssat \from, 2, \from
 usat \intr, 1, \from  
 BBTOO \twoo,\ref,\trigname,lispMEX
 str \intr, [\ref, lispMEX, LSL #2]
 eor \twoo, \twoo, \intr
 ands \twoo, \twoo, \intr
 it ne
 addne scanSCAN, scanSCAN, 1
 @strbne scanSCAN, [scanSREF, lispMEX]

 lsr \from, \from, 1
 and \intr, \from, 1
 add \ref, \ref, 0x20
 ldr \twoo, [\ref, lispMEX, LSL #2]
 str \intr, [\ref, lispMEX, LSL #2]
 eor \twoo, \twoo, \intr
 ands \twoo, \twoo, \intr
 it ne
 subne scanSCAN, scanSCAN, 1
 @strbne scanSCAN, [scanSREF, lispMEX]

 .else
 TRIG_IDEE_TOO \from, \twoo, \trigname, \ref
 it ne
 addne scanSCAN, scanSCAN, 1
 @strbne scanSCAN, [scanSREF, lispMEX]
 .endif
.endm

.macro TOGOOLDE
 VAKLORDEIGHT togoesVALES
 POPSEX
 SCANSOR_IDEE_PREP togoesPLACZ
 SIGNOTRIG lispRET, scanPLAZ, scanDEEP, togotrig, scanCODE
 strb scanSCAN, [scanSREF, lispMEX]
 SCANSOR_IDEE_PREPTOO
 SCANSOR_IDEE_FRONT
 SCANSOR_IDEE_LOOP
 2: @lively
 POPSEX
 mov lispACC, lispRET
 SYNTHLOADER workONE, togoesVALES
 strh lispRET, [workONE, lispMEX, LSL 1]
 SCANSOR_IDEE_END 
 .ltorg
.endm

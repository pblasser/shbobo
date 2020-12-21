@SHLISP "WANILLA" ASSEMBLAGE 
@COPYLEFT SHBOBO PLZ MUTATE

ORIGINATE

@LP > lispACC 
.macro PHILTRE_IDEE_QUALITE acc, bp
 RECTARET
 SYNTHLOADER lispWOR, \bp
 ldrsh lispWOR, [lispWOR, lispMEX, LSL 1]
 mul workONE, lispWOR, lispRET
 .ifeq ARAB
 asr workONE, workONE, 0xF
 .else
 asr workONE, workONE, 0x10
 .endif
 @ALSER workONE
 ssat workONE, 0x10, workONE
 @SUSAT workONE
 sub \acc, \acc, workONE
.endm

.macro PHILTRE_IDEE_PARAM acc, bp, lp
 RECTARET
 mul \acc, \acc, lispRET
 .ifeq ARAB
 asr \acc, \acc, 0xF
 .else 
 asr \acc, \acc, 0x10
 .endif
 @ALSER \acc
 SYNTHLOADER workTWO, \bp
 ldrsh workONE, [workTWO, lispMEX, LSL 1]
 add \acc, \acc, workONE
 ssat \acc, 0x10, \acc
 @SUSAT \acc
 
 strh \acc, [workTWO, lispMEX, LSL 1]
 SYNTHLOADER workONE, \lp
 ldrsh workTWO, [workONE, lispMEX, LSL 1]
 @LOADERH workTWO, lispWOR
 mul \acc, \acc, lispRET
 asr \acc, \acc, 0xF
 @ALSER \acc
 add \acc, \acc, workTWO
 ssat \acc, 0x10, \acc
 @SUSAT \acc
 strh \acc, [workONE, lispMEX, LSL 1]
.endm

.macro WATERSTEP numb
 @mov workFOR, workTRI
 SYNTHLOADER workTRI, waterLP
 ldrsh workTRI, [workTRI, lispMEX, LSL 1]
 @LOADERH workTRI, workTRI
 .ifeq \numb
 sub workTRI, lispACC, workTRI
 mov lispACC, 0
 .else
 rsb workTRI, workTRI, 0
 .endif
 DOGG waterQNQN, 0
 PHILTRE_IDEE_QUALITE workTRI, waterBP
 DOGG waterQNQN, 0x20
 @add lispRET, lispRET, workFOR
 PHILTRE_IDEE_PARAM workTRI, waterBP, waterLP
 add lispACC, lispACC, workTRI
 add lispMEX, lispMEX, 0x4
 and lispMEX, lispMEX, 0xF
.endm

.macro WATER
 VAKLORD waterVALES
 POPSEX
 TRIG_IDEE_TOO lispRET, lispWOR, watertrig, workTRI
 SYNTHLOADER workONE, waterDROP
 ldrb workTWO, [workONE, lispMEX] @byte
 ittt ne @incrementing plaz
 addne workTWO, workTWO, 1
 andne workTWO, workTWO, 3
 strbne workTWO, [workONE, lispMEX]
 HIGHSTATE
 moveq lispACC, 0
 @mov lispACC, 0x8000
 add lispMEX, lispMEX, workTWO, lsl 2
 PARMER1 waterQNQN, 0
 PARMER1 waterQNQN, 0x20

 WATERSTEP 0
 WATERSTEP 1
 WATERSTEP 2
 WATERSTEP 3

 SYNTHLOADER workONE, waterVALES
 and lispMEX, lispMEX, 3
 strh lispACC, [workONE, lispMEX, LSL 1]
 LISPMULADD
.endm

.macro PHILT    @ philt inn queue freaq mul add
 and lispMEX, lispMEX, 3
 SYNTHLOADER lispWOR, philtLP
 ldrsh lispACC, [lispWOR, lispMEX, LSL 1]
 POPSEX
 sub lispACC, lispRET, lispACC
 POPSEX
 PHILTRE_IDEE_QUALITE lispACC, philtBP
 
 POPSEX
 PHILTRE_IDEE_PARAM lispACC, philtBP, philtLP
 
 LISPMULADD
.endm
INSTORG PHILT, 0
@redundant philtaphish
INSTORG PHILT, 4

INSTORG WATER, 0x8

.macro HIGHPASS    @ philt inn queue freaq mul add
 and lispMEX, lispMEX, 3
 SYNTHLOADER lispWOR, philtLP
 ldrsh lispACC, [lispWOR, lispMEX, LSL 1]
 POPSEX
 sub lispACC, lispRET, lispACC
 POPSEX
 PHILTRE_IDEE_QUALITE lispACC, philtBP
 mov lispWOR, lispACC
 POPSEX
 PHILTRE_IDEE_PARAM lispACC, philtBP, philtLP
 mov lispACC, lispWOR
 LISPMULADD
.endm
INSTORG HIGHPASS, 0xC

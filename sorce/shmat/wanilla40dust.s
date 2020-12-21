@SHLISP "WANILLA" ASSEMBLAGE 
@COPYLEFT SHBOBO PLZ MUTATE

ORIGINATE

.macro NOISE_MIT_IDEE4 acc, lrd, val
 SYNTHLOADER \lrd, \val
 ldrsh \acc, [\lrd, lispMEX, LSL 1] 
 movw workFOR, 25173
 mul \acc, \acc, workFOR
 movw workFOR, 13849
 add \acc, \acc, workFOR
.endm
.macro NOISE_MEAT_IDEE4 acc, lrd, val
 NOISE_MIT_IDEE4 \acc, \lrd, \val
 strh \acc, [\lrd, lispMEX, LSL 1]
.endm

.macro NOISE
 and lispMEX, lispMEX, #7
 NOISE_MEAT_IDEE4 lispACC, lispWOR, noiseVALES
 VAKLORDEIGHT noiseVALES
 LISPMULADD
.endm

INSTORG NOISE, 0
INSTORG NOISE, 4
	
.macro DUST
 VAKLORDEIGHT dustRAMPS
 POPSEX
 RECTARET
 add lispACC, lispACC, lispRET, asr 8

 NOISE_MIT_IDEE4 workTWO, workONE, dustVALES
 @usat lispRET, 0x10, workTWO
 movw workFOR, 0x7FFF
 and lispRET, workTWO, workFOR
 @RECTA lispRET, workTWO
 cmp lispACC, lispRET
 itt gt
 .ifeq ARAB
  mvngt lispACC, lispRET
 .else
  movgt lispACC, 0
 .endif
 strhgt workTWO, [workONE, lispMEX, LSL 1]
 strh lispACC, [lispWOR, lispMEX, LSL 1]
 LISPMULADD
.endm
INSTORG DUST, 8
INSTORG DUST, 0xC

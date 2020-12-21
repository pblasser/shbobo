@SHLISP "WANILLA" ASSEMBLAGE 
@COPYLEFT SHBOBO PLZ MUTATE

ORIGINATE

.macro PRESSR
 VAKLORD comprVALE
 POPSEX
 mov lispACC, lispRET
 POPSEX
 RECTA lispWOR, lispRET
 POPSEX
 RECTARET
 SYNTHLOADER workTWO, comprSWANG
 ldr workONE, [workTWO, lispMEX, lsl 2]
 RECTA workTRI, lispACC
 cmp workTRI, workONE, asr 0x10
 ite gt 
 addsgt lispWOR, workONE, lispWOR, lsl 4
 subsle lispWOR, workONE, lispRET
 it mi
 movmi lispWOR, 0
 str lispWOR, [workTWO, lispMEX, lsl 2]
 POPSEX
 sub lispRET, lispRET, lispWOR, asr 0x10
 mul lispACC, lispACC, lispRET
 @asr lispACC, lispACC, 0x8
 ALSERACK
 SUSATACK
 LISPMULADD
.endm
INSTORG PRESSR, 0


.macro LIKDC
 VAKLORD likdcVALE
 POPSEX
 mov lispACC, lispRET
 POPSEX
 RECTARET
 lsr lispRET, lispRET, 0x8
 SYNTHLOADER workTWO, likdcSWANG
 ldr workONE, [workTWO, lispMEX, lsl 2]

 lsl workFOR, lispRET, 0x10
 .ifeq ARAB
 rsb workTRI, workFOR, 0x80000000
 smull workONE, workTRI, workONE, workTRI
 @lsl workTRI, workTRI, 0x1
 .else
 rsb workTRI, workFOR, 0x0
 umull workONE, workTRI, workONE, workTRI
 .endif

 mul workFOR, lispACC, lispRET
 add workFOR, workFOR, workTRI
 .ifeq ARAB
 lsl workTRI, workFOR, 0x1
 str workTRI, [workTWO, lispMEX, lsl 2]
 .else
 str workFOR, [workTWO, lispMEX, lsl 2]
 .endif
 
 ALSER workFOR
 SUSAT workFOR
 
@hipass:

 sub lispACC, lispACC, workFOR
 SUSATACK
 LISPMULADD
.endm
INSTORG LIKDC, 4

.macro WAVESHAPR @inn thresh
 POPSEX
 mov lispACC, lispRET
 POPSEX
 NUTTS
4:
 RECTARET
 .ifeq ARAB
  sdiv workONE, lispACC, lispRET
  cmp workONE, 0
  beq 5f
  ittee lt
  sublt workTWO, workONE, 1
  mullt workTWO, workTWO, lispRET
  addge workONE, workONE, 1
  mulge workTWO, workONE, lispRET
  tst workONE, 2 
 .else
  udiv workONE, lispACC, lispRET
  mul workTWO, workONE, lispRET
  tst workONE, 1
 .endif
 ite ne 
 subne lispACC, workTWO, lispACC
 subeq lispACC, lispACC, workTWO
 LISPMULADD  @b 8f
5:
 RECTARET
 .ifeq ARAB
  sdiv lispWOR, lispACC, lispRET
 .else
  udiv lispWOR, lispACC, lispRET
 .endif
 mul lispWOR, lispWOR, lispRET
 sub lispACC, lispACC, lispWOR
 LISPMULADD  @b 8f
6:
 and lispACC, lispACC, lispRET
 LISPMULADD  @b 8f
7:
 eor lispACC, lispACC, lispRET
 LISPMULADD  @b 8f
8: 
@ LISPMULADD
.endm
INSTORG WAVESHAPR, 8
@redundant
INSTORG WAVESHAPR, 0xC

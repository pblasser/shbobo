@SHLISP "WANILLA" ASSEMBLAGE 
@COPYLEFT SHBOBO PLZ MUTATE

ORIGINATE

.macro RECTA out, reg
 .ifeq ARAB
 cmp \reg, 0
 it lt
 rsblt \out, \reg, 0
 .else
 usat \out, 0x10, \reg
 .endif
.endm
.macro RECTAR acc
 RECTA \acc, \acc
.endm
.macro RECTARET
 RECTAR lispRET
.endm

.macro TRANGO_IDEE_NUME acc, gwonzname
 @assert acc=lispACC or workONE
 @assert lispWOR=&trangoes
 @POPSEX or FOGDOG 2
 RECTARET
 BB workTWO,\gwonzname,lispMEX
 cmp workTWO, 1
 ite eq
 addeq \acc, \acc, lispRET, ASR 4
 subne \acc, \acc, lispRET, ASR 4
 strh \acc, [lispWOR, lispMEX, LSL 1]
.endm

.macro TRANGO_IDEE_DENO acc, gwonzname
 @assert acc=lispACC or workONE
 @assert lispWOR=&trangoes
 @POPSEX or FOGDOG 2
 RECTARET
 BITBAND workTWO, \gwonzname
 subs workTRI, \acc, lispRET
 itttt gt 
 movgt workFOR, 0
 strgt workFOR, [workTWO, lispMEX, LSL 2]
 subgt \acc, \acc, workTRI, lsl 1
 strhgt \acc, [lispWOR, lispMEX, LSL 1]
 .ifeq ARAB
 @addsle workTRI, \acc, lispRET
 adds workTRI, \acc, lispRET
 .else 
 @movsle workTRI, \acc
 movs workTRI, \acc
 .endif
 itttt lt
 movlt workFOR, 1
 strlt workFOR, [workTWO, lispMEX, LSL 2]
 sublt \acc, \acc, workTRI, lsl 1
 strhlt \acc, [lispWOR, lispMEX, LSL 1]
.endm

.macro VAKLORDEIGHT vale
 and lispMEX, lispMEX, #7 @!!!!
 SYNTHLOADER lispWOR,\vale
 LOADERH lispACC, lispWOR
.endm

.macro TRANGO
 VAKLORDEIGHT trangoes

 POPSEX
 TRANGO_IDEE_NUME lispACC, trangwonz
 
 POPSEX
 TRANGO_IDEE_DENO lispACC, trangwonz
 
 LISPMULADD
.endm
INSTORG TRANGO, 0
INSTORG TRANGO, 4

.macro TRANSA_IDEE_NUME acc, dum
 @assert acc=lispACC or workONE
 @assert lispWOR=&transaws
 @POPSEX or FOGDOG 2
 RECTARET
 add \acc, \acc, lispRET, ASR 4
 strh \acc, [lispWOR, lispMEX, LSL 1]
.endm

.macro TRANSA_IDEE_DENO acc, dum
 @assert acc=lispACC or workONE
 @assert lispWOR=&transaws
 @POPSEX or FOGDOG 2
 RECTARET
 subs workTWO, \acc, lispRET
 itt gt 
 .ifeq ARAB 
 subgt \acc, workTWO, lispRET  @, LSL 1
 .else
 subgt \acc, \acc, lispRET  @, LSL 1
 .endif
 strhgt \acc, [lispWOR, lispMEX, LSL 1]
.endm

.macro TRANSA
 VAKLORDEIGHT transaws

 POPSEX
 TRANSA_IDEE_NUME lispACC, 0
 
 POPSEX
 TRANSA_IDEE_DENO lispACC, 0
 
 LISPMULADD
.endm
INSTORG TRANSA, 8
INSTORG TRANSA, 0xC

@SHLISP "WANILLA" ASSEMBLAGE 
@COPYLEFT SHBOBO PLZ MUTATE

ORIGINATE

.macro SWOOP_IDEE_NUME acc, gwonzname
 @assert acc=lispACC or workONE
 @assert lispWOR=&trangoes
 @POPSEX or FOGDOG 2
 RECTARET
 SYNTHLOADER workTRI,\gwonzname
 ldrb workTWO, [workTRI, lispMEX]
 .ifeq ARAB
 and workTWO, workTWO, 3
 cmp workTWO, 2
 .else 
 and workTWO, workTWO, 1
 tst workTWO, 1
 .endif
 it eq
 subeq \acc, \acc, lispRET, ASR 8
 tst workTWO, 1
 it ne
 addne \acc, \acc, lispRET, ASR 8
 strh \acc, [lispWOR, lispMEX, LSL 1]
.endm

.macro SWOOP_IDEE_DENO acc, gwonzname
 @assert acc=lispACC or workONE
 @assert lispWOR=&trangoes
 @POPSEX or FOGDOG 2
 RECTARET
 SYNTHLOADER workTRI,\gwonzname
.ifeq ARAB
 ldrb workTWO, [workTRI, lispMEX]
 cmp workTWO, 3
 bne 1f
 cmp \acc, 0
 itt gt
 movgt \acc, 0
 strbgt \acc, [workTRI,lispMEX]
1: @norton
 subs workFOR, \acc, lispRET
 @cmp \acc, lispRET
 ittte gt
 movgt workTWO, 2
 strbgt workTWO, [workTRI, lispMEX]
 @subgt \acc, \acc, workFOR, lsl 1
 movgt \acc, lispRET
@@@@@@@@@@@@ddoesz this seem to fix the fogbug?
 addsle workFOR, \acc, lispRET
 @cmnle \acc, lispRET
 ittt le
 movle workTWO, 3
 strble workTWO, [workTRI, lispMEX]
 suble \acc, \acc, workFOR, lsl 1
.else
 subs workFOR, \acc, lispRET
 @cmp \acc, lispRET
 ittte gt
 movgt workTWO, 0
 strbgt workTWO, [workTRI, lispMEX]
 @subgt \acc, \acc, workFOR, lsl 1
 @too fix fogbug 
 movgt \acc, lispRET
 cmple \acc, 0
 it lt
 movlt \acc, 0
.endif
 strh \acc, [lispWOR,lispMEX,LSL 1]
.endm

.macro SWOOP @trig nume deno mul add
 VAKLORDEIGHT swoopVALES
 POPSEX
 TRIG_IDEE_TOO lispRET, workTWO, swooptrig, workTRI
 SYNTHLOADER workTRI, swoopGWONZ
 ittt ne
 @ldrne workTRI,=swoopGWONZ
 ldrbne workTWO, [workTRI, lispMEX]
 orrne workTWO, 1
 strbne workTWO, [workTRI, lispMEX]
 POPSEX
 SWOOP_IDEE_NUME lispACC, swoopGWONZ
 POPSEX
 SWOOP_IDEE_DENO lispACC, swoopGWONZ
 LISPMULADD
 .ltorg
.endm
INSTORG SWOOP, 0
INSTORG SWOOP, 4
 
.macro ALSEROUP
 .ifeq ARAB
 asr lispACC, lispACC, 0x10
 .else
 lsr lispACC, lispACC, 0x10
 .endif
.endm

.macro MOUNT
 and lispMEX, lispMEX, #7
 SYNTHLOADER lispWOR, mountVALES
 ldr lispACC, [lispWOR, lispMEX, LSL 2]
 ALSEROUP @lispACC 

 POPSEX
 ldr lispACC, [lispWOR, lispMEX, LSL 2]
 RECTARET
 BB workTWO,lfogwonz,lispMEX
 cmp workTWO, 1
 ite eq
 addeq lispACC, lispACC, lispRET @, LSL 4
 subne lispACC, lispACC, lispRET @, LSL 4
 str lispACC, [lispWOR, lispMEX, LSL 2]

 POPSEX
 RECTARET
 BITBAND workTWO, lfogwonz
 subs workTRI, lispACC, lispRET, lsl 0x10
 itttt gt 
 movgt workFOR, 0
 strgt workFOR, [workTWO, lispMEX, LSL 2]
 subgt lispACC, lispACC, workTRI, lsl 1
 strgt lispACC, [lispWOR, lispMEX, LSL 2]
 .ifeq ARAB
 adds workTRI, lispACC, lispRET, lsl 0x10
 .else 
 movs workTRI, lispACC
 .endif
 itttt lt
 movlt workFOR, 1
 strlt workFOR, [workTWO, lispMEX, LSL 2]
 sublt lispACC, lispACC, workTRI, lsl 1
 strlt lispACC, [lispWOR, lispMEX, LSL 2]

 ALSEROUP @lispACC
 LISPMULADD
.endm
INSTORG MOUNT, 8
INSTORG MOUNT, 0xC

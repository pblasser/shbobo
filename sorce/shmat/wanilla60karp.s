@SHLISP "WANILLA" ASSEMBLAGE 
@COPYLEFT SHBOBO PLZ MUTATE

ORIGINATE

.macro PULSE_MEAT_IDEE3 acc, lrd, val
 SYNTHLOADER \lrd, \val
 @ldr workONE, =karpPULSZ
 @cmp workTWO, 1
 ite ne
 movne \acc, 0x7F00
 ldrsheq \acc, [\lrd, lispMEX, lsl 1]
 mov workTRI, 0x7E00
 mul \acc, \acc, workTRI
 asr \acc, \acc, 0xF
 strh \acc, [\lrd, lispMEX, lsl 1]
.endm

.macro BUFFLOAD1 acc
 SYNTHLOADER workONE, karpBUFFA
 add workONE, workONE, lispMEX, lsl 12
 .ifeq ARAB
 ldrsh \acc, [workONE, lispWOR, lsl 1]
 .else
 ldrh \acc, [workONE, lispWOR, lsl 1]
 .endif
.endm

.macro COMBSEAT
 and lispMEX, lispMEX, #3
 SYNTHLOADER lispWOR, karpPLACZ
 ldrh lispWOR, [lispWOR, lispMEX, lsl 1]
 BUFFLOAD1 lispACC
.endm

.macro COMBMEAT
 POPSEX
 SYNTHLOADER lispWOR, karpPLACZ
 ldrh lispWOR, [lispWOR, lispMEX, lsl 1]
 .ifeq ARAB
  add lispWOR, lispWOR, lispRET, asr 8
 .else
  add lispWOR, lispWOR, lispRET, lsr 8
 .endif
 usat lispWOR, 11, lispWOR
 SYNTHLOADER workONE, karpPLACZ
 strh lispWOR, [workONE, lispMEX, lsl 1]
 
 POPSEX
 RECTARET
 cmp lispWOR, lispRET, lsr 5 @8
 it ge
 movge lispWOR, 0
@this could also be wraparound in the zixlaz matrix, for fractal imagery
@gonna make a byte melody too. experiment rewriting in shtar
@case for using mul as matrix generator: e.g. 13 bytes of code and 256 table, that's 269


 ldrb lispRET, [lispCOD]
 cmp lispRET, 0
 beq 6f
 POPSEX @feedba
 BUFFLOAD1 workTRI
 mul workTRI, workTRI, lispRET
 ALSER workTRI
 add lispACC, lispACC, workTRI
 asr lispACC, lispACC, 1
 SUSATACK
 strh lispACC, [workONE, lispWOR, lsl 1]
 SYNTHLOADER workONE, karpPLACZ
 strh lispWOR, [workONE, lispMEX, lsl 1]
 LISPMULADD
6:
 BUFFLOAD1 workTRI
 add lispACC, lispACC, workTRI
 asr lispACC, lispACC, 1
 SUSATACK
 strh lispACC, [workONE, lispWOR, lsl 1]
 SYNTHLOADER workONE, karpPLACZ
 strh lispWOR, [workONE, lispMEX, lsl 1]
 POPSEX
 b 6b
.endm

.macro ZITHTRIG
 VAKLORD zithVALES
 POPSEX
 mov lispACC, 0
 TRIG_IDEE_TOO lispRET, lispWOR, zithtrig, workTRI
 SYNTHLOADER workONE, zithSTRNG
 ldrb workTWO, [workONE, lispMEX] @byte
 ittt ne @incrementing plaz
 addne workTWO, workTWO, 1
 andne workTWO, workTWO, 3
 strbne workTWO, [workONE, lispMEX]
 PULSE_MEAT_IDEE3 workTWO, workONE, zithPULSZ
 NOISE_MEAT_IDEE4 workTRI, workONE, karpNOISZ
 ldrsh workTRI, [workONE, lispMEX, LSL 1] 
 mul workTWO, workTWO, workTRI
 ALSER workTWO
 @asr workTWO, workTWO, 0xF
 add lispACC, lispACC, workTWO

 SYNTHLOADER workONE, zithSTRNG
 ldrb workTWO, [workONE, lispMEX] @byte
 add lispMEX, lispMEX, workTWO, LSL 2 

 POPSEX
 RECTARET
 lsr lispRET, lispRET, 8
 cmp lispWOR, 1
 itt eq
 ldreq workONE, =zithNNNN
 strbeq lispRET, [workONE, lispMEX]
 @and lispMEX, lispMEX, #3 
.endm

.macro ZITHDOG 
 SYNTHLOADER lispRET, zithNNNN
 ldrb lispRET, [lispRET, lispMEX]
.endm

.macro ZITHMEAT numb
 SYNTHLOADER lispWOR, zithPLACZ
 ldrb workTWO, [lispWOR, lispMEX]
 SYNTHLOADER workONE, karpBUFFA
 @@@@@@@@@Zither frag bug next two lines makes workTRI
 @july 4 2013 peterb
 lsr workTRI, lispMEX, 2
 bfi workTRI, lispMEX, 2, 2
 add workONE, workONE, workTRI, lsl 10
 @add workONE, workONE, lispMEX, lsl 10
 .ifeq ARAB
 ldrsh workTRI, [workONE, workTWO, lsl 1]
 .else
 ldrh workTRI, [workONE, workTWO, lsl 1]
 .endif
 @add lispACC, workTRI, lispACC
 add workTWO, workTWO, 1
 cmp workTWO, lispRET
 it ge
 movge workTWO, 0
 strb workTWO, [lispWOR, lispMEX]
 .ifeq ARAB
 ldrsh workFOR, [workONE, workTWO, lsl 1]
 .else
 ldrh workFOR, [workONE, workTWO, lsl 1]
 .endif
 mov lispWOR, 0x7F00
 mul workFOR, workFOR, lispWOR
 ALSER workFOR
 add workFOR, workFOR, workTRI
 asr workFOR, workFOR, 1
 .ifeq \numb
 add workFOR, workFOR, lispACC
 mov lispACC, 0
 .endif
 SUSAT workFOR
 strh workFOR, [workONE, workTWO, lsl 1]
 add lispACC, lispACC, workFOR
 add lispMEX, lispMEX, 0x4
 and lispMEX, lispMEX, 0xF
.endm

.macro ZITHER @zith trig deno mul add
 ZITHTRIG
 ZITHDOG
 ZITHMEAT 0
 ZITHDOG
 ZITHMEAT 1
 ZITHDOG
 ZITHMEAT 2
 ZITHDOG
 ZITHMEAT 3
@ SUSATACK
 SYNTHLOADER workONE, zithVALES
 and lispMEX, lispMEX, 3
 strh lispACC, [workONE, lispMEX, LSL 1]
 LISPMULADD
.endm

.macro KARP   @ karp trig deno mul add
 COMBSEAT
 POPSEX
 TRIG_IDEE_TOO lispRET, workTWO, karptrig, workTRI
 PULSE_MEAT_IDEE3 workTWO, workONE, karpPULSZ
 NOISE_MEAT_IDEE4 workTRI, workONE, karpNOISZ
 ldrsh workTRI, [workONE, lispMEX, LSL 1] 
 mul workTWO, workTWO, workTRI
 asr workTWO, workTWO, 0xF
 add lispACC, lispACC, workTWO
 COMBMEAT
.endm
INSTORG KARP, 0
 
.macro COMB 
 COMBSEAT
 POPSEX
 add lispACC, lispACC, lispRET
 COMBMEAT
.endm
INSTORG COMB, 4

.macro COCO


.endm


INSTORG ZITHER, 8
@redundant zither
INSTORG ZITHER, 0xC

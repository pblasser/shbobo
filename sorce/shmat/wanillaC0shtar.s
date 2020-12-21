@SHLISP "WANILLA" ASSEMBLAGE 
@COPYLEFT SHBOBO PLZ MUTATE

ORIGINATE

.macro MELOLOAD acc
 and lispMEX, lispMEX, 3
 SYNTHLOADER lispWOR, meloPLACZ
 ldr lispWOR, [lispWOR, lispMEX, lsl 2]
 SYNTHLOADER workONE, karpBUFFA
 add workONE, workONE, lispMEX, lsl 12
 add lispWOR, workONE, lispWOR, lsr 20
 .ifeq ARAB
 ldrsb \acc, [lispWOR]
 .else
 ldrb \acc, [lispWOR]
 .endif
 lsl \acc, \acc, 8
.endm

.macro MELOINN
 POPSEX
 @cmp lispRET, 0
 @ite lt
 @rsblt workONE, lispRET, 0
 mov workONE, lispRET
 @RECTA workONE, lispRET
 @mov lispACC, 0x1000
 @mov workONE, 0
 cmp workONE, 0x400
 ittt ge
 movge lispACC, lispRET
 asrge workONE, lispACC, 8
 strbge workONE, [lispWOR]
.endm

.macro MELOGATE
 POPSEX
 cmp lispRET, 0
 it gt
 orrgt lispWOR, lispWOR, 0x80000000
 @here's an interesting hack
 @use the top bit of file reference
 @to indicate punch on file
 @for next input;
 @checked at arm infocenter
 @and these srams are not negative
.endm
 
 .macro MELON
 POPSEX
 tst lispWOR, 0x80000000
 itttt ne
 movne lispACC, lispRET
 andne lispWOR, 0x7FFFFFFF
 asrne workONE, lispACC, 8
 strbne workONE, [lispWOR]
 .endm
 
.macro MELONUME
 POPSEX
 SYNTHLOADER workONE, meloPLACZ 
 ldr lispWOR, [workONE, lispMEX, lsl 2]
 add lispWOR, lispWOR, lispRET 
 str lispWOR, [workONE, lispMEX, lsl 2]
@ asr lispACC, lispWOR, 20

.endm

.macro MELOSKIP
 POPSEX
 SYNTHLOADER workONE, meloPULSZ
 SYNTHLOADER workTWO, meloPLACZ
 usat lispRET, 1, lispRET
 BBTOO workTRI,workFOR,karptrig,lispMEX
 str lispRET, [workFOR, lispMEX, lsl 2]
 eor workFOR, lispRET, workTRI
 tst workFOR, workTRI
 itt ne
 ldrne lispWOR, [workTWO, lispMEX, lsl 2]
 strne lispWOR, [workONE, lispMEX, lsl 2]
 tst workFOR, lispRET
 itt ne
 ldrne lispWOR, [workONE, lispMEX, lsl 2]
 strne lispWOR, [workTWO, lispMEX, lsl 2]
.endm
  


.macro MELODY
 MELOLOAD lispACC
 MELOGATE
 MELON
 MELONUME
 MELOSKIP
 LISPMULADD
.endm
INSTORG MELODY, 0


.macro WORM
 VAKLORD wormVALES
 POPSEX
 
 .ifeq ARAB
 cmp lispRET, 0
 it lt
 rsblt lispRET, lispRET, 0
 ssat lispRET, 0x10, lispRET, lsl 0
 .else
 usat lispRET, 0x10, lispRET, lsl 0
 .endif 
 cmp lispRET, lispACC
 it gt
 movgt lispACC, lispRET
 cmp lispACC, 0
 it gt
 subgt lispACC, lispACC, 1
 strh lispACC, [lispWOR, lispMEX, LSL 1]
 LISPMULADD
.endm
INSTORG WORM, 4

.macro SCALE
 and lispMEX, lispMEX, #3
 POPSEX
 .ifeq ARAB
 ssat lispRET, 7, lispRET, asr 9
 .else 
 usat lispRET, 6, lispRET, asr 10
 .endif
 bic lispRET, lispRET, 0x1
 
 .ifeq ARAB
 ldr lispWOR, =tarball
 .else
 ldr lispWOR, =tarbass
 .endif
 ldrh lispACC, [lispWOR, lispRET]
 .ifeq ARAB
 asr lispACC, lispACC, 1
 .endif

 LISPMULADD
.endm
INSTORG SCALE, 8
.ltorg
tarbass:

.hword	4444
.hword	4628
.hword	4821
.hword	5022
.hword	5231
.hword	5448
.hword	5675
.hword	5911
.hword	6157
.hword	6414
.hword	6681
.hword	6959
.hword	7248
.hword	7550
.hword	7864
.hword	8192
.hword	8532
.hword	8888
.hword	9257
.hword	9643
.hword	10044
.hword	10462
.hword	10897
.hword	11351
.hword	11823
.hword	12315
.hword	12828
.hword	13362
.hword	13918
.hword	14497
.hword	15100
.hword	15729
tarball:

.hword	16384
.hword	17065
.hword	17776
.hword	18515
.hword	19286
.hword	20088
.hword	20925
.hword	21795
.hword	22702
.hword	23647
.hword	24631
.hword	25656
.hword	26724
.hword	27836
.hword	28995
.hword	30201
.hword	31458
.hword	32768
.hword	34131
.hword	35552
.hword	37031
.hword	38572
.hword	40177
.hword	41850
.hword	43591
.hword	45405
.hword	47295
.hword	49263
.hword	51313
.hword	53449
.hword	55673
.hword	57990

.macro LADDER
 VAKLORD ladderVALES
 
 POPSEX
 RECTARET
 .ifeq ARAB
 lsr scanSCAN, lispRET, 0xA
 .else 
 lsr scanSCAN, lispRET, 0xB
 .endif

 SCANSOR_IDEE_PREPTOO

 1:
.rept 16
 cmp scanSCAN, 0
 beq 2f @lively
 SCANSOR_TESTICLES
 @closure repeat
 itttt eq
 subeq scanSCAN, 1
 ldrbeq lispRET, [lispCOD]
 cmpeq lispRET, 0
 moveq lispCOD, scanCODE
.endr
 b 1b

 2: @lively
 POPSEX
 mov lispACC, lispRET
 SYNTHLOADER workONE, ladderVALES
 strh lispRET, [workONE, lispMEX, LSL 1]
 SCANSOR_IDEE_END 
 .ltorg
.endm


 INSTORG LADDER, 0xC

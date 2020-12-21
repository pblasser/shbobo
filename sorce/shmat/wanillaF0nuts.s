@SHLISP "WANILLA" ASSEMBLAGE 
@COPYLEFT SHBOBO PLZ MUTATE

.equ GPIOC_ODR, 0x4001100C
ORIGINATE

QUARTEREPEATR = 4
.macro OUTLOUTRTRIGMODO
 NUTTS
@july nin 13 reverse RITE LEFT!
4:
 mov lispACC, dacRITE
 .rept QUARTEREPEATR
 POPSEX
 add dacRITE, dacRITE, lispRET
 mov lispACC, dacRITE
 .endr
 b 4b
5:
 mov lispACC, dacLEFT
 .rept QUARTEREPEATR
 POPSEX
 add dacLEFT, dacLEFT, lispRET
 mov lispACC, dacLEFT
 .endr
 b 5b
6: @trig inn ref
 .ifeq ARAB
 mvn lispACC, 0xFF
 .else
 movw lispACC, 0xFF00
 .endif
 POPSEX
 @mov lispACC, lispRET
 movs lispWOR, lispRET
 ite gt
 .ifeq ARAB 
 movgt lispACC, 0x8000 
 .else
 movgt lispACC, 0x10000 
 .endif
 movle lispACC, 0
 POPSEX
 cmp lispWOR, lispRET 
 @cmp lispACC, lispRET
 ite gt
 .ifeq ARAB 
 movgt lispACC, 0x8000 
 .else
 movgt lispACC, 0x10000 
 .endif
 movle lispACC,0
 LISPMULADD
7: @modo inn mod mul add
 mov lispACC, 0
 POPSEX
 mov lispACC, lispRET
 POPSEX
 asr lispRET, lispRET, 8
 mul lispACC, lispACC, lispRET
 @.ifeq ARAB
 @sxth lispACC, lispACC
 @.else
 @uxth lispACC, lispACC
 @.endif 
 LISPMULADD
.endm
INSTORG OUTLOUTRTRIGMODO, 0

.equ SYSTICK_RELOAD, 0xE000E014 
.macro SRATEMULADDTARBUTT
 NUTTS
4: @  SRATE 0xF4
 BBTOO lispACC, workONE, jumpsrattrig, lispMEX
 eor lispACC, lispACC, 1
 str lispACC, [workONE, lispMEX, LSL #2]
 .ifeq ARAB
 lsl lispACC, lispACC, 0xF
 .else
 lsl lispACC, lispACC, 0x10
 .endif
 SYNTHLOAD lispMEX, SYSTICK_RELOAD @nutMEX
 mov lispWOR, 0
1:
 .rept QUARTEREPEATR
 POPSEX
 adds lispWOR, lispWOR, lispRET
 it le
 rsble lispWOR, lispWOR, 1
 str lispWOR, [lispMEX]
 .endr
 b 1b
5: @MUL 0xF5
 mov lispACC, 0
 POPSEX
 mov lispACC, lispRET
 LISPMULADD
6: @ADD 0xF6
 mov lispACC, 0
 POPSEX 
 mov lispACC, lispRET
1:
 .rept QUARTEREPEATR
 POPSEX
 add lispACC, lispACC, lispRET
 SUSATACK
 .endr
 b 1b
7: @TARBUTT 0xF7
 SYNTHLOAD lispWOR, GPIOA_IDR
 ldrh lispWOR, [lispWOR] 
 .ifeq SHBOBO
 tst lispWOR, 2
 .else
 mvn lispWOR, lispWOR
 tst lispWOR, 0x400
 .endif
 HIGHSTATE
 moveq lispACC, 0
 LISPMULADD
.endm
INSTORG SRATEMULADDTARBUTT, 4

.equ GPIOA_ODR, 0x4001080C
.macro BENDJUMPPANSHORT
 NUTTS
4:
 .rept 2
 POPSEX
 lsr lispRET, lispRET, 8
 sxtb lispRET, lispRET
 SYNTHLOADER lispWOR, witch_vectore
 ldrb lispACC, [lispWOR]
 add lispACC, lispACC, lispRET
 strb lispACC, [lispWOR]
 @strb lispRET, [lispWOR]
 .endr
 b 4b
5:
 mov lispACC, 0
1:
 .rept 2
 POPEEK
 beq 2f
 POPSEX
 add lispACC, lispACC, lispRET
 .endr
 b 1b
2:
 mov lispRET, lispACC
 TRIG_IDEE_PRIMITIF lispRET, lispWOR, jumpsrattrig, workONE
 bne 3f
 POPSEX
 b 5b

3: @ACTIVE
@july seventee bne to save time
 lsr lispRET, lispACC, 8
 sxtb lispRET, lispRET
 SYNTHLOADER workONE, witch_vectore
 ldrb lispACC, [workONE]
 add lispACC, lispACC, lispRET
@july nin of 13, test to see if neg, then put vexamt in witch
 mov workTWO, 0x10000 @lispVectors
 ldrb workTWO, [workTWO,1] @get vexamt
 tst lispACC, 1<<31
 it ne
 movne lispACC, workTWO @, 1
 @tst lispWOR, 1
 @itttt ne
 strb lispACC, [workONE]

.ifeq SHBOBO @lights only on shnth
 ldr lispWOR, =GPIOC_ODR
 lsl lispRET, lispACC, 8
 strh lispRET, [lispWOR]
.endif
3:
 POPSEX
 @july seventee speurious popsex
 b 3b
6:  @pan inn field inn field
 .rept 2
 POPSEX
 mov lispACC, lispRET
 POPSEX
 usat lispWOR, 0xF, lispRET
 mul lispWOR, lispACC, lispWOR
 ALSER lispWOR
 add dacLEFT, dacLEFT, lispWOR
 .ifeq ARAB
 rsb lispWOR, lispRET, 0
 .else
 rsb lispWOR, lispRET, 0x10000
 .endif
 usat lispWOR, 0xF, lispWOR
 mul lispWOR, lispACC, lispWOR
 ALSER lispWOR
 add dacRITE, dacRITE, lispWOR
 .endr
 b 6b
7: @short bigg smal AKA orange
 POPSEX
 movs lispACC, lispRET
 POPSEX
 .ifeq ARAB
 asr lispRET, lispRET, 8
 .else
 lsr lispRET, lispRET, 8
 .endif
 add lispACC, lispACC, lispRET
 POPSEX
 b 7b
.endm
INSTORG BENDJUMPPANSHORT, 8
 
.macro DIRACARABLIGHTS
 and lispMEX, lispMEX, #3
 mov lispACC, 0
 tst lispMEX, 2
 bne 2f @ledsz
1: @dirac arab
 .rept QUARTEREPEATR
 and lispSIN, lispMEX, 1
 ldrb lispRET, [lispCOD], 1
 cmp lispRET, 0
 ittt eq
 moveq lispRET, lispACC
 moveq lispSIN, 0
 POPEQE
 SEXY
 add lispACC, lispACC, lispRET
 .endr
 b 1b
2:
@july nin of 13, lights is adder of liszt
 @mov lispACC, 0
 SYNTHLOAD lispWOR, GPIOC_ODR
 .rept QUARTEREPEATR
 POPSEX
 add lispACC, lispACC, lispRET
 .ifeq SHBOBO
 strh lispACC, [lispWOR]
 .endif
 .endr
 b 2b
.endm
INSTORG DIRACARABLIGHTS, 0xC

.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0

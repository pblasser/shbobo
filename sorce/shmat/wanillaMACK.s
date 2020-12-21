@SHLISP "WANILLA" ASSEMBLAGE 
@COPYLEFT SHBOBO PLZ MUTATE


.equ BBAND, 0x22000000
.macro BITBAND r, addr
 bitref = ((\addr-bitband)<<5) + BBAND
 SYNTHLOAD \r, bitref
.endm

.macro BB r, addr, plaz
 BITBAND \r, \addr
 ldr \r, [\r, \plaz, LSL #2]
.endm

.macro BBTOO r, rt, addr, plaz
 BITBAND \rt, \addr
 ldr \r, [\rt, \plaz, LSL #2]
.endm

lispMEX .req r0
lispACC .req r1
lispWOR .req r2
lispRET .req r3
lispSIN .req r9
lispCOD .req r12

dacLEFT .req r10
dacRITE .req r11

workONE .req r4
workTWO .req r5
workTRI .req r6
workFOR .req r7
workFIV .req r8

.equ SEXPRESSON, 0x8000

#define POPPERS {lispMEX,lispACC,lispWOR,pc}

.macro POPEQE
 popeq {lispMEX,lispACC,lispWOR,pc}
.endm
.macro POPLTE
 poplt {lispMEX,lispACC,lispWOR,pc}
.endm

.macro POPEEK
 ldrb lispRET, [lispCOD]
 cmp lispRET, 0
.endm
.macro RAMP
 ldrb lispRET, [lispCOD], 1
 cmp lispRET, 0
.endm

.macro POPERAMP
 RAMP
 itt eq
 .ifeq ARAB
 ssateq lispRET, 0x10, lispACC
 .else
 usateq lispRET, 0x10, lispACC
 .endif
 @moveq lispRET, lispACC
 POPEQE
.endm

.macro SEXY
 cmp lispRET, 0xFF
 .ifeq ARAB 
 itte ne
 lslne lispRET, lispRET, 8
 sxthne lispRET, lispRET
 .else
 ite ne
 lslne lispRET, lispRET, 8
 .endif
 bleq sexpression
.endm

.macro POPSEX
 POPERAMP
 SEXY
.endm

.macro TRIG_IDEE_TOO from, twoo, trigname, ref
 usat \from, 1, \from
 BBTOO \twoo,\ref,\trigname,lispMEX
 str \from, [\ref, lispMEX, LSL #2]
 eor \twoo, \from, \twoo
 ands \twoo, \from, \twoo
.endm

.macro TRIG_IDEE_PRIMITIF from, twoo, trigname, ref
 cmp \from, 0
 it ne 
 movne \from, 1 
 @usat \from, 1, \from
 BBTOO \twoo,\ref,\trigname,lispMEX
 str \from, [\ref, lispMEX, LSL #2]
 eor \twoo, \from, \twoo
 ands \twoo, \from, \twoo
.endm

.macro SUSAT acc
 .ifeq ARAB
 ssat \acc, 0x10, \acc
 .else 
 usat \acc, 0x10, \acc
 .endif
.endm
.macro SUSATACK 
 SUSAT lispACC
.endm

.macro ALSER acc
 .ifeq ARAB
 asr \acc, \acc, 0xF
 .else 
 lsr \acc, \acc, 0x10
 .endif
.endm
.macro ALSERACK
 ALSER lispACC
.endm

.macro LOADERH vale, ref
 .ifeq ARAB
 ldrsh \vale, [\ref, lispMEX, LSL 1]
 .else
 ldrh \vale, [\ref, lispMEX, LSL 1]
 .endif
.endm

.macro VAKLORD vale
 and lispMEX, lispMEX, #3
 SYNTHLOADER lispWOR,\vale
 LOADERH lispACC, lispWOR
.endm

.macro SEXTNINER
9:
 POPSEX
 b 9b
.endm

@LISPMULADD "spinnoff zone"
.macro LISPMULADD 
9:
 .rept 2
  POPSEX
  mul lispACC, lispACC, lispRET
  ALSERACK
  POPSEX
  add lispACC, lispACC, lispRET
 .endr 
 b 9b
 .ltorg
.endm

.macro NUTTS
 and lispMEX, lispMEX, 3
 tbb [pc, lispMEX]
 1: 
 .byte ((4f-1b)/2)
 .byte ((5f-1b)/2)
 .byte ((6f-1b)/2)
 .byte ((7f-1b)/2)
.endm

.macro ORGASM plaz, phile
 .org (0x20000 + (\plaz << 9))
 .include "\phile"
 .ltorg
.endm

.macro ORIGINATE
 _origin = .
.endm

.macro SEGMENTORG plaz
 .org _origin + (\plaz<<9)
.endm

.macro INSTORG mack, orig
 ARAB = 0
 SEGMENTORG \orig 
 \mack
 ARAB = 1
 SEGMENTORG (\orig + 2)
 \mack
 ARAB = 0
.endm

@SHNTH ASSEMBLAGE 
@COPYRIGHT SHBOBO

lispMEX .req r0
lispACC .req r1
lispWOR .req r2
lispRET .req r3
lispSIN .req r9
lispCOD .req r12

@witch_vector was thought of 
@on the train in Tokyo.
@like a mini vector table 
@for the presets.
 mov lispSIN, 0
 mov lispRET, 0x10000 @lispVectors
 ldrb lispWOR, [lispRET,1] @get vexamt
 SYNTHLOADER lispACC, witch_vectore
 ldrb lispMEX, [lispACC] @get witch
 cmp lispMEX, lispWOR
 itt gt
 movgt lispMEX, 0
 strbgt lispMEX, [lispACC]
 cmp lispMEX, 0 @comp mexwitch
 itte eq 
 lsleq lispCOD, lispWOR, 1
 addeq lispCOD, lispCOD, 2
 ldrhne lispCOD, [lispRET, lispMEX, lsl 1]
 add lispCOD, lispCOD, 0x10000

overlord:
 .rept 20
 ldrb lispMEX, [lispCOD], 1
 cmp lispMEX, 0
 beq sexend
 cmp lispMEX, 0xFF
 it eq
 bleq sexpression
 .endr
 b overlord
.ltorg

.org 0x8000
sexpression:
 push {lispMEX,lispACC,lispWOR,lr}
 ldrb lispRET, [lispCOD], 1
 cmp lispRET, 0xFF
 ite ne
 lslne lispRET, lispRET, 8
 bleq sexpression @recur MEXP
 lsr lispMEX, lispRET, 8
 @mov lispMEX, lispRET
  
 and lispRET, lispMEX, 0xFC
 lsl lispRET, lispRET, 9
 add lispRET, lispRET, 0x20000
 add lispRET, lispRET, lispSIN, LSL 10
 add lispRET, lispRET, 1
 bx lispRET
sexend:
.ltorg

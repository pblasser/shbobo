@SHLISP "WANILLA" ASSEMBLAGE 
@COPYLEFT SHBOBO PLZ MUTATE

@匹 升昇速 降速 上限 下限 乘乗 加
@sidrassi nndd muladd

ORIGINATE

.macro FOURSES  
 and lispMEX, lispMEX, #3
 SYNTHLOADER workONE,foursesVALE
 LOADERH lispACC, workONE
 POPSEX
 RECTARET
 BB lispWOR,foursgwonz,lispMEX
 cmp lispWOR, 1
 it eq
 addeq lispACC, lispACC, lispRET, ASR 4
 POPSEX
 RECTARET
 cmp lispWOR, 1
 it ne
 subne lispACC, lispACC, lispRET, ASR 4
 POPSEX 
 BITBAND lispWOR, foursgwonz
 subs workONE, lispACC, lispRET
 ittt gt 
 movgt workTWO, 0
 strgt workTWO, [lispWOR, lispMEX, LSL 2]
 subgt lispACC, lispACC, workONE
 POPSEX
 subs workONE, lispACC, lispRET
 ittt lt
 movlt workTWO, 1
 strlt workTWO, [lispWOR, lispMEX, LSL 2]
 sublt lispACC, lispACC, workONE
 SYNTHLOADER workONE,foursesVALE
 strh lispACC, [workONE, lispMEX, LSL 1]
 LISPMULADD
.endm
INSTORG FOURSES, 0
 @redundant 
INSTORG FOURSES, 4
INSTORG FOURSES, 8
INSTORG FOURSES, 0xC

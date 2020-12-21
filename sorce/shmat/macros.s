@SHNTH ASSEMBLAGE 
@COPYRIGHT SHBOBO

.macro SYNTHLOAD ref, vale
 .ifeq ((\vale) & 0xFFFFFF00)
  mov \ref, (\vale)
 .else
  movw \ref, ((\vale) & 0xFFFF)
  movt \ref, ((\vale>>16) & 0xFFFF)
 .endif
.endm

.macro SYNTHLOADEREQ ref, vale
 synthref = (\vale - bitband) + 0x20000000
 movweq \ref, ((synthref) & 0xFFFF)
 movteq \ref, ((synthref>>16) & 0xFFFF)
.endm

.macro SYNTHLOADER ref, vale
 synthref = (\vale - bitband) + 0x20000000
 SYNTHLOAD \ref, synthref
.endm

.macro LODESTRA reg, val
 SYNTHLOAD r1, \reg 
 SYNTHLOAD r0, \val
 str r0, [r1]  
.endm

.macro LODMOTRA reg, val
 SYNTHLOAD r1, \reg 
 mov r0, \val
 str r0, [r1]  
.endm

.macro LODESTRAH reg, val
 SYNTHLOAD r1, \reg 
 SYNTHLOAD r0, \val
 strh r0, [r1] 
.endm

@SHLISP "WANILLA" ASSEMBLAGE 
@COPYLEFT SHBOBO PLZ MUTATE

ORIGINATE

.macro FOGGINGPREP
 @SYNTHLOADER workONE, fogNDNDZ
.endm

.macro PARMER1 ref, plaz
 POPSEX
 cmp lispWOR, 1
 ittt eq
 SYNTHLOADEREQ workONE, (\ref + \plaz)
 strheq lispRET, [workONE, lispMEX, lsl 1]
.endm
.macro FOGGING ndnd
 PARMER1 fogNDNDZ, (\ndnd<<5)
.endm

@DOGGRET
.macro DOGG ref, plaz
 SYNTHLOADER lispRET, (\ref + \plaz)
 LOADERH lispRET, lispRET
.endm
.macro FOGDOG ndnd
 SYNTHLOADER lispRET, fogNDNDZ + (\ndnd << 5)
 LOADERH lispRET, lispRET
.endm

.macro FOGTRIG 
 and lispMEX, lispMEX, #3
 SYNTHLOADER workONE, fogVALES
 ldrsh lispACC, [workONE, lispMEX, LSL 1]
 POPSEX
 TRIG_IDEE_TOO lispRET, lispWOR, fogtrig, workTRI
 SYNTHLOADER workONE, fogPLACZ
 ldrb workTWO, [workONE, lispMEX] @byte
 SYNTHLOADER workTRI, fogSWOOPgwonz
 
 tst lispWOR, 1
 ittt ne @incrementing plaz
 addne workTWO, workTWO, 1
 andne workTWO, workTWO, 3
 strbne workTWO, [workONE, lispMEX]
 itttt ne  @storring fogSWOOPgwonz
 addne workTRI, workTRI, workTWO, LSL 2
 ldrbne workFOR, [workTRI, lispMEX]
 orrne workFOR, 1
 strbne workFOR, [workTRI, lispMEX]
 add lispMEX, lispMEX, workTWO, LSL 2 
 FOGGINGPREP
 FOGGING 0
 FOGGING 1
 FOGGING 2
 FOGGING 3
 and lispMEX, lispMEX, #3  @normalize MEXP
 mov lispACC, 0
.endm

.macro FOGMEAT_IDEE_NUME mack
 SYNTHLOADER lispWOR, fogSWOOPvales
 LOADERH workONE, lispWOR
 FOGDOG 0
 SWOOP_IDEE_NUME workONE, fogSWOOPgwonz
 FOGDOG 1
 SWOOP_IDEE_DENO workONE, fogSWOOPgwonz
 SYNTHLOADER lispWOR, fogTRANGvales
 LOADERH workFIV, lispWOR
 FOGDOG 2
 \mack workFIV, fogtran
 FOGDOG 3
.endm
@room for swamp
.macro FOGMEAT_IDEE_DENO mack
 \mack workFIV, fogtran
 mul  workFIV, workFIV, workONE
 ALSER workFIV
 add lispACC, lispACC, workFIV
 add lispMEX, lispMEX, 0x4
.endm

.macro FOG @ fog trig ndnd
 FOGTRIG
8:
 FOGMEAT_IDEE_NUME TRANGO_IDEE_NUME
 FOGMEAT_IDEE_DENO TRANGO_IDEE_DENO
 FOGMEAT_IDEE_NUME TRANGO_IDEE_NUME
 FOGMEAT_IDEE_DENO TRANGO_IDEE_DENO
 cmp lispMEX, 0x10 @if 16
 bge 9f
 b 8b
9:
 SUSATACK
 SYNTHLOADER workONE, fogVALES
 @ldr workONE, =fogVALES
 and lispMEX, lispMEX, 3
 strh lispACC, [workONE, lispMEX, LSL 1]
 LISPMULADD
.endm
INSTORG FOG, 0

.macro SWAMP @ fog trig ndnd mul add
 FOGTRIG
8:
 FOGMEAT_IDEE_NUME TRANGO_IDEE_NUME
 add lispRET, lispRET, workONE
 FOGMEAT_IDEE_DENO TRANGO_IDEE_DENO
 FOGMEAT_IDEE_NUME TRANGO_IDEE_NUME
 add lispRET, lispRET, workONE
 FOGMEAT_IDEE_DENO TRANGO_IDEE_DENO
 cmp lispMEX, 0x10 @if 16
 bge 9f
 b 8b
9:
 SUSATACK
 SYNTHLOADER workONE, fogVALES
 and lispMEX, lispMEX, 3
 strh lispACC, [workONE, lispMEX, LSL 1]
 LISPMULADD
.endm
INSTORG SWAMP, 0x04

.macro FOZ @ fog trig ndnd
 FOGTRIG
8:
 FOGMEAT_IDEE_NUME TRANSA_IDEE_NUME
 FOGMEAT_IDEE_DENO TRANSA_IDEE_DENO
 FOGMEAT_IDEE_NUME TRANSA_IDEE_NUME
 FOGMEAT_IDEE_DENO TRANSA_IDEE_DENO
 cmp lispMEX, 0x10 @if 16
 bge 9f
 b 8b
9:
 SUSATACK
 SYNTHLOADER workONE, fogVALES
 and lispMEX, lispMEX, 3
 strh lispACC, [workONE, lispMEX, LSL 1]
 LISPMULADD
.endm
INSTORG FOZ, 8

@redundant FOZ
INSTORG FOZ, 0xC


@SHNTH ASSEMBLAGE 
@COPYRIGHT SHBOBO

.macro JADERPHILTE 
 ldrsh r1, [r0], 4
 ssat r2, 5, r1
 sub r1, r1, r2
 lsl r1, r1, 6
 ldrsh r2, [r3]
 mov r12, 0xE
 mul r2, r2, r12
 add r2, r2, r1
 ssat r2, 0x10, r2, asr 4
 strh r2, [r3], 2
.endm

.equ POT_GEOFF, 0x7FC
.equ POT_MULCH, 0x107

.macro JADERAB
 ldrsh r1, [r0], 4
 movw r2, POT_MULCH
 mul r1, r1, r2
 ldrsh r2, [r3]
 mov r12, 0xF
 mul r2, r2, r12
 add r2, r2, r1, asr 4
 ssat r1, 0x10, r2, asr 4
 strh r1, [r3], 2
.endm

 SYNTHLOAD r0, ADC1_JDR1
 SYNTHLOADER r3, barres

.ifeq SHBOBO
 JADERPHILTE 
 JADERPHILTE 
 JADERPHILTE 
 JADERPHILTE 
.else
 JADERAB
 JADERAB
 JADERPHILTE 
 JADERPHILTE 

 SYNTHLOAD r2, GPIOA_IDR
 ldrh r0, [r2]
 mvn r0, r0, lsl 0x16 @22
 and r0, r0, 0xF0000000  

 @GPIOC_IDR
 add r2, r2, 0x800
 ldrh r1, [r2]
 mvn r1, r1, lsl 0xC
 bfc r1, 0, 0x10
 bfc r1, 0x1C, 0x4
 orr r0, r0, r1
  
 @GPIOB_IDR
 sub r2, r2, 0x400
 ldrh r1, [r2]
 mvn r1, r1
 bfc r1, 0x10, 0x10
 orr r0, r0, r1
 str r0, [r3]
.endif

.ifeq SHBOBO
 SYNTHLOAD r0, ADC1_DR
 ldr r0, [r0]
.else
 movw r0, POT_GEOFF @0x800
.endif
 SYNTHLOAD r1, ADC1_JOFR1
 str r0, [r1], 4
 str r0, [r1], 4
 
.ifne SHBOBO
 SYNTHLOAD r0, ADC1_DR
 ldr r0, [r0]
.endif
 str r0, [r1], 4
 str r0, [r1]

 LODMOTRA ADC1_SR, 0
@ cpsie i
 bx lr 
 
.ltorg

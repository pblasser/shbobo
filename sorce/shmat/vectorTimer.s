@SHNTH ASSEMBLAGE 
@COPYRIGHT SHBOBO

.macro TIMPHILTE plaz
 SYNTHLOAD r0, (TIM2_CCR1 + (\plaz * 0x400))
 ldrh r1, [r0]
 SYNTHLOADER r0, (chinkwonkTARESZ + (\plaz<<1))
 tst r3, #0x2
 it ne
 strhne r1, [r0]
 ldrh r0, [r0]
 sub r1, r1, r0
 lsl r1, r1, 6
 SYNTHLOADER r2, (chinkwonks + (\plaz<<1))
 ldrsh r0, [r2]
 add r0, r0, r1
 ssat r0, 0x10, r0, asr 1
 strh r0, [r2]
.endm

@ cpsid i
 SYNTHLOAD r3, GPIOA_IDR
 ldrh r3, [r3]
 TIMPHILTE 0
 TIMPHILTE 1
 @LODMOTRA TIM2_SR, 0
 @LODMOTRA TIM3_SR, 0
@ cpsie i
 bx lr
.ltorg



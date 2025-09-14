@SHNTH ASSEMBLAGE 
@COPYRIGHT SHBOBO


.macro THUMBFILTA
 ldr r0, [r2]
 lsl r0, r0, 1
 bfi r0, r3, 0, 1
 lsr r3, r3, 1
 bfi r0, r3, 8, 1
 lsr r3, r3, 1
 bfi r0, r3, 16, 1
 lsr r3, r3, 1
 bfi r0, r3, 24, 1
 str r0, [r2], 4
.endm

@ cpsid i
 SYNTHLOAD r3, GPIOB_IDR
 SYNTHLOADER r2, chinkwonkTARESZ
 ldrh r3, [r3]
 eor r3, r3, 0xFFFFFFFF
 strh r3, [r2]
 @bx lr
 THUMBFILTA
 THUMBFILTA
 THUMBFILTA
 THUMBFILTA
 
 
 LODMOTRA TIM2_SR, 0
 LODMOTRA TIM1_SR, 0
@ cpsie i
 bx lr
.ltorg



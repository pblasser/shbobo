@SHNTH ASSEMBLAGE 
@COPYRIGHT SHBOBO

dacLEFT .req r10
dacRITE .req r11
.macro DACKER r, plaz
 ssat \r, 0xC, \r, asr 4
 add \r, \r , 0x800
 usat \r, 0xC, \r
 SYNTHLOAD r0, (DAC_DHR12R1  + (\plaz * 0xC))
 str \r, [r0]
 mov \r, 0
.endm

 push {lr}
 SYSTICKOFF
 @cpsid i
 DACKER dacLEFT, 0
 DACKER dacRITE, 1
 
 @SYNTHLOAD r0, GPIOA_ODR
 @mov r1, 0 @orange off
 @str r1, [r0]
 
 LODMOTRA SYSTICK_RELOAD, 0x1000
.include "sexpress.s"
 @cpsie i
 SYSTICKONN
 pop {pc}

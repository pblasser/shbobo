@SHNTH ASSEMBLAGE 
@COPYRIGHT SHBOBO

initiate:
 LODESTRA PWR_CR, 0x10
 SYNTHLOAD r0, PWR_CSR
 ldr r0, [r0]
 tst r0, 0x04
 beq notbrownd
 LODESTRA CORTEX_M3_SCB_SCR, 0x4 @use deepsleep
 LODESTRA PWR_CR, 0x2 @power down deepsleep
 wfi
 @bne initiate @brownout
 
notbrownd:
 LODESTRA RCC_CR, 0x00010081 @ HSEON
CRYST_waiter:
 SYNTHLOAD r1, RCC_CR
 ldr r1, [r1]
 SYNTHLOAD r0, 0x00020002 @ HSERDY
 tst r1, r0
 beq CRYST_waiter
 
 .equ CLOCKCONFIG, 0x001DFC00 
 @PLL times nine, from cryst
 @APB1 = 36mhz
 @APB2 = 4.5mhz
 @ADC = 562.5 khz
 LODESTRA FLASH_ACR, 0x32 @one wait state
 LODESTRA RCC_CFGR, CLOCKCONFIG @72mhz PLL
 LODESTRA RCC_CR, 0x01010081 @PLL ON 
PLL_waiter:
 SYNTHLOAD r1, RCC_CR
 ldr r1, [r1]
 SYNTHLOAD r0, 0x02020002
 tst r1, r0
 beq PLL_waiter
 LODESTRA RCC_CFGR, (CLOCKCONFIG | 2) @USEPLL

 .ifeq SHBOBO
  .equ PERIONE, 0x20000003
  LODESTRA RCC_APB2ENR, 0x00000E15 
  @ (tim1,adc2,adc1) iopc (^~_iopb iopa res afio) 
 .else
  .equ PERIONE, 0x20000000 @timers off
  LODESTRA RCC_APB2ENR, 0x0000021D
  @  (adc1 iopg) iopc (iopb iopa res afio)  
 .endif
 LODESTRA RCC_APB1ENR, PERIONE 
 LODESTRA AFIO_MAPR, 0x02000000 @4pa15 from SWs

 .ifeq SHBOBO
 LODESTRA GPIOA_CRL, 0x44000044 @float in, dac, mike mido, tare kwonk 
 LODESTRA GPIOA_CRH, 0x44444244 @pow sw, swusb+, -orange, min
 LODESTRA GPIOB_CRL, 0x88888888
 LODESTRA GPIOB_CRH, 0x88888888 
 LODESTRA GPIOB_ODR, 0x00000000
 LODESTRA GPIOC_CRL, 0x44440000 @butts and barres
 LODESTRA GPIOC_CRH, 0x22222222 @leds
 .else
 LODESTRA GPIOA_CRL, 0x88000000 @fretties, dac, mike mido, dink tonk
 LODESTRA GPIOA_CRH, 0x44444888 @pow sw, swusb+, -tar, fretties
 LODESTRA GPIOA_ODR, 0x0000FFFF
 LODESTRA GPIOB_CRL, 0x88888888 @fretties
 LODESTRA GPIOB_CRH, 0x88888888 
 LODESTRA GPIOB_ODR, 0x0000FFFF @onn
 LODESTRA GPIOC_CRL, 0x88880000 @frets and barres
 LODESTRA GPIOC_CRH, 0x88888888 @fretties
 LODESTRA GPIOC_ODR, 0x0000FFFF @onn
 .endif
 @LODESTRA AFIO_MAPR, 0x00000000 @4pa15 from SWs

 LODESTRA DAC_BOUNDARY, 0x00010001

 @100 = bars @ 13.55 khz
 @111 = bars @ 2.34 khz
 LODESTRA ADC1_SMPR1,0b11111111111111110000100100100100
 @LODESTRA ADC1_SMPR1,0xFFFFFFFF
@bot is 10,11,12,13 
 LODESTRA ADC1_SMPR2, 0xFFFFF100  
@ bot is 0,1,2
 LODESTRA ADC1_SQR3, 0x00000002 
 LODESTRA ADC1_JSQR, 0b00000000001101101011000101101010
 LODESTRA ADC1_CR1, 0x00000580 
 LODESTRA ADC1_CR2, 0x00000003 
 LODESTRA ADC1_CR2, 0x00000003 

 @LODESTRA RUPT_SETENA0, 0x30140000
 .ifeq SHBOBO @adc, usb, tim
 LODESTRA RUPT_SETENA0, 0x10140000
 .else @adc, usb
 LODESTRA RUPT_SETENA0, 0x00140000
 .endif

 .ifeq SHBOBO
  @mike 010 on chan 3 = 41.666 khz samprate
  LODESTRA ADC2_SMPR2, 0xFFFFF5FF 
  LODESTRA ADC2_SQR3, 0x00000003 
  LODESTRA ADC2_CR1, 0x00000100 
  LODESTRA ADC2_CR2, 0x00000003 
  LODESTRA ADC2_CR2, 0x00000003 

 LODESTRA TIM1_CR1, 0x1 
 LODESTRA TIM1_CCMR1, 0x60
 LODESTRA TIM1_CCER, 0x01
 LODESTRA TIM1_PSC, 0x04 @prescaler
 @apb2 = 4.5mhz div 4 = 1.125 / 64k = 17.578125
 LODESTRA TIM1_CCR1, 0xFFFD @bery high
 LODESTRA TIM1_CR2, 0x40 @OC1REF -> TRGO
 LODESTRA TIM1_CR1, 0x01 @CEN

 LODESTRA TIM2_CR1, 0x01 
 LODESTRA TIM2_CCMR1, 0x03
 LODESTRA TIM2_CCER, 0x0003 @capturefall 
 LODESTRA TIM2_SMCR, 0x4004 
 LODESTRA TIM2_CR1, 0x01 
 LODESTRA TIM2_DIER, 0x02 

 LODESTRA TIM3_CR1, 0x01 
 LODESTRA TIM3_CCMR1, 0x03
 LODESTRA TIM3_CCER, 0x0003 @capturefall
 LODESTRA TIM3_SMCR, 0x4004 
 LODESTRA TIM3_CR1, 0x01 
 LODESTRA TIM3_DIER, 0x02 
 .endif

 SYNTHLOADER r1, bitband+0x20
 mov r0, 0
 SYNTHLOADER r2, bitband+0xB000
zeroing: 
 str r0, [r1], 4
 cmp r1, r2
 blt zeroing

 SYNTHLOAD r1, GPIOA_IDR 
 ldr r1, [r1]
 tst r1, #0x8000 @check if PA15 (USBPOWER)
 bne usb_onn
 
cystick_goat:
_dummy: 
_nmi_handler:
_hard_fault:
_memory_fault:
_bus_fault:
_usage_fault:
SVCHandler:
DebugMonitor:
PendSVC:
 SYNTHLOAD r0, STACKINIT
 mov sp, r0
@b cystick_goat



 LODESTRA SYSTICK_RELOAD, 0x00000500  
 SYSTICKONN
 
cyshold:
 .rept 20
 wfi
 .endr
 b cyshold
.ltorg

usb_onn:
 INITIATUSB

 SYNTHLOAD r0, GPIOA_IDR
 ldrh r0, [r0]
.ifeq SHBOBO
 tst r0, 0x2
 beq cystick_goat
.else
 tst r0, 0x0400
 bne cystick_goat
.endif


.ifeq SHBOBO
 SYNTHLOAD r2, GPIOA_ODR
 mov r1, 0x0400
 str r1, [r2]
.endif

 mvn r0, 0x0
1:
 subs r0, r0, 1

.ifeq SHBOBO
 itte eq
 moveq r1, 0x0000
 streq r1, [r2]
.endif

 bne 1b
 b cystick_goat


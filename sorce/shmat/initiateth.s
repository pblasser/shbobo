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


  .equ PERIONE, 0x20004000
  LODESTRA RCC_APB2ENR, 0x1D 
  @ (tim1,adc2,adc1) iopc (^~_iopb iopa res afio) 

 LODESTRA RCC_APB1ENR, PERIONE 
 LODESTRA AFIO_MAPR, 0x02000000 @4pa15 from SWs

 LODESTRA GPIOA_CRL, 0x44000049 @float in, dac, mike mido, tare kwonk 
 LODESTRA GPIOA_CRH, 0x44444249 @pow sw, swusb+, -orange, min, pa8 timout
 @ LODESTRA GPIOA_ODR, 0x00000100
 LODESTRA GPIOB_CRL, 0x88888888
 LODESTRA GPIOB_CRH, 0x88888888 
  LODESTRA GPIOB_ODR,0x00000000
 LODESTRA GPIOC_CRL, 0x44440222 @butts and barres
 LODESTRA GPIOC_CRH, 0x22222222 @leds

 LODESTRAH SPI2_CR1, 0x0a3F @b37
 LODESTRAH SPI2_CR2, 0x4
 LODESTRAH SPI2_CR1, 0x0a7F @b77
 
 LODESTRAH SPI2_CR1, 0x0a7F @b77

 LODESTRAH SPI2_DR, 0x7A7A
 1:
 SYNTHLOAD r2, SPI2_SR
 ldr r3, [r2]
 tst r3, 2
 beq 1b 
 
 LODESTRAH SPI2_DR, 0x7D72
 1:
 SYNTHLOAD r2, SPI2_SR
 ldr r3, [r2]
 tst r3, 2
 beq 1b 
 LODESTRAH SPI2_DR, 0x7EFF 
 1:
 SYNTHLOAD r2, SPI2_SR
 ldr r3, [r2]
 tst r3, 2
 beq 1b 
 
 LODESTRAH SPI2_DR, 0x7D2A
 1:
 SYNTHLOAD r2, SPI2_SR
 ldr r3, [r2]
 tst r3, 2
 beq 1b 
 LODESTRAH SPI2_DR, 0x7E00
 1:
 SYNTHLOAD r2, SPI2_SR
 ldr r3, [r2]
 tst r3, 2
 beq 1b 

 LODESTRAH SPI2_DR, 0x7D24
 1:
 SYNTHLOAD r2, SPI2_SR
 ldr r3, [r2]
 tst r3, 2
 beq 1b 
 LODESTRAH SPI2_DR, 0x7E00
 1:
 SYNTHLOAD r2, SPI2_SR
 ldr r3, [r2]
 tst r3, 2
 beq 1b 

 

 
  2:
 .macro BANGSPIN amt
  mov r3, \amt
  1:
  subs r3, 1
  bne 1b
 .endm

 LODESTRA GPIOC_ODR, 0x3
 BANGSPIN 0x100000
 LODESTRA GPIOC_ODR, 0x2@cs
 
 .macro BANGCLCK
  tst r2, 0x8000    
  ite ne
  movne r0, 0x4
  moveq r0, 0x0
  str r0, [r1]
  BANGSPIN 0x400
  orr r0, 0x2
  str r0,[r1]
  BANGSPIN 0x400
 .endm  
 
 .macro BANGWORD b
  mov r2, \b
  .rept 16
  BANGCLCK
  lsl r2, 1
  .endr
  .endm
  
  BANGWORD 0x7A7A 

  BANGWORD 0x7D72
  BANGWORD 0x7EFF 

  BANGWORD 0x7D2A
  BANGWORD 0x7E00
  
  BANGWORD 0x7D24
  BANGWORD 0x7E00
  
  BANGWORD 0x7D1F
  BANGWORD 0x7E0F

  BANGWORD 0x7D71
  BANGWORD 0x7EFF  
  
  BANGWORD 0x7D73
  BANGWORD 0x7EFF
  LODESTRA GPIOC_ODR, 0x3

 
 LODESTRA DAC_BOUNDARY, 0x00010001



 @LODESTRA RUPT_SETENA0, 0x10100000
 @LODESTRA RUPT_SETENA0, 0x10140000
 LODESTRA RUPT_SETENA0, 0x18100000
 @tim2 usb
 @tim1 is 24, 25,26,27
 
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
 tst r0, 0x2
 beq cystick_goat


 mvn r0, 0x0
1:
 subs r0, r0, 1

 bne 1b
 b cystick_goat


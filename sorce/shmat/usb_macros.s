@SHNTH ASSEMBLAGE 
@COPYRIGHT SHBOBO
 
 .equ NUM_CONFIGURATIONS, 1
 .equ NUM_INTERFACES,  1
 .equ NUM_STRINGS,   2
 .equ MAX_PACKET_SIZE,  8

 .equ POWERED_STATE, 0x00
 .equ DEFAULT_STATE, 0x01
 .equ ADDRESS_STATE, 0x02
 .equ CONFIG_STATE, 0x03

 .equ DEVICE_DESC, 1
 .equ CONFIG_DESC, 2
 .equ STRING_DESC, 3
 .equ INTERF_DESC, 4
 .equ ENDPOI_DESC, 5
 .equ HID_DESC,   0x21
 .equ REPORT_DESC,  0x22
 .equ PHYSICAL_DESC, 0x23
@STANDARD REQUESTS
 .equ NO_REQUEST , 0xFF
 .equ GET_STATUS,  0x00
 .equ CLEAR_FEATURE, 0x01
 .equ SET_FEATURE,  0x03
 .equ SET_ADDRESS,  0x05
 .equ GET_DESCRIPTOR, 0x06
 .equ SET_DESCRIPTOR, 0x07
 .equ GET_CONFIGURATION, 0x08
 .equ SET_CONFIGURATION, 0x09
 .equ GET_INTERFACE, 0x0A
 .equ SET_INTERFACE, 0x0B
 .equ SYNCH_FRAME,  0x0C
@CLASS REQUESTS
 .equ GET_REPORT,  0x01
 .equ GET_IDLE,  0x02
 .equ GET_PROTOCOL, 0x03
 .equ SET_REPORT,  0x09
 .equ SET_IDLE,  0x0A
 .equ SET_PROTOCOL, 0x0B

.macro TURNOFF 
 .ifeq SHBOBO
 SYNTHLOAD r0, GPIOC_ODR
 mov r1, 0x0000
 str r1, [r0]
 .endif
.endm

.macro TURNONN
 .ifeq SHBOBO
 SYNTHLOAD r0, GPIOC_ODR
 mov r1, 0xFF00
 str r1, [r0]
 .endif
.endm

.macro TURNDON
.ifeq SHBOBO
 SYNTHLOAD r0, GPIOC_ODR
 ldrh r1, [r0]
 sub r1, r1, 0x100
 str r1, [r0]
.endif
.endm
 
.macro RESETLISPROG
 SYNTHLOADER r0, USB_lisprog_loke
 mov r1, 0
 str r1, [r0]
.endm
 
.macro SETUPACKETS
 RESETLISPROG
 LODESTRA USB_BTABLE, 0
 LODESTRA USB_ADDR0_TX, 0x10
 LODESTRA USB_COUNT0_TX, 0x08
 LODESTRA USB_ADDR0_RX, 0x18
 LODESTRA USB_COUNT0_RX, 0x1008 @BLSIZ NUMBLOCK 
 LODESTRA USB_ADDR1_TX, 0x20
 LODESTRA USB_COUNT1_TX, 0x08
 LODESTRA USB_ADDR1_RX, 0x28
 LODESTRA USB_COUNT1_RX, 0x08   @BLSIZ NUMBLOCK 
.endm

.macro SYSTICKOFF
 LODESTRA SYSTICK_CSR, 0x05 
.endm

.macro SYSTICKONN
 LODESTRA SYSTICK_CSR, 0x07 
.endm

.macro ARMEP1PHIRST
 LODESTRA USB_COUNT1_TX, 0x8
 SYNTHLOAD r1, USB_EP1R
 ldr r2, [r1]
 and r3, r2, #0x7000
 eor r3, #0x3000 @want 11
 and r2, r2, #0x70
 eor r2, #0x30
 orr r3, r3, r2
 orr r3, #0x0001 @ea 1
 orr r3, #0x0600 @interrupt
 str r3, [r1]
.endm

.macro ARMEP1
 @LODESTRA USB_COUNT1_TX, 0x8
 SYNTHLOAD r1, USB_EP1R
 ldr r2, [r1]
 and r3, r2, #0x3000
 eor r3, #0x3000 @want 11
 and r2, r2, #0x30
 eor r2, #0x30
 orr r3, r3, r2
 orr r3, #0x0001 @ea 1
 orr r3, #0x0600 @interrupt
 str r3, [r1]
.endm
 
.macro ARMEP0
 SYNTHLOAD r1, USB_EP0R
 ldr r2, [r1]
 and r3, r2, #0x3000
 eor r3, #0x3000 @want 11
 orr r3, #0x0200 @control
 and r2, #0x0030 
 eor r2, #0x0030 @want 11
 orr r3, r2, r3
 str r3, [r1]
.endm

.macro INITIATUSB
 cpsid i
 SETUPACKETS
 mov r0, 0
 SYNTHLOADER r1, USB_USWSTAT
 strb r0, [r1]
 SYNTHLOADER r1, USB_curr_config
 strb r0, [r1]
 SYNTHLOADER r1, USB_idle_rate
 strb r0, [r1]
 @mov r0, 1
 @SYNTHLOADER r1, USB_device_status
 @strb r0, [r1]
 SYNTHLOADER r1, USB_protocol
 strb r0, [r1]
 mov r0, NO_REQUEST
 SYNTHLOADER r1, USB_dev_req
 strb r0, [r1]
 
 LODESTRA RCC_APB1ENR, (PERIONE | 0x00800000)
 @DAC APB1 enable, USB clock, tim2+3 bit 0,1
 LODESTRAH USB_CNTR, 0x0001 
 @PWDN off, but fres on still
 mov r1, #0x600 @ 72 thingies
1: @lil_tstartup_loop:
 subs r1, #0x1
 bne 1b
 LODESTRAH USB_CNTR, 0x8400 
 LODESTRAH USB_ISTR, 0
 ARMEP0
 ARMEP1PHIRST
 LODESTRAH USB_DADDR, 0x80 
 cpsie i
.endm

.macro ZILP
 LODESTRA USB_COUNT0_TX, 0
.endm
 
.macro GWONZUSZEG
 ldrh r2, [r0], 2
 lsr r2, 8
 ldrh r3, [r0], 2
 and r3, 0xFF00
 orr r2, r2, r3
 strh r2, [r1], 4
.endm

.macro GWONZUSFRETS
 ldrh r2, [r0], 2
 strh r2, [r1], 4
.endm

.macro GWONZUSBUT plaz
 bfi r0, r3, \plaz+8, 1
 lsr r3, 1
 bfi r0, r12, \plaz+9, 1
 lsr r12, 1
.endm

.macro GWONZULATE broker @broke
 SYNTHLOAD r1, \broker
 SYNTHLOADER r0, barres
 GWONZUSZEG
 GWONZUSZEG
 .ifeq SHBOBO
 GWONZUSZEG
 SYNTHLOAD r2, ADC2_DR @mike
 ldrh r2, [r2]
 SYNTHLOAD r0, ADC1_DR
 ldrh r0, [r0]
 sub r2, r2, r0
 asr r2, 4
 ssat r2, 8, r2
 and r2, 0xFF
 SYNTHLOAD r3, GPIOA_IDR
 ldrh r3, [r3]
 lsr r3, #0x6
 SYNTHLOAD r12, GPIOC_IDR
 ldrh r12, [r12] @wasz r1 wrong!
 lsr r12, #0x4
 mov r0, 0
 GWONZUSBUT 0
 GWONZUSBUT 2
 GWONZUSBUT 4
 GWONZUSBUT 6
 orr r2, r0, r2
 strh r2, [r1]
 .else
 GWONZUSFRETS
 GWONZUSFRETS
 .endif
.endm


.macro THUMBUS plaz
 ldrb r2, [r0], 1
 cmp r2, 0
 it eq
 bfceq r3, \plaz, 1
.endm


.endm
.macro THUMBULATE broker @broke
 SYNTHLOAD r1, \broker
 SYNTHLOAD r0, GPIOB_IDR
 ldrh r0, [r0]
 strh r0, [r1]
.endm



.macro GWONZULATE1
 .ifne THUMB
 THUMBULATE USB_1_TX
 .else
 GWONZULATE USB_1_TX
 .endif
.endm

.macro GWONZULATE0
 LODESTRA USB_COUNT0_TX, 8
 .ifne THUMB
 THUMBULATE USB_1_TX
 .else
 GWONZULATE USB_0_TX
 .endif
.endm

.macro STALLEP0
 SYNTHLOAD r1, USB_EP0R
 ldr r2, [r1]
 and r3, r2, #0x3000
 eor r3, #0x1000 @want 01 on RX
 orr r3, #0x0200 @control
 and r2, #0x0030 
 eor r2, #0x0010 @want 01 on TX
 @eor r2, #0x0030 @want 01 on TX  YOYOYOYOYOYOYOYOYOYO
 orr r3, r2, r3
 str r3, [r1]
.endm

.macro CHECKLOKD
 SYNTHLOAD r0, FLASH_CR
 ldr r0, [r0]
 tst r0, 0x80 @is lokd
.endm

.macro CHEKBUSY
 1:
  SYNTHLOAD r0, FLASH_SR
  ldr r0, [r0]
  tst r0, 0x1 @is busy
  bne 1b
.endm

.macro SHOWLOKE
 .ifeq SHBOBO
 SYNTHLOAD r0, GPIOC_ODR
 SYNTHLOADER r1, USB_lisprog_loke
 ldr r1, [r1]
 lsl r1, 8
 str r1, [r0]
 .endif
.endm

.macro SHOWOBR
  .ifeq SHBOBO
  SYNTHLOAD r0, GPIOC_ODR
  SYNTHLOAD r1, FLASH_WRPR
  ldr r1, [r1]
  lsl r1, 8
  str r1, [r0]
 .endif
.endm
 
.macro LISPRXFLASH
  mov r0, 1
  str r0, [r4] @set PG bit
  ldrh r0, [r3], 4
  strh r0, [r2,r1]
  add r1, r1, 2
  CHEKBUSY
.endm

.macro LISPRX2FLASH
  SYNTHLOADER r0, USB_lisprog_loke
  ldr r1, [r0]
  SYNTHLOAD r2, FLASH_SPACE + 0x10000
  SYNTHLOAD r3, USB_0_RX
  SYNTHLOAD r4, FLASH_CR
	
  LISPRXFLASH
  LISPRXFLASH
  LISPRXFLASH
  LISPRXFLASH

  movw r0, 0xfff0
  movt r0, 2
  cmp r1, r0
  bge LisprogEnd
  SYNTHLOADER r0, USB_lisprog_loke
  str r1, [r0]
  @no chek of valuesz
  SHOWLOKE
.endm

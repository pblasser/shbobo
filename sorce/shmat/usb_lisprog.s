@SHNTH ASSEMBLAGE 
@COPYRIGHT SHBOBO

 cpsid i	
 cpsid i
 SYSTICKOFF
 @stallep0
 mov r0, NO_REQUEST
 SYNTHLOADER r1, USB_dev_req
 strb r0, [r1]
 SYNTHLOADER r1, USB_report_wLength
 ldrb r1, [r1]
 cmp r1, 8
 blt LisprogEnd
 SYNTHLOADER r1, USB_lisprog_loke
 ldr r2, [r1]
 movw r0, 0xfff0
 movt r0, 2
 cmp r2, r0
 itt ge 
 movge r2, 0
 strge r2, [r1]
 movw.w r3, 0x7ff
 tst r2, r3
 beq LisprogErase
 LISPRX2FLASH
 ZILP
 ARMEP0
 cpsie i
 USBX
	
LisprogEnd:
 SYNTHLOADER r0, USB_lisprog_loke
 mov r1, 0
 str r1, [r0]
 TURNONN
 ZILP
 ARMEP0
 SYSTICKONN
 cpsie i
 USBX
	
LisprogErase:
 @stallep0

 SYNTHLOAD r1, FLASH_KEYR
 CHECKLOKD

LisprogLockloop:
 itttt ne
 ldrne r0, =FLASH_KEY1
 strne r0, [r1]
 ldrne r0, =FLASH_KEY2
 strne r0, [r1]
 CHECKLOKD
 bne LisprogLockloop	

 CHEKBUSY	
 SYNTHLOAD r0, FLASH_CR
 mov r1, 2 @set PER
 str r1, [r0]
	
 @select page AR
 SYNTHLOAD r0, FLASH_AR
 mov r1, 0x10000 @+ FLASH_SPACE
 SYNTHLOADER r2, USB_lisprog_loke
 ldr r2, [r2]
 movw r3, 0xfff0
 movt r3, 2
 cmp r2, r3
 it ge
 movge r2, 0
 add r1, r1, r2
 str r1, [r0]
	
 @set STRT, PER
 SYNTHLOAD r0, FLASH_CR
 mov r1, 0x42
 str r1, [r0]
 TURNONN	
 
 CHEKBUSY
 LISPRX2FLASH
 cpsie i
 ZILP
 ARMEP0
 USBX

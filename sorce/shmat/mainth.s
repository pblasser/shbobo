@SHNTH ASSEMBLAGE 
@COPYRIGHT SHBOBO

.thumb                  
.syntax unified

.include "equates.s" 
.include "macros.s"
.include "usb_macros.s"
.include "ramus_bss.s"     
.section .text     
.org 0
vectors:        
.word STACKINIT
.word initiate + 1
.word _nmi_handler + 1  @ 
.word _hard_fault  + 1  @ 
.word _memory_fault + 1 @ 
.word _bus_fault + 1    @ 
.word _usage_fault + 1  @ 
.word 0
.word 0
.word 0
.word 0
.word SVCHandler + 1
.word DebugMonitor + 1
.word 0
.word PendSVC + 1
.word sysHandle + 1
.space (18*4),0
.word adcHandle + 1 
.word 0
.word usbHandle + 1 
.space (6*4),0 @was 7
 .word timHandle + 1 @tim2

 .word timHandle + 1 @tim1
 .space 3*4,0 @was 2
.include "initiateth.s"
.ltorg

usbHandle:
.include "vectorUSB.s"
.ltorg

adcHandle:
.include "vectorADC.s"
.ltorg

timHandle: 
.ifeq SHBOBO
 .include "vectorThimer.s"
.endif
.ltorg

sysHandle:
.include "vectorSystick.s"
.ltorg

.org 0x10000 @this is at 64k
lispVectors:
.space (0x100),0


.org 0x20000
.include "wanillaMACK.s"
ORGASM 0x00, wanilla00buttsth.s
ORGASM 0x10, wanilla10trango.s
ORGASM 0x20, wanilla20togo.s
ORGASM 0x30, wanilla30swoop.s
ORGASM 0x40, wanilla40dust.s
ORGASM 0x50, wanilla50fog.s
ORGASM 0x60, wanilla60karp.s
ORGASM 0x70, wanilla70philt.s
ORGASM 0x80, wanilla80fourses.s
ORGASM 0x90, wanilla90slewhel.s
ORGASM 0xA0, wanillaA0pulse.s
ORGASM 0xB0, wanillaB0sauce.s
ORGASM 0xC0, wanillaC0shtar.s

@ORGASM 0xD0, wanillaD0voder.s
ORGASM 0xD0, wanillaD0rungler.s

ORGASM 0xE0, wanillaE0dynamo.s
ORGASM 0xF0, wanillaF0nuts.s


.end

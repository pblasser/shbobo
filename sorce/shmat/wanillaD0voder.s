@SHLISP "WANILLA" ASSEMBLAGE 
@COPYLEFT SHBOBO PLZ MUTATE

ORIGINATE
@voder contains a togo for scansion
@a table branch for phonemes
@a big table of 32 cv patterns 
@including integration on said
@parameters, using persistance
@then it has a TRANSA_IDEE
@a NOISE_IDEE
@summed into lispRET
@then send to PHILTA
@then PHILTB
@then PHILTC

@uses all the works of scanning
.macro SCANSOR_IDEE_SILE plazbait
	SCANSOR_IDEE_PREP \plazbait
	ittt lt
	strblt scanPLAZ, [scanSREF, lispMEX] @chicken out
	movlt lispRET, 0
	POPLTE @silencio
	b 1b
.endm

.macro ANNOUNCE    @ philt inn queue freaq mul add
	VAKLORD voderVALE

	POPSEX
	TRANSA_IDEE_NUME lispACC
	
	POPSEX
	TRANSA_IDEE_DENO lispACC
	
	POPSEX
	TRIG_IDEE_TOO lispRET, lispWOR, vodertrig, workONE
	itttt ne
	ldrne workONE, =announcerPLAZ
	ldrbne workTWO, [workONE, lispMEX]
	addne workTWO, workTWO, 1
	strbne workTWO, [workONE, lispMEX]
	
	POPSEX
	cmp lispRET, 0
	ittt gt
	ldrgt workONE, =announcerPLAZ
	movgt workTWO, 0
	strbgt workTWO, [workONE, lispMEX]
	
	SCANSOR_IDEE_SILE announcerPLAZ
2: @lively
	POPSEX
	bl tbhPLAZ5
	SCANSOR_IDEE_END 
	.ltorg
.endm
INSTORG ANNOUNCE, 0 @for voder f t string

.macro VODER    @ philt inn queue freaq mul add
	VAKLORD voderVALE
	
	POPSEX
	TRANSA_IDEE_NUME lispACC
	
	POPSEX
	TRANSA_IDEE_DENO lispACC
	
	POPSEX
	TRIG_IDEE_TOO lispRET, lispWOR, vodertrig, workONE
	
	POPSEX
	tst lispWOR, 1
	it ne
	uxtbne lispRET, lispRET, ror 8
 
	bl tbhPLAZ5
	LISPMULADD
.endm
INSTORG VODER, 4 @for voder f inn

voderBUZPARM .req workONE @if 0 then unvoicd
voderNOZPARM .req workTWO
voderPHAPARM .req workTRI
voderPHEPARM .req workFOR
voderPHIPARM .req workFIV

SEGMENTORG 8
tbhPLAZ5:
	and lispRET, lispRET, 0x1F @32 plazzs
	tbh [pc, lispRET, lsl 1]
1:
	.short ((voderSILE-1b)/2)
	.short ((voderA-1b)/2)
	.short ((voderB-1b)/2)
	.short ((voderC-1b)/2)
	.short ((voderD-1b)/2)
	.short ((voderE-1b)/2)
	.short ((voderF-1b)/2)
	.short ((voderG-1b)/2)
	.short ((voderH-1b)/2)
	.short ((voderI-1b)/2)
	.short ((voderJ-1b)/2)
	.short ((voderK-1b)/2)
	.short ((voderL-1b)/2)
	.short ((voderM-1b)/2)
	.short ((voderN-1b)/2)
	.short ((voderO-1b)/2)
	.short ((voderP-1b)/2)
	.short ((voderQ-1b)/2)
	.short ((voderR-1b)/2)
	.short ((voderS-1b)/2)
	.short ((voderT-1b)/2)
	.short ((voderU-1b)/2)
	.short ((voderV-1b)/2)
	
.macro VODETO regj, parm, vale
	ldr lispRET, =\parm
	LOADERH \regj, lispRET
	cmp \regj, \vale
	it le
	addle \regj, \regj, 16
	it ge
	subge \regj, \regj, 16
	strh \regj, [lispRET, lispMEX, LSL 1]
.endm

.macro VODEIMPULSE regj, parm, vale, strt
	ldr lispRET, =\parm
	LOADERH \regj, lispRET
	tst lispWOR, 1
	it ne 
	movne \regj, \strt
	cmp \regj, \vale
	it le
	addle \regj, \regj, 16
	it ge
	subge \regj, \regj, 16
	strh \regj, [lispRET, lispMEX, LSL 1]
.endm

voderSILE:
	mov lispACC, 0
	bx lr
voderA:
	VODETO voderBUZPARM, voderBUZZPARM, 0x7000
	VODETO voderNOZPARM, voderNOIZPARM, 0
	VODETO voderPHAPARM, voderPHALPARM, 0x1000
	VODETO voderPHEPARM, voderPHELPARM, 0x5000
	VODETO voderPHIPARM, voderPHILPARM, 0x6000
	b voderVOWEL
voderB:
	VODEIMPULSE voderBUZPARM, voderBUZZPARM, 0, 0x8000
	VODEIMPULSE voderNOZPARM, voderNOIZPARM, 0, 0x8000
	VODEIMPULSE voderPHAPARM, voderPHALPARM, 0x1000, 0
	VODEIMPULSE voderPHEPARM, voderPHELPARM, 0x5000, 0
	VODEIMPULSE voderPHIPARM, voderPHILPARM, 0x6000, 0
	b voderVOWEL
voderC:
voderD:
voderE:
voderF:
voderG:
voderH:
voderI:
voderJ:
voderK:
voderL:
voderM:
voderN:
voderO:
voderP:
voderQ:
voderR:
voderS:
voderT:
voderU:
voderV:
voderW:
voderX:
voderY:
voderZ:
voderSH:
voderCH:
voderUMLAUT:
voderTRILL:
voderCLICK:
voderWHISTLE:

@SYNTH BLOXXX
voderVOWEL:
	@mov lispRET, voderBUZPARM
	mul lispACC, lispACC, voderBUZPARM
	ALSERACK
	mov lispRET, lispACC
	
	VAKLORD voderPHAL
	sub lispACC, lispRET, lispACC
	
	mov lispRET, 8 @queueu
	PHILTRE_IDEE_QUALITE lispACC, voderPHAB
	
	mov lispRET, voderPHAPARM
	PHILTRE_IDEE_PARAM lispACC, voderPHAB, voderPHAL
	bx lr
	
voderPLOSIVE:
voderFRICATIVE:

.ltorg

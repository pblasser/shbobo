;csound -Lstdin -odac csn.orc csn.sco

sr 		= 		44100
kr 		= 		4410
ksmps 	= 		10
nchnls 	= 		1
ginvo init 800

ifn 	ftgen 1 , 0,   4096,    10, 1
#define MACRONOSC # 
inote = rnd(100) + 400 
kenv linseg 0, p3/2, ginvo, p3/2, 0 
a1   	oscil   kenv, inote, 1 
       	out      a1
	endin 
#
#define MACRONBUZ # 
inote = rnd(100) + 400 
kenv linseg 0, p3/2, ginvo, p3/2, 0 
a1   	buzz   	kenv, inote, 10, 1  
        out     a1 
	endin	
#
#define MACRONPLK # 
inote = rnd(100) + 400 
kenv linseg 0, p3/2, ginvo, p3/2, 0 
a1   	pluck   	ginvo, inote, inote,0, 1  
        out     a1 
	endin	
#

	instr  	100
$MACRONPLK
	instr   101
$MACRONBUZ 
	instr  	102
$MACRONOSC 
	instr   103
$MACRONBUZ
	instr 202
endin

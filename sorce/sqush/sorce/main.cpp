//The mascots of SHLISP are
//DSP
//Macroperation
//and finally, Situations

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <errno.h> 
#include <signal.h> 
#include <string.h> 
#include <stdio.h> 
#include <stdlib.h> 
FILE * pipe;
#include "chub.h" 

int main(int argc, char * argv[]) {
 char * orc, *sco;
 //chubOPEN();
 if (argc > 2) { 
  orc = strdup(argv[1]);
  sco = strdup(argv[2]);
  char comBuf [150];
  int resin;
  resin = sprintf(comBuf, "csound -Lstdin -odac %s %s", orc, sco);
  puts(comBuf);
  pipe = popen(comBuf,"w");
 //pipe = stdout;
 //printf("i100 0 100\n");
  chubOPEN();
  chubRUN();
 }
}




#define LINUSTORWALDS

#include "stdafx.h"

#include "ging.h" //-lasound  -ldl?
#include "chub.h" 
#include "grax.h"
#include "LaceyBanks.h"

 //signed char gwonz[6];
int transferred; 

int main(int argc, char * argv[]) {
 char * inputfile;
 inputfile = 0;
 if (argc > 1) inputfile = strdup(argv[1]);
 
 open_grax();
 open_chub();
 open_pcm();

 abstr =  new LaceyBanks();
 if (inputfile) {
  printf("inputfile %s\n", inputfile);
  abstr->textorium_script(inputfile);
 }
 while (1)  {
  
  grax_switchloop();
  chub_run();
  pcm_runnus(gwonz);
 }

    chub_closz();
pcm_closz();
return 0;
}

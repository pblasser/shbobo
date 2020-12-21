
#if defined(STDTR)
#include <tr1/memory>
#define TRCOLO std::tr1::
#else
#include <memory>
#define TRCOLO std::
#endif

#include <cmath>
 #include <list>
#include <vector>
#include "SDL.h"

#if defined(STEVEJOBS)
#import <Cocoa/Cocoa.h>
#endif

#define FORI for(int i=0;i<4;i++)
#define FORJ for(int j=0;j<4;j++)
#define RMLIPPER(inn,ott) { \
if((inn>0)&(ott>0)) ott = 0;\
else if (inn>0) ott = 1;\
if((inn<0)&(ott<0)) ott = 0;\
else if (inn<0) ott = -1;\
if(inn==0) ott = 0; \
return 1; }

#define POINTSINRECTAL(p,r,i) \
((p.x>r[i].left)&(p.x<r[i].right)& \
(p.y>r[i].top)&(p.y<r[i].bottom))

#define POINTSINRECTALIS(p,r,i,j) \
((p.x>r[i][j].left)&(p.x<r[i][j].right)& \
(p.y>r[i][j].top)&(p.y<r[i][j].bottom))


#define COPYRECTAL(x,y) \
{x.left = y.left; x.right = y.right; \
x.top = y.top; x.bottom = y.bottom;}


#include "Chub.h"
#include "_chubbing.c"

#include "Prime.h"
#include "Multaple.h"
#include "Numba.h"
#include "RatChord.h"

#include "RoyalMoutarde.h"
#include "RoyalMinister.h"

#include "PerspexStabile.h"
PerspexStabile poe;

#include "Carre.h"
#include "Gambit.h"
#include "Barre.h"
#include "MultiplexPotentiator.h"

bool misterDead = false;
int chubMassage(void* data) {
 if (misterDead) return 0;
 static_cast<Chub*>(data)->chubRUN();
 return 0;
}
void gingMassage(void*par,Uint8*stream,int len) {
 if (misterDead) return;
 static_cast<MultiplexPotentiator*>(par)->ging(stream,len);
}

int main(int argc, char *argv[]) {
 MultiplexPotentiator* mp = new MultiplexPotentiator();
 
 SDL_Init(SDL_INIT_EVERYTHING);
 SDL_Window *win = SDL_CreateWindow("JI", 40,40,400,400, 
  SDL_WINDOW_RESIZABLE);
 SDL_Renderer *renderer = SDL_CreateRenderer(win, -1,
  SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
 poe.init(renderer);
 
 SDL_Thread*thred;
 if (mp->chubINIT()) {
  printf("init\n");
  thred=SDL_CreateThread(chubMassage, "chub", mp);
 }
 SDL_AudioSpec want, have;
 SDL_AudioDeviceID dev;
 SDL_zero(want);
 want.userdata = mp;
 want.freq = 44100;
 want.format = AUDIO_F32;
 want.channels = 2;
 want.samples = 512;
 want.callback = gingMassage;
 dev = SDL_OpenAudioDevice(NULL, 0, &want, &have,0);
 if (dev == 0) return 0;
 printf("format:%#x\n",have.format);
 printf("srate:%d\n",have.freq);
 printf("samples:%d\n",have.samples);
 printf("channels:%d\n",have.channels);
 SDL_PauseAudioDevice(dev, 0);  

 while (1) {
  SDL_Event e;
  if (SDL_PollEvent(&e)) {
   if (e.type == SDL_QUIT){
    //delete(mp);
    break;}
   if (e.type==SDL_WINDOWEVENT) 
    if (e.window.event==SDL_WINDOWEVENT_SIZE_CHANGED) {
			  mp->resized( e.window.data1, e.window.data2);
			  poe.init(renderer);
    }
   if (e.type==SDL_MOUSEBUTTONDOWN) 
    mp->mouseButt(e.button.x,e.button.y);
   if (e.type==SDL_KEYDOWN)
    mp->keyPress(e.key.keysym.sym);
  }
  SDL_SetRenderDrawBlendMode(renderer,SDL_BLENDMODE_BLEND);
  mp->paint(renderer);
  SDL_RenderPresent(renderer);
     //   NSOpenPanel *op = [NSOpenPanel openPanel];
    //[op setAllowsMultipleSelection:YES];
  //  [op setTitle:@"Choose File"];
    //[op setMessage:@"Choose file for Importing."];
  //  [op setFloatingPanel:true]; 
  //  bool result =[op runModalForDirectory:NSHomeDirectory() file:nil ];
 }
 misterDead = true;
 SDL_PauseAudioDevice(dev, 1);
 SDL_CloseAudioDevice(dev);
 mp->chubCLOZ();
 //SDL_WaitThread(thred, NULL);
 //delete(mp);
 printf("deleted\n");
 //SDL_WaitThread(thred, NULL);
 //SDL_DetachThread(thred);
 SDL_DestroyRenderer(renderer);
 SDL_DestroyWindow(win);
 SDL_Quit();
 
 return 0;
}

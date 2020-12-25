
#if defined(STDTR)
#include <tr1/memory>
#define TRCOLO std::tr1::
#else
#include <memory>
#define TRCOLO std::
#endif

#define GL_GLEXT_PROTOTYPES
#define LUA_COMPAT_APIINTCASTS //december 2020

#include <cmath>
#include <vector>
#include "SDL2/SDL.h"
#undef main
#include "SDL2/SDL_opengl.h"
#include "SDL2/SDL_audio.h"
#include "SDL2/SDL_video.h"
#include "lua.hpp"
//#include <OpenGL/gl3.h>
#include "grax.h"


float srate, prate;
#include "Opero.h"
#include "lunar.h"
#include "Mikey.h"
#include "luaness.h"


SDL_Event event;
bool ham = true;
void mixaudio(void *unused, Uint8 *stream, int len) {

//  if (ham) {
//  grax();
//  m.prep(); ham = false;
//  printf("audicle\n");
//  } 
//m.rendrar();
 m.collide();
 m.sounder(stream, len); 
// m.rendrar();
}
Uint32 collrunc(Uint32 interval, void *param) {
 Uint32 stardis = SDL_GetTicks();
// m.collide();
 Uint32 endus = SDL_GetTicks() - stardis;
 endus = endus % interval;
 return interval - endus;
}

SDL_AudioSpec want, have;
SDL_AudioDeviceID dev;

bool init() { 
 if( SDL_Init( SDL_INIT_EVERYTHING ) < 0 ) return false;
 grax();
 m.prep();
 SDL_zero(want);
 want.freq = 44100;
 want.format = AUDIO_F32SYS;//AUDIO_F32;
 want.channels = 2;
 want.samples = 512;//1024;//512;//4096;
 want.callback = mixaudio;  // you wrote this function elsewhere.
 dev = SDL_OpenAudioDevice(NULL, 0, &want, &have, SDL_AUDIO_ALLOW_FORMAT_CHANGE| SDL_AUDIO_ALLOW_FREQUENCY_CHANGE);
 if (dev == 0) {
  printf("Failed to open audio: %s\n", SDL_GetError());
 } else {
  if (have.format != want.format)  // we let this one thing change.
   printf("We didn't get Float32 audio format.\n");
  SDL_PauseAudioDevice(dev, 0);  // start audio playing.
 }
 srate = have.freq;
 printf("srate:%f\n",srate);
 printf("samples:%d\n",have.samples);
 sthread = SDL_CreateThread( shnthrunc, "mthread", (void *)NULL);
 //SDL_AddTimer(10, collrunc,NULL);
 prate = srate / (float)have.samples;//100
 return true;
}

void clean_up() {
 SDL_CloseAudioDevice(dev);
 SDL_Quit();
}

bool quit = false;

int mikeyspace(lua_State *L) { 
 shSpa s;
 s =  caSpa(lunar_getopero(L,1,0));
 if (s) {
  m.setSpace(s); //return 0;
  while(quit==false) {
   static Uint32 stardis = SDL_GetTicks();
   while(SDL_PollEvent(&event)) 
    if( event.type == SDL_QUIT ) 
     exit(0);     
   m.rendrar ();
   static Uint32 endus = SDL_GetTicks() - stardis;
   endus = endus % (1000 / FRAMES_PER_SECOND);
   SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - endus ); 
   if (m.spacedout()) break; //return 0;
  } m.setSpace(nospace);
 }
 return 0;
}

int mikeywarp(lua_State *L) {
 shOpr obj;
 if (obj=lunar_getopero(L,1)) {
  m.setWarp(obj);
  while(quit==false) {
   static Uint32 stardis = SDL_GetTicks();
   while(SDL_PollEvent(&event)) 
    if( event.type == SDL_QUIT ) 
     exit(0);
    m.rendrar ();
   static Uint32 endus = SDL_GetTicks() - stardis;
   endus = endus % (1000 / FRAMES_PER_SECOND);
   SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - endus ); 
   if (m.spacedout()) break; //return 0;
  } m.setWarp(nowarp);
 }
 return 0;
}

int main( int argc, char *argv[] ) {
  
 if( init() == false )  return 1;
 luainit();
 clean_up();
 return 0;
}

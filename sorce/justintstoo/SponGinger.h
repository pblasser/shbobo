
#if defined(STDTR)
#include <tr1/memory>
#define TRCOLO std::tr1::
#else
#include <memory>
#define TRCOLO std::
#endif

#define GL_GLEXT_PROTOTYPES

#include <cmath>
#include <vector>
#include "SDL.h"
//#undef main
//#include "SDL2/SDL_video.h"

//#include "SDL.h"

bool testGerono(double x, double y) {
 x = (x/100.0)- 0.5;
 y = y/100.0;
 printf("x%f y%f\n",x,y);
 return (pow(y,4)<(pow(y,2)-pow(x,4)-pow(x,2)));
}
    SDL_Renderer *renderer = NULL;
    SDL_Texture *bitmapTex = NULL;
   SDL_Rect srcrect;
Uint32 my_callbackfunc(Uint32 interval, void *param)
{

    return(10);
}


int main(int argc, char *argv[]) {
    SDL_Window *win = NULL;
 SDL_Surface *surface = NULL;
    int posX = 100, posY = 100, width = 320, height = 240;

    SDL_Init(SDL_INIT_VIDEO);

    win = SDL_CreateWindow("Hello World", posX, posY, width, height, 
    SDL_WINDOW_RESIZABLE);

    renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);

srcrect.x=0;
srcrect.y=0;
srcrect.w=100;
srcrect.h=100;

    surface = SDL_CreateRGBSurface(0, 100, 100, 32, 0, 0, 0, 0);
    SDL_LockSurface(surface);

    /* This assumes that color value zero is black. Use
       SDL_MapRGBA() for more robust surface color mapping! */
    /* height times pitch is the size of the surface's whole buffer. */
    SDL_memset(surface->pixels, 0, surface->h * surface->pitch);
  	for (int i = 0; i < surface->h; i++)
  	 for (int j = 0; j < surface->w; j++) {
  	  int offset = i * surface->w + j ;
  	  
  	  int *target_pixel = (int *)surface->pixels+offset ;
      if(testGerono(j,i)) *(Uint32 *)target_pixel = rand();
  	 }// int*ix = surface->pixels + 
  	 //((int*)surface->pixels))[i] = rand();
  	 
    SDL_UnlockSurface(surface);

    bitmapTex = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    SDL_TimerID my_timer_id = SDL_AddTimer(10, my_callbackfunc, NULL);
					 SDL_Rect sss = {(char)rand(),(char)rand(),(char)rand(),(char)rand()};
    while (1) {
        SDL_Event e;
        if (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) 
                break;
            if (e.type==SDL_WINDOWEVENT) 
              if (e.window.event==SDL_WINDOWEVENT_SIZE_CHANGED) {
				  srcrect.x=0;
srcrect.y=0;
                srcrect.w = e.window.data1;
                srcrect.h = e.window.data2;
              }

			        

        }
			  		 
					 SDL_SetRenderDrawColor(renderer,0,0,0,255);
					  SDL_RenderClear(renderer);
//SDL_RenderFillRect(renderer,&srcrect);
					 SDL_SetRenderDrawColor(renderer,rand(),rand(),rand(),255);

SDL_RenderFillRect(renderer,&sss);
        SDL_SetTextureBlendMode(bitmapTex, SDL_BLENDMODE_BLEND); 
        SDL_SetTextureAlphaMod(bitmapTex,rand());
        SDL_RenderCopy(renderer, bitmapTex, NULL, &srcrect);
        SDL_RenderPresent(renderer);
		SDL_Delay(33);

    }

    SDL_DestroyTexture(bitmapTex);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(win);

    SDL_Quit();

    return 0;
}

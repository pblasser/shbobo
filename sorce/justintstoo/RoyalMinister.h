

struct RoyalMinister : RoyalMoutarde {

 void drawMustardX(SDL_Renderer*r,int x, int y){
  SDL_Rect rrr={x-16,y,16,64};
  SDL_SetTextureAlphaMod(donks[deno_status%16],intensity*20);
  SDL_RenderCopy(r, donks[deno_status%16], NULL, &rrr);
  rrr={x-16,y-64,16,64};
  SDL_SetTextureAlphaMod(donks[nume_status%16],intensity*20);
  SDL_RenderCopy(r, donks[nume_status%16], NULL, &rrr);
 }
 void mouseButt(int x, int y) {
  if ((x<0)&&(x>-16)) {
   FORI
    if ((y>(16*i))&&(y<(16*(i+1))))
     deno_status ^= 1<<i;
   y = 0-y;
   FORI
    if ((y>(16*(3-i)))&&(y<(16*(4-i))))
     nume_status ^= 1<<i;
  }
 }
 void keyPress(SDL_Keycode k) {
  switch (k) {
   case SDLK_a: intensity=0; break;
   case SDLK_s: intensity=1;break;
   case SDLK_d: intensity=2;break;
   case SDLK_f: intensity=3;break;
   case SDLK_g: intensity=4;break;
   case SDLK_h: intensity=5;break;
   case SDLK_j: intensity=6;break;
   case SDLK_k: intensity=7;break;
   case SDLK_l: intensity=8;break;

  }
  //printf("intensityu:%d\n",intensity);
 }
};
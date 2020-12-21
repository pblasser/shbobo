

struct RoyalMoutarde {
 static SDL_Texture * dinks[16];
 static SDL_Texture * donks[16];
 int deno_status,nume_status;
 int intensity;
  static void noise(SDL_Renderer*r) {
  
 }
 RoyalMoutarde() : deno_status(rand()&rand()&15),
 nume_status(rand()&rand()&15), intensity(0) {}
	static bool testGerono(SDL_Renderer*r, double x, double y, int n) {
  x = (x/16.0);
  y = y/16.0;
 //printf("x%f y%f\n",x,y);
  double p = pow(y,2)-pow(x,4)-pow(x,2)-pow(y,4);
  if (p > 0) SDL_SetRenderDrawColor(r,rand()%n,rand()%n,rand()%n,p*1000);
  return p>0;
 }
 static void drawGerono(SDL_Renderer*r, int x, int y, int d, int n) {
  for (int i = -8; i < 8; i++)
    for (int j = -8; j < 8; j++)
     if(testGerono(r,i,j+(d*8),n)) {
      
      SDL_RenderDrawPoint(r,x+i,y+j);
     }
 }
 static bool testCircle(SDL_Renderer*r, double x, double y, int n) {
  x = (x/8.0);
  y = y/8.0;
  double p = 1.0-pow(x,2)-pow(y,2);
  if (p > 0) SDL_SetRenderDrawColor(r,rand()%n,rand()%n,rand()%n,p*256);
  return p>0;
 }
 static void drawCircle(SDL_Renderer*r, int x, int y, int n) {
  for (int i = -8; i < 8; i++)
    for (int j = -8; j < 8; j++) 
     if(testCircle(r,i,j,n)) {
     
      SDL_RenderDrawPoint(r,x+i,y+j);
     }
 }
 static void init(SDL_Renderer*r){
   for (int i =0; i<16; i++)
    dinks[i]=doTexture(r, 16, 64, i, 255);
   for (int i =0; i<16; i++)
    donks[i]=doTexture(r, 16, 64, i, 16);
 }
 static SDL_Texture * doTexture(SDL_Renderer*r, int x, int y, int n, int back) {
  SDL_Texture * tex;
  SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY,"0");
  tex = SDL_CreateTexture( r, 
   SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 
    x,y );
    SDL_SetTextureBlendMode(tex, SDL_BLENDMODE_BLEND);
  SDL_SetRenderTarget(r, tex);
  SDL_SetRenderDrawColor(r,0,0,0,0);
  SDL_SetRenderDrawBlendMode(r,SDL_BLENDMODE_NONE);
  SDL_RenderClear(r);
  
  if (n&1) drawGerono(r,x>>1,(y>>3),-1, back);
  if (n&2) drawCircle(r,x>>1,(y>>2)+(y>>3), back);
  if (n&4) drawCircle(r,x>>1,(y>>1)+(y>>3), back);
  if (n&8) drawGerono(r,x>>1,y-(y>>3),1, back);
  SDL_SetRenderTarget(r,NULL);
  return tex;
 }
 virtual void drawMustardX(SDL_Renderer*r,int x, int y){
  SDL_Rect rrr={x,y,16,64};
  SDL_SetTextureAlphaMod(dinks[deno_status%16],intensity*20);
  SDL_RenderCopy(r, dinks[deno_status%16], NULL, &rrr);
  rrr={x,y-64,16,64};
  SDL_SetTextureAlphaMod(dinks[nume_status%16],intensity*20);
  SDL_RenderCopy(r, dinks[nume_status%16], NULL, &rrr);
 }
 virtual void mouseButt(int x, int y) {
  if ((x>0)&&(x<16)) {
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
   case SDLK_q: intensity=0; break;
   case SDLK_w: intensity=1;break;
   case SDLK_e: intensity=2;break;
   case SDLK_r: intensity=3;break;
   case SDLK_t: intensity=4;break;
   case SDLK_y: intensity=5;break;
   case SDLK_u: intensity=6;break;
   case SDLK_i: intensity=7;break;
   case SDLK_o: intensity=8;break;
   case SDLK_p: intensity=9;break;
   case SDLK_LEFTBRACKET: intensity=10;break;
   case SDLK_RIGHTBRACKET: intensity=11;break;
  }
  //printf("intensityu:%d\n",intensity);
 }
};

 SDL_Texture * RoyalMoutarde::dinks[16];
  SDL_Texture * RoyalMoutarde::donks[16];
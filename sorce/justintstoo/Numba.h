
struct Limba {
 int value;
 Multaple * multna;
 SDL_Texture * numer;
 Limba() { }
 SDL_Texture * doTexture(SDL_Renderer*r, int x, int y, int d) {
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
  SDL_SetRenderDrawColor(r,rand(),rand(),rand(),255);
  drawDomino(r,x>>1,(y>>1)-(d*(y>>1)),d);
  SDL_SetRenderTarget(r,NULL);
  return tex;
 }
 void init(SDL_Renderer*r){
   numer=doTexture(r, 256, 256, 0);
 }
 ~Limba() {
  //if (multna) delete(multna);
 } 
 void drawDomino(SDL_Renderer*r,int x, int y, int d){
  int acc = y;
  Multaple * m = multna;
  while(m) {
   acc += d*m->drawHead(r,x,acc,(d==0?1:d));
   m=m->tail;
  }
 }
 void drawDominoX(SDL_Renderer*r,int x, int y){
    SDL_Rect rrr={x-128,y-128,256,256};
    SDL_RenderCopy(r, numer, NULL, &rrr);
 }
};

struct Numba : Limba {
 SDL_Texture *denor;
 Numba() {}
 void init(SDL_Renderer*r){
   numer=doTexture(r, 32, 128, 1);
    denor=doTexture(r, 32, 128, -1);
 }
 ~Numba() {
  //if (multna) delete(multna);
 } 
 void drawNume(SDL_Renderer*r,int x, int y){
 
  SDL_Rect rrr = {x-16,y-(value>>1),32,value>>1};
  
  //SDL_SetRenderDrawColor(r,rand(),rand(),rand(),128);
  
  SDL_RenderFillRect(r,&rrr);
 }
  void drawDeno(SDL_Renderer*r,int x, int y){
  SDL_Rect rrr = {x-16,y,32,value>>1};
  //SDL_SetRenderDrawBlendMode(r,SDL_BLENDMODE_BLEND);
  //SDL_SetRenderDrawColor(r,rand(),rand(),rand(),128);
  SDL_RenderFillRect(r,&rrr);
 }

 
  void drawDominoX(SDL_Renderer*r,int x, int y, int d){
   //SDL_Rect rr = {0,0,100,200};
   //SDL_Rect rrr={x,y,32,64};
//   printf("hoemanydra\n");
   //SDL_SetTextureAlphaMod(numer,rand());
   if (d>0) {
    SDL_Rect rrr={x-16,y,32,128};
    SDL_RenderCopy(r, numer, NULL, &rrr);
   } else {
    SDL_Rect rrr={x-16,y-128,32,128};
    SDL_RenderCopy(r, denor, NULL, &rrr);
   }
 }
 
};


//helper funk!
void SDL_SetRenderBalto(SDL_Renderer* r, SDL_Color s) {
  SDL_SetRenderDrawColor(r,s.r,s.g,s.b,255);
}

struct Carre {
 int position;
 SDL_Color maryflag[4];
 SDL_Color flagger(Uint8 r,Uint8 g,Uint8 b) {
  SDL_Color c={r,g,b,255};
  return c;
 }
 Carre() : position(rand()&7) {
  maryflag[0]=flagger(245,0,0);
  maryflag[1]=flagger(245,245,245);
  maryflag[2]=flagger(245,255,0);
  maryflag[3]=flagger(0,0,0);
 }
 
 int integrand;
 int vale,olde;
 int signales;
 bool collide(signed char s) {
  olde=vale;
  vale=((int)s)<<4;
  signales=vale-olde;
  return false;
  //integrand+=s;
  //integrand =s;
 }
 bool collide() {
  olde=vale;
  if (vale>0)vale--;
  if (vale<0)vale++;
  //else return true;
  signales=vale-olde;
  if (vale==0) return true;
  return false;
 }
 
 void keyPress(SDL_Keycode k) {
  if (k==SDLK_m) 
   position=(position+1)&7;
   //break;
 }
 void draw(SDL_Renderer*r,int x, int y){
  SDL_Rect rrr; 
  for (int i =6;i>0;i--) {
   rrr.x=x-i;
   rrr.y=y-i;
   rrr.w=rrr.h=i<<1;
   SDL_SetRenderBalto(r,maryflag[((i+(position>>2))%4)]);
   SDL_RenderFillRect(r,&rrr);
   i-=(position%3);
  }
 }
};
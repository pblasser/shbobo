#define URPRIMLIM 256

struct Prime {
 int value;
 int weight;
 int scale;
 Prime * tail;
 int coss[URPRIMLIM];
 int sinn[URPRIMLIM];
 int chinkwonk; 
 
 Prime(int v, int w, Prime * tel) {
  value = v;
  weight = w;
  printf("Prime:%d,%d\n",v,w);
  scale =URPRIMLIM/((value+1)*(value+1));
 //scale = scale>>1;
  scale = (scale<1?1:scale);
  tail = tel;
  chinkwonk = value/3;
  for (int i = 0; i<value; i++) {
   sinn[i] = 0.5*(double)value*sin((((double)i)/(double)value)*3.14159*2);
   coss[i] = 0.5*(double)value*cos((((double)i)/(double)value)*3.14159*2);
  }
 }
 
 ~Prime(){}
 int getValue() {
  return (value*scale)>>1;
 }
 void headVisit(SDL_Renderer*r,int x, int y, int d, int c){
  int off = 0;
  if (value==2) {
   SDL_RenderDrawLine(r,x-4,y,x+4,y);
  } else
  for (int i=0;i<value;i++) {
   int oldoff = off;
   off+=c;
   off %= value;
   SDL_RenderDrawLine(r,
    x+d*(sinn[oldoff])*scale,y+d*(coss[oldoff])*scale,
    x+d*(sinn[off])*scale,y+d*(coss[off])*scale);
  }
 } 
 void headVisit(SDL_Renderer*r,int x, int y, int d){
  headVisit(r,x,y,d,chinkwonk);
 }
};
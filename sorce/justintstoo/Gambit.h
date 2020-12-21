

struct Gambit {
 Gambit * others;
 RoyalMoutarde rm;
 RoyalMinister rmi;
 Carre car;
 int quiznoquantan;
 int placz;
 int hys, osc, mus;
 int numeMustard, denoMustard;
 int signales,knume,kdeno,qwrth;
 RatChord * dursz;
 int x,y;
 int wraparound;

 Gambit() : wraparound(1), 
 //ministersANDmoutardes(rand()) ,
 numeMustard(0), denoMustard(0),
 hys(0), osc(0), quiznoquantan(0),
 knume(0), kdeno(0),qwrth(0)
 {
   dursz = poe.getQuid(rand(),rand());

 }

 int kingalNume(int i) {
  RatChord*r = poe.kingalNume(dursz,i);
  if (r) {
   dursz=r;
   return 1;
  }
  return 0;
 }
 int kingalDeno(int i) {
  RatChord*r = poe.kingalDeno(dursz,i);
  if (r) {
   dursz=r;
   return 1;
  }
  return 0;
 }
 int queenalis(int i) {
  RatChord*r = poe.queenalis(dursz,i);
  if (r) {
   dursz=r;
   return 1;
  }
  return 0;
 }
 void pitch_collision() {
  int squirt=128;
  if (1&rmi.intensity)squirt=181;
  FORI {
   if((1<<i)&rmi.nume_status) {
    knume+=(squirt*others[i].car.signales);
    qwrth+=(squirt*others[i].car.signales);
   }
   if((1<<i)&rmi.deno_status) {
    kdeno+=(squirt*others[i].car.signales);
    qwrth-=(squirt*others[i].car.signales);
   }
  }
  if (car.position&1)
   if (kingalNume(knume>>(14-(rmi.intensity>>1))))
    knume=0;
  if (car.position&2)
   if (kingalDeno(kdeno>>(14-(rmi.intensity>>1))))
    kdeno=0;
  if (car.position&4)
   if (queenalis(qwrth>>(14-(rmi.intensity>>1))))
    qwrth=0;  
 }
 
 bool collide(signed char s) {
   pitch_collision();
   return car.collide(s);
  }
 bool collide() {
   pitch_collision();
   return car.collide();
 }
 
 void ging(int * a, int ind, int len) {
  numeMustard=denoMustard=0;
  int squirt=128;
  if (1&rm.intensity)squirt=181;
  FORI {
   if((1<<i)&rm.nume_status)
    numeMustard+=(squirt*others[i].mus)>>(28-(rm.intensity>>1));
   if((1<<i)&rm.deno_status)
    denoMustard+=(squirt*others[i].mus)>>(28-(rm.intensity>>1));
  }
  int height=(denoMustard+dursz->deno->value)<<8;
  if (osc>height) hys=0;
  if (osc<-height) hys=1;
  int spoddy=(numeMustard+dursz->nume->value)*poe.strittle;
  if (spoddy<1) spoddy=1;
  if (hys==1) osc+= spoddy;
  else osc-=spoddy;
  int differosc=osc-height;
  int pluserosc= -(osc+height);
  if (quiznoquantan) {
   hys=1;
   if (differosc>=0) 
    osc=differosc-height;
  } else {
   if ((differosc>=0)&&(hys==1)) {
     hys=0;
     osc=height-differosc;
   }
   if ((pluserosc>=0)&&(hys==0)) {
     hys=1;
     osc=pluserosc-height;
   }
  }
  #define TRINGING(ting) ((ting>3?ting-3:0)+(ting<-3?ting+3:0))
  #define GINGFADE ((car.vale-car.olde)*ind/(len))+car.olde
  int gwonz=TRINGING(GINGFADE);
  mus = gwonz*osc;
  if (gwonz>0)a[0]+=(mus);//>>4;
  else a[1]+=(mus);//>>4;
 // int height
 }
 void paint(SDL_Renderer * rn) {
  dursz->nume->drawDominoX(rn,x,y-6,-1);
  dursz->deno->drawDominoX(rn,x,y+6,1);
  rm.drawMustardX(rn,x,y);
  rmi.drawMustardX(rn,x,y);
  car.draw(rn,x,y);
 }
 void prepaint(SDL_Renderer * rn) {
  SDL_SetRenderDrawBlendMode(rn,SDL_BLENDMODE_BLEND);
  int v = car.vale>>5;
  int sprank=128+rand()%8;
  if (v>0)
   SDL_SetRenderDrawColor(rn,sprank+v+(v>>1),sprank+(v>>1),sprank,sprank);
  if (v<0)
   SDL_SetRenderDrawColor(rn,sprank,sprank-(v>>1),sprank-v-(v>>1),sprank);
  dursz->nume->drawNume(rn,x,y-6);
  dursz->deno->drawDeno(rn,x,y+6);
 }
 void mouseButt(int xx, int yy) {
  rm.mouseButt(xx-x,yy-y);
  rmi.mouseButt(xx-x,yy-y);
 }
 void keyPress(SDL_Keycode k) {
  if (k==SDLK_SLASH) quiznoquantan=!quiznoquantan;
  rm.keyPress(k);
  rmi.keyPress(k);
  car.keyPress(k);
 }
 void resized(int xx, int yy) {
  x=xx;y=yy;
 }
 void random() {
  dursz = poe.getQuid(rand(),rand());
 }
};
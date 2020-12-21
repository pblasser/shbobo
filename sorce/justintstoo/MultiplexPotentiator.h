
//MISTER P, the POTENTIATOR
//sits at the top of the "original 
//application deliverable code".
//He interacts much with the library
//he inherits the AbstractChubEngine
//which is a callback class for
//ging grax and chub.

  #define FORTH for (int th=0;th<32;th++)


struct MultiplexPotentiator : Chub {
 int amt;
 int sr;
 int sterge[2];
 int oneatatime;
 int offset;
 
 SDL_Rect r;
 Barre b[32];

 Barre * penis;
 MultiplexPotentiator(){
  penis = &b[0];
  endor=false;
  offset = 0;
  oneatatime = 0;
  //chubbies.push_back(new ChubberySituation());
  amt = 1;
 }
 ~MultiplexPotentiator() {
  endor=true;
  
 }
 void resized(int x, int y) {
  r.x = 0;
  r.y=0;
  r.w=x;
  r.h=y;
  int error = x&16;
  error = error + (x>>6);
  FORTH b[th].resized(th*(x>>5)+error,y);
 }
 void mouseButt(int x, int y) {
  FORTH FORI b[th].g[i].mouseButt(x,y);
 }
 
 
 //BARZER LOGIX:
 //-DATA STRUCTURE
 //-KEY PRESSUES
 //-COLLIDING THREAD?
 //-GINGING OTHREADT?
 std::list<Barre*> players;
 int capacity;

 
 void keyPress(SDL_Keycode k) {
  if (k==SDLK_RETURN) {
    capacity++;
    capacity%=32;
    return;
  }
  if (k==SDLK_BACKSPACE) {
    capacity--;
    capacity%=32;
    return;
  }
  FORTH FORI b[th].g[i].keyPress(k);
 }
 


int lastfret;
 char clz(unsigned int x) {
    int n = 0;
    for (;x;n++) 
     x >>= 1;
    return n%32;
 }
 #define UCH(i) (((unsigned char)gwonz[4+i])<<(i*8))

 void collide() {
  int fret = clz(UCH(0)|UCH(1)|UCH(2)|UCH(3));
  if (fret!=lastfret) {
    if (players.size()<capacity)
      players.push_front(&b[fret]);
  }
  penis = &b[fret];
  penis->collide(gwonz); 
  lastfret=fret;
 }
 
 
 void ging(Uint8*stream,int len) {
  collide();
  
  static float * finstream =(float*)stream;
  static int sinlength = len >> 3;
  //printf("audiolen=%d\n",sinlength);
  int acc[2] = {0,0};
  for (int ind=0; ind<sinlength;) {
   acc[0]=acc[1]=0;
   //FORI gingwonz[i]= GINGFADE;
   penis->ging(acc, ind, sinlength); 
   acc[0]=acc[0]>>12;
    acc[1]=acc[1]>>12;
   finstream[(ind<<1)]=(float)(acc[0])/(256*256);
   //if (KOMPRESS
   finstream[(ind<<1)+1]=(float)(acc[1])/(256*256);
   ind++;
  }
 }
 void paint(SDL_Renderer * rn) {
  SDL_SetRenderDrawColor(rn,64,64,64,255);
  SDL_RenderFillRect(rn,&r);
  poe.paint(rn,r.w>>1,r.h>>1);
  penis->prepaint(rn); 
  FORTH b[th].paint(rn);
 }  
};


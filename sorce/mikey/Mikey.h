
#include "Shnth.h"
#include "Mikosphere.h"
#include <vector>
 #define PI 3.14159265
#define TWOPIE 6.2831853
#define forit(type,obje) \
 for (std::vector<type>::iterator it = obje.begin(); it != obje.end(); ++it)

shOpr nowarp(new Opero(0.0));

struct Stuff  {
 int xloke,yloke;
 virtual ~Stuff() { }
 virtual void rendrar(Mikey& m) = 0; 
 virtual void collide(Mikey& m) = 0;
};

struct Squar : Stuff, Opero {
 int xwido, yhido;
 bool visible;
 bool operator==(Stuff& s) {
  return (s.xloke>xloke-xwido) &&
   (s.yloke>yloke-yhido) &&
   (s.xloke<(xloke+xwido)) &&
   (s.yloke<(yloke+yhido));
 }
 //virtual ~Squar() { }
 virtual void sounder(float * l, float * r) = 0;
 void keepin(Stuff& s) {
  if (s.xloke<xloke-xwido) s.xloke=xloke-xwido;
  else if (s.yloke<yloke-yhido) s.yloke=yloke-yhido;
  else if (s.xloke>(xloke+xwido)) s.xloke=(xloke+xwido);
  else if (s.yloke>(yloke+yhido)) s.yloke=(yloke+yhido);
 }
};
 
struct Circo : Stuff {
 int rad;
 bool operator==(Squar& s) {
  return (s.xloke+s.xwido>xloke-rad) &&
   (s.yloke+s.yhido>yloke-rad) &&
   (s.xloke-s.xwido<(xloke+rad)) &&
   (s.yloke-s.yhido<(yloke+rad));
 }
 bool operator<=(Squar& s){
  int dx = s.xloke - xloke; 
  int dy = s.yloke - yloke;
  float rx = sqrt((float)((dx*dx)+(dy*dy))) - rad;
  return (rx < s.xwido) || (rx < s.yhido);// && (rx >= -s.yhido);
 }
};

class Space;
typedef TRCOLO shared_ptr<Space> shSpa;
#define caSpa(a) TRCOLO dynamic_pointer_cast<Space,Opero>(a)
//shSpa nospace;

struct Mikey : Shnth , Circo {
 Mikosphere *mm;
 Mikey();
 void prep() {mm = new Mikosphere();}
 //int xx, yy;
 float zoomo;
 float sino, cosi;
 shOpr warpsound;
 float rota;
 Sint16 * sinstream;
 int sinlength;
 float lefto, rigto;
    float lleft, lrite;
 int osc; bool gwon;
 float siz;
 signed char lgz[2];
 #include "Punch.h"
 shSpa myspace;
 Track arms;
 void setSpace(shSpa s);
 void setWarp(shOpr o);
 void collide(Mikey& m){}
 void collide();
 void sounder(Uint8 *stream, int len);
 void sounder(Mikey& m){}
 void rendrar(Mikey& m){}
 void rendrar();
 void warprar();
 bool spacedout();
 bool operator<(Squar& s);
};
Mikey m;
#include "Space.h"
shSpa nospace(new Space());

 Mikey::Mikey() : siz(50) {
  xloke = yloke = 0; 
  myspace = shSpa(new Space()); //nospace
  warpsound = nowarp;
  zoomo=0;
  rad = siz;
  
 }
 void Mikey::setSpace(shSpa s) {
  myspace = s; xloke=yloke=0;
 }
 void Mikey::setWarp(shOpr o) {
  warpsound = o;
 }
 void Mikey::collide() {
     float gwonzl =-gwonz[0];
     float gwonzr =-gwonz[3];
     lleft = (gwonzl+ lleft*63)/64.0;
     lrite = (gwonzr + lrite*63)/64.0;
     lefto = gwonzl;// - lleft;
     rigto = gwonzr;// - lrite;
     lefto *= 100.0/prate;
     rigto *= 100.0/prate;
  if (lefto > 12) {
   rota += lefto/42.0f; //rota = 23;
   xloke += lefto*sin(PI*rota/180.0f) / 22;
   yloke += lefto*cos(PI*rota/180.0f) / 22;
  } if (rigto > 12) {
   rota -= rigto/42.0f; //rota = 23;
   xloke += (rigto)*sin(PI*rota/180.0f) / 22;
   yloke += (rigto)*cos(PI*rota/180.0f) / 22;
  } rota = fmod(rota,360.0);
  arms.collide(*this);
  if (myspace) myspace->collide(*this);
 }
 bool Mikey::operator<(Squar& s) {
  return (s.xloke+s.xwido>xloke-zoomo*4) &&
   (s.yloke+s.yhido>yloke-zoomo*4) &&
   (s.xloke-s.xwido<(xloke+zoomo*4)) &&
   (s.yloke-s.yhido<(yloke+zoomo*4));
 }


 void Mikey::sounder(Uint8 *stream, int len) {
  //return;
  //printf("buflen%d\n",len);
  static float * finstream =(float*)stream;
  sinstream = (Sint16*)stream;
  
  sinlength = len >> 1;
  sinlength = len >> 2;
  int i; 
  if (warpsound!=nowarp) {
   for ( i=0; i<sinlength;  ) {
    float sar = warpsound->calx(srate);
    finstream[i++] = sar*0.1;
    finstream[i++] = sar*0.1;
   } //printf ("warpsound\n");
  } 
  else if (myspace) {
   for ( i=0; i<sinlength;  ) {
    static float l,r;
    myspace->sounder(&l,&r);
    finstream[i++] = l*0.1;//fmin(fmax(l,-32000.0),32000.0);
    finstream[i++] = r*0.1;//fmin(fmax(r,-32000.0),32000.0);
   } 
  }
  lgz[1]=gwonz[1];lgz[0]=gwonz[0];
 }

 bool Mikey::spacedout() {  
  if (warpsound!=nowarp) return (zoomo <= 0);
  return myspace->spacedout(); 
 }
 void Mikey::rendrar() {
 //printf("moon\n");
 
  sino = sinf(PI*rota/180);
  cosi = cosf(PI*rota/180);
  int winw, winh;
  
  SDL_GetWindowSize(screen, &winw,&winh);
  //printf("renr\n");
  glViewport(0, 0, (GLsizei) winw, (GLsizei) winh);
  //printf("rendrrr\n");
  glBindVertexArray(mm->mivaosha[0]);
  //printf("rendrraasdr\n");
  glUseProgram(mm->mivaosha[1]);
  glUniform2f(mm->mitran, 0,0);
  glUniform1f(mm->micolo, 0);
  glUniform1f(mm->miworl, zoomo);
  glUniform1f(mm->mibigg, rad);
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  //glUniform4f(mm->mitown, 0.2,0.1,0.1,1.0);
  mm->bronk();
  arms.rendrar(*this);
  //printf("redrrr\n");
  if (warpsound!=nowarp) {
   glBindVertexArray(m.mm->mivaosha[0]);
   glUseProgram(m.mm->mivaosha[1]);
   glUniform4f(m.mm->mitown, 0,0,0,0);
   zoomo -= 1;
  } else if (myspace!=nospace){ 
   //printf("goonr\n");
   zoomo = (gwonz[4] + 180 + gwonz[5]);
   myspace->rendrar(*this);
  } 
  SDL_GL_SwapWindow(screen);
 }

void Mikey::warprar() {  
  zoomo -= 1;
  int winw, winh;
  SDL_GetWindowSize(screen, &winw,&winh);
  glViewport(0, 0, (GLsizei) winw, (GLsizei) winh);
  glBindVertexArray(mm->mivaosha[0]);
  glUseProgram(mm->mivaosha[1]);
  glUniform2f(mm->mitran, 0,0);
  glUniform1f(mm->micolo, 0);
  glUniform1f(mm->miworl, zoomo);
  glUniform1f(mm->mibigg, rad);
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  mm->bronk();
  arms.rendrar(*this);
  if (myspace){ 
   //myspace->rendrar(*this);
  } 
  //if (warpsound!=nowarp) return (zoomo <= 0);
  SDL_GL_SwapWindow(screen);
 }

int shnthrunc(void* ptr) {
 m.shnthOPEN();
 m.shnthRUN(); 
 return 0;
}
SDL_Thread *sthread;
int threadReturnValue;
  
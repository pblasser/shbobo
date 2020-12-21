
struct Tempo : TRCOLO shared_ptr<float> {
};

struct Difer : Opero {
 float last;
 shOpr inn,mul,add;
 static const char className[];
 Difer(lua_State *L): Opero() { 
  last = 0;
  broinger(L, 1, "inn", &inn);
  broinger(L, 2, "mul", &mul,1.0);
  broinger(L, 3, "add", &add);
 }
 float calx(float sr) {
  float dd =inn->calx(sr);
  float d =dd-last;
  last = dd;
  if (d>0.0) mint = 1.0;
  else mint = 0.0;
  return mint*mul->calx(sr)+add->calx(sr);
 }
 const char * getClassName() { return className; }
};
const char Difer::className[] = "Difer";

struct Horse : Opero {
 bool gwon; 
 float osc; 
 shOpr nup,non,top,bot; 
 static const char className[];
 shOpr mul,add;
 Horse(lua_State *L): Opero() { 
  osc = 0; gwon = false;
  broinger(L, 1, "nup", &nup);
  broinger(L, 2, "non", &non);
  broinger(L, 3, "top", &top,1.0);
  broinger(L, 4, "bot", &bot,-1.0);
  broinger(L, 5, "mul", &mul,1.0);
  broinger(L, 6, "add", &add);
 }
 float calx(float sr) {
  float fmm = 2.0 * nup->calx(sr) / sr; 
  fmm = (fmm<=0.0 ? -fmm : fmm);
  float fm = 2.0 * non->calx(sr) / sr; 
  fm = (fm<=0.0 ? -fm : fm);
  if (gwon) osc+= fmm; else osc-=fm;
  //printf("housc %f\n", osc);
  float differosc = osc - top->calx(sr);
  float pluserosc = (-(osc - bot->calx(sr)));
  if (differosc > 0) {
   gwon=false; 
   osc -= differosc*2;
   osc = top->calx(sr);
  } else if (pluserosc > 0) {
   gwon=true;
   osc+= pluserosc*2;
   osc = bot->calx(sr);
  } //printf("horsemint%f %f %f %f %f\n",mint,fmm,fm,differosc,pluserosc);
  mint = osc;
  return mint*mul->calx(sr)+add->calx(sr);
 }
 const char * getClassName() { return className; }
};
const char Horse::className[] = "Horse";

struct Fours : Opero {
 struct Horse : Opero {
  bool gwon; 
  float osc; 
  shOpr fre; char frenam[6];
  Horse * top, * bot;
  Horse(Horse*b,Horse*t) : top(t), bot(t) {}
  Horse(float vale, int i = 0) : osc(vale) {
   sprintf(frenam, "fre%d", i);
  }
  float calx(float sr) {
   float fmm = 2.0 * fre->calx(sr) / sr; 
   fmm = (fmm<=0.0 ? -fmm : fmm);
   if (gwon) osc+= fmm; else osc-=fmm;
   float differosc = osc - top->osc;
   float pluserosc = ((osc + bot->osc));
   if (differosc >= 0) {
    gwon=false; top->gwon=true;
    osc -= differosc; //top->osc += differosc; 
   } else if (pluserosc >= 0) {
    gwon=true;bot->gwon=false;
    osc+= pluserosc;
   }
   //mint = osc;
   return osc;
  }
 }; Horse *zies [6];
 static const char className[];
 shOpr mul,add;
 Fours(lua_State *L): Opero() { 
  zies[0] = new Horse(-1.0);
  zies[5] = new Horse(1.0);
  for (int i = 1; i < 5; i++) {
   zies[i] = new Horse((float)i/8.0,i);
   broinger(L, i, zies[i]->frenam, &(zies[i]->fre),1.0);
   zies[i-1]->top = zies[i];
   zies[i]->bot = zies[i-1];
  } zies[4]->top = zies[5];
  broinger(L, 5, "mul", &mul,1.0);
  broinger(L, 6, "add", &add);
 }
 float calx(float sr) {
  mint = 0;
  for (int i = 1; i < 5; i++) {
   mint += zies[i]->calx(sr);
  }
  return mint*mul->calx(sr)+add->calx(sr);
 }
 const char * getClassName() { return className; }
};
const char Fours::className[] = "Fours";



struct Trang : Opero {
 bool gwon; float osc; 
 static const char className[];
 shOpr fre,mul,add;
 Trang(lua_State *L): Opero() { 
  gwon = false; osc = 0;
  broinger(L, 1, "fre", &fre);
  broinger(L, 2, "mul", &mul,1.0);
  broinger(L, 3, "add", &add);
 }
//  void buffcalx(int bs) {
//   buffstuff = bs;
//   fre->buffcalx(bs);
//   mul->buffcalx(bs);
//   add->buffcalx(bs);
//   if (buffstuff == 0) buff[0] = calx(prate);
//   else for(int i = 0; i < 512; i++) 
//    buff[i] = calx(srate);
//  }
 float calx(float sr) {
  float fmm = 2.0 * fre->calx(sr) / sr; 
  fmm = (fmm<=0.0 ? -fmm : fmm);
  if (gwon) osc+= fmm; else osc-=fmm;
  float differosc = osc - 1.0;
  float pluserosc = (-(osc + 1.0));
  if (differosc >= 0) {
    gwon=false;
    osc -= differosc;
  } else if (pluserosc >= 0) {
    gwon=true;
    osc+= pluserosc;
  }
  mint = osc * mul->calx(sr) + add->calx(sr);
  return mint;
 }
 const char * getClassName() { return className; }
};
const char Trang::className[] = "Trang";


struct Drang : Opero {
    bool gwon1, gwon2; float osc1, osc2;
    static const char className[];
    shOpr fre,frf,mul,add,qua;
    Drang(lua_State *L): Opero() {
        gwon1 = gwon2 = false; osc1 = osc2 = 0;
        broinger(L, 1, "fre", &fre);
        broinger(L, 2, "frf", &frf);
        broinger(L, 3, "qua", &qua);
        broinger(L, 4, "mul", &mul,1.0);
        broinger(L, 5, "add", &add);
    }
    float calx(float sr) {
        float fmo = 2.0 * fre->calx(sr) / sr ;
        float fmo2 = 2.0 * frf->calx(sr) / sr ;
        float quan = qua->calx(sr);
        quan = fabs(quan);
        float fmm = fmo * (osc2*quan+1);
        fmm = (fmm<=0.0 ? -fmm : fmm);
        if (gwon1) osc1+= fmm; else osc1-=fmm;
        float differosc = osc1 - 1.0;
        float pluserosc = (-(osc1 + 1.0));
        if (differosc >= 0) {
            gwon1=false;
            osc1 -= differosc;
        } else if (pluserosc >= 0) {
            gwon1=true;
            osc1+= pluserosc;
        }
        fmm = fmo2 * (1-osc1*quan);
        fmm = (fmm<=0.0 ? -fmm : fmm);
        if (gwon2) osc2+= fmm; else osc2-=fmm;
         differosc = osc2 - 1.0;
         pluserosc = (-(osc2 + 1.0));
        if (differosc >= 0) {
            gwon2=false;
            osc2 -= differosc;
        } else if (pluserosc >= 0) {
            gwon2=true;
            osc2+= pluserosc;
        }
        mint = (osc1+osc2) * mul->calx(sr) + add->calx(sr);
        return mint;
    }
    const char * getClassName() { return className; }
};
const char Drang::className[] = "Drang";





struct Tooth : Opero {
 float osc;
 static const char className[];
 shOpr fre,mul,add;
 Tooth(lua_State *L) : Opero(), osc(0) { 
  broinger(L, 1, "fre", &fre);
  broinger(L, 2, "mul", &mul,1.0);
  broinger(L, 3, "add", &add);
 }
 int i = 0;
 float calx(float sr) {
  float fmm = fre->calx(sr) / sr; 
  fmm = (fmm<=0.0 ? -fmm : fmm);
  osc+= fmm; 
  float differosc = osc - 1.0;
  if (differosc >= 0) {
    osc = differosc - 1.0;
  }
  mint = osc * mul->calx(sr) + add->calx(sr);
  return mint;
 }
 const char * getClassName()  { return className; }
};
const char Tooth::className[] = "Tooth";



struct Noise : Opero {
 static const char className[];
 shOpr mul,add;
 Noise(lua_State *L) : Opero(){ 
  //broinger(L, 1, "fre", &fre);
  broinger(L, 1, "mul", &mul,1.0);
  broinger(L, 2, "add", &add);
 }
 float calx(float sr) {
  mint = frand(-1.0,1.0) * mul->calx(sr) + add->calx(sr);
  return mint;
 }
 const char * getClassName()  { return className; }
};
const char Noise::className[] = "Noise";


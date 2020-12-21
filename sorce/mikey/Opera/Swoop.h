
struct Swoop : Opero {
 bool gwon; float osc; 
 shOpr inn,fre,mul,add,qua;
 static const char className[];
 Swoop(lua_State *L) : Opero(), osc(0), tardis(0) {
  broinger(L, 1, "inn", &inn);
  broinger(L, 2, "fre", &fre);
  broinger(L, 3, "qua", &qua,0.1);
  broinger(L, 4, "mul", &mul,1.0);
  broinger(L, 5, "add", &add);
 }
 float tardis;
 float calx(float sr) {
  float cronk = inn->calx(sr)/10;
  tardis += cronk;
  //if (tardis > 0.0) tardis += fmax(cronk,0.0);
  //else tardis += fmin(cronk,0.0);
  float quod = 1.0-qua->calx(sr);
  tardis *= quod;
  float fmm = fabs(2.0 * fre->calx(sr) / sr);
  osc+= fmm * (tardis>0?1:-1);
  //printf("osco%f fmm%f tardis%f\n",osc,fmm,tardis);
  if (osc > fabs(tardis)) {
   osc = fabs(tardis);
   tardis = -fabs(tardis);
  } else if (osc < -fabs(tardis)) {
   //tardis *= quod;
   osc = -fabs(tardis);
   tardis = fabs(tardis);
  }  
  mint = osc* mul->calx(sr) + add->calx(sr);
  return mint;
 }
 const char * getClassName()   { return className; }
};
const char Swoop::className[] = "Swoop";

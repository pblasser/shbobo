class Karpo : public Refer {
 float guide[65536];
 short plaz;
 float lastsamp;
 //shOpr sp,q;
 public:
 shOpr inn,sp,q,mul,add;
 static const char className[];
 Karpo(lua_State *L) : Refer() {
  broingInit(L, 1, "inn", &inn);
  broingInit(L, 2, "sp", &sp);
  broingInit(L, 3, "q", &q,0.5);
  broingInit(L, 4, "mul", &mul,1.0);
  broingInit(L, 5, "add", &add);
  lastsamp = 0;
 }
 float calx(float sr) {  
  short len = sr / sp->calx(sr);
  if (plaz > len) plaz = 0;
  else plaz++;
  float ls = guide[plaz];
  guide[plaz] = (guide[plaz] + lastsamp) * q->calx(sr);
  guide[plaz] += inn->calx(sr)/20.0;
  lastsamp = ls;
  float mint = guide[plaz] * mul->calx(sr) +add->calx(sr);
  setMint(mint);
  return mint;
 }
};
const char Karpo::className[] = "Karpo";


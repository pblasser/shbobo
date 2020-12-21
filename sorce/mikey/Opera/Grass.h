
struct BistaTranz {
 float squl, squr;
 bool state;
 BistaTranz (){squl=squr=0;}
 float calx(float fmm, float den) {
  if (state) {
   squl += fmm;
   if (squl >= den) {
    squr = -den;
    state = !state;
   }
  } else {
   squr += fmm;
   if (squr >= den) {
    squl = -den;
    state = !state;
   }
  } return squl;
 }
};

struct Bista : Opero {
 BistaTranz bt;
 shOpr mul, add, fmo, den;
 Bista(lua_State *L): Opero() {
  broinger(L, 1, "fre", &fmo);
  broinger(L, 2, "den", &den, 1.0);
  broinger(L, 3, "mul", &mul,1.0);
  broinger(L, 4, "add", &add);
 }
 float calx(float sr) {
  mint = 0;
  float fmm = 4*fmo->calx(sr)/sr;
  float deno = fabs(den->calx(sr));
  bt.calx(fmm,deno);
  mint = bt.squr * mul->calx(sr) + add->calx(sr);
   return mint;
  }
  static const char className[];
  const char * getClassName()  { return className; }
};
const char Bista::className[] = "Bista";

struct RunglTranz {
 unsigned char pattern;
 float mint;
 float lastcar;
 RunglTranz(){pattern=rand();}
 float calx(bool car, bool mod) {
  if (car && !lastcar)
   pattern = (pattern << 1) | (mod ? 1 : 0);
  lastcar = car;
  //printf("patternfloat%d\n",pattern);
  mint = (float)pattern / 256; 
  return mint;
 }
};

struct Grass : Opero {
 BistaTranz square[4];
 RunglTranz castle[4];
 static const char className[];
 shOpr mul, add, fmo, cha;
 Grass(lua_State *L): Opero() {
  broinger(L, 1, "fre", &fmo);
  broinger(L, 2, "cha", &cha);
  broinger(L, 3, "mul", &mul,1.0);
  broinger(L, 4, "add", &add);
 }
 float calx(float sr) {
  mint = 0;
  float chaos = cha->calx(sr);
  //printf("chaos%f\n",chaos);
  float fmm = 4*fmo->calx(sr)/sr;
  for (int i = 0; i < 4; i++) {
   square[i].calx(
    fmm*(1+chaos*castle[i].calx(
     square[(i+2)%4].state, square[(i+1)%4].state)),
    1+(float)i/10);
   } 
  float mullo = mul->calx(sr);
  mint = square[0].squl*mullo + add->calx(sr);
  return mint;
 }
 const char * getClassName()  { return className; }
};
const char Grass::className[] = "Grass";
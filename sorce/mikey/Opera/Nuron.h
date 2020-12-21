//sodium channels from -1 to 1
struct Nuron : Opero {
 bool lastgwonz; float osc;
  static const char className[];
 //Opero*fm;
 shOpr fm, inn, mul, add;
 Nuron(lua_State *L): Opero() {
  broinger(L, 1, "inn", &inn);
  broinger(L, 2, "fm", &fm);
  broinger(L, 3, "mul", &mul,1.0);
  broinger(L, 4, "add", &add);
  lastgwonz = true;
  osc = -1.0;	 
 }
 float calx(float sr) {
  if (inn->calx(sr) > 0.0) {
   if (lastgwonz==true) osc = -1;  //wasz minus equals one
   lastgwonz = false;
  } else lastgwonz = true;
  if (osc <= 0.0)
   osc += fabsf(fm->calx(sr))/sr;
  mint = osc *mul->calx(sr) + add->calx(sr);
  return mint;
 }
 const char * getClassName()  { return className; }
};
const char Nuron::className[] = "Nuron";

struct Wheel : Opero {
 float osc;
 static const char className[];
 shOpr upp, don, mul, add;
 Wheel(lua_State *L): Opero() {
  broinger(L, 1, "upp", &upp);
  broinger(L, 2, "don", &don);
  broinger(L, 3, "mul", &mul,1.0);
  broinger(L, 4, "add", &add);
  osc = 0.0;	 
 }
 float calx(float sr) {
  float u = upp->calx(sr); 
  float d = don->calx(sr);
  if (u > 0.0) 
   osc += u/sr;
  if (d > 0.0) 
   osc -= d/sr;
  mint = osc *mul->calx(sr) + add->calx(sr);
  return mint;
 }
 const char * getClassName()  { return className; }
};
const char Wheel::className[] = "Wheel";


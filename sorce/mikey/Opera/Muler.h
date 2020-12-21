
struct Muler : Opero {
 shOpr inn, mul;
 static const char className[];
 Muler(lua_State *L): Opero() { 
  broinger(L,1,"inn",&inn);
  broinger(L,2,"mul",&mul,1.0);
 }
 float calx(float sr) {
  mint = inn->calx(sr)*mul->calx(sr);
  return mint;
 } const char * getClassName() { return className; }
};
const char Muler::className[] = "Muler";

struct Diver :  Opero {
 static const char className[];
 shOpr inn, div;
 Diver(lua_State *L): Opero() { 
  broinger(L,1,"inn",&inn);
  broinger(L,2,"div",&div);
 }
 float calx(float sr) {
  float dive = div->calx(sr);
  if (dive==0.0) mint = 0.0;
  else mint = inn->calx(sr)/dive;
  if (mint!=mint) mint = 0;
  return mint;
 } const char * getClassName()   { return className; }
};
const char Diver::className[] = "Diver";

struct Modor : Opero {
 static const char className[];
 shOpr inn, mod;
 Modor(lua_State *L): Opero() { 
  broinger(L,1,"inn",&inn);
  broinger(L,2,"mod",&mod);
 }
 float calx(float sr) {
  float dive = mod->calx(sr);
  if (dive==0.0) mint = 0.0;
  else mint = fmod(inn->calx(sr),dive);
  return mint;
 } const char * getClassName()   { return className; }
};
const char Modor::className[] = "Modor";

struct Powor : Opero {
 static const char className[];
 shOpr inn, wop;
 Powor(lua_State *L): Opero() { 
  broinger(L,1,"inn",&inn);
  broinger(L,2,"pow",&wop);
 }
 float calx(float sr) {
  mint = pow(inn->calx(sr),wop->calx(sr));
  return mint;
 } const char * getClassName()   { return className; }
};
const char Powor::className[] = "Powor";

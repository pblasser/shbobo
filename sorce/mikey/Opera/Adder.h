
struct Adder : Opero {
 static const char className[];
 shOpr inn, add;
 Adder(lua_State *L) : Opero() { 
  broinger(L,1,"inn",&inn);
  broinger(L,2,"add",&add);
 }
 float calx(float sr) {
  mint = inn->calx(sr) + add->calx(sr);
  return mint;
 } const char * getClassName()   { return className; }
};
const char Adder::className[] = "Adder";

struct Suber : Opero {
 shOpr inn, sub;
 static const char className[];
 Suber(lua_State *L) : Opero() { 
  broinger(L,1,"inn",&inn);
  broinger(L,2,"sub",&sub);
 }
 float calx(float sr) {
  mint = inn->calx(sr)-sub->calx(sr);
  return mint;
 } const char * getClassName()   { return className; }
};
const char Suber::className[] = "Suber";


struct Trigg : Opero {
 static const char className[];
 shOpr inn, mul, add;
 Trigg(lua_State *L) : Opero() {
  broinger(L,1,"inn",&inn);
  broinger(L,2,"mul",&mul,1.0);
  broinger(L,3,"add",&add);
 }
 float calx(float sr) {
  mint = (inn->calx(sr)>0?1:0)*mul->calx(sr) + add->calx(sr);
  return mint;
 } const char * getClassName()   { return className; }
};
const char Trigg::className[] = "Trigg";

struct Salsa : Opero {
    static const char className[];
    shOpr inn, mul, add, trg;
    Salsa(lua_State *L) : Opero() {
        broinger(L,1,"trg",&trg);
        broinger(L,2,"inn",&inn);
        broinger(L,3,"mul",&mul,1.0);
        broinger(L,4,"add",&add);
    }
    float calx(float sr) {
        if (trg->calx(sr) > 0)
            mint = inn->calx(sr);
        return mint*mul->calx(sr) + add->calx(sr);;
    } const char * getClassName()   { return className; }
};
const char Salsa::className[] = "Salsa";
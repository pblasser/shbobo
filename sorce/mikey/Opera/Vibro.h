
struct Vibro : Opero {
 float lp, bp;
 //float speedo;
 shOpr inn,fre,que,mul,add,cos;
 public:
 static const char className[];
 Vibro(lua_State *L) : Opero() , lp(0), bp(0) {
  cos.reset(new Opero(0.0));
  broing["cos"] = &cos;
  broinger(L,1,"inn",&inn);
  broinger(L,2,"fre",&fre);
  broinger(L,3,"que",&que,0.1);
  broinger(L,4,"mul",&mul,1.0);
  broinger(L,5,"add",&add);
 }
 float calx(float sr) {  
  float f = 2.0*sin(PI * fre->calx(sr) / sr);
  f = (f<=0.0 ? -f : f);
  float hp = inn->calx(sr) - lp;
  hp -= bp * que->calx(sr);
  bp += hp * f;
  lp += bp * f;
  cos->setMint(bp);
  //lp = fmin(fmax(lp,-128.0),128.0);
  //bp = fmin(fmax(bp,-128.0),128.0);
  mint = lp*mul->calx(sr)+add->calx(sr);
  return mint;
 } const char * getClassName() { return className; }
};
const char Vibro::className[] = "Vibro";

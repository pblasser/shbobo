
class Golem : public Squar {
 public:
 shOpr pux, puy;
 shOpr red, grn, blu;
 shOpr xspaz, yspaz;
 shOpr add;
 float mixo,redf,bluf,grnf;
 Golem(lua_State *L) { 
  //printf("golem is %s %p\n", getClassName(), this);
  pux.reset(new Opero(0.0));
  puy.reset(new Opero(0.0));
  add.reset(new Opero(0.0));
  broing["pux"] = &pux;
  broing["puy"] = &puy;
  broing["x"] = &xspaz;
  broing["y"] = &yspaz;
  broing["red"] = &red;
  broing["grn"] = &grn;
  broing["blu"] = &blu;
  broing["add"] = &add;
  xspaz = lunar_getopero(L,1);
  yspaz = lunar_getopero(L,2);
  xwido = 2;
  yhido = 2;
  red = lunar_getopero(L,3, frand(0.0,1.0));
  grn = lunar_getopero(L,4,frand(0.0,1.0));
  blu = lunar_getopero(L,5,frand(0.0,1.0));
 }

 static const char className[];
 ~Golem() {}
#define randl 2
 void collide(Mikey& m) {
  redf = red->calx(prate);
  grnf = grn->calx(prate);
  bluf = blu->calx(prate);
   if ((m==(*this)) && (m<=(*this))) {
    float hardness = m.gwonz[0] + m.gwonz[3];
    pux->setMint(hardness/128);
    puy->setMint(hardness/128);
   } else {
    pux->setMint(0);
    puy->setMint(0);
   }
  xloke = xspaz->calx(prate);  
  yloke = yspaz->calx(prate);
  float cozer = (xloke-m.xloke);
  float sinza = (yloke-m.yloke);
  float angola = (sinza/cozer); 
  if  (angola!=angola) mixo = 0;
  else {
   angola = atan(sinza/cozer);
   if (cozer < 0) angola += PI;
   angola += PI * m.rota / 180.0;
   mixo = cos(angola); //mixo = 0
  }
 }
 void sounder(float*l,float*r) {  
  //printf("golemsound%f\n",addd->sounder());
  float ca = add->calx(srate);
  *l += (1.0-mixo)*ca;
  *r += (1.0+mixo)*ca;
  
 }
 void rendrar(Mikey& m) { 
  glUniform2f(totran, xloke-m.xloke,yloke-m.yloke);
  glUniform3f(toworl,m.cosi,m.sino,m.zoomo);
  glUniform2f(tobigg,10,10);
  glUniform4f(tocolo,redf,grnf,bluf,1.0);
  glDrawArrays(GL_TRIANGLE_STRIP,0,4); 
 }
 const char * getClassName() { return className; }
};
const char Golem::className[] = "Golem";

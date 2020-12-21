
struct Chube : Squar  {
 //std::vector<shOpr> operos; 
 shOpr pux, puy;
 shOpr rox, roy;
 shOpr xsp, ysp;
 shOpr wid, hid;
 shOpr red, grn, blu,dep;
 shOpr add;
 bool dead;
 int depo;
 int towntonx, towntony;
 float mixo;
 ~Chube() {}
 Chube(lua_State *L) { 
  broing["pux"] = &pux;
  broing["puy"] = &puy;
  pux.reset(new Opero(0.0));
  puy.reset(new Opero(0.0));
  add.reset(new Opero(0.0));
  broinger(L,1,"x",&xsp);
  broinger(L,2,"y",&ysp);
  broinger(L,3,"w",&wid);
  broinger(L,4,"h",&hid);
  broinger(L,5,"rox",&rox);
  broinger(L,6,"roy",&roy);
  broinger(L,7,"red",&red);
  broinger(L,8,"grn",&grn);
  broinger(L,9,"blu",&blu);
  broinger(L,10,"dep",&dep,66.0);
  broinger(L,11,"add",&add);
  dead = false;
   depo = 66; 
 }
 static const char className[];
 void setTownton(int x, int y) {
  towntonx=x; towntony=y;
 }
 //virtual void setter(const char*str,shOpr bingang) {
  //if (strcmp(str,"add")==0) 
  // operos.push_back(bingang);
  //Opero::setter(str,bingang);
 //}
#define randl 2
 void collide(Mikey& m) {
  if (dead) return;
  float puxo = 0;
  float puyo = 0;
  if ((m.arms==(*this)) && (m.arms<=(*this))) {   
   //printf("inarms\n");
    if (m.arms.left==(*this)) { 
     puxo -= m.arms.col * m.arms.ll;
     puyo -= m.arms.sil * m.arms.ll;
    }
    if (m.arms.rite==(*this)) { 
     puxo += m.arms.cor * m.arms.lr;
     puyo += m.arms.sir * m.arms.lr;
    }
  }
   pux->setMint(puxo/128);
   puy->setMint(puyo/128);
  xloke = xsp->calx(prate) +towntonx;  
  yloke = ysp->calx(prate) + towntony;  
  xwido = wid->calx(prate);
  yhido = hid->calx(prate);
  red->calx(prate);blu->calx(prate);grn->calx(prate);
  float roatx = fabs(rox->calx(prate));
  float roaty = fabs(roy->calx(prate));
  if ((roatx > 1.0) || (roaty > 1.0))  {
   dead = true;
  }
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
  //forit (shOpr,operos) { 
  float addo = add->calx(srate);
   *l += (1.0-mixo)*addo;
   *r += (1.0+mixo)*addo;
 }

 void rendrar(Mikey& m) { 
  if (dead) return; 
  glUniform2f(chtran,xloke-m.xloke,yloke-m.yloke);
  glUniform2f(chrosi,sinf(rox->getMint()),sinf(roy->getMint()));
  glUniform2f(chroco,cosf(rox->getMint()),cosf(roy->getMint()));
  glUniform3f(chbigg, xwido*2, yhido*2, depo);
  glUniform3f(chcolo, red->getMint(),grn->getMint(),blu->getMint());
  glDrawArrays(GL_TRIANGLE_STRIP,0,12);  
 }
 const char * getClassName() { return className; }
};

const char Chube::className[] = "Chube";

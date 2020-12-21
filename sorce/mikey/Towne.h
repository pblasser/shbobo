
#include "Chube.h"

typedef TRCOLO shared_ptr<Chube> shChb;
#define caChb(a) TRCOLO dynamic_pointer_cast<Chube,Opero>(a)

struct Towne : Squar {
 float fogden;
 std::vector<shChb> chubies; 
 GLfloat fogColor[4];
 shOpr red, grn, blu;
 Towne() {
  xloke = yloke = 0;
  xwido = yhido = 5000;
   fogColor[0] = 0;
  fogColor[1] = 0;
  fogColor[2] = 0;
  fogColor[3] = 0;
 }
 Towne(lua_State *L) { 
  
  fogden  = 1.0;
  xloke = luaL_checkint(L, 1);
  yloke = luaL_checkint(L, 2);
  xwido = luaL_checkint(L, 3);
  yhido = luaL_checkint(L, 4);
  broinger(L,5,"red",&red);
  broinger(L,6,"grn",&grn);
  broinger(L,6+1,"blu",&blu);
  //red = lunar_getopero(L,5);
  //grn = lunar_getopero(L,6);
  //blu = lunar_getopero(L,6+1);
  fogColor[0] = red->getMint();
  fogColor[1] = grn->getMint();
  fogColor[2] = blu->getMint();
 }
 static const char className[];
 void sounder(float*l, float*r) {
  forit (shChb,chubies) { 
   if (!(*it)->dead) (*it)->sounder(l,r);
  } 
 } 
 virtual void setter(const char*str,shOpr bingang) {
  shChb c = caChb(bingang);
  if (!c) return;
  if (strcmp(str,"add")==0) {
   c->setTownton(xloke,yloke);
   chubies.push_back(c);
   return; 
  }
  Opero::setter(str,bingang);
 }
 void qrendrar(){
 
 
  glUniform2f(totran, xloke-m.xloke,yloke-m.yloke);
  glUniform3f(toworl,m.cosi,m.sino,m.zoomo);
  glUniform2f(tobigg,xwido*2,yhido*2);
  glUniform4f(tocolo, fogColor[0],fogColor[1],fogColor[2], fogden);
  glDrawArrays(GL_TRIANGLE_STRIP,0,4);  
 }
 void rendrar(Mikey& m) {
  qrendrar ();
  fogColor[3] = fogden;
  glBindVertexArray(chvaosha[0]);  
  glUseProgram(chvaosha[1]);
  glUniform3f(chworl,m.cosi,m.sino,m.zoomo);
  glUniform4f(chtown, fogColor[0],fogColor[1],fogColor[2], fogden);
  forit (shChb,chubies)
   (*it)->rendrar(m);
  glBindVertexArray(m.mm->mivaosha[0]);
  glUseProgram(m.mm->mivaosha[1]);
  glUniform4f(m.mm->mitown, fogColor[0],fogColor[1],fogColor[2], fogden);
 }
 void collide(Mikey& m) {
  fogColor[0] = red->calx(prate);
  fogColor[1] = grn->calx(prate);
  fogColor[2] = blu->calx(prate);
  fogden  = 0.0;
  float sizzle = chubies.size();
  forit (shChb,chubies) { 
   (*it)->collide(m);
   if (!(*it)->dead) fogden += 1.0/sizzle;
  } 
 } 
 float getFogden() { return fogden; }
 const char * getClassName() { return className; }
};
const char Towne::className[] = "Towne";

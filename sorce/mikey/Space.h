
#include "Towne.h"
#include "Golem.h"

typedef TRCOLO shared_ptr<Towne> shTow;
#define caTow(a) TRCOLO dynamic_pointer_cast<Towne,Opero>(a)
typedef TRCOLO shared_ptr<Golem> shGol;
#define caGol(a) TRCOLO dynamic_pointer_cast<Golem,Opero>(a)

class Space : public Squar {
 protected:
 std::vector<shTow> townies; 
 std::vector<shGol> golmies; 
 //Towne * quicktown;
 shTow quicktown;
 shTow notown;
 public:
 Space() { 
  xloke = yloke = 0;
  xwido = yhido = 1000;
 }
 Space(lua_State *L) { 
  notown.reset(new Towne());
  quicktown = notown;
  xloke = luaL_checkint(L, 1);
  yloke = luaL_checkint(L, 2);
  xwido = luaL_checkint(L, 3);
  yhido = luaL_checkint(L, 4);
 }
 static const char className[];
 virtual void setter(const char*str, shOpr bingang) {
  shTow t = caTow(bingang);
  shGol g = caGol(bingang);
  if (strcmp(str,"add")==0) {
   if (t) townies.push_back(t);
   else if (g) golmies.push_back(g);
   return;
  }
  Opero::setter(str,bingang);
 }
 void sounder(float* l, float * r) {
  *l = *r = 0;
  //return;
  if (quicktown==notown) {
   forit(shGol,golmies)
    if ((**it).visible) (*it)->sounder(l,r); 
  } else if (quicktown) 
   quicktown->sounder(l,r);
 }
 void rendrar(Mikey& m) {
  glBindVertexArray(tovaosha[0]);  
  glUseProgram(tovaosha[1]);
  
  if (quicktown==notown) {
   forit(shGol,golmies)
    if ((**it).visible) (*it)->rendrar(m); 
   forit (shTow,townies) 
    if ((**it).visible) (*it)->qrendrar();
   glBindVertexArray(m.mm->mivaosha[0]);
   glUseProgram(m.mm->mivaosha[1]);
   glUniform4f(m.mm->mitown, 0,0,0,0);
  } else { 
   quicktown->rendrar(m);
  }
 }
 void collide(Mikey& m) {  
  //wraparound is this appropriate?
  m.xloke = fmod(m.xloke,xwido);
  m.yloke = fmod(m.yloke,yhido);
  forit (shTow,townies) {
   if (m<(**it)) (**it).visible = true;
   else (**it).visible = false;
   if  ((*it)->getFogden() == 0.0){
    quicktown = notown;
    townies.erase (it); 
    break;
   }
   if ((**it)==m) {
    quicktown = (*it); 
    quicktown->collide(m); 
    return;
   }
  }
  quicktown = notown;
  forit(shGol,golmies) {
   (*it)->collide(m); 
   if (m<(**it)) (**it).visible = true;
   else (**it).visible = false;
  }
 }
 bool spacedout() { 
  return (townies.size() == 0);
 }
 const char * getClassName()   { return className; }
};
const char Space::className[] = "Space";


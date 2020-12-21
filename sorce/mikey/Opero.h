 #define PI 3.14159265
#define TWOPIE 6.2831853

float inline frand() { 
	return (float)(rand()%1111) / (float)(1111); }
//returns from 0 to 1
float inline frand(float Max) { 
	return frand() * Max; 
}
//returns from 0 to Max
float inline frand(float Min, float Max) { 
	return (frand() * (Max - Min)) + Min; 
} //returns from Min to Max

#include <map>
#include <string>
#include <algorithm>


struct Opero;
typedef TRCOLO shared_ptr<Opero> shOpr;
typedef shOpr* userdataType;
typedef TRCOLO weak_ptr<Opero> weOpr;
shOpr lunar_getopero(lua_State *L, int narg, float opto=0);

struct Opero {
 float mint;
 shOpr ref;
 Opero(){}
 Opero(float m) { 
  mint = m; 
 }
 virtual ~Opero() { } 
 // for destruction of multiple inheritance
 void makeRefer(const shOpr& s);
 struct custom_comparer {
  bool operator()(const std::string& left, const std::string& right) const {
   return std::lexicographical_compare(left.begin(),left.end(),right.begin(),right.end());
  }
 };
 std::map<const char*,shOpr*,custom_comparer> broing;
 static const char className[];
 void broinger(lua_State *L, int step, const char * namo, shOpr*ino, float opt=0) {
  broing[namo] = ino;
  int walk = 0;
  if ((step>=lua_gettop(L)) && (lua_istable(L,lua_gettop(L)))) { 
  //for (int i = 1; i <= lua_gettop(L); i++) { 
   //if (lua_istable(L,lua_gettop(L))) { 
    
    lua_getfield (L, lua_gettop(L), namo);
    *ino = lunar_getopero(L,-1,opt);
    //printf ("tablo%f%d\n", (*ino)->getMint(),lua_gettop(L));
    lua_pop(L,1);
   } //else if ((++walk)==step) 
  else *ino = lunar_getopero(L,step,opt);
  //}
  //} 
  //else *ino = lunar_getopero(L,step,opt);
 }
 int nexter(lua_State *L) { 
  std::map<const char*,shOpr*>::iterator it;
  if (lua_isnil(L, -1)) 
   it = broing.begin();
  else 
   it = broing.upper_bound(lua_tostring(L,-1));
  if (it==broing.end()) {
   lua_pushnil(L); return 1;
  }
  lua_pushstring (L,it->first);
  shOpr *o = new shOpr(*it->second);
  if (!o) return 0;
  userdataType *ud;
  ud = static_cast<userdataType*>(lua_newuserdata(L, sizeof(userdataType)));
  *ud = o;
  luaL_getmetatable(L, "Opero");//(*o)->getClassName());
  lua_setmetatable(L, -2); 
  return 2;   
 }
 virtual void setter(const char*str,shOpr bingang) {
  for (std::map<const char*,shOpr*>::iterator it=broing.begin(); it!=broing.end(); ++it)
   if (strcmp(str,it->first)==0) *it->second = bingang;
 }
 virtual shOpr getter(const char*str) {
  for (std::map<const char*,shOpr*>::iterator it=broing.begin(); it!=broing.end(); ++it)
   if (strcmp(str,it->first)==0) return *it->second;
  return shOpr();
 }
//  float buff[512];
//  int buffstuff;
//  void buffcalx(int bs) {
//   buffstuff = bs;
//   if (buffstuff == 0) buff[0] = calx(prate);
//   else for(int i = 0; i < 512; i++) 
//    buff[i] = calx(srate);
//  }
//   
 virtual float calx(float sr) { return mint; }
  void setMint(float f) { mint = f; }
  float getMint() { return mint; }
 virtual const char * getClassName()  { return className; }
};
const char Opero::className[] = "Opero";

struct Refer : Opero {
 weOpr refr;
 Refer(const shOpr& r) { 
  refr = r;
 } 
 static const char className[];


 float calx(float sr) { 
  shOpr lo = refr.lock();
  if (lo) return lo->getMint(); 
//printf("nolockl\n");
   return 0;
 }
 const char * getClassName()  { return className; }
};
const char Refer::className[] = "Refer";
void Opero::makeRefer(const shOpr& s) {
 ref.reset(new Refer(s));
 broing["ref"] = &ref;
}



shOpr lunar_getopero(lua_State *L, int narg, float opto) {
 if (lua_isuserdata(L,narg)) {
  userdataType *ud =
   static_cast<userdataType*>(lua_touserdata(L, narg));
  if(ud) return **ud ;//ud->pT;
 }
 float r = luaL_optnumber (L, narg, opto);
 shOpr o (new Opero(r));
 o->makeRefer(o);
 return o;
}

#define forit(type,obje) \
 for (std::vector<type>::iterator it = obje.begin(); it != obje.end(); ++it)

class Mikey;

#include <vector>

#include "Opera/Vibro.h"
#include "Opera/Trang.h"
#include "Opera/Nuron.h"
#include "Opera/Trigg.h"
//#include "Opera/Karpo.h"
//#include "Opera/Tronk.h"
#include "Opera/Grass.h"
#include "Opera/Adder.h"
#include "Opera/Fours.h"
#include "Opera/Muler.h"
#include "Opera/Swoop.h"
//#include "Opera/Pendo.h"


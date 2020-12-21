
static inline int opero_new(lua_State * L, Opero * o) {
 if (!o) return 0;
 shOpr * obj = new shOpr(o);
 (*obj)->makeRefer(*obj);
 userdataType *ud =
  static_cast<userdataType*>(lua_newuserdata(L, sizeof(userdataType)));
 if (ud) {
  *ud = obj;
  luaL_getmetatable(L, "Opero");
  lua_setmetatable(L, -2); 
  return 1;
 } return 0; 
}

static int lunar_mul(lua_State * L) {
 return opero_new(L, new Muler(L));
}

static int lunar_add(lua_State * L) {
 return opero_new(L, new Adder(L));
}

static int lunar_div(lua_State * L) {
 return opero_new(L, new Diver(L));
}

static int lunar_sub(lua_State * L) {
 return opero_new(L, new Suber(L));
}

static int lunar_mod(lua_State * L) {
 return opero_new(L, new Modor(L));
}

static int lunar_pow(lua_State * L) {
 return opero_new(L, new Powor(L));
}

static int lunar_nex(lua_State *L) {
 userdataType *ud = static_cast<userdataType*>(lua_touserdata(L, 1));
 shOpr obj;
 if (ud) obj = **ud;//ud->pT;
 if (!obj) return 0;
 return obj->nexter(L);
 return 0;
}

static int lunar_pai(lua_State *L) {
 lua_pushcfunction(L, lunar_nex);
 lua_pushvalue(L, -2);
 lua_pushnil(L);
 return 3;
}

static int lunar_nin(lua_State *L) {
 userdataType *ud = static_cast<userdataType*>(lua_touserdata(L, 1));
 shOpr obj;
 if (ud) obj = **ud;//ud->pT;
 if (!obj) return 0;
 obj->setter(lua_tostring(L, -2),lunar_getopero(L,-1,0));
 return 0;           
}
  
static int lunar_ind(lua_State *L) {
 userdataType *ud = static_cast<userdataType*>(lua_touserdata(L, 1));
 if(!ud) return 0; 
 shOpr obj = **ud;//ud->pT;
 if(!obj) return 0;
 shOpr *o = new shOpr(obj->getter(lua_tostring(L, -1)));
 if (!o) return 0;
 ud = static_cast<userdataType*>(lua_newuserdata(L, sizeof(userdataType)));
 *ud = o;
 luaL_getmetatable(L, "Opero");//(*o)->getClassName());
 lua_setmetatable(L, -2); 
 return 1;              
}

static int lunar_gco(lua_State *L) {
 userdataType *ud = static_cast<userdataType*>(lua_touserdata(L, 1));
 delete(*ud);
 return 0;
}

static int lunar_tos (lua_State *L) {
 char buff[32];
 char bufftoo[132];
 userdataType *ud = static_cast<userdataType*>(lua_touserdata(L, 1));
 if (!ud) return 0;
 shOpr obj = **ud;//ud->pT;
 if (!obj) return 0;
 sprintf(buff, "%p:", (void*)obj.get());
 sprintf(bufftoo, "{");
 for (std::map<const char*,shOpr*>::iterator it=obj->broing.begin(); it!=obj->broing.end(); ++it) {
  strcat(bufftoo, it->first);
  strcat(bufftoo, " ");
 }
 strcat(bufftoo, "}");
 lua_pushfstring(L, "%s: %s (%s)", obj->getClassName(), bufftoo, buff);
 return 1;
}

void lunar_operotable(lua_State *L) {
 lua_newtable(L);
 lua_setglobal(L, "Opera");
 luaL_newmetatable(L, "Opero");
 int metatable = lua_gettop(L);
 lua_pushliteral(L, "__tostring");
 lua_pushcfunction(L, lunar_tos);
 lua_settable(L, metatable);
 lua_pushliteral(L, "__newindex");
 lua_pushcfunction(L, lunar_nin);
 lua_settable(L, metatable);
 lua_pushliteral(L, "__gc");
 lua_pushcfunction(L, lunar_gco);
 lua_settable(L, metatable);
 lua_pushliteral(L, "__next");
 lua_pushcfunction(L, lunar_nex);
 lua_settable(L, metatable);
 lua_pushliteral(L, "__pairs");
 lua_pushcfunction(L, lunar_pai);
 lua_settable(L, metatable);
 lua_pushliteral(L, "__index");
 lua_pushcfunction(L, lunar_ind);
 lua_settable(L, metatable);
 lua_pushliteral(L, "__mul");
 lua_pushcfunction(L, lunar_mul);
 lua_settable(L, metatable);
 lua_pushliteral(L, "__add");
 lua_pushcfunction(L, lunar_add);
 lua_settable(L, metatable);
 lua_pushliteral(L, "__div");
 lua_pushcfunction(L, lunar_div);
 lua_settable(L, metatable);
 lua_pushliteral(L, "__sub");
 lua_pushcfunction(L, lunar_sub);
 lua_settable(L, metatable);
 lua_pushliteral(L, "__unm");
 lua_pushcfunction(L, lunar_sub);
 lua_settable(L, metatable);
 lua_pushliteral(L, "__mod");
 lua_pushcfunction(L, lunar_mod);
 lua_settable(L, metatable);
 lua_pushliteral(L, "__pow");
 lua_pushcfunction(L, lunar_pow);
 lua_settable(L, metatable);
 lua_pop(L, 1);  // drop metatable
}

template <typename T> 
static int lunar_new(lua_State *L) {
 return opero_new(L, new T(L));        
}

template <typename T> 
static void lunar_register(lua_State *L) {
 lua_pushcfunction(L, (lunar_new<T>));
 lua_setglobal(L, T::className);
 lua_getglobal(L, "Opera");
 lua_getglobal(L, T::className);
 lua_setfield (L, -2, T::className);
 lua_pop(L, 1);
}

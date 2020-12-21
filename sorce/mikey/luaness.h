lua_State *l;

int mikeyspace(lua_State *L);
int mikeywarp(lua_State *L);

bool luainit () {
 int error;
 l = luaL_newstate();
 luaL_openlibs(l); 
 lua_pushcfunction(l, mikeyspace);
 lua_setglobal(l, "mikeyspace");
 lua_pushcfunction(l, mikeywarp);
 lua_setglobal(l, "mikeywarp");

 lunar_operotable(l);
 lunar_register<Vibro>(l);
lunar_register<Noise>(l);
 lunar_register<Grass>(l);
     lunar_register<Bista>(l);
 lunar_register<Adder>(l);
 lunar_register<Powor>(l);
 lunar_register<Muler>(l);
 lunar_register<Diver>(l);
 lunar_register<Suber>(l);
 lunar_register<Trang>(l);
     lunar_register<Drang>(l);
 lunar_register<Tooth>(l);
 lunar_register<Wheel>(l);
	// lunar_register<Minto>(l);
//lunar_register<Refer>(l);
lunar_register<Swoop>(l);
lunar_register<Fours>(l);
lunar_register<Horse>(l);
lunar_register<Difer>(l);
//lunar_register<Refer>(l);
// lunar_register<Karpo>(l);
//	lunar_register<Pendo>(l);
lunar_register<Trigg>(l);
    lunar_register<Salsa>(l);
	lunar_register<Nuron>(l);
 lunar_register<Towne>(l);
 lunar_register<Space>(l);
 lunar_register<Chube>(l);
 lunar_register<Golem>(l);

#if defined(STEVEJOBS)
	char path[PATH_MAX];
	char luapath[PATH_MAX];
	CFURLRef res = CFBundleCopyBundleURL(CFBundleGetMainBundle());
	CFURLGetFileSystemRepresentation(res, true, (UInt8 *)path, PATH_MAX);
	strcpy(luapath,path);
	strcat(luapath,"/../luals/?.lua");
	strcat(path,"/../main.lua");
	char supapath[PATH_MAX+PATH_MAX];
	sprintf(supapath,"package.path=package.path..\";%s\"",luapath);
	luaL_dostring(l,supapath);
	lua_pushstring(l,luapath);
	lua_setglobal(l,"LUA_PATH");
error =luaL_dofile (l, path);
CFRelease(res);
#else
 char luapath[PATH_MAX];
 strcpy(luapath,"./luals/?.lua");
 char supapath[PATH_MAX+PATH_MAX];
 sprintf(supapath,"package.path=package.path..\";%s\"",luapath);
 luaL_dostring(l,supapath);
 error =luaL_dofile (l, "main.lua");
#endif
 if (error) {
  fprintf(stderr, "%s", lua_tostring(l, -1));
  lua_pop(l, 1);  /* pop error message from the stack */
 } 
 return true;
}


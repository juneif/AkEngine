#include "Ak_LuaGlue.h"
#include "lua_tinker.h"

lua_State* g_luaState = NULL;




void TestF()
{
	printf("TTT\n");
}




void LuaGlue_Init()
{
	g_luaState = lua_open();
	luaL_openlibs(g_luaState);
	lua_tinker::init(g_luaState);

	LuaGlue_RegisterLuaFile("resources/main.lua");


	lua_tinker::def(g_luaState, "ak_test", TestF);
	lua_tinker::call<void>(g_luaState, "TestFun", 100);
}

void LuaGlue_Destroy()
{
	lua_close(g_luaState);
}

void LuaGlue_RegisterLuaFile(const char* c_szFileName)
{
	lua_tinker::dofile(g_luaState, c_szFileName);
}
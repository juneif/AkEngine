#ifndef _AK_LUAGLUE_H_
#define _AK_LUAGLUE_H_

void LuaGlue_Init();
void LuaGlue_Destroy();

void LuaGlue_RegisterLuaFile(const char* c_szFileName);

#endif
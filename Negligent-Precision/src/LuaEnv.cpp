#include "nppch.h"
#include "LuaEnv.h"


bool LuaEnv::callFile(std::string filename)
{
	if (luaL_loadfile(_state, filename.c_str()))
	{
		std::cout << "Error: Lua couldn't load script ( " << filename << " )" << std::endl;
		return false;
	}
	else if (lua_pcall(_state, 0, 0, 0))
	{
		std::cout << "Error: " << lua_tostring(_state, -1) << std::endl;
		return false;
	}
	return true;
}

LuaEnv::LuaEnv()
{
	_state = luaL_newstate();
	luaL_openlibs(_state);
}

LuaEnv::~LuaEnv()
{
	lua_close(_state);
}
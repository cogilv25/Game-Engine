#include "nppch.h"
#include "LuaEnv.h"


void LuaEnv::callFile(std::string filename)
{
	if (luaL_loadfile(_state, filename.c_str()))
		std::cout << "Error: script not loaded ("<< filename << ")" << std::endl;
	else
		if (lua_pcall(_state, 0, 0, 0))
			std::cout << "Error: " << lua_tostring(_state, -1) << std::endl;
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
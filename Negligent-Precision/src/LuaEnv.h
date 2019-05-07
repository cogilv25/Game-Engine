#pragma once
extern "C"
{
	#include "lua.h"
	#include "lauxlib.h"
	#include "lualib.h"
}
#include <string>

class LuaEnv
{
	lua_State * _state;
	template <typename T> T _getNull()
	{
		return 0;
	}
	template<> std::string _getNull()
	{
		return "Null";
	}

	template <typename T> inline T _getLuaTop()
	{
		std::cout << "Error: Attempted to get unknown type from lua stack" << std::endl;
		return 0;
	}
	template<> inline int _getLuaTop()
	{
		if (lua_isnumber(_state,-1))
			return (int)lua_tonumber(_state, -1);

		std::cout << "Error: Attempted to get non-number as an int from lua stack" << std::endl;
		return 0;
	}
	template<> inline float _getLuaTop()
	{
		if (lua_isnumber(_state, -1))
			return (float)lua_tonumber(_state, -1);

		std::cout << "Error: Attempted to get non-number as a float from lua stack" << std::endl;
		return 0.0f;
	}
	template<> inline std::string _getLuaTop()
	{
		if (lua_isstring(_state, -1))
			return lua_tostring(_state, -1);

		std::cout << "Error: Attempted to get non-string as a string from lua stack" << std::endl;
		return "Null";
	}
	template<> inline const char* _getLuaTop()
	{
		if (lua_isstring(_state, -1))
			return lua_tostring(_state, -1);

		std::cout << "Error: Attempted to get non-string as a string from lua stack" << std::endl;
		return "Null";
	}
public:
	void callFile(std::string filename);
	template<typename T> inline T get(std::string name)
	{
		if (!_state)
		{
			std::cout << "Error: Tried to get a value before initialising LuaEnv" << std::endl; 
			return 0;
		}
		lua_getglobal(_state, name.c_str());
		if (lua_isnil(_state, -1))
		{
			std::cout << "Error: Tried to get a value undefined in LuaEnv" << std::endl;
			return _getNull<T>();
		}
		T out = _getLuaTop<T>();
		lua_pop(_state, 1);
		return out;
	}
	LuaEnv();
	~LuaEnv();
};


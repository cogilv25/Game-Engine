#pragma once


#include <stack>
#include <string>
#include <iostream>
#include <assert.h>

#ifdef NP_PLATFORM_WINDOWS
#include <Windows.h>
#endif


#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "imgui.h"
#include "glm/glm.hpp"
extern "C"
{
# include "lua.h"
# include "lauxlib.h"
# include "lualib.h"
}
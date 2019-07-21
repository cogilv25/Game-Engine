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

//I wish I would comment things at the time... what is this! xD
//These files are included in the project now and def is in:
//imgui_impl_opengl3.cpp so no longer required here
/*
#define IMGUI_IMPL_OPENGL_LOADER_GLAD
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
*/
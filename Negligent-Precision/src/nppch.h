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
/*
#define IMGUI_IMPL_OPENGL_LOADER_GLAD
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
*/
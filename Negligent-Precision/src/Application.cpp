#include "nppch.h"
#include "Application.h"
#include "LuaEnv.h"
#include "examples/imgui_impl_glfw.h"
#include "examples/imgui_impl_opengl3.h"

namespace np
{
	
	glm::mat4 MVP = glm::mat4(1.0f);
	Application::Application()
	{
		//Test
		LuaEnv luaVM;
		luaVM.callFile("../bin/Debug-windows-x86_64/Sandbox/test.lua");

		Window win(luaVM.get<std::string>("settings.title"), luaVM.get<int>("width"), luaVM.get<int>("height"));
		win.initialize();

		glfwMakeContextCurrent(win._glfwWindow);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		assert(status);
		GLuint textureID;

		glCreateTextures(GL_TEXTURE_2D, 1, &textureID);
		assert(glGetError()==0);
	}


	Application::~Application()
	{
		glfwTerminate();
	}

	void Application::run()
	{
		initialise();
		std::cin.get();
		shutdown();
	}

}
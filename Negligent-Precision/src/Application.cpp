#include "nppch.h"
#include "Application.h"
#include "examples/imgui_impl_glfw.h"
#include "examples/imgui_impl_opengl3.h"

namespace np
{
	
	glm::mat4 MVP = glm::mat4(1.0f);
	Application::Application()
	{
		//Test
		Window win("Test", 1280, 720);
		win.initialize();
		glfwMakeContextCurrent(win._glfwWindow);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		assert(status);
		GLuint textureID;
		glCreateTextures(GL_TEXTURE_2D, 1, &textureID);
		assert(glGetError()==0);

		auto L = luaL_newstate();
		luaL_openlibs(L);

		if (luaL_loadfile(L, "../bin/Debug-windows-x86_64/Sandbox/test.lua"))
			std::cout << "Error: script not loaded (test.lua)" << std::endl;
		else
			if (lua_pcall(L, 0, 1, 0))
				std::cout << "Error: " << lua_tostring(L, -1) << std::endl;
			else
				std::cout << lua_tostring(L, -1) << std::endl;
		
		std::cin.get();

	}


	Application::~Application()
	{
	}

	void Application::run()
	{
		initialise();
		std::cin.get();
		shutdown();
	}

}
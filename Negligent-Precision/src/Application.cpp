#include "nppch.h"
#include "Application.h"

namespace np
{
	
	glm::mat4 MVP = glm::mat4(1.0f);
	Application::Application()
	{
		//Test
		glfwInit();
		auto window = glfwCreateWindow(1280, 720, "Test", 0, 0);
		glfwMakeContextCurrent(window);
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
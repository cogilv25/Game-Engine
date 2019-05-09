#include "nppch.h"
#include "Application.h"
#include "LuaEnv.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

namespace np
{
	
	glm::mat4 MVP = glm::mat4(1.0f);
	Application::Application()
	{


		//These should be a part of Renderer init but they have to
		//be called before glfwInit...
		glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_API);

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);

		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);

		Window win;
		_window._title = luaVM.get<std::string>("title");
		_window._width = luaVM.get<int>("width");
		_window._height = luaVM.get<int>("height");
		_window.initialize();

		//Causes heap validation error 
		//_renderer.initialize(_window.windowRef);

		glfwMakeContextCurrent(_window._windowRef);
		glfwSwapInterval(1);


		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		assert(status);

		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		assert(glGetError() == 0);
		LuaEnv settings;
		if (settings.callFile("scripts/settings.lua"))
		{
			_window->_title = settings.get<std::string>("title");
			_window->_width = settings.get<int>("width");
			_window->_height = settings.get<int>("height");
		}
		else
		{
			//Make things awkward :P
			_window->_title = "No settings.lua file in scripts directory!";
			_window->_width = 500;
			_window->_height = 50;
			glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

		ImGui::CreateContext();
		ImGui_ImplGlfw_InitForOpenGL(_window._windowRef, true);
		ImGui_ImplOpenGL3_Init("#version 410");
		ImGui::StyleColorsDark();

		GLuint textureID;

		glCreateTextures(GL_TEXTURE_2D, 1, &textureID);
		assert(glGetError()==0);
	}


	Application::~Application()
	{
		_renderer.shutdown();
		glfwTerminate();
	}

	void Application::run()
	{
		initialize();
		_running = true;

		while (_running)
		{
			if (glfwWindowShouldClose(_window._windowRef))
				break;

			glClear(GL_COLOR_BUFFER_BIT | GL_STENCIL_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			glfwPollEvents();

			update();
			draw();

			_renderer.draw();

			glfwSwapBuffers(_window._windowRef);
		}

		shutdown();
	}

	void Application::stop()
	{
		_running = false;
	}

	bool Application::getKeyDown(int key)
	{
		if(glfwGetKey(_window._windowRef, key) == GLFW_PRESS)
			return true;
		return false;
	}

}
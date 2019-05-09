#include "nppch.h"
#include "Application.h"
#include "LuaEnv.h"

namespace np
{
	
	glm::mat4 MVP = glm::mat4(1.0f);
	Application::Application()
	{
		_window = new Window();
		_renderer = new Renderer();

		if (!glfwInit())
			std::cout << "Error: GLFW failed to initialize" << std::endl;

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
		}
		_window->initialize();

		//Used to cause heap validation error - not sure why what I did fixed it... So requires investigation.
		//Fixed by making _window and _renderer pointers and allocating at runtime? delete order doesn't matter
		_renderer->initialize(_window);

		GLuint textureID;

		glCreateTextures(GL_TEXTURE_2D, 1, &textureID);
		assert(glGetError()==0);
	}


	Application::~Application()
	{
		_renderer->shutdown();
		delete _renderer;
		delete _window;
		glfwTerminate();
	}

	void Application::run()
	{
		initialize();
		_running = true;

		while (_running)
		{
			if (glfwWindowShouldClose(_window->_windowRef))
				break;

			glClear(GL_COLOR_BUFFER_BIT | GL_STENCIL_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			glfwPollEvents();

			update();

			_renderer->startFrame();
			draw();
			_renderer->draw();
			_renderer->endFrame();
		}

		shutdown();
	}

	void Application::stop()
	{
		_running = false;
	}

	bool Application::getKeyDown(int key)
	{
		if(glfwGetKey(_window->_windowRef, key) == GLFW_PRESS)
			return true;
		return false;
	}

}
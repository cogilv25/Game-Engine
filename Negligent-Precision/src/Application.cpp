#include "nppch.h"
#include "Application.h"
#include "LuaEnv.h"
#include <chrono>

namespace np
{
	
	Application * Application::_instance;

	glm::mat4 MVP = glm::mat4(1.0f);
	Application::Application() 
		:window(*new Window), renderer(*new Renderer)
	{

		if (!glfwInit())
			std::cout << "Error: GLFW failed to initialize" << std::endl;

		LuaEnv settings;
		if (settings.callFile("scripts/settings.lua"))
		{
			window._title = settings.get<std::string>("title");
			window._width = settings.get<int>("width");
			window._height = settings.get<int>("height");
		}
		else
		{
			//Make things awkward :P
			//TODO: Maybe create the file
			window._title = "No settings.lua file in scripts directory!";
			window._width = 500;
			window._height = 50;
			glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
		}
		window.initialize();

		//Used to cause heap validation error.
		//Not sure why what I did fixed it so requires investigation. I fixed it
		//by allocating window and renderer at runtime? delete order didn't matter
		//Perhaps something todo with Renderer Constructor needing to be called first?
		renderer.initialize(&window);
		input.initialize(window._windowRef);

		GLuint textureID;

		glCreateTextures(GL_TEXTURE_2D, 1, &textureID);
		assert(glGetError()==0);

		_instance = this;
		std::cout << std::boolalpha;
	}


	Application::~Application()
	{
		renderer.shutdown();
		delete &renderer;
		delete &window;
		glfwTerminate();
	}

	void Application::run()
	{
		initialize();
		_running = true;

		//initial value somewhere around 60fps
		float frameTime = 0.0160f;

		auto before = std::chrono::high_resolution_clock::now();

		while (_running)
		{
			auto before = std::chrono::high_resolution_clock::now();

			if (glfwWindowShouldClose(window._windowRef))
				break;

			glClear(GL_COLOR_BUFFER_BIT | GL_STENCIL_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			glfwPollEvents();

			update();

			renderer.startFrame();
			draw();
			if (_showDebugInfo)
			{
				ImGui::Begin("Debug");
				ImGui::Text("FPS: %.0f", 1.0f/frameTime);
				ImGui::End();
			}
			renderer.draw();
			renderer.endFrame();


			auto after = std::chrono::high_resolution_clock::now();
			frameTime -= frameTime / 60.0f;
			frameTime += (std::chrono::duration_cast<std::chrono::duration<float>>(after - before).count()) / 60.0f;
		}

		shutdown();
	}

	void Application::stop()
	{
		_running = false;
	}


	

}
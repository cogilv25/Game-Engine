#pragma once
#include "Core.h"

namespace np
{
	class NP_API Renderer
	{
		friend class Application;
	private:
		GLFWwindow * _window;
	private:
		Renderer();
		~Renderer();
	private:
		void initialize(GLFWwindow*);
		void shutdown();
		void draw();

	};

}
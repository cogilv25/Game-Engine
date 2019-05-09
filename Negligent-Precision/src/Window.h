#pragma once
#include "Core.h"
#include <string>


struct GLFWwindow;
namespace np
{
	class NP_API Window
	{
		friend class Application;
		friend class Renderer;
	private:
		std::string _title;
		unsigned int _width;
		unsigned int _height;
		GLFWwindow* _windowRef;
	private:
		Window();
		Window(std::string title, unsigned int width, unsigned int height);
		~Window();
	private:
		void initialize();
	};

}
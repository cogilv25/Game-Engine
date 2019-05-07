#pragma once
#include "Core.h"
#include <string>


struct GLFWwindow;
namespace np
{
	class NP_API Window
	{
		friend class Application;
	private:
		std::string _title;
		unsigned int _width;
		unsigned int _height;
		GLFWwindow* _glfwWindow;
	public:
		Window();
		Window(std::string title, unsigned int width, unsigned int height);
		~Window();
	public:
		void initialize();
	};

}
#include "nppch.h"
#include "Window.h"


namespace np
{
	Window::Window()
	{
		_windowRef = 0;
		_width = 0;
		_height = 0;
	}

	Window::Window(std::string title, unsigned int width, unsigned int height)
	{
		_windowRef = 0;
		_title = title;
		_width = width;
		_height = height;
	}

	Window::~Window()
	{
		if(_windowRef)
			glfwDestroyWindow(_windowRef);
	}


	void Window::initialize()
	{
		if (!glfwInit())
			std::cout << "Error: GLFW failed to initialize" << std::endl;

			_windowRef = glfwCreateWindow(_width, _height, _title.c_str(), 0, 0);
	}
}
#include "nppch.h"
#include "Window.h"


namespace np
{
	Window::Window()
	{
		_glfwWindow = 0;
		_width = 800;
		_height = 400;
		_title = "Negligent Precision Application";
	}

	Window::Window(std::string title, unsigned int width, unsigned int height)
	{
		_glfwWindow = 0;
		_title = title;
		_width = width;
		_height = height;
	}

	Window::~Window()
	{
		if(_glfwWindow)
			glfwDestroyWindow(_glfwWindow);
	}


	void Window::initialize()
	{
		if (!glfwInit())
			std::cout << "Error: GLFW failed to initialize" << std::endl;
			_glfwWindow = glfwCreateWindow(_width, _height, _title.c_str(), 0, 0);
	}
}
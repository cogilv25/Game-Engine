#include "nppch.h"
#include "Application.h"

namespace np
{

	Application::Application()
	{
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
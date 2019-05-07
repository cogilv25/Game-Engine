#pragma once
#include "Core.h"
#include "Window.h"


namespace np
{
	class NP_API Application
	{

	public:
		void run();
		Application();
		~Application();
		//Functions to be overridden by client app
		virtual void update() = 0;
		virtual void draw() = 0;
		virtual void initialise() = 0;
		virtual void shutdown() = 0;
	};
}
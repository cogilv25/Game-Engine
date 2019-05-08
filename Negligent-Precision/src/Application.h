#pragma once
#include "Core.h"
#include "Window.h"
#include "Renderer.h"


namespace np
{
	class NP_API Application
	{
		bool _running;
		Window _window;
		Renderer _renderer;
	protected:
		bool getKeyDown(int key);
		//Functions to be overridden by client app
		virtual void update() = 0;
		virtual void draw() = 0;
		virtual void initialize() {};
		virtual void shutdown() {};

	public:
		Application();
		~Application();

	public:
		void run();
		void stop();
	};
}
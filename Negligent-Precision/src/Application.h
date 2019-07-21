#pragma once
#include "Core.h"
#include "Window.h"
#include "Renderer.h"
#include "Input.h"

namespace np
{


	class NP_API Application
	{
		friend void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
	private:
		bool _running;
		static Application * _instance;
	protected:
		//Maybe this is bad practice? but I wanted user
		//to be able to use . operator instead of ->
		//and had to use runtime allocation
		//due to heap validation error?

		Renderer& renderer;
		Window& window;

		Input input;

		bool _showDebugInfo = false;
	protected:
		//Functions to be overridden by client app
		virtual void update() = 0;
		virtual void draw() = 0;
		//Optional client overridable functions
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
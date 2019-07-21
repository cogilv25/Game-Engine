#pragma once
#include "Core.h"

namespace np
{

	class Window;

	class NP_API Renderer
	{
		friend class Application;
	private:
		const Window * _window;
	private:
		Renderer();
		~Renderer();
	private:
		void initialize(const Window*);
		void shutdown();
		void startFrame();
		void draw();
		void endFrame();
	public:
		//Client accessible functions
	};

}
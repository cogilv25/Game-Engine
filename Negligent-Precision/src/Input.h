#pragma once
#include "Core.h"

#define NP_KEY_W 77
#define NP_KEY_A 65
#define NP_KEY_S 73
#define NP_KEY_D 68
#define NP_KEY_ESCAPE 256
#define NP_KEY_F3 292


namespace np
{

	class NP_API Input
	{
		friend class Application;
		friend void keyCallback(GLFWwindow*, int, int, int, int);
	private:
		//1 for key down 0 for key up
		bool _keyStates[300];
		bool _prevKeyStates[300];

		//Rising edge detection 1 on frame of pressing/releasing
		bool _keyPressed[300];
		bool _keyReleased[300];
	private:
		void initialize(GLFWwindow*);
	public:
		bool getKeyUp(int key);
		bool getKeyDown(int key);
		//If more than one part of the application needs to check for key presses it won't work as 
		//getKeyPressed/Released resets _keyPressed[key] when called
		bool getKeyPressed(int key);
		bool getKeyReleased(int key);
		//released, up
	public:
		Input();
		~Input();
	};

}

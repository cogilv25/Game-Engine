#include "nppch.h"
#include "Input.h"
#include "Application.h"

namespace np
{

	void keyCallback(GLFWwindow * window, int key, int scancode, int action, int mods)
	{
		Input* inp = &Application::_instance->input;

		inp->_prevKeyStates[key] = inp->_keyStates[key];
		inp->_keyStates[key] = action;
		if (!inp->_prevKeyStates[key] && inp->_keyStates[key])
		{
			inp->_keyPressed[key] = true;
		}
		else if (inp->_prevKeyStates[key] && !inp->_keyStates[key])
		{
			inp->_keyReleased[key] = true;
		}

	}
	void Input::initialize(GLFWwindow* win)
	{
		glfwSetKeyCallback(win, keyCallback);
	}

	bool Input::getKeyDown(int key)
	{
		return _keyStates[key];
	}

	bool Input::getKeyUp(int key)
	{
		return !(_keyStates[key]);
	}

	bool Input::getKeyPressed(int key)
	{
		bool result = false;
		if (_keyPressed[key])
		{
			result = true;
			_keyPressed[key] = false;
		}
		return result;
	}

	bool Input::getKeyReleased(int key)
	{
		bool result = false;
		if (_keyReleased[key])
		{
			result = true;
			_keyReleased[key] = false;
		}
		return result;
	}

	Input::Input()
	{
		memset(_keyStates, 0, 300 * sizeof(bool));
		memset(_prevKeyStates, 0, 300 * sizeof(bool));
		memset(_keyPressed, false, 300 * sizeof(bool));
		memset(_keyReleased, false, 300 * sizeof(bool));
	}


	Input::~Input()
	{
	}

}
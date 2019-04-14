#include "nppch.h"
#include "Application.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "imgui.h"

namespace np
{

	Application::Application()
	{
		//Test
		glfwInit();
		auto window = glfwCreateWindow(1280, 720, "Test", 0, 0);
		glfwMakeContextCurrent(window);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		assert(status);
		GLuint textureID;
		glCreateTextures(GL_TEXTURE_2D, 1, &textureID);
		assert(glGetError()==0);
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
#include "nppch.h"
#include "Renderer.h"
#include "Window.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

namespace np
{

	Renderer::Renderer()
	{
		//These must be called before glfwInit()
		glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_API);

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);

		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
	}

	Renderer::~Renderer()
	{

	}

	void Renderer::initialize(const Window* w)
	{
		_window = w;

		glfwMakeContextCurrent(w->_windowRef);
		glfwSwapInterval(1);


		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		assert(status);

		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		assert(glGetError() == 0);
		ImGui::CreateContext();
		ImGui_ImplGlfw_InitForOpenGL(w->_windowRef, true);
		ImGui_ImplOpenGL3_Init("#version 410");
		ImGui::StyleColorsDark();
	}

	void Renderer::shutdown()
	{
		ImGui_ImplOpenGL3_Shutdown();
		ImGui_ImplGlfw_Shutdown();
		ImGui::DestroyContext();
	}

	void Renderer::startFrame()
	{
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();
	}

	void Renderer::draw()
	{
		ImGui::Begin("Debug");
		ImGui::Text("FPS: %.0f", 54.33);
		ImGui::End();
	}

	void Renderer::endFrame()
	{
		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
		glfwSwapBuffers(_window->_windowRef);
	}

}
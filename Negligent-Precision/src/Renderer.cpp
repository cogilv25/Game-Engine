#include "nppch.h"
#include "Renderer.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

namespace np
{

	Renderer::Renderer()
	{
	}

	Renderer::~Renderer()
	{
	}

	void Renderer::initialize(GLFWwindow * w)
	{
		_window = w;
		glfwMakeContextCurrent(w);
		glfwSwapInterval(1);


		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		assert(status);

		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		assert(glGetError() == 0);

		ImGui::CreateContext();
		ImGui_ImplGlfw_InitForOpenGL(w, true);
		ImGui_ImplOpenGL3_Init("#version 410");
		ImGui::StyleColorsDark();
	}

	void Renderer::shutdown()
	{
		ImGui_ImplOpenGL3_Shutdown();
		ImGui_ImplGlfw_Shutdown();
		ImGui::DestroyContext();
	}

	void Renderer::draw()
	{
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();
		ImGui::Begin("Debug");
		ImGui::Text("FPS: %.0f", 54.33);
		ImGui::End();
		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}

}
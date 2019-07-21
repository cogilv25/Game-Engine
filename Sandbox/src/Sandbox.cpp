#include "Sandbox.h"
#include <iostream>

using namespace np;

//Define function called by main() in EntryPoint.h
Application* np::createApplication()
{
	return new Sandbox;
}


void Sandbox::initialize()
{
	
}

void Sandbox::shutdown()
{

}

void Sandbox::update()
{
	if (input.getKeyPressed(NP_KEY_ESCAPE))
		stop();
	if (input.getKeyPressed(NP_KEY_F3))
		_showDebugInfo = !_showDebugInfo;
}

void Sandbox::draw()
{
	ImGui::Begin("Test");
	ImGui::Text("Hello World %d", 42, "test");
	ImGui::End();
}
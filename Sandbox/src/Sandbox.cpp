#include "Sandbox.h"
#include <iostream>

//Define function called by main() in EntryPoint.h
np::Application* np::createApplication()
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
	if (getKeyDown(NP_ESCAPE))
	{
		stop();
	}
}

void Sandbox::draw()
{

}
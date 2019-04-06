#include "Sandbox.h"
#include <iostream>

//Define function called by main() in EntryPoint.h
np::Application* np::createApplication()
{
	return new Sandbox;
}

void Sandbox::initialise()
{

}

void Sandbox::shutdown()
{

}

void Sandbox::update()
{

}

void Sandbox::draw()
{

}
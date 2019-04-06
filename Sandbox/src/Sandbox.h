#pragma once
#include <Negligent-Precision.h>
class Sandbox : public np::Application
{
public:
	void update();
	void draw();
	void initialise();
};
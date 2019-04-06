#pragma once
namespace np{
extern Application* createApplication();
}

int main(int argc, char** argv)
{
	np::Application* application = np::createApplication();
	application->run();
	delete application;
}

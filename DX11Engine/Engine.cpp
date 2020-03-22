#include "Engine.h"

bool Engine::Init(HINSTANCE hInstance, std::string title, std::string wClass, int width, int height)
{
	//Init window
	return m_renderWindow.Init(hInstance, title, wClass, width, height);

	//Init graphics
}

bool Engine::ProcessEvents()
{
	return m_renderWindow.ProcessEvents();
}

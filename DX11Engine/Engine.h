#pragma once
#include "WindowContainer.h"

class Engine : WindowContainer
{
public:
	bool Init(HINSTANCE hInstance, std::string title, std::string wClass, int width, int height);
	bool ProcessEvents();
	void Update();

private:
	bool m_debug = true;
};


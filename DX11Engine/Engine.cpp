#include "Engine.h"

bool Engine::Init(HINSTANCE hInstance, std::string title, std::string wClass, int width, int height)
{
	//Init window
	return m_renderWindow.Init(this, hInstance, title, wClass, width, height);

	//Init graphics
}

bool Engine::ProcessEvents()
{
	return m_renderWindow.ProcessEvents();
}

void Engine::Update()
{
	while (!m_keyboard.CharBufferIsEmpty())
	{
		unsigned char ch = m_keyboard.ReadChar();
		std::string str = "Input: ";
		str += ch;
		str += "\n";
		OutputDebugStringA(str.c_str());
	}

	while (!m_keyboard.KeyBufferIsEmpty())
	{
		KeyboardEvent e = m_keyboard.ReadKey();
		unsigned char keycode = e.GetKeyCode();
		std::string str = "Keycode: ";
		str += keycode;
		
		if (e.IsPress())
			str += " is pressed ";
		else if (e.IsRelease())
			str += " is released";
		
		str += "\n";
		OutputDebugStringA(str.c_str());
	}
}

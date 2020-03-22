#pragma once
#include "ErrorLogger.h"

class RenderWindow
{
public:
	~RenderWindow();
	bool Init(HINSTANCE hInstance, std::string title, std::string wClass, int width, int height);
	bool ProcessEvents();

private:
	void RegisterWindowClass();
	
	HWND m_handle = NULL;
	HINSTANCE m_hInstance = NULL;
	std::string m_title, m_wClass = "";
	std::wstring m_titleWide, m_wClassWide = L"";
	int m_width, m_height = 0;
};


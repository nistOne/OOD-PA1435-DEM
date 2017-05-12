#pragma once
#include "Window.h"
#include "Log.h"

using namespace std;

class TextWindow : public Window
{
private:

	// Edit
	Log m_log;

public:

	TextWindow();
	~TextWindow();

	virtual void Render();
};
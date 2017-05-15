#pragma once
#include "Window.h"
#include "Log.h"

using namespace std;

class TextWindow : public Window
{
private:

	// Edit
	//Log m_log;

public:

	TextWindow();
	~TextWindow();

	void testUpdate();
	virtual void Render(sf::RenderWindow &window);
};
#pragma once
#include "Window.h"

using namespace std;

class textWindow : public Window
{
private:

	

	LogNode * m_firstLog;
	LogNode * m_lastLog;

public:

	textWindow(sf::Vector2f size, sf::Vector2f pos, sf::Color color);
	~textWindow();

	bool render();
	
	void log_push(string line);
};
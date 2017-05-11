#pragma once
#include "Window.h"

using namespace std;

class textWindow : public Window
{
private:

	string * m_log;

public:

	textWindow(sf::Vector2f size, sf::Vector2f pos, sf::Color color);
	~textWindow();

	//log_push
};
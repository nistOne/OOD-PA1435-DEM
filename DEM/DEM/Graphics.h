#pragma once
#include "SFML-2.4.2/include/SFML/Graphics.hpp"
#include "GameWindow.h"
#include "TextWindow.h"

class Graphics
{
private:

	sf::RenderWindow m_window;
	GameWindow m_gameWindow;
	TextWindow m_textWindow;

public:

	Graphics();
	~Graphics();

	Observer* getMapObserver();

	void Render();
};
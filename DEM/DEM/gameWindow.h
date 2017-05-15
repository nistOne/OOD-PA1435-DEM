#pragma once
#include "Window.h"

class GameWindow : public Window
{
private:
	// Add getMap function.


public:

	GameWindow();
	~GameWindow();

	virtual void Render(sf::RenderWindow &window);
};
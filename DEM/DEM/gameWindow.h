#pragma once
#include "Window.h"

class GameWindow : public Window
{
private:
	// Edit

public:

	GameWindow();
	~GameWindow();

	virtual void Render(sf::RenderWindow &window);
};
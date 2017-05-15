#pragma once
#include "Window.h"

// DELETE
#include "Map.h"

class GameWindow : public Window
{
private:
	// Add getMap function.

	// DELETE
	Map m_map;

public:

	GameWindow();
	~GameWindow();

	virtual void Render(sf::RenderWindow &window);
};
#pragma once
#include "Window.h"
#include "MapObserver.h"
#include "Map.h"
#include "Constants.h"

class GameWindow : public Window
{
private:
	// Add getMap function.

	MapObserver* m_mapObserver;
	char m_map[MAPWIDTH][MAPHEIGHT];
	
public:

	GameWindow();
	~GameWindow();

	Observer* getObserver();

	virtual void Render(sf::RenderWindow* window);
};
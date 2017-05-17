#pragma once
#include "Window.h"
#include "MapObserver.h"
#include "CoordObserver.h"
#include "Map.h"
#include "Constants.h"

class GameWindow : public Window
{
private:
	// Add getMap function.

	MapObserver* m_mapObserver;
	CoordObserver* m_coordObserver;
	char m_map[MAPWIDTH][MAPHEIGHT];
	
public:

	GameWindow();
	~GameWindow();

	Observer* getMapObserver();
	Observer* getCoordObserver();

	virtual void Render(sf::RenderWindow* window);
};
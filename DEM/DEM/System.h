#pragma once
#include "Graphics.h"
#include "EntityHandler.h"
#include "Map.h"

class System
{
private:

	sf::RenderWindow* m_rWindow;
	EntityHandler m_entityHandler;
	Graphics m_graphics;
	Map m_map;

public:

	System();
	~System();

	void Run();

};
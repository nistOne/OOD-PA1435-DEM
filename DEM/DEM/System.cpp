#include "System.h"

System::System()
{
}

System::~System()
{
}

void System::Run()
{
	this->m_entityHandler.addPlayer("Sanic");

	// Register observers to Map.
	this->map.registerObserver(this->m_entityHandler.getObserver());
	this->map.registerObserver(this->m_graphics.getMapObserver());

	this->map.GenerateMap();

	// Game loop. Observ input later on.
	while (true)
	{
		this->m_graphics.Render();
	}
}

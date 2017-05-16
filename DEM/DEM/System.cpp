#include "System.h"

System::System()
{
}

System::~System()
{
}

void System::Run()
{
	this->map.registerObserver(this->m_graphics.getMapObserver());
	this->map.GenerateMap();

	// Game loop. Observ input later on.
	while (true)
	{
		this->m_graphics.Render();
	}
}

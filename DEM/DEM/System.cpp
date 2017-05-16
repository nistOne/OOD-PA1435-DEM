#include "System.h"

System::System()
{
	this->m_rWindow = new sf::RenderWindow(sf::VideoMode(1200, 800), "DEM");
}

System::~System()
{
	delete this->m_rWindow;
}

void System::Run()
{
	this->m_graphics.setRenderWindow(this->m_rWindow);
	
	this->m_entityHandler.addPlayer("Sanic");
	
	// Register observers to Map.
	this->m_map.registerObserver(this->m_entityHandler.getObserver());
	this->m_map.registerObserver(this->m_graphics.getMapObserver());

	this->m_map.GenerateMap();

	// Game loop. Observ input later on.
	while (this->m_rWindow->isOpen())
	{
		sf::Event event;
		while (this->m_rWindow->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				this->m_rWindow->close();
		}
		
		this->m_graphics.Render();
	}
}

#include "System.h"

// DELETE
#include <iostream>

System::System()
{
	this->m_rWindow = new sf::RenderWindow(sf::VideoMode(1200, 800), "DEM");
	this->m_inputGrabber = new InputGrabber();

	this->m_rWindow->setKeyRepeatEnabled(false);
}

System::~System()
{
	delete this->m_rWindow;
	delete this->m_inputGrabber;
}

void System::Run()
{
	this->m_graphics.setRenderWindow(this->m_rWindow);
	
	this->m_entityHandler.addPlayer("Sanic");
	
	// Register observers.
	this->m_map.registerObserver(this->m_entityHandler.getMapObserver());
	this->m_map.registerObserver(this->m_graphics.getMapObserver());
	this->m_entityHandler.registerDialogueObserver(this->m_graphics.getDialogueObserver());
	this->m_inputGrabber->registerInputObserver(this->m_entityHandler.getInputObserver());

	this->m_map.GenerateMap();

	// Game loop. Observ input later on.
	while (this->m_rWindow->isOpen())
	{
		sf::Event event;
		while (this->m_rWindow->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				this->m_rWindow->close();

			this->m_inputGrabber->setEvent(event);
		}
		
		this->m_graphics.Render();
	}
}

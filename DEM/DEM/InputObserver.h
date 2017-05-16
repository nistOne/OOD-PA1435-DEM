#pragma once
#include "Observer.h"
#include "SFML-2.4.2/include/SFML/Graphics.hpp"

class InputObserver : public Observer
{
private:

	sf::Event m_event;

public:

	InputObserver();
	~InputObserver();

	void update(sf::Event event);

	virtual Observer* getPointer();
	sf::Event getEvent();
};
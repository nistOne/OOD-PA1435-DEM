#pragma once
#include "Subject.h"
#include "InputObserver.h"
#include "SFML-2.4.2/include/SFML/Graphics.hpp"

class InputGrabber : public Subject
{
private:

	sf::Event m_event;

public:

	InputGrabber() {}
	~InputGrabber() {}

	virtual void notifyObservers();

	void setEvent(sf::Event event);
};
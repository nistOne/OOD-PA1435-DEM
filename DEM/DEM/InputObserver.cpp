#include "InputObserver.h"

InputObserver::InputObserver()
{
}

InputObserver::~InputObserver()
{
}

void InputObserver::update(sf::Event event)
{
	this->m_event = event;
}

Observer * InputObserver::getPointer()
{
	return this;
}

sf::Event InputObserver::getEvent()
{
	return this->m_event;
}

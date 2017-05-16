#include "InputObserver.h"

InputObserver::InputObserver()
{
	this->m_updated = false;
}

InputObserver::~InputObserver()
{
}

void InputObserver::update(sf::Event event)
{
	this->m_event = event;
	this->setUpdated();
}

Observer * InputObserver::getPointer()
{
	return this;
}

sf::Event InputObserver::getEvent()
{
	return this->m_event;
}

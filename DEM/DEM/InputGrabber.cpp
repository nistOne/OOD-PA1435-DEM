#include "InputGrabber.h"

void InputGrabber::notifyObservers()
{
	InputObserver* tempObserver;

	for (int i = 0; i < this->m_observers.size(); i++)
	{
		tempObserver = dynamic_cast<InputObserver*>(this->m_observers.at(i)->getPointer());
		tempObserver->update(this->m_event);
	}
}

void InputGrabber::setEvent(sf::Event event)
{
	this->m_event = event;
	this->notifyObservers();
}

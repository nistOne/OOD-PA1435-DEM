#include "CoordGrabber.h"

void CoordGrabber::notifyObservers()
{
	CoordObserver* tempObserver;

	for (int i = 0; i < this->m_observers.size(); i++)
	{
		tempObserver = dynamic_cast<CoordObserver*>(this->m_observers.at(i)->getPointer());
		tempObserver->update(ID, m_pos, m_icon);
	}
}

void CoordGrabber::setCoord(int ID, sf::Vector2i pos, char icon)
{
	this->ID = ID;
	this->m_pos = pos;
	this->m_icon = icon;
	this->notifyObservers();
}

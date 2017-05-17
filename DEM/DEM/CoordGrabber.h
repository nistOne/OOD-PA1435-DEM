#pragma once
#include "Subject.h"
#include "CoordObserver.h"

class CoordGrabber : public Subject
{
private:

	int ID;
	sf::Vector2i m_pos;
	char m_icon;

public:

	CoordGrabber() {}
	~CoordGrabber() {}

	virtual void notifyObservers();

	void setCoord(int ID, sf::Vector2i pos, char icon);
};
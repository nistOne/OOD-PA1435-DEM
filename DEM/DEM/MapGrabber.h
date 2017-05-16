#pragma once
#include "Subject.h"
#include "MapObserver.h"

// Change to get from a file instead.
#define MAPHEIGHT 60
#define MAPWIDTH 90

class MapGrabber : public Subject
{
private:

	char m_map[MAPWIDTH][MAPHEIGHT];

public:

	MapGrabber();
	~MapGrabber();

	virtual void notifyObservers();

	void setMap(char map[MAPWIDTH][MAPHEIGHT]);
};
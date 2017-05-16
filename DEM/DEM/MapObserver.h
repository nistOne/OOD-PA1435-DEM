#pragma once
#include "Observer.h"
#include "Constants.h"


class MapObserver : public Observer
{
protected:

	char m_map[MAPWIDTH][MAPHEIGHT];

public:

	MapObserver();
	~MapObserver();

	Observer* getPointer();
	void getMap(char map[MAPWIDTH][MAPHEIGHT]);

	void update(char map[MAPWIDTH][MAPHEIGHT]);

};
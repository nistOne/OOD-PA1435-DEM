#include "MapObserver.h"

MapObserver::MapObserver()
{
	
}

MapObserver::~MapObserver()
{
}

Observer* MapObserver::getPointer()
{
	return this;
}

void MapObserver::getMap(char map[MAPWIDTH][MAPHEIGHT])
{
	for (int i = 0; i < MAPWIDTH; i++)
	{
		for (int j = 0; j < MAPHEIGHT; j++)
		{
			map[i][j] = this->m_map[i][j];
		}
	}
}

void MapObserver::update(char map[MAPWIDTH][MAPHEIGHT])
{
	for (int i = 0; i < MAPWIDTH; i++)
	{
		for (int j = 0; j < MAPHEIGHT; j++)
		{
			this->m_map[i][j] = map[i][j];
		}
	}
}

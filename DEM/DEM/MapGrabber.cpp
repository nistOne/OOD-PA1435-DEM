#include "MapGrabber.h"

MapGrabber::MapGrabber()
{
}

MapGrabber::~MapGrabber()
{

}

void MapGrabber::notifyObservers()
{
	MapObserver* tempObserver;

	for (int i = 0; i < this->m_observers.size(); i++)
	{
		tempObserver = dynamic_cast<MapObserver*>(this->m_observers.at(i)->getPointer());
		tempObserver->update(this->m_map);
	}
}

void MapGrabber::setMap(char map[MAPWIDTH][MAPHEIGHT])
{
	for (int i = 0; i < MAPWIDTH; i++)
	{
		for (int j = 0; j < MAPHEIGHT; j++)
		{
			this->m_map[i][j] = map[i][j];
		}
	}

	this->notifyObservers();
}

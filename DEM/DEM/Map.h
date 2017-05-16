#ifndef MAP_H
#define MAP_H
#include "MapGrabber.h"
#include "Constants.h"

class Map
{
private:
	char m_map[MAPWIDTH][MAPHEIGHT];
	MapGrabber * m_mapGrabber;

public:
	Map();
	~Map();

	void GenerateMap();
	void Print();

	void registerObserver(Observer * observer);
	void getMap(char map[MAPWIDTH][MAPHEIGHT]);
};

#endif // !MAP_HB
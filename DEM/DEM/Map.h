#ifndef MAP_H
#define MAP_H
#include "MapGrabber.h"
#include "Constants.h"
#include "SFML-2.4.2/include/SFML/Graphics.hpp"

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
	sf::Vector2i getSpawn();
	void getMap(char map[MAPWIDTH][MAPHEIGHT]);
};

#endif // !MAP_HB
#ifndef MAP_H
#define MAP_H

#define MAPHEIGHT 60
#define MAPWIDTH 90

class Map
{
private:
	char m_map[MAPWIDTH][MAPHEIGHT];

public:
	Map();
	~Map();

	bool GenerateMap();
};

#endif // !MAP_HB
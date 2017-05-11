#include "Map.h"
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace ::std;

Map::Map()
{
}


Map::~Map()
{
}

bool Map::GenerateMap()
{
	srand(time(NULL));
	int nr_of_rooms_TOP = (rand() % 10144 + 3) % MAPWIDTH / 10;
	int nr_of_rooms_BOT = (rand() % 10144 + 3) % MAPWIDTH / 10;



	return true;
}

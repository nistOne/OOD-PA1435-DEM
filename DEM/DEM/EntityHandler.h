#ifndef ENTITYHANDLER_H
#define ENTITYHANDLER_H

#include <string>

#include "Player.h"
#include "NPC.h"
#include "Map.h"
#include "Constants.h"
#include "MapObserver.h"

class EntityHandler
{
private:
	Entity** entitys;
	int nrOfEntitys;
	std::string response;
	MapObserver* m_mapObserver;
	char m_map[MAPWIDTH][MAPHEIGHT];

public:
	EntityHandler();
	~EntityHandler();
	void attack(Entity* attacker, Entity* target);
	void addPlayer(std::string name);
	
	bool update();
	bool checkUnitCollision();
	bool checkWallCollision(sf::Vector2i dir);
	int calcDamage(int strenght);
	std::string getResponse(Player& player)const;

	Observer* getObserver();
};

#endif // !ENTITYHANDLER_H
#ifndef ENTITYHANDLER_H
#define ENTITYHANDLER_H

#include <string>

#include "Player.h"
#include "NPC.h"
#include "Map.h"

class EntityHandler
{
private:
	Entity** entitys;
	int nrOfEntitys;
	Map m_map;
public:
	EntityHandler(std::string name);
	~EntityHandler();
	bool update();
	bool checkUnitCollision();
	bool checkWallCollision(sf::Vector2i dir);
	float calcDamage(Player& player, NPC& npc);
	std::string getResponse(Player& player)const;
};

#endif // !ENTITYHANDLER_H
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

	MapObserver* m_mapObserver;
	char m_map[MAPWIDTH][MAPHEIGHT];

	bool wantToMove();

public:
	EntityHandler();
	~EntityHandler();

	void initialize(Observer* dialogueObserver);

	void addPlayer(std::string name);

	bool update(); // Need to call Player::update().
	bool checkUnitCollision();
	bool checkWallCollision();
	float calcDamage(Player& player, NPC& npc);
	std::string getResponse(Player& player)const;

	Observer* getMapObserver();
	Observer* getPlayerObserver();
};

#endif // !ENTITYHANDLER_H
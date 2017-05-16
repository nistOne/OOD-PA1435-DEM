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

	bool wantToMove(int entityIndex);						// checks if the player pos = it's targeted pos
	int getPlayerIndex();									// gets the index of the player in Entity**
	void getEntityOnPos(sf::Vector2i pos, Entity* entity);	// checks if any entity is on target position
	bool checkWallCollision();

public:
	EntityHandler();
	~EntityHandler();

	void addPlayer(std::string name);

	bool update();
	
	
	float calcDamage(Player& player, NPC& npc);
	std::string getResponse(Player& player)const;

	Observer* getObserver();
};

#endif // !ENTITYHANDLER_H
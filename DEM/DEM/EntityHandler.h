#ifndef ENTITYHANDLER_H
#define ENTITYHANDLER_H

#include <string>

#include "Player.h"
#include "NPC.h"
#include "Map.h"
#include "Constants.h"
#include "MapObserver.h"
#include "DialogueGrabber.h"

class EntityHandler
{
private:
	Entity** entitys;
	int nrOfEntitys;
	int ID_counter;

	MapObserver* m_mapObserver;
	DialogueGrabber* m_dialogueGrabber;

	char m_map[MAPWIDTH][MAPHEIGHT];

	bool wantToMove(int entityIndex);						// checks if the player pos = it's targeted pos
	int getPlayerIndex();									// gets the index of the player in Entity**
	Entity* getEntityOnPos(sf::Vector2i pos);				// checks if any entity is on target position
	bool checkWallCollision();

public:
	EntityHandler();
	~EntityHandler();
	void attack(Entity* attacker, Entity* target);

	void addPlayer(std::string name, sf::Vector2i spawnPos);
	void addNPC(std::string name, sf::Vector2i spawnPos);
	
	bool update();
	int calcDamage(int strenght);

	Observer* getMapObserver();
	Observer* getInputObserver();
	void registerDialogueObserver(Observer* dialogueObserver);
	void registerCoordObserver(Observer* coordObserver);

	void updateEntities()
	{
		for(int i = 0; i < this->nrOfEntitys; i++)
			this->entitys[i]->move();
	}
};

#endif // !ENTITYHANDLER_H
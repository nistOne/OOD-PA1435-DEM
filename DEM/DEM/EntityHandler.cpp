#include "EntityHandler.h"

bool EntityHandler::wantToMove()
{
	return false;
}

EntityHandler::EntityHandler()
{
	entitys = new Entity*[10];

	this->m_mapObserver = new MapObserver();
}
EntityHandler::~EntityHandler() {
	for (int i = 0; i < nrOfEntitys; i++)
		delete entitys[i];
	delete[] entitys;

	delete this->m_mapObserver;
}

void EntityHandler::addPlayer(std::string name)
{
	// Fix cap to avoid accessing undefined memory!
	this->entitys[nrOfEntitys++] = new Player(45.0, 45.0, 100, 25, name);
}

bool EntityHandler::checkUnitCollision()
{
	for (int i = 1; i < nrOfEntitys; i++)
	{
		if (entitys[0]->getTargetPos().x == entitys[i]->getTargetPos().x && entitys[0]->getPos().y == entitys[0]->getPos().y)
		{
			return true;
		}
	}
	return false;
}
bool EntityHandler::checkWallCollision()
{
	char map[MAPWIDTH][MAPHEIGHT];
	m_mapObserver->getMap(map);

	if (map[entitys[0]->getTargetPos().x][entitys[0]->getTargetPos().y] == 35 || 
		map[entitys[0]->getTargetPos().x][entitys[0]->getTargetPos().y] == 46)	// if target tile is floor
		return true;

	return false;
}
bool EntityHandler::update()
{
	// Update map.
	this->m_mapObserver->getMap(this->m_map);
	
	return true;
}
float EntityHandler::calcDamage(Player& player, NPC& npc)
{
	player.takeDamage(npc.getStrength());

	// EDIT
	return -1;
}
std::string EntityHandler::getResponse(Player& player)const
{
	std::string response = "The monster hits the player for " + player.getLastDamageTaken();

	// EDIT
	return response;
}

Observer * EntityHandler::getObserver()
{
	return this->m_mapObserver;
}

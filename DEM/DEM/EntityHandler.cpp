#include "EntityHandler.h"

bool EntityHandler::wantToMove(int entityIndex)
{
	if (this->entitys[entityIndex]->getPos() != this->entitys[entityIndex]->getTargetPos())
		return true;

	return false;
}

int EntityHandler::getPlayerIndex()
{
	for (int i = 0; i < this->nrOfEntitys; i++)
	{
		if (entitys[i] == dynamic_cast<Player*>(entitys[i]))
		{
			return i;
		}
	}
	/// error ? ? ? 
}

void EntityHandler::getEntityOnPos(sf::Vector2i pos, Entity* entity)
{
	for (int i = 0; i < nrOfEntitys && entity == nullptr; i++)
	{
		if (entitys[i]->getPos() == pos)
			entity = entitys[i];
	}
}

bool EntityHandler::checkWallCollision()
{
	char map[MAPWIDTH][MAPHEIGHT];
	m_mapObserver->getMap(map);
	int playerIndex = getPlayerIndex();

	if (map[entitys[playerIndex]->getTargetPos().x][entitys[playerIndex]->getTargetPos().y] == 35 ||
		map[entitys[playerIndex]->getTargetPos().x][entitys[playerIndex]->getTargetPos().y] == 46)	// if target tile is floor
		return true;

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

void EntityHandler::initialize(Observer * dialogueObserver)
{
	// EDIT!
	Player* temp = dynamic_cast<Player*>(this->entitys[0]);

	temp->registerDialogueObserver(dialogueObserver);
}

void EntityHandler::addPlayer(std::string name)
{
	// Fix cap to avoid accessing undefined memory!
	this->entitys[nrOfEntitys++] = new Player(45.0, 45.0, 100, 25, name);
}

bool EntityHandler::update()
{
	Entity* temp = nullptr;
	if (wantToMove(getPlayerIndex()))
	{
		if (checkWallCollision())
		{
			getEntityOnPos(entitys[getPlayerIndex()]->getTargetPos(), temp);
			if (temp == nullptr)
			{
				entitys[getPlayerIndex()]->move();
				entitys[getPlayerIndex()]->setTargetPos(entitys[getPlayerIndex()]->getTargetPos());
			}
			else
			{
				// fight?
			}
		}
	}

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

Observer* EntityHandler::getMapObserver()
{
	return this->m_mapObserver;
}

Observer * EntityHandler::getPlayerObserver()
{
	// EDIT!
	Player* temp = dynamic_cast<Player*>(this->entitys[0]);

	return temp->getInputObserver();
}

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

#include <time.h>
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
int EntityHandler::calcDamage(int strenght)
{
	int actualDamage = 0;
	srand(time(NULL));
	int random = rand() % 7;
	if (random == 5)
	{
		actualDamage = strenght * 2;
	}
	else if (random == 3 || random == 6)
	{
		actualDamage = 0;
	}
	else
	{
		actualDamage = strenght * 1;
	}
	return actualDamage;
}
std::string EntityHandler::getResponse(Player& player)const
{
	return response;
}

Observer* EntityHandler::getMapObserver()
{
	return this->m_mapObserver;
}
void EntityHandler::attack(Entity* attacker, Entity* target)
{
	int actualDamage = calcDamage(attacker->getStrength());
	target->takeDamage(actualDamage);
	response = attacker->getName() + " Attacks " + target->getName() + " for" + std::to_string(actualDamage) + " Damage";
}

Observer * EntityHandler::getPlayerObserver()
{
	// EDIT!
	Player* temp = dynamic_cast<Player*>(this->entitys[0]);

	return temp->getInputObserver();
}

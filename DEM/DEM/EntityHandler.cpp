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
	return -1;
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
	{
		return false;
	}

	return true;
}

#include <time.h>
EntityHandler::EntityHandler()
{
	entitys = new Entity*[10];
	this->nrOfEntitys = 0;
	this->ID_counter = 0;

	this->m_mapObserver = new MapObserver();
	this->m_dialogueGrabber = new DialogueGrabber();
}

EntityHandler::~EntityHandler() {
	for (int i = 0; i < nrOfEntitys; i++)
		delete entitys[i];
	delete[] entitys;

	delete this->m_mapObserver;
	delete this->m_dialogueGrabber;
}

void EntityHandler::addPlayer(std::string name, sf::Vector2i spawnPos)
{
	// Fix cap to avoid accessing undefined memory!
	this->entitys[this->nrOfEntitys++] = new Player(spawnPos.x, spawnPos.y, 100, 25, name, this->ID_counter++);
	this->entitys[this->nrOfEntitys - 1]->move();
}

bool EntityHandler::update()
{
	int playerIndex = this->getPlayerIndex();
	Player* pPlayer = dynamic_cast<Player*>(this->entitys[playerIndex]);

	pPlayer->update();

	Entity* temp = nullptr;

	// Update map.
	this->m_mapObserver->getMap(this->m_map);

	if (wantToMove(getPlayerIndex()))
	{
		if (!checkWallCollision())
		{
			getEntityOnPos(entitys[getPlayerIndex()]->getTargetPos(), temp);
			if (temp == nullptr)
			{
				entitys[getPlayerIndex()]->move();
				//entitys[getPlayerIndex()]->setTargetPos(entitys[getPlayerIndex()]->getTargetPos());
			}
			else
			{
				// fight?
			}
		}
	}
	
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

Observer* EntityHandler::getMapObserver()
{
	return this->m_mapObserver;
}
void EntityHandler::attack(Entity* attacker, Entity* target)
{
	int actualDamage = calcDamage(attacker->getStrength());
	target->takeDamage(actualDamage);

	string dialogue = attacker->getName() + " Attacks " + target->getName() + " for" + std::to_string(actualDamage) + " Damage";
	this->m_dialogueGrabber->addDialogue("FIGHT", dialogue);
}

Observer * EntityHandler::getInputObserver()
{
	int playerIndex = this->getPlayerIndex();
	Player* temp = dynamic_cast<Player*>(this->entitys[playerIndex]);

	return temp->getInputObserver();
}

void EntityHandler::registerDialogueObserver(Observer * dialogueObserver)
{
	this->m_dialogueGrabber->registerInputObserver(dialogueObserver);
}

void EntityHandler::registerCoordObserver(Observer * coordObserver)
{
	for (int i = 0; i < this->nrOfEntitys; i++)
	{
		this->entitys[i]->registerCoordObserver(coordObserver);
	}
}

#include "EntityHandler.h"
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

void EntityHandler::addPlayer(std::string name)
{
	// Fix cap to avoid accessing undefined memory!
	this->entitys[nrOfEntitys++] = new Player(45.0, 45.0, 100, 25, name);
}

bool EntityHandler::checkUnitCollision()
{
	for (int i = 1; i < nrOfEntitys; i++)
	{
		if (entitys[0]->getPos().x == entitys[i]->getPos().x && entitys[0]->getPos().y == entitys[0]->getPos().y)
		{
			return true;
		}
	}
	return false;
}
bool EntityHandler::checkWallCollision(sf::Vector2i dir)
{
	//Directions a;

	//if (dir.x == 0 && dir.y == 1)		// the direction is up
	//	a = UP;

	//else if (dir.x == 1 && dir.y == 0)	// the direction is right
	//	a = RIGHT;

	//else if (dir.x == 0 && dir.y == -1)	// the direction is down
	//	a = DOWN;

	//else if (dir.x == -1 && dir.y == 0)	// the direction is left
	//	a = LEFT;

	//switch (a) {
	//case UP:
	//	if (m_map[entitys[0]->getPos().x][entitys[0]->getPos().y + 1])
	//	{

	//	}
	//case RIGHT:

	//case DOWN:

	//case LEFT:

	//default:
	//	break;
	//}
	return false;
}
bool EntityHandler::update()
{
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

Observer * EntityHandler::getObserver()
{
	return this->m_mapObserver;
}
void EntityHandler::attack(Entity* attacker, Entity* target)
{
	int actualDamage = calcDamage(attacker->getStrength());
	target->takeDamage(actualDamage);
	response = attacker->getName() + " Attacks " + target->getName() + " for" + std::to_string(actualDamage) + " Damage";
}

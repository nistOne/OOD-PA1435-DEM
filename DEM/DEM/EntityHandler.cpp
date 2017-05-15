#include "EntityHandler.h"

EntityHandler::EntityHandler(std::string name)
{
	entitys = new Entity*[10];
	this->entitys[0] = new Player(45.0, 45.0, 100, 25, name);
	this->nrOfEntitys = 1;
}
EntityHandler::~EntityHandler()
{

}
bool EntityHandler::checkCollision(float x, float y)
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
bool EntityHandler::update()
{

	// EDIT
	return false;
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
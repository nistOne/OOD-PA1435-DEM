#include "Entity.h"

Entity::Entity()
{
	hitPoint = 0;
	strenght = 0;
	name = "Unkown";
	pos.x = 0;
	pos.y = 0;
}

Entity::Entity(int x, int y, int hitPoint, int strenght, std::string name)
{
	this->hitPoint = hitPoint;
	this->strenght = strenght;
	this->name = name;
	pos.x = x;
	pos.y = y;
	targetPos.x = x;
	targetPos.y = y;
}

Entity::~Entity()
{

}

float Entity::getStrength()const
{
	return this->strenght;
}
float Entity::getHitPoint()const
{
	return this->hitPoint;
}
std::string Entity::getName()const
{
	return this->name;
}
bool Entity::update()
{
	// EDIT

	return false;
}

sf::Vector2i Entity::getPos()const
{
	return this->pos;
}

sf::Vector2i Entity::getTargetPos() const
{
	return this->targetPos;
}

void Entity::setTargetPos(sf::Vector2i pos)
{
	this->targetPos = pos;
}

void Entity::takeDamage(int damage)
{
	this->hitPoint -= damage;
}
#include "Entity.h"

Entity::Entity()
{
	hitPoint = 0;
	strenght = 0;
	name = "Unkown";
	pos.x = 0.0;
	pos.y = 0.0;
}
Entity::Entity(float x, float y, int hitPoint, int strenght, std::string name)
{
	this->hitPoint = hitPoint;
	this->strenght = strenght;
	this->name = name;
	pos.x = x;
	pos.y = y;
	this->lastDamageTaken = 0;
}
Entity::~Entity()
{

}
float Entity::getStrength()const
{
	return this->strenght;
}
bool Entity::update()
{

}
sf::Vector2f Entity::getPos()const
{
	return this->pos;
}
void Entity::takeDamage(int damage)
{
	this->hitPoint -= damage;
	this->lastDamageTaken = damage;
}
int Entity::getLastDamageTaken()const
{
	return this->lastDamageTaken;
}
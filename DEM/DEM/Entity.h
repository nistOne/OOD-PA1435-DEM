#pragma once
#include "SFML-2.4.2/include/SFML/Graphics.hpp"
#include <string>

class Entity
{
protected:
	float hitPoint;
	float strenght;
	int lastDamageTaken;
	std::string name;
	sf::Vector2i pos;
	sf::Vector2i targetPos;
public:
	Entity();
	Entity(int x, int y, int hitPoint, int strenght, std::string name);
	virtual ~Entity();
	sf::Vector2i getPos()const;
	sf::Vector2i getTargetPos()const;
	void setTargetPos(sf::Vector2i pos);
	float getStrength()const;
	bool update();
	void takeDamage(int damage);
	int getLastDamageTaken()const;
	virtual void move() = 0;
};
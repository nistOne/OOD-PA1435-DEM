#pragma once
#include "SFML-2.4.2/include/SFML/Graphics.hpp"
#include <string>

enum Directions { UP, RIGHT, DOWN, LEFT };

class Entity
{
protected:
	float hitPoint;
	float strenght;
	int lastDamageTaken;
	std::string name;
	sf::Sprite sprite;
	sf::Vector2i pos;
	sf::Vector2i targetPos;
public:
	Entity();
	Entity(int x, int y, int hitPoint, int strenght, std::string name);
	virtual ~Entity();
	sf::Vector2i getPos()const;
	sf::Vector2i getTargetPos()const;
	float getStrength()const;
	bool update();
	void takeDamage(int damage);
	int getLastDamageTaken()const;
	virtual void move(sf::Vector2i dir) = 0;
};
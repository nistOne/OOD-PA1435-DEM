#pragma once
#include "SFML-2.4.2/include/SFML/Graphics.hpp"
#include <string>

enum Directions { UP, RIGHT, DOWN, LEFT };

class Entity
{
protected:
	int hitPoint;
	int strenght;
	int lastDamageTaken;
	std::string name;
	sf::Sprite sprite;
	sf::Vector2i pos;
public:
	Entity();
	Entity(int x, int y, int hitPoint, int strenght, std::string name);
	virtual ~Entity();
	sf::Vector2i getPos()const;
	float getStrength()const;
	bool update();
	void takeDamage(int damage);
	int getLastDamageTaken()const;
	float getHitPoint()const;
	std::string getName()const;
	virtual void move(sf::Vector2i dir) = 0;
};
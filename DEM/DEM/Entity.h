#pragma once
#include "SFML-2.4.2/include/SFML/Graphics.hpp"
#include "CoordGrabber.h"
#include <string>

class Entity
{
protected:
	CoordGrabber* m_coordGrabber;

	int ID;
	char icon;
	int hitPoint;
	int strenght;
	std::string name;
	sf::Vector2i pos;
	sf::Vector2i targetPos;

public:
	Entity();
	Entity(int x, int y, int hitPoint, int strenght, std::string name, int ID);
	virtual ~Entity();
	sf::Vector2i getPos()const;
	sf::Vector2i getTargetPos()const;
	void setTargetPos(sf::Vector2i pos);
	float getStrength()const;
	void takeDamage(int damage);
	float getHitPoint()const;
	std::string getName()const;
	void move();

	void registerCoordObserver(Observer* coordObserver);
};
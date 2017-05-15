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
	sf::Sprite sprite;
	sf::Vector2f pos;
public:
	Entity();
	Entity(float x, float y, int hitPoint, int strenght, std::string name);
	virtual ~Entity();
	sf::Vector2f getPos()const;
	float getStrength()const;
	bool update();
	void takeDamage(int damage);
	int getLastDamageTaken()const;
	virtual void move(float x, float y) = 0;
};
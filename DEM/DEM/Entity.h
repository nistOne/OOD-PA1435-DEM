#pragma once
#include <SFML/Graphics.hpp>
#include <string>
class Entity
{
private:
	float hitPoint;
	float strenght;
	std::string name;
	sf::Sprite sprite;
	sf::Vector2f pos;
public:
	Entity();
	~Entity();
	sf::Vector2f getPos();
	float getStrength();
	bool update();
	virtual void move()const = 0;
};
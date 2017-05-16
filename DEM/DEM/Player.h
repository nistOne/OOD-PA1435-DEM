#pragma once
#include "Entity.h"
class Player : public Entity
{
private:

public:
	Player(int x, int y, int hitPoint, int strenght, std::string name);
	~Player();
	void move(sf::Vector2i dir);
};

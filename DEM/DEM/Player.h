#pragma once
#include "Entity.h"
class Player : public Entity
{
private:

public:
	Player(float x, float y, int hitPoint, int strenght, std::string name);
	~Player();
	void move(float x, float y);
};

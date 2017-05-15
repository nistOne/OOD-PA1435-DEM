#pragma once
#include "Player.h"
#include "NPC.h"
#include <string>
class EntityHandler
{
private:
	Entity** entitys;
	int nrOfEntitys;
public:
	EntityHandler(std::string name);
	~EntityHandler();
	bool update();
	bool checkCollision(float x, float y);
	float calcDamage(Player& player, NPC& npc);
	std::string getResponse(Player& player)const;
};

#pragma once
#include "Entity.h"
#include <string>
class NPC : public Entity
{
private:

public:
	NPC(float x, float y, int hitPoint, int strenght, std::string name);
	~NPC();
};

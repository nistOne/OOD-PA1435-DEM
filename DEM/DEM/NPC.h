#pragma once
#include "Entity.h"
#include <string>
class NPC : public Entity
{
private:

public:
	NPC(float x, float y, int hitPoint, int strenght, std::string name);
	~NPC();
	void move(float x, float y);
	std::string returnLine();
	//response getResponse(action);
};

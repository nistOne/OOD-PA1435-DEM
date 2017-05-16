#include "NPC.h"
NPC::NPC(float x, float y, int hitPoint, int strenght, std::string name) : Entity(x, y, hitPoint, strenght, name)
{

}
NPC::~NPC()
{

}
void NPC::move(float x, float y)
{
	this->pos.x += x;
	this->pos.y += y;
}
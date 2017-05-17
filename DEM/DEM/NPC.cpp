#include "NPC.h"
NPC::NPC(float x, float y, int hitPoint, int strenght, std::string name, int ID) : Entity(x, y, hitPoint, strenght, name, ID)
{
	this->icon = 'N';
}
NPC::~NPC()
{

}
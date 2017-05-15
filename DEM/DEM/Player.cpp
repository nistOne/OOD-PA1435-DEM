#include "Player.h"

Player::Player(float x, float y, int hitPoint, int strenght, std::string name) : Entity(x, y, hitPoint, strenght, name)
{
	
}
Player::~Player()
{

}
void Player::move(float x, float y)
{
	this->pos.x += x;
	this->pos.y += y;
	this->sprite.move(x, y);
}
#include "Player.h"

Player::Player(int x, int y, int hitPoint, int strenght, std::string name) : Entity(x, y, hitPoint, strenght, name)
{
	
}
Player::~Player()
{

}
void Player::move(sf::Vector2i dir)
{
	this->pos = this->targetPos;
}
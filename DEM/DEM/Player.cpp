#include "Player.h"

#include <iostream>

Player::Player(int x, int y, int hitPoint, int strenght, std::string name, int ID) : Entity(x, y, hitPoint, strenght, name, ID)
{
	this->m_inputObserver = new InputObserver;
	this->icon = '@';
}
Player::~Player()
{
	delete this->m_inputObserver;
}

void Player::update()
{
	if (this->m_inputObserver->isUpdated())
	{
		sf::Event event = this->m_inputObserver->getEvent();
		
		if (event.type == sf::Event::KeyPressed)
		{
			switch (event.key.code)
			{
			case sf::Keyboard::Up:
				this->targetPos = this->pos;
				this->targetPos.y--;
				std::cout << "UP" << std::endl;
				break;
			case sf::Keyboard::Down:
				this->targetPos = this->pos;
				this->targetPos.y++;
				std::cout << "DOWN" << std::endl;
				break;
			case sf::Keyboard::Left:
				this->targetPos = this->pos;
				this->targetPos.x--;
				std::cout << "LEFT" << std::endl;
				break;
			case sf::Keyboard::Right:
				this->targetPos = this->pos;
				this->targetPos.x++;
				std::cout << "RIGHT" << std::endl;
				break;
			}
		}
	}
}

Observer * Player::getInputObserver()
{
	return this->m_inputObserver;
}



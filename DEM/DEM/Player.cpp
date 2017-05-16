#include "Player.h"

Player::Player(int x, int y, int hitPoint, int strenght, std::string name) : Entity(x, y, hitPoint, strenght, name)
{
	this->m_inputObserver = new InputObserver;
}
Player::~Player()
{
	delete this->m_inputObserver;
}
void Player::move(sf::Vector2i dir)
{
	this->pos = this->targetPos;
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
				break;
			case sf::Keyboard::Down:
				this->targetPos = this->pos;
				this->targetPos.y++;
				break;
			case sf::Keyboard::Left:
				this->targetPos = this->pos;
				this->targetPos.x--;
				break;
			case sf::Keyboard::Right:
				this->targetPos = this->pos;
				this->targetPos.x++;
				break;
			}
		}
	}
}

Observer * Player::getObserver()
{
	return this->m_inputObserver;
}



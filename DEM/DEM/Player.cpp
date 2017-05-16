#include "Player.h"

Player::Player(int x, int y, int hitPoint, int strenght, std::string name) : Entity(x, y, hitPoint, strenght, name)
{
	this->m_dialogueGrabber = new DialogueGrabber;
	this->m_inputObserver = new InputObserver;
}
Player::~Player()
{
	delete this->m_dialogueGrabber;
	delete this->m_inputObserver;
}
void Player::move()
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

Observer * Player::getInputObserver()
{
	return this->m_inputObserver;
}

void Player::registerDialogueObserver(Observer * observer)
{
	this->m_dialogueGrabber->registerObserver(observer);
}



#pragma once
#include "Entity.h"
#include "InputObserver.h"

class Player : public Entity
{
private:

	InputObserver* m_inputObserver;

public:

	Player(int x, int y, int hitPoint, int strenght, std::string name);
	~Player();
	void move(sf::Vector2i dir);

	void update();

	Observer* getInputObserver();
	void setDialogueObserver(Observer* observer);
};

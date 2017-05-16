#pragma once
#include "Entity.h"
#include "InputObserver.h"
#include "DialogueGrabber.h"

class Player : public Entity
{
private:

	DialogueGrabber* m_dialogueGrabber;
	InputObserver* m_inputObserver;

public:

	Player(int x, int y, int hitPoint, int strenght, std::string name);
	~Player();
	void move(sf::Vector2i dir);

	void update();

	Observer* getInputObserver();
	void registerDialogueObserver(Observer* observer);
};

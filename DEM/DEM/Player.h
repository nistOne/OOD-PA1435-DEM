#pragma once
#include "Entity.h"
#include "InputObserver.h"
#include "DialogueGrabber.h"

class Player : public Entity
{
private:

	InputObserver* m_inputObserver;

public:

	Player(int x, int y, int hitPoint, int strenght, std::string name);
	~Player();
	void move();

	void update();

	Observer* getInputObserver();
};
//Fight, eh, dialogsaken funka, text window, logen fightfunktion som tar in npc ovh player, playern kommer st� var
// g�ras: en klass som attakerar, den andra tar skada, generera en str�ng d�r det st�r vad som h�nder. kunna h�mta attakdamage. om den d�r s� d�r den
// skapa vector som  vector<Entity*> entities;
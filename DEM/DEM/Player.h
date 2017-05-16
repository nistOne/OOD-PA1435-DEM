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
//Fight, eh, dialogsaken funka, text window, logen fightfunktion som tar in npc ovh player, playern kommer stå var
// göras: en klass som attakerar, den andra tar skada, generera en sträng där det står vad som händer. kunna hämta attakdamage. om den dör så dör den
// skapa vector som  vector<Entity*> entities;
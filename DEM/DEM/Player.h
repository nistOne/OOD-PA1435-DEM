#pragma once
#include "Entity.h"
class Player : public Entity
{
private:

public:
	Player(int x, int y, int hitPoint, int strenght, std::string name);
	~Player();
	void move(sf::Vector2i dir);
	
};
//Fight, eh, dialogsaken funka, text window, logen fightfunktion som tar in npc ovh player, playern kommer st� var
// g�ras: en klass som attakerar, den andra tar skada, generera en str�ng d�r det st�r vad som h�nder. kunna h�mta attakdamage. om den d�r s� d�r den
// skapa vector som  vector<Entity*> entities;
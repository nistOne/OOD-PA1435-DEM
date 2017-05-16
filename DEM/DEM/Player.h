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
//Fight, eh, dialogsaken funka, text window, logen fightfunktion som tar in npc ovh player, playern kommer stå var
// göras: en klass som attakerar, den andra tar skada, generera en sträng där det står vad som händer. kunna hämta attakdamage. om den dör så dör den
// skapa vector som  vector<Entity*> entities;
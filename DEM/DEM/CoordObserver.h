#pragma once
#include "Observer.h"
#include "SFML-2.4.2/include/SFML/Graphics.hpp"
#include <vector>

using namespace std;

struct Coord
{
	int ID;
	sf::Vector2i pos;
	char icon;
};

class CoordObserver : public Observer
{
private:

	vector<Coord> m_coords;

public:

	CoordObserver() {}
	~CoordObserver() {}

	void update(int ID, sf::Vector2i pos, char icon);

	virtual Observer* getPointer();

	int getSize();
	int getIndex(sf::Vector2i pos);
	char getIcon(int index);

};

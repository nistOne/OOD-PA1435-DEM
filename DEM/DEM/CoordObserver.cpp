#include "CoordObserver.h"

void CoordObserver::update(int ID, sf::Vector2i pos, char icon)
{
	Coord tempCoord = { ID, pos, icon };
	int index = -1;

	// Find element and update pos.
	for (int i = 0; i < this->m_coords.size() && index == -1; i++)
	{
		if (this->m_coords.at(i).ID == ID)
		{
			this->m_coords.at(i).pos = pos;
		}
	}

	// If element not found.
	if (index == -1)
	{
		this->m_coords.push_back(tempCoord);
	}

	this->setUpdated();
}

Observer * CoordObserver::getPointer()
{
	return this;
}

int CoordObserver::getSize()
{
	return this->m_coords.size();
}

int CoordObserver::getIndex(sf::Vector2i pos)
{
	int index = -1;

	int size = this->m_coords.size();

	for (int i = 0; i < size && index == -1; i++)
	{
		if (this->m_coords.at(i).pos == pos)
		{
			index = i;
		}
	}

	return index;
}

char CoordObserver::getIcon(int index)
{
	return this->m_coords.at(index).icon;
}

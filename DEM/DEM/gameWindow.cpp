#include "GameWindow.h"

GameWindow::GameWindow() : Window()
{
	this->m_text.setPosition(80, 0);

	this->m_mapObserver = new MapObserver();
	this->m_coordObserver = new CoordObserver();
}

GameWindow::~GameWindow()
{
	delete this->m_mapObserver;
	delete this->m_coordObserver;
}

Observer * GameWindow::getMapObserver()
{
	return this->m_mapObserver;
}

Observer * GameWindow::getCoordObserver()
{
	return this->m_coordObserver;
}

void GameWindow::Render(sf::RenderWindow* window)
{
	string mapString = "";
	int entityIndex;


	window->draw(this->m_box);

	// -- Get map --
	this->m_mapObserver->getMap(this->m_map);


	for (int i = 0; i < MAPHEIGHT; i++)
	{
		for (int j = 0; j < MAPWIDTH; j++)
		{
			entityIndex = this->m_coordObserver->getIndex(sf::Vector2i(i, j));
			if (entityIndex = !- 1)
				mapString += this->m_coordObserver->getIcon(entityIndex);
			else
				mapString += this->m_map[j][i];
		}
		mapString += "\n";
	}


	this->m_text.setString(mapString);
	window->draw(this->m_text);
}

//sf::Text text_map;
//text_map.setFont(font);
//text_map.setString(map);
//text_map.setCharacterSize(15);
//text_map.setFillColor(sf::Color::White);
//text_map.setPosition(40, 50);

//string map = "";
//map += "##########################################################################################\n";
//map += "##########################################################################################\n";
//map += "##########################################################################################\n";
//map += "##########################################################################################\n";
//map += "##########################################################################################\n";
//map += "##########################################################################################\n";
//map += "##########################################################################################\n";
//map += "##########################################################################################\n";
//map += "##########################################################################################\n";
//map += "##########################################################################################\n";
//map += "##########################################################################################\n";
//map += "##########################################################################################\n";
//map += "##########################################################################################\n";
//map += "##########################################################################################\n";
//map += "##########################################################################################\n";
//map += "##########################################################################################\n";
//map += "##########################################################################################\n";
//map += "##########################################################################################\n";
//map += "##########################################################################################\n";
//map += "##########################################################################################\n";
//map += "##########################################################################################\n";
//map += "##########################################################################################\n";
//map += "##########################################################################################\n";
//map += "##########################################################################################\n";
//map += "##########################################################################################\n";
//map += "##########################################################################################\n";
//map += "##########################################################################################\n";
//map += "##########################################################################################\n";
//map += "##########################################################################################\n";
//map += "##########################################################################################\n";
//map += "##########################################################################################\n";
//map += "##########################################################################################\n";
//map += "##########################################################################################\n";
//map += "##########################################################################################\n";
//map += "##########################################################################################\n";
//map += "##########################################################################################\n";
//map += "##########################################################################################\n";
//map += "##########################################################################################\n";
//map += "##########################################################################################\n";
//map += "##########################################################################################\n";
//map += "##########################################################################################\n";
//map += "##########################################################################################\n";
//map += "##########################################################################################\n";
//map += "##########################################################################################\n";
//map += "##########################################################################################\n";
//map += "##########################################################################################\n";
//map += "##########################################################################################\n";
//map += "##########################################################################################\n";
//map += "##########################################################################################\n";
//map += "##########################################################################################\n";
//map += "##########################################################################################\n";
//map += "##########################################################################################\n";
//map += "##########################################################################################\n";
//map += "##########################################################################################\n";
//map += "##########################################################################################\n";
//map += "##########################################################################################\n";
//map += "##########################################################################################\n";
//map += "##########################################################################################\n";
//map += "##########################################################################################\n";
//map += "##########################################################################################";
#include "SFML-2.4.2/include/SFML/Graphics.hpp"
#include <iostream>

#include "Map.h"

using namespace ::std;

int main()
{
	char m_map[MAPWIDTH][MAPHEIGHT];

	/// generate default terrain
	int j = 0;
	for (int i = 0; i < 90; i++)
	{
		m_map[i][j] = 35;
		if (i >= MAPWIDTH - 1)
		{
			i = 0;
			j++;
			if (j >= MAPHEIGHT - 1)
				i = MAPWIDTH;
		}
	}

	srand(time(NULL));
	int nr_of_rooms = 24 +(rand() % 10144 + 3) % 4;
	//int nr_of_rooms_BOT = 2 +(rand() % 10144 + 3) % (MAPWIDTH / 10);

	int roomWidth = 0;
	int roomHeight = 0;
	//int previousSize = 0;
	int roomcounter = 0;
	int roomStartPosX = 0;
	int roomStartPosY = 0;
	int Yvariable = 0;
	/// room generator
	while (roomcounter != nr_of_rooms)
	{
		roomWidth = rand() % 5 + 8;
		roomHeight = rand() % 3 + 5;
		roomStartPosX = roomStartPosX + rand() % 5 + 2;
		Yvariable = rand() % 3 + 1;
		roomStartPosY = roomStartPosY + Yvariable;

		j = roomStartPosY;
		for (int i = roomStartPosX; i < roomStartPosX + roomWidth; i++)
		{

			if (j == roomStartPosY || j == roomStartPosY + roomHeight - 1)		// top & bot wall
			{
				m_map[i][j] = 45;
			}
			else if (i == roomStartPosX || i == roomStartPosX + roomWidth - 1)	// left & right wall
			{
				m_map[i][j] = 124;
			}
			else																// floor
			{
				m_map[i][j] = 46;
			}

			if (i == roomStartPosX + roomWidth -1)								// next row
			{
				i = roomStartPosX - 1;
				j++;
				if (j == roomStartPosY + roomHeight)							// finnished
				{
					i = roomStartPosX + roomWidth;
				}
			}
		}// for
		roomStartPosY = roomStartPosY - Yvariable;

		// creates new row when at the far right
		roomStartPosX += (roomWidth + 2);
		if ((roomStartPosX + 16 > MAPWIDTH))
		{
			roomStartPosX = 0;
			roomStartPosY += 8 + Yvariable;
		}


		roomcounter++;
		//roomcounter = nr_of_rooms;
	}// room generator





	/// print map
	j = 0;
	for (int i = 0; i < 90; i++)
	{
		cout << m_map[i][j] ;
		if (i >= MAPWIDTH - 1)
		{
			i = 0;
			j++;
			cout << endl;
			if (j >= MAPHEIGHT - 1)
				i = MAPWIDTH;
		}
	}


	//std::cout << " Topnr = " << nr_of_rooms_TOP << std::endl;

	while (1 != 0)
	{
	}




	///*sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");
	//sf::CircleShape shape(100.f);
	//shape.setFillColor(sf::Color::Green);

	//while (window.isOpen())
	//{
	//	sf::Event event;
	//	while (window.pollEvent(event))
	//	{
	//		if (event.type == sf::Event::Closed)
	//			window.close();
	//	}

	//	window.clear();
	//	window.draw(shape);
	//	window.display();*/
	//}

	return 0;
}
#include "Map.h"
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace ::std;

Map::Map()
{
	this->m_mapGrabber = new MapGrabber();
}

Map::~Map()
{
	delete this->m_mapGrabber;
}

void Map::GenerateMap()
{
	/// generate default terrain
	int j = 0;
	for (int i = 0; i < 90; i++)
	{
		this->m_map[i][j] = 32; // 35
		if (i >= MAPWIDTH - 1)
		{
			i = 0;
			j++;
			if (j >= MAPHEIGHT - 1)
				i = MAPWIDTH;
		}// if
	}// for

	 /// room generator
	srand(time(NULL));
	int nr_of_rooms = 8 + (rand() % 10144 + 3) % 4;

	int roomWidth = 0;
	int roomHeight = 0;
	//int previousSize = 0;
	int roomcounter = 0;
	int roomStartPosX = 0;
	int roomStartPosY = 0;
	int Yvariable = 0;

	while (roomcounter != nr_of_rooms)
	{
		roomWidth = rand() % 7 + 8;
		roomHeight = rand() % 4 + 7;
		roomStartPosX = roomStartPosX + rand() % 5 + 2;
		Yvariable = rand() % 9 + 1;
		roomStartPosY = roomStartPosY + Yvariable;

		j = roomStartPosY;
		for (int i = roomStartPosX; i < roomStartPosX + roomWidth; i++)
		{

			if (j == roomStartPosY || j == roomStartPosY + roomHeight - 1)		// top & bot wall
			{
				this->m_map[i][j] = 45;
			}
			else if (i == roomStartPosX || i == roomStartPosX + roomWidth - 1)	// left & right wall
			{
				this->m_map[i][j] = 124;
			}
			else																// floor
			{
				this->m_map[i][j] = 46;
			}

			if (i == roomStartPosX + roomWidth - 1)								// next row
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
		roomStartPosX += (roomWidth + 6);
		if ((roomStartPosX + 16 > MAPWIDTH))
		{
			roomStartPosX = 0;
			roomStartPosY += 12 + Yvariable;
		}
		roomcounter++;
	}// room generator


	 /// create paths 
	int randomVariable = 0;
	sf::Vector2i pathStart = { 0,0 };
	sf::Vector2i pathEnd = { 0,0 };
	bool startFlag = false;			// 
	bool endFlag = false;			// 
	bool finnishedFlag = false;		// 
	for (int i = 0; i < 10; i++)				// generate all paths
	{
		finnishedFlag = false;
		startFlag = false;
		while (!startFlag) // getting startpoint for path
		{
			pathStart.x = rand() % 88 + 1;
			pathStart.y = rand() % 58 + 1;
			if (this->m_map[pathStart.x][pathStart.y] == 45 || this->m_map[pathStart.x][pathStart.y] == 124) // if hits a wall
			{
				if (this->m_map[pathStart.x + 1][pathStart.y] == 45 && this->m_map[pathStart.x - 1][pathStart.y] == 45 || this->m_map[pathStart.x][pathStart.y + 1] == 124 && this->m_map[pathStart.x][pathStart.y - 1] == 124)
				{
					startFlag = true;
				}
			}
		}// while

		endFlag = false;
		while (!endFlag) // getting end point for path
		{
			pathEnd.x = rand() % 88 + 1;
			pathEnd.y = rand() % 58 + 1;
			if (this->m_map[pathEnd.x][pathEnd.y] == 45 || this->m_map[pathEnd.x][pathEnd.y] == 124 || pathEnd.x == pathStart.x && pathEnd.y == pathStart.y) // if hits a wall
			{
				if (pathStart.x != pathEnd.x && pathStart.y != pathEnd.y)
				{
					if (this->m_map[pathStart.x + 1][pathStart.y] == 45 && this->m_map[pathStart.x - 1][pathStart.y] == 45 || this->m_map[pathStart.x][pathStart.y + 1] == 124 && this->m_map[pathStart.x][pathStart.y - 1] == 124)
					{
						endFlag = true;
					}
				}
			}
		}// while

		while (!finnishedFlag) // creating the path
		{
			randomVariable = rand() % 100;
			if (randomVariable > 50)			// randomly goes up/down or right/left
			{
				if (pathStart.x < pathEnd.x)
				{
					if (this->m_map[pathStart.x + 1][pathStart.y] == 45 && this->m_map[pathStart.x - 1][pathStart.y] == 45)
					{
						if (pathStart.y < pathEnd.y)
						{
							pathStart.y++;
						}// if
						else
						{
							pathStart.y--;
						}// else if
					}// if
					else
					{
						pathStart.x++;
					}
				}// if
				else if (pathStart.x > pathEnd.x)
				{
					if (this->m_map[pathStart.x + 1][pathStart.y] == 45 && this->m_map[pathStart.x - 1][pathStart.y] == 45)
					{
						if (pathStart.y < pathEnd.y)
						{
							pathStart.y++;
						}// if
						else
						{
							pathStart.y--;
						}// else if
					}// if
					else
					{
						pathStart.x--;
					}
				}// else if
			} // if
			else
			{
				if (pathStart.y < pathEnd.y)
				{
					if (this->m_map[pathStart.x][pathStart.y + 1] == 124 && this->m_map[pathStart.x][pathStart.y - 1] == 124)
					{
						if (pathStart.x < pathEnd.x)
						{
							pathStart.x++;
						}// if
						else
						{
							pathStart.x--;
						}// else if
					}// if
					else
					{
						pathStart.y++;
					}
				}// if
				else if (pathStart.y > pathEnd.y)
				{
					if (this->m_map[pathStart.x][pathStart.y + 1] == 124 && this->m_map[pathStart.x][pathStart.y - 1] == 124)
					{
						if (pathStart.x < pathEnd.x)
						{
							pathStart.x++;
						}// if
						else
						{
							pathStart.x--;
						}// else if
					}// if
					else
					{
						pathStart.y--;
					}
				}// else if
			} // else

			if (this->m_map[pathStart.x][pathStart.y] == 32) // if the pos is empty...
			{
				this->m_map[pathStart.x][pathStart.y] = 35;
			}// if
			else if (this->m_map[pathStart.x][pathStart.y] == 45 || this->m_map[pathStart.x][pathStart.y] == 124) // if the pos is wall
			{
				this->m_map[pathStart.x][pathStart.y] = 46;
			}// else if

			if (pathEnd.x == pathStart.x && pathEnd.y == pathStart.y) // if path is finnished
			{
				finnishedFlag = true;
			}// if
		} // while
	} //for all paths

	// Notify all observers with an update.
	this->m_mapGrabber->setMap(this->m_map);
}

sf::Vector2i Map::getSpawn()
{
	/*bool flag = false;
	int xPos = 0;
	int yPos = 0;
	while (!flag)
	{
		xPos = (rand() % MAPWIDTH - 10) + 10;
		yPos = (rand() % MAPHEIGHT - 7) + 7;
		if (m_map[xPos][yPos] == 46)
			flag = true;
	}*/

	for (int i = 0; i < MAPWIDTH; i++)
	{
		for (int j = 0; j < MAPHEIGHT; j++)
		{
			if (m_map[i][j] == '.')
				return sf::Vector2i{ i, j };
		}
	}

	//return sf::Vector2i{xPos,yPos};
	return sf::Vector2i{ 0, 0 };
}

void Map::registerObserver(Observer * observer)
{
	this->m_mapGrabber->registerInputObserver(observer);
}

void Map::getMap(char map[MAPWIDTH][MAPHEIGHT])
{
	for (int i = 0; i < MAPWIDTH; i++)
	{
		for (int j = 0; j < MAPHEIGHT; j++)
		{
			map[i][j] = this->m_map[i][j];
		}
	}
}

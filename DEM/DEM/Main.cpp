#include "SFML-2.4.2/include/SFML/Graphics.hpp"
#include <iostream>
#include <string>

#include "Map.h"

#include "Graphics.h"

using namespace std;

int main()
{
	Map map;
	map.GenerateMap();
	map.Print();

	Graphics graphics;
	std::cout << "Master branch!" << std::endl;

	while (true)
	{
		graphics.Render();
	}

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
	//	window.display();
	//}

	return 0;
}
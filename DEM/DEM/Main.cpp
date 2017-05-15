#include "SFML-2.4.2/include/SFML/Graphics.hpp"
#include <iostream>

#include "Map.h"

int main()
{
	Map map;
	map.GenerateMap();
	map.Print();
	sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}

	return 0;
}
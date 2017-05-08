#include "SFML-2.4.2/include/SFML/Graphics.hpp"
#include <iostream>

int main()
{
	std::cout << "HEY EMMA!! :D NICE TO MEED YOU!" << std::endl;

	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
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
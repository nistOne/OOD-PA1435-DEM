#include "SFML-2.4.2/include/SFML/Graphics.hpp"
#include <iostream>
#include <string>

#include "Graphics.h"

using namespace std;

int main()
{
	Graphics graphics;
	std::cout << "Master branch!" << std::endl;

	

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
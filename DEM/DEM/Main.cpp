#include "SFML-2.4.2/include/SFML/Graphics.hpp"
#include <iostream>
#include <string>

#include "Graphics.h"
#include "Entity.h"
#include "EntityHandler.h"

#include "System.h"

using namespace std;



int main()
{

	System system;
	system.Run();

	/*while (true)
	{
		graphics.Render();
	}*/

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

	/*sf::Event event;
	while (window.pollEvent(event))
	{
		switch (event.type) {

		case sf::Event::KeyPressed:
			if (event.key.code == sf::Keyboard::Up)
			{
				
			}
			else if (event.key.code == sf::Keyboard::Down)
			{

			}
		default:
			break;
		}
	}*/

	return 0;
}


	
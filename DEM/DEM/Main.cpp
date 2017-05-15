#include "SFML-2.4.2/include/SFML/Graphics.hpp"
#include <iostream>
#include <string>

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

	return 0;
}
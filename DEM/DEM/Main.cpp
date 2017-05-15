#include "SFML-2.4.2/include/SFML/Graphics.hpp"
#include <iostream>
#include <string>

#include "Graphics.h"

using namespace std;

int main()
{
	Graphics graphics;
	//sf::RenderWindow * rw = new sf::RenderWindow(sf::VideoMode(1200, 800), "DEM");
	//graphics.setRenderWindow(rw);

	std::cout << "Nists branch!" << std::endl;

	//bool state = true;
	//while(state)
	//while (rw->isOpen())
	while(true)
	{
		graphics.Render();
		
		/*sf::Event event;
		while (rw->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				rw->close();
		}*/
	}

	//delete rw;

	return 0;
}
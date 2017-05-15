#include "SFML-2.4.2/include/SFML/Graphics.hpp"
#include <iostream>
#include <string>

#include "Graphics.h"

using namespace std;

int main()
{
	Graphics graphics;

	std::cout << "Nists branch!" << std::endl;

	//bool state = true;
	//while(state)
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

	return 0;
}
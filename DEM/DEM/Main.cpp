#include "SFML-2.4.2/include/SFML/Graphics.hpp"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	std::cout << "Nists branch!" << std::endl;

	sf::RenderWindow window(sf::VideoMode(1200, 800), "SFML works!");

	sf::RectangleShape mapBox(sf::Vector2f(800, 800));
	mapBox.setFillColor(sf::Color::Black);

	

	sf::RectangleShape textBox(sf::Vector2f(400, 800));
	textBox.setPosition(sf::Vector2f(802, 0));
	textBox.setFillColor(sf::Color(30, 30, 30));
	textBox.setOutlineColor(sf::Color::White);
	textBox.setOutlineThickness(2);

	sf::Font font;
	if (!font.loadFromFile("whitrabt.ttf"))
	{
		std::cout << "[ERROR] Font not loaded!" << std::endl;
	}

	string map = "";
	map += "##########################################################################################\n";
	map += "##########################################################################################\n";
	map += "##########################################################################################\n";
	map += "##########################################################################################\n";
	map += "##########################################################################################\n";
	map += "##########################################################################################\n";
	map += "##########################################################################################\n";
	map += "##########################################################################################\n";
	map += "##########################################################################################\n";
	map += "##########################################################################################\n";
	map += "##########################################################################################\n";
	map += "##########################################################################################\n";
	map += "##########################################################################################\n";
	map += "##########################################################################################\n";
	map += "##########################################################################################\n";
	map += "##########################################################################################\n";
	map += "##########################################################################################\n";
	map += "##########################################################################################\n";
	map += "##########################################################################################\n";
	map += "##########################################################################################\n";
	map += "##########################################################################################\n";
	map += "##########################################################################################\n";
	map += "##########################################################################################\n";
	map += "##########################################################################################\n";
	map += "##########################################################################################\n";
	map += "##########################################################################################\n";
	map += "##########################################################################################\n";
	map += "##########################################################################################\n";
	map += "##########################################################################################\n";
	map += "##########################################################################################\n";
	map += "##########################################################################################\n";
	map += "##########################################################################################\n";
	map += "##########################################################################################\n";
	map += "##########################################################################################\n";
	map += "##########################################################################################\n";
	map += "##########################################################################################\n";
	map += "##########################################################################################\n";
	map += "##########################################################################################\n";
	map += "##########################################################################################\n";
	map += "##########################################################################################\n";
	map += "##########################################################################################\n";
	map += "##########################################################################################\n";
	map += "##########################################################################################\n";
	map += "##########################################################################################\n";
	map += "##########################################################################################\n";
	map += "##########################################################################################\n";
	map += "##########################################################################################\n";
	map += "##########################################################################################\n";
	map += "##########################################################################################\n";
	map += "##########################################################################################\n";
	map += "##########################################################################################\n";
	map += "##########################################################################################\n";
	map += "##########################################################################################\n";
	map += "##########################################################################################\n";
	map += "##########################################################################################\n";
	map += "##########################################################################################\n";
	map += "##########################################################################################\n";
	map += "##########################################################################################\n";
	map += "##########################################################################################\n";
	map += "##########################################################################################";

	string chat = "";
	//chat += "TEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEXT";
	chat += "[MONSTER]\n";
	chat += "\tYou can run, but you can't\n";
	chat += "\thide!\n\n";
	chat += "[CHILD]\n";
	chat += "\tLol fkn pleb.\n\n";
	chat += "[MONSTER]\n";
	chat += "\tLOL I GOT FKN REKT SON!\n\n";
	chat += "[Nist]\n";
	chat += "\tNeat.\n\n";
	chat += "Lorem ipsum dolor sit amet, consectetur\n";
	chat += "adipiscing elit.Integer mauris est, ornare\n";
	chat += "sagittis rutrum quis, semper a neque.Nunc\n";
	chat += "in vulputate nulla.Aliquam pretium varius\n";
	chat += "luctus.Suspendisse nisl magna, malesuada\n";
	chat += "vel felis dictum, luctus aliquam velit.\n\n";

	sf::Text text_map;
	text_map.setFont(font);
	text_map.setString(map);
	text_map.setCharacterSize(15);
	text_map.setFillColor(sf::Color::White);
	text_map.setPosition(40, 50);

	sf::Text text_chat;
	text_chat.setFont(font);
	text_chat.setString(chat);
	text_chat.setCharacterSize(15);
	text_chat.setFillColor(sf::Color::White);
	text_chat.setPosition(815, 50);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();

		// ------------------------------ //


		window.draw(mapBox);
		window.draw(textBox);
		window.draw(text_map);
		window.draw(text_chat);

		// ------------------------------ //
		window.display();
	}

	return 0;
}
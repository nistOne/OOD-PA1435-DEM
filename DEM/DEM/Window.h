#pragma once
#include "SFML-2.4.2/include/SFML/Graphics.hpp"

class Window
{
private:

	sf::Vector2f m_size;
	sf::Vector2f m_pos;
	sf::Color m_color;

public:

	Window(sf::Vector2f size, sf::Vector2f pos, sf::Color color);
	~Window();

	bool update();
};
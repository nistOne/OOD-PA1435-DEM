#pragma once
#include "SFML-2.4.2/include/SFML/Graphics.hpp"

class Window
{
protected:

	sf::RectangleShape m_box;
	sf::Font m_font;

public:

	Window();
	~Window();

	void Initialize(sf::Vector2f size, sf::Vector2f pos, sf::Color color);
	
	void setOutlineColor(sf::Color color);
	void setOutlineThickness(int thickness);
	
	virtual void Render() = 0;
};
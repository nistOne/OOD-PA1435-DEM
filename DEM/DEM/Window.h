#pragma once
#include "SFML-2.4.2/include/SFML/Graphics.hpp"
#include <string>

using namespace std;

class Window
{
protected:

	sf::RectangleShape m_box;
	sf::Font m_font;
	string m_toPrint;

public:

	Window();
	~Window();

	void Initialize(sf::Vector2f size, sf::Vector2f pos, sf::Color color);
	
	void setOutlineColor(sf::Color color);
	void setOutlineThickness(int thickness);

	virtual void Render(sf::RenderWindow &window) = 0;
};
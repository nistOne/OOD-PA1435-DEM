#pragma once
#include "SFML-2.4.2/include/SFML/Graphics.hpp"
#include <string>

using namespace std;

class Window
{
protected:

	sf::RectangleShape m_box;
	sf::Font m_font;
	sf::Text m_text;

public:

	Window();
	~Window();

	void Initialize(sf::Vector2f size, sf::Vector2f pos, sf::Color color);

	void setBox_size(float x, float y);
	void setBox_position(float x, float y);
	void setBox_color(sf::Color color);
	void setBox_outlineColor(sf::Color color);
	void setBox_outlineThickness(float thickness);

	void setText_string(string text);
	void setText_charSize(int characterSize);
	void setText_color(sf::Color color);
	void setText_position(float x, float y);

	virtual void Render(sf::RenderWindow* window) = 0;
};
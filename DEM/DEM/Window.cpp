#include "Window.h"

Window::Window()
{
	this->m_font.loadFromFile("whitrabt.ttf");

	this->m_nrOfTexts = 5;
	this->m_text = new sf::Text[this->m_nrOfTexts];
}

Window::~Window()
{
	delete[]this->m_text;
}

void Window::Initialize(sf::Vector2f size, sf::Vector2f pos, sf::Color color)
{
	this->m_box.setSize(size);
	this->m_box.setPosition(pos);
	this->m_box.setFillColor(color);
}

//void Window::Render(sf::RenderWindow & window)
//{
//	window.draw(this->m_box);
//
//	sf::Text print;
//
//	this->m_font.loadFromFile("whitrabt.ttf");
//
//	this->test = new sf::Text[5];
//
//	this->test[0].setFont(this->m_font);
//	this->test[0].setString(m_printString);
//	this->test[0].setCharacterSize(15);
//	this->test[0].setFillColor(sf::Color::White);
//	this->test[0].setPosition(815, 50);
//
//	window.draw(test[0]);
//	delete[]this->test;
//}

void Window::setBox_size(float x, float y)
{
	this->m_box.setSize(sf::Vector2f(x, y));
}

void Window::setBox_position(float x, float y)
{
	this->m_box.setPosition(sf::Vector2f(x, y));
}

void Window::setBox_color(sf::Color color)
{
	this->m_box.setFillColor(color);
}

void Window::setBox_outlineColor(sf::Color color)
{
	this->m_box.setOutlineColor(color);
}

void Window::setBox_outlineThickness(float thickness)
{
	this->m_box.setOutlineThickness(thickness);
}

void Window::setText_string(int index, string text)
{
	this->m_text[index].setString(text);
}

void Window::setText_charSize(int index, int characterSize)
{
	this->m_text[index].setCharacterSize(characterSize);
}

void Window::setText_color(int index, sf::Color color)
{
	this->m_text[index].setFillColor(color);
}

void Window::setText_position(int index, float x, float y)
{
	this->m_text[index].setPosition(sf::Vector2f(x, y));
}

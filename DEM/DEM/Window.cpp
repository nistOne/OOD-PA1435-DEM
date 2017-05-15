#include "Window.h"

Window::Window()
{
	this->m_font.loadFromFile("whitrabt.ttf");
	this->m_text.setFont(this->m_font);
	this->m_text.setCharacterSize(15);
	this->m_text.setFillColor(sf::Color::White);
}

Window::~Window()
{
}

void Window::Initialize(sf::Vector2f size, sf::Vector2f pos, sf::Color color)
{
	this->m_box.setSize(size);
	this->m_box.setPosition(pos);
	this->m_box.setFillColor(color);
}

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

void Window::setText_string(string text)
{
	this->m_text.setString(text);
}

void Window::setText_charSize(int characterSize)
{
	this->m_text.setCharacterSize(characterSize);
}

void Window::setText_color(sf::Color color)
{
	this->m_text.setFillColor(color);
}

void Window::setText_position(float x, float y)
{
	this->m_text.setPosition(sf::Vector2f(x, y));
}

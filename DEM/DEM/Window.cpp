#include "Window.h"

Window::Window()
{
	this->m_font.loadFromFile("whitrabt.ttf");
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

void Window::setOutlineColor(sf::Color color)
{
	this->m_box.setOutlineColor(color);
}

void Window::setOutlineThickness(int thickness)
{
	this->m_box.setOutlineThickness(thickness);
}

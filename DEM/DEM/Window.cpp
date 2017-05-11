#include "Window.h"

Window::Window(sf::Vector2f size, sf::Vector2f pos, sf::Color color)
{
	this->m_size = size;
	this->m_pos = pos;
	this->m_color = color;
}

Window::~Window()
{

}

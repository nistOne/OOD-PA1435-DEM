#include "textWindow.h"

textWindow::textWindow(sf::Vector2f size, sf::Vector2f pos, sf::Color color) : Window(size, pos, color)
{
	// Create a chat log, holding 20 rows of text.
	this->m_log = new string[20];
}

textWindow::~textWindow()
{
	delete this->m_log;
}
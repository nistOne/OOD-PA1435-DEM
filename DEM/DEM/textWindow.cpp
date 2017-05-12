#include "TextWindow.h"

TextWindow::TextWindow()
{
	this->m_log.setCapacity(20);
	this->m_box.setOutlineColor(sf::Color::White);
	this->m_box.setOutlineThickness(2);
}

TextWindow::~TextWindow()
{
}

void TextWindow::Render()
{
	// Edit
}
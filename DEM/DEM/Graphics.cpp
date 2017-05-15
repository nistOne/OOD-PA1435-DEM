#include "Graphics.h"

Graphics::Graphics()
{
	//this->m_window.create(sf::VideoMode(1200, 800), "DEM");

	//this->m_gameWindow.Initialize(sf::Vector2f(800, 800), sf::Vector2f(0, 0), sf::Color::Black);
	this->m_textWindow.Initialize(sf::Vector2f(400, 800), sf::Vector2f(802, 0), sf::Color(30, 30, 30));
}

Graphics::~Graphics()
{

}

void Graphics::Render()
{
	this->m_textWindow.testUpdate();

	// Render GameWindow
	// Render TextWindow
	this->m_window.clear();
	this->m_textWindow.Render(this->m_window);
	this->m_window.display();
}
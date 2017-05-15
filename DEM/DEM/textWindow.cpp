#include "TextWindow.h"

TextWindow::TextWindow() : Window()
{
	//this->m_box.setOutlineColor(sf::Color::White);
	//this->m_box.setOutlineThickness(2);
	setBox_outlineColor(sf::Color::White);
	setBox_outlineThickness(2);

	this->m_text.setPosition(815, 50);
}

TextWindow::~TextWindow()
{
}

void TextWindow::testUpdate()
{
	//string chat = "";
	//chat += "[MONSTER]\n";
	//chat += "\tYou can run, but you can't\n";
	//chat += "\thide!\n\n";
	//chat += "[CHILD]\n";
	//chat += "\tLol fkn pleb.\n\n";
	//chat += "[MONSTER]\n";
	//chat += "\tLOL I GOT FKN REKT SON!\n\n";
	//chat += "[Nist]\n";
	//chat += "\tNeat.\n\n";
	//chat += "Lorem ipsum dolor sit amet, consectetur\n";
	//chat += "adipiscing elit.Integer mauris est, ornare\n";
	//chat += "sagittis rutrum quis, semper a neque.Nunc\n";
	//chat += "in vulputate nulla.Aliquam pretium varius\n";
	//chat += "luctus.Suspendisse nisl magna, malesuada\n";
	//chat += "vel felis dictum, luctus aliquam velit.\n\n";

	LogEvent tempEvent;

	tempEvent.author = "MONSTER";
	tempEvent.data = "You can run, but you can't hide!";
	//this->m_log.Push(tempEvent);

	tempEvent.author = "CHILD";
	tempEvent.data = "Lol fkn pleb.";
	//this->m_log.Push(tempEvent);

	tempEvent.author = "MONSTER";
	tempEvent.data = "LOL I GOT FKN REKT SON!";
	//this->m_log.Push(tempEvent);

	tempEvent.author = "Nist";
	tempEvent.data = "Neat.";
	//this->m_log.Push(tempEvent);

	//this->m_text[0].setString(chat);
	//this->m_printString = chat;
}

void TextWindow::Render(sf::RenderWindow &window)
{
	//window.draw(this->m_box);
	window.draw(this->m_box);
	
	// Draw won't work with an array sf::Text..
	sf::Text tempText;

	LogEvent msg;

	

	//for (int i = this->m_log.getNrOfElements(); i >= 0; i--)
	//{
	//	msg = this->m_log.getEvent(i);

	//	tempText.setFont(this->m_font);
	//	tempText.setString("[" + msg.author + "]\n\t" + msg.data + "\n\n");
	//
	//	//window.draw(this->m_text[i]);
	//	window->draw(tempText);
	//}
	this->m_text.setString("NIST IS HERE");
	window.draw(this->m_text);
}
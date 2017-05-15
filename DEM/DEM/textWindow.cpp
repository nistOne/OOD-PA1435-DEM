#include "TextWindow.h"

#define CAP 20

TextWindow::TextWindow() : Window()
{
	//this->m_box.setOutlineColor(sf::Color::White);
	//this->m_box.setOutlineThickness(2);
	setBox_outlineColor(sf::Color::White);
	setBox_outlineThickness(2);

	this->m_text.setPosition(815, 50);

	this->m_log.addMessage("MONSTER", "You can run, but you can't hide!");
	this->m_log.addMessage("CHILD", "Lol fkn pleb.");
	this->m_log.addMessage("MONSTER", "LOL I GOT FKN REKT SON!");
	this->m_log.addMessage("Nist", "Neat.");

	string lorem = "";
	lorem += "Lorem ipsum dolor sit amet, consectetur adipiscing elit.";
	lorem += " Integer mauris est, ornare adipiscing elit.Integer mauris";
	lorem += " est, ornare sagittis rutrum quis, semper a neque.Nunc in";
	lorem += " vulputate nulla.Aliquam pretium varius luctus.Suspendisse";
	lorem += " nisl magna, malesuada vel felis dictum, luctus aliquam velit.";

	this->m_log.addMessage(lorem);

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
	//chat += "\n";
	//chat += "\n";
	//chat += "\n";
	//chat += "\n";
	//chat += "\n\n";
}

void TextWindow::Render(sf::RenderWindow &window)
{
	window.draw(this->m_box);

	int nrOfMessages = this->m_log.getNrOfMessages();
	nrOfMessages > CAP ? CAP : nrOfMessages;

	string print = "";
	
	for (int i = 0; i < nrOfMessages; i++)
	{
		print += this->m_log.getMessageAtLine(i);
		print += "\n\n";

	}
		this->m_text.setString(print);
		window.draw(this->m_text);
}
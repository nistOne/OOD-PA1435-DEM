#include "TextWindow.h"

#define CAP 20

TextWindow::TextWindow() : Window()
{
	this->m_dialogueObserver = new DialogueObserver();

	//this->m_box.setOutlineColor(sf::Color::White);
	//this->m_box.setOutlineThickness(2);
	setBox_outlineColor(sf::Color::White);
	setBox_outlineThickness(2);

	this->m_text.setPosition(815, 50);

	this->m_dialogueObserver->update("MONSTER", "You can run, but you can't hide!");
	this->m_dialogueObserver->update("CHILD", "Lol fkn pleb.");
	this->m_dialogueObserver->update("MONSTER", "LOL I GOT FKN REKT SON!");
	this->m_dialogueObserver->update("Nist", "Neat.");

	string lorem = "";
	lorem += "Lorem ipsum dolor sit amet, consectetur adipiscing elit.";
	lorem += " Integer mauris est, ornare adipiscing elit.Integer mauris";
	lorem += " est, ornare sagittis rutrum quis, semper a neque.Nunc in";
	lorem += " vulputate nulla.Aliquam pretium varius luctus.Suspendisse";
	lorem += " nisl magna, malesuada vel felis dictum, luctus aliquam velit.";

	this->m_dialogueObserver->update("None", lorem);

}

TextWindow::~TextWindow()
{
	delete this->m_dialogueObserver;
}

Observer * TextWindow::getDialoueObserver()
{
	return this->m_dialogueObserver;
}

void TextWindow::Render(sf::RenderWindow* window)
{
	window->draw(this->m_box);

	int nrOfMessages = this->m_dialogueObserver->getLogSize();
	nrOfMessages > CAP ? CAP : nrOfMessages;

	string print = "";
	
	for (int i = 0; i < nrOfMessages; i++)
	{
		print += this->m_dialogueObserver->getMessageAtLine(i);
		print += "\n\n";

	}
		this->m_text.setString(print);
		window->draw(this->m_text);
}
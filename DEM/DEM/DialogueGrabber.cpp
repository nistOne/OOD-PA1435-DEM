#include "DialogueGrabber.h"

void DialogueGrabber::notifyObservers()
{
	DialogueObserver* tempObserver;

	for (int i = 0; i < this->m_observers.size(); i++)
	{
		tempObserver = dynamic_cast<DialogueObserver*>(this->m_observers.at(i)->getPointer());
		tempObserver->update(this->m_author, this->m_message);
	}
}

void DialogueGrabber::addDialogue(string author, string message)
{
	this->m_author = author;
	this->m_message = message;
	this->notifyObservers();
}

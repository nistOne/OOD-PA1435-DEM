#pragma once
#include "Subject.h"
#include "DialogueObserver.h"
#include <string>

using namespace std;

class DialogueGrabber : public Subject
{
private:

	string m_author;
	string m_message;

public:

	DialogueGrabber() {}
	~DialogueGrabber() {}

	virtual void notifyObservers();

	void addDialogue(string author, string message);
};
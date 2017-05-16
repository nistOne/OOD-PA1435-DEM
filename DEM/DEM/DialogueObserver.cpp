#include "DialogueObserver.h"

void DialogueObserver::update(string author, string message)
{
	LogMessage msg = { author, message };
	this->m_log.push_back(msg);
	this->setUpdated();
}

Observer * DialogueObserver::getPointer()
{
	return this;
}

int DialogueObserver::getLogSize()
{
	return this->m_log.size();
}

string DialogueObserver::getMessageAtLine(int line)
{
	string returnString;
	LogMessage msg = this->m_log.at(line);

	returnString = "[" + msg.author + "]\n";

	if (msg.message.length() < 30)
		returnString += "\t" + msg.message;
	else
	{
		returnString += "\t";
		for (int i = 0; i < msg.message.length(); i++)
		{
			returnString += msg.message[i];

			if (i != 0 && i % 35 == 0)
			{
				returnString += "\n\t";
			}
		}
	}

	return returnString;
}

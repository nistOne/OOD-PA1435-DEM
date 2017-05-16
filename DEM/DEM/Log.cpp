#include "Log.h"

Log::Log()
{
}

Log::~Log()
{
	this->m_messages.clear();
}

void Log::addMessage(string author, string message)
{
	LogMessage msg = { author, message };
	this->m_messages.push_back(msg);
}

void Log::addMessage(string message)
{
	LogMessage msg = { "None", message };
	this->m_messages.push_back(msg);
}

int Log::getNrOfMessages()
{
	return this->m_messages.size();
}

string Log::getMessageAtLine(int line)
{
	string returnString;
	LogMessage msg = this->m_messages.at(line);

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


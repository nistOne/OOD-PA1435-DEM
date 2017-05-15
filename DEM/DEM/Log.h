#pragma once
#include <string>
#include <vector>

using namespace std;

struct LogMessage
{
	string author;
	string data;
};

class Log
{
private:

	vector<LogMessage> m_messages;

public:

	Log();
	~Log();

	void addMessage(string author, string message);
	void addMessage(string message);
	
	int getNrOfMessages();
	string getMessageAtLine(int line);
};
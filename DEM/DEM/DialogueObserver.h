#pragma once
#include "Observer.h"
#include <string>
#include <vector>

using namespace std;

struct LogMessage
{
	string author;
	string message;
};

class DialogueObserver : public Observer
{
private:

	vector<LogMessage> m_log;

public:

	DialogueObserver() {}
	~DialogueObserver() {}

	void update(string author, string message);

	Observer* getPointer();

	int getLogSize();
	string getMessageAtLine(int line);
};
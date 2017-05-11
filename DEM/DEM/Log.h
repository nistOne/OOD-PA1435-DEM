#pragma once
#include <string>

using namespace std;

struct LogEvent
{
	string author;
	string msg;
};

class Log
{
private:

	class LogNode
	{
	public:
		LogNode(string data) { string data = data; this->next = nullptr; }
		~LogNode() { delete this->next; }

		LogNode * next;

		LogEvent data;
	};

	LogNode * first;
	LogNode * walker;
	LogNode * last;

public:

	Log(int maxLogEvents);
	~Log();

	void Push()

	LogEvent GetNext();
	void Reset();
};
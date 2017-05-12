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
		LogNode(LogEvent logEvent, LogNode * next = nullptr, LogNode * prev = nullptr)
		{
			this->data = logEvent;
			this->next = next;
			this->prev = prev;
		}
		~LogNode() { delete this->next; }

		LogNode * next;
		LogNode * prev;

		LogEvent data;
	};

	LogNode * m_first;
	LogNode * m_walker;
	LogNode * m_last;

	int m_capacity;
	int m_nrOfEvents;

public:

	Log();
	~Log();

	void setCapacity(int capacity);

	void Push(LogEvent logEvent);

	LogEvent GetNext();
	void Reset();
};
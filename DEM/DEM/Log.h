#pragma once
#include <string>

using namespace std;

struct LogEvent
{
	string author;
	string data;
};

class Log
{
private:

	LogEvent ** m_events;
	int m_capacity;
	int m_nrOfEvents;

	void setNull(int fromIndex = 0);

public:

	Log();
	~Log();

	int getCapacity();
	int getNrOfElements();

	void Push(LogEvent logEvent);

	LogEvent getEvent(int position);
};
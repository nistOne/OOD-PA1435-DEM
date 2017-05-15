#include "Log.h"

void Log::setNull(int fromIndex)
{
	for (int i = fromIndex; i < this->m_capacity; i++)
	{
		this->m_events[i] = nullptr;
	}
}

Log::Log()
{
	this->m_capacity = 20;
	this->m_nrOfEvents = 0;

	this->m_events = new LogEvent*[this->m_nrOfEvents];
	this->setNull();
}

Log::~Log()
{
	for (int i = 0; i < this->m_capacity; i++)
	{
		delete this->m_events[i];
	}
	
	delete[]this->m_events;
}

int Log::getCapacity()
{
	return this->m_capacity;
}

int Log::getNrOfElements()
{
	return this->m_nrOfEvents;
}

void Log::Push(LogEvent logEvent)
{
	LogEvent * newEvent = new LogEvent(logEvent);

	if (this->m_nrOfEvents == this->m_capacity)
	{
		delete this->m_events[this->m_nrOfEvents--];
	}

	for (int i = this->m_nrOfEvents - 1; i >= 0; i--)
	{
		this->m_events[i + 1] = this->m_events[i];
	}

	this->m_events[this->m_nrOfEvents++] = newEvent;
}



LogEvent Log::getEvent(int position)
{
	return *(this->m_events[position]);
}

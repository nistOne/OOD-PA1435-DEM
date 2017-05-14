#include "Log.h"

Log::Log()
{
	this->m_capacity = 0;
	this->m_nrOfEvents = 0;

	this->m_first = nullptr;
	this->m_walker = nullptr;
	this->m_last = nullptr;
}

Log::~Log()
{
	// Recursive delete.
	delete this->m_first;
}

void Log::setCapacity(int capacity)
{
	this->m_capacity = capacity;
}

void Log::Push(LogEvent logEvent)
{
	LogNode * temp = new LogNode(logEvent, this->m_first);
	this->m_first->prev = temp;
	this->m_first = temp;

	if (this->m_nrOfEvents == 0)
	{
		this->m_last = temp;
		this->m_nrOfEvents++;
	}
	else if (this->m_nrOfEvents == this->m_capacity)
	{
		this->m_last = this->m_last->prev;
		delete this->m_last->next;
		this->m_last->next = nullptr;
	}
}

LogEvent Log::GetCurrent()
{
	LogEvent returnValue;

	if (this->m_walker == this->m_last)
	{
		returnValue.author = "ERROR";
		returnValue.data = "ERROR";
	}
	else
	{
		returnValue = this->m_walker->data;
		this->m_walker = this->m_walker->next;
	}
	
	return returnValue;
}

void Log::Reset_front()
{
	this->m_walker = this->m_first;
}

void Log::Reset_back()
{
	this->m_walker = this->m_last;
}

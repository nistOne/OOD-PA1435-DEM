#include "Subject.h"

void Subject::registerObserver(Observer * observer)
{
	this->m_observers.push_back(observer);
}

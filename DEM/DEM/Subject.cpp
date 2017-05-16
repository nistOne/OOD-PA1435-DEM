#include "Subject.h"

void Subject::registerInputObserver(Observer * observer)
{
	this->m_observers.push_back(observer);
}

#pragma once
#include "Observer.h"
#include <vector>

using namespace std;

class Subject
{
protected:

	vector<Observer*> m_observers;

public:

	Subject() {}
	~Subject() {}

	virtual void registerInputObserver(Observer* observer);
	//virtual void unregisterObserver(Observer* observer);
	virtual void notifyObservers() = 0;

};
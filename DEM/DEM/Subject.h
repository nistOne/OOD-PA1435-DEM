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

	virtual void registerObserver(Observer * observer) = 0;
	//virtual void unregisterObserver(Observer observer); // May need to be inplemented.
	virtual void notifyObservers() = 0;

};
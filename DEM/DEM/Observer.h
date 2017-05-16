#pragma once

class Observer
{
private:

public:

	Observer() {}
	~Observer() {}

	// TODO: Set parameters.
	//virtual void update() = 0;
	virtual Observer* getPointer() = 0;

};
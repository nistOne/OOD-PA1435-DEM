#pragma once

class Observer
{
protected:

	bool m_updated;
	void setUpdated();

public:

	Observer() {}
	~Observer() {}

	// TODO: Set parameters.
	//virtual void update() = 0;
	virtual Observer* getPointer() = 0;

	bool isUpdated();

};
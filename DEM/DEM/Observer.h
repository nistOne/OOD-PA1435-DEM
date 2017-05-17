#pragma once

class Observer
{
protected:

	bool m_updated;
	void setUpdated();

public:

	Observer() {}
	~Observer() {}

	virtual Observer* getPointer() = 0;

	bool isUpdated();

};
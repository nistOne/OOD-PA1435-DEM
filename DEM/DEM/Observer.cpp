#include "Observer.h"

void Observer::setUpdated()
{
	this->m_updated = true;
}

bool Observer::isUpdated()
{
	if (this->m_updated)
	{
		this->m_updated = false;
		return true;
	}

	return this->m_updated;
}

#include "System.h"

System::System()
{
}

System::~System()
{
}

void System::Run()
{
	
	// Game loop. Observ input later on.
	while (true)
	{
		this->m_graphics.Render();
	}
}

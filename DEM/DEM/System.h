#pragma once
#include "Graphics.h"
#include "Map.h"

class System
{
private:

	//EntityHandler entityHandler;
	Graphics m_graphics;
	

public:

	System();
	~System();

	void Run();

};
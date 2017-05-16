#pragma once
#include "Graphics.h"
#include "Map.h"

class System
{
private:

	//EntityHandler entityHandler;
	Graphics m_graphics;
	
	// Delete!!!
	Map map;

public:

	System();
	~System();

	void Run();

};
#pragma once
#include "Graphics.h"
#include "EntityHandler.h"
#include "Map.h"

class System
{
private:

	EntityHandler m_entityHandler;
	Graphics m_graphics;
	
	
	Map map;

public:

	System();
	~System();

	void Run();

};
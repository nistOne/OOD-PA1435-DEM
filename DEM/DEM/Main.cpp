#include "SFML-2.4.2/include/SFML/Graphics.hpp"
#include <iostream>
#include <string>

#include "System.h"

using namespace std;



int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	System system;
	system.Run();

	return 0;
}


	
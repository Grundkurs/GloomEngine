#include <iostream>

using namespace std;

#include "Game.h"

int main()
	{
	Game game;
	if ( !game.init() )
		{
		return 1;
		}
	else
		{
		return game.run();
		}
	}


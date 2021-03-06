#pragma once

#ifndef GAME_H
#define GAME_H

#include "Core/GloomEngine.h"
using gloom::GloomEngine;

class Game : public GloomEngine
{
public:
	Game();
	virtual ~Game();

	bool init();

	virtual void gameUpdate();
	virtual void gameDraw();

private:
	Game( const Game & other );
	Game( Game && other );
	Game & operator = ( const Game & other );
	Game & operator = ( Game && other );
};

#endif // GAME_H

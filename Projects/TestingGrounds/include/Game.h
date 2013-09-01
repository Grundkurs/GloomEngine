#pragma once

#ifndef GAME_H
#define GAME_H

#include "include/Core/GlowEngine.h"

class Game : public GlowEngine
{
public:
	Game();
	virtual ~Game();

	bool init();

	virtual void gameUpdate();
	virtual void gameDraw();
};

#endif // GAME_H

#include "include/Game.h"

#include "Core/Logger.h"

Game::Game()
	:
	GloomEngine()
	{

	}

Game::~Game()
	{

	}

bool Game::init()
	{
	LogFuncBegin()

	if ( !GloomEngine::init() )
		{
		LogFailure("Failed to init GlowEngine")
		return false;
		}

	LogFuncEndSuccess()
	return true;
	}

void Game::gameUpdate()
	{

	}

void Game::gameDraw()
	{

	}

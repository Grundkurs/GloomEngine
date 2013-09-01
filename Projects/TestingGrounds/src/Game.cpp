#include "include/Game.h"

#include "include/Core/Logger.h"

Game::Game()
	:
	GlowEngine()
	{

	}

Game::~Game()
	{

	}

bool Game::init()
	{
	LogFuncBegin()

	if ( !GlowEngine::init() )
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

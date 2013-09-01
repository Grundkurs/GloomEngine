#include "include/Core/GloomEngine.h"

#include "include/Core/Logger.h"
#include "include/Renderer/Window.h"
using namespace gloom;

#include "GLFW/glfw3.h"

GloomEngine::GloomEngine()
	:
	mpWindow( new Window() ),
	mTimeStampD(0.0),
	mTimeDeltaD(0.0),
	mTimeStampF(0.0f),
	mTimeDeltaF(0.0f),
	mReturnValue(0)
	{

	}

GloomEngine::~GloomEngine()
	{
	if ( mpWindow )
		{
		delete mpWindow;
		mpWindow = nullptr;
		}
	}

bool GloomEngine::init()
	{
	LogFuncBegin()
	// TODO: load the config file for engine startup properties

	// init glfw window
	// TODO: currently window size is hard coded until config loader code exists
	if ( !mpWindow->init( 800, 600 ) )
		{
		LogFailure("Failed to setup window.")
		return false;
		}

	LogFuncEndSuccess()
	return true;
	}

int GloomEngine::run()
	{
	LogFuncBegin()
	mTimeStampD = glfwGetTime();
	mTimeStampF = float(mTimeStampD);
	while ( mpWindow->isOpen() )
		{
		// setup timers
		double now = glfwGetTime();
		mTimeDeltaD = now - mTimeStampD;
		mTimeStampD = now;
		mTimeDeltaF = float(mTimeDeltaD);
		mTimeStampF = float(mTimeStampF);

		glfwPollEvents();

		gameUpdate();
		gameDraw();

		mpWindow->display();
		}
	LogFuncEndSuccess()
	return mReturnValue;
	}

double GloomEngine::getTimeStampD() const
	{
	return mTimeStampD;
	}

double GloomEngine::getTimeDeltaD() const
	{
	return mTimeDeltaD;
	}

float GloomEngine::getTimeStampF() const
	{
	return mTimeStampF;
	}

float GloomEngine::getTimeDeltaF() const
	{
	return mTimeDeltaF;
	}

void GloomEngine::setReturnValue(int returnValue)
	{
	mReturnValue = returnValue;
	}

#include "Core/GloomEngineConfig.h"

#include "Core/Logger.h"
#include "Core/ResourcePaths.h"

#include <fstream>
using namespace std;

namespace gloom
{

GloomEngineConfig::GloomEngineConfig()
	:
	mScreenWidth(800),
	mScreenHeight(600),
	mGLVersionMajor(3),
	mGLVersionMinor(3),
	mGLCoreProfile(true),
	mGLAASamples(0)
	{

	}

bool GloomEngineConfig::LoadConfigFile(const string & fileName)
	{
	LogFuncBegin()
	ifstream ifs;
	ifs.open( GetPathToConfigs() + fileName );

	if ( !ifs.is_open() )
		{
		LogFailure("Failed to open config file " + fileName )
		return false;
		}

	string command;

	while ( ifs >> command )
		{
		if ( command == "screenWidth" )
			{
			ifs >> mScreenWidth;
			}
		else if ( command == "screenHeight" )
			{
			ifs >> mScreenHeight;
			}
		else if ( command == "glVersionMajor" )
			{
			ifs >> mGLVersionMajor;
			}
		else if ( command == "glVersionMinor" )
			{
			ifs >> mGLVersionMinor;
			}
		else if ( command == "glCoreProfile" )
			{
			string strBool;
			ifs >> strBool;

			mGLCoreProfile = ( strBool == "true" ? true : false );
			}
		else if ( command == "glAASamples" )
			{
			ifs >> mGLAASamples;
			}
		else
			{
			LogWarning("Script file has unknown command " + command)
			// throw away rest of line
			getline(ifs, command);
			}

		if ( ifs.bad() )
			{
			LogFailure("Error while loading config command " + command )
			return false;
			}
		}

	LogFuncEndSuccess()
	return true;
	}

int GloomEngineConfig::getScreenWidth() const
	{
	return mScreenWidth;
	}

int GloomEngineConfig::getScreenHeight() const
	{
	return mScreenHeight;
	}

int GloomEngineConfig::getGLVersionMajor() const
	{
	return mGLVersionMajor;
	}

int GloomEngineConfig::getGLVersionMinor() const
	{
	return mGLVersionMinor;
	}

bool GloomEngineConfig::getGLCoreProfile() const
	{
	return mGLCoreProfile;
	}

int GloomEngineConfig::getGLAASamples() const
	{
	return mGLAASamples;
	}

}

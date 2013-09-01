#include "include/Core/GloomEngineConfig.h"

#include "include/Core/Logger.h"
#include "include/Core/ResourcePaths.h"

#include <fstream>
using namespace std;

namespace gloom
{

GloomEngineConfig::GloomEngineConfig()
	:
	mScreenWidth(800),
	mScreenHeight(600)
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

}

#pragma once
#ifndef GLOOMENGINECONFIG_H
#define GLOOMENGINECONFIG_H

#include <string>

namespace gloom
{

class GloomEngineConfig
{
public:
	GloomEngineConfig();

	bool LoadConfigFile( const std::string & fileName = "GloomEngine.config" );

	int getScreenWidth() const;
	int getScreenHeight() const;

private:

	int mScreenWidth;
	int mScreenHeight;

};

}
#endif // GLOOMENGINECONFIG_H

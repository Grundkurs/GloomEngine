#pragma once
#ifndef GLOOMENGINECONFIG_H
#define GLOOMENGINECONFIG_H

#include <string>
using std::string;

namespace gloom
{

class GloomEngineConfig
{
public:
	GloomEngineConfig();

	bool LoadConfigFile( const string & fileName = "GloomEngine.config" );

	int getScreenWidth() const;
	int getScreenHeight() const;

private:
	GloomEngineConfig( const GloomEngineConfig & other );
	GloomEngineConfig( GloomEngineConfig && other );
	GloomEngineConfig & operator = ( const GloomEngineConfig & other );
	GloomEngineConfig & operator = ( GloomEngineConfig && other );

	int mScreenWidth;
	int mScreenHeight;

};

}
#endif // GLOOMENGINECONFIG_H

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

	int getGLVersionMajor() const;
	int getGLVersionMinor() const;

	bool getGLCoreProfile() const;

	int getGLAASamples() const;

private:
	GloomEngineConfig( const GloomEngineConfig & other );
	GloomEngineConfig( GloomEngineConfig && other );
	GloomEngineConfig & operator = ( const GloomEngineConfig & other );
	GloomEngineConfig & operator = ( GloomEngineConfig && other );

	int mScreenWidth;
	int mScreenHeight;

	int mGLVersionMajor;
	int mGLVersionMinor;

	bool mGLCoreProfile;

	int mGLAASamples;
};

}
#endif // GLOOMENGINECONFIG_H

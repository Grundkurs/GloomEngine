#ifndef RESOURCEPATHS_H
#define RESOURCEPATHS_H

#include <string>
using std::string;

namespace gloom
{

inline const string & GetPathToConfigs()
	{
	static const string configPath = "../../Resources/Configs/";
	return configPath;
	}

inline const string & GetPathToScripts()
	{
	static const string scriptPath = "../../Resources/Scripts/";
	return scriptPath;
	}

inline const string & GetPathToMeshes()
	{
	static const string meshPath = "../../Resources/Meshes/";
	return meshPath;
	}

inline const string & GetPathToAudio()
	{
	static const string audioPath = "../../Resources/Audio/";
	return audioPath;
	}

inline const string & GetPathToMaps()
	{
	static const string mapPath = "../../Resources/Maps/";
	return mapPath;
	}

}
#endif // RESOURCEPATHS_H

#pragma once
#include "Singleton.h"

class AtlasManager : public Singleton<AtlasManager>
{
public:
	void SetAtlas(string atlasName, string txtLocate, string pngLocate);
	void SetAtlasAnimation(string atlasName, string key, string txtLocate);

	AtlasManager() {}
	virtual ~AtlasManager() {}
};

#define ATLASMANAGER AtlasManager::GetSingleton()
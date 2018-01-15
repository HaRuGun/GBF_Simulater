#pragma once
#include "Singleton.h"

class AtlasManager : public Singleton<AtlasManager>
{
public:
	map<string, string> SetAtlas(string AtlasName, string txtLocate, string pngLocate);

	AtlasManager() {}
	virtual ~AtlasManager() {}
};

#define ATLASMANAGER AtlasManager::GetSingleton()
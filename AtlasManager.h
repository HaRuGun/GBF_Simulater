#pragma once
#include "Singleton.h"



class AtlasManager : public Singleton<AtlasManager>
{
public:
	void SetAtlas(string AtlasName, string txtLocate, string pngLocate);
	void SetAtlasAnimation(string AtlasName, string AnimName, string txtLocate);

	AtlasManager() {}
	virtual ~AtlasManager() {}
};

#define ATLASMANAGER AtlasManager::GetSingleton()
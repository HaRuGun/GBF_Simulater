#pragma once
#include "Singleton.h"


enum SOUNDTYPE
{
	BGM = 1,
	SE
};

struct SoundData
{
	FMOD::Sound* Sound;
	FMOD::Channel* Channel;
	SOUNDTYPE type;

	SoundData()
		:Sound(nullptr), Channel(nullptr)
	{
	}
};

class SoundManager : public Singleton<SoundManager>
{
private:
	FMOD::System* System;

	map<string, SoundData*> mapSound;

public:
	void Init();
	void Update();
	void Release();

	void LoadSound(string key, LPCSTR fileName, SOUNDTYPE type);
	void PlaySound(string key);
	void StopSound(string key);

	SoundManager();
	virtual ~SoundManager();
};

#define SOUNDMANAGER SoundManager::GetSingleton()
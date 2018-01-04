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

public:
	void Init();
	void Update();
	void Release();

	void LoadSound(SoundData &soundData, LPCSTR fileName, SOUNDTYPE type);
	void PlaySound(SoundData &soundData);
	void StopSound(SoundData &soundData);

	SoundManager();
	virtual ~SoundManager();
};

#define SOUNDMANAGER SoundManager::GetSingleton()
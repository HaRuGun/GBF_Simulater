#include "stdafx.h"


SoundManager::SoundManager()
{
	Init();
}


SoundManager::~SoundManager()
{
	Release();
}


// Method


void SoundManager::Init()
{
	FMOD::System_Create(&System);
	System->init(10, FMOD_INIT_NORMAL, 0);
}


void SoundManager::Update()
{
	//System->update();
}


void SoundManager::Release()
{
	System->release();
	System->close();
}


// Custom


void SoundManager::LoadSound(SoundData &soundData, LPCSTR fileName, SOUNDTYPE type)
{
	soundData.type = type;

	switch (type)
	{
	case BGM:
		System->createStream(fileName, FMOD_LOOP_NORMAL, NULL, &soundData.Sound);
		return;

	case SE:
		System->createSound(fileName, FMOD_DEFAULT, NULL, &soundData.Sound);
		return;
	}
}


void SoundManager::PlaySound(SoundData &soundData)
{
	System->update();
	System->playSound(FMOD_CHANNEL_FREE, soundData.Sound, false, &soundData.Channel);
}


void SoundManager::StopSound(SoundData &soundData)
{
	if (!soundData.Channel) return;

	bool bIsPlaying;
	soundData.Channel->isPlaying(&bIsPlaying);

	if (bIsPlaying)
	{
		soundData.Channel->stop();
		soundData.Channel = nullptr;
	}
}
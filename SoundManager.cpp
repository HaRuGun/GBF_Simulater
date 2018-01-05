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
	map<string, SoundData*>::iterator iter;
	for (iter = mapSound.begin(); iter != mapSound.end(); ++iter)
	{
		iter->second->Sound->release();
		SAFE_DELETE(iter->second);
	}
	mapSound.clear();

	System->release();
	System->close();
}


// Custom


void SoundManager::LoadSound(string key, LPCSTR fileName, SOUNDTYPE type)
{
	SoundData* dest;
	dest = new SoundData;
	dest->type = type;

	switch (type)
	{
	case BGM:
		System->createStream(fileName, FMOD_LOOP_NORMAL, NULL, &dest->Sound);
		mapSound.insert(make_pair(key, dest));
		return;

	case SE:
		System->createSound(fileName, FMOD_DEFAULT, NULL, &dest->Sound);
		mapSound.insert(make_pair(key, dest));
		return;
	}
}


void SoundManager::PlaySound(string key)
{
	SoundData* dest = mapSound.find(key)->second;
	if (dest == NULL)
		return;

	System->update();
	System->playSound(FMOD_CHANNEL_FREE, dest->Sound, false, &dest->Channel);
}


void SoundManager::StopSound(string key)
{
	SoundData* dest = mapSound.find(key)->second;
	if (dest == NULL)
		return;

	if (!dest->Channel)
		return;

	bool bIsPlaying;
	dest->Channel->isPlaying(&bIsPlaying);

	if (bIsPlaying)
	{
		dest->Channel->stop();
		dest->Channel = nullptr;
	}
}
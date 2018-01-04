#include "stdafx.h"


void SceneManager::Init()
{
	pCurrentScene = &sMain;
	pNextScene = nullptr;
	bSceneChange = false;

	sMain.Init();
}


void SceneManager::Release()
{
	pCurrentScene->Release();
}


void SceneManager::Update(double deltaTime)
{
	pCurrentScene->Update(deltaTime);

	if (bSceneChange)
	{
		pCurrentScene->Release();
		pCurrentScene = pNextScene;
		pCurrentScene->Init();

		bSceneChange = false;
	}
}


void SceneManager::Render()
{
	pCurrentScene->Render();
}


// Custom


void SceneManager::ChageScene(Scene* pScene)
{
	if (pScene != nullptr)
	{
		pNextScene = pScene;
		bSceneChange = true;
	}

	return;
}
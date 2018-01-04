#pragma once
#include "SMain.h"

class SceneManager : public Singleton<SceneManager>
{
private:
	Scene* pCurrentScene;
	Scene* pNextScene;
	bool bSceneChange;

	SMain sMain;

public:
	void Init();
	void Update(double deltaTime);
	void Render();
	void Release();
	 
	void ChageScene(Scene * pScene);

	Scene* GetSMainScene() { return &sMain; }

	SceneManager() {}
	virtual ~SceneManager() {}
};

#define SCENEMANAGER SceneManager::GetSingleton()
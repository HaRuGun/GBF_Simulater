#pragma once
#include "Singleton.h"

#define KEYMAX 256

class InputManager : public Singleton<InputManager>
{
private:
	bool bKeyState[KEYMAX];
	bool bPrevKeyState[KEYMAX];
	
	POINT pMouse;
	bool bMouseClick;

	void Init();

public:
	void Update();

	bool IsKeyDown(int iKey);
	bool IsKeyHold(int iKey);
	bool IsKeyUp(int iKey);
	//bool IsObjectClicked(Object object);

	void SetMouseClick(bool bMouseClick);
	bool GetMouseClick();
	POINT GetMousePos();

	InputManager();
	virtual ~InputManager();
};

#define INPUTMANAGER InputManager::GetSingleton()
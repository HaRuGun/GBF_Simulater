#include "stdafx.h"


InputManager::InputManager()
{
	Init();
}


InputManager::~InputManager()
{
}


void InputManager::Init()
{
	pMouse = { 0, 0 };
	bMouseClick = false;

	memset(bKeyState, false, sizeof(bKeyState));
	memset(bPrevKeyState, false, sizeof(bPrevKeyState));
}


void InputManager::Update()
{
	memcpy(bPrevKeyState, bKeyState, sizeof(bPrevKeyState));

	for (int i = 0; i < KEYMAX; i++)
		bKeyState[i] = GetAsyncKeyState(i) & 0x8000;

	::GetCursorPos(&pMouse);
	::ScreenToClient(hWnd, &pMouse);
}


// Custom


bool InputManager::IsKeyDown(int iKey)
{
	if (bPrevKeyState[iKey] == false && bKeyState[iKey] == true)
		return true;
	return false;
}


bool InputManager::IsKeyHold(int iKey)
{
	if (bPrevKeyState[iKey] == true && bKeyState[iKey] == true)
		return true;
	return false;
}


bool InputManager::IsKeyUp(int iKey)
{
	if (bPrevKeyState[iKey] == true && bKeyState[iKey] == false)
		return true;
	return false;
}

/*
bool InputManager::IsObjectClicked(Object object)
{

}
*/


// Set


void InputManager::SetMouseClick(bool bMouseClick)
{
	this->bMouseClick = bMouseClick;
}


// Get


POINT InputManager::GetMousePos()
{
	return pMouse;
}


bool InputManager::GetMouseClick()
{
	return bMouseClick;
}
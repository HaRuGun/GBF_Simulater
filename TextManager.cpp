#include "stdafx.h"


TextManager::TextManager()
{
	Init();
}


TextManager::~TextManager()
{
	Release();
}


void TextManager::Init()
{
	D3DXCreateFont(
		lpd3dDevice,
		25,
		0,
		FW_DONTCARE,
		1,
		false,
		DEFAULT_CHARSET,
		OUT_DEFAULT_PRECIS,
		DEFAULT_QUALITY,
		DEFAULT_PITCH | FF_DONTCARE,
		"배달의민족 주아",
		//"Arial",
		&Font);
}


void TextManager::Release()
{
	SAFE_RELEASE(Font);
}

void TextManager::WriteText(LPCSTR text, float x, float y, DWORD alphaColor)
{
	RECT rc = { x, y, 0, 0 };
	Font->DrawText(NULL, text, -1, &rc, DT_NOCLIP, alphaColor);
}


void TextManager::LostDevice()
{
	if (Font)
		Font->OnLostDevice();
}


void TextManager::ResetDevice()
{
	if (Font)
		Font->OnResetDevice();
}
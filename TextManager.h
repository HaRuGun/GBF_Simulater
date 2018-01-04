#pragma once


class TextManager : public Singleton<TextManager>
{
private:
	ID3DXFont* Font;
	ID3DXSprite* Sprite;

	void Init();
	void Release();

public:
	void WriteText(LPCSTR text, float x, float y, DWORD alphaColor);

	void LostDevice();
	void ResetDevice();

	TextManager();
	virtual ~TextManager();
};

#define TEXTMANAGER TextManager::GetSingleton()
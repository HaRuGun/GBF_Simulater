#pragma once
#include "Singleton.h"

using namespace std;

struct texture
{
	LPDIRECT3DTEXTURE9 lpd3dTex;
	D3DXIMAGE_INFO info;
};

struct matrix
{
public:
	float width, height;
	float x, y;
	float velocity, direction;
};

struct frameData
{
public:
	int wCount, hCount;
	int wIndex, hIndex;
};


// Atlas Animation
struct animFrame
{
	float fTime;
	vector<animKey> vectorKey;
};

struct animKey
{
	string sParts;
	matrix mat;
};


class ImageManager : public Singleton<ImageManager>
{
private:
	LPD3DXSPRITE lpd3dSprite;
	
	map<string, texture*> mapTexture;
	map<string, RECT> mapAtlas;
	map<string, vector<animFrame>> mapAnim;
	
	int Init();
	int Release();

public:
	HRESULT Begin();
	void End();

	void LostDevice();
	void ResetDevice();

	void AddImage(string key, LPCSTR lpPath);
	void AddAtlas(string key, RECT rc);
	void AddAtlasAnimation(string key, vector<animFrame> animFrame);

	void DrawImage(string key, matrix mat, int alpha = 255.0f);
	void DrawFrameImage(string key, frameData frame, matrix mat, int alpha = 255.0f);
	void DrawAtlasImage(string atlasName, string key, matrix mat, int alpha = 255.0f);
	void DrawAtlasAnimation(string atlasName, string animName, matrix mat, int alpha = 255.0f);

	ImageManager();
	virtual ~ImageManager();
};

#define IMAGEMANAGER ImageManager::GetSingleton()
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

	matrix(float _x, float _y) { x = _x; y = _y; }
	matrix(float _width, float _height, float _x, float _y, float _velocity, float _direction)
	{
		width = _width; height = _height;
		x = _x; y = _y;
		velocity = _velocity; direction = _direction;
	}
	matrix() {}
	~matrix() {}
};	


struct frameData
{
public:
	int wCount, hCount;
	int wIndex, hIndex;
};


// Atlas Animation
struct animKey
{
	string sParts;
	matrix mat;
};

struct animFrame
{
	float fTime;
	vector<animKey> vectorKey;
};

struct atlasAnimation
{
	double dCurrentTime;
	size_t frameCount;
	vector<animFrame> vectorFrame;
};


class ImageManager : public Singleton<ImageManager>
{
private:
	LPD3DXSPRITE lpd3dSprite;
	
	map<string, texture*> mapTexture;
	map<string, RECT> mapAtlas;
	map<string, atlasAnimation> mapAnimation;
	
	int Init();
	int Release();

public:
	HRESULT Begin();
	void End();

	void LostDevice();
	void ResetDevice();

	void AddImage(string key, LPCSTR lpPath);
	void AddAtlas(string key, RECT rc);
	void AddAtlasAnimation(string key, atlasAnimation anim);

	void DrawImage(string key, matrix mat, int alpha = 255.0f);
	void DrawFrameImage(string key, frameData frame, matrix mat, int alpha = 255.0f);
	void DrawAtlasImage(string atlasName, string key, matrix mat, int alpha = 255.0f);
	
	void PlayAtlasAnimation(string atlasName, string key, matrix mat, double deltaTime, int alpha = 255.0f);
	void StopAtlasAnimation(string atlasName, string key);

	ImageManager();
	virtual ~ImageManager();
};

#define IMAGEMANAGER ImageManager::GetSingleton()
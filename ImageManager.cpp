#include "stdafx.h"


ImageManager::ImageManager()
{
	Init();
}

ImageManager::~ImageManager()
{
	Release();
}

int ImageManager::Init()
{
	D3DXCreateSprite(lpd3dDevice, &lpd3dSprite);
	return 0;
}


int ImageManager::Release()
{
	map<string, texture*>::iterator iter;
	for (iter = mapTexture.begin(); iter != mapTexture.end(); ++iter)
	{
		iter->second->lpd3dTex->Release();
		SAFE_DELETE(iter->second);
	}
	mapTexture.clear();

	SAFE_RELEASE(lpd3dSprite);
	return 0;
}


HRESULT ImageManager::Begin()
{
	return lpd3dSprite->Begin(D3DXSPRITE_ALPHABLEND);
}


void ImageManager::End()
{
	lpd3dSprite->End();
}


void ImageManager::LostDevice()
{
	if (lpd3dSprite != nullptr)
		lpd3dSprite->OnLostDevice();
}


void ImageManager::ResetDevice()
{
	if (lpd3dSprite != nullptr)
		lpd3dSprite->OnResetDevice();
}


void ImageManager::AddImage(string key, LPCSTR lpPath)
{
	LPDIRECT3DTEXTURE9 lpd3dTex;
	D3DXIMAGE_INFO info;

	D3DXCreateTextureFromFileEx(lpd3dDevice, lpPath, D3DX_DEFAULT_NONPOW2, D3DX_DEFAULT_NONPOW2, 0, 0,
		D3DFMT_UNKNOWN, D3DPOOL_MANAGED, D3DX_DEFAULT, D3DX_DEFAULT, 0, &info, nullptr, &lpd3dTex);

	texture* dest = new texture;
	dest->lpd3dTex = lpd3dTex;
	dest->info = info;

	mapTexture.insert(make_pair(key, dest));
}


void ImageManager::DrawImage(string key, matrix mat, int alpha)
{
	texture* tex = mapTexture.find(key)->second;
	if (tex != NULL)
	{
		D3DXMATRIX matTrans;
		D3DXVECTOR3 Center = { (float)tex->info.Width / 2, (float)tex->info.Height / 2, 0.0f };

		D3DXMatrixIdentity(&matTrans);
		D3DXMatrixAffineTransformation2D(&matTrans, 1.0f, nullptr, D3DXToRadian(mat.direction), &D3DXVECTOR2(mat.x, mat.y));
		lpd3dSprite->SetTransform(&matTrans);

		lpd3dSprite->Draw(tex->lpd3dTex, nullptr, &Center, nullptr, D3DCOLOR_RGBA(0xFF, 0xFF, 0xFF, alpha));
	}
}


void ImageManager::DrawFrameImage(string key, frameData frame, matrix mat, int alpha)
{
	texture* tex = mapTexture.find(key)->second;
	if (tex != NULL)
	{
		float width = (float)tex->info.Width;
		float height = (float)tex->info.Height;

		float left = width / frame.wCount * frame.wIndex;
		float top = height / frame.hCount * frame.hIndex;
		float right = width / frame.wCount * (frame.wIndex + 1);
		float bottom = height / frame.hCount * (frame.hIndex + 1);
		RECT image = { left, top, right, bottom };

		D3DXMATRIX matTrans;
		D3DXVECTOR3 Center = { width / frame.wCount / 2, height / frame.hCount / 2, 0.0f };

		D3DXMatrixIdentity(&matTrans);
		D3DXMatrixAffineTransformation2D(&matTrans, 1.0f, nullptr, D3DXToRadian(mat.direction), &D3DXVECTOR2(mat.x, mat.y));
		lpd3dSprite->SetTransform(&matTrans);

		lpd3dSprite->Draw(tex->lpd3dTex, &image, &Center, nullptr, D3DCOLOR_RGBA(0xFF, 0xFF, 0xFF, alpha));
	}
}
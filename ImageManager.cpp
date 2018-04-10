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


//


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


void ImageManager::AddAtlas(string key, RECT rc)
{
	mapAtlas.insert(make_pair(key, rc));
}


void ImageManager::AddAtlasAnimation(string key, atlasAnimation anim)
{
	mapAnimation.insert(make_pair(key, anim));
}


//


void ImageManager::DrawImage(string key, matrix mat, int alpha)
{
	texture* tex = mapTexture.find(key)->second;
	if (tex != NULL)
	{
		D3DXVECTOR3 Center = { (float)tex->info.Width / 2, (float)tex->info.Height / 2, 0.0f };

		D3DXMATRIXA16 matS, matR, matT, matResult;

		D3DXMatrixScaling(&matS, mat.width, mat.height, 1);
		D3DXMatrixRotationZ(&matR, D3DXToRadian(mat.direction));
		D3DXMatrixTranslation(&matT, mat.x, mat.y, 0);

		matResult = matR * matT * matS;

		lpd3dSprite->SetTransform(&matResult);

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

		D3DXVECTOR3 Center = { width / frame.wCount / 2, height / frame.hCount / 2, 0.0f };
		
		D3DXMATRIXA16 matS, matR, matT, matResult;

		D3DXMatrixScaling(&matS, mat.width, mat.height, 1);
		D3DXMatrixRotationZ(&matR, D3DXToRadian(mat.direction));
		D3DXMatrixTranslation(&matT, mat.x, mat.y, 0);
		
		matResult = matS * matR * matT;

		lpd3dSprite->SetTransform(&matResult);

		lpd3dSprite->Draw(tex->lpd3dTex, &image, &Center, nullptr, D3DCOLOR_RGBA(0xFF, 0xFF, 0xFF, alpha));
	}
}


void ImageManager::DrawAtlasImage(string atlasName, string key, matrix mat, int alpha)
{
	texture* tex = mapTexture.find(atlasName)->second;
	if (tex != NULL)
	{
		RECT image = mapAtlas.find(key)->second;

		float width = image.right - image.left;
		float height = image.bottom - image.top;

		D3DXMATRIX matTrans, matS;
		D3DXVECTOR3 Center = { width / 2, height / 2, 0.0f };

		D3DXMatrixIdentity(&matTrans);
		D3DXMatrixAffineTransformation2D(&matTrans, mat.width, nullptr, D3DXToRadian(mat.direction), &D3DXVECTOR2(mat.x, mat.y));
		lpd3dSprite->SetTransform(&matTrans);

		lpd3dSprite->Draw(tex->lpd3dTex, &image, &Center, nullptr, D3DCOLOR_RGBA(0xFF, 0xFF, 0xFF, alpha));
	}
}


//


void ImageManager::PlayAtlasAnimation(string atlasName, string key, matrix mat, double deltaTime, int alpha)
{
	atlasAnimation destAnim = mapAnimation.find(atlasName + key)->second;
	destAnim.dCurrentTime += deltaTime;

	animFrame destFrame = destAnim.vectorFrame[destAnim.frameCount];

	size_t j;
	for (j = 0; j < destFrame.vectorKey.size(); j++)
	{
		animKey destKey = destFrame.vectorKey[j];
		DrawAtlasImage(atlasName, destKey.sParts, destKey.mat, alpha);
	}

	if (destFrame.fTime >= destAnim.dCurrentTime)
		destAnim.frameCount++;
}


void ImageManager::StopAtlasAnimation(string atlasName, string key)
{
	atlasAnimation destAnim = mapAnimation.find(atlasName + key)->second;
	if (destAnim.dCurrentTime != 0 || destAnim.frameCount != 0)
	{
		destAnim.dCurrentTime = 0;
		destAnim.frameCount = 0;
	}
}
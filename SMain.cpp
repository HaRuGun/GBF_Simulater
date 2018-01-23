#include "stdafx.h"
#include "SMain.h"

SMain::SMain()
{
}

SMain::~SMain()
{
}

void SMain::Init() 
{
	IMAGEMANAGER->AddImage("MAIN", "./Texture/sprites.jpg");
	mat = { 1, 1, 500, 300, 0, 30 };
	ATLASMANAGER->SetAtlas("JETA", "./txt/jeta.txt", "./Texture/jeta.png");
	pos = { 1, 1, 350, 350, 0, 0 };
}

void SMain::Update(double deltaTime)
{
}

void SMain::Render(double deltaTime)
{
	IMAGEMANAGER->DrawImage("MAIN", mat);

	if(INPUTMANAGER->IsKeyDown(VK_SPACE))
		IMAGEMANAGER->DrawAtlasImage("JETA", "JETAHURT", pos);
	else
		IMAGEMANAGER->DrawAtlasImage("JETA", "JETAHEAD", pos);
}

void SMain::Release()
{

}
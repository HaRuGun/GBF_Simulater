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
	mat = { 0, 0, 0, 0, 0, 0 };
}

void SMain::Update(double deltaTime)
{
}

void SMain::Render() 
{
	IMAGEMANAGER->DrawImage("MAIN", mat);
}

void SMain::Release()
{

}
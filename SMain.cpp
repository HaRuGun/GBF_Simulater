#include "stdafx.h"
#include "SMain.h"
#include "MColossusNormal.h"
#include "MainBattle.h"


SMain::SMain()
{
}

SMain::~SMain()
{
}

void SMain::Init() 
{
	mainBattle = new MainBattle;
	mainBattle->Init();
}

void SMain::Update(double deltaTime)
{
	mainBattle->Update(deltaTime);
	OBJECTMANAGER->Update(deltaTime);
}

void SMain::Render(double deltaTime)
{
	mainBattle->Render(deltaTime);
	OBJECTMANAGER->Render(deltaTime);
}

void SMain::Release()
{
	OBJECTMANAGER->Release();
}
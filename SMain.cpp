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
}

void SMain::Render(double deltaTime)
{
	mainBattle->Render(deltaTime);
}

void SMain::Release()
{

}
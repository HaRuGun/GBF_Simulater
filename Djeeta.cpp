#include "stdafx.h"
#include "Djeeta.h"
#include "Abillity.h"

void CDjeeta::Init()
{
	ATLASMANAGER->SetAtlas("Jeta", "./txt/Jeta.txt", "./Texture/Jeta.png");

	sName = "Djeeta";

	stat.tElement = WATER;
	stat.tType = CHARACTER;
	
	stat.fHp = 1000.0f;
	stat.fAtk = 3000.0f;
	stat.fCAGauge = 0.0f;

	stat.fDef = 50.0f;
	stat.fDARate = 15.0f;
	stat.fTARate = 5.0f;
	
	mat.direction = 0;
	mat.height = 1;
	mat.width = 1;
}

void CDjeeta::Update(double deltaTime)
{

}

void CDjeeta::Render(double deltaTime)
{
	IMAGEMANAGER->DrawAtlasImage("Jeta", "JetaSTAY", mat);
}

void CDjeeta::Release()
{
}

void CDjeeta::IdleAnime()
{
	if (frame.wCount >= 0 && frame.wCount <= 39)
	{

	}
	if (frame.wCount >= 50 && frame.wCount <= 89)
	{

	}
}

//

void AbEterBlast::AbillitySet()
{
	sName = "EterBlast";
	sDetail = "4x ~ 5x Damage to entire enemy";
	
	iCoolDown = 5;

}

void AbEterBlast::AbillityAct()
{
}

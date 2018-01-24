#include "stdafx.h"
#include "Djeeta.h"
#include "Abillity.h"

void CDjeeta::Init()
{
	sName = "Djeeta";

	stat.tElement = WATER;
	stat.tType = CHARACTER;
	
	stat.fHp = 1000.0f;
	stat.fAtk = 3000.0f;
	stat.fCAGauge = 0.0f;

	stat.fDef = 50.0f;
	stat.fDARate = 15.0f;
	stat.fTARate = 5.0f;
}

void CDjeeta::Update(double deltaTime)
{
}

void CDjeeta::Render(double deltaTime)
{
}

void CDjeeta::Release()
{
}

//

void AbEterBlast::AbillitySet()
{
	sName = "EterBlast";
	sDetail = "4x ~ 5x Damage to entire enemy";
	
	iCoolDown = 5;

}
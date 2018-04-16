#include "stdafx.h"
#include "MainBattle.h"


void MainBattle::Init()
{
	phase = READY;
	Boss = dynamic_cast<MColossusNormal*>(OBJECTMANAGER->AddObject(OBJECT_STATE::E_MONSTER, new MColossusNormal()));
	Boss->Init();
	character[0] = dynamic_cast<CDjeeta*>(OBJECTMANAGER->AddObject(OBJECT_STATE::M_CHARACTER, new CDjeeta(matrix(1000, 240))));

	jeetaSpawner = new SpawnerFor<CDjeeta>();

}

void MainBattle::Update(double deltaTime)
{
	switch (phase)
	{
	case READY:			PhaseReady();	break;
	case START_PHASE:	PhaseStart();	break;
	case ACTION_PHASE:	PhaseAction();	break;
	case ATTACK_PHASE:	PhaseAttack();	break;
	case ENEMY_PHASE:	PhaseEnemy();	break;
	case END_PHASE:		PhaseEnd();		break;
	case FINISH:		PhaseFinish();	break;
	}
}

void MainBattle::Render(double deltaTime)
{
	
}

void MainBattle::Release()
{
}


//


void MainBattle::PhaseReady()
{

}

void MainBattle::PhaseStart()
{

}

void MainBattle::PhaseAction()
{

}

void MainBattle::PhaseAttack()
{

}

void MainBattle::PhaseEnemy()
{

}

void MainBattle::PhaseEnd()
{

}

void MainBattle::PhaseFinish()
{

}
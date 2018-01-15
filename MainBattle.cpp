#include "stdafx.h"
#include "MainBattle.h"


void MainBattle::Init()
{
	phase = NONE;
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

void MainBattle::Render()
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

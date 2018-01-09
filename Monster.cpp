#include "stdafx.h"
#include "Monster.h"


void Monster::Init()
{
}

void Monster::Update(double deltaTime)
{
}

void Monster::Render()
{
}

void Monster::Release()
{
}

void Monster::AddDamage(Unit * unit, int damage)
{
	unitStatus *destTempStatus = unit->GetStat();
	if (Getelemental(*destTempStatus))
		stat.fHp -= damage * 1.3;
	else
		stat.fHp -= damage;
}

bool Monster::Getelemental(unitStatus stat)
{
	if (this->stat.tElement == WIND && stat.tElement == FIRE)
		return true;
	else if (this->stat.tElement == EARTH && stat.tElement == WATER)
		return true;
	else if (this->stat.tElement == WATER && stat.tElement == EARTH)
		return true;
	else if (this->stat.tElement == FIRE && stat.tElement == WIND)
		return true;
	else if (this->stat.tElement == LIGHT && stat.tElement == DARK)
		return true;
	else if (this->stat.tElement == DARK && stat.tElement == LIGHT)
		return true;
	else
		return false;
}

void Monster::EndTurn()
{
	iChGauge++;
}

void Monster::AttackPattern(Unit *unit)
{

}

void Monster::NomalAttack(Unit * unit)
{
	unitStatus 
	(unit, stat.fAtk - stat.fAtk * ((unit->GetStat()->fDef / 3) / 100));
}


Monster::Monster()
{
}


Monster::~Monster()
{
}

#pragma once
#include "Object.h"

enum TAG_ELEMENTAL
{
	FIRE = 0,
	WATER,
	EARTH,
	WIND,
	LIGHT,
	DARK
};

enum TYPE_UNIT
{
	CHARACTER = 0,
	MONSTER,
	BOSS
};

struct unitStatus
{
	//Visible
	TAG_ELEMENTAL tElement;
	TYPE_UNIT tType;
	float fHp, fAtk, fCAGauge;

	//Invisible
	float fDef;
	float fDARate, fTARate;
};

class Unit : public Object
{
protected:
	unitStatus stat;

public:
	unitStatus* GetStat() { return &stat; }
	void SetStat(unitStatus stat) { this->stat = stat; }

	Unit();
	virtual ~Unit();
};
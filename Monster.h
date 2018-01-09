#pragma once
#include "Unit.h"

class Monster : public Unit
{
private:
	int iChGauge;

public:
	virtual void Init();
	virtual void Update(double deltaTime);
	virtual void Render();
	virtual void Release();
	void AddDamage(Unit *unit, int damage);
	bool Getelemental(unitStatus stat);
	void EndTurn();
	void AttackPattern(Unit *unit);
	void NomalAttack(Unit *unit);

	Monster();
	virtual ~Monster();
};


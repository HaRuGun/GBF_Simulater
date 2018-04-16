#pragma once


enum MONSTER_ANIME_STATE
{
	M_IDLE,
	M_ATTACK,
	M_HURT
};

class Abillity;

class UMonster :
	public Unit
{
protected:
	string sName;

	Abillity* pAbillityArray[4];

	matrix mat;
	frameData frame;

	MONSTER_ANIME_STATE a_State;

public:
	virtual void Init() {}
	virtual void Update(double deltaTime) {}
	virtual void Render(double deltaTime) {}
	virtual void Release() {}

	virtual void IdleAnime() {}

	UMonster();
	virtual ~UMonster();
};


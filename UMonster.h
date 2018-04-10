#pragma once


class Abillity;

class UMonster :
	public Unit
{
protected:
	string sName;

	Abillity* pAbillityArray[4];

	matrix mat;
	frameData frame;

public:
	virtual void Init() {}
	virtual void Update(double deltaTime) {}
	virtual void Render(double deltaTime) {}
	virtual void Release() {}

	virtual void IdleAnime() {}

	UMonster();
	virtual ~UMonster();
};


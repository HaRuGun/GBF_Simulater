#pragma once
#include "Unit.h"

const int iTextureCount = 1;

enum CHARACTER_ANIME_STATE
{
	C_IDLE,
	C_ATTACK,
	C_HURT
};

class Abillity;

class UCharacter :
	public Unit
{
protected:
	string sName;

	Abillity* pAbillityArray[4];

	CHARACTER_ANIME_STATE a_State;

	string sTextureArray[iTextureCount];
	matrix mat;
	frameData frame;

public:
	virtual void Init() {}
	virtual void Update(double deltaTime) {}
	virtual void Render(double deltaTime) {}
	virtual void Release() {}

	void SetAnimeState(CHARACTER_ANIME_STATE _state) { a_State = _state; }

	virtual UCharacter *clone() = 0;
	virtual ~UCharacter() {}
};
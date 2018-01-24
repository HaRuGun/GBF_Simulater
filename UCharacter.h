#pragma once
#include "Unit.h"

const int iTextureCount = 1;

class Abillity;

class UCharacter :
	public Unit
{
protected:
	string sName;

	Abillity* pAbillityArray[4];

	string sTextureArray[iTextureCount];
	matrix mat;
	frameData frame;

public:
	virtual void Init() {}
	virtual void Update(double deltaTime) {}
	virtual void Render(double deltaTime) {}
	virtual void Release() {}

	UCharacter() {}
	virtual ~UCharacter() {}
};
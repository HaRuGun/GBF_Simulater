#pragma once
#include "UCharacter.h"
#include "Abillity.h"

class Abillity;

class CDjeeta :
	public UCharacter
{
protected:


public:
	void Init();
	void Update(double deltaTime);
	void Render();
	void Release();

	CDjeeta() {}
	virtual ~CDjeeta() {}
};

// Action Abill 1
class AbEterBlast
	: public Abillity
{
public:
	void AbillitySet();
	void AbillityAct();

	AbEterBlast() {}
	virtual ~AbEterBlast() {}
};
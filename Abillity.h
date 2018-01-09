#pragma once

class Abillity
{
protected:
	string sName;
	string sDetail;

	int iCoolDown; //Turn
	int iDebuffDuration; //Sec.
	int iBuffDuration; //Turn

public:
	virtual void AbillitySet() {}
	virtual void AbillityAct() {}

	Abillity() {}
	virtual ~Abillity() {}
};
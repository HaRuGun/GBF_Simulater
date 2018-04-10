#pragma once


class MColossusNormal : 
	public UMonster
{
private:
	matrix colbody;
	matrix colDeath;
	matrix colhead;
	matrix colLshoulder;
	matrix colRshoulder;
	matrix colRArm;
	matrix colHandle;
	matrix colRleg;
	matrix colLHand;
	matrix colSword;
	matrix colFoot;

public:
	void Init();
	void Update(double deltaTime);
	void Render(double deltaTime);
	void Release();

	void IdleAnime();

	MColossusNormal();
	virtual ~MColossusNormal();
};


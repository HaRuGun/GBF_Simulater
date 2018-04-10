#pragma once
#include "Scene.h"

class MainBattle;

class MColossusNormal;
class SMain : public Scene
{
protected:
	matrix mat;
	matrix pos;
	matrix move;
	MColossusNormal *mColossusNormal;
	MainBattle *mainBattle;

public:
	void Init();
	void Update(double deltaTime);
	void Render(double deltaTime);
	void Release();

	SMain();
	virtual ~SMain();
};


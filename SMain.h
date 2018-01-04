#pragma once
#include "Scene.h"

class SMain : public Scene
{
protected:
	matrix mat;

public:

	void Init();
	void Update(double deltaTime);
	void Render();
	void Release();

	SMain();
	virtual ~SMain();
};


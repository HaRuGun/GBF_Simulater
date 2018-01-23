#pragma once


class Scene
{
public:
	virtual void Init() {}
	virtual void Update(double deltaTime) {}
	virtual void Render(double deltaTime) {}
	virtual void Release() {}

	Scene() {}
	virtual ~Scene() {}
};


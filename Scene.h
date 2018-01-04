#pragma once


class Scene
{
public:
	virtual void Init() {}
	virtual void Update(double deltaTime) {}
	virtual void Render() {}
	virtual void Release() {}

	Scene() {}
	virtual ~Scene() {}
};


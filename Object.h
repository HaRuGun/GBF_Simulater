#pragma once

class Object
{
public:
	virtual void Init() {}
	virtual void Update(double deltaTime) {}
	virtual void Render(double deltaTime) {}
	virtual void Release() {}

	Object() {}
	virtual ~Object() {}
};
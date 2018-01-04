#pragma once

class Object
{
public:
	virtual void Init() {}
	virtual void Update(double deltaTime) {}
	virtual void Render() {}
	virtual void Release() {}

	Object() {}
	virtual ~Object() {}
};
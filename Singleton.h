#pragma once

template <typename T>
class Singleton
{
protected:
	static T* p;

public:
	static T* GetSingleton()
	{
		if (!p)
			p = new T;
		return p;
	}

	static void ReleaseSingleton()
	{
		if (p)
			delete p;
		p = nullptr;
	}

	Singleton() {}
	virtual ~Singleton() {}
};

template <typename T>
T * Singleton<T>::p = nullptr;
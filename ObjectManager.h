#pragma once


class ObjectManager : public Singleton<ObjectManager>
{
public:


	ObjectManager();
	virtual ~ObjectManager();
};

#define OBJECTMANAGER ObjectManager::GetSingleton()
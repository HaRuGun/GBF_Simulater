#pragma once

#define MAX_OBJECT_SIZE 7

enum OBJECT_STATE
{
	M_UNDER,
	M_BACKGROUND,
	E_MONSTER,
	M_CHARACTER,
	M_WEAPON,
	M_EFFECT,
	M_UI
};
class ObjectManager :
	public Singleton<ObjectManager>
{
private:
	map<OBJECT_STATE, vector<Object*>*> m_Object;
public:
	void Init();
	void Update(double deltaTime);
	void Render(double deltaTime);
	void Release();
	Object *AddObject(OBJECT_STATE state, Object *obj);
	vector<Object*> *Getv_Object(OBJECT_STATE state);

	ObjectManager();
	virtual ~ObjectManager();
};

#define OBJECTMANAGER ObjectManager::GetSingleton()
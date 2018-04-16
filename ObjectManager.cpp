#include "stdafx.h"



void ObjectManager::Init()
{
	for (int i = 0; i < MAX_OBJECT_SIZE; i++)
		m_Object.insert(make_pair(OBJECT_STATE(i), new vector<Object*>));
}

void ObjectManager::Update(double deltaTime)
{
	for (const auto &iter : m_Object)
	{
		for (const auto &_iter : *iter.second)
		{
			_iter->Update(deltaTime);
		}
	}
}

void ObjectManager::Render(double deltaTime)
{
	for (const auto &iter : m_Object)
	{
		for (const auto &_iter : *iter.second)
		{
			_iter->Render(deltaTime);
		}
	}
}

void ObjectManager::Release()
{
	for (auto iter : m_Object)
	{
		for (auto _iter : *iter.second)
		{
			SAFE_RELEASE(_iter);
			SAFE_DELETE(_iter);
		}
		iter.second->clear();
	}
	m_Object.clear();
}

Object * ObjectManager::AddObject(OBJECT_STATE state, Object *obj)
{
	auto iter = m_Object.find(state);
	if (iter == m_Object.end()) return nullptr;

	iter->second->push_back(obj);
	obj->Init();

	return obj;
}

vector<Object*>* ObjectManager::Getv_Object(OBJECT_STATE state)
{
	auto iter = m_Object.find(state);
	if (iter == m_Object.end()) return nullptr;


	return iter->second;
}

ObjectManager::ObjectManager()
{
	Init();
}


ObjectManager::~ObjectManager()
{
	Release();
}


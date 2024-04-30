#pragma once
#include <list>
#include <typeinfo>
#include <iostream>
#include <vector>
#include "main.h"
#include "game_object.h"
#include "camera.h"
#include "filed.h"
#include "Player.h"
#include "Polygon.h"
#include "box.h"
#include "enemy.h"
#include "wall.h"
#include "bullet.h"
#include "explosion.h"
#include "2dbox.h"
#include "Number.h"
#include "item.h"
#include "Fade.h"
#include "ebullet.h"
#include "3dpolygon.h"
#include "trap.h"
#include "pattern.h"
#define Object_Max 20
class CScene
{
protected:
	std::list<CGameObject*> m_GameObject[Object_Max];
	int TeleportCount;

	
public:
	CScene(){}
	virtual ~CScene(){}

	virtual void Init() = 0;


	virtual void Uninit()
	{
		for (int i = 0; i < Object_Max; i++)
		{
			for (CGameObject* object : m_GameObject[i])
			{
				object->Uninit();
				delete object;
			}
			m_GameObject[i].clear();
		}
		
		
		
		
		
		
		
		
	}

	virtual void Update()
	{
		for (int i = 0; i < Object_Max; i++)
		{
			for (CGameObject* object : m_GameObject[i])
			{
				object->Update();

			}


			m_GameObject[i].remove_if
			(
				[](CGameObject* object)
			{
				{return object->Destroy(); };
			}
			);
		}
	}

	virtual void Draw()
	{

		
		for (int i = 0; i < Object_Max; i++)
		{
			for (CGameObject* object : m_GameObject[i])
			{
				object->Transparent();

			}

		}
		for (int i = 0; i < Object_Max; i++)
		{
			for (CGameObject* object : m_GameObject[i])
			{
				object->Draw();
			}
		}
	}

	template <typename T>
	T* AddGameObject(int Layer)
	{
		T* gameObject = new T();
		m_GameObject[Layer].push_back(gameObject);
		gameObject->Init();

		return gameObject;
	}

	template <typename T>
	T* GetGameObject(int Layer)
	{
		for (CGameObject* object : m_GameObject[Layer])
		{
			if (typeid(*object) == typeid(T))
			{
				return (T*)object;
			}
		}
		return NULL;
	}

	

	template <typename T>
	std::vector<T*> GetGameObjects(int Layer)
	{
		std::vector<T*> objects;
		for (CGameObject* object : m_GameObject[Layer])
		{
			if (typeid(*object) == typeid(T))
			{
				objects.push_back((T*)object);
			}
		}
		return objects;
	}
};
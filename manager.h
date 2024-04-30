#pragma once
#include "scene.h"

class CManager
{
private:
	static class CScene* m_Scene;
	static bool Setting;
	static bool Pause;
	static int PauseCount;
public:
	CManager() {}
	~CManager() {}
	static void Init();
	static void Uninit();
	static void Update();
	static void Draw();
	static bool GetPause() { return Pause; }
	static class CScene* GetScene() { return m_Scene; }
	
	template <typename T>
	static void SetScene()
	{
		if (m_Scene != NULL)
		{
			m_Scene->Uninit();
			delete m_Scene;
		}
		T* scene = new T();
		m_Scene = scene;
		scene->Init();

	}

	template <typename T>
	static bool SceneGet()
	{
		if (typeid(*m_Scene) == typeid(T))
		{
			return true;
		}
		else
		{
			return false;
		}
	
	}

	/*template <typename T>
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
	}*/
};
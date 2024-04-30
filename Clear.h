#pragma once
#include "scene.h"
enum
{
	GOTITLE,
	GOEXIT
};
class CClear : public CScene
{
private:
	static bool GameExit;
	int SceneType;

public:
	void Init();
	void Update();
	void Uninit();
	static bool SetExit() { return GameExit; }
};
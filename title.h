#pragma once
#include "scene.h"
enum
{
	NULLL,
	STARTGAME,
	TUTORIAL,
	EXIT
};
class CTitle : public CScene
{
private:
	int SceneType;
	static bool GameExit;
public:
	void Init();
	void Update();
	void Uninit();
	static bool SetExit() { return GameExit; }
};
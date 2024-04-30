#pragma once
#include "scene.h"
enum
{
	STAGE3,
	STAGE4,
	STAGE5,
	STAGE6
};
class CStagebreak : public CScene
{
private:
	static int Stage;
	static int ChangeCount;
public:
	void Init();
	void Update();
	void Uninit();
	static void SaveStage(int index);
};
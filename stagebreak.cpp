#include "stage4.h"
#include "stage3.h"
#include "stage5.h"
#include "Stage6.h"
#include "Player.h"
#include "filed.h"
#include "camera.h"
#include "light.h"
#include "scene.h"
#include "input.h"
#include "manager.h"
#include "title.h"
#include "collision.h"
#include "sound.h"
#include "Grid.h"
#include "Polygon.h"
#include "Number.h"
#include "3dpolygon.h"
#include "stagebreak.h"
#include "skybox.h"
int CStagebreak::ChangeCount;
int CStagebreak::Stage;
void CStagebreak::Init()
{
	ChangeCount = 0;
	PatternReset();
	AddGameObject<CFade>(19)->CaeateFade();
	ResetCollision();
}

void CStagebreak::Update()
{
	CScene::Update();
	ChangeCount++;
	if (Stage == STAGE3)
	{
		if (ChangeCount > 10)
		{
			CPlayer::ResetPlayer(3);

			CManager::SetScene<CStage3>();
		}
	}
	if (Stage == STAGE4)
	{
		if (ChangeCount > 10)
		{
			CPlayer::ResetPlayer(4);

			CManager::SetScene<CStage4>();
		}
	}
	if (Stage == STAGE5)
	{
		if (ChangeCount > 10)
		{
			CPlayer::ResetPlayer(5);

			CManager::SetScene<CStage5>();
		}
	}
	if (Stage == STAGE6)
	{
		if (ChangeCount > 10)
		{
			CPlayer::ResetPlayer(6);

			CManager::SetScene<CStage6>();
		}
	}
}
void CStagebreak::Uninit()
{
	CScene::Uninit();
}
void CStagebreak::SaveStage(int index)
{
	Stage = index;
}
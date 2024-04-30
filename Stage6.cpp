#include "stage6.h"
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
#include "Rail.h"
#include "bullet.h"
#include "Clear.h"
#include "Grid.h"
#include "Polygon.h"
#include "Number.h"
#include "3dpolygon.h"
#include "stagebreak.h"
#include "skybox.h"
#include "warning.h"
void CStage6::Init()
{

	PatternReset();
	{//äÓñ{
		AddGameObject<CPlayer>(2);
		AddGameObject<CCamera>(0)->SetObject(D3DXVECTOR3(145.0f, 4.5f, 10.0f), D3DXVECTOR3(1.0f, 1.0f, 1.0f), TYPE_SETTING);
		AddGameObject<CPolygon>(12)->SetObject(D3DXVECTOR3(SCREEN_WIDTH *0.9f, SCREEN_HEIGHT *0.75f, 0.0f), D3DXVECTOR3(1.5f, 0.4f, 0.0f), SMALLGUN_UI_TEXTURE);
		AddGameObject<CPolygon>(12)->SetObject(D3DXVECTOR3(SCREEN_WIDTH *0.88f, SCREEN_HEIGHT *0.65f, 0.0f), D3DXVECTOR3(1.5f, 0.4f, 0.0f), SHOTGUN_UI_TEXTURE);
		AddGameObject<CPolygon>(12)->SetObject(D3DXVECTOR3(SCREEN_WIDTH *0.88f, SCREEN_HEIGHT *0.55f, 0.0f), D3DXVECTOR3(1.5f, 0.4f, 0.0f), RIPLEGUN_UI_TEXTURE);
		AddGameObject<CPolygon>(15)->SetObject(D3DXVECTOR3(SCREEN_WIDTH *0.87f, SCREEN_HEIGHT *0.77f, 0.0f), D3DXVECTOR3(3.0f, 1.3f, 0.0f), CURSOR_TEXTURE);
		AddGameObject<CPolygon>(11)->SetObject(D3DXVECTOR3(SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT *0.5f, 0.0f), D3DXVECTOR3(0.5f, 0.5f, 0.0f), AIM_TEXTURE);
		AddGameObject<CPolygon>(11)->SetObject(D3DXVECTOR3(SCREEN_WIDTH * 0.07f, SCREEN_HEIGHT *0.75f, 0.0f), D3DXVECTOR3(0.2f, 1.5f, 0.0f), HPGAGE_GRAY_TEXTURE);
		AddGameObject<CPolygon>(11)->SetObject(D3DXVECTOR3(SCREEN_WIDTH * 0.07f, SCREEN_HEIGHT *0.75f, 0.0f), D3DXVECTOR3(0.2f, 1.5f, 0.0f), HPGAGE_RED_TEXTURE);
		AddGameObject<CPolygon>(11)->SetObject(D3DXVECTOR3(SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT *0.05f, 0.0f), D3DXVECTOR3(1.0f, 0.5f, 0.0f), PAUSE_TEXTURE);


		AddGameObject<CNumber>(10)->SetTexture(HP_NUMBER, 3, D3DXVECTOR3(SCREEN_WIDTH * 0.0f, SCREEN_HEIGHT *0.825, 0.0f), D3DXVECTOR3(0.3f, 0.3f, 0.0f));
		AddGameObject<CNumber>(10)->SetTexture(BULLET_NUMBER, 2, D3DXVECTOR3(SCREEN_WIDTH *0.75f, SCREEN_HEIGHT *0.8f, 0.0f), D3DXVECTOR3(0.3f, 0.3f, 0.0f));
		AddGameObject<CNumber>(10)->SetTexture(MAX_BULLET_NUMBER, 3, D3DXVECTOR3(SCREEN_WIDTH *0.85f, SCREEN_HEIGHT *0.85f, 0.0f), D3DXVECTOR3(0.3f, 0.3f, 0.0f));
	}
	{//ï«
		{//ê^ÇÒíÜ
			AddGameObject<CWall>(6)->SetBrickWall(BEHIND_WALL, D3DXVECTOR3(140.0f, 5.0f, 0.0f), D3DXVECTOR3(10.0f, 5.0f, 1.0f));
			AddGameObject<CWall>(4)->SetBrickWall(LEFT_WALL, D3DXVECTOR3(140.0f, 5.0f, 0.0f), D3DXVECTOR3(1.0f, 5.0f, 30.0f));
			AddGameObject<CWall>(3)->SetBrickWall(RIGHT_WALL, D3DXVECTOR3(150.0f, 5.0f, 0.0f), D3DXVECTOR3(1.0f, 5.0f, 30.0f));

			AddGameObject<CWall>(6)->SetBrickWall(BEHIND_WALL, D3DXVECTOR3(130.0f, 5.0f, 30.0f), D3DXVECTOR3(10.0f, 5.0f, 1.0f));
			AddGameObject<CWall>(6)->SetBrickWall(BEHIND_WALL, D3DXVECTOR3(150.0f, 5.0f, 30.0f), D3DXVECTOR3(10.0f, 5.0f, 1.0f));
			AddGameObject<CWall>(4)->SetBrickWall(LEFT_WALL, D3DXVECTOR3(130.0f, 5.0f, 30.0f), D3DXVECTOR3(1.0f, 5.0f, 10.0f));
			AddGameObject<CWall>(3)->SetBrickWall(RIGHT_WALL, D3DXVECTOR3(160.0f, 5.0f, 30.0f), D3DXVECTOR3(1.0f, 5.0f, 10.0f));
			AddGameObject<CWall>(4)->SetBrickWall(LEFT_WALL, D3DXVECTOR3(130.0f, 5.0f, 50.0f), D3DXVECTOR3(1.0f, 5.0f, 10.0f));
			AddGameObject<CWall>(3)->SetBrickWall(RIGHT_WALL, D3DXVECTOR3(160.0f, 5.0f, 50.0f), D3DXVECTOR3(1.0f, 5.0f, 10.0f));
			AddGameObject<CWall>(5)->SetBrickWall(FRONT_WALL, D3DXVECTOR3(130.0f, 5.0f, 60.0f), D3DXVECTOR3(10.0f, 5.0f, 1.0f));
			AddGameObject<CWall>(5)->SetBrickWall(FRONT_WALL, D3DXVECTOR3(150.0f, 5.0f, 60.0f), D3DXVECTOR3(10.0f, 5.0f, 1.0f));

			AddGameObject<CWall>(4)->SetBrickWall(LEFT_WALL, D3DXVECTOR3(140.0f, 5.0f, 60.0f), D3DXVECTOR3(1.0f, 5.0f, 20.0f));
			AddGameObject<CWall>(3)->SetBrickWall(RIGHT_WALL, D3DXVECTOR3(150.0f, 5.0f, 60.0f), D3DXVECTOR3(1.0f, 5.0f, 20.0f));

			AddGameObject<CWall>(6)->SetBrickWall(BEHIND_WALL, D3DXVECTOR3(110.0f, 5.0f, 80.0f), D3DXVECTOR3(30.0f, 5.0f, 1.0f));
			AddGameObject<CWall>(6)->SetBrickWall(BEHIND_WALL, D3DXVECTOR3(150.0f, 5.0f, 80.0f), D3DXVECTOR3(30.0f, 5.0f, 1.0f));
			AddGameObject<CWall>(4)->SetBrickWall(LEFT_WALL, D3DXVECTOR3(110.0f, 5.0f, 80.0f), D3DXVECTOR3(1.0f, 5.0f, 70.0f));
			AddGameObject<CWall>(3)->SetBrickWall(RIGHT_WALL, D3DXVECTOR3(180.0f, 5.0f, 80.0f), D3DXVECTOR3(1.0f, 5.0f, 70.0f));
			AddGameObject<CWall>(5)->SetBrickWall(FRONT_WALL, D3DXVECTOR3(110.0f, 5.0f, 140.0f), D3DXVECTOR3(70.0f, 5.0f, 1.0f));

		}
		{//LeftFloor
			AddGameObject<CWall>(6)->SetBrickWall(BEHIND_WALL, D3DXVECTOR3(110.0f, 5.0f, 40.0f), D3DXVECTOR3(20.0f, 5.0f, 1.0f));
			AddGameObject<CWall>(5)->SetBrickWall(FRONT_WALL, D3DXVECTOR3(110.0f, 5.0f, 50.0f), D3DXVECTOR3(20.0f, 5.0f, 1.0f));

			AddGameObject<CWall>(3)->SetBrickWall(RIGHT_WALL, D3DXVECTOR3(110.0f, 5.0f, 30.0f), D3DXVECTOR3(1.0f, 5.0f, 10.0f));
			AddGameObject<CWall>(3)->SetBrickWall(RIGHT_WALL, D3DXVECTOR3(110.0f, 5.0f, 50.0f), D3DXVECTOR3(1.0f, 5.0f, 10.0f));

			AddGameObject<CWall>(6)->SetBrickWall(BEHIND_WALL, D3DXVECTOR3(80.0f, 5.0f, 30.0f), D3DXVECTOR3(30.0f, 5.0f, 1.0f));
			AddGameObject<CWall>(5)->SetBrickWall(FRONT_WALL, D3DXVECTOR3(79.5f, 5.0f, 60.0f), D3DXVECTOR3(30.0f, 5.0f, 1.0f));

			AddGameObject<CWall>(4)->SetBrickWall(LEFT_WALL, D3DXVECTOR3(80.0f, 5.0f, 30.0f), D3DXVECTOR3(1.0f, 5.0f, 10.0f));
			AddGameObject<CWall>(4)->SetBrickWall(LEFT_WALL, D3DXVECTOR3(80.0f, 5.0f, 50.0f), D3DXVECTOR3(1.0f, 5.0f, 10.0f));

			AddGameObject<CWall>(6)->SetBrickWall(BEHIND_WALL, D3DXVECTOR3(60.0f, 5.0f, 40.0f), D3DXVECTOR3(20.0f, 5.0f, 1.0f));
			AddGameObject<CWall>(5)->SetBrickWall(FRONT_WALL, D3DXVECTOR3(60.0f, 5.0f, 50.0f), D3DXVECTOR3(20.0f, 5.0f, 1.0f));

			AddGameObject<CWall>(3)->SetBrickWall(RIGHT_WALL, D3DXVECTOR3(60.0f, 5.0f, 20.0f), D3DXVECTOR3(1.0f, 5.0f, 20.0f));
			AddGameObject<CWall>(3)->SetBrickWall(RIGHT_WALL, D3DXVECTOR3(60.0f, 5.0f, 50.0f), D3DXVECTOR3(1.0f, 5.0f, 20.0f));

			AddGameObject<CWall>(6)->SetBrickWall(BEHIND_WALL, D3DXVECTOR3(20.0f, 5.0f, 20.0f), D3DXVECTOR3(40.0f, 5.0f, 1.0f));
			AddGameObject<CWall>(5)->SetBrickWall(FRONT_WALL, D3DXVECTOR3(20.0f, 5.0f, 70.0f), D3DXVECTOR3(40.0f, 5.0f, 1.0f));

			AddGameObject<CWall>(4)->SetBrickWall(LEFT_WALL, D3DXVECTOR3(20.0f, 5.0f, 20.0f), D3DXVECTOR3(1.0f, 5.0f, 50.0f));
		}
		{//RightFloor
			AddGameObject<CWall>(6)->SetBrickWall(BEHIND_WALL, D3DXVECTOR3(160.0f, 5.0f, 40.0f), D3DXVECTOR3(20.0f, 5.0f, 1.0f));
			AddGameObject<CWall>(5)->SetBrickWall(FRONT_WALL, D3DXVECTOR3(160.0f, 5.0f, 50.0f), D3DXVECTOR3(20.0f, 5.0f, 1.0f));

			AddGameObject<CWall>(4)->SetBrickWall(LEFT_WALL, D3DXVECTOR3(180.0f, 5.0f, 30.0f), D3DXVECTOR3(1.0f, 5.0f, 10.0f));
			AddGameObject<CWall>(4)->SetBrickWall(LEFT_WALL, D3DXVECTOR3(180.0f, 5.0f, 50.0f), D3DXVECTOR3(1.0f, 5.0f, 10.0f));

			AddGameObject<CWall>(6)->SetBrickWall(BEHIND_WALL, D3DXVECTOR3(180.0f, 5.0f, 30.0f), D3DXVECTOR3(30.0f, 5.0f, 1.0f));
			AddGameObject<CWall>(5)->SetBrickWall(FRONT_WALL, D3DXVECTOR3(180.0f, 5.0f, 60.0f), D3DXVECTOR3(30.0f, 5.0f, 1.0f));

			AddGameObject<CWall>(3)->SetBrickWall(RIGHT_WALL, D3DXVECTOR3(210.0f, 5.0f, 30.0f), D3DXVECTOR3(1.0f, 5.0f, 10.0f));
			AddGameObject<CWall>(3)->SetBrickWall(RIGHT_WALL, D3DXVECTOR3(210.0f, 5.0f, 50.0f), D3DXVECTOR3(1.0f, 5.0f, 10.0f));

			AddGameObject<CWall>(6)->SetBrickWall(BEHIND_WALL, D3DXVECTOR3(210.0f, 5.0f, 40.0f), D3DXVECTOR3(20.0f, 5.0f, 1.0f));
			AddGameObject<CWall>(5)->SetBrickWall(FRONT_WALL, D3DXVECTOR3(210.0f, 5.0f, 50.0f), D3DXVECTOR3(20.0f, 5.0f, 1.0f));

			AddGameObject<CWall>(4)->SetBrickWall(LEFT_WALL, D3DXVECTOR3(230.0f, 5.0f, 20.0f), D3DXVECTOR3(1.0f, 5.0f, 20.0f));
			AddGameObject<CWall>(4)->SetBrickWall(LEFT_WALL, D3DXVECTOR3(230.0f, 5.0f, 50.0f), D3DXVECTOR3(1.0f, 5.0f, 20.0f));

			AddGameObject<CWall>(6)->SetBrickWall(BEHIND_WALL, D3DXVECTOR3(230.0f, 5.0f, 20.0f), D3DXVECTOR3(40.0f, 5.0f, 1.0f));
			AddGameObject<CWall>(5)->SetBrickWall(FRONT_WALL, D3DXVECTOR3(230.0f, 5.0f, 70.0f), D3DXVECTOR3(40.0f, 5.0f, 1.0f));

			AddGameObject<CWall>(3)->SetBrickWall(RIGHT_WALL, D3DXVECTOR3(270.0f, 5.0f, 20.0f), D3DXVECTOR3(1.0f, 5.0f, 50.0f));

		}
	}
	{//Filed
		AddGameObject<CField>(8)->SetField(D3DXVECTOR3(10.0f, 2.5f, -10.0f), D3DXVECTOR3(270.0f, 0.5f, 160.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 1.0f);
	}
	{//Ceiling
		AddGameObject<CField>(1)->SetField(D3DXVECTOR3(280.0f, 7.5f, -10.0f), D3DXVECTOR3(270.0f, 0.5f, 160.0f), D3DXVECTOR3(0.0f, 0.0f, D3DXToRadian(180.0f)), -1.0f, CEILING);
	}
	{//Pattern
		AddGameObject<C3dpolygon>(7)->SetObject(D3DXVECTOR3(145.5f, 3.0f, 25.0f), D3DXVECTOR3(0.35f, 0.35f, 0.35f), BAZOOKA_POLYGON);
		AddGameObject<C3dpolygon>(1)->SetObject(D3DXVECTOR3(145.5f, 4.5f, 61.0f), D3DXVECTOR3(4.0f, 2.0f, 2.0f), DOOR_1);
		AddGameObject<C3dpolygon>(2)->SetObject(D3DXVECTOR3(145.5f, 4.5f, 71.0f), D3DXVECTOR3(4.0f, 2.0f, 2.0f), DOOR_2);
		AddGameObject<C3dpolygon>(3)->SetObject(D3DXVECTOR3(145.5f, 3.5f, 110.0f), D3DXVECTOR3(0.4f, 0.2f, 0.4f), CROWN_POLYGON);


	}
	{//Trap
		//AddGameObject<CTrap>(5)->SetObject(D3DXVECTOR3(120.0f, 3.5f, 40.0f), D3DXVECTOR3(1.0f, 1.0f, 3.0f), SPIKE, D3DXVECTOR3(0.0f, 0.0f, 0.0f));
		//AddGameObject<CTrap>(5)->SetObject(D3DXVECTOR3(120.0f, 3.5f, 43.0f), D3DXVECTOR3(1.0f, 1.0f, 3.0f), SPIKE, D3DXVECTOR3(0.0f, 0.0f, 0.0f));
		//AddGameObject<CTrap>(5)->SetObject(D3DXVECTOR3(120.0f, 3.5f, 46.0f), D3DXVECTOR3(1.0f, 1.0f, 3.0f), SPIKE, D3DXVECTOR3(0.0f, 0.0f, 0.0f));
		//AddGameObject<CTrap>(5)->SetObject(D3DXVECTOR3(120.0f, 3.5f, 49.0f), D3DXVECTOR3(1.0f, 1.0f, 3.0f), SPIKE, D3DXVECTOR3(0.0f, 0.0f, 0.0f));
		//
		//AddGameObject<CTrap>(5)->SetObject(D3DXVECTOR3(70.0f, 3.5f, 40.0f), D3DXVECTOR3(1.0f, 1.0f, 3.0f), SPIKE, D3DXVECTOR3(0.0f, 0.0f, 0.0f));
		//AddGameObject<CTrap>(5)->SetObject(D3DXVECTOR3(70.0f, 3.5f, 43.0f), D3DXVECTOR3(1.0f, 1.0f, 3.0f), SPIKE, D3DXVECTOR3(0.0f, 0.0f, 0.0f));
		//AddGameObject<CTrap>(5)->SetObject(D3DXVECTOR3(70.0f, 3.5f, 46.0f), D3DXVECTOR3(1.0f, 1.0f, 3.0f), SPIKE, D3DXVECTOR3(0.0f, 0.0f, 0.0f));
		//AddGameObject<CTrap>(5)->SetObject(D3DXVECTOR3(70.0f, 3.5f, 49.0f), D3DXVECTOR3(1.0f, 1.0f, 3.0f), SPIKE, D3DXVECTOR3(0.0f, 0.0f, 0.0f));
		//
		//AddGameObject<CTrap>(6)->SetObject(D3DXVECTOR3(167.0f, 4.0f, 45.0f), D3DXVECTOR3(1.0f, 0.3f, 0.3f), Z_TRAP, D3DXVECTOR3(0.0f, D3DXToRadian(90.0f), 0.0f));
		//AddGameObject<CTrap>(6)->SetObject(D3DXVECTOR3(170.0f, 4.0f, 45.0f), D3DXVECTOR3(1.0f, 0.3f, 0.3f), Z_TRAP, D3DXVECTOR3(0.0f, D3DXToRadian(90.0f), 0.0f));
		//AddGameObject<CTrap>(6)->SetObject(D3DXVECTOR3(173.0f, 4.0f, 45.0f), D3DXVECTOR3(1.0f, 0.3f, 0.3f), Z_TRAP, D3DXVECTOR3(0.0f, D3DXToRadian(90.0f), 0.0f));
		//
		//AddGameObject<CTrap>(6)->SetObject(D3DXVECTOR3(217.0f, 4.0f, 45.0f), D3DXVECTOR3(1.0f, 0.3f, 0.3f), Z_TRAP, D3DXVECTOR3(0.0f, D3DXToRadian(90.0f), 0.0f));
		//AddGameObject<CTrap>(6)->SetObject(D3DXVECTOR3(220.0f, 4.0f, 45.0f), D3DXVECTOR3(1.0f, 0.3f, 0.3f), Z_TRAP, D3DXVECTOR3(0.0f, D3DXToRadian(90.0f), 0.0f));
		//AddGameObject<CTrap>(6)->SetObject(D3DXVECTOR3(223.0f, 4.0f, 45.0f), D3DXVECTOR3(1.0f, 0.3f, 0.3f), Z_TRAP, D3DXVECTOR3(0.0f, D3DXToRadian(90.0f), 0.0f));
	}
	{//Item
		AddGameObject<CItem>(9)->SetObject(D3DXVECTOR3(145.0f, 4.0f, 65.0f), D3DXVECTOR3(0.5f, 0.5f, 1.2f), TYPE_ITEM_HEART);
		AddGameObject<CItem>(9)->SetObject(D3DXVECTOR3(55.0f, 4.0f, 55.0f), D3DXVECTOR3(0.5f, 0.5f, 1.2f), TYPE_ITEM_HEART);
		AddGameObject<CItem>(9)->SetObject(D3DXVECTOR3(235.0f, 4.0f, 55.0f), D3DXVECTOR3(0.5f, 0.5f, 1.2f), TYPE_ITEM_HEART);

		AddGameObject<CItem>(9)->SetObject(D3DXVECTOR3(85.0f, 4.0f, 35.0f), D3DXVECTOR3(0.5f, 0.5f, 1.2f), TYPE_ITEM_BULLET);
		AddGameObject<CItem>(9)->SetObject(D3DXVECTOR3(85.0f, 4.0f, 55.0f), D3DXVECTOR3(0.5f, 0.5f, 1.2f), TYPE_ITEM_BULLET);

		AddGameObject<CItem>(9)->SetObject(D3DXVECTOR3(205.0f, 4.0f, 35.0f), D3DXVECTOR3(0.5f, 0.5f, 1.2f), TYPE_ITEM_BULLET);
		AddGameObject<CItem>(9)->SetObject(D3DXVECTOR3(205.0f, 4.0f, 55.0f), D3DXVECTOR3(0.5f, 0.5f, 1.2f), TYPE_ITEM_BULLET);
		AddGameObject<CItem>(9)->SetObject(D3DXVECTOR3(145.0f, 4.0f, 75.0f), D3DXVECTOR3(0.5f, 0.5f, 1.2f), TYPE_ITEM_BULLET);

	}
	AddGameObject<CFade>(19)->CaeateFade();
	StopSound();
	PlaySoundA(SOUND_LABEL_STAGE6_BGM);
}

void CStage6::Update()
{
	Collision_Update();

	CScene::Update();

	Pattern_Update();

	CFade* Fade = CManager::GetScene()->GetGameObject<CFade>(19);
	Fade->SetFadeOut();
	ShowCursor(false);
	SetCursorPos(1920 / 2, 1080 / 2);
	CCamera* Camera = CManager::GetScene()->GetGameObject<CCamera>(0);
	CScene* scene = CManager::GetScene();
	CPlayer* Player = CManager::GetScene()->GetGameObject<CPlayer>(2);

	if (Player->GetPlayerHp() <= 0)
	{
		Fade->SetFadeIn();
		if (Fade->GetFade() >= 1.0f)
		{
			CManager::SetScene<CStagebreak>();
			CStagebreak::SaveStage(STAGE6);

		}
	}
	if (Camera->GetTeleport() && Player->GetPlayerHp() > 0)
	{
		TeleportCount++;
		if (TeleportCount == 1)
		{
			scene->AddGameObject<CExplosion>(8)->SetTexture(CREATE_EFFECT, CREATE_EFFECT_X, CREATE_EFFECT_Y, Camera->GetPosition() + (Camera->GetFrontVec() * 2.0f), D3DXVECTOR3(15.0f, 10.0f, 0.0f));
			PlaySoundA(SOUND_LABEL_SE_SUMMONING);

		}
		if (TeleportCount == 70)
		{
			Fade->SetFadeIn();
		}
		if (Fade->GetFade() >= 1.0f)
		{
			ResetCollision();

			CManager::SetScene<CClear>();
		}
	}


}

void CStage6::Uninit()
{
	CScene::Uninit();
	
}
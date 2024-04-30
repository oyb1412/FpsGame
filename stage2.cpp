#include "stage2.h"
#include "stage1.h"
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
void CStage2::Init()
{
	//CItem::Load();
	//CExplosion::Load();
	//CNumber::Load();
	//CEnemy::Load();
	//CEbullet::Load();
	//CTrap::Load();
	//C3dpolygon::Load();
	//CFade::Load();
	//TeleportCount = 0;
	//AddGameObject<CCamera>(0)->SetObject(D3DXVECTOR3(150.0f, 4.5f, 170.0f), D3DXVECTOR3(1.0f, 1.0f, 1.0f));
	////AddGameObject<CCamera>(0)->SetObject(D3DXVECTOR3(230.0f, 4.5f, 40.0f), D3DXVECTOR3(1.0f, 1.0f, 1.0f));

	//AddGameObject<CField>(1)->SetField(D3DXVECTOR3(300.0f, 0.0f, 50.0f), D3DXVECTOR3(20.0f, 0.5f, 25.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 1.0f);
	//AddGameObject<CField>(1)->SetField(D3DXVECTOR3(300.0f, 10.0f, 50.0f), D3DXVECTOR3(20.0f, 0.5f, 25.0f), D3DXVECTOR3(D3DXToRadian(180.0f), 0.0f, 0.0f), -1.0f);

	//AddGameObject<CPlayer>(2);

	//




	//{//Å®
	//	//AddGameObject<CWall>(3)->SetWall(D3DXVECTOR3(-60.0f, 5.0f, -250.0f), D3DXVECTOR3(3.0f, 5.0f, 50.0f), D3DXVECTOR3(-58.0f, 5.0f, -250.0f));
	//	//AddGameObject<CWall>(3)->SetWall(D3DXVECTOR3(-60.0f, 5.0f, 45.0f), D3DXVECTOR3(3.0f, 5.0f, 50.0f), D3DXVECTOR3(-58.0f, 5.0f, 45.0f));
	//	AddGameObject<CWall>(3)->SetWall(RIGHT_WALL, D3DXVECTOR3(230.0f, 5.0f, 245.0f), D3DXVECTOR3(3.0f, 5.0f, 50.0f));
	//	AddGameObject<CWall>(3)->SetWall(RIGHT_WALL, D3DXVECTOR3(380.0f, 5.0f, 225.0f), D3DXVECTOR3(3.0f, 5.0f, 100.0f));
	//	AddGameObject<CWall>(3)->SetWall(RIGHT_WALL, D3DXVECTOR3(230.0f, 5.0f, 100.0f), D3DXVECTOR3(3.0f, 5.0f, 55.0f));
	//	AddGameObject<CWall>(3)->SetWall(RIGHT_WALL, D3DXVECTOR3(450.0f, 5.0f, 35.0f), D3DXVECTOR3(3.0f, 5.0f, 50.0f));

	//}
	//{//Å©

	//	//AddGameObject<CWall>(4)->SetWall(D3DXVECTOR3(-95.0f, 5.0f, -50.0f), D3DXVECTOR3(3.0f, 5.0f, 250.0f), D3DXVECTOR3(-97.0f, 5.0f, -50.0f));
	//	//AddGameObject<CWall>(4)->SetWall(D3DXVECTOR3(60.0f, 5.0f, -100.0f), D3DXVECTOR3(3.0f, 5.0f, 50.0f), D3DXVECTOR3(58.0f, 5.0f, -100.0f));
	//	AddGameObject<CWall>(4)->SetWall(LEFT_WALL, D3DXVECTOR3(200.0f, 5.0f, 245.0f), D3DXVECTOR3(3.0f, 5.0f, 50.0f));
	//	AddGameObject<CWall>(4)->SetWall(LEFT_WALL, D3DXVECTOR3(330.0f, 5.0f, 245.0f), D3DXVECTOR3(3.0f, 5.0f, 50.0f));
	//	AddGameObject<CWall>(4)->SetWall(LEFT_WALL, D3DXVECTOR3(200.0f, 5.0f, 75.0f), D3DXVECTOR3(3.0f, 5.0f, 80.0f));
	//	AddGameObject<CWall>(4)->SetWall(LEFT_WALL, D3DXVECTOR3(130.0f, 5.0f, 170.0f), D3DXVECTOR3(3.0f, 5.0f, 50.0f));

	//}
	//{//ëO

	//	//AddGameObject<CWall>(5)->SetWall(D3DXVECTOR3(0.0f, 5.0f, 195.0f), D3DXVECTOR3(100.0f, 5.0f, 3.0f), D3DXVECTOR3(0.0f, 5.0f, 197.0f));
	//	//AddGameObject<CWall>(5)->SetWall(D3DXVECTOR3(-20.0f, 5.0f, -150.0f), D3DXVECTOR3(80.0f, 5.0f, 3.0f), D3DXVECTOR3(-20.0f, 5.0f, -148.0f));
	//	//AddGameObject<CWall>(5)->SetWall(D3DXVECTOR3(20.0f, 5.0f, -5.0f), D3DXVECTOR3(80.0f, 5.0f, 3.0f), D3DXVECTOR3(20.0f, 5.0f, -3.0f));
	//	AddGameObject<CWall>(5)->SetWall(FRONT_WALL, D3DXVECTOR3(150.0f, 5.0f, 195.0f), D3DXVECTOR3(50.0f, 5.0f, 3.0f));
	//	AddGameObject<CWall>(5)->SetWall(FRONT_WALL, D3DXVECTOR3(240.0f, 5.0f, 290.0f), D3DXVECTOR3(50.0f, 5.0f, 3.0f));
	//	AddGameObject<CWall>(5)->SetWall(FRONT_WALL, D3DXVECTOR3(280.0f, 5.0f, 195.0f), D3DXVECTOR3(50.0f, 5.0f, 3.0f));
	//	AddGameObject<CWall>(5)->SetWall(FRONT_WALL, D3DXVECTOR3(350.0f, 5.0f, 290.0f), D3DXVECTOR3(50.0f, 5.0f, 3.0f));
	//	AddGameObject<CWall>(5)->SetWall(FRONT_WALL, D3DXVECTOR3(380.0f, 5.0f, 50.0f), D3DXVECTOR3(150.0f, 5.0f, 3.0f));


	//}
	//{//å„
	//	//AddGameObject<CWall>(6)->SetWall(D3DXVECTOR3(20.0f, 5.0f, -200.0f), D3DXVECTOR3(80.0f, 5.0f, 3.0f), D3DXVECTOR3(20.0f, 5.0f, -202.0f));
	//	//AddGameObject<CWall>(6)->SetWall(D3DXVECTOR3(-20.0f, 5.0f, -50.0f), D3DXVECTOR3(80.0f, 5.0f, 3.0f), D3DXVECTOR3(-20.0f, 5.0f, -52.0f));
	//	//AddGameObject<CWall>(6)->SetWall(D3DXVECTOR3(20.0f, 5.0f, 95.0f), D3DXVECTOR3(80.0f, 5.0f, 3.0f), D3DXVECTOR3(20.0f, 5.0f, 93.0f));
	//	//AddGameObject<CWall>(6)->SetWall(D3DXVECTOR3(-80.0f, 5.0f, -295.0f), D3DXVECTOR3(20.0f, 5.0f, 3.0f), D3DXVECTOR3(-80.0f, 5.0f, -297.0f));
	//	AddGameObject<CWall>(6)->SetWall(BEHIND_WALL,D3DXVECTOR3(150.0f, 5.0f, 155.0f), D3DXVECTOR3(50.0f, 5.0f, 3.0f));
	//	AddGameObject<CWall>(6)->SetWall(BEHIND_WALL,D3DXVECTOR3(380.0f, 5.0f, 155.0f), D3DXVECTOR3(150.0f, 5.0f, 3.0f));
	//	AddGameObject<CWall>(6)->SetWall(BEHIND_WALL,D3DXVECTOR3(380.0f, 5.0f,10.0f), D3DXVECTOR3(200.0f, 5.0f, 3.0f));


	//}

	//AddGameObject<CTrap>(9)->SetObject(D3DXVECTOR3(250.0f, 4.0f, 15.0f), D3DXVECTOR3(3.0f, 1.0f, 1.0f), Z_TRAP);
	//AddGameObject<CTrap>(9)->SetObject(D3DXVECTOR3(270.0f, 4.0f, 25.0f), D3DXVECTOR3(3.0f, 1.0f, 1.0f), Z_TRAP);
	//AddGameObject<CTrap>(9)->SetObject(D3DXVECTOR3(290.0f, 4.0f, 35.0f), D3DXVECTOR3(3.0f, 1.0f, 1.0f), Z_TRAP);

	//AddGameObject<CTrap>(9)->SetObject(D3DXVECTOR3(350.0f, 4.0f, 40.0f), D3DXVECTOR3(3.0f, 1.0f, 1.0f), Z_TRAP);
	//AddGameObject<CTrap>(9)->SetObject(D3DXVECTOR3(370.0f, 4.0f, 30.0f), D3DXVECTOR3(3.0f, 1.0f, 1.0f), Z_TRAP);
	//AddGameObject<CTrap>(9)->SetObject(D3DXVECTOR3(390.0f, 4.0f, 20.0f), D3DXVECTOR3(3.0f, 1.0f, 1.0f), Z_TRAP);
	//

	//AddGameObject<CNumber>(10)->SetTexture(BULLET_NUMBER, 2, D3DXVECTOR3(1300.0f, 850.0f, 0.0f), D3DXVECTOR3(0.5f, 0.5f, 0.0f));
	//AddGameObject<CNumber>(10)->SetTexture(MAX_BULLET_NUMBER, 3, D3DXVECTOR3(1530.0f, 900.0f, 0.0f), D3DXVECTOR3(0.5f, 0.5f, 0.0f));
	//AddGameObject<CNumber>(10)->SetTexture(HP_NUMBER, 3, D3DXVECTOR3(0.0f, 875.0f, 0.0f), D3DXVECTOR3(0.5f, 0.5f, 0.0f));

	//AddGameObject<CPolygon>(11)->SetObject(D3DXVECTOR3(SCREEN_WIDTH / 2 - 50, SCREEN_HEIGHT / 2 - 50, 0.0f), D3DXVECTOR3(0.5f, 0.5f, 0.0f), AIM_TEXTURE);

	//AddGameObject<CPolygon>(12)->SetObject(D3DXVECTOR3(SCREEN_WIDTH / 2 + 40, SCREEN_HEIGHT / 2 - 180, 0.0f), D3DXVECTOR3(4.5f, 2.5f, 0.0f), SMALLGUN_UI_TEXTURE);


	//AddGameObject<CPolygon>(15)->SetObject(D3DXVECTOR3(SCREEN_WIDTH / 2 + 240, SCREEN_HEIGHT / 2 - 20, 0.0f), D3DXVECTOR3(4.2f, 1.3f, 0.0f), CURSOR_TEXTURE);

	//AddGameObject<CPolygon>(16)->SetObject(D3DXVECTOR3(SCREEN_WIDTH / 2 + 490, SCREEN_HEIGHT / 2 + 210, 0.0f), D3DXVECTOR3(2.5f, 0.2f, 0.0f), RIFLEGUN_IMPOSSIBLE_TEXTURE);
	//
	//AddGameObject<C3dpolygon>(5)->SetObject(D3DXVECTOR3(215.0f, 0.0f, 195.0f), D3DXVECTOR3(0.15f, 0.05f, 0.3f), EXIT_DOOR);
	//AddGameObject<C3dpolygon>(6)->SetObject(D3DXVECTOR3(215.0f, 0.0f, 155.0f), D3DXVECTOR3(0.15f, 0.05f, 0.3f), TOOL_DOOR);
	//AddGameObject<C3dpolygon>(7)->SetObject(D3DXVECTOR3(420.0f, 2.0f, 30.0f), D3DXVECTOR3(1.5f, 1.05f, 1.5f), RIFLEGUN_POLYGON);

	//AddGameObject<CPattern>(2)->SetObject(D3DXVECTOR3(160.0f, 2.0f, 180.0f), D3DXVECTOR3(3.0f, 5.0f, 30.0f), PATTERN_TWO);
	//AddGameObject<CPattern>(3)->SetObject(D3DXVECTOR3(280.0f, 2.0f, 180.0f), D3DXVECTOR3(3.0f, 5.0f, 30.0f), PATTERN_THREE);
	//AddGameObject<CPattern>(4)->SetObject(D3DXVECTOR3(220.0f, 2.0f, 215.0f), D3DXVECTOR3(40.0f, 5.0f, 3.0f), PATTERN_FOUR);

	//AddGameObject<CFade>(19)->CaeateFade();
	//PlaySoundA(SOUND_LABEL_STAGE2_BGM);

}

void CStage2::Update()
{
	CScene::Update();
	ShowCursor(false);
	SetCursorPos(1920 / 2, 1080 / 2);
	Collision_Update();
	CFade* Fade = CManager::GetScene()->GetGameObject<CFade>(19);
	Fade->SetFadeOut();
	CCamera* Camera = CManager::GetScene()->GetGameObject<CCamera>(0);
	CScene* scene = CManager::GetScene();

	if (Camera->GetTeleport())
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
			CManager::SetScene<CStage1>();
		}
	}

}

void CStage2::Uninit()
{
	CExplosion::Unload();
	CNumber::Unload();
	CEnemy::Unload();
	CItem::Unload();
	CFade::Unload();
	CEbullet::Unload();
	CTrap::Unload();
	C3dpolygon::Unload();
}
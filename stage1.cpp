#include "stage1.h"
#include "stage2.h"
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
void CStage1::Init()
{
	/*CItem::Load();
	CExplosion::Load();
	CNumber::Load();
	CEnemy::Load();
	CEbullet::Load();
	CTrap::Load();
	CFade::Load();
	C3dpolygon::Load();
	TeleportCount = 0;*/
	AddGameObject<CCamera>(0)->SetObject(D3DXVECTOR3(-80.0f, 4.5f, -275.0f), D3DXVECTOR3(1.0f, 1.0f, 1.0f));
	//AddGameObject<CCamera>(0)->SetObject(D3DXVECTOR3(-90.0f, 4.5f, 140.0f), D3DXVECTOR3(1.0f, 1.0f, 1.0f));
	AddGameObject<CGrid>(1)->SetObject(D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(1.0f, 1.0f, 1.0f));

	//AddGameObject<CField>(1)->SetField(D3DXVECTOR3(0.0f, 0.0f, -50.0f), D3DXVECTOR3(10.0f, 0.5f, 25.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 1.0f);
	//AddGameObject<CField>(1)->SetField(D3DXVECTOR3(0.0f, 10.0f, -50.0f), D3DXVECTOR3(10.0f, 0.5f, 25.0f), D3DXVECTOR3(D3DXToRadian(180.0f), 0.0f, 0.0f), -1.0f);


	//AddGameObject<CPlayer>(2);

	//AddGameObject<CPattern>(1)->SetObject(D3DXVECTOR3(-60.0f, 5.0f, 145.0f), D3DXVECTOR3(3.0f, 5.0f, 50.0f), PATTERN_ONE);

	//AddGameObject<C3dpolygon>(5)->SetObject(D3DXVECTOR3(-77.0f, 10.0f, 90.0f), D3DXVECTOR3(0.15f, 0.05f, 0.3f), PATTERNONE_POLYGON);

	//{//Å®
	//	AddGameObject<CWall>(3)->SetWall(RIGHT_WALL,D3DXVECTOR3(-60.0f, 5.0f, -250.0f), D3DXVECTOR3(3.0f, 5.0f, 50.0f));
	//	AddGameObject<CWall>(3)->SetWall(RIGHT_WALL, D3DXVECTOR3(-60.0f, 5.0f, 45.0f), D3DXVECTOR3(3.0f, 5.0f, 50.0f));
	//	AddGameObject<CWall>(3)->SetWall(RIGHT_WALL, D3DXVECTOR3(97.0f, 5.0f, -50.0f), D3DXVECTOR3(3.0f, 5.0f, 250.0f));

	//}
	//{//Å©

	//	AddGameObject<CWall>(4)->SetWall(LEFT_WALL, D3DXVECTOR3(-95.0f, 5.0f, -50.0f), D3DXVECTOR3(3.0f, 5.0f, 250.0f));
	//	AddGameObject<CWall>(4)->SetWall(LEFT_WALL, D3DXVECTOR3(60.0f, 5.0f, -100.0f), D3DXVECTOR3(3.0f, 5.0f, 50.0f));

	//}
	//{//ëO

	//	AddGameObject<CWall>(5)->SetWall(FRONT_WALL, D3DXVECTOR3(0.0f, 5.0f, 195.0f), D3DXVECTOR3(100.0f, 5.0f, 3.0f));
	//	AddGameObject<CWall>(5)->SetWall(FRONT_WALL, D3DXVECTOR3(-20.0f, 5.0f, -150.0f), D3DXVECTOR3(80.0f, 5.0f, 3.0f));
	//	AddGameObject<CWall>(5)->SetWall(FRONT_WALL, D3DXVECTOR3(20.0f, 5.0f, -5.0f), D3DXVECTOR3(80.0f, 5.0f, 3.0f));


	//}
	//{//å„
	//	AddGameObject<CWall>(6)->SetWall(BEHIND_WALL,D3DXVECTOR3(20.0f, 5.0f, -200.0f), D3DXVECTOR3(80.0f, 5.0f, 3.0f));
	//	AddGameObject<CWall>(6)->SetWall(BEHIND_WALL, D3DXVECTOR3(-20.0f, 5.0f, -50.0f), D3DXVECTOR3(80.0f, 5.0f, 3.0f));
	//	AddGameObject<CWall>(6)->SetWall(BEHIND_WALL, D3DXVECTOR3(20.0f, 5.0f, 95.0f), D3DXVECTOR3(80.0f, 5.0f, 3.0f));
	//	AddGameObject<CWall>(6)->SetWall(BEHIND_WALL, D3DXVECTOR3(-80.0f, 5.0f, -295.0f), D3DXVECTOR3(20.0f, 5.0f, 3.0f));


	//}
	//AddGameObject<CTrap>(8)->SetObject(D3DXVECTOR3(75.0f, 4.0f, -140.0f), D3DXVECTOR3(3.0f, 1.0f, 1.0f), X_TRAP, D3DXVECTOR3(0.0f, D3DXToRadian(90.0f), 0.0f));
	//AddGameObject<CTrap>(8)->SetObject(D3DXVECTOR3(95.0f, 4.0f, -130.0f), D3DXVECTOR3(3.0f, 1.0f, 1.0f), X_TRAP, D3DXVECTOR3(0.0f, D3DXToRadian(90.0f), 0.0f));

	//AddGameObject<CTrap>(8)->SetObject(D3DXVECTOR3(95.0f, 4.0f, -70.0f), D3DXVECTOR3(3.0f, 1.0f, 1.0f), X_TRAP, D3DXVECTOR3(0.0f, D3DXToRadian(90.0f), 0.0f));
	//AddGameObject<CTrap>(8)->SetObject(D3DXVECTOR3(75.0f, 4.0f, -60.0f), D3DXVECTOR3(3.0f, 1.0f, 1.0f), X_TRAP, D3DXVECTOR3(0.0f, D3DXToRadian(90.0f), 0.0f));

	//AddGameObject<CTrap>(8)->SetObject(D3DXVECTOR3(-60.0f, 4.0f, 10.0f), D3DXVECTOR3(3.0f, 1.0f, 1.0f), X_TRAP, D3DXVECTOR3(0.0f, D3DXToRadian(90.0f), 0.0f));
	//AddGameObject<CTrap>(8)->SetObject(D3DXVECTOR3(-70.0f, 4.0f, 30.0f), D3DXVECTOR3(3.0f, 1.0f, 1.0f), X_TRAP, D3DXVECTOR3(0.0f, D3DXToRadian(90.0f), 0.0f));
	//AddGameObject<CTrap>(8)->SetObject(D3DXVECTOR3(-80.0f, 4.0f, 50.0f), D3DXVECTOR3(3.0f, 1.0f, 1.0f), X_TRAP, D3DXVECTOR3(0.0f, D3DXToRadian(90.0f), 0.0f));
	//AddGameObject<CTrap>(8)->SetObject(D3DXVECTOR3(-60.0f, 4.0f, 70.0f), D3DXVECTOR3(3.0f, 1.0f, 1.0f), X_TRAP, D3DXVECTOR3(0.0f, D3DXToRadian(90.0f), 0.0f));

	//AddGameObject<CItem>(7)->SetObject(D3DXVECTOR3(-90.0f, 2.0f, -160.0f), D3DXVECTOR3(1.5f, 1.5f, 3.5f), TYPE_ITEM_BULLET);
	//AddGameObject<CItem>(7)->SetObject(D3DXVECTOR3(-80.0f, 2.0f, -160.0f), D3DXVECTOR3(1.5f, 1.5f, 3.5f), TYPE_ITEM_HEART);

	//AddGameObject<CItem>(7)->SetObject(D3DXVECTOR3(90.0f, 2.0f, -180.0f), D3DXVECTOR3(1.5f, 1.5f, 3.5f), TYPE_ITEM_BULLET);
	//AddGameObject<CItem>(7)->SetObject(D3DXVECTOR3(90.0f, 2.0f, -190.0f), D3DXVECTOR3(1.5f, 1.5f, 3.5f), TYPE_ITEM_HEART);

	//AddGameObject<CItem>(7)->SetObject(D3DXVECTOR3(90.0f, 2.0f, -10.0f), D3DXVECTOR3(1.5f, 1.5f, 3.5f), TYPE_ITEM_BULLET);

	//AddGameObject<CItem>(7)->SetObject(D3DXVECTOR3(-90.0f, 2.0f, -40.0f), D3DXVECTOR3(1.5f, 1.5f, 3.5f), TYPE_ITEM_BULLET);
	//AddGameObject<CItem>(7)->SetObject(D3DXVECTOR3(-90.0f, 2.0f, -30.0f), D3DXVECTOR3(1.5f, 1.5f, 3.5f), TYPE_ITEM_HEART);

	//AddGameObject<CItem>(7)->SetObject(D3DXVECTOR3(-90.0f, 2.0f, 190.0f), D3DXVECTOR3(1.5f, 1.5f, 3.5f), TYPE_ITEM_BULLET);
	//AddGameObject<CItem>(7)->SetObject(D3DXVECTOR3(90.0f, 2.0f, 190.0f), D3DXVECTOR3(1.5f, 1.5f, 3.5f), TYPE_ITEM_BULLET);
	//AddGameObject<CItem>(7)->SetObject(D3DXVECTOR3(90.0f, 2.0f, 100.0f), D3DXVECTOR3(1.5f, 1.5f, 3.5f), TYPE_ITEM_BULLET);

	//AddGameObject<CEnemy>(8)->SetTexture(TYPE_GOLEM, D3DXVECTOR3(-30.0f, 3.0f, -160.0f), D3DXVECTOR3(0.7f, 0.7f, 0.7f), 2);
	//AddGameObject<CEnemy>(8)->SetTexture(TYPE_GOLEM, D3DXVECTOR3(0.0f, 3.0f, -190.0f), D3DXVECTOR3(0.7f, 0.7f, 0.7f), 2);
	//AddGameObject<CEnemy>(8)->SetTexture(TYPE_GOLEM, D3DXVECTOR3(60.0f, 3.0f, -170.0f), D3DXVECTOR3(0.7f, 0.7f, 0.7f), 2);
	//AddGameObject<CEnemy>(8)->SetTexture(TYPE_WOLF, D3DXVECTOR3(60.0f, 3.5f, -180.0f), D3DXVECTOR3(6.5f, 3.0f, 6.5f), 4);
	//AddGameObject<CEnemy>(8)->SetTexture(TYPE_GOLEM, D3DXVECTOR3(80.0f, 3.0f, -130.0f), D3DXVECTOR3(0.7f, 0.7f, 0.7f), 2);
	//AddGameObject<CEnemy>(8)->SetTexture(TYPE_GOLEM, D3DXVECTOR3(30.0f, 3.0f, -20.0f), D3DXVECTOR3(0.7f, 0.7f, 0.7f), 2);
	//AddGameObject<CEnemy>(8)->SetTexture(TYPE_WOLF, D3DXVECTOR3(40.0f, 3.0f, -50.0f), D3DXVECTOR3(6.5f, 3.0f, 6.5f), 4);
	//AddGameObject<CEnemy>(8)->SetTexture(TYPE_GOLEM, D3DXVECTOR3(0.0f, 3.0f, -35.0f), D3DXVECTOR3(0.7f, 0.7f, 0.7f), 2);
	//AddGameObject<CEnemy>(8)->SetTexture(TYPE_WOLF, D3DXVECTOR3(-90.0f, 3.0f, 0.0f), D3DXVECTOR3(6.5f, 3.0f, 6.5f), 4);
	//AddGameObject<CEnemy>(8)->SetTexture(TYPE_GOLEM, D3DXVECTOR3(-50.0f, 3.0f, -50.0f), D3DXVECTOR3(0.7f, 0.7f, 0.7f), 2);
	//AddGameObject<CEnemy>(8)->SetTexture(TYPE_GOLEM, D3DXVECTOR3(-80.0f, 3.0f, 30.0f), D3DXVECTOR3(0.7f, 0.7f, 0.7f), 2);
	//AddGameObject<CEnemy>(8)->SetTexture(TYPE_GOLEM, D3DXVECTOR3(-70.0f, 3.0f, 50.0f), D3DXVECTOR3(0.7f, 0.7f, 0.7f), 2);
	//AddGameObject<CEnemy>(8)->SetTexture(TYPE_WOLF, D3DXVECTOR3(-75.0f, 3.0f, 60.0f), D3DXVECTOR3(6.5f, 3.0f, 6.5f), 4);
	//AddGameObject<CEnemy>(8)->SetTexture(TYPE_GOLEM, D3DXVECTOR3(-90.0f, 3.0f, 70.0f), D3DXVECTOR3(0.7f, 0.7f, 0.7f), 2);

	//AddGameObject<CNumber>(10)->SetTexture(BULLET_NUMBER, 2, D3DXVECTOR3(1300.0f, 850.0f, 0.0f), D3DXVECTOR3(0.5f, 0.5f, 0.0f));
	//AddGameObject<CNumber>(10)->SetTexture(MAX_BULLET_NUMBER, 3, D3DXVECTOR3(1530.0f, 900.0f, 0.0f), D3DXVECTOR3(0.5f, 0.5f, 0.0f));
	//AddGameObject<CNumber>(10)->SetTexture(HP_NUMBER, 3, D3DXVECTOR3(0.0f, 875.0f, 0.0f), D3DXVECTOR3(0.5f, 0.5f, 0.0f));

	//AddGameObject<CPolygon>(11)->SetObject(D3DXVECTOR3(SCREEN_WIDTH / 2 - 50, SCREEN_HEIGHT / 2 - 50, 0.0f), D3DXVECTOR3(0.5f, 0.5f, 0.0f), AIM_TEXTURE);

	//AddGameObject<CPolygon>(12)->SetObject(D3DXVECTOR3(SCREEN_WIDTH / 2 + 40, SCREEN_HEIGHT / 2 - 180, 0.0f), D3DXVECTOR3(4.5f, 2.5f, 0.0f), GUN_UI_TEXTURE);


	//AddGameObject<CPolygon>(15)->SetObject(D3DXVECTOR3(SCREEN_WIDTH / 2 + 240, SCREEN_HEIGHT / 2 - 20, 0.0f), D3DXVECTOR3(4.2f, 1.3f, 0.0f), CURSOR_TEXTURE);

	//AddGameObject<CPolygon>(16)->SetObject(D3DXVECTOR3(SCREEN_WIDTH / 2 + 490, SCREEN_HEIGHT / 2 + 140, 0.0f), D3DXVECTOR3(2.5f, 0.2f, 0.0f), SHOTGUN_IMPOSSIBLE_TEXTURE);
	//AddGameObject<CPolygon>(16)->SetObject(D3DXVECTOR3(SCREEN_WIDTH / 2 + 490, SCREEN_HEIGHT / 2 + 210, 0.0f), D3DXVECTOR3(2.5f, 0.2f, 0.0f), RIFLEGUN_IMPOSSIBLE_TEXTURE);

	//AddGameObject<CFade>(19)->CaeateFade();

	//PlaySoundA(SOUND_LABEL_STAGE1_BGM);

}

void CStage1::Update()
{
	CScene::Update();
	/*ShowCursor(false);
	SetCursorPos(1920 / 2, 1080 / 2);
	Collision_Update();
	CFade* Fade = CManager::GetScene()->GetGameObject<CFade>(19);
	Fade->SetFadeOut();
	CScene* scene = CManager::GetScene();
	CCamera* Camera = CManager::GetScene()->GetGameObject<CCamera>(0);
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
			CManager::SetScene<CStage2>();
		}
	}*/

}

void CStage1::Uninit()
{
	/*CExplosion::Unload();
	CNumber::Unload();
	CEnemy::Unload();
	CItem::Unload();
	CFade::Unload();
	CEbullet::Unload();
	CTrap::Unload();
	C3dpolygon::Unload();*/
}
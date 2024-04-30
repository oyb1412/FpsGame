#include "stage2.h"
#include "stage1.h"
#include "Player.h"
#include "filed.h"
#include "camera.h"
#include "light.h"
#include "scene.h"
#include "input.h"
#include "Clear.h"
#include "manager.h"
#include "title.h"
#include "sound.h"
#include "Mouse.h"
#include "stage4.h"
#include "stage3.h"
#include "warning.h"
#include "Rail.h"
#include "warning.h"
bool CClear::GameExit;
void CClear::Init()
{
	

	AddGameObject<CPolygon>(0)->SetObject(D3DXVECTOR3(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0.0f), D3DXVECTOR3(10.0f, 5.5f, 0.0f), CLEAR_BG_TEXTURE);

	AddGameObject<CPolygon>(5)->SetObject(D3DXVECTOR3(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 - 300, 0.0f), D3DXVECTOR3(4.0f, 1.5f, 0.0f), CLEAR_LOGO1_TEXTURE);

	AddGameObject<CPolygon>(1)->SetObject(D3DXVECTOR3(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 + 100, 0.0f), D3DXVECTOR3(2.5f, 1.0f, 0.0f), CLEAR_LOGO2_TEXTURE);
	AddGameObject<CPolygon>(3)->SetObject(D3DXVECTOR3(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 + 300, 0.0f), D3DXVECTOR3(2.5f, 0.7f, 0.0f), TITLE_LOGO3_TEXTURE);
	AddGameObject<CPolygon>(4)->SetObject(D3DXVECTOR3(SCREEN_WIDTH / 2 - 350, SCREEN_HEIGHT / 2 + 100, 0.0f), D3DXVECTOR3(1.0f, 0.5f, 0.0f), ARROW_TEXTURE);

	AddGameObject<CFade>(6)->CaeateFade();
	StopSound();
	PlaySoundA(SOUND_LABEL_CLEAR_BGM);
	GameExit = false;
}

void CClear::Update()
{
	CScene::Update();

	CPolygon* ClearLogo1 = CManager::GetScene()->GetGameObject<CPolygon>(1);
	CPolygon* ClearLogo3 = CManager::GetScene()->GetGameObject<CPolygon>(3);
	CPolygon* ClearArrow = CManager::GetScene()->GetGameObject<CPolygon>(4);
	CFade* Fade = CManager::GetScene()->GetGameObject<CFade>(6);


	Fade->SetFadeOut();
	D3DXVECTOR3 min1 = InputMouse::getmin();
	D3DXVECTOR3 min2 = ClearLogo1->getmin();
	D3DXVECTOR3 max1 = InputMouse::getmax();
	D3DXVECTOR3 max2 = ClearLogo1->getmax();
	if (CGameObject::TdCheckBoxCollision(min1, max1, min2, max2))
	{
		ClearArrow->SetArrow(D3DXVECTOR3(SCREEN_WIDTH / 2 - 350, SCREEN_HEIGHT / 2 + 100, 0.0f));
		if (InputMouse::PushLeft() && Fade->GetFade() == 0.0f)
		{
			PlaySoundA(SOUND_LABEL_SE_CHOICE);

			SceneType = GOTITLE;
			Fade->SetFadeIn();
		}
	}

	else if (CGameObject::TdCheckBoxCollision(min1, max1, min2, max2))
	{
		ClearArrow->SetArrow(D3DXVECTOR3(SCREEN_WIDTH / 2 - 350, SCREEN_HEIGHT / 2 + 300, 0.0f));

		if (InputMouse::PushLeft() && Fade->GetFade() == 0.0f)
		{
			PlaySoundA(SOUND_LABEL_SE_CHOICE);

			SceneType = GOEXIT;
			Fade->SetFadeIn();
		}
	}
	else
	{
		SceneType = 0;
	}

	if (Fade->GetFade() >= 1.0f && SceneType == GOTITLE)
	{
		CPlayer::ResetPlayer(3);
		StopSound();
		CManager::SetScene<CTitle>();
	}

	if (Fade->GetFade() >= 1.0f && SceneType == GOEXIT)
	{
		GameExit = true;
	}
}
void CClear::Uninit()
{
	CScene::Uninit();
	if (SceneType = GOEXIT)
	{
		/*CFade::Unload();
		CEnemy::Unload();
		C3dpolygon::Unload();
		CTrap::Unload();
		CPlayer::Unload();
		CWall::Unload();
		CField::Unload();
		CBullet::Unload();
		CExplosion::Unload();
		CEbullet::Unload();
		CNumber::Unload();
		CPolygon::Unload();
		CItem::Unload();
		CWarning::Unload();
		CRail::Unload();*/
	}
}
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
#include "sound.h"
#include "Mouse.h"
#include "stage4.h"
#include "warning.h"
#include "stage3.h"
#include "Rail.h"
bool CTitle::GameExit;
void CTitle::Init()
{
	/*CEnemy::Load();
	CFade::Load();
	CExplosion::Load();
	CTrap::Load();
	CItem::Load();
	CPlayer::Load();
	CEbullet::Load();
	CBullet::Load();
	C3dpolygon::Load();
	CNumber::Load();
	CPolygon::Load();
	CWall::Load();
	CField::Load();
	CWarning::Load();
	CRail::Load();*/

	AddGameObject<CPolygon>(0)->SetObject(D3DXVECTOR3(SCREEN_WIDTH / 2 , SCREEN_HEIGHT / 2 , 0.0f), D3DXVECTOR3(10.0f, 5.5f, 0.0f), BG_TEXTURE);

	AddGameObject<CPolygon>(5)->SetObject(D3DXVECTOR3(SCREEN_WIDTH / 2 , SCREEN_HEIGHT / 2-300 , 0.0f), D3DXVECTOR3(4.0f, 1.5f, 0.0f), TITLE_NAME_TEXTURE);

	AddGameObject<CPolygon>(1)->SetObject(D3DXVECTOR3(SCREEN_WIDTH / 2 , SCREEN_HEIGHT / 2 +100, 0.0f), D3DXVECTOR3(2.5f, 0.7f, 0.0f), TITLE_LOGO1_TEXTURE);
	AddGameObject<CPolygon>(3)->SetObject(D3DXVECTOR3(SCREEN_WIDTH / 2 , SCREEN_HEIGHT / 2 + 300, 0.0f), D3DXVECTOR3(2.5f, 0.7f, 0.0f), TITLE_LOGO3_TEXTURE);
	AddGameObject<CPolygon>(4)->SetObject(D3DXVECTOR3(SCREEN_WIDTH / 2 - 350, SCREEN_HEIGHT / 2 +100, 0.0f), D3DXVECTOR3(1.0f, 0.5f, 0.0f), ARROW_TEXTURE);



	AddGameObject<CFade>(6)->CaeateFade();
	PlaySoundA(SOUND_LABEL_TITLE_BGM);
	SceneType = 0;
	GameExit = false;
}

void CTitle::Update()
{
	CScene::Update();

	CPolygon* TitleLogo1 = CManager::GetScene()->GetGameObject<CPolygon>(1);
	CPolygon* TitleLogo2 = CManager::GetScene()->GetGameObject<CPolygon>(2);
	CPolygon* TitleLogo3 = CManager::GetScene()->GetGameObject<CPolygon>(3);
	CPolygon* TitleArrow = CManager::GetScene()->GetGameObject<CPolygon>(4);
	CFade* Fade = CManager::GetScene()->GetGameObject<CFade>(6);


	Fade->SetFadeOut();

	if (CGameObject::TdCheckBoxCollision(InputMouse::getmin(), InputMouse::getmax(), TitleLogo1->getmin(), TitleLogo1->getmax()))
	{
		TitleArrow->SetArrow(D3DXVECTOR3(SCREEN_WIDTH / 2 - 350, SCREEN_HEIGHT / 2 +100,0.0f));
		if (InputMouse::PushLeft() && Fade->GetFade() == 0.0f)
		{
			PlaySoundA(SOUND_LABEL_SE_CHOICE);
			SceneType = STARTGAME;
			Fade->SetFadeIn();
		}
	}
	
	else if (CGameObject::TdCheckBoxCollision(InputMouse::getmin(), InputMouse::getmax(), TitleLogo3->getmin(), TitleLogo3->getmax()))
	{
		TitleArrow->SetArrow(D3DXVECTOR3(SCREEN_WIDTH / 2 - 350, SCREEN_HEIGHT / 2 + 300, 0.0f));

		if (InputMouse::PushLeft() &&Fade->GetFade() == 0.0f)
		{
			PlaySoundA(SOUND_LABEL_SE_CHOICE);

			SceneType = EXIT;
			Fade->SetFadeIn();
		}
	}
	else
	{
		SceneType = 0;
	}
	Fade->GetFade();
	if (Fade->GetFade() >= 0.9f && SceneType == STARTGAME )
	{
		CManager::SetScene<CStage3>();
	}

	if (Fade->GetFade() >= 0.9f && SceneType == EXIT)
	{
		GameExit = true;
	}
}
void CTitle::Uninit()
{
	CScene::Uninit();
	
}


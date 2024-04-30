
#include "main.h"
#include "manager.h"
#include "renderer.h"
#include "Polygon.h"
#include "filed.h"
#include "camera.h"
#include "model.h"
#include "Player.h"
#include "enemy.h"
#include "bullet.h"
#include "input.h"
#include "light.h"
#include "collision.h"
#include "scene.h"
#include "sound.h"
#include <list>
#include "stage1.h"
#include "stage2.h"
#include "stage3.h"
#include "stage4.h"
#include "stage5.h"
#include "Stage6.h"
#include "Clear.h"
#include "stagebreak.h"
#include "title.h"
#include "Mouse.h"
#include "Fade.h"
#include "warning.h"
#include "Rail.h"
CScene* CManager::m_Scene = NULL;
bool CManager::Setting;
bool CManager::Pause;
int CManager::PauseCount;

void CManager::Init()
{
	CRenderer::Init();
	CInput::Init();
	SetScene<CTitle>();
//	SetScene<CClear>();
//	SetScene<CStage6>();
 //  SetScene<CStage4>();
//	  SetScene<CStage3>();

	Pause = false;
	Setting = true;
	PauseCount = 0;

	CEnemy::Load();
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
	CRail::Load();
}

void CManager::Uninit()
{
	m_Scene->Uninit();
	delete m_Scene;
	CRenderer::Uninit();
	CInput::Uninit();
	InputMouse::FreeDirectInput();

	CFade::Unload();
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
	CRail::Unload();
}

void CManager::Update()
{
	PauseCount--;
	std::vector<CPolygon*> PausePolygonList= CManager::GetScene()->GetGameObjects<CPolygon>(18);

	if (CInput::GetKeyPress('P') && Pause && PauseCount < 0)
	{
		for (CPolygon* PuasePolygon : PausePolygonList)
		{
			PuasePolygon->SetDestroy();
		}
		Pause = false;
		PauseCount = 30;
	}
	if (CInput::GetKeyPress('P') && !Pause&& PauseCount < 0)
	{
		m_Scene->AddGameObject<CPolygon>(18)->SetObject(D3DXVECTOR3(SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT *0.5f, 0.0f), D3DXVECTOR3(7.0f, 5.0f, 0.0f), PAUSE2_TEXTURE);
		Pause = true;
		PauseCount = 30;
	}
	if (Pause&& PauseCount < 0)
	{
		if (InputMouse::WhillMouseUp())
		{
			InputMouse::SetMouseSenser(0.1f);
			PauseCount = 5;
		}
		if (InputMouse::WhillMouseDown())
		{
			InputMouse::SetMouseSenser(-0.1f);
			PauseCount = 5;
		}
	}
	if (!Pause)
	{
		m_Scene->Update();
	}

	CInput::Update();
	InputMouse::ReadDate();

}

void CManager::Draw()
{
	CRenderer::Begin();

	CLight::SetLight();
	
	
		m_Scene->Draw();


	if (SceneGet<CTitle>() || SceneGet<CClear>())
	{
		InputMouse::DrawMouse();
	}
	CRenderer::End();

}

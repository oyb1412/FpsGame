#include "main.h"
#include "manager.h"
#include "renderer.h"
#include "model.h"
#include "bullet.h"
#include "Player.h"
#include "box.h"
#include "input.h"
#include "scene.h"
#include "camera.h"
#include "sound.h"
#include "Mouse.h"
#include "Polygon.h"
#include "3dpolygon.h"
#include "eattack.h"
#include "stage1.h"
#include "stage2.h"
#include "stage5.h"
#include "Stage6.h"
#define MAXREROADTIME 170
CModel* C3dpolygon::Teleport_Model;
CModel* C3dpolygon::Gate_Model;
CModel* C3dpolygon::ShotGun_Model;
CModel* C3dpolygon::SmallGun_Model;

CModel* C3dpolygon::RifleGun_Model;
CModel* C3dpolygon::Rock_Model;
CModel* C3dpolygon::Bazooka_Model;
CModel* C3dpolygon::Crown_Model;

ID3D11ShaderResourceView* C3dpolygon::Black_Texture;
ID3D11ShaderResourceView* C3dpolygon::Blue_Texture;
ID3D11ShaderResourceView* C3dpolygon::Rock_Texture;

ID3D11ShaderResourceView* C3dpolygon::ShotGun_Texture;
ID3D11ShaderResourceView* C3dpolygon::SmallGun_Texture;

ID3D11ShaderResourceView* C3dpolygon::RifleGun_Texture;
ID3D11ShaderResourceView* C3dpolygon::Crown_Texture;

void C3dpolygon::Load()
{
	Crown_Model = new CModel();
	Crown_Model->Load("asset\\model\\model\\crown.obj");

	Teleport_Model = new CModel();
	Teleport_Model->Load("asset\\model\\model\\medal.obj");

	Bazooka_Model = new CModel();
	Bazooka_Model->Load("asset\\model\\model\\bazooka.obj");

	Gate_Model = new CModel();
	Gate_Model->Load("asset\\model\\model\\gate.obj");

	ShotGun_Model = new CModel();
	ShotGun_Model->Load("asset\\model\\model\\shotgun.obj");

	SmallGun_Model = new CModel();
	SmallGun_Model->Load("asset\\model\\model\\wqe.obj");

	Rock_Model = new CModel();
	Rock_Model->Load("asset\\model\\wall\\rock.obj");

	RifleGun_Model = new CModel();
	RifleGun_Model->Load("asset\\model\\model\\rifle.obj");

	D3DX11CreateShaderResourceViewFromFile(CRenderer::GetDevice(),
		"asset/texture/color/Gold.png",
		NULL,
		NULL,
		&Crown_Texture,
		NULL);

	D3DX11CreateShaderResourceViewFromFile(CRenderer::GetDevice(),
		"asset/texture/color/Black.jpg",
		NULL,
		NULL,
		&Black_Texture,
		NULL);

	D3DX11CreateShaderResourceViewFromFile(CRenderer::GetDevice(),
		"asset/texture/enemy/Rock.png",
		NULL,
		NULL,
		&Rock_Texture,
		NULL);

	D3DX11CreateShaderResourceViewFromFile(CRenderer::GetDevice(),
		"asset/texture/color/Blue.jpg",
		NULL,
		NULL,
		&Blue_Texture,
		NULL);

	D3DX11CreateShaderResourceViewFromFile(CRenderer::GetDevice(),
		"asset/texture/gun/ShotGun_Texture.jpg",
		NULL,
		NULL,
		&ShotGun_Texture,
		NULL);

	D3DX11CreateShaderResourceViewFromFile(CRenderer::GetDevice(),
		"asset/texture/gun/RifleGun_Texture.jpg",
		NULL,
		NULL,
		&RifleGun_Texture,
		NULL);

	D3DX11CreateShaderResourceViewFromFile(CRenderer::GetDevice(),
		"asset/texture/gun/SmallGun_Texture.jpg",
		NULL,
		NULL,
		&SmallGun_Texture,
		NULL);

	
}
void C3dpolygon::Unload()
{
	Crown_Model->Unload();
	delete Crown_Model;
	Bazooka_Model->Unload();
	delete Bazooka_Model;
	Rock_Model->Unload();
	delete Rock_Model;
	Teleport_Model->Unload();
	delete Teleport_Model;
	Gate_Model->Unload();
	delete Gate_Model;
	ShotGun_Model->Unload();
	delete ShotGun_Model;
	RifleGun_Model->Unload();
	delete RifleGun_Model;
	Black_Texture->Release();
	Blue_Texture->Release();
	ShotGun_Texture->Release();
	RifleGun_Texture->Release();
	SmallGun_Texture->Release();
	Rock_Texture->Release();
	Crown_Texture->Release();
}
void C3dpolygon::Init()
{

	m_Box = new CBox();
	m_Box->Init();
	OpenDoor = false;
	PatternBegin = false;
	PatternCount = 5;
}

void C3dpolygon::Uninit()
{
	
}

void C3dpolygon::Update()
{
	m_Box->Update(m_Position, m_Min, m_Max);
	CScene* scene = CManager::GetScene();
	CCamera* Camera = CManager::GetScene()->GetGameObject<CCamera>(0);
	CPlayer* Player = CManager::GetScene()->GetGameObject<CPlayer>(2);
	C3dpolygon* ExitDoor = CManager::GetScene()->GetGameObject<C3dpolygon>(5);
	if (Type == ROCK_POLYGON)
	{
		m_Position.y -= 0.1f;
		if (m_Position.y < 1.0f)
		{
			if (CManager::SceneGet<CStage5>())
			{
				scene->AddGameObject<CEattack>(8)->SetObject(D3DXVECTOR3(m_Position.x, m_Position.y + 4.0f, m_Position.z), D3DXVECTOR3(10.0f, 10.0f, 10.0f), ATTACK_BOOM);
				scene->AddGameObject<CExplosion>(8)->SetTexture(BOOM_EFFECT, BOOM_EFFECT_X, BOOM_EFFECT_Y, D3DXVECTOR3(m_Position.x, m_Position.y + 4.0f, m_Position.z), D3DXVECTOR3(10.0f, 10.0f, 0.0f));
			}
			if (CManager::SceneGet<CStage6>())
			{
				scene->AddGameObject<CEattack>(8)->SetObject(D3DXVECTOR3(m_Position.x, m_Position.y + 4.0f, m_Position.z), D3DXVECTOR3(5.0f, 5.0f, 5.0f), ATTACK_BOOM);
				scene->AddGameObject<CExplosion>(8)->SetTexture(BOOM_EFFECT, BOOM_EFFECT_X, BOOM_EFFECT_Y, D3DXVECTOR3(m_Position.x, m_Position.y + 4.0f, m_Position.z), D3DXVECTOR3(5.0f, 5.0f, 0.0f));
			}
			SetDestroy();

		}
	}
	if (Type == TELEPORT)
	{
		if (UpTeleport)
		{
			if (m_Position.y > 2.5f)
			{
				m_Position.y -= 0.05f;
			}
		}
	}
	if (Type == DOOR_1 || Type == DOOR_2 || Type == TUTORIALDOOR_1 || Type == TUTORIALDOOR_2)
	{
		if (CloseDoor)
		{
			if (m_Position.y < 4.5f)
			{
				m_Position.y += 0.1f;
			}
			if (m_Position.y >= 4.5f)
			{
				CloseDoor = false;
			}
		}
		if (OpenDoor)
		{
			if(Type == DOOR_1)
			{
				if (m_Position.y >= -5.0f)
				{
					m_Position.y -= 0.05f;
				}
				if (m_Position.y <= 0.0f)
				{
					Camera->FreeDoor();
				}
			}
			if (Type == DOOR_2)
			{
				if (m_Position.y >= 0.0f)
				{
					m_Position.y -= 0.05f;
				}
				if (m_Position.y <= 0.0f)
				{
					Camera->FreeDoor();
				}
			}
			if (Type == TUTORIALDOOR_1)
			{
				if (m_Position.y >= -5.0f)
				{
					m_Position.y -= 0.05f;
				}
				if (m_Position.y <= 0.0f)
				{
					Camera->FreeDoor();
				}
			}
			if (Type == TUTORIALDOOR_2)
			{
				if (m_Position.y >= -5.0f)
				{
					m_Position.y -= 0.05f;
				}
				if (m_Position.y <= 0.0f)
				{
					Camera->FreeDoor();
				}
			}
			
		}
	}
	if (Type == SMALLGUN_POLYGON)
	{
		m_Rotation.y += D3DXToRadian(60.0f);
		D3DXVECTOR3 playerPosition = Camera->GetPosition();

		D3DXVECTOR3 direction = m_Position - playerPosition;

		float length = D3DXVec3Length(&direction);

		if (length < 3.0f)
		{
			Player->GetSmallGun();
			scene->AddGameObject<CFade>(19)->SetObject(D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(50.0f, 50.0f, 0.0f), FADE_WHITE);

			PlaySoundA(SOUND_LABEL_SE_GET_GUN);
			scene->AddGameObject<CPolygon>(12)->SetObject(D3DXVECTOR3(SCREEN_WIDTH *0.9f, SCREEN_HEIGHT *0.75f, 0.0f), D3DXVECTOR3(1.5f, 0.4f, 0.0f), SMALLGUN_UI_TEXTURE);
			scene->AddGameObject<CPolygon>(15)->SetObject(D3DXVECTOR3(SCREEN_WIDTH *0.87f, SCREEN_HEIGHT *0.77f, 0.0f), D3DXVECTOR3(3.0f, 1.3f, 0.0f), CURSOR_TEXTURE);
			scene->AddGameObject<CNumber>(10)->SetTexture(BULLET_NUMBER, 2, D3DXVECTOR3(SCREEN_WIDTH *0.75f, SCREEN_HEIGHT *0.8f, 0.0f), D3DXVECTOR3(0.3f, 0.3f, 0.0f));
			scene->AddGameObject<CNumber>(10)->SetTexture(MAX_BULLET_NUMBER, 3, D3DXVECTOR3(SCREEN_WIDTH *0.85f, SCREEN_HEIGHT *0.85f, 0.0f), D3DXVECTOR3(0.3f, 0.3f, 0.0f));
			
			SetDestroy();
		}
	}
	if (Type == SHOTGUN_POLYGON)
	{
		m_Rotation.y += D3DXToRadian(60.0f);
		D3DXVECTOR3 playerPosition = Camera->GetPosition();

		D3DXVECTOR3 direction = m_Position - playerPosition;

		float length = D3DXVec3Length(&direction);

		if (length < 3.0f)
		{
			Player->GetShotGun();
			scene->AddGameObject<CFade>(19)->SetObject(D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(50.0f, 50.0f, 0.0f), FADE_WHITE);
			scene->AddGameObject<CPolygon>(12)->SetObject(D3DXVECTOR3(SCREEN_WIDTH *0.88f, SCREEN_HEIGHT *0.65f, 0.0f), D3DXVECTOR3(1.5f, 0.4f, 0.0f), SHOTGUN_UI_TEXTURE);
			PlaySoundA(SOUND_LABEL_SE_GET_GUN);

			SetDestroy();
		}
	}
	if (Type == RIFLEGUN_POLYGON)
	{
		m_Rotation.y += D3DXToRadian(60.0f);
		D3DXVECTOR3 playerPosition = Camera->GetPosition();

		D3DXVECTOR3 direction = m_Position - playerPosition;

		float length = D3DXVec3Length(&direction);

		if (length < 6.0f)
		{
			Player->GetRifleGun();
			scene->AddGameObject<CFade>(19)->SetObject(D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(50.0f, 50.0f, 0.0f), FADE_WHITE);
			PlaySoundA(SOUND_LABEL_SE_GET_GUN);
			scene->AddGameObject<CPolygon>(12)->SetObject(D3DXVECTOR3(SCREEN_WIDTH *0.88f, SCREEN_HEIGHT *0.55f, 0.0f), D3DXVECTOR3(1.5f, 0.4f, 0.0f), RIPLEGUN_UI_TEXTURE);

			SetDestroy();
		}
	}
	if (Type == BAZOOKA_POLYGON)
	{
		m_Rotation.y += D3DXToRadian(60.0f);
		D3DXVECTOR3 playerPosition = Camera->GetPosition();

		D3DXVECTOR3 direction = m_Position - playerPosition;

		float length = D3DXVec3Length(&direction);

		if (length < 3.0f)
		{
			Player->GetBazooka();
			scene->AddGameObject<CFade>(19)->SetObject(D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(50.0f, 50.0f, 0.0f), FADE_WHITE);
			PlaySoundA(SOUND_LABEL_SE_GET_GUN);
			scene->AddGameObject<CPolygon>(12)->SetObject(D3DXVECTOR3(SCREEN_WIDTH *0.88f, SCREEN_HEIGHT *0.45f, 0.0f), D3DXVECTOR3(1.5f, 0.4f, 0.0f), BAZOOKA_UI_TEXTURE);

			SetDestroy();
		}
	}
	if (Type == CROWN_POLYGON)
	{
		m_Rotation.y += D3DXToRadian(60.0f);
		D3DXVECTOR3 playerPosition = Camera->GetPosition();

		D3DXVECTOR3 direction = m_Position - playerPosition;

		float length = D3DXVec3Length(&direction);

		if (length < 3.0f)
		{
			Camera->SetTeleport();

			SetDestroy();
		}
	}
	if (CManager::SceneGet<CStage1>())
	{
		if (Type == PATTERNONE_POLYGON)
		{

			if (PatternBegin)
			{
				PatternCount++;
				if (m_Position.y > 0.0f)
				{
					m_Position.y -= 0.15f;
				}
			}
			if (!PatternBegin)
			{
				if (m_Position.y < 10.0f)
				{
					m_Position.y += 0.15f;
				}
			}
		}
	


	
		
			
			
		}

	if (CManager::SceneGet<CStage2>())
	{
		if (Type == TOOL_DOOR)
		{
			if (UpDoor)
			{
				if (m_Position.y < 10.0f)
				{
					m_Position.y += 0.1f;
				}
			}
		}
		if (Type == EXIT_DOOR)
		{
			if (UpDoor)
			{
				if (m_Position.y < 10.0f)
				{
					m_Position.y += 0.1f;
				}
			}
		}
		
	}
}
void C3dpolygon::Transparent()
{
	
		if (Type == TELEPORT)
		{
			m_Box->Draw(&Teleport_World);
		}
		if (Type == DOOR_1 || Type == DOOR_2 || Type == TUTORIALDOOR_1 || Type == TUTORIALDOOR_2)
		{
			m_Box->Draw(&Door_World);
		}
		if (Type == ROCK_POLYGON)
		{
			m_Box->Draw(&world);
		}
	
}
void C3dpolygon::Draw()
{
	//マトリクス設定

	D3DXMATRIX  scale, rot, trans, HighY_Trans,  High_Scale, High_Trans, Medal_Rot, Medal_World,Shotgun_World,Shotgun_Rot,low_scale;
	D3DXMatrixScaling(&scale, m_Scale.x, m_Scale.y, m_Scale.z);
	D3DXMatrixScaling(&High_Scale, m_Scale.x*2.0f, m_Scale.y*2.0f, m_Scale.z );
	D3DXMatrixTranslation(&High_Trans, m_Position.x, m_Position.y + 2.0f, m_Position.z);

	D3DXMatrixRotationY(&Medal_Rot, D3DXToRadian(m_Rotation.y));
	D3DXMatrixTranslation(&trans, m_Position.x, m_Position.y, m_Position.z);
	D3DXMatrixTranslation(&HighY_Trans, m_Position.x, m_Position.y+1.0f, m_Position.z);
	D3DXMatrixRotationY(&Shotgun_Rot, D3DXToRadian(m_Rotation.y));
	D3DXMatrixScaling(&low_scale, m_Scale.x *3.0f, m_Scale.y+3.0f, m_Scale.z*3.0f);

	world = scale * trans;
	Shotgun_World = scale * Shotgun_Rot * trans;
	Teleport_World = low_scale * HighY_Trans;
	Door_World = High_Scale * trans;
	Medal_World = scale * Medal_Rot * HighY_Trans;
	CRenderer::SetWorldMatrix(&world);
	//テクスチャ設定
	assert(Black_Texture);
	CRenderer::GetDeviceContext()->PSSetShaderResources(0, 1, &Black_Texture);

	//モデル描画
	if (Type == TELEPORT)
	{
		if (m_Position.y < 19.0f)
		{
			CRenderer::GetDeviceContext()->PSSetShaderResources(0, 1, &Blue_Texture);

			Teleport_Model->Draw();
		}
	}
	if (Type == DOOR_1 || Type == DOOR_2 || Type == TUTORIALDOOR_1 || Type == TUTORIALDOOR_2)
	{
		Gate_Model->Draw();
	}
	if (Type == SHOTGUN_POLYGON)
	{
		assert(ShotGun_Texture);
		CRenderer::GetDeviceContext()->PSSetShaderResources(0, 1, &ShotGun_Texture);
		CRenderer::SetWorldMatrix(&Shotgun_World);
		ShotGun_Model->Draw();
	}
	if (Type == SMALLGUN_POLYGON)
	{
		assert(SmallGun_Texture);
		CRenderer::GetDeviceContext()->PSSetShaderResources(0, 1, &SmallGun_Texture);
		CRenderer::SetWorldMatrix(&Shotgun_World);
		SmallGun_Model->Draw();
	}
	if (Type == RIFLEGUN_POLYGON)
	{
		assert(RifleGun_Texture);
		CRenderer::GetDeviceContext()->PSSetShaderResources(0, 1, &RifleGun_Texture);
		CRenderer::SetWorldMatrix(&Shotgun_World);
		RifleGun_Model->Draw();
	}
	if (Type == BAZOOKA_POLYGON)
	{
		CRenderer::SetWorldMatrix(&Shotgun_World);
		Bazooka_Model->Draw();
	}
	if (Type == ROCK_POLYGON)
	{
		assert(Rock_Texture);
		CRenderer::GetDeviceContext()->PSSetShaderResources(0, 1, &Rock_Texture);
		CRenderer::SetWorldMatrix(&world);
		Rock_Model->Draw();
	}
	if (Type == CROWN_POLYGON)
	{
		assert(Crown_Texture);
		CRenderer::GetDeviceContext()->PSSetShaderResources(0, 1, &Crown_Texture);
		CRenderer::SetWorldMatrix(&Shotgun_World);
		Crown_Model->Draw();
	}



}
#include "main.h"
#include "manager.h"
#include "renderer.h"
#include "model.h"
#include "Player.h"
#include "Bullet.h"
#include "input.h"
#include "scene.h"
#include "box.h"
#include "camera.h"
#include "game_object.h"
#include "explosion.h"
#include "attack.h"
#include "sound.h"
CModel* CBullet::Bazooka_Model;
ID3D11ShaderResourceView* CBullet::Bazooka_Texture;

void CBullet::Load()
{
	Bazooka_Model = new CModel();
	Bazooka_Model->Load("asset\\model\\enemybullet\\missile.obj");

	D3DX11CreateShaderResourceViewFromFile(CRenderer::GetDevice(),
		"asset/texture/color/Gray.png",
		NULL,
		NULL,
		&Bazooka_Texture,
		NULL);
}

void CBullet::Unload()
{
	Bazooka_Model->Unload();
	delete Bazooka_Model;
}
void CBullet::Init()
{
	CCamera* Camera = CManager::GetScene()->GetGameObject<CCamera>(0);

	
	m_Position = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	m_Rotation = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_Scale = D3DXVECTOR3(0.01f, 0.01f, 0.01f);
	g_Box = new CBox();
	g_Box->Init();
	m_Max = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_Min = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	SmallGunBullet_Front = Camera->GetFrontVec() ;
	
	ShotGunBullet_Front[0].x = Camera->GetFrontVec().x+Camera->GetRightVec().x*0.06f;
	ShotGunBullet_Front[0].y = Camera->GetFrontVec().y;
	ShotGunBullet_Front[0].z = Camera->GetFrontVec().z + Camera->GetRightVec().z*0.05f;

	ShotGunBullet_Front[1].x = Camera->GetFrontVec().x;
	ShotGunBullet_Front[1].y = Camera->GetFrontVec().y - 0.06f;
	ShotGunBullet_Front[1].z = Camera->GetFrontVec().z;

	ShotGunBullet_Front[2].x = Camera->GetFrontVec().x;
	ShotGunBullet_Front[2].y = Camera->GetFrontVec().y+0.05f;
	ShotGunBullet_Front[2].z = Camera->GetFrontVec().z;

	ShotGunBullet_Front[3].x = Camera->GetFrontVec().x - Camera->GetRightVec().x*0.06f;
	ShotGunBullet_Front[3].y = Camera->GetFrontVec().y;
	ShotGunBullet_Front[3].z = Camera->GetFrontVec().z - Camera->GetRightVec().z*0.05f;

	RifleGunBullet_Front = Camera->GetFrontVec();

	BazookaBullet_Front = Camera->GetFrontVec();

	Effect[0] = false;
	Effect[1] = false;
	BulletCount = 0;
}

void CBullet::Update()
{
	BulletCount++;
	if (BulletCount > 120)
	{
		SetDestroy();
	}
	CScene* scene = CManager::GetScene();

	g_Box->Update(m_Position, m_Min, m_Max);
	CCamera* Camera = CManager::GetScene()->GetGameObject<CCamera>(0);
	if (Effect[0])
	{
		D3DXVECTOR3 Length = m_Position - Camera->GetPosition();
		float FLength = D3DXVec3Length(&Length);
		scene->AddGameObject<CExplosion>(9)->SetTexture(HEADSHOT_HIT, HEADSHOT_EFFECT_X, HEADSHOT_EFFECT_Y, (m_Position - Camera->GetFrontVec() * 6), D3DXVECTOR3(FLength / 30, FLength / 30, 0.0f));
		Effect[0] = false;
	}
	if (Effect[1])
	{
		D3DXVECTOR3 Length = m_Position - Camera->GetPosition();
		float FLength = D3DXVec3Length(&Length);
		scene->AddGameObject<CExplosion>(9)->SetTexture(GUN_HIT, SHOT_EFFECT_X, SHOT_EFFECT_Y, (m_Position - Camera->GetFrontVec() * 9), D3DXVECTOR3(FLength / 30, FLength / 30, 0.0f));
		Effect[1] = false;
	}
	if (Type == SMALLGUN_BULLET)
	{
		m_Position += SmallGunBullet_Front*2.0f ;
	}
	else if (Type == SHOTGUN_BULLET)
	{
		m_Position += ShotGunBullet_Front[0] * 2.0f;
	}
	else if (Type == SHOTGUN_BULLET2)
	{
		m_Position += ShotGunBullet_Front[1] * 2.0f;
	}
	else if (Type == SHOTGUN_BULLET3)
	{
		m_Position += ShotGunBullet_Front[2] * 2.0f;
	}
	else if (Type == SHOTGUN_BULLET4)
	{
		m_Position += ShotGunBullet_Front[3] * 2.0f;
	}
	else if (Type == RIFLEGUN_BULLET)
	{
		m_Position += RifleGunBullet_Front * 2.0f;
	}
	else if (Type == BAZOOKA_BULLET)
	{
		m_Position += BazookaBullet_Front*0.9f;
		if (m_Position.y < 2.5f || m_Position.y > 7.5f)
		{
			if (m_Position.y < 2.5f)
			{
				scene->AddGameObject<CAttack>(8)->SetObject(D3DXVECTOR3(m_Position.x,m_Position.y+1.0f,m_Position.z), D3DXVECTOR3(15.0f, 5.0f, 10.0f));
				PlaySoundA(SOUND_LABEL_SE_BOSS_BOOM);

				scene->AddGameObject<CExplosion>(8)->SetTexture(BOOM_EFFECT, BOOM_EFFECT_X, BOOM_EFFECT_Y, D3DXVECTOR3(m_Position.x, m_Position.y + 1.0f, m_Position.z), D3DXVECTOR3(10.0f, 5.0f, 0.0f));
			}
			else if (m_Position.y > 7.5f)
			{
				scene->AddGameObject<CAttack>(8)->SetObject(D3DXVECTOR3(m_Position.x, m_Position.y - 1.0f, m_Position.z), D3DXVECTOR3(15.0f, 5.0f, 10.0f));
				PlaySoundA(SOUND_LABEL_SE_BOSS_BOOM);

				scene->AddGameObject<CExplosion>(8)->SetTexture(BOOM_EFFECT, BOOM_EFFECT_X, BOOM_EFFECT_Y, D3DXVECTOR3(m_Position.x, m_Position.y - 1.0f, m_Position.z), D3DXVECTOR3(10.0f, 5.0f, 0.0f));

			}
			SetDestroy();
		}
	}
	std::vector<CEnemy*> enemyList = CManager::GetScene()->GetGameObjects<CEnemy>(8);
	
	
}

void CBullet::Uninit()
{
	g_Box->Destroy();
}
void CBullet::Transparent()
{
	g_Box->Draw(&boxworld);
}
void CBullet::Draw()
{
	CCamera* camera = CManager::GetScene()->GetGameObject<CCamera>(0);

	D3DXMATRIX scale, rot, trans,boxscale;
	D3DXMatrixScaling(&scale, m_Scale.x*4.0f, m_Scale.y*4.0f, m_Scale.z);
	D3DXMatrixScaling(&boxscale, m_Scale.x*1.3f, m_Scale.y*1.3f, m_Scale.z*1.3f);

	D3DXMatrixRotationYawPitchRoll(&rot, m_Rotation.y, m_Rotation.x, m_Rotation.z);
	D3DXMatrixTranslation(&trans, m_Position.x, m_Position.y, m_Position.z);

	if (Count < 1)
	{
		D3DXVECTOR3 PuP = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		D3DXVECTOR3 PEye = camera->GetPosition();
		D3DXMatrixLookAtLH(&EviewMatrix, &PEye, &m_Position
			, &PuP);
		view = EviewMatrix;
		D3DXMatrixIdentity(&invView);

		invView._11 = view._11;
		invView._13 = view._13;
		invView._31 = view._31;
		invView._33 = view._33;
		D3DXMatrixInverse(&invView, NULL, &invView);
		Count++;
	}
	world = scale * invView * trans;

	boxworld = boxscale * rot * trans;
	if (Type == BAZOOKA_BULLET)
	{
		assert(Bazooka_Texture);
		CRenderer::GetDeviceContext()->PSSetShaderResources(0, 1, &Bazooka_Texture);
		CRenderer::SetWorldMatrix(&world);
		Bazooka_Model->Draw();
	}
}



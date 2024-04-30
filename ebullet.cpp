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
#include "eattack.h"
#include "sound.h"
#include "ebullet.h"
#include "enemy.h"
ID3D11ShaderResourceView* CEbullet::EnemyBullet_Texture;
ID3D11ShaderResourceView* CEbullet::BossBullet_Texture;
ID3D11ShaderResourceView* CEbullet::Boom_Texture;

CModel* CEbullet::EnemyBullet_Model;
CModel* CEbullet::Boom_Model;
void CEbullet::Load()
{
	D3DX11CreateShaderResourceViewFromFile(CRenderer::GetDevice(),
		"asset/texture/color/Red.jpg",
		NULL,
		NULL,
		&EnemyBullet_Texture,
		NULL);

	D3DX11CreateShaderResourceViewFromFile(CRenderer::GetDevice(),
		"asset/texture/color/Red.jpg",
		NULL,
		NULL,
		&BossBullet_Texture,
		NULL);

	D3DX11CreateShaderResourceViewFromFile(CRenderer::GetDevice(),
		"asset/texture/enemy/Golem_Texture.png",
		NULL,
		NULL,
		&Boom_Texture,
		NULL);

	EnemyBullet_Model = new CModel();
	EnemyBullet_Model->Load("asset\\model\\enemybullet\\missile.obj");

	Boom_Model = new CModel();
	Boom_Model->Load("asset\\model\\enemybullet\\mine.obj");

}

void CEbullet::Unload()
{
	if (EnemyBullet_Texture != NULL)
	{
		EnemyBullet_Texture->Release();
	}
	if (BossBullet_Texture != NULL)
	{
		BossBullet_Texture->Release();
	}
	if (Boom_Texture != NULL)
	{
		Boom_Texture->Release();
	}
	EnemyBullet_Model->Unload();
	delete EnemyBullet_Model;
	Boom_Model->Unload();
	delete Boom_Model;

}
void CEbullet::Init()
{
	Life = 0;
	
	m_Count = 0;
	m_sCount = 0;
	m_Length = 2;
	m_Height = 3;
	Count = 0;
	BoomType = false;

	g_Box = new CBox();
	g_Box->Init();

}

void CEbullet::Update()
{
	m_sCount++;
	
	g_Box->Update(m_Position, m_Min, m_Max);
	if (Type == ENEMY_BULLET)
	{
		if (m_sCount % 2 == 0)
		{
			m_Count++;
		}
		if (m_sCount > 200)
		{
			SetDestroy();
		}
		m_Position.x += Bullet_Front.x * 0.5f;
		m_Position.z += Bullet_Front.z * 0.5f;

	}
	else if (Type == BOSS_BULLET)
	{
		if (m_sCount % 2 == 0)
		{
			m_Count++;
		}
		if (m_sCount > 200)
		{
			SetDestroy();
		}
		m_Position.x += Bullet_Front.x * 0.5f;
		m_Position.z += Bullet_Front.z * 0.5f;
	}
	if (Type == BOOM)
	{
		if (m_Position.y < 8.0f && !BoomType)
		{
			m_Position.y += 0.15f;
		}
		if (m_Position.y >= 8.0f)
		{
			BoomType = true;
		}
		if (BoomType && m_Position.y > 3.0f)
		{
			m_Position.y -= 0.15f;
		}
		if (m_Position.y > 3.0f&& m_Position.x < 60.0f&& m_Position.x > 10.0f && m_Position.z < 505.0f&& m_Position.z > 455.0f)
		{
			if (m_Position.x < Boom_Position.x )
			{
				m_Position.x += Bullet_Front.x * 0.4f;
			}
			if (m_Position.x > Boom_Position.x )
			{
				m_Position.x += Bullet_Front.x * 0.4f;
			}
			if (m_Position.z < Boom_Position.z)
			{
				m_Position.z += Bullet_Front.z * 0.4f;
			}
			if (m_Position.z > Boom_Position.z )
			{
				m_Position.z += Bullet_Front.z * 0.4f;
			}
		}
		
		if (m_Position.y <= 3.0f && BoomType)
		{
			m_Count++;
			CScene* scene = CManager::GetScene();

			if (m_Count == 180)
			{
				scene->AddGameObject<CEattack>(8)->SetObject((m_Position), D3DXVECTOR3(16.0f,16.0f, 16.0f),ATTACK_BOOM);
				scene->AddGameObject<CExplosion>(8)->SetTexture(BOOM_EFFECT, BOOM_EFFECT_X,BOOM_EFFECT_Y, m_Position, D3DXVECTOR3(16.0f,16.0f, 0.0f));
				PlaySoundA(SOUND_LABEL_SE_BOSS_BOOM);

				SetDestroy();
			}
		}
	}
}

void CEbullet::Uninit()
{
	g_Box->Destroy();
}
void CEbullet::Transparent()
{
		g_Box->Draw(&world);
}
void CEbullet::Draw()
{
	LIGHT light;
	light.Enable = false;
	CRenderer::SetLight(light);

	CCamera* camera = CManager::GetScene()->GetGameObject<CCamera>(0);

	D3DXMATRIX  scale, rot, trans,world1,boxscale;
	D3DXMatrixScaling(&scale, m_Scale.x*1.5f, m_Scale.y*1.5f, m_Scale.z*1.5f);
	D3DXMatrixScaling(&boxscale, m_Scale.x*0.6f, m_Scale.y*0.6f, m_Scale.z*1.0f);

	D3DXMatrixRotationYawPitchRoll(&rot, m_Rotation.y, m_Rotation.x, m_Rotation.z);
	D3DXMatrixTranslation(&trans, m_Position.x, m_Position.y, m_Position.z);
	world = boxscale * rot * trans;	
	
	if (Count < 1)
	{
		D3DXVECTOR3 Camera = camera->GetPosition();
		D3DXVECTOR3 dir = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		D3DXMatrixLookAtLH(&EviewMatrix, &Camera, &m_Position
			, &dir);
		view = EviewMatrix;
		D3DXMatrixIdentity(&invView);

		invView._11 = view._11;
		invView._13 = view._13;
		invView._31 = view._31;
		invView._33 = view._33;
		D3DXMatrixInverse(&invView, NULL, &invView);
		Count++;
	}
	world1 = scale * invView * trans;


	if (Type == ENEMY_BULLET)
	{
		assert(EnemyBullet_Texture);
		CRenderer::GetDeviceContext()->PSSetShaderResources(0, 1, &EnemyBullet_Texture);
		CRenderer::SetWorldMatrix(&world1);

		EnemyBullet_Model->Draw();
	}
	if (Type == BOSS_BULLET)
	{
		assert(BossBullet_Texture);
		CRenderer::GetDeviceContext()->PSSetShaderResources(0, 1, &BossBullet_Texture);
		CRenderer::SetWorldMatrix(&world1);

		EnemyBullet_Model->Draw();
	}
	if (Type == BOOM)
	{
		assert(Boom_Texture);
		CRenderer::GetDeviceContext()->PSSetShaderResources(0, 1, &Boom_Texture);
		CRenderer::SetWorldMatrix(&world1);

		Boom_Model->Draw();
	}

}



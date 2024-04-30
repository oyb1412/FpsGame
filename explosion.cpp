#include "main.h"
#include "renderer.h"
#include "manager.h"
#include "scene.h"
#include "explosion.h"
#include "camera.h"
#include "light.h"
#include "sound.h"
#include "stage3.h"
#include "stage4.h"
#include "stage5.h"
#include "Stage6.h"
ID3D11ShaderResourceView* CExplosion::Gun_Effect_Texture;
ID3D11ShaderResourceView* CExplosion::Gun_Hit_Texture;
ID3D11ShaderResourceView* CExplosion::ShotGun_Hit_Texture;
ID3D11ShaderResourceView* CExplosion::HeadShot_Hit_Texture;

ID3D11ShaderResourceView* CExplosion::Boss_Door_Texture;
ID3D11ShaderResourceView* CExplosion::Create_Effect_Texture;
ID3D11ShaderResourceView* CExplosion::Enemy_Distroy_Texture;
ID3D11ShaderResourceView* CExplosion::Boom_Effect_Texture;
void CExplosion::Load()
{
	//ƒeƒNƒX?ƒƒ



	D3DX11CreateShaderResourceViewFromFile(CRenderer::GetDevice(),
		"asset/texture/gun/Gun_Effect.png",
		NULL,
		NULL,
		&Gun_Effect_Texture,
		NULL);

	D3DX11CreateShaderResourceViewFromFile(CRenderer::GetDevice(),
		"asset/texture/enemy/Boom_Effect.png",
		NULL,
		NULL,
		&Boom_Effect_Texture,
		NULL);

	D3DX11CreateShaderResourceViewFromFile(CRenderer::GetDevice(),
		"asset/texture/gun/Shot_Effect.png",
		NULL,
		NULL,
		&Gun_Hit_Texture,
		NULL);

	D3DX11CreateShaderResourceViewFromFile(CRenderer::GetDevice(),
		"asset/texture/gun/ShotGun_Hit.png",
		NULL,
		NULL,
		&ShotGun_Hit_Texture,
		NULL);

	D3DX11CreateShaderResourceViewFromFile(CRenderer::GetDevice(),
		"asset/texture/gun/HeadShot_Effect.png",
		NULL,
		NULL,
		&HeadShot_Hit_Texture,
		NULL);

	D3DX11CreateShaderResourceViewFromFile(CRenderer::GetDevice(),
		"asset/texture/etc/Door.png",
		NULL,
		NULL,
		&Boss_Door_Texture,
		NULL);

	D3DX11CreateShaderResourceViewFromFile(CRenderer::GetDevice(),
		"asset/texture/etc/Create_Effect.png",
		NULL,
		NULL,
		&Create_Effect_Texture,
		NULL);

	D3DX11CreateShaderResourceViewFromFile(CRenderer::GetDevice(),
		"asset/texture/enemy/Enemy_Distroy.png",
		NULL,
		NULL,
		&Enemy_Distroy_Texture,
		NULL);
}

void CExplosion::Unload()
{
	Boom_Effect_Texture->Release();
	HeadShot_Hit_Texture->Release();
	Enemy_Distroy_Texture->Release();
	Gun_Effect_Texture->Release();
	Gun_Hit_Texture->Release();
	ShotGun_Hit_Texture->Release();
	Boss_Door_Texture->Release();
	Create_Effect_Texture->Release();
}
void CExplosion::Init()
{
	VERTEX_3D vertex[4];

	vertex[0].Position = D3DXVECTOR3(-1.0f, 1.0f, 0.0f);
	vertex[0].Normal = D3DXVECTOR3(0.0f, 0.0f, -1.0f);
	vertex[0].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
	vertex[0].TexCoord = D3DXVECTOR2(0.0f, 0.0f);

	vertex[1].Position = D3DXVECTOR3(1.0f, 1.0f, 0.0f);
	vertex[1].Normal = D3DXVECTOR3(0.0f, 0.0f, -1.0f);
	vertex[1].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
	vertex[1].TexCoord = D3DXVECTOR2(1.0f, 0.0f);

	vertex[2].Position = D3DXVECTOR3(-1.0f, -1.0f, 0.0f);
	vertex[2].Normal = D3DXVECTOR3(0.0f, 0.0f, -1.0f);
	vertex[2].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
	vertex[2].TexCoord = D3DXVECTOR2(0.0f, 1.0f);

	vertex[3].Position = D3DXVECTOR3(1.0f, -1.0f, 0.0f);
	vertex[3].Normal = D3DXVECTOR3(0.0f, 0.0f, -1.0f);
	vertex[3].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
	vertex[3].TexCoord = D3DXVECTOR2(1.0f, 1.0f);

	D3D11_BUFFER_DESC bd;
	ZeroMemory(&bd, sizeof(bd));
	bd.Usage = D3D11_USAGE_DYNAMIC;
	bd.ByteWidth = sizeof(VERTEX_3D) * 4;
	bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	bd.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;

	D3D11_SUBRESOURCE_DATA sd;
	ZeroMemory(&sd, sizeof(sd));
	sd.pSysMem = vertex;

	CRenderer::GetDevice()->CreateBuffer(&bd, &sd, &m_VertexBuffer);


	

	m_Position = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_Rotation = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_Scale = D3DXVECTOR3(3.0f,3.0f, 0.0f);

	m_Count = 0;
	s_Count = 0;
}

void CExplosion::Uninit()
{
	m_VertexBuffer->Release();
}

void CExplosion::Update()
{
	CScene* scene = CManager::GetScene();
	CCamera* camera = CManager::GetScene()->GetGameObject<CCamera>(0);

	if (Type != BOSS_DOOR && Type != CREATE_EFFECT && Type != HEADSHOT_HIT && Type != GUN_HIT && Type != SUMMON_SHORT && Type != SUMMON_LONG)
	{
		m_Count++;
	}
	if (Type == CREATE_EFFECT)
	{
		s_Count++;
		if (s_Count % 8 == 0)
		{
			m_Count++;
		}
	}
	if (Type == SUMMON_SHORT)
	{
		s_Count++;
		if (s_Count == 5)
		{
			PlaySoundA(SOUND_LABEL_SE_SUMMONING);
		}
		if (s_Count % 8 == 0)
		{
			m_Count++;
		}
		if (m_Count >= (m_Length * m_Height))
		{
			if (CManager::SceneGet<CStage3>() || CManager::SceneGet<CStage5>() || CManager::SceneGet<CStage6>())
			{
				scene->AddGameObject<CEnemy>(8)->SetTexture(TYPE_WOLF, D3DXVECTOR3(m_Position.x, m_Position.y - 2.0f, m_Position.z), D3DXVECTOR3(0.6f, 0.3f, 0.6f),30);
				SetDestroy();
			}
			else if (CManager::SceneGet<CStage4>())
			{
				scene->AddGameObject<CEnemy>(8)->SetTexture(TYPE_AIRPLANE, D3DXVECTOR3(m_Position.x, m_Position.y - 2.0f, m_Position.z), D3DXVECTOR3(0.04f, 0.04f, 0.04f), 30);
				SetDestroy();
			}
		}
	}
	if (Type == SUMMON_LONG)
	{
		s_Count++;
		if (s_Count == 5)
		{
			PlaySoundA(SOUND_LABEL_SE_SUMMONING);
		}
		if (s_Count % 8 == 0)
		{
			m_Count++;
		}
		if (m_Count >= (m_Length * m_Height))
		{
			scene->AddGameObject<CEnemy>(8)->SetTexture(TYPE_GOLEM,D3DXVECTOR3(m_Position.x,m_Position.y - 3.0f,m_Position.z), D3DXVECTOR3(1.0f, 1.5f, 1.0f), 40);
			SetDestroy();
		}
	}
	if (Type == HEADSHOT_HIT)
	{
		s_Count++;
		if (s_Count % 3 == 0)
		{
			m_Count++;
		}
	}
	if (Type == GUN_HIT)
	{
		s_Count++;
		if (s_Count % 2 == 0)
		{
			m_Count++;
		}
	}
	if (Type == BOSS_DOOR)
	{
		if (CManager::SceneGet<CStage4>())
		{
			if (s_Count < 450)
			{
				if (m_Scale.x < 30.0f)
				{
					m_Scale.x += 0.6f;
				}
				if (m_Scale.y < 6.0f)
				{
					m_Scale.y += 0.06f;
				}
			}
			s_Count++;
			if (s_Count % 5 == 0)
			{
				m_Count++;
			}
			if (s_Count > 400)
			{
				m_Scale.x -= 0.4f;
				m_Scale.y -= 0.04f;
			}
			if (s_Count > 500)
			{
				SetDestroy();
			}
		}
		else if (CManager::SceneGet<CStage5>())
		{
			if (s_Count < 450)
			{
				if (m_Scale.x < 10.0f)
				{
					m_Scale.x += 0.2f;
				}
				if (m_Scale.y < 4.0f)
				{
					m_Scale.y += 0.04f;
				}
			}
			if (s_Count % 400 == 0 && s_Count < 2900 && s_Count > 200)
			{
				scene->AddGameObject<CEnemy>(8)->SetTexture(TYPE_WOLF, D3DXVECTOR3(m_Position.x+camera->GetFrontVec().x*10.0f, m_Position.y - 1.6f, m_Position.z + camera->GetFrontVec().z*10.0f), D3DXVECTOR3(0.6f, 0.3f, 0.6f), 20);
			}
			s_Count++;
			if (s_Count > 2900)
			{
				m_Scale.x -= 0.2f;
				m_Scale.y -= 0.04f;
			}
			if (s_Count > 3000)
			{
				C3dpolygon* ClearTeleport = CManager::GetScene()->GetGameObject<C3dpolygon>(4);
				ClearTeleport->SetTeleport();
				SetDestroy();
			}
			if (s_Count % 5 == 0)
			{
				m_Count++;
			}
		
		}
		else if (CManager::SceneGet<CStage6>())
		{
			if (s_Count < 450)
			{
				if (m_Scale.x < 5.0f)
				{
					m_Scale.x += 0.1f;
				}
				if (m_Scale.y < 2.0f)
				{
					m_Scale.y += 0.02f;
				}
			}
			if (s_Count % 500 == 0 && s_Count <2000 && s_Count >120)
			{
				scene->AddGameObject<CEnemy>(8)->SetTexture(TYPE_WOLF, D3DXVECTOR3(m_Position.x + camera->GetFrontVec().x*10.0f, m_Position.y - 1.6f, m_Position.z + camera->GetFrontVec().z*10.0f), D3DXVECTOR3(0.6f, 0.3f, 0.6f), 20);
				
			}
			if (s_Count % 1000 == 0 && s_Count < 2000 && s_Count > 120)
			{
				if (m_Position.x < 140.0f)
				{
					scene->AddGameObject<CExplosion>(8)->SetTexture(SUMMON_LONG, CREATE_EFFECT_X, CREATE_EFFECT_Y, D3DXVECTOR3(40.0f, 5.6f, 25.0f), D3DXVECTOR3(5.0f, 4.0f, 0.0f));
					scene->AddGameObject<CExplosion>(8)->SetTexture(SUMMON_LONG, CREATE_EFFECT_X, CREATE_EFFECT_Y, D3DXVECTOR3(40.0f, 5.6f, 65.0f), D3DXVECTOR3(5.0f, 4.0f, 0.0f));
				}
				else if (m_Position.x > 140.0f)
				{
					scene->AddGameObject<CExplosion>(8)->SetTexture(SUMMON_LONG, CREATE_EFFECT_X, CREATE_EFFECT_Y, D3DXVECTOR3(250.0f, 5.6f, 25.0f), D3DXVECTOR3(5.0f, 4.0f, 0.0f));
					scene->AddGameObject<CExplosion>(8)->SetTexture(SUMMON_LONG, CREATE_EFFECT_X, CREATE_EFFECT_Y, D3DXVECTOR3(250.0f, 5.6f, 65.0f), D3DXVECTOR3(5.0f, 4.0f, 0.0f));
				}
			}
			s_Count++;
			if (s_Count > 2000)
			{
				m_Scale.x -= 0.1f;
				m_Scale.y -= 0.02f;
			}
			if (s_Count > 2100)
			{
				SetDestroy();
			}
			if (s_Count % 5 == 0)
			{
				m_Count++;
			}
		}
	}
	CPlayer* Player = CManager::GetScene()->GetGameObject<CPlayer>(2);
	if (Type == GUN_SHOT_EFFECT)
	{
		m_Position.x = camera->GetPosition().x + (camera->GetFrontVec().x * 2.0f + camera->GetRightVec().x*0.65f);
		m_Position.z = camera->GetPosition().z + (camera->GetFrontVec().z * 2.0f + camera->GetRightVec().z*0.65f);
		m_Position.y = camera->GetPosition().y + camera->GetFrontVec().y - 0.15f;
	}
	if (Type == SHOTGUN_SHOT_EFFECT)
	{
		m_Position.x = camera->GetPosition().x + (camera->GetFrontVec().x * 2.0f + camera->GetRightVec().x*0.4f);
		m_Position.z = camera->GetPosition().z + (camera->GetFrontVec().z * 2.0f + camera->GetRightVec().z*0.4f);
		m_Position.y = camera->GetPosition().y + camera->GetFrontVec().y + 0.3f;
	}
	if (Type == RIFLEGUN_SHOT_EFFECT)
	{
		m_Position.x = camera->GetPosition().x + (camera->GetFrontVec().x * 2.0f + camera->GetRightVec().x*0.5f);
		m_Position.z = camera->GetPosition().z + (camera->GetFrontVec().z * 2.0f + camera->GetRightVec().z*0.5f);
		m_Position.y = camera->GetPosition().y + camera->GetFrontVec().y-0.1f ;
	}
	if (m_Count >= m_Length * m_Height && Type != BOSS_DOOR && Type != SUMMON_LONG && Type != SUMMON_SHORT)
	{
		SetDestroy();
		return;
	}
}

void CExplosion::Transparent()
{

}
void CExplosion::Draw()
{
	LIGHT light;
	light.Enable = false;
	CRenderer::SetLight(light);
	{
		float x = m_Count % m_Length * (1.0f / m_Length);
		float y = m_Count / m_Length * (1.0f / m_Height);

		D3D11_MAPPED_SUBRESOURCE msr;
		CRenderer::GetDeviceContext()->Map(m_VertexBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &msr);
		VERTEX_3D* vertex = (VERTEX_3D*)msr.pData;

		vertex[0].Position = D3DXVECTOR3(-1.0f, 1.0f, 0.0f);
		vertex[0].Normal = D3DXVECTOR3(0.0f, 0.0f, -1.0f);
		vertex[0].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[0].TexCoord = D3DXVECTOR2(x, y);

		vertex[1].Position = D3DXVECTOR3(1.0f, 1.0f, 0.0f);
		vertex[1].Normal = D3DXVECTOR3(0.0f, 0.0f, -1.0f);
		vertex[1].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[1].TexCoord = D3DXVECTOR2(x + (1.0f / m_Length), y);

		vertex[2].Position = D3DXVECTOR3(-1.0f, -1.0f, 0.0f);
		vertex[2].Normal = D3DXVECTOR3(0.0f, 0.0f, -1.0f);
		vertex[2].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[2].TexCoord = D3DXVECTOR2(x, y + (1.0f / m_Height));

		vertex[3].Position = D3DXVECTOR3(1.0f, -1.0f, 0.0f);
		vertex[3].Normal = D3DXVECTOR3(0.0f, 0.0f, -1.0f);
		vertex[3].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[3].TexCoord = D3DXVECTOR2(x + (1.0f / m_Length), y + (1.0f / m_Height));

		CRenderer::GetDeviceContext()->Unmap(m_VertexBuffer, 0);
	}
	CCamera* camera = CManager::GetScene()->GetGameObject<CCamera>(0);
	D3DXMATRIX view = camera->GetViewMatrix();
	D3DXMATRIX invView;
	D3DXMatrixInverse(&invView, NULL, &view);
	invView._41 = 0.0f;
	invView._42 = 0.0f;
	invView._43 = 0.0f;

	D3DXMATRIX world, scale, rot, trans;
	D3DXMatrixScaling(&scale, m_Scale.x, m_Scale.y, m_Scale.z);
	D3DXMatrixTranslation(&trans, m_Position.x, m_Position.y, m_Position.z);
	world = scale * invView * trans;
	CRenderer::SetWorldMatrix(&world);

	UINT stride = sizeof(VERTEX_3D);
	UINT offset = 0;
	CRenderer::GetDeviceContext()->IASetVertexBuffers(
		0, 1, &m_VertexBuffer, &stride, &offset);

	MATERIAL material;
	ZeroMemory(&material, sizeof(material));
	material.Diffuse = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	CRenderer::SetMaterial(material);

	if (Type == GUN_SHOT_EFFECT|| Type == SHOTGUN_SHOT_EFFECT||Type == RIFLEGUN_SHOT_EFFECT)
	{
		assert(Gun_Effect_Texture);
		CRenderer::GetDeviceContext()->PSSetShaderResources(0, 1, &Gun_Effect_Texture);
	}
	else if (Type == GUN_HIT)
	{
		assert(Gun_Hit_Texture);
		CRenderer::GetDeviceContext()->PSSetShaderResources(0, 1, &Gun_Hit_Texture);
	}
	else if (Type == SHOTGUN_HIT)
	{
		assert(ShotGun_Hit_Texture);
		CRenderer::GetDeviceContext()->PSSetShaderResources(0, 1, &ShotGun_Hit_Texture);
	}
	else if (Type == CREATE_EFFECT || Type == SUMMON_SHORT || Type == SUMMON_LONG)
	{
		assert(Create_Effect_Texture);
		CRenderer::GetDeviceContext()->PSSetShaderResources(0, 1, &Create_Effect_Texture);
	}
	else if (Type == BOSS_DOOR)
	{	
		assert(Boss_Door_Texture);
		CRenderer::GetDeviceContext()->PSSetShaderResources(0, 1, &Boss_Door_Texture);
	}
	else if (Type == HEADSHOT_HIT)
	{
		assert(HeadShot_Hit_Texture);
		CRenderer::GetDeviceContext()->PSSetShaderResources(0, 1, &HeadShot_Hit_Texture);
	}
	else if (Type == ENEMY_DISTROY)
	{
		assert(Enemy_Distroy_Texture);
		CRenderer::GetDeviceContext()->PSSetShaderResources(0, 1, &Enemy_Distroy_Texture);
	}
	else if (Type == BOOM_EFFECT)
	{
		assert(Boom_Effect_Texture);
		CRenderer::GetDeviceContext()->PSSetShaderResources(0, 1, &Boom_Effect_Texture);
	}
	CRenderer::GetDeviceContext()->IASetPrimitiveTopology(
		D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP);

	CRenderer::GetDeviceContext()->Draw(4, 0);
}


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
#include "stage4.h"
#include "stage5.h"
#include "trap.h"


ID3D11ShaderResourceView* CTrap::Shuriken_Texture;
ID3D11ShaderResourceView* CTrap::Skull_Texture;

CModel* CTrap::Model_Shuriken;
CModel* CTrap::Model_Spike;
CModel* CTrap::Model_Skull;

void CTrap::Load()
{
	D3DX11CreateShaderResourceViewFromFile(CRenderer::GetDevice(),
		"asset/texture/color/Black.jpg",
		NULL,
		NULL,
		&Shuriken_Texture,
		NULL);

	D3DX11CreateShaderResourceViewFromFile(CRenderer::GetDevice(),
		"asset/texture/color/Gray.png",
		NULL,
		NULL,
		&Skull_Texture,
		NULL);

	Model_Shuriken = new CModel();
	Model_Shuriken->Load("asset\\model\\trap\\shuriken.obj");

	Model_Spike = new CModel();
	Model_Spike->Load("asset\\model\\trap\\spike.obj");

	Model_Skull = new CModel();
	Model_Skull->Load("asset\\model\\trap\\skull.obj");
}

void CTrap::Unload()
{
	Model_Shuriken->Unload();
	delete Model_Shuriken;
	Model_Spike->Unload();
	delete Model_Spike;
	Shuriken_Texture->Release();
	Skull_Texture->Release();
	Model_Skull->Unload();
	delete Model_Skull;
}
void CTrap::Init()
{
	


	m_Position = D3DXVECTOR3(-80.0f, 1.0f, -275.0f);
	m_Rotation = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_Scale = D3DXVECTOR3(0.05f, 0.05f, 0.05f);

	m_Max = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_Min = D3DXVECTOR3(0.0f, 0.0f, 0.0f);




	m_Box = new CBox();
	m_Box->Init();
	SkullUp = false;
	SkullMove = SKULL_MOVE;
}

void CTrap::Uninit()
{
	m_Box->Destroy();
}

void CTrap::Update()
{
	m_Box->Update(m_Position, m_Min, m_Max);
	if (Type == SKULL)
	{
		if (CManager::SceneGet<CStage4>())
		{
			if (m_Position.z >= 95.0f)
			{
				SkullUp = false;
				m_Rotation.y += D3DXToRadian(180.0f);
			}
			if (m_Position.z <= 35.0f)
			{
				SkullUp = true;
				m_Rotation.y += D3DXToRadian(180.0f);
			}
			if (SkullUp)
			{
				SkullMove = SKULL_MOVE/2;
			}
			if (!SkullUp)
			{
				SkullMove = -SKULL_MOVE/2;
			}

		}
		else if (CManager::SceneGet<CStage5>())
		{
			if (m_Position.z >= 355.0f)
			{
				SkullUp = false;
				m_Rotation.y += D3DXToRadian(180.0f);
			}
			if (m_Position.z <= 225.0f)
			{
				SkullUp = true;
				m_Rotation.y += D3DXToRadian(180.0f);
			}
			if (SkullUp)
			{
				SkullMove = SKULL_MOVE;
			}
			if (!SkullUp)
			{
				SkullMove = -SKULL_MOVE;
			}

		}
		m_Position.z += SkullMove;

		
	}
	CCamera* Camera = CManager::GetScene()->GetGameObject<CCamera>(0);
	D3DXVECTOR3 Savevec = m_Position - Camera->GetPosition();
	float length = D3DXVec3Length(&Savevec);
	if (length < 50.0f)
	{
		if (Type == X_TRAP)
		{
			m_Rotation.x += D3DXToRadian(20.0f);
			if (!Trap_Move_X)
			{
				m_Position.x -= 0.5f;
			}
			else if (Trap_Move_X)
			{
				m_Position.x += 0.5f;
			}
		}
		if (Type == Z_TRAP)
		{
			m_Rotation.y += D3DXToRadian(30.0f);
			if (!Trap_Move_Z)
			{
				m_Position.z -= 0.1f;
			}
			else if (Trap_Move_Z)
			{
				m_Position.z += 0.1f;
			}
		}
	}

}

void CTrap::Transparent()
{
	CCamera* Camera = CManager::GetScene()->GetGameObject<CCamera>(0);
	D3DXVECTOR3 Savevec = m_Position - Camera->GetPosition();
	float length = D3DXVec3Length(&Savevec);
	if (length < 50.0f)
	{
		if (Type == X_TRAP)
		{
			m_Box->Draw(&xboxworld);
		}
		else if (Type == Z_TRAP)
		{
			m_Box->Draw(&zboxworld);
		}
	}

	if (length < 8.0f)
	{

		if (Type == SPIKE)
		{
			m_Box->Draw(&spikeboxworld);
		}
		else if (Type == SKULL)
		{
			m_Box->Draw(&skullboxworld);
		}
	}
}

void CTrap::Draw()
{
	//マトリクス設定

	D3DXMATRIX world, scale, rot, trans,xboxscale,zboxscale,spikeboxscale,spikeboxtrans,skullboxscale;
	D3DXMatrixScaling(&scale, m_Scale.x, m_Scale.y, m_Scale.z);
	D3DXMatrixScaling(&xboxscale, m_Scale.x*3.0f, m_Scale.y*5.0f, m_Scale.z*2.0f);
	D3DXMatrixScaling(&zboxscale, m_Scale.x*0.5f, m_Scale.y*3.5f, m_Scale.z*1.5f);

	D3DXMatrixRotationYawPitchRoll(&rot, m_Rotation.y, m_Rotation.x, m_Rotation.z);
	D3DXMatrixTranslation(&trans, m_Position.x, m_Position.y, m_Position.z);

	D3DXMatrixScaling(&spikeboxscale, m_Scale.x*1.0f, m_Scale.y*1.0f, m_Scale.z*1.0f);
	D3DXMatrixTranslation(&spikeboxtrans, m_Position.x, m_Position.y+0.3f, m_Position.z);

	D3DXMatrixScaling(&skullboxscale, m_Scale.x*1.5f, m_Scale.y*1.5f, m_Scale.z*1.5f);
	
		world = scale * rot* trans;
	
	zboxworld = zboxscale * trans;
	xboxworld = xboxscale* trans;
	spikeboxworld = spikeboxscale * spikeboxtrans;
	skullboxworld = skullboxscale * trans;
	CRenderer::SetWorldMatrix(&world);
	//テクスチャ設定
	assert(Shuriken_Texture);
	CRenderer::GetDeviceContext()->PSSetShaderResources(0, 1, &Shuriken_Texture);

	//モデル描画
	CCamera* Camera = CManager::GetScene()->GetGameObject<CCamera>(0);
	D3DXVECTOR3 Savevec = m_Position - Camera->GetPosition();
	float length = D3DXVec3Length(&Savevec);
	if (length < 150.0f)
	{
		if (Type == X_TRAP || Type == Z_TRAP)
		{
			Model_Shuriken->Draw();
		}
		else if (Type == SPIKE)
		{
			Model_Spike->Draw();
		}
		else if (Type == SKULL)
		{
			assert(Skull_Texture);
			CRenderer::GetDeviceContext()->PSSetShaderResources(0, 1, &Skull_Texture);
			Model_Skull->Draw();
		}
	}



}


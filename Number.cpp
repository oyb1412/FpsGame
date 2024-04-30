#include "main.h"
#include "renderer.h"
#include "manager.h"
#include "scene.h"
#include "Number.h"
#include "camera.h"
#include "collision.h"
#include "enemy.h"
ID3D11ShaderResourceView* CNumber::Black_Number_Texture;
ID3D11ShaderResourceView* CNumber::Red_Number_Texture;
void CNumber::Load()
{
	D3DX11CreateShaderResourceViewFromFile(CRenderer::GetDevice(),
		"asset/texture/number/Number.png",
		NULL,
		NULL,
		&Black_Number_Texture,
		NULL);

	D3DX11CreateShaderResourceViewFromFile(CRenderer::GetDevice(),
		"asset/texture/number/Red_Number.png",
		NULL,
		NULL,
		&Red_Number_Texture,
		NULL);


}

void CNumber::Unload()
{
	Black_Number_Texture->Release();
	Red_Number_Texture->Release();
}
void CNumber::Init()
{

	VERTEX_3D vertex[4];

	vertex[0].Position = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	vertex[0].Normal = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	vertex[0].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
	vertex[0].TexCoord = D3DXVECTOR2(0.0f, 0.0f);

	vertex[1].Position = D3DXVECTOR3(200.0f, 0.0f, 0.0f);
	vertex[1].Normal = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	vertex[1].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
	vertex[1].TexCoord = D3DXVECTOR2(1.0f, 0.0f);

	vertex[2].Position = D3DXVECTOR3(0.0f, 200.0f, 0.0f);
	vertex[2].Normal = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	vertex[2].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
	vertex[2].TexCoord = D3DXVECTOR2(0.0f, 1.0f);

	vertex[3].Position = D3DXVECTOR3(200.0f, 200.0f, 0.0f);
	vertex[3].Normal = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
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


	//テクスチャ



	m_Position = D3DXVECTOR3(SCREEN_WIDTH / 2 - 50, SCREEN_HEIGHT / 2 - 50, 0.0f);
	m_Rotation = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_Scale = D3DXVECTOR3(0.5f, 0.5f, 0.0f);

	m_Count = 30;
}

void CNumber::Uninit()
{
	m_VertexBuffer->Release();
}

void CNumber::Update()
{
	CPlayer* Player = CManager::GetScene()->GetGameObject<CPlayer>(2);
	CCamera* Camera = CManager::GetScene()->GetGameObject<CCamera>(0);

	if (Player->GetWeaponType() == SMALLGUN)
	{
		if (Type == BULLET_NUMBER)
		{
			m_Count = Player->GetBulletNumber(SMALLGUN);
		}
		else if (Type == MAX_BULLET_NUMBER)
		{
			m_Count = Player->GetMaxBulletNumber(SMALLGUN);
		}
	}
	if (Player->GetWeaponType() == SHOTGUN)
	{
		if (Type == BULLET_NUMBER)
		{
			m_Count = Player->GetBulletNumber(SHOTGUN);
		}
		else if (Type == MAX_BULLET_NUMBER)
		{
			m_Count = Player->GetMaxBulletNumber(SHOTGUN);
		}
	}
	if (Player->GetWeaponType() == RIFLEGUN)
	{
		if (Type == BULLET_NUMBER)
		{
			m_Count = Player->GetBulletNumber(RIFLEGUN);
		}
		else if (Type == MAX_BULLET_NUMBER)
		{
			m_Count = Player->GetMaxBulletNumber(RIFLEGUN);
		}
	}
	if (Player->GetWeaponType() == BAZOOKA)
	{
		if (Type == BULLET_NUMBER)
		{
			m_Count = Player->GetBulletNumber(BAZOOKA);
		}
		else if (Type == MAX_BULLET_NUMBER)
		{
			m_Count = Player->GetMaxBulletNumber(BAZOOKA);
		}
	}
	std::vector<CEnemy*> EnemyList = CManager::GetScene()->GetGameObjects<CEnemy>(8);
	CEnemy* Boss = CManager::GetScene()->GetGameObject<CEnemy>(9);

	if (Type == HP_NUMBER)
	{
		m_Count = Player->GetPlayerHp();
	}
	if (Type == ENEMY_NUMBER)
	{
		m_Count = EnemyList.size()-1;
	}
	
}

void CNumber::Transparent()
{

}

void CNumber::Draw()
{
	LIGHT light;
	light.Enable = false;
	CRenderer::SetLight(light);
	D3DXMATRIX world, scale, rot, trans;
	int Score = m_Count;

	for (int i = Max_Number; i > 0; i--)
	{
		int x = Score % 10;
		D3D11_MAPPED_SUBRESOURCE msr;
		CRenderer::GetDeviceContext()->Map(m_VertexBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &msr);
		VERTEX_3D* vertex = (VERTEX_3D*)msr.pData;

		vertex[0].Position = D3DXVECTOR3(0.0f + (i *200), 0.0f, 0.0f);
		vertex[0].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[0].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[0].TexCoord = D3DXVECTOR2(x*0.099f, 0.0f);

		vertex[1].Position = D3DXVECTOR3(200.0f + (i * 200), 0.0f, 0.0f);
		vertex[1].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[1].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[1].TexCoord = D3DXVECTOR2(x*0.099f + 0.1f, 0.0f);

		vertex[2].Position = D3DXVECTOR3(0.0f + (i * 200), 200.0f, 0.0f);
		vertex[2].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[2].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[2].TexCoord = D3DXVECTOR2(x*0.099f, 1.0f);

		vertex[3].Position = D3DXVECTOR3(200.0f + (i * 200), 200.0f, 0.0f);
		vertex[3].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[3].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[3].TexCoord = D3DXVECTOR2(x*0.099f + 0.1f, 1.0f);

	CRenderer::GetDeviceContext()->Unmap(m_VertexBuffer, 0);

	D3DXMatrixScaling(&scale, m_Scale.x, m_Scale.y, m_Scale.z);
	D3DXMatrixRotationYawPitchRoll(&rot, m_Rotation.y, m_Rotation.x, m_Rotation.z);
	D3DXMatrixTranslation(&trans, m_Position.x, m_Position.y, m_Position.z);
	world = scale * rot * trans;
	//マトリクス設定
	CRenderer::SetWorldViewProjection2D();

	//頂点バッファ
	UINT stride = sizeof(VERTEX_3D);
	UINT offset = 0;
	CRenderer::GetDeviceContext()->IASetVertexBuffers(
		0, 1, &m_VertexBuffer, &stride, &offset);

	MATERIAL material;
	ZeroMemory(&material, sizeof(material));
	material.Diffuse = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	CRenderer::SetMaterial(material);

	//テクスチャ設定
	if (Type == BULLET_NUMBER || Type == MAX_BULLET_NUMBER)
	{
		assert(Black_Number_Texture);
		CRenderer::GetDeviceContext()->PSSetShaderResources(0, 1, &Black_Number_Texture);
	}


	if (Type == HP_NUMBER || Type == ENEMY_NUMBER)
	{
		assert(Red_Number_Texture);
		CRenderer::GetDeviceContext()->PSSetShaderResources(0, 1, &Red_Number_Texture);
	}

	

	//プリミティブトポロジ設定
	CRenderer::GetDeviceContext()->IASetPrimitiveTopology(
		D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP);
	CRenderer::SetWorldMatrix(&world);

	//ポリゴン描画
	CRenderer::GetDeviceContext()->Draw(4, 0);
	Score /= 10;

	}
}


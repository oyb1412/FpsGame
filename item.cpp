#include "main.h"
#include "manager.h"
#include "renderer.h"
#include "model.h"
#include "Player.h"
#include "item.h"
#include "box.h"
#include "2dbox.h"
#include "input.h"
#include "camera.h"
#include "scene.h"
#include "stage3.h"
#include "stage4.h"
#include "stage5.h"
#include "Stage6.h"
ID3D11ShaderResourceView* CItem::Bullet;
ID3D11ShaderResourceView* CItem::Heart;
ID3D11ShaderResourceView* CItem::Key_Texture;

void CItem::Load()
{


	D3DX11CreateShaderResourceViewFromFile(CRenderer::GetDevice(),
		"asset/texture/item/Bullet.png",
		NULL,
		NULL,
		&Bullet,
		NULL);

	D3DX11CreateShaderResourceViewFromFile(CRenderer::GetDevice(),
		"asset/texture/item/Heart.png",
		NULL,
		NULL,
		&Heart,
		NULL);

	D3DX11CreateShaderResourceViewFromFile(CRenderer::GetDevice(),
		"asset/texture/item/Key.png",
		NULL,
		NULL,
		&Key_Texture,
		NULL);
}

void CItem::Unload()
{
	Bullet->Release();
	Heart->Release();
	Key_Texture->Release();
}
void CItem::Init()
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
	bd.Usage = D3D11_USAGE_DEFAULT;
	bd.ByteWidth = sizeof(VERTEX_3D) * 4;
	bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	bd.CPUAccessFlags = 0;
	bd.MiscFlags = 0;
	bd.StructureByteStride = 0;

	D3D11_SUBRESOURCE_DATA sd;
	ZeroMemory(&sd, sizeof(sd));
	sd.pSysMem = vertex;

	CRenderer::GetDevice()->CreateBuffer(&bd, &sd, &m_VertexBuffer);

	m_Position = D3DXVECTOR3(0.0f, 0.5f, 0.0f);
	m_Rotation = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_Scale = D3DXVECTOR3(1.0f, 1.0f, 1.0f);
	m_Max = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_Min = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	
	Item_Shake = false;
}

void CItem::Update()
{
	if (CManager::SceneGet<CStage3>() )
	{
		if (m_Position.z > 240.0f)
		{
			if (!Item_Shake && m_Position.y < 9.0f)
			{
				m_Position.y += 0.05f;
			}
			if (!Item_Shake && m_Position.y >= 9.0f)
			{
				Item_Shake = true;
			}
			if (Item_Shake && m_Position.y > 8.0f)
			{
				m_Position.y -= 0.05f;
			}
			if (Item_Shake && m_Position.y <= 8.0f)
			{
				Item_Shake = false;
			}
		}
		else
		{
			if (!Item_Shake && m_Position.y < 4.0f)
			{
				m_Position.y += 0.05f;
			}
			if (!Item_Shake && m_Position.y >= 4.0f)
			{
				Item_Shake = true;
			}
			if (Item_Shake && m_Position.y > 3.0f)
			{
				m_Position.y -= 0.05f;
			}
			if (Item_Shake && m_Position.y <= 3.0f)
			{
				Item_Shake = false;
			}
		}
	}
	if (CManager::SceneGet<CStage4>() || CManager::SceneGet<CStage5>() || CManager::SceneGet<CStage6>())
	{
		if (!Item_Shake && m_Position.y < 5.0f)
		{
			m_Position.y += 0.05f;
		}
		if (!Item_Shake && m_Position.y >= 5.0f)
		{
			Item_Shake = true;
		}
		if (Item_Shake && m_Position.y > 4.0f)
		{
			m_Position.y -= 0.05f;
		}
		if (Item_Shake && m_Position.y <= 4.0f)
		{
			Item_Shake = false;
		}
	}
}
void CItem::Transparent()
{

}
void CItem::Uninit() 
{
	
}

void CItem::Draw()
{
	LIGHT light;
	light.Enable = false;
	CRenderer::SetLight(light);
	CCamera* camera = CManager::GetScene()->GetGameObject<CCamera>(0);
	D3DXMATRIX view = camera->GetViewMatrix();
	D3DXMATRIX invView;
	D3DXMatrixInverse(&invView, NULL, &view);
	invView._41 = 0.0f;
	invView._42 = 0.0f;
	invView._43 = 0.0f;

	D3DXMATRIX world, scale, rot, trans;
	D3DXMatrixScaling(&scale, m_Scale.x, m_Scale.y, m_Scale.z);
	D3DXMatrixRotationYawPitchRoll(&rot, m_Rotation.y, m_Rotation.x, m_Rotation.z);
	D3DXMatrixTranslation(&trans, m_Position.x, m_Position.y, m_Position.z);
	world = scale * invView * trans;

	UINT stride = sizeof(VERTEX_3D);
	UINT offset = 0;
	CRenderer::GetDeviceContext()->IASetVertexBuffers(
		0, 1, &m_VertexBuffer, &stride, &offset);

	MATERIAL material;
	ZeroMemory(&material, sizeof(material));
	material.Diffuse = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	CRenderer::SetMaterial(material);
	if (Type == TYPE_ITEM_BULLET)
	{
		assert(Bullet);
		CRenderer::GetDeviceContext()->PSSetShaderResources(0, 1, &Bullet);
	}
	else if (Type == TYPE_ITEM_HEART)
	{
		assert(Heart);
		CRenderer::GetDeviceContext()->PSSetShaderResources(0, 1, &Heart);
	}
	else if (Type == TYPE_ITEM_KEY)
	{
		assert(Key_Texture);
		CRenderer::GetDeviceContext()->PSSetShaderResources(0, 1, &Key_Texture);
	}


	CRenderer::SetWorldMatrix(&world);

	CRenderer::GetDeviceContext()->IASetPrimitiveTopology(
		D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP);

	//?ƒŠƒSƒ“?‰æ
	CRenderer::GetDeviceContext()->Draw(4, 0);
}

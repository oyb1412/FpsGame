#include "main.h"
#include "renderer.h"
#include "filed.h"
#include "input.h"
#include "light.h"
#include "wall.h"
#include "box.h"
#include "model.h"
#include "manager.h"
#include "stage3.h"
#include "stage4.h"
#include "stage5.h"
#include "Stage6.h"
#include "warning.h"
#include <time.h>
#include "3dpolygon.h"


ID3D11ShaderResourceView* CWarning::Warning_Texture;

void CWarning::Load()
{

	//テクスチャ
	D3DX11CreateShaderResourceViewFromFile(CRenderer::GetDevice(),
		"asset/texture/color/Red.jpg",
		NULL,
		NULL,
		&Warning_Texture,
		NULL);

	assert(Warning_Texture);

}
void CWarning::Unload()
{
	Warning_Texture->Release();
	
}
void CWarning::Init()
{
	VERTEX_3D vertex[4];

	vertex[0].Position = D3DXVECTOR3(-0.5f, 0.0f, 0.5f);
	vertex[0].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	vertex[0].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
	vertex[0].TexCoord = D3DXVECTOR2(0.0f, 0.0f);

	vertex[1].Position = D3DXVECTOR3(0.5f, 0.0f, 0.5f);
	vertex[1].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	vertex[1].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
	vertex[1].TexCoord = D3DXVECTOR2(1.0f, 0.0f);

	vertex[2].Position = D3DXVECTOR3(-0.5f, 0.0f, -0.5f);
	vertex[2].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	vertex[2].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
	vertex[2].TexCoord = D3DXVECTOR2(0.0f, 1.0f);

	vertex[3].Position = D3DXVECTOR3(0.5f, 0.0f, -0.5f);
	vertex[3].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	vertex[3].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
	vertex[3].TexCoord = D3DXVECTOR2(1.0f,1.0f);

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

	Fade = 1.0f;
}

void CWarning::Uninit()
{
	if (m_VertexBuffer != NULL)
	{
		m_VertexBuffer->Release();
	}
}

void CWarning::Update()
{
	CScene* scene = CManager::GetScene();

	Fade -= 0.006f;
	if (Fade <= 0.0f)
	{
		if (CManager::SceneGet<CStage6>())
		{
			scene->AddGameObject<C3dpolygon>(1)->SetObject(D3DXVECTOR3(m_Position.x + 5.0f, m_Position.y + 10.0f, m_Position.z), D3DXVECTOR3(m_Scale.x*0.2f, 5.0f, m_Scale.z*0.2f), ROCK_POLYGON);
		}
		else
		{
			scene->AddGameObject<C3dpolygon>(1)->SetObject(D3DXVECTOR3(m_Position.x + 5.0f, m_Position.y + 10.0f, m_Position.z + 5.0f), D3DXVECTOR3(m_Scale.x*0.2f, 5.0f, m_Scale.z*0.2f), ROCK_POLYGON);

		}
		SetDestroy();
	}

}

void CWarning::Transparent()
{
	
}
void CWarning::Draw()
{
	CLight::SetLight(FIELD_LIGHT);




	D3DXMATRIX world, scale, rot, trans, Rtrans1, Rtrans2;

	D3DXMatrixScaling(&scale, m_Scale.x, m_Scale.y, m_Scale.z);

	D3DXMatrixRotationYawPitchRoll(&rot, m_Rotation.y, m_Rotation.x, m_Rotation.z);
	D3DXMatrixTranslation(&trans, m_Position.x, m_Position.y, m_Position.z);

	D3DXMatrixTranslation(&Rtrans1, 0.0f, 0.0f, m_Scale.z*0.5f - 0.5f);
	D3DXMatrixTranslation(&Rtrans2, m_Scale.x*0.5f - 0.5f, 0.0f, 0.0f);

	world = scale * rot * trans;


	if (m_Scale.z > 1.0f)
	{
		world = scale * rot * Rtrans1 * trans;

	}
	if (m_Scale.x > 1.0f)
	{
		world = scale * rot * Rtrans2  * trans;

	}
	if (m_Scale.z > 1.0f && m_Scale.x > 1.0f)
	{
		world = scale * Rtrans1 * Rtrans2 * rot * trans;

	}

	CRenderer::SetWorldMatrix(&world);
	//マトリクス設定

	//頂点バッファ
	UINT stride = sizeof(VERTEX_3D);
	UINT offset = 0;
	CRenderer::GetDeviceContext()->IASetVertexBuffers(
		0, 1, &m_VertexBuffer, &stride, &offset);

	MATERIAL material;
	ZeroMemory(&material, sizeof(material));
	
		material.Diffuse = D3DXCOLOR(1.0f, 1.0f, 1.0f, Fade);


	CRenderer::SetMaterial(material);
	//テクスチャ設定
	
		CRenderer::GetDeviceContext()->PSSetShaderResources(0, 1, &Warning_Texture);
		
	
	//プリミティブトポロジ設定
	CRenderer::GetDeviceContext()->IASetPrimitiveTopology(
		D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP);

		//ポリゴン描画
		CRenderer::GetDeviceContext()->Draw(4, 0);


}


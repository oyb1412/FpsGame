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
#include <time.h>


CModel* CField::Bridge_Model;
CModel* CField::Soil_Model;
ID3D11ShaderResourceView* CField::Field_Texture;
ID3D11ShaderResourceView* CField::Ceiling_Texture;
ID3D11ShaderResourceView* CField::Bridge_Texture;
ID3D11ShaderResourceView* CField::SmallBridge_Texture;
ID3D11ShaderResourceView* CField::Grass_Texture;
ID3D11ShaderResourceView* CField::FactoryField_Texture;
ID3D11ShaderResourceView* CField::FactoryFloor_Texture;
ID3D11ShaderResourceView* CField::Brick_Texture;
ID3D11ShaderResourceView* CField::Scaffold_Texture;
void CField::Load()
{
	Bridge_Model = new CModel();
	Bridge_Model->Load("asset\\model\\field\\bridge.obj");

	Soil_Model = new CModel();
	Soil_Model->Load("asset\\model\\field\\soil.obj");
	//テクス?ャ
	D3DX11CreateShaderResourceViewFromFile(CRenderer::GetDevice(),
		"asset/texture/wall/Wall2.jpg",
		NULL,
		NULL,
		&Brick_Texture,
		NULL);

	assert(Brick_Texture);

	D3DX11CreateShaderResourceViewFromFile(CRenderer::GetDevice(),
		"asset/texture/field/Factory_Floor.jpg",
		NULL,
		NULL,
		&FactoryFloor_Texture,
		NULL);

	assert(FactoryFloor_Texture);

	D3DX11CreateShaderResourceViewFromFile(CRenderer::GetDevice(),
		"asset/texture/field/Factory_Field.jpg",
		NULL,
		NULL,
		&FactoryField_Texture,
		NULL);

	assert(FactoryField_Texture);

	D3DX11CreateShaderResourceViewFromFile(CRenderer::GetDevice(),
		"asset/texture/field/Scaffold_Texture.jpg",
		NULL,
		NULL,
		&Scaffold_Texture,
		NULL);

	assert(Scaffold_Texture);
	D3DX11CreateShaderResourceViewFromFile(CRenderer::GetDevice(),
		"asset/texture/field/Field_Texture.png",
		NULL,
		NULL,
		&Field_Texture,
		NULL);

	assert(Field_Texture);

	D3DX11CreateShaderResourceViewFromFile(CRenderer::GetDevice(),
		"asset/texture/wall/Ceiling_Texture.jpg",
		NULL,
		NULL,
		&Ceiling_Texture,
		NULL);

	assert(Ceiling_Texture);

	D3DX11CreateShaderResourceViewFromFile(CRenderer::GetDevice(),
		"asset/texture/field/Grass_Texture.jpg",
		NULL,
		NULL,
		&Grass_Texture,
		NULL);

	D3DX11CreateShaderResourceViewFromFile(CRenderer::GetDevice(),
		"asset/texture/color/Black.jpg",
		NULL,
		NULL,
		&Bridge_Texture,
		NULL);

	D3DX11CreateShaderResourceViewFromFile(CRenderer::GetDevice(),
		"asset/texture/field/SmallBridge_Texture.jpg",
		NULL,
		NULL,
		&SmallBridge_Texture,
		NULL);

	assert(Grass_Texture);
}
void CField::Unload()
{
	Brick_Texture->Release();
	FactoryFloor_Texture->Release();
	FactoryField_Texture->Release();
	Scaffold_Texture->Release();
	Field_Texture->Release();
	Grass_Texture->Release();
	Bridge_Texture->Release();
	Ceiling_Texture->Release();
	SmallBridge_Texture->Release();

	Bridge_Model->Unload();
	delete Bridge_Model;
	Soil_Model->Unload();
	delete Soil_Model;
}
void CField::Init()
{
	VERTEX_3D vertex[4];

	vertex[0].Position = D3DXVECTOR3(-0.5f, 0.0f, 0.5f);
	vertex[0].Normal = D3DXVECTOR3(0.0f, m_Normal, 0.0f);
	vertex[0].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
	vertex[0].TexCoord = D3DXVECTOR2(0.0f, 0.0f);

	vertex[1].Position = D3DXVECTOR3(0.5f, 0.0f, 0.5f);
	vertex[1].Normal = D3DXVECTOR3(0.0f, m_Normal, 0.0f);
	vertex[1].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
	vertex[1].TexCoord = D3DXVECTOR2(m_Scale.x / UV_X, 0.0f);

	vertex[2].Position = D3DXVECTOR3(-0.5f, 0.0f, -0.5f);
	vertex[2].Normal = D3DXVECTOR3(0.0f, m_Normal, 0.0f);
	vertex[2].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
	vertex[2].TexCoord = D3DXVECTOR2(0.0f, m_Scale.z / UV_X);

	vertex[3].Position = D3DXVECTOR3(0.5f, 0.0f, -0.5f);
	vertex[3].Normal = D3DXVECTOR3(0.0f, m_Normal, 0.0f);
	vertex[3].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
	vertex[3].TexCoord = D3DXVECTOR2(m_Scale.x / UV_X, m_Scale.z / UV_X);
	
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

	srand((unsigned int)time(NULL));
	
	m_Box = new CBox();
	m_Box->Init();
	ModelType = 0;
	BridgeMoveCount = 0.0f;
	BridgeMove = false;
	FadeType = false;
	FadeCount = 0.0f;
	RailCount = 0;
	m_Position = D3DXVECTOR3(0.0f, 0.0f, -50.0f);
	m_Rotation = D3DXVECTOR3(0.0f, 0.0f,0.0f);
	m_Scale = D3DXVECTOR3(10.0f,0.5f, 25.0f);
}

void CField::Uninit()
{
	if (m_VertexBuffer != NULL)
	{
		m_VertexBuffer->Release();
	}
	m_Box->Destroy();
}

void CField::Update()
{
	m_Box->Update(m_Position, m_Min, m_Max);
	RandomFade = rand() % 100;
	FadeCount = RandomFade * 0.0001f;
	if (Type == SCAFFOLD)
	{
		if (Fade <= 0.0f)
		{
			FadeType = true;
		}
		else if (Fade >= 1.0f)
		{
			FadeType = false;
		}

		if (FadeType)
		{
			Fade += 0.003f;
		}

		if (!FadeType)
		{
			Fade -= 0.003f;
		}
	}
	if (ModelType == SMALLBRIDGE)
	{
		m_Position.x += BridgeMoveCount;
		if (m_Position.x <= 0.0f)
		{
			BridgeMove = true;
		}
		if (m_Position.x >= 60.0f)
		{
			BridgeMove = false;
		}
		if (BridgeMove)
		{
			BridgeMoveCount = 0.2f;
		}
		if (!BridgeMove)
		{
			BridgeMoveCount = -0.2f;
		}
	}

}

void CField::Transparent()
{
	if (Type != SCAFFOLD  && ModelType != SMALLBRIDGE && ModelType != BRIDGE)
	{
		m_Box->Draw(&boxworld);
	}
	if (ModelType == BRIDGE)
	{
		CCamera* Camera = CManager::GetScene()->GetGameObject<CCamera>(0);
		D3DXVECTOR3 Savevec = m_Position - Camera->GetPosition();
		float length = D3DXVec3Length(&Savevec);
		if (length < 60.0f)
		{
			m_Box->Draw(&boxworld);
		}
	}
	if (Type == SCAFFOLD || ModelType == SMALLBRIDGE)
	{
		CCamera* Camera = CManager::GetScene()->GetGameObject<CCamera>(0);
		D3DXVECTOR3 Savevec = m_Position - Camera->GetPosition();
		float length = D3DXVec3Length(&Savevec);
		if (length < 30.0f)
		{
			m_Box->Draw(&boxworld);
		}
	}


}
void CField::Draw()
{
	CLight::SetLight(FIELD_LIGHT);

	D3D11_MAPPED_SUBRESOURCE msr;
	CRenderer::GetDeviceContext()->Map(m_VertexBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &msr);
	VERTEX_3D* vertex = (VERTEX_3D*)msr.pData;

	vertex[0].Position = D3DXVECTOR3(-0.5f, 0.0f, 0.5f);
	vertex[0].Normal = D3DXVECTOR3(0.0f, m_Normal, 0.0f);
	vertex[0].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
	vertex[0].TexCoord = D3DXVECTOR2(0.0f, 0.0f);

	vertex[1].Position = D3DXVECTOR3(0.5f, 0.0f, 0.5f);
	vertex[1].Normal = D3DXVECTOR3(0.0f, m_Normal, 0.0f);
	vertex[1].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
	vertex[1].TexCoord = D3DXVECTOR2(m_Scale.x / UV_X, 0.0f);

	vertex[2].Position = D3DXVECTOR3(-0.5f, 0.0f, -0.5f);
	vertex[2].Normal = D3DXVECTOR3(0.0f, m_Normal, 0.0f);
	vertex[2].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
	vertex[2].TexCoord = D3DXVECTOR2(0.0f, m_Scale.z / UV_X);

	vertex[3].Position = D3DXVECTOR3(0.5f, 0.0f, -0.5f);
	vertex[3].Normal = D3DXVECTOR3(0.0f, m_Normal, 0.0f);
	vertex[3].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
	vertex[3].TexCoord = D3DXVECTOR2(m_Scale.x / UV_X, m_Scale.z / UV_X);

	CRenderer::GetDeviceContext()->Unmap(m_VertexBuffer, 0);

	
	D3DXMATRIX world, scale, rot, trans, Rtrans1, Rtrans2,Rtrans3,boxtrans,soilworld,soilscale,soiltrans,boxscale;
	
		D3DXMatrixScaling(&scale, m_Scale.x, m_Scale.y, m_Scale.z);

	D3DXMatrixRotationYawPitchRoll(&rot, m_Rotation.y, m_Rotation.x, m_Rotation.z);
	D3DXMatrixTranslation(&trans, m_Position.x, m_Position.y, m_Position.z);
	D3DXMatrixTranslation(&boxtrans, m_Position.x, m_Position.y+1.5f, m_Position.z);

	D3DXMatrixTranslation(&Rtrans1, 0.0f, 0.0f, m_Scale.z*0.5f - 0.5f);
	D3DXMatrixTranslation(&Rtrans2, m_Scale.x*0.5f - 0.5f, 0.0f, 0.0f);
	D3DXMatrixTranslation(&Rtrans3, -m_Scale.x*0.5f - 0.5f, 0.0f, 0.0f);

	D3DXMatrixTranslation(&soiltrans, m_Position.x, m_Position.y -5.1f, m_Position.z);
	D3DXMatrixScaling(&soilscale, m_Scale.x*0.5f, m_Scale.y*10.0f, m_Scale.z*0.5f);
	D3DXMatrixScaling(&boxscale, m_Scale.x*0.0f, m_Scale.y*0.0f, m_Scale.z*0.0f);

	soilworld = soilscale * rot * soiltrans;
	boxworld = scale * rot * boxtrans;
	world = scale * rot * trans;
	

	if (m_Scale.z > 1.0f)
	{
		world = scale * rot * Rtrans1 * trans;
		boxworld = scale * rot* Rtrans1 * boxtrans;
		soilworld = soilscale * rot* Rtrans1 * soiltrans;

	}
	if (m_Scale.x > 1.0f)
	{
		world = scale * rot * Rtrans2  * trans;
		boxworld = scale * rot* Rtrans2 * boxtrans;
		soilworld = soilscale * rot* Rtrans2 * soiltrans;

	}
	if (m_Scale.z > 1.0f && m_Scale.x > 1.0f)
	{
		world = scale * Rtrans1 * Rtrans2 * rot * trans;
		boxworld = scale * Rtrans1 * Rtrans2* rot * boxtrans;
		soilworld = soilscale * rot* Rtrans1* Rtrans2 * soiltrans;

	}
	if (Type == SCAFFOLD && Fade < 0.2f)
	{
		boxworld = boxscale * rot * boxtrans;
	}
	CRenderer::SetWorldMatrix(&world);
	//?トリクス設定

	//頂?バッフ?
	UINT stride = sizeof(VERTEX_3D);
	UINT offset = 0;
	CRenderer::GetDeviceContext()->IASetVertexBuffers(
		0, 1, &m_VertexBuffer, &stride, &offset);

	MATERIAL material;
	ZeroMemory(&material, sizeof(material));
	if (Type == SCAFFOLD)
	{
		material.Diffuse = D3DXCOLOR(1.0f, 1.0f, 1.0f, Fade);
	}
	else
	{
		material.Diffuse = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

	}
	CRenderer::SetMaterial(material);
	//テクス?ャ設定
	if (CManager::SceneGet<CStage5>())
	{
		CRenderer::GetDeviceContext()->PSSetShaderResources(0, 1, &FactoryField_Texture);
		if (Type == SCAFFOLD)
		{
			CRenderer::GetDeviceContext()->PSSetShaderResources(0, 1, &Scaffold_Texture);

		}
		if (Type == FLOOR)
		{
			CRenderer::GetDeviceContext()->PSSetShaderResources(0, 1, &FactoryFloor_Texture);

		}
		if (Type == CEILING)
		{
			CRenderer::GetDeviceContext()->PSSetShaderResources(0, 1, &Ceiling_Texture);
		}
	}
	if (CManager::SceneGet<CStage3>())
	{
		CRenderer::GetDeviceContext()->PSSetShaderResources(0, 1, &Field_Texture);
		if (Type == CEILING)
		{
			CRenderer::GetDeviceContext()->PSSetShaderResources(0, 1, &Ceiling_Texture);
		}
	}
	if (CManager::SceneGet<CStage4>())
	{
		CRenderer::GetDeviceContext()->PSSetShaderResources(0, 1, &Grass_Texture);
		if (ModelType == BRIDGE)
		{
			CRenderer::GetDeviceContext()->PSSetShaderResources(0, 1, &Bridge_Texture);
		}

	}
	if (CManager::SceneGet<CStage6>())
	{
		CRenderer::GetDeviceContext()->PSSetShaderResources(0, 1, &Brick_Texture);

	}
	//プリ?ティブト?ロジ設定
	CRenderer::GetDeviceContext()->IASetPrimitiveTopology(
		D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP);
	if (ModelType != BRIDGE && ModelType != SMALLBRIDGE )
	{
		//?リゴン?画
		CRenderer::GetDeviceContext()->Draw(4, 0);
		if (CManager::SceneGet<CStage4>())
		{
			CRenderer::SetWorldMatrix(&soilworld);

			CRenderer::GetDeviceContext()->PSSetShaderResources(0, 1, &SmallBridge_Texture);
			Soil_Model->Draw();
		}
		if (CManager::SceneGet<CStage5>() && Type != SCAFFOLD && Type != FLOOR && Type != CEILING)
		{
			CRenderer::SetWorldMatrix(&soilworld);

			CRenderer::GetDeviceContext()->PSSetShaderResources(0, 1, &SmallBridge_Texture);
			Soil_Model->Draw();
		}
		
	}
	else
	{
		Bridge_Model->Draw();
	}

}


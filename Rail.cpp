#include "main.h"
#include "renderer.h"
#include "manager.h"
#include "scene.h"
#include "explosion.h"
#include "camera.h"
#include "light.h"
#include "Rail.h"
#include "model.h"
ID3D11ShaderResourceView* CRail::RightRail_Texture;
ID3D11ShaderResourceView* CRail::LeftRail_Texture;
ID3D11ShaderResourceView* CRail::DownRail_Texture;
CModel* CRail::Soil_Model;

void CRail::Load()
{
	//テクス?ャ

	Soil_Model = new CModel();
	Soil_Model->Load("asset\\model\\field\\soil.obj");

	D3DX11CreateShaderResourceViewFromFile(CRenderer::GetDevice(),
		"asset/texture/rail/Right_Rail.png",
		NULL,
		NULL,
		&RightRail_Texture,
		NULL);

	D3DX11CreateShaderResourceViewFromFile(CRenderer::GetDevice(),
		"asset/texture/rail/Left_Rail.png",
		NULL,
		NULL,
		&LeftRail_Texture,
		NULL);

	D3DX11CreateShaderResourceViewFromFile(CRenderer::GetDevice(),
		"asset/texture/rail/Down_Rail.png",
		NULL,
		NULL,
		&DownRail_Texture,
		NULL);

}

void CRail::Unload()
{
	RightRail_Texture->Release();
	LeftRail_Texture->Release();
	DownRail_Texture->Release();
	Soil_Model->Unload();
	delete Soil_Model;
}
void CRail::Init()
{
	VERTEX_3D vertex[4];

	vertex[0].Position = D3DXVECTOR3(-10.0f, 0.0f, 10.0f);
	vertex[0].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	vertex[0].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
	vertex[0].TexCoord = D3DXVECTOR2(0.0f, 0.0f);

	vertex[1].Position = D3DXVECTOR3(10.0f, 0.0f, 10.0f);
	vertex[1].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	vertex[1].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
	vertex[1].TexCoord = D3DXVECTOR2(1.0f, 0.0f);

	vertex[2].Position = D3DXVECTOR3(-10.0f, 0.0f, -10.0f);
	vertex[2].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	vertex[2].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
	vertex[2].TexCoord = D3DXVECTOR2(0.0f, 1.0f);

	vertex[3].Position = D3DXVECTOR3(10.0f, 0.0f, -10.0f);
	vertex[3].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
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


	m_Box = new CBox();
	m_Box->Init();

	m_Position = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_Rotation = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_Scale = D3DXVECTOR3(3.0f, 3.0f, 0.0f);

	
	UVY = 0.3f;
	LeftX = 0.6f;
	RightX = 1.0f;
}

void CRail::Uninit()
{
	m_VertexBuffer->Release();
	m_Box->Destroy();
}

void CRail::Update()
{
	CScene* scene = CManager::GetScene();
	m_Box->Update(m_Position, m_Min, m_Max);

	if (Type == RIGHTRAIL)
	{
		LeftX -= 0.005f;
		RightX -= 0.005f;
		UVY = 0.0f;
		if (LeftX <= 0.0f)
		{
			LeftX = 0.6f;
			RightX = 1.0f;
		}
	}
	if (Type == LEFTRAIL)
	{
		LeftX += 0.005f;
		RightX += 0.005f;
		UVY = 0.0f;
		if (LeftX >= 1.0f)
		{
			LeftX = 0.0f;
			RightX = 0.4f;
		}
	}
	if (Type == DOWNRAIL)
	{
		UVY -= 0.01f;
		if (UVY <= 0.0f)
		{
			UVY = 0.6f;
		}
	}
}

void CRail::Transparent()
{
	m_Box->Draw(&boxworld);
}
void CRail::Draw()
{
	LIGHT light;
	light.Enable = false;
	CRenderer::SetLight(light);
	{
	

		D3D11_MAPPED_SUBRESOURCE msr;
		CRenderer::GetDeviceContext()->Map(m_VertexBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &msr);
		VERTEX_3D* vertex = (VERTEX_3D*)msr.pData;
		if (Type != DOWNRAIL)
		{
			vertex[0].Position = D3DXVECTOR3(-0.5f, 0.0f, 0.5f);
			vertex[0].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
			vertex[0].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
			vertex[0].TexCoord = D3DXVECTOR2(LeftX, UVY);

			vertex[1].Position = D3DXVECTOR3(0.5f, 0.0f, 0.5f);
			vertex[1].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
			vertex[1].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
			vertex[1].TexCoord = D3DXVECTOR2(RightX, UVY);

			vertex[2].Position = D3DXVECTOR3(-0.5f, 0.0f, -0.5f);
			vertex[2].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
			vertex[2].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
			vertex[2].TexCoord = D3DXVECTOR2(LeftX, UVY + 1.0f);

			vertex[3].Position = D3DXVECTOR3(0.5f, 0.0f, -0.5f);
			vertex[3].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
			vertex[3].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
			vertex[3].TexCoord = D3DXVECTOR2(RightX, UVY + 1.0f);
		}
		else if (Type == DOWNRAIL)
		{
			vertex[0].Position = D3DXVECTOR3(-0.5f, 0.0f, 0.5f);
			vertex[0].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
			vertex[0].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
			vertex[0].TexCoord = D3DXVECTOR2(0.0f, UVY);

			vertex[1].Position = D3DXVECTOR3(0.5f, 0.0f, 0.5f);
			vertex[1].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
			vertex[1].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
			vertex[1].TexCoord = D3DXVECTOR2(1.0f, UVY);

			vertex[2].Position = D3DXVECTOR3(-0.5f, 0.0f, -0.5f);
			vertex[2].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
			vertex[2].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
			vertex[2].TexCoord = D3DXVECTOR2(0.0f, UVY + 0.4f);

			vertex[3].Position = D3DXVECTOR3(0.5f, 0.0f, -0.5f);
			vertex[3].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
			vertex[3].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
			vertex[3].TexCoord = D3DXVECTOR2(1.0f, UVY + 0.4f);
		}
		CRenderer::GetDeviceContext()->Unmap(m_VertexBuffer, 0);
	}


	D3DXMATRIX  scale, rot, trans,Rtrans1,Rtrans2,soilworld,soilscale,soiltrans;
	D3DXMatrixScaling(&scale, m_Scale.x, m_Scale.y, m_Scale.z);
	D3DXMatrixTranslation(&trans, m_Position.x, m_Position.y, m_Position.z);
	D3DXMatrixTranslation(&boxtrans, m_Position.x, m_Position.y+1.5f, m_Position.z);

	D3DXMatrixTranslation(&Rtrans1, 0.0f, 0.0f, m_Scale.z*0.5f - 0.5f);
	D3DXMatrixTranslation(&Rtrans2, m_Scale.x*0.5f - 0.5f, 0.0f, 0.0f);
	D3DXMatrixTranslation(&soiltrans, m_Position.x, m_Position.y - 5.1f, m_Position.z);
	D3DXMatrixScaling(&soilscale, m_Scale.x*0.5f, m_Scale.y*10.0f, m_Scale.z*0.5f);
	world = scale  * trans;
	soilworld = soilscale * soiltrans;
	boxworld = scale * boxtrans;
	if (m_Scale.z > 1.0f)
	{
		world = scale * Rtrans1 * trans;
		soilworld = soilscale * Rtrans1 * soiltrans;
		boxworld = scale * Rtrans1 *boxtrans;

	}
	if (m_Scale.x > 1.0f)
	{
		world = scale  * Rtrans2  * trans;
		soilworld = soilscale * Rtrans2 * soiltrans;
		boxworld = scale * Rtrans2 *boxtrans;


	}
	if (m_Scale.z > 1.0f && m_Scale.x > 1.0f)
	{
		world = scale * Rtrans1 * Rtrans2  * trans;
		soilworld = soilscale * Rtrans1* Rtrans2 * soiltrans;
		boxworld = scale * Rtrans1* Rtrans2 *boxtrans;


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
	material.Diffuse = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	CRenderer::SetMaterial(material);
	//テクス?ャ設定
	if (Type == RIGHTRAIL)
	{
		assert(RightRail_Texture);
		CRenderer::GetDeviceContext()->PSSetShaderResources(0, 1, &RightRail_Texture);
	}
	else if (Type == LEFTRAIL)
	{
		assert(LeftRail_Texture);
		CRenderer::GetDeviceContext()->PSSetShaderResources(0, 1, &LeftRail_Texture);
	}
	else if (Type == DOWNRAIL)
	{
		assert(DownRail_Texture);
		CRenderer::GetDeviceContext()->PSSetShaderResources(0, 1, &DownRail_Texture);
	}
	CRenderer::GetDeviceContext()->IASetPrimitiveTopology(
		D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP);

	CRenderer::GetDeviceContext()->Draw(4, 0);

	CRenderer::SetWorldMatrix(&soilworld);

	Soil_Model->Draw();

}


#include "main.h"
#include "manager.h"
#include "renderer.h"
#include "model.h"
#include "Player.h"
#include "wall.h"
#include "box.h"
#include "input.h"
#include "stage3.h"
#include "stage5.h"
#include "Stage6.h"
#include "light.h"
CModel* CWall::Grass_Model;
CModel* CWall::Grass1_Model;
CModel* CWall::Rock_Model;
ID3D11ShaderResourceView* CWall::Wall_Texture;
ID3D11ShaderResourceView* CWall::Pillar_Texture;
ID3D11ShaderResourceView* CWall::Grass_Texture;
ID3D11ShaderResourceView* CWall::Rock_Texture;
ID3D11ShaderResourceView* CWall::Factory_Texture;
ID3D11ShaderResourceView* CWall::BrickWall_Texture;

void CWall::Load()
{
	Grass_Model = new CModel();
	Grass_Model->Load("asset\\model\\wall\\grass.obj");
	Grass1_Model = new CModel();
	Grass1_Model->Load("asset\\model\\wall\\grass1.obj");

	Rock_Model = new CModel();
	Rock_Model->Load("asset\\model\\wall\\rock.obj");

	

	D3DX11CreateShaderResourceViewFromFile(CRenderer::GetDevice(),
		"asset/texture/wall/Factory_Skybox.png",
		NULL,
		NULL,
		&Factory_Texture,
		NULL);

	assert(Factory_Texture);

	D3DX11CreateShaderResourceViewFromFile(CRenderer::GetDevice(),
		"asset/texture/wall/Wall2.jpg",
		NULL,
		NULL,
		&BrickWall_Texture,
		NULL);

	assert(BrickWall_Texture);

	D3DX11CreateShaderResourceViewFromFile(CRenderer::GetDevice(),
		"asset/texture/wall/Wall.jpg",
		NULL,
		NULL,
		&Wall_Texture,
		NULL);

	assert(Wall_Texture);

	D3DX11CreateShaderResourceViewFromFile(CRenderer::GetDevice(),
		"asset/texture/wall/Pillar_Texture.jpg",
		NULL,
		NULL,
		&Pillar_Texture,
		NULL);

	assert(Pillar_Texture);

	D3DX11CreateShaderResourceViewFromFile(CRenderer::GetDevice(),
		"asset/texture/color/Green.jpg",
		NULL,
		NULL,
		&Grass_Texture,
		NULL);

	assert(Grass_Texture);


	D3DX11CreateShaderResourceViewFromFile(CRenderer::GetDevice(),
		"asset/texture/enemy/Enemy_Bullet.png",
		NULL,
		NULL,
		&Rock_Texture,
		NULL);
}
void CWall::Unload()
{
	Grass_Model->Unload();
	delete Grass_Model;
	Grass1_Model->Unload();
	delete Grass1_Model;
	Rock_Model->Unload();
	delete Rock_Model;
	Factory_Texture->Release();
	BrickWall_Texture->Release();
	Rock_Texture->Release();
	Grass_Texture->Release();
	Pillar_Texture->Release();
	Wall_Texture->Release();

}
void CWall::Init()
{
	{//上
		vertex[0].Position = D3DXVECTOR3(-1.0f, 1.0f, 1.0f);
		vertex[0].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[0].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[0].TexCoord = D3DXVECTOR2(0.0f, 0.0f);

		vertex[1].Position = D3DXVECTOR3(1.0f, 1.0f, 1.0f);
		vertex[1].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[1].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[1].TexCoord = D3DXVECTOR2(1.0f, 0.0f);

		vertex[2].Position = D3DXVECTOR3(-1.0f, 1.0f, -1.0f);
		vertex[2].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[2].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[2].TexCoord = D3DXVECTOR2(0.0f, 1.0f);

		vertex[3].Position = D3DXVECTOR3(-1.0f, 1.0f, -1.0f);
		vertex[3].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[3].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[3].TexCoord = D3DXVECTOR2(0.0f, 1.0f);

		vertex[4].Position = D3DXVECTOR3(1.0f, 1.0f, 1.0f);
		vertex[4].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[4].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[4].TexCoord = D3DXVECTOR2(1.0f, 0.0f);

		vertex[5].Position = D3DXVECTOR3(1.0f, 1.0f, -1.0f);
		vertex[5].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[5].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[5].TexCoord = D3DXVECTOR2(1.0f, 1.0f);

	}
	{//前
		vertex[6].Position = D3DXVECTOR3(-1.0f, 1.0f, -1.0f);
		vertex[6].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[6].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[6].TexCoord = D3DXVECTOR2(0.0f, 0.0f);

		vertex[7].Position = D3DXVECTOR3(1.0f, 1.0f, -1.0f);
		vertex[7].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[7].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[7].TexCoord = D3DXVECTOR2(1.0f, 0.0f);

		vertex[8].Position = D3DXVECTOR3(-1.0f, -1.0f, -1.0f);
		vertex[8].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[8].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[8].TexCoord = D3DXVECTOR2(0.0f, 1.0f);

		vertex[9].Position = D3DXVECTOR3(-1.0f, -1.0f, -1.0f);
		vertex[9].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[9].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[9].TexCoord = D3DXVECTOR2(0.0f, 1.0f);

		vertex[10].Position = D3DXVECTOR3(1.0f, 1.0f, -1.0f);
		vertex[10].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[10].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[10].TexCoord = D3DXVECTOR2(1.0f, 0.0f);

		vertex[11].Position = D3DXVECTOR3(1.0f, -1.0f, -1.0f);
		vertex[11].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[11].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[11].TexCoord = D3DXVECTOR2(1.0f, 1.0f);
	}
	{//右
		vertex[12].Position = D3DXVECTOR3(1.0f, 1.0f, -1.0f);
		vertex[12].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[12].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[12].TexCoord = D3DXVECTOR2(0.0f, 0.0f);

		vertex[13].Position = D3DXVECTOR3(1.0f, 1.0f, 1.0f);
		vertex[13].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[13].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[13].TexCoord = D3DXVECTOR2(1.0f, .0f);

		vertex[14].Position = D3DXVECTOR3(1.0f, -1.0f, -1.0f);
		vertex[14].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[14].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[14].TexCoord = D3DXVECTOR2(0.0f, 1.0f);

		vertex[15].Position = D3DXVECTOR3(1.0f, -1.0f, -1.0f);
		vertex[15].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[15].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[15].TexCoord = D3DXVECTOR2(0.0f, 1.0f);

		vertex[16].Position = D3DXVECTOR3(1.0f, 1.0f, 1.0f);
		vertex[16].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[16].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[16].TexCoord = D3DXVECTOR2(1.0f, 0.0f);

		vertex[17].Position = D3DXVECTOR3(1.0f, -1.0f, 1.0f);
		vertex[17].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[17].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[17].TexCoord = D3DXVECTOR2(1.0f, 1.0f);
	}
	{//左
		vertex[18].Position = D3DXVECTOR3(-1.0f, 1.0f, 1.0f);
		vertex[18].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[18].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[18].TexCoord = D3DXVECTOR2(0.0f, 0.0f);

		vertex[19].Position = D3DXVECTOR3(-1.0f, 1.0f, -1.0f);
		vertex[19].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[19].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[19].TexCoord = D3DXVECTOR2(1.0f, 0.0f);

		vertex[20].Position = D3DXVECTOR3(-1.0f, -1.0f, 1.0f);
		vertex[20].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[20].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[20].TexCoord = D3DXVECTOR2(0.0f, 1.0f);

		vertex[21].Position = D3DXVECTOR3(-1.0f, -1.0f, 1.0f);
		vertex[21].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[21].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[21].TexCoord = D3DXVECTOR2(0.0f, 1.0f);

		vertex[22].Position = D3DXVECTOR3(-1.0f, 1.0f, -1.0f);
		vertex[22].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[22].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[22].TexCoord = D3DXVECTOR2(1.0f, 0.0f);

		vertex[23].Position = D3DXVECTOR3(-1.0f, -1.0f, -1.0f);
		vertex[23].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[23].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[23].TexCoord = D3DXVECTOR2(1.0f, 1.0f);
	}
	{//後ろ
		vertex[24].Position = D3DXVECTOR3(1.0f, 1.0f, 1.0f);
		vertex[24].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[24].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[24].TexCoord = D3DXVECTOR2(0.0f, 0.0f);

		vertex[25].Position = D3DXVECTOR3(-1.0f, 1.0f, 1.0f);
		vertex[25].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[25].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[25].TexCoord = D3DXVECTOR2(1.0f, 0.0f);

		vertex[26].Position = D3DXVECTOR3(1.0f, -1.0f, 1.0f);
		vertex[26].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[26].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[26].TexCoord = D3DXVECTOR2(0.0f, 1.0f);

		vertex[27].Position = D3DXVECTOR3(1.0f, -1.0f, 1.0f);
		vertex[27].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[27].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[27].TexCoord = D3DXVECTOR2(0.0f, 1.0f);

		vertex[28].Position = D3DXVECTOR3(-1.0f, 1.0f, 1.0f);
		vertex[28].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[28].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[28].TexCoord = D3DXVECTOR2(1.0f, 0.0f);

		vertex[29].Position = D3DXVECTOR3(-1.0f, -1.0f, 1.0f);
		vertex[29].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[29].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[29].TexCoord = D3DXVECTOR2(1.0f, 1.0f);
	}
	{//下
		vertex[30].Position = D3DXVECTOR3(-1.0f, -1.0f, -1.0f);
		vertex[30].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[30].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[30].TexCoord = D3DXVECTOR2(0.0f, 0.0f);

		vertex[31].Position = D3DXVECTOR3(1.0f, -1.0f, -1.0f);
		vertex[31].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[31].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[31].TexCoord = D3DXVECTOR2(1.0f, 0.0f);

		vertex[32].Position = D3DXVECTOR3(-1.0f, -1.0f, 1.0f);
		vertex[32].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[32].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[32].TexCoord = D3DXVECTOR2(0.0f, 1.0f);

		vertex[33].Position = D3DXVECTOR3(-1.0f, -1.0f, 1.0f);
		vertex[33].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[33].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[33].TexCoord = D3DXVECTOR2(0.0f, 1.0f);

		vertex[34].Position = D3DXVECTOR3(1.0f, -1.0f, -1.0f);
		vertex[34].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[34].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[34].TexCoord = D3DXVECTOR2(1.0f, 0.0f);

		vertex[35].Position = D3DXVECTOR3(1.0f, -1.0f, 1.0f);
		vertex[35].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[35].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[35].TexCoord = D3DXVECTOR2(1.0f, 1.0f);
	}

	D3D11_BUFFER_DESC bd;
	ZeroMemory(&bd, sizeof(bd));
	bd.Usage = D3D11_USAGE_DYNAMIC;
	bd.ByteWidth = sizeof(VERTEX_3D) * 36;
	bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	bd.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;

	D3D11_SUBRESOURCE_DATA sd;
	ZeroMemory(&sd, sizeof(sd));
	sd.pSysMem = vertex;
	sd.SysMemPitch = 0;
	sd.SysMemSlicePitch = 0;

	CRenderer::GetDevice()->CreateBuffer(&bd, &sd, &m_VertexBuffer);




	m_Position = D3DXVECTOR3(-10.0f, -90.5f, 420.0f);
	m_Rotation = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_Scale = D3DXVECTOR3(1.0f, 1.0f, 30.0f);
	g_Box = new CBox();
	g_Box->Init();
	
	m_Max = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_Min = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

	

	Type = 0;
	Texture_Type = 0;
	ModelType = 0;
}

void CWall::Update()
{
	g_Box->Update(m_Position, m_Min, m_Max);

}

void CWall::Uninit()
{
	m_VertexBuffer->Release();
	g_Box->Destroy();
	
	
}

void CWall::Transparent()
{
	g_Box->Draw(&world);

}

void CWall::Draw()
{
	CLight::SetLight(WALL_LIGHT);


	D3D11_MAPPED_SUBRESOURCE msr;
	CRenderer::GetDeviceContext()->Map(m_VertexBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &msr);
	VERTEX_3D* vertex = (VERTEX_3D*)msr.pData;

	{//上
		vertex[0].Position = D3DXVECTOR3(-0.5f, 0.5f, 0.5f);
		vertex[0].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[0].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[0].TexCoord = D3DXVECTOR2(0.0f, 0.0f);

		vertex[1].Position = D3DXVECTOR3(0.5f, 0.5f, 0.5f);
		vertex[1].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[1].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[1].TexCoord = D3DXVECTOR2(1.0f, 0.0f);

		vertex[2].Position = D3DXVECTOR3(-0.5f, 0.5f, -0.5f);
		vertex[2].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[2].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[2].TexCoord = D3DXVECTOR2(0.0f, 1.0f);

		vertex[3].Position = D3DXVECTOR3(-0.5f, 0.5f, -0.5f);
		vertex[3].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[3].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[3].TexCoord = D3DXVECTOR2(0.0f, 1.0f);

		vertex[4].Position = D3DXVECTOR3(0.5f, 0.5f, 0.5f);
		vertex[4].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[4].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[4].TexCoord = D3DXVECTOR2(1.0f, 0.0f);

		vertex[5].Position = D3DXVECTOR3(0.5f, 0.5f, -0.5f);
		vertex[5].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[5].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[5].TexCoord = D3DXVECTOR2(1.0f, 1.0f);

	}
	{//前
		vertex[6].Position = D3DXVECTOR3(-0.5f, 0.5f, -0.5f);
		vertex[6].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[6].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[6].TexCoord = D3DXVECTOR2(0.0f, 0.0f);

		vertex[7].Position = D3DXVECTOR3(0.5f, 0.5f, -0.5f);
		vertex[7].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[7].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[7].TexCoord = D3DXVECTOR2(m_Scale.x/ UV_X, 0.0f);

		vertex[8].Position = D3DXVECTOR3(-0.5f, -0.5f, -0.5f);
		vertex[8].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[8].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[8].TexCoord = D3DXVECTOR2(0.0f, 1.0f);

		vertex[9].Position = D3DXVECTOR3(-0.5f, -0.5f, -0.5f);
		vertex[9].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[9].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[9].TexCoord = D3DXVECTOR2(0.0f, 1.0f);

		vertex[10].Position = D3DXVECTOR3(0.5f, 0.5f, -0.5f);
		vertex[10].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[10].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[10].TexCoord = D3DXVECTOR2(m_Scale.x / UV_X, 0.0f);

		vertex[11].Position = D3DXVECTOR3(0.5f, -0.5f, -0.5f);
		vertex[11].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[11].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[11].TexCoord = D3DXVECTOR2(m_Scale.x / UV_X, 1.0f);
	}
	{//右
		vertex[12].Position = D3DXVECTOR3(0.5f, 0.5f, -0.5f);
		vertex[12].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[12].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[12].TexCoord = D3DXVECTOR2(0.0f, 0.0f);

		vertex[13].Position = D3DXVECTOR3(0.5f, 0.5f, 0.5f);
		vertex[13].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[13].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[13].TexCoord = D3DXVECTOR2(m_Scale.z / UV_X, 0.0f);

		vertex[14].Position = D3DXVECTOR3(0.5f, -0.5f, -0.5f);
		vertex[14].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[14].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[14].TexCoord = D3DXVECTOR2(0.0f, 1.0f);

		vertex[15].Position = D3DXVECTOR3(0.5f, -0.5f, -0.5f);
		vertex[15].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[15].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[15].TexCoord = D3DXVECTOR2(0.0f, 1.0f);

		vertex[16].Position = D3DXVECTOR3(0.5f, 0.5f, 0.5f);
		vertex[16].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[16].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[16].TexCoord = D3DXVECTOR2(m_Scale.z / UV_X, 0.0f);

		vertex[17].Position = D3DXVECTOR3(0.5f, -0.5f, 0.5f);
		vertex[17].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[17].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[17].TexCoord = D3DXVECTOR2(m_Scale.z / UV_X, 1.0f);
	}
	{//左
		vertex[18].Position = D3DXVECTOR3(-0.5f, 0.5f, 0.5f);
		vertex[18].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[18].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[18].TexCoord = D3DXVECTOR2(0.0f, 0.0f);

		vertex[19].Position = D3DXVECTOR3(-0.5f, 0.5f, -0.5f);
		vertex[19].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[19].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[19].TexCoord = D3DXVECTOR2(m_Scale.z / UV_X, 0.0f);

		vertex[20].Position = D3DXVECTOR3(-0.5f, -0.5f, 0.5f);
		vertex[20].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[20].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[20].TexCoord = D3DXVECTOR2(0.0f, 1.0f);

		vertex[21].Position = D3DXVECTOR3(-0.5f, -0.5f, 0.5f);
		vertex[21].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[21].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[21].TexCoord = D3DXVECTOR2(0.0f, 1.0f);

		vertex[22].Position = D3DXVECTOR3(-0.5f, 0.5f, -0.5f);
		vertex[22].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[22].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[22].TexCoord = D3DXVECTOR2(m_Scale.z / UV_X, 0.0f);

		vertex[23].Position = D3DXVECTOR3(-0.5f, -0.5f, -0.5f);
		vertex[23].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[23].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[23].TexCoord = D3DXVECTOR2(m_Scale.z / UV_X, 1.0f);
	}
	{//後ろ
		vertex[24].Position = D3DXVECTOR3(0.5f, 0.5f, 0.5f);
		vertex[24].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[24].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[24].TexCoord = D3DXVECTOR2(0.0f, 0.0f);

		vertex[25].Position = D3DXVECTOR3(-0.5f, 0.5f, 0.5f);
		vertex[25].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[25].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[25].TexCoord = D3DXVECTOR2(m_Scale.x / UV_X, 0.0f);

		vertex[26].Position = D3DXVECTOR3(0.5f, -0.5f, 0.5f);
		vertex[26].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[26].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[26].TexCoord = D3DXVECTOR2(0.0f, 1.0f);

		vertex[27].Position = D3DXVECTOR3(0.5f, -0.5f, 0.5f);
		vertex[27].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[27].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[27].TexCoord = D3DXVECTOR2(0.0f, 1.0f);

		vertex[28].Position = D3DXVECTOR3(-0.5f, 0.5f, 0.5f);
		vertex[28].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[28].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[28].TexCoord = D3DXVECTOR2(m_Scale.x / UV_X, 0.0f);

		vertex[29].Position = D3DXVECTOR3(-0.5f, -0.5f, 0.5f);
		vertex[29].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[29].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[29].TexCoord = D3DXVECTOR2(m_Scale.x / UV_X, 1.0f);
	}
	{//下
		vertex[30].Position = D3DXVECTOR3(-0.5f, -0.5f, -0.5f);
		vertex[30].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[30].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[30].TexCoord = D3DXVECTOR2(0.0f, 0.0f);

		vertex[31].Position = D3DXVECTOR3(0.5f, -0.5f, -0.5f);
		vertex[31].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[31].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[31].TexCoord = D3DXVECTOR2(1.0f, 0.0f);

		vertex[32].Position = D3DXVECTOR3(-0.5f, -0.5f, 0.5f);
		vertex[32].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[32].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[32].TexCoord = D3DXVECTOR2(0.0f, 1.0f);

		vertex[33].Position = D3DXVECTOR3(-0.5f, -0.5f, 0.5f);
		vertex[33].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[33].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[33].TexCoord = D3DXVECTOR2(0.0f, 1.0f);

		vertex[34].Position = D3DXVECTOR3(0.5f, -0.5f, -0.5f);
		vertex[34].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[34].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[34].TexCoord = D3DXVECTOR2(1.0f, 0.0f);

		vertex[35].Position = D3DXVECTOR3(0.5f, -0.5f, 0.5f);
		vertex[35].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[35].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[35].TexCoord = D3DXVECTOR2(1.0f, 1.0f);
	}


	CRenderer::GetDeviceContext()->Unmap(m_VertexBuffer, 0);


	D3DXMATRIX  scale, rot, trans,trans2,world2,Rtrans1,Rtrans2,grassworld,grassscale,grasstrans;
	D3DXMATRIX rockworld, rockscale, rocktrans;
	D3DXMatrixScaling(&scale, m_Scale.x, m_Scale.y, m_Scale.z);
	D3DXMatrixRotationYawPitchRoll(&rot, m_Rotation.y, m_Rotation.x, m_Rotation.z);
	D3DXMatrixTranslation(&trans, m_Position.x + 0.5f , m_Position.y, m_Position.z+0.5f);
	D3DXMatrixTranslation(&trans2, Wall_Position.x + 0.5f,Wall_Position.y,Wall_Position.z + 0.5f);

	D3DXMatrixTranslation(&Rtrans1, 0.0f , 0.0f, m_Scale.z*0.5f-0.5f);
	D3DXMatrixTranslation(&Rtrans2, m_Scale.x*0.5f-0.5f , 0.0f, 0.0f );
	
	D3DXMatrixTranslation(&rocktrans, m_Position.x + 5.5f, m_Position.y-0.7f, m_Position.z + 6.0f);
	D3DXMatrixScaling(&rockscale, m_Scale.x*0.4f, m_Scale.y*0.8f, m_Scale.z*5.7f);


	if (Type == RIGHT_WALL)
	{
		D3DXMatrixScaling(&grassscale, m_Scale.x*0.8f, m_Scale.y*0.3f, m_Scale.z*0.5f);
		D3DXMatrixTranslation(&grasstrans, m_Position.x-0.1f , m_Position.y*0.5f, m_Position.z);
	}
	else if (Type == LEFT_WALL)
	{
		D3DXMatrixScaling(&grassscale, m_Scale.x*0.8f, m_Scale.y*0.3f, m_Scale.z*0.5f);
		D3DXMatrixTranslation(&grasstrans, m_Position.x - 0.9f, m_Position.y*0.5f, m_Position.z);
	}
	else if (Type == FRONT_WALL || Type == BEHIND_WALL)
	{
		D3DXMatrixScaling(&grassscale, m_Scale.x*0.5f, m_Scale.y*0.3f, m_Scale.z*1.0f);
		D3DXMatrixTranslation(&grasstrans, m_Position.x - 0.2f, m_Position.y*0.5f, m_Position.z);
	}

	rockworld = rockscale * rot * rocktrans;
	grassworld = grassscale * rot * grasstrans;
	world = scale * rot * trans;
	world2 = scale * rot * trans2;
	if (m_Scale.z > 1.0f)
	{
		world2 =  scale * Rtrans1 * rot * trans2;
		world = scale * Rtrans1 * rot * trans;

	}
	if (m_Scale.x > 1.0f)
	{
		world2 = scale * Rtrans2 * rot * trans2;
		world = scale * Rtrans2 * rot * trans;

	}
	if (m_Scale.z > 1.0f && m_Scale.x > 1.0f)
	{
		world2 = scale * Rtrans1 * Rtrans2 * rot * trans2;
		world = scale * Rtrans1 * Rtrans2 * rot * trans;

	}
	UINT stride = sizeof(VERTEX_3D);
	UINT offset = 0;
	CRenderer::GetDeviceContext()->IASetVertexBuffers(
		0, 1, &m_VertexBuffer, &stride, &offset);

	MATERIAL material;
	ZeroMemory(&material, sizeof(material));
	material.Diffuse = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	CRenderer::SetMaterial(material);
	//テクスチャ設定
	if (CManager::SceneGet<CStage6>())
	{
		CRenderer::GetDeviceContext()->PSSetShaderResources(0, 1, &BrickWall_Texture);
		
	}
	else
	{
		CRenderer::GetDeviceContext()->PSSetShaderResources(0, 1, &Wall_Texture);
	}
	if (Texture_Type == PILLAR)
	{
		CRenderer::GetDeviceContext()->PSSetShaderResources(0, 1, &Pillar_Texture);

	}
	//プリミティブトポロジ設定
	CRenderer::GetDeviceContext()->IASetPrimitiveTopology(
		D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	CRenderer::SetWorldMatrix(&world2);

	//ポリゴン描画
	if (ModelType != ROCK)
	{
		CCamera* Camera = CManager::GetScene()->GetGameObject<CCamera>(0);
		D3DXVECTOR3 Savevec = m_Position - Camera->GetPosition();
		float length = D3DXVec3Length(&Savevec);
		if (ModelType != GRASS)
		{
			CRenderer::GetDeviceContext()->Draw(36, 0);
		}
		else if (Type == RIGHT_WALL || Type == LEFT_WALL)
		{
			if (length < 100.0f)
			{
				assert(Grass_Texture);
				CRenderer::GetDeviceContext()->PSSetShaderResources(0, 1, &Grass_Texture);
				CRenderer::SetWorldMatrix(&grassworld);
				if(m_Position.z < 445.0f)
				Grass_Model->Draw();
			}
		}
		else if (Type == FRONT_WALL || Type == BEHIND_WALL)
		{
			if (length < 100.0f)
			{
				assert(Grass_Texture);
				CRenderer::GetDeviceContext()->PSSetShaderResources(0, 1, &Grass_Texture);
				CRenderer::SetWorldMatrix(&grassworld);
				if (m_Position.z < 445.0f)
				Grass1_Model->Draw();
			}
		}
	}

	if (ModelType == ROCK && Type == FRONT_WALL)
	{
		assert(Rock_Texture);
		CRenderer::GetDeviceContext()->PSSetShaderResources(0, 1, &Rock_Texture);
		CRenderer::SetWorldMatrix(&rockworld);
		Rock_Model->Draw();
	}


}

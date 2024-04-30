#include "main.h"
#include "manager.h"
#include "renderer.h"
#include "model.h"
#include "Player.h"
#include "wall.h"
#include "box.h"
#include "input.h"
#include "light.h"
#include "skybox.h"
#include "camera.h"
#include "scene.h"
#include "stage4.h"
#include "stage5.h"
void CSkybox::Init()
{
	{//↓
		vertex[0].Position = D3DXVECTOR3(-10.0f, -10.0f, 10.0f);
		vertex[0].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[0].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[0].TexCoord = D3DXVECTOR2(1.0f / 4.0f, 2.0f / 3.0f);

		vertex[1].Position = D3DXVECTOR3(10.0f, -10.0f, 10.0f);
		vertex[1].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[1].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[1].TexCoord = D3DXVECTOR2(2.0f / 4.0f, 2.0f /3.0f);

		vertex[2].Position = D3DXVECTOR3(-10.0f, -10.0f, -10.0f);
		vertex[2].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[2].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[2].TexCoord = D3DXVECTOR2(1.0f / 4.0f, 3.0f / 3.0f);

		vertex[3].Position = D3DXVECTOR3(-10.0f, -10.0f, -10.0f);
		vertex[3].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[3].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[3].TexCoord = D3DXVECTOR2(1.0f / 4.0f, 3.0f / 3.0f);

		vertex[4].Position = D3DXVECTOR3(10.0f, -10.0f, 10.0f);
		vertex[4].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[4].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[4].TexCoord = D3DXVECTOR2(2.0f / 4.0f, 2.0f / 3.0f);

		vertex[5].Position = D3DXVECTOR3(10.0f,-10.0f, -10.0f);
		vertex[5].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[5].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[5].TexCoord = D3DXVECTOR2(2.0f / 4.0f, 3.0f / 3.0f);

	}
	{//前
		vertex[6].Position = D3DXVECTOR3(-10.0f, 10.0f, 10.0f);
		vertex[6].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[6].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[6].TexCoord = D3DXVECTOR2(1.0f / 4.0f, 1.0f / 3.0f);

		vertex[7].Position = D3DXVECTOR3(10.0f, 10.0f, 10.0f);
		vertex[7].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[7].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[7].TexCoord = D3DXVECTOR2(2.0f / 4.0f, 1.0f / 3.0f);

		vertex[8].Position = D3DXVECTOR3(-10.0f, -10.0f, 10.0f);
		vertex[8].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[8].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[8].TexCoord = D3DXVECTOR2(1.0f / 4.0f, 2.0f / 3.0f);

		vertex[9].Position = D3DXVECTOR3(-10.0f, -10.0f, 10.0f);
		vertex[9].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[9].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[9].TexCoord = D3DXVECTOR2(1.0f / 4.0f, 2.0f / 3.0f);

		vertex[10].Position = D3DXVECTOR3(10.0f, 10.0f, 10.0f);
		vertex[10].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[10].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[10].TexCoord = D3DXVECTOR2(2.0f / 4.0f, 1.0f / 3.0f);

		vertex[11].Position = D3DXVECTOR3(10.0f, -10.0f, 10.0f);
		vertex[11].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[11].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[11].TexCoord = D3DXVECTOR2(2.0f / 4.0f, 2.0f / 3.0f);
	}
	{//←
		vertex[12].Position = D3DXVECTOR3(-10.0f, 10.0f, -10.0f);
		vertex[12].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[12].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[12].TexCoord = D3DXVECTOR2(0.0f / 4.0f, 1.0f / 3.0f);

		vertex[13].Position = D3DXVECTOR3(-10.0f, 10.0f, 10.0f);
		vertex[13].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[13].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[13].TexCoord = D3DXVECTOR2(1.0f / 4.0f, 1.0f / 3.0f);

		vertex[14].Position = D3DXVECTOR3(-10.0f, -10.0f, -10.0f);
		vertex[14].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[14].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[14].TexCoord = D3DXVECTOR2(0.0f / 4.0f, 2.0f / 3.0f);

		vertex[15].Position = D3DXVECTOR3(-10.0f, -10.0f, -10.0f);
		vertex[15].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[15].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[15].TexCoord = D3DXVECTOR2(0.0f / 4.0f, 2.0f / 3.0f);

		vertex[16].Position = D3DXVECTOR3(-10.0f, 10.0f, 10.0f);
		vertex[16].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[16].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[16].TexCoord = D3DXVECTOR2(1.0f / 4.0f, 1.0f / 3.0f);

		vertex[17].Position = D3DXVECTOR3(-10.0f, -10.0f, 10.0f);
		vertex[17].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[17].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[17].TexCoord = D3DXVECTOR2(1.0f / 4.0f, 2.0f / 3.0f);
	}
	{//→
		vertex[18].Position = D3DXVECTOR3(10.0f, 10.0f, 10.0f);
		vertex[18].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[18].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[18].TexCoord = D3DXVECTOR2(2.0f / 4.0f, 1.0f / 3.0f);

		vertex[19].Position = D3DXVECTOR3(10.0f, 10.0f, -10.0f);
		vertex[19].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[19].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[19].TexCoord = D3DXVECTOR2(3.0f / 4.0f, 1.0f / 3.0f);

		vertex[20].Position = D3DXVECTOR3(10.0f, -10.0f, 10.0f);
		vertex[20].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[20].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[20].TexCoord = D3DXVECTOR2(2.0f / 4.0f, 2.0f / 3.0f);

		vertex[21].Position = D3DXVECTOR3(10.0f, -10.0f, 10.0f);
		vertex[21].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[21].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[21].TexCoord = D3DXVECTOR2(2.0f / 4.0f, 2.0f / 3.0f);

		vertex[22].Position = D3DXVECTOR3(10.0f, 10.0f, -10.0f);
		vertex[22].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[22].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[22].TexCoord = D3DXVECTOR2(3.0f / 4.0f, 1.0f / 3.0f);

		vertex[23].Position = D3DXVECTOR3(10.0f, -10.0f, -10.0f);
		vertex[23].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[23].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[23].TexCoord = D3DXVECTOR2(3.0f / 4.0f, 2.0f / 3.0f);
	}
	{//後ろ
		vertex[24].Position = D3DXVECTOR3(10.0f, 10.0f, -10.0f);
		vertex[24].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[24].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[24].TexCoord = D3DXVECTOR2(3.0f / 4.0f, 1.0f / 3.0f);

		vertex[25].Position = D3DXVECTOR3(-10.0f, 10.0f, -10.0f);
		vertex[25].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[25].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[25].TexCoord = D3DXVECTOR2(4.0f / 4.0f, 1.0f / 3.0f);

		vertex[26].Position = D3DXVECTOR3(10.0f, -10.0f, -10.0f);
		vertex[26].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[26].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[26].TexCoord = D3DXVECTOR2(3.0f / 4.0f,2.0f / 3.0f);

		vertex[27].Position = D3DXVECTOR3(10.0f, -10.0f, -10.0f);
		vertex[27].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[27].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[27].TexCoord = D3DXVECTOR2(3.0f / 4.0f, 2.0f / 3.0f);

		vertex[28].Position = D3DXVECTOR3(-10.0f, 10.0f, -10.0f);
		vertex[28].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[28].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[28].TexCoord = D3DXVECTOR2(4.0f / 4.0f, 1.0f / 3.0f);
		
		vertex[29].Position = D3DXVECTOR3(-10.0f, -10.0f, -10.0f);
		vertex[29].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[29].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[29].TexCoord = D3DXVECTOR2(4.0f / 4.0f,2.0f / 3.0f);
	}
	{//↑
		vertex[30].Position = D3DXVECTOR3(-10.0f, 10.0f, -10.0f);
		vertex[30].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[30].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[30].TexCoord = D3DXVECTOR2(1.0f / 4.0f, 0.0f / 3.0f);

		vertex[31].Position = D3DXVECTOR3(10.0f, 10.0f, -10.0f);
		vertex[31].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[31].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[31].TexCoord = D3DXVECTOR2(2.0f / 4.0f, 0.0f / 3.0f);

		vertex[32].Position = D3DXVECTOR3(-10.0f, 10.0f, 10.0f);
		vertex[32].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[32].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[32].TexCoord = D3DXVECTOR2(1.0f / 4.0f, 1.0f /3.0f);

		vertex[33].Position = D3DXVECTOR3(-10.0f, 10.0f, 10.0f);
		vertex[33].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[33].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[33].TexCoord = D3DXVECTOR2(1.0f / 4.0f, 1.0f / 3.0f);

		vertex[34].Position = D3DXVECTOR3(10.0f, 10.0f, -10.0f);
		vertex[34].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[34].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[34].TexCoord = D3DXVECTOR2(2.0f / 4.0f, 0.0f / 3.0f);

		vertex[35].Position = D3DXVECTOR3(10.0f, 10.0f, 10.0f);
		vertex[35].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[35].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[35].TexCoord = D3DXVECTOR2(2.0f / 4.0f, 1.0f / 3.0f);
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


	D3DX11CreateShaderResourceViewFromFile(CRenderer::GetDevice(),
		"asset/texture/wall/Skybox.png",
		NULL,
		NULL,
		&Sky_Texture,
		NULL);

	assert(Sky_Texture);

	D3DX11CreateShaderResourceViewFromFile(CRenderer::GetDevice(),
		"asset/texture/wall/Factory_Skybox.png",
		NULL,
		NULL,
		&Factory_Texture,
		NULL);

	assert(Factory_Texture);





}

void CSkybox::Update()
{
	CCamera* Camera = CManager::GetScene()->GetGameObject<CCamera>(0);
	m_Position = Camera->GetPosition();
}

void CSkybox::Uninit()
{
	Sky_Texture->Release();
	m_VertexBuffer->Release();

}

void CSkybox::Transparent()
{

}

void CSkybox::Draw()
{
	D3D11_MAPPED_SUBRESOURCE msr;
	CRenderer::GetDeviceContext()->Map(m_VertexBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &msr);
	VERTEX_3D* vertex = (VERTEX_3D*)msr.pData;

	{//↓
		vertex[0].Position = D3DXVECTOR3(-10.0f, -10.0f, 10.0f);
		vertex[0].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[0].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[0].TexCoord = D3DXVECTOR2(1.0f / 4.0f, 2.0f / 3.0f);

		vertex[1].Position = D3DXVECTOR3(10.0f, -10.0f, 10.0f);
		vertex[1].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[1].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[1].TexCoord = D3DXVECTOR2(2.0f / 4.0f, 2.0f / 3.0f);

		vertex[2].Position = D3DXVECTOR3(-10.0f, -10.0f, -10.0f);
		vertex[2].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[2].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[2].TexCoord = D3DXVECTOR2(1.0f / 4.0f, 3.0f / 3.0f);

		vertex[3].Position = D3DXVECTOR3(-10.0f, -10.0f, -10.0f);
		vertex[3].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[3].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[3].TexCoord = D3DXVECTOR2(1.0f / 4.0f, 3.0f / 3.0f);

		vertex[4].Position = D3DXVECTOR3(10.0f, -10.0f, 10.0f);
		vertex[4].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[4].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[4].TexCoord = D3DXVECTOR2(2.0f / 4.0f, 2.0f / 3.0f);

		vertex[5].Position = D3DXVECTOR3(10.0f, -10.0f, -10.0f);
		vertex[5].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[5].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[5].TexCoord = D3DXVECTOR2(2.0f / 4.0f, 3.0f / 3.0f);

	}
	{//前
		vertex[6].Position = D3DXVECTOR3(-10.0f, 10.0f, 10.0f);
		vertex[6].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[6].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[6].TexCoord = D3DXVECTOR2(1.0f / 4.0f, 1.0f / 3.0f);

		vertex[7].Position = D3DXVECTOR3(10.0f, 10.0f, 10.0f);
		vertex[7].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[7].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[7].TexCoord = D3DXVECTOR2(2.0f / 4.0f, 1.0f / 3.0f);

		vertex[8].Position = D3DXVECTOR3(-10.0f, -10.0f, 10.0f);
		vertex[8].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[8].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[8].TexCoord = D3DXVECTOR2(1.0f / 4.0f, 2.0f / 3.0f);

		vertex[9].Position = D3DXVECTOR3(-10.0f, -10.0f, 10.0f);
		vertex[9].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[9].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[9].TexCoord = D3DXVECTOR2(1.0f / 4.0f, 2.0f / 3.0f);

		vertex[10].Position = D3DXVECTOR3(10.0f, 10.0f, 10.0f);
		vertex[10].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[10].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[10].TexCoord = D3DXVECTOR2(2.0f / 4.0f, 1.0f / 3.0f);

		vertex[11].Position = D3DXVECTOR3(10.0f, -10.0f, 10.0f);
		vertex[11].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[11].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[11].TexCoord = D3DXVECTOR2(2.0f / 4.0f, 2.0f / 3.0f);
	}
	{//←
		vertex[12].Position = D3DXVECTOR3(-10.0f, 10.0f, -10.0f);
		vertex[12].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[12].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[12].TexCoord = D3DXVECTOR2(0.0f / 4.0f, 1.0f / 3.0f);

		vertex[13].Position = D3DXVECTOR3(-10.0f, 10.0f, 10.0f);
		vertex[13].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[13].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[13].TexCoord = D3DXVECTOR2(1.0f / 4.0f, 1.0f / 3.0f);

		vertex[14].Position = D3DXVECTOR3(-10.0f, -10.0f, -10.0f);
		vertex[14].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[14].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[14].TexCoord = D3DXVECTOR2(0.0f / 4.0f, 2.0f / 3.0f);

		vertex[15].Position = D3DXVECTOR3(-10.0f, -10.0f, -10.0f);
		vertex[15].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[15].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[15].TexCoord = D3DXVECTOR2(0.0f / 4.0f, 2.0f / 3.0f);

		vertex[16].Position = D3DXVECTOR3(-10.0f, 10.0f, 10.0f);
		vertex[16].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[16].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[16].TexCoord = D3DXVECTOR2(1.0f / 4.0f, 1.0f / 3.0f);

		vertex[17].Position = D3DXVECTOR3(-10.0f, -10.0f, 10.0f);
		vertex[17].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[17].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[17].TexCoord = D3DXVECTOR2(1.0f / 4.0f, 2.0f / 3.0f);
	}
	{//→
		vertex[18].Position = D3DXVECTOR3(10.0f, 10.0f, 10.0f);
		vertex[18].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[18].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[18].TexCoord = D3DXVECTOR2(2.0f / 4.0f, 1.0f / 3.0f);

		vertex[19].Position = D3DXVECTOR3(10.0f, 10.0f, -10.0f);
		vertex[19].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[19].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[19].TexCoord = D3DXVECTOR2(3.0f / 4.0f, 1.0f / 3.0f);

		vertex[20].Position = D3DXVECTOR3(10.0f, -10.0f, 10.0f);
		vertex[20].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[20].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[20].TexCoord = D3DXVECTOR2(2.0f / 4.0f, 2.0f / 3.0f);

		vertex[21].Position = D3DXVECTOR3(10.0f, -10.0f, 10.0f);
		vertex[21].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[21].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[21].TexCoord = D3DXVECTOR2(2.0f / 4.0f, 2.0f / 3.0f);

		vertex[22].Position = D3DXVECTOR3(10.0f, 10.0f, -10.0f);
		vertex[22].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[22].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[22].TexCoord = D3DXVECTOR2(3.0f / 4.0f, 1.0f / 3.0f);

		vertex[23].Position = D3DXVECTOR3(10.0f, -10.0f, -10.0f);
		vertex[23].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[23].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[23].TexCoord = D3DXVECTOR2(3.0f / 4.0f, 2.0f / 3.0f);
	}
	{//後ろ
		vertex[24].Position = D3DXVECTOR3(10.0f, 10.0f, -10.0f);
		vertex[24].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[24].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[24].TexCoord = D3DXVECTOR2(3.0f / 4.0f, 1.0f / 3.0f);

		vertex[25].Position = D3DXVECTOR3(-10.0f, 10.0f, -10.0f);
		vertex[25].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[25].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[25].TexCoord = D3DXVECTOR2(4.0f / 4.0f, 1.0f / 3.0f);

		vertex[26].Position = D3DXVECTOR3(10.0f, -10.0f, -10.0f);
		vertex[26].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[26].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[26].TexCoord = D3DXVECTOR2(3.0f / 4.0f, 2.0f / 3.0f);

		vertex[27].Position = D3DXVECTOR3(10.0f, -10.0f, -10.0f);
		vertex[27].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[27].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[27].TexCoord = D3DXVECTOR2(3.0f / 4.0f, 2.0f / 3.0f);

		vertex[28].Position = D3DXVECTOR3(-10.0f, 10.0f, -10.0f);
		vertex[28].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[28].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[28].TexCoord = D3DXVECTOR2(4.0f / 4.0f, 1.0f / 3.0f);

		vertex[29].Position = D3DXVECTOR3(-10.0f, -10.0f, -10.0f);
		vertex[29].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[29].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[29].TexCoord = D3DXVECTOR2(4.0f / 4.0f, 2.0f / 3.0f);
	}
	{//↑
		vertex[30].Position = D3DXVECTOR3(-10.0f, 10.0f, -10.0f);
		vertex[30].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[30].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[30].TexCoord = D3DXVECTOR2(1.0f / 4.0f, 0.0f / 3.0f);

		vertex[31].Position = D3DXVECTOR3(10.0f, 10.0f, -10.0f);
		vertex[31].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[31].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[31].TexCoord = D3DXVECTOR2(2.0f / 4.0f, 0.0f / 3.0f);

		vertex[32].Position = D3DXVECTOR3(-10.0f, 10.0f, 10.0f);
		vertex[32].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[32].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[32].TexCoord = D3DXVECTOR2(1.0f / 4.0f, 1.0f / 3.0f);

		vertex[33].Position = D3DXVECTOR3(-10.0f, 10.0f, 10.0f);
		vertex[33].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[33].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[33].TexCoord = D3DXVECTOR2(1.0f / 4.0f, 1.0f / 3.0f);

		vertex[34].Position = D3DXVECTOR3(10.0f, 10.0f, -10.0f);
		vertex[34].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[34].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[34].TexCoord = D3DXVECTOR2(2.0f / 4.0f, 0.0f / 3.0f);

		vertex[35].Position = D3DXVECTOR3(10.0f, 10.0f, 10.0f);
		vertex[35].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[35].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[35].TexCoord = D3DXVECTOR2(2.0f / 4.0f, 1.0f / 3.0f);
	}

	CRenderer::GetDeviceContext()->Unmap(m_VertexBuffer, 0);



	D3DXMATRIX world, scale, rot, trans;
	D3DXMatrixScaling(&scale, m_Scale.x, m_Scale.y, m_Scale.z);
	D3DXMatrixRotationYawPitchRoll(&rot, m_Rotation.y, m_Rotation.x, m_Rotation.z);
	D3DXMatrixTranslation(&trans, m_Position.x, m_Position.y, m_Position.z);




	

	world = scale * rot * trans;
	
	UINT stride = sizeof(VERTEX_3D);
	UINT offset = 0;
	CRenderer::GetDeviceContext()->IASetVertexBuffers(
		0, 1, &m_VertexBuffer, &stride, &offset);

	MATERIAL material;
	ZeroMemory(&material, sizeof(material));
	material.Diffuse = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	CRenderer::SetMaterial(material);
	//テクスチャ設定
	if (CManager::SceneGet<CStage4>())
	{
		CRenderer::GetDeviceContext()->PSSetShaderResources(0, 1, &Sky_Texture);
	}

	//プリミティブトポロジ設定
	CRenderer::GetDeviceContext()->IASetPrimitiveTopology(
		D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	CRenderer::SetWorldMatrix(&world);
	CRenderer::GetDeviceContext()->Draw(36, 0);

	
}
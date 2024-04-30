#include "main.h"
#include "renderer.h"
#include "filed.h"
#include "input.h"
#include "light.h"
#include "Grid.h"
void CGrid::Init()
{
	VERTEX_3D vertex[800];
	for (int i = 0; i < 199; i++)
	{
		vertex[i * 4].Position = D3DXVECTOR3(-100.0f, 0.0f, 100.0f-i);
		vertex[i * 4].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[i * 4].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[i * 4].TexCoord = D3DXVECTOR2(0.0f, 0.0f);

		vertex[i * 4 + 1].Position = D3DXVECTOR3(100.0f , 0.0f, 100.0f-i);
		vertex[i * 4 + 1].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[i * 4 + 1].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[i * 4 + 1].TexCoord = D3DXVECTOR2(2.0f, 0.0f);

		vertex[i * 4 + 2].Position = D3DXVECTOR3(-100.0f+i , 0.0f, 100.0f );
		vertex[i * 4 + 2].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[i * 4 + 2].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[i * 4 + 2].TexCoord = D3DXVECTOR2(0.0f, 0.0f);

		vertex[i * 4 + 3].Position = D3DXVECTOR3(-100.0f+i , 0.0f, -100.0f );
		vertex[i * 4 + 3].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		vertex[i * 4 + 3].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[i * 4 + 3].TexCoord = D3DXVECTOR2(2.0f, 0.0f);
		if (i == 100)
		{
			vertex[i * 4].Position = D3DXVECTOR3(-100.0f, 0.0f, 100.0f - i );
			vertex[i * 4].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
			vertex[i * 4].Diffuse = D3DXVECTOR4(1.0f, 0.0f, 0.0f, 1.0f);
			vertex[i * 4].TexCoord = D3DXVECTOR2(0.0f, 0.0f);

			vertex[i * 4 + 1].Position = D3DXVECTOR3(100.0f , 0.0f, 100.0f - i);
			vertex[i * 4 + 1].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
			vertex[i * 4 + 1].Diffuse = D3DXVECTOR4(1.0f, 0.0f, 0.0f, 1.0f);
			vertex[i * 4 + 1].TexCoord = D3DXVECTOR2(2.0f, 0.0f);

			vertex[i * 4 + 2].Position = D3DXVECTOR3(-100.0f + i , 0.0f, 100.0f );
			vertex[i * 4 + 2].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
			vertex[i * 4 + 2].Diffuse = D3DXVECTOR4(0.0f, 0.0f, 1.0f, 1.0f);
			vertex[i * 4 + 2].TexCoord = D3DXVECTOR2(0.0f, 0.0f);

			vertex[i * 4 + 3].Position = D3DXVECTOR3(-100.0f + i, 0.0f, -100.0f);
			vertex[i * 4 + 3].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
			vertex[i * 4 + 3].Diffuse = D3DXVECTOR4(0.0f, 0.0f, 1.0f, 1.0f);
			vertex[i * 4 + 3].TexCoord = D3DXVECTOR2(2.0f, 0.0f);
		}
	}


	

	D3D11_BUFFER_DESC bd;
	ZeroMemory(&bd, sizeof(bd));
	bd.Usage = D3D11_USAGE_DEFAULT;
	bd.ByteWidth = sizeof(VERTEX_3D) * 800;
	bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	bd.CPUAccessFlags = 0;

	D3D11_SUBRESOURCE_DATA sd;
	ZeroMemory(&sd, sizeof(sd));
	sd.pSysMem = vertex;

	CRenderer::GetDevice()->CreateBuffer(&bd, &sd, &m_VertexBuffer);


	//ƒeƒNƒX?ƒƒ
	D3DX11CreateShaderResourceViewFromFile(CRenderer::GetDevice(),
		"asset/texture/color/White.jpg",
		NULL,
		NULL,
		&Field_Texture,
		NULL);

	assert(Field_Texture);

	m_Position = D3DXVECTOR3(0.0f, 0.0f, -50.0f);
	m_Rotation = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_Scale = D3DXVECTOR3(10.0f, 0.5f, 25.0f);
}

void CGrid::Uninit()
{
	m_VertexBuffer->Release();
	Field_Texture->Release();
}

void CGrid::Update()
{

}

void CGrid::Transparent()
{

}

void CGrid::Draw()
{
	LIGHT light;
	light.Enable = false;
	CRenderer::SetLight(light);


	D3DXMATRIX world, scale, rot, trans;
	D3DXMatrixScaling(&scale, m_Scale.x, m_Scale.y, m_Scale.z);
	D3DXMatrixRotationYawPitchRoll(&rot, m_Rotation.y, m_Rotation.x, m_Rotation.z);
	D3DXMatrixTranslation(&trans, m_Position.x, m_Position.y, m_Position.z);
	world = scale * rot * trans;

	CRenderer::SetWorldMatrix(&world);

	UINT stride = sizeof(VERTEX_3D);
	UINT offset = 0;
	CRenderer::GetDeviceContext()->IASetVertexBuffers(
		0, 1, &m_VertexBuffer, &stride, &offset);

	MATERIAL material;
	ZeroMemory(&material, sizeof(material));
	material.Diffuse = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	CRenderer::SetMaterial(material);
	CRenderer::GetDeviceContext()->PSSetShaderResources(0, 1, &Field_Texture);

	CRenderer::GetDeviceContext()->IASetPrimitiveTopology(
		D3D11_PRIMITIVE_TOPOLOGY_LINELIST);

	CRenderer::GetDeviceContext()->Draw(800, 0);
}
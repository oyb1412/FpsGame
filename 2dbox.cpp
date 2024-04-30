#include "main.h"
#include "renderer.h"
#include "2dbox.h"
#include "input.h"
#include "camera.h"
#include "scene.h"
#define FADE 1.0f

void C2DBox::Init()
{
	
	VERTEX_3D vertex[4];

	vertex[0].Position = D3DXVECTOR3(-100.0f, -100.0f,0.0f);
	vertex[0].Normal = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	vertex[0].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, FADE);
	vertex[0].TexCoord = D3DXVECTOR2(0.0f, 0.0f);

	vertex[1].Position = D3DXVECTOR3(100.0f, -100.0f, 0.0f);
	vertex[1].Normal = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	vertex[1].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, FADE);
	vertex[1].TexCoord = D3DXVECTOR2(1.0f, 0.0f);

	vertex[2].Position = D3DXVECTOR3(-100.0f, 100.0f, 0.0f);
	vertex[2].Normal = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	vertex[2].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, FADE);
	vertex[2].TexCoord = D3DXVECTOR2(0.0f, 1.0f);

	vertex[3].Position = D3DXVECTOR3(100.0f, 100.0f, 0.0f);
	vertex[3].Normal = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	vertex[3].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, FADE);
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


	Save_Min = vertex[0].Position;
	Save_Max = vertex[3].Position;
	Save_Min2 = Save_Min;
	Save_Max2 = Save_Max;

	D3DX11CreateShaderResourceViewFromFile(CRenderer::GetDevice(),
		"asset/texture/ui/MouseCursor.png",
		NULL,
		NULL,
		&Cursor_Texture,
		NULL);

}

void C2DBox::Uninit()
{
	if (m_VertexBuffer != NULL)
	{
		m_VertexBuffer->Release();
	}
	if (Cursor_Texture != NULL)
	{
		Cursor_Texture->Release();
	}
}

void C2DBox::Update(POINT Position, D3DXVECTOR3& Min, D3DXVECTOR3& Max)
{
	Min = Save_Min2;
	Max = Save_Max2;
}

void C2DBox::Draw(D3DXMATRIX* World,int Type)
{
	LIGHT light;
	light.Enable = false;
	CRenderer::SetLight(light);

	CRenderer::SetWorldViewProjection2D();

	
	D3DXVec3TransformCoord(&Save_Min2, &Save_Min, World);
	D3DXVec3TransformCoord(&Save_Max2, &Save_Max, World);

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
	

		//プリミティブトポロジ設定
		CRenderer::GetDeviceContext()->IASetPrimitiveTopology(
			D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP);
		CRenderer::SetWorldMatrix(World);
		assert(Cursor_Texture);
		CRenderer::GetDeviceContext()->PSSetShaderResources(0, 1, &Cursor_Texture);
		if (Type == 0)
		{
			//ポリゴン描画
			CRenderer::SetMode(0);
			CRenderer::GetDeviceContext()->Draw(4, 0);
			CRenderer::SetMode(1);
		}
		if (Type == 1)
		{

			CRenderer::GetDeviceContext()->Draw(4, 0);

		}

	
		
}


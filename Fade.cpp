#include "main.h"
#include "renderer.h"
#include "Fade.h"
ID3D11ShaderResourceView* CFade::White_Texture;
ID3D11ShaderResourceView* CFade::Black_Texture;
ID3D11ShaderResourceView* CFade::Red_Texture;
void CFade::Load()
{
	D3DX11CreateShaderResourceViewFromFile(CRenderer::GetDevice(),
		"asset/texture/color/White.jpg",
		NULL,
		NULL,
		&White_Texture,
		NULL);

	D3DX11CreateShaderResourceViewFromFile(CRenderer::GetDevice(),
		"asset/texture/color/Black.jpg",
		NULL,
		NULL,
		&Black_Texture,
		NULL);

	D3DX11CreateShaderResourceViewFromFile(CRenderer::GetDevice(),
		"asset/texture/color/Red.jpg",
		NULL,
		NULL,
		&Red_Texture,
		NULL);

}

void CFade::Unload()
{
	if (White_Texture != NULL)
	{
		White_Texture->Release();
	}
	if (Black_Texture != NULL)
	{
		Black_Texture->Release();
	}
	if (Red_Texture != NULL)
	{
		Red_Texture->Release();
	}
}
void CFade::Init()
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


	Fade = 0.9f;
	FadeOutType = false;
	FadeInType = false;


	m_Position = D3DXVECTOR3(SCREEN_WIDTH / 2 - 50, SCREEN_HEIGHT / 2 - 50, 0.0f);
	m_Rotation = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_Scale = D3DXVECTOR3(0.5f, 0.5f, 0.0f);
}

void CFade::Uninit()
{
	m_VertexBuffer->Release();
}

void CFade::Update()
{
	if (Type == FADE_WHITE || Type == FADE_RED)
	{
		Fade -= 0.05f;
	}
	if (Type == FADE_BLACK)
	{
		if (FadeOutType && !FadeInType)
		{
			if (Fade > 0.0f)
			{
				Fade -= 0.01f;
			}
			if (Fade <= 0.0f)
			{
				Fade = 0.0f;
			}
		}
		if (FadeInType)
		{
			if (Fade < 1.0f)
			{
				Fade += 0.02f;
			}
			if (Fade >= 1.0f)
			{
				Fade = 1.0f;
			}
		}
	}
}

void CFade::Transparent()
{

}

void CFade::Draw()
{
	D3DXMATRIX world, scale, rot, trans;
	D3DXMatrixScaling(&scale, m_Scale.x, m_Scale.y, m_Scale.z);
	D3DXMatrixRotationYawPitchRoll(&rot, m_Rotation.y, m_Rotation.x, m_Rotation.z);
	D3DXMatrixTranslation(&trans, m_Position.x, m_Position.y, m_Position.z);
	world = scale * rot * trans;


	LIGHT light;
	light.Enable = false;
	CRenderer::SetLight(light);

	//マトリクス設定
	CRenderer::SetWorldViewProjection2D();

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
	if (Type == FADE_WHITE)
	{
		assert(White_Texture);
		CRenderer::GetDeviceContext()->PSSetShaderResources(0, 1, &White_Texture);
	}
	if (Type == FADE_BLACK)
	{
		assert(Black_Texture);
		CRenderer::GetDeviceContext()->PSSetShaderResources(0, 1, &Black_Texture);
	}
	if (Type == FADE_RED)
	{
		assert(Red_Texture);
		CRenderer::GetDeviceContext()->PSSetShaderResources(0, 1, &Red_Texture);
	}
	//プリミティブトポロジ設定
	CRenderer::GetDeviceContext()->IASetPrimitiveTopology(
		D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP);
	CRenderer::SetWorldMatrix(&world);

	//ポリゴン描画
	CRenderer::GetDeviceContext()->Draw(4, 0);
}

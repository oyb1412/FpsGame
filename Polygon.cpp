#include "main.h"
#include "renderer.h"
#include "Polygon.h"
#include "Player.h"
#include "scene.h"
#include "manager.h"

ID3D11ShaderResourceView* CPolygon::Aim_Texture;
ID3D11ShaderResourceView* CPolygon::HPGage_Gray_Texture;
ID3D11ShaderResourceView* CPolygon::HPGage_Red_Texture;
ID3D11ShaderResourceView* CPolygon::GrayGage_Texture;
ID3D11ShaderResourceView* CPolygon::GreenGage_Texture;
ID3D11ShaderResourceView* CPolygon::GunUi_Texture;
ID3D11ShaderResourceView* CPolygon::ShotGunUi_Texture;
ID3D11ShaderResourceView* CPolygon::RifleGunUi_Texture;
ID3D11ShaderResourceView* CPolygon::BazookaUi_Texture;

ID3D11ShaderResourceView* CPolygon::Cursor_Texture;
ID3D11ShaderResourceView* CPolygon::TeleportLogo_Texture;
ID3D11ShaderResourceView* CPolygon::GateLogo_Texture;
ID3D11ShaderResourceView* CPolygon::Stage1Clear_Logo_Texture;
ID3D11ShaderResourceView* CPolygon::Stage2Clear_Logo_Texture;
ID3D11ShaderResourceView* CPolygon::Title_Logo1_Texture;
ID3D11ShaderResourceView* CPolygon::Title_Logo2_Texture;
ID3D11ShaderResourceView* CPolygon::Title_Logo3_Texture;
ID3D11ShaderResourceView* CPolygon::Title_Name_Texture;

ID3D11ShaderResourceView* CPolygon::Arrow_Texture;
ID3D11ShaderResourceView* CPolygon::Enemy_Attack_Texture;
ID3D11ShaderResourceView* CPolygon::Tutorial_Logo1_Texture;
ID3D11ShaderResourceView* CPolygon::Tutorial_Logo2_Texture;
ID3D11ShaderResourceView* CPolygon::Tutorial_Logo3_Texture;
ID3D11ShaderResourceView* CPolygon::Tutorial_Logo4_Texture;
ID3D11ShaderResourceView* CPolygon::Tutorial_Logo5_Texture;
ID3D11ShaderResourceView* CPolygon::Tutorial_Space_Texture;
ID3D11ShaderResourceView* CPolygon::Bg_Texture;
ID3D11ShaderResourceView* CPolygon::Clear_Logo1_Texture;
ID3D11ShaderResourceView* CPolygon::Clear_Logo2_Texture;
ID3D11ShaderResourceView* CPolygon::Clear_Bg_Texture;
ID3D11ShaderResourceView* CPolygon::Pause_Texture;
ID3D11ShaderResourceView* CPolygon::Pause2_Texture;

void CPolygon::Load()
{
	//テクス?ャ
	D3DX11CreateShaderResourceViewFromFile(CRenderer::GetDevice(),
		"asset/texture/logo/Pause_Logo2.png",
		NULL,
		NULL,
		&Pause2_Texture,
		NULL);

	D3DX11CreateShaderResourceViewFromFile(CRenderer::GetDevice(),
		"asset/texture/logo/Pause_Logo.png",
		NULL,
		NULL,
		&Pause_Texture,
		NULL);

	D3DX11CreateShaderResourceViewFromFile(CRenderer::GetDevice(),
		"asset/texture/bg/Clear.jpg",
		NULL,
		NULL,
		&Clear_Bg_Texture,
		NULL);

	D3DX11CreateShaderResourceViewFromFile(CRenderer::GetDevice(),
		"asset/texture/logo/Clear_Logo2.png",
		NULL,
		NULL,
		&Clear_Logo2_Texture,
		NULL);

	D3DX11CreateShaderResourceViewFromFile(CRenderer::GetDevice(),
		"asset/texture/logo/Clear_Logo1.png",
		NULL,
		NULL,
		&Clear_Logo1_Texture,
		NULL);

	D3DX11CreateShaderResourceViewFromFile(CRenderer::GetDevice(),
		"asset/texture/bg/Bg.jpg",
		NULL,
		NULL,
		&Bg_Texture,
		NULL);

	D3DX11CreateShaderResourceViewFromFile(CRenderer::GetDevice(),
		"asset/texture/ui/AIM.png",
		NULL,
		NULL,
		&Aim_Texture,
		NULL);

	D3DX11CreateShaderResourceViewFromFile(CRenderer::GetDevice(),
		"asset/texture/ui/Gage_Gray.png",
		NULL,
		NULL,
		&GrayGage_Texture,
		NULL);

	D3DX11CreateShaderResourceViewFromFile(CRenderer::GetDevice(),
		"asset/texture/ui/Gage_Green.png",
		NULL,
		NULL,
		&GreenGage_Texture,
		NULL);

	D3DX11CreateShaderResourceViewFromFile(CRenderer::GetDevice(),
		"asset/texture/ui/SmallGun_Ui.png",
		NULL,
		NULL,
		&GunUi_Texture,
		NULL);

	D3DX11CreateShaderResourceViewFromFile(CRenderer::GetDevice(),
		"asset/texture/ui/ShotGun_Ui.png",
		NULL,
		NULL,
		&ShotGunUi_Texture,
		NULL);

	D3DX11CreateShaderResourceViewFromFile(CRenderer::GetDevice(),
		"asset/texture/ui/RifleGun_Ui.png",
		NULL,
		NULL,
		&RifleGunUi_Texture,
		NULL);

	D3DX11CreateShaderResourceViewFromFile(CRenderer::GetDevice(),
		"asset/texture/ui/Bazooka_Ui.png",
		NULL,
		NULL,
		&BazookaUi_Texture,
		NULL);

	D3DX11CreateShaderResourceViewFromFile(CRenderer::GetDevice(),
		"asset/texture/ui/Cursor.png",
		NULL,
		NULL,
		&Cursor_Texture,
		NULL);

	D3DX11CreateShaderResourceViewFromFile(CRenderer::GetDevice(),
		"asset/texture/logo/Teleport_Logo.png",
		NULL,
		NULL,
		&TeleportLogo_Texture,
		NULL);

	D3DX11CreateShaderResourceViewFromFile(CRenderer::GetDevice(),
		"asset/texture/logo/Gate_Logo.png",
		NULL,
		NULL,
		&GateLogo_Texture,
		NULL);







	D3DX11CreateShaderResourceViewFromFile(CRenderer::GetDevice(),
		"asset/texture/logo/Stage1Clear_Logo.png",
		NULL,
		NULL,
		&Stage1Clear_Logo_Texture,
		NULL);

	D3DX11CreateShaderResourceViewFromFile(CRenderer::GetDevice(),
		"asset/texture/logo/Stage2Clear_Logo.png",
		NULL,
		NULL,
		&Stage2Clear_Logo_Texture,
		NULL);

	D3DX11CreateShaderResourceViewFromFile(CRenderer::GetDevice(),
		"asset/texture/logo/Title_Name.png",
		NULL,
		NULL,
		&Title_Name_Texture,
		NULL);

	D3DX11CreateShaderResourceViewFromFile(CRenderer::GetDevice(),
		"asset/texture/logo/Title_Logo1.png",
		NULL,
		NULL,
		&Title_Logo1_Texture,
		NULL);

	D3DX11CreateShaderResourceViewFromFile(CRenderer::GetDevice(),
		"asset/texture/logo/Title_Logo2.png",
		NULL,
		NULL,
		&Title_Logo2_Texture,
		NULL);

	D3DX11CreateShaderResourceViewFromFile(CRenderer::GetDevice(),
		"asset/texture/logo/Title_Logo3.png",
		NULL,
		NULL,
		&Title_Logo3_Texture,
		NULL);

	D3DX11CreateShaderResourceViewFromFile(CRenderer::GetDevice(),
		"asset/texture/ui/Arrow.png",
		NULL,
		NULL,
		&Arrow_Texture,
		NULL);

	D3DX11CreateShaderResourceViewFromFile(CRenderer::GetDevice(),
		"asset/texture/enemy/Enemy_Attack.png",
		NULL,
		NULL,
		&Enemy_Attack_Texture,
		NULL);

	D3DX11CreateShaderResourceViewFromFile(CRenderer::GetDevice(),
		"asset/texture/ui/HPGage_Gray.png",
		NULL,
		NULL,
		&HPGage_Gray_Texture,
		NULL);

	D3DX11CreateShaderResourceViewFromFile(CRenderer::GetDevice(),
		"asset/texture/color/Red.jpg",
		NULL,
		NULL,
		&HPGage_Red_Texture,
		NULL);


	D3DX11CreateShaderResourceViewFromFile(CRenderer::GetDevice(),
		"asset/texture/logo/Tutorial_Logo1.png",
		NULL,
		NULL,
		&Tutorial_Logo1_Texture,
		NULL);

	D3DX11CreateShaderResourceViewFromFile(CRenderer::GetDevice(),
		"asset/texture/logo/Tutorial_Logo2.png",
		NULL,
		NULL,
		&Tutorial_Logo2_Texture,
		NULL);

	D3DX11CreateShaderResourceViewFromFile(CRenderer::GetDevice(),
		"asset/texture/logo/Tutorial_Logo3.png",
		NULL,
		NULL,
		&Tutorial_Logo3_Texture,
		NULL);

	D3DX11CreateShaderResourceViewFromFile(CRenderer::GetDevice(),
		"asset/texture/logo/Tutorial_Logo4.png",
		NULL,
		NULL,
		&Tutorial_Logo4_Texture,
		NULL);

	D3DX11CreateShaderResourceViewFromFile(CRenderer::GetDevice(),
		"asset/texture/logo/Tutorial_Logo5.png",
		NULL,
		NULL,
		&Tutorial_Logo5_Texture,
		NULL);

	D3DX11CreateShaderResourceViewFromFile(CRenderer::GetDevice(),
		"asset/texture/logo/Tutorial_Space.png",
		NULL,
		NULL,
		&Tutorial_Space_Texture,
		NULL);
}
void CPolygon::Unload()
{
	Pause2_Texture->Release();
	Pause_Texture->Release();
	Clear_Bg_Texture->Release();
	Clear_Logo2_Texture->Release();
	Clear_Logo1_Texture->Release();
	Title_Name_Texture->Release();
	Bg_Texture->Release();
	Aim_Texture->Release();
	HPGage_Gray_Texture->Release();
	HPGage_Red_Texture->Release();
	GrayGage_Texture->Release();
	GreenGage_Texture->Release();
	GunUi_Texture->Release();
	ShotGunUi_Texture->Release();
	Cursor_Texture->Release();
	TeleportLogo_Texture->Release();
	GateLogo_Texture->Release();
	Stage1Clear_Logo_Texture->Release();
	Stage2Clear_Logo_Texture->Release();
	Title_Logo1_Texture->Release();
	Title_Logo2_Texture->Release();
	Title_Logo3_Texture->Release();
	Arrow_Texture->Release();
	Enemy_Attack_Texture->Release();
	Tutorial_Logo1_Texture->Release();
	Tutorial_Logo2_Texture->Release();
	Tutorial_Logo3_Texture->Release();
	Tutorial_Logo4_Texture->Release();
	Tutorial_Logo5_Texture->Release();
	Tutorial_Space_Texture->Release();
}

void CPolygon::Init()
{
	Box = new C2DBox();
	Box->Init();
	VERTEX_3D vertex[4];

	vertex[0].Position = D3DXVECTOR3(-100.0f, -100.0f, 0.0f);
	vertex[0].Normal = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	vertex[0].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
	vertex[0].TexCoord = D3DXVECTOR2(0.0f, 0.0f);

	vertex[1].Position = D3DXVECTOR3(100.0f, -100.0f, 0.0f);
	vertex[1].Normal = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	vertex[1].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
	vertex[1].TexCoord = D3DXVECTOR2(1.0f, 0.0f);

	vertex[2].Position = D3DXVECTOR3(-100.0f, 100.0f, 0.0f);
	vertex[2].Normal = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	vertex[2].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
	vertex[2].TexCoord = D3DXVECTOR2(0.0f, 1.0f);

	vertex[3].Position = D3DXVECTOR3(100.0f, 100.0f, 0.0f);
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


	
	m_Position = D3DXVECTOR3(SCREEN_WIDTH /2 - 50, SCREEN_HEIGHT/2 - 50, 0.0f);
	m_Rotation = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_Scale = D3DXVECTOR3(0.5f, 0.5f, 0.0f);
	GageUV = 1.0f;
	GageScale = m_Scale;
	GageTrans = m_Position;
	Count = 0;
	Fade = 1.0f;
	nagasa = 1.5f;
	FadeCount = false;
	for (int i = 0; i < 3; i++)
	{
		CursorMove[i] = false;
	}
}

void CPolygon::Uninit()
{
	m_VertexBuffer->Release();

	
}

void CPolygon::Update()
{
	CPlayer* player = CManager::GetScene()->GetGameObject<CPlayer>(2);


	Box->Update(position,m_min,m_max);
	if (Type == TITLE_NAME_TEXTURE || Type == CLEAR_LOGO1_TEXTURE || Type == PAUSE_TEXTURE)
	{
		if (Fade >= 1.0f)
		{
			FadeCount = false;
		}
		if (Fade <= 0.3f)
		{
			FadeCount = true;
		}
		if (FadeCount)
		{
			Fade += 0.01f;
		}
		if (!FadeCount)
		{
			Fade -= 0.01f;
		}
	}

	if (Type == SHOTGUN_IMPOSSIBLE_TEXTURE)
	{
		if (player->SetShotGun())
		{
			SetDestroy();
			return;
		}
	}
	if (Type == RIFLEGUN_IMPOSSIBLE_TEXTURE)
	{
		if (player->SetRifleGun())
		{
			SetDestroy();
			return;
		}
	}
	if (Type == GAGE_GREEN_TEXTURE)
	{
		m_Scale.x -= 0.009f;
		if (m_Scale.x <= 0.0f)
		{
			SetDestroy();
		}
	}
	if (Type == GAGE_GRAY_TEXTURE)
	{
		m_Scale.z -= 0.009f;
		if (m_Scale.z <= 0.0f)
		{
			SetDestroy();
		}
	}
	if (Type == HPGAGE_RED_TEXTURE)
	{
	
		for (int i = 0; i < 11; i++)
		{

			if (player->GetPlayerHp() == i*10)
			{
				nagasa = 0.15f * i;
			}
			m_Scale.y = nagasa;

		}
	}
	if (Type == ENEMY_ATTACK_TEXTURE)
	{
		Count++;
		if (Count > 60)
		{
			Fade -= 0.05f;
			if (Fade <= 0.0f)
			{
				SetDestroy();
			}
		}
	}
	if (Type == CURSOR_TEXTURE)
	{
		if (CursorMove[0])
		{
			if (m_Position.y < SCREEN_HEIGHT *0.77f)
			{
				m_Position.y += 12.0f;
			}
			if (m_Position.y >= SCREEN_HEIGHT * 0.77f)
			{
				m_Position.y = SCREEN_HEIGHT * 0.77f;
				CursorMove[0] = false;
			}
		}
		if (CursorMove[1])
		{
			if (m_Position.y > SCREEN_HEIGHT *0.68f)
			{
				m_Position.y -= 12.0f;
				if (m_Position.y <= SCREEN_HEIGHT * 0.68f)
				{
					m_Position.y = SCREEN_HEIGHT *0.68f;
					CursorMove[1] = false;
				}
			}
			if (m_Position.y < SCREEN_HEIGHT *0.68f)
			{
				m_Position.y += 12.0f;
				if (m_Position.y >= SCREEN_HEIGHT * 0.68f)
				{
					m_Position.y = SCREEN_HEIGHT * 0.68f;
					CursorMove[1] = false;
				}
			}

		}
		if (CursorMove[2])
		{
			if (m_Position.y > SCREEN_HEIGHT *0.57f)
			{
				m_Position.y -= 12.0f;
			}
			if (m_Position.y <= SCREEN_HEIGHT * 0.57f)
			{
				m_Position.y = SCREEN_HEIGHT * 0.57f;
				CursorMove[2] = false;
			}
		}
		if (CursorMove[3])
		{
			if (m_Position.y > SCREEN_HEIGHT *0.475f)
			{
				m_Position.y -= 12.0f;
			}
			if (m_Position.y <= SCREEN_HEIGHT * 0.475f)
			{
				m_Position.y = SCREEN_HEIGHT * 0.475f;
				CursorMove[3] = false;
			}
		}
			
	}
}

void CPolygon::Transparent()
{
	if (Type == TITLE_LOGO1_TEXTURE || Type == TITLE_LOGO2_TEXTURE || Type == TITLE_LOGO3_TEXTURE
		|| Type == CLEAR_LOGO2_TEXTURE )
	{
		Box->Draw(&world);
	}
}

void CPolygon::Draw()
{
	LIGHT light;
	light.Enable = false;
	CRenderer::SetLight(light);

	CRenderer::SetWorldViewProjection2D();

	//頂?バッフ?
	UINT stride = sizeof(VERTEX_3D);
	UINT offset = 0;
	CRenderer::GetDeviceContext()->IASetVertexBuffers(
		0, 1, &m_VertexBuffer, &stride, &offset);

	MATERIAL material;
	ZeroMemory(&material, sizeof(material));
	material.Diffuse = D3DXCOLOR(1.0f, 1.0f, 1.0f, Fade);
	CRenderer::SetMaterial(material);


	D3DXMATRIX  scale, rot, trans, trans1, trans2, trans3;
	D3DXMatrixScaling(&scale, m_Scale.x, m_Scale.y, m_Scale.z);
	D3DXMatrixRotationYawPitchRoll(&rot, m_Rotation.y, m_Rotation.x, m_Rotation.z);

	D3DXVECTOR3 Lentgh = D3DXVECTOR3(SCREEN_WIDTH, SCREEN_HEIGHT, 0.0f) - m_Position;

	D3DXMatrixTranslation(&trans1, m_Scale.x*0.5f - 100.0f, m_Scale.y*0.5f + 100.0f, 0.0f);
	D3DXMatrixTranslation(&trans2, m_Scale.x*0.5f + 100.0f, m_Scale.y*0.5f - 100.0f, 0.0f);

	if (Type == GAGE_GRAY_TEXTURE || Type == GAGE_GREEN_TEXTURE || Type == HPGAGE_RED_TEXTURE || Type == HPGAGE_GRAY_TEXTURE)
	{
		D3DXMatrixTranslation(&trans, m_Position.x + 50.0f, m_Position.y - 50.0f, m_Position.z);

		world = trans2 * scale* trans1* rot *trans;
	}
	else
	{
		D3DXMatrixTranslation(&trans, m_Position.x , m_Position.y, m_Position.z);

		world =  scale*  rot *trans;

	}
	CPlayer* Player = CManager::GetScene()->GetGameObject<CPlayer>(2);



	//?トリクス設定



	//テクス?ャ設定
	if (Type == AIM_TEXTURE)
	{
		assert(Aim_Texture);
		CRenderer::GetDeviceContext()->PSSetShaderResources(0, 1, &Aim_Texture);
	

		//?リゴン?画
	}
	if (Type == GAGE_GRAY_TEXTURE)
	{
		assert(GrayGage_Texture);
		CRenderer::GetDeviceContext()->PSSetShaderResources(0, 1, &GrayGage_Texture);
	}
	if (Type == GAGE_GREEN_TEXTURE)
	{

		assert(GreenGage_Texture);
		CRenderer::GetDeviceContext()->PSSetShaderResources(0, 1, &GreenGage_Texture);
	}
	if (Type == SMALLGUN_UI_TEXTURE)
	{

		assert(GunUi_Texture);
		CRenderer::GetDeviceContext()->PSSetShaderResources(0, 1, &GunUi_Texture);
	}
	if (Type == SHOTGUN_UI_TEXTURE)
	{

		assert(ShotGunUi_Texture);
		CRenderer::GetDeviceContext()->PSSetShaderResources(0, 1, &ShotGunUi_Texture);
	}
	if (Type == RIPLEGUN_UI_TEXTURE)
	{

		assert(RifleGunUi_Texture);
		CRenderer::GetDeviceContext()->PSSetShaderResources(0, 1, &RifleGunUi_Texture);
	}
	if (Type == BAZOOKA_UI_TEXTURE)
	{

		assert(BazookaUi_Texture);
		CRenderer::GetDeviceContext()->PSSetShaderResources(0, 1, &BazookaUi_Texture);
	}
	if (Type == CURSOR_TEXTURE)
	{

		assert(Cursor_Texture);
		CRenderer::GetDeviceContext()->PSSetShaderResources(0, 1, &Cursor_Texture);
	}
	if (Type == TELEPORT_TEXTURE)
	{

		assert(TeleportLogo_Texture);
		CRenderer::GetDeviceContext()->PSSetShaderResources(0, 1, &TeleportLogo_Texture);
	}
	if (Type == GATE_TEXTURE)
	{

		assert(GateLogo_Texture);
		CRenderer::GetDeviceContext()->PSSetShaderResources(0, 1, &GateLogo_Texture);
	}


	if (Type == STAGE1CLEAR_LOGO_TEXTURE)
	{
		assert(Stage1Clear_Logo_Texture);
		CRenderer::GetDeviceContext()->PSSetShaderResources(0, 1, &Stage1Clear_Logo_Texture);
	}
	if (Type == STAGE2CLEAR_LOGO_TEXTURE)
	{
		assert(Stage2Clear_Logo_Texture);
		CRenderer::GetDeviceContext()->PSSetShaderResources(0, 1, &Stage2Clear_Logo_Texture);
	}
	if (Type == TITLE_LOGO1_TEXTURE)
	{
		assert(Title_Logo1_Texture);
		CRenderer::GetDeviceContext()->PSSetShaderResources(0, 1, &Title_Logo1_Texture);
	}
	if (Type == TITLE_LOGO2_TEXTURE)
	{
		assert(Title_Logo2_Texture);
		CRenderer::GetDeviceContext()->PSSetShaderResources(0, 1, &Title_Logo2_Texture);
	}
	if (Type == TITLE_LOGO3_TEXTURE)
	{
		assert(Title_Logo3_Texture);
		CRenderer::GetDeviceContext()->PSSetShaderResources(0, 1, &Title_Logo3_Texture);
	}
	if (Type == ARROW_TEXTURE)
	{
		assert(Arrow_Texture);
		CRenderer::GetDeviceContext()->PSSetShaderResources(0, 1, &Arrow_Texture);
	}
	if (Type == ENEMY_ATTACK_TEXTURE)
	{
		assert(Enemy_Attack_Texture);
		CRenderer::GetDeviceContext()->PSSetShaderResources(0, 1, &Enemy_Attack_Texture);
	}
	if (Type == HPGAGE_GRAY_TEXTURE)
	{
		assert(HPGage_Gray_Texture);
		CRenderer::GetDeviceContext()->PSSetShaderResources(0, 1, &HPGage_Gray_Texture);
	}
	if (Type == HPGAGE_RED_TEXTURE)
	{
		assert(HPGage_Red_Texture);
		CRenderer::GetDeviceContext()->PSSetShaderResources(0, 1, &HPGage_Red_Texture);
	}
	if (Type == TUTORIAL_LOGO1_TEXTURE)
	{
		assert(Tutorial_Logo1_Texture);
		CRenderer::GetDeviceContext()->PSSetShaderResources(0, 1, &Tutorial_Logo1_Texture);
	}
	if (Type == TUTORIAL_LOGO2_TEXTURE)
	{
		assert(Tutorial_Logo2_Texture);
		CRenderer::GetDeviceContext()->PSSetShaderResources(0, 1, &Tutorial_Logo2_Texture);
	}
	if (Type == TUTORIAL_LOGO3_TEXTURE)
	{
		assert(Tutorial_Logo3_Texture);
		CRenderer::GetDeviceContext()->PSSetShaderResources(0, 1, &Tutorial_Logo3_Texture);
	}
	if (Type == TUTORIAL_LOGO4_TEXTURE)
	{
		assert(Tutorial_Logo4_Texture);
		CRenderer::GetDeviceContext()->PSSetShaderResources(0, 1, &Tutorial_Logo4_Texture);
	}
	if (Type == TUTORIAL_LOGO5_TEXTURE)
	{
		assert(Tutorial_Logo5_Texture);
		CRenderer::GetDeviceContext()->PSSetShaderResources(0, 1, &Tutorial_Logo5_Texture);
	}
	if (Type == TUTORIAL_SPACE)
	{
		assert(Tutorial_Space_Texture);
		CRenderer::GetDeviceContext()->PSSetShaderResources(0, 1, &Tutorial_Space_Texture);
	}
	if (Type == BG_TEXTURE)
	{
		assert(Bg_Texture);
		CRenderer::GetDeviceContext()->PSSetShaderResources(0, 1, &Bg_Texture);
	}
	if (Type == TITLE_NAME_TEXTURE)
	{
		assert(Title_Name_Texture);
		CRenderer::GetDeviceContext()->PSSetShaderResources(0, 1, &Title_Name_Texture);
	}
	if (Type == CLEAR_LOGO1_TEXTURE)
	{
		assert(Clear_Logo1_Texture);
		CRenderer::GetDeviceContext()->PSSetShaderResources(0, 1, &Clear_Logo1_Texture);
	}
	if (Type == CLEAR_LOGO2_TEXTURE)
	{
		assert(Clear_Logo2_Texture);
		CRenderer::GetDeviceContext()->PSSetShaderResources(0, 1, &Clear_Logo2_Texture);
	}
	if (Type == CLEAR_BG_TEXTURE)
	{
		assert(Clear_Bg_Texture);
		CRenderer::GetDeviceContext()->PSSetShaderResources(0, 1, &Clear_Bg_Texture);
	}
	if (Type == PAUSE_TEXTURE)
	{
		assert(Pause_Texture);
		CRenderer::GetDeviceContext()->PSSetShaderResources(0, 1, &Pause_Texture);
	}
	if (Type == PAUSE2_TEXTURE)
	{
		assert(Pause2_Texture);
		CRenderer::GetDeviceContext()->PSSetShaderResources(0, 1, &Pause2_Texture);
	}
	//プリ?ティブト?ロジ設定
	CRenderer::GetDeviceContext()->IASetPrimitiveTopology(
		D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP);
	CRenderer::SetWorldMatrix(&world);
	CRenderer::GetDeviceContext()->Draw(4, 0);


	//?リゴン?画
}

#include "main.h"
#include "manager.h"
#include "renderer.h"
#include "model.h"
#include "bullet.h"
#include "Player.h"
#include "box.h"
#include "input.h"
#include "scene.h"
#include "camera.h"
#include "sound.h"
#include "Mouse.h"
#include "Polygon.h"
#define MAXREROADTIME 170
int CPlayer::SmallGun_Bullet_Number = 20;
int CPlayer::ShotGun_Bullet_Number = 10;
int CPlayer::RifleGun_Bullet_Number = 30;
int CPlayer::Bazooka_Bullet_Number = 5;

int CPlayer::SmallGun_Max_Bullet_Number = 40;
int CPlayer::ShotGun_Max_Bullet_Number = 20;
int CPlayer::RifleGun_Max_Bullet_Number = 90;
int CPlayer::Bazooka_Max_Bullet_Number = 10;

bool CPlayer::HaveSmallGun = false;

bool CPlayer::HaveShotGun = false;
bool CPlayer::HaveRifleGun = false;
bool CPlayer::HaveBazooka = false;

int CPlayer::Player_Hp = 100;

CModel* CPlayer::Model_SmallGun;
CModel* CPlayer::Model_ShotGun;
CModel* CPlayer::Model_RifleGun;
CModel* CPlayer::Model_Bazooka;

D3DXMATRIX mtxRotation;
float ShotAngle;
ID3D11ShaderResourceView* CPlayer::SmallGun_Texture;
ID3D11ShaderResourceView* CPlayer::ShotGun_Texture;
ID3D11ShaderResourceView* CPlayer::RifleGun_Texture;

void CPlayer::Load()
{
	Model_SmallGun = new CModel();
	Model_SmallGun->Load("asset\\model\\model\\wqe.obj");
	Model_ShotGun = new CModel();
	Model_ShotGun->Load("asset\\model\\model\\shotgun.obj");
	Model_RifleGun = new CModel();
	Model_RifleGun->Load("asset\\model\\model\\rifle.obj");
	Model_Bazooka = new CModel();
	Model_Bazooka->Load("asset\\model\\model\\bazooka.obj");

	D3DX11CreateShaderResourceViewFromFile(CRenderer::GetDevice(),
		"asset/texture/gun/SmallGun_Texture.jpg",
		NULL,
		NULL,
		&SmallGun_Texture,
		NULL);

	D3DX11CreateShaderResourceViewFromFile(CRenderer::GetDevice(),
		"asset/texture/gun/ShotGun_Texture.jpg",
		NULL,
		NULL,
		&ShotGun_Texture,
		NULL);

	D3DX11CreateShaderResourceViewFromFile(CRenderer::GetDevice(),
		"asset/texture/gun/RifleGun_Texture.jpg",
		NULL,
		NULL,
		&RifleGun_Texture,
		NULL);
}
void CPlayer::Unload()
{
	Model_Bazooka->Unload();
	delete Model_Bazooka;
	Model_SmallGun->Unload();
	delete Model_SmallGun;
	Model_ShotGun->Unload();
	delete Model_ShotGun;
	Model_RifleGun->Unload();
	delete Model_RifleGun;
	SmallGun_Texture->Release();
	ShotGun_Texture->Release();
	RifleGun_Texture->Release();
}

void CPlayer::Init()
{

	m_Position = D3DXVECTOR3(-80.0f, 1.0f, -275.0f);
	m_Rotation = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_Scale = D3DXVECTOR3(0.05f, 0.05f, 0.05f);
	
	m_Max = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_Min =D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	ShotAngle = 0.0f;
	Reroad_Start = false;
	WallFloat = 0.0f;
	
	ShotGun_Reroad = false;
	Angle_Start = false;
	Reroad_Time = 0;
	

	WeaponType = SMALLGUN;
	WeaponChange = false;
	Item_Key = false;
	
	Player_Hp = 100;
}

void CPlayer::Uninit()
{
	
}

void CPlayer::Update()
{
	CScene* scene = CManager::GetScene();
	CCamera* Camera = CManager::GetScene()->GetGameObject<CCamera>(0);
	CPolygon* ImpossibleShotgun = CManager::GetScene()->GetGameObject<CPolygon>(16);
	CPolygon* ImpossibleRiflegun = CManager::GetScene()->GetGameObject<CPolygon>(17);

	
	if (WeaponType == BAZOOKA)
	{
		m_Scale = D3DXVECTOR3(0.15f, 0.15f, 0.2f);
		if (!Reroad_Start && !WeaponChange)
		{
			m_Position.y = Camera->GetPosition().y - 0.35f;
		}
		/*if (Camera->GetBazookaShot() && ShotAngle > -40.0f)
		{
			ShotAngle -= 1.0f;
		}
		


		if (!Camera->GetBazookaShot() && !Reroad_Start)
		{
			ShotAngle = 0.0f;
		}*/
		if (Angle_Start)
		{
			if (ShotAngle > -80.0f)
			{
				ShotAngle -= 3.0f;
			}
			if (ShotAngle <= -60.0f)
			{
				ShotAngle = 0.0f;
				Angle_Start = false;
			}
		}
		else
		{
			ShotAngle = 0.0f;

		}
		if (WeaponChange)
		{
			ShotAngle += 1.0f;
			m_Position.y -= 0.15f;
			Reroad_Time++;
			if (40 < Reroad_Time)
			{
				Reroad_Time = 0;
				WeaponChange = false;
			}
		}
		if (Reroad_Start)
		{

			ShotAngle += 1.0f;
			m_Position.y -= 0.15f;
			Reroad_Time++;
			if (MAXREROADTIME < Reroad_Time)
			{
				if (Bazooka_Bullet_Number == 0 && Bazooka_Max_Bullet_Number >= 10)
				{
					Bazooka_Max_Bullet_Number -= 5;
					Bazooka_Bullet_Number += 5;
					Reroad_Start = false;
					Reroad_Time = 0;
					ShotAngle = 0.0f;
				}
				else if (Bazooka_Bullet_Number == 0 && Bazooka_Max_Bullet_Number <= 5)
				{
					Bazooka_Bullet_Number += Bazooka_Max_Bullet_Number;
					Bazooka_Max_Bullet_Number = 0;
					Reroad_Start = false;
					Reroad_Time = 0;
					ShotAngle = 0.0f;
				}
				else if (Bazooka_Bullet_Number > 0 && Bazooka_Max_Bullet_Number >= 10)
				{
					int nokori = 5 - Bazooka_Bullet_Number;
					Bazooka_Bullet_Number += nokori;
					Bazooka_Max_Bullet_Number -= nokori;
					Reroad_Start = false;
					Reroad_Time = 0;
					ShotAngle = 0.0f;
				}
				else if (Bazooka_Bullet_Number > 0 && Bazooka_Max_Bullet_Number < 10)
				{
					int nokori = 5 - Bazooka_Bullet_Number;

					if (Bazooka_Max_Bullet_Number > nokori)
					{
						Bazooka_Bullet_Number += nokori;
						Bazooka_Max_Bullet_Number -= nokori;
						Reroad_Start = false;
						Reroad_Time = 0;
						ShotAngle = 0.0f;
					}
					else if (Bazooka_Max_Bullet_Number <= nokori)
					{
						Bazooka_Bullet_Number += Bazooka_Max_Bullet_Number;
						Bazooka_Max_Bullet_Number = 0;
						Reroad_Start = false;
						Reroad_Time = 0;
						ShotAngle = 0.0f;
					}
				}
			}
		}
	}

	if (WeaponType == RIFLEGUN)
	{
		m_Scale = D3DXVECTOR3(0.15f, 0.15f, 0.2f);
		if (!Reroad_Start && !WeaponChange)
		{
			m_Position.y = Camera->GetPosition().y - 0.35f;
		}
		if (Camera->GetRifleGunShot() && ShotAngle > -40.0f)
		{
			ShotAngle -= 0.04f;

		}
	

		if (!Camera->GetRifleGunShot() && !Reroad_Start)
		{
			ShotAngle = 0.0f;

		}
		if (WeaponChange)
		{
			ShotAngle += 1.0f;
			m_Position.y -= 0.15f;
			Reroad_Time++;
			if (40 < Reroad_Time)
			{
				Reroad_Time = 0;
				WeaponChange = false;
			}
		}
		if (Reroad_Start)
		{

			ShotAngle += 1.0f;
			m_Position.y -= 0.15f;
			Reroad_Time++;
			if (MAXREROADTIME < Reroad_Time)
			{
				if (RifleGun_Bullet_Number == 0 && RifleGun_Max_Bullet_Number >= 30)
				{
					RifleGun_Max_Bullet_Number -= 30;
					RifleGun_Bullet_Number += 30;
					Reroad_Start = false;
					Reroad_Time = 0;
					ShotAngle = 0.0f;
				}
				else if (RifleGun_Bullet_Number == 0 && RifleGun_Max_Bullet_Number < 30)
				{
					RifleGun_Bullet_Number += RifleGun_Max_Bullet_Number;
					RifleGun_Max_Bullet_Number = 0;
					Reroad_Start = false;
					Reroad_Time = 0;
					ShotAngle = 0.0f;
				}
				else if (RifleGun_Bullet_Number > 0 && RifleGun_Max_Bullet_Number >= 30)
				{
					int nokori = 30 - RifleGun_Bullet_Number;
					RifleGun_Bullet_Number += nokori;
					RifleGun_Max_Bullet_Number -= nokori;
					Reroad_Start = false;
					Reroad_Time = 0;
					ShotAngle = 0.0f;
				}
				else if (RifleGun_Bullet_Number > 0 && RifleGun_Max_Bullet_Number < 30)
				{
					int nokori = 30 - RifleGun_Bullet_Number;

					if (RifleGun_Max_Bullet_Number > nokori)
					{
						RifleGun_Bullet_Number += nokori;
						RifleGun_Max_Bullet_Number -= nokori;
						Reroad_Start = false;
						Reroad_Time = 0;
						ShotAngle = 0.0f;
					}
					else if (RifleGun_Max_Bullet_Number <= nokori)
					{
						RifleGun_Bullet_Number += RifleGun_Max_Bullet_Number;
						RifleGun_Max_Bullet_Number = 0;
						Reroad_Start = false;
						Reroad_Time = 0;
						ShotAngle = 0.0f;
					}
				}
			}
		}
	}

	if (WeaponType == SHOTGUN)
	{
		m_Scale = D3DXVECTOR3(0.15f, 0.15f, 0.2f);
		if (!Reroad_Start && !WeaponChange )
		{
			m_Position.y = Camera->GetPosition().y - 0.45f;
		}
		
		if (Angle_Start)
		{
			if (ShotAngle > -60.0f)
			{
				ShotAngle -= 5.0f;
			}
			if (ShotAngle <= -60.0f)
			{
				ShotAngle = 0.0f;
				Angle_Start = false;
			}
		}
	

	
		if (WeaponChange)
		{
			ShotAngle += 1.0f;
			m_Position.y -= 0.15f;
			Reroad_Time++;
			if (40 < Reroad_Time)
			{
				ShotAngle = 0.0f;
				Reroad_Time = 0;
				WeaponChange = false;
			}
		}
		if (Reroad_Start)
		{

			ShotAngle += 1.0f;
			m_Position.y -= 0.15f;
			Reroad_Time++;
			if (MAXREROADTIME < Reroad_Time)
			{
				if (ShotGun_Bullet_Number == 0 && ShotGun_Max_Bullet_Number >= 10)
				{
					ShotGun_Max_Bullet_Number -= 10;
					ShotGun_Bullet_Number += 10;
					Reroad_Start = false;
					Reroad_Time = 0;
					ShotAngle = 0.0f;
				}
				else if (ShotGun_Bullet_Number == 0 && ShotGun_Max_Bullet_Number < 10)
				{
					ShotGun_Bullet_Number += ShotGun_Max_Bullet_Number;
					ShotGun_Max_Bullet_Number = 0;
					Reroad_Start = false;
					Reroad_Time = 0;
					ShotAngle = 0.0f;
				}
				else if (ShotGun_Bullet_Number > 0 && ShotGun_Max_Bullet_Number >= 10)
				{
					int nokori = 10 - ShotGun_Bullet_Number;
					ShotGun_Bullet_Number += nokori;
					ShotGun_Max_Bullet_Number -= nokori;
					Reroad_Start = false;
					Reroad_Time = 0;
					ShotAngle = 0.0f;
				}
				else if (ShotGun_Bullet_Number > 0 && ShotGun_Max_Bullet_Number < 10)
				{
					int nokori = 10 - ShotGun_Bullet_Number;

					if (ShotGun_Max_Bullet_Number > nokori)
					{
						ShotGun_Bullet_Number += nokori;
						ShotGun_Max_Bullet_Number -= nokori;
						Reroad_Start = false;
						Reroad_Time = 0;
						ShotAngle = 0.0f;
					}
					else if (ShotGun_Max_Bullet_Number <= nokori)
					{
						ShotGun_Bullet_Number += ShotGun_Max_Bullet_Number;
						ShotGun_Max_Bullet_Number = 0;
						Reroad_Start = false;
						Reroad_Time = 0;
						ShotAngle = 0.0f;
					}
				}
			}
		}
	
		
	}
	if (WeaponType == SMALLGUN)
	{
		m_Scale = D3DXVECTOR3(0.05f, 0.05f, 0.05f);
		if (!Reroad_Start && !WeaponChange)
		{
			m_Position.y = Camera->GetPosition().y - 0.35f;
		}

		if (Angle_Start)
		{
			if (ShotAngle > -45.0f)
			{
				ShotAngle -= 3.0f;
			}
			if (ShotAngle <= -45.0f)
			{
				ShotAngle = 0.0f;
				Angle_Start = false;
			}
		}

		if (WeaponChange)
		{
			ShotAngle += 1.0f;
			m_Position.y -= 0.15f;
			Reroad_Time++;
			if (40 < Reroad_Time)
			{
				Reroad_Time = 0;
				ShotAngle = 0.0f;
				WeaponChange = false;
			}
		}
		if (Reroad_Start)
		{

			ShotAngle += 1.0f;
			m_Position.y -= 0.15f;
			Reroad_Time++;
			if (MAXREROADTIME < Reroad_Time)
			{
				if (SmallGun_Bullet_Number == 0 && SmallGun_Max_Bullet_Number >= 20)
				{
					SmallGun_Max_Bullet_Number -= 20;
					SmallGun_Bullet_Number += 20;
					Reroad_Start = false;
					Reroad_Time = 0;
					ShotAngle = 0.0f;
				}
				else if (SmallGun_Bullet_Number == 0 && SmallGun_Max_Bullet_Number < 20)
				{
					SmallGun_Bullet_Number += SmallGun_Max_Bullet_Number;
					SmallGun_Max_Bullet_Number = 0;
					Reroad_Start = false;
					Reroad_Time = 0;
					ShotAngle = 0.0f;
				}
				else if (SmallGun_Bullet_Number > 0 && SmallGun_Max_Bullet_Number >= 20)
				{
					int nokori = 20 - SmallGun_Bullet_Number;
					SmallGun_Bullet_Number += nokori;
					SmallGun_Max_Bullet_Number -= nokori;
					Reroad_Start = false;
					Reroad_Time = 0;
					ShotAngle = 0.0f;
				}
				else if (SmallGun_Bullet_Number > 0 && SmallGun_Max_Bullet_Number < 20)
				{
					int nokori = 20 - SmallGun_Bullet_Number;

					if (SmallGun_Max_Bullet_Number > nokori)
					{
						SmallGun_Bullet_Number += nokori;
						SmallGun_Max_Bullet_Number -= nokori;
						Reroad_Start = false;
						Reroad_Time = 0;
						ShotAngle = 0.0f;
					}
					else if (SmallGun_Max_Bullet_Number <= nokori)
					{
						SmallGun_Bullet_Number += SmallGun_Max_Bullet_Number;
						SmallGun_Max_Bullet_Number = 0;
						Reroad_Start = false;
						Reroad_Time = 0;
						ShotAngle = 0.0f;
					}
				}
			}
		}
	}
	m_Position.z = Camera->GetPosition().z+((Camera->GetFrontVec().z*0.8f + Camera->GetRightVec().z*0.4f));
	m_Position.x = Camera->GetPosition().x + ((Camera->GetFrontVec().x*0.8f + Camera->GetRightVec().x*0.4f));
	if (Type == SHOTGUN)
	{
		m_Position.z = Camera->GetPosition().z + ((Camera->GetFrontVec().z*1.0f + Camera->GetRightVec().z*0.4f));
	}

}

void CPlayer::Transparent()
{

}

void CPlayer::Draw()
{
	CCamera* camera = CManager::GetScene()->GetGameObject<CCamera>(0);
	D3DXMATRIX view = camera->GetViewMatrix();
	D3DXMATRIX invView;
	D3DXVECTOR3 Camera = camera->GetPosition();
	D3DXVECTOR3 dir = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	D3DXMatrixLookAtLH(&EviewMatrix, &Camera, &m_Position
		, &dir);
	view = EviewMatrix;
	
	D3DXMatrixIdentity(&invView);

	invView._11 = view._11;
	invView._13 = view._13;
	invView._31 = view._31;
	invView._33 = view._33;
	D3DXMatrixInverse(&invView, NULL, &invView);



	D3DXMATRIX world, scale, rot,rotx, trans,RifleWorld,RifleScale,Shotrot,Shotrotx,Shotworld;
	D3DXMatrixScaling(&scale, m_Scale.x, m_Scale.y, m_Scale.z);
	D3DXMatrixScaling(&RifleScale, m_Scale.x*0.6f, m_Scale.y*0.6f, m_Scale.z*0.6f);

	D3DXMatrixRotationY(&rot, D3DXToRadian(70));
	D3DXMatrixRotationY(&Shotrot, D3DXToRadian(150));
	D3DXVECTOR3 cameraDir = camera->GetRightVec();
	D3DXMatrixRotationAxis(&rotx, &cameraDir, D3DXToRadian(ShotAngle));
	D3DXMatrixRotationAxis(&Shotrotx, &cameraDir, D3DXToRadian(-ShotAngle));

	D3DXMatrixTranslation(&trans, m_Position.x, m_Position.y, m_Position.z);

	world = scale * invView *rot*rotx* trans;
	RifleWorld = RifleScale * invView *rotx* trans;
	Shotworld = scale * invView*Shotrotx*Shotrot* trans;
	CRenderer::SetWorldMatrix(&world);

	if (WeaponType == SMALLGUN && HaveSmallGun)
	{
		assert(SmallGun_Texture);
		CRenderer::GetDeviceContext()->PSSetShaderResources(0, 1, &SmallGun_Texture);
		Model_SmallGun->Draw();
	}
	if (WeaponType == SHOTGUN)
	{
		assert(ShotGun_Texture);
		CRenderer::GetDeviceContext()->PSSetShaderResources(0, 1, &ShotGun_Texture);
		CRenderer::SetWorldMatrix(&Shotworld);

		Model_ShotGun->Draw();
	}
	if (WeaponType == RIFLEGUN)
	{
		assert(RifleGun_Texture);
		CRenderer::GetDeviceContext()->PSSetShaderResources(0, 1, &RifleGun_Texture);
		CRenderer::SetWorldMatrix(&RifleWorld);

		Model_RifleGun->Draw();
	}
	if (WeaponType == BAZOOKA)
	{
	
		CRenderer::SetWorldMatrix(&Shotworld);
		CRenderer::GetDeviceContext()->PSSetShaderResources(0, 1, &ShotGun_Texture);

		Model_Bazooka->Draw();
	}

}
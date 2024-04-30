#pragma once

#include "game_object.h"
enum
{
	SMALLGUN,
	SHOTGUN,
	RIFLEGUN,
	BAZOOKA
};
class CPlayer : public CGameObject
{
private:
	static class CModel* Model_SmallGun;
	static class CModel* Model_ShotGun;
	static class CModel* Model_RifleGun;
	static class CModel* Model_Bazooka;
	D3DXMATRIX mtxRotation;
	float ShotAngle = 0.0f;
	static ID3D11ShaderResourceView* SmallGun_Texture;
	static ID3D11ShaderResourceView* ShotGun_Texture;
	static ID3D11ShaderResourceView* RifleGun_Texture;
	D3DXMATRIX EviewMatrix;

	static int SmallGun_Bullet_Number;
	static int ShotGun_Bullet_Number;
	static int RifleGun_Bullet_Number;
	static int Bazooka_Bullet_Number;

	static int SmallGun_Max_Bullet_Number;
	static int ShotGun_Max_Bullet_Number;
	static int RifleGun_Max_Bullet_Number;
	static int Bazooka_Max_Bullet_Number;

	bool ShotGun_Reroad=false;
	bool Reroad_Start=false;
	int Reroad_Time=0;
	static int Player_Hp;
	int WeaponType=0;
	bool WeaponChange=false;
	bool Item_Key=false;
	
	bool Angle_Start=false;

	static bool HaveSmallGun;
	static bool HaveShotGun;
	static bool HaveRifleGun;
	static bool HaveBazooka;

	float WallFloat=0.0f;

public:
	CPlayer() {}
	~CPlayer() {}
	void Init();
	void Uninit();
	void Update();
	void Draw();
	void Transparent();
	static void Load();
	static void Unload();
	static void ResetPlayer(int index)
	{
		if (index == 4)
		{
			SmallGun_Bullet_Number = 20;
			ShotGun_Bullet_Number = 10;

			SmallGun_Max_Bullet_Number = 30;	
			ShotGun_Max_Bullet_Number = 20;
			HaveShotGun = false;


			Player_Hp = 100;
		}
		else if (index == 3)
		{
			HaveSmallGun = false;
			HaveShotGun = false;
			HaveRifleGun = false;
			HaveBazooka = false;

			SmallGun_Bullet_Number = 20;
			ShotGun_Bullet_Number = 10;
			RifleGun_Bullet_Number = 30;
			Bazooka_Bullet_Number = 5;

			SmallGun_Max_Bullet_Number = 30;
			ShotGun_Max_Bullet_Number = 20;
			RifleGun_Max_Bullet_Number = 90;
			Bazooka_Max_Bullet_Number = 10;

			Player_Hp = 100;
		}
		else if (index == 5)
		{
			SmallGun_Bullet_Number = 20;
			ShotGun_Bullet_Number = 10;
			RifleGun_Bullet_Number = 30;

			SmallGun_Max_Bullet_Number = 30;
			ShotGun_Max_Bullet_Number = 20;
			RifleGun_Max_Bullet_Number = 90;

			HaveRifleGun = false;


			Player_Hp = 100;
		}
		else if (index == 6)
		{
			SmallGun_Bullet_Number = 20;
			ShotGun_Bullet_Number = 10;
			RifleGun_Bullet_Number = 30;
			Bazooka_Bullet_Number = 5;

			SmallGun_Max_Bullet_Number = 30;
			ShotGun_Max_Bullet_Number = 20;
			RifleGun_Max_Bullet_Number = 90;
			Bazooka_Max_Bullet_Number = 10;

			HaveBazooka = false;



			Player_Hp = 100;
		}
	}

	void SetWallFloat(float index) { WallFloat = index; }
	void GetSmallGun() { HaveSmallGun = true; }
	bool SetSmallGun() { return HaveSmallGun; }
	void GetShotGun() { HaveShotGun = true; }
	bool SetShotGun() { return HaveShotGun; }
	void GetRifleGun() { HaveRifleGun = true; }
	bool SetRifleGun() { return HaveRifleGun; }
	void GetBazooka() { HaveBazooka = true; }
	bool SetBazooka() { return HaveBazooka; }
	void SetAngle() { Angle_Start = true; }

	void SetKey() {Item_Key = true; }
	bool GetKey() {return Item_Key; }
	void DeleteKey() { Item_Key = false; }

	void ChangeWeapon(int Type) { WeaponType = Type; }
	bool GetWeaponChange() { return WeaponChange; }
	void SetWeaponChange() { WeaponChange = true; }
	int GetWeaponType() { return WeaponType; }
	int GetPlayerHp() { return Player_Hp; }
	void SetPlayerHp(int index) { Player_Hp = index; }
	int GetMaxBulletNumber(int Type) 
	{ 
		if (Type == SMALLGUN)
		{
			return SmallGun_Max_Bullet_Number;
		}
		else if (Type == SHOTGUN)
		{
			return ShotGun_Max_Bullet_Number;
		}
		else if (Type == RIFLEGUN)
		{
			return RifleGun_Max_Bullet_Number;
		}
		else if (Type == BAZOOKA)
		{
			return Bazooka_Max_Bullet_Number;
		}
		else
		{
			return false;
		}
	}
	int GetBulletNumber(int Type)
	{ 
		if (Type == SMALLGUN)
		{
			return SmallGun_Bullet_Number;
		}
		else if (Type == SHOTGUN)
		{
			return ShotGun_Bullet_Number;
		}
		else if (Type == RIFLEGUN)
		{
			return RifleGun_Bullet_Number;
		}
		else if (Type == BAZOOKA)
		{
			return Bazooka_Bullet_Number;
		}
		else
		{
			return false;
		}
	}
	void MinusBulletNumber(int Type) 
	{ 
		if (Type == SMALLGUN)
		{
			SmallGun_Bullet_Number--;
		}
		if (Type == SHOTGUN)
		{
			ShotGun_Bullet_Number--;
		}
		if (Type == RIFLEGUN)
		{
			RifleGun_Bullet_Number--;
		}
		if (Type == BAZOOKA)
		{
			Bazooka_Bullet_Number--;
		}
	}
	void Begin_Reroad() { Reroad_Start = true; }
	bool GetReroad() { return Reroad_Start; }
	void GetHp() { Player_Hp += 10; }
	void MinusHP(int index = 10) { Player_Hp -= index; }
	void GetBullet()
	{
		if (SmallGun_Max_Bullet_Number < 300)
		{
			SmallGun_Max_Bullet_Number += 10;
		}
		if (HaveShotGun && ShotGun_Max_Bullet_Number < 100)
		{
			ShotGun_Max_Bullet_Number += 5;
		}
		if (HaveRifleGun && RifleGun_Max_Bullet_Number < 500)
		{
			RifleGun_Max_Bullet_Number += 15;
		}
		if (HaveBazooka && Bazooka_Max_Bullet_Number < 15)
		{
			Bazooka_Max_Bullet_Number += 3;
		}
	}
};
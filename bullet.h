#pragma once
#include "game_object.h"
enum
{
	SMALLGUN_BULLET,
	SHOTGUN_BULLET,
	SHOTGUN_BULLET2,
	SHOTGUN_BULLET3,
	SHOTGUN_BULLET4,
	RIFLEGUN_BULLET,
	BAZOOKA_BULLET
};
class CBullet : public CGameObject
{
private:
	class CBox* g_Box;
	static class CModel* Bazooka_Model;
	D3DXVECTOR3 SmallGunBullet_Front  = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	D3DXVECTOR3 ShotGunBullet_Front[4] = {  D3DXVECTOR3(0.0f,0.0f,0.0f) };
	D3DXVECTOR3 RifleGunBullet_Front = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	D3DXVECTOR3 BazookaBullet_Front = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	D3DXMATRIX view;
	D3DXMATRIX invView;
	D3DXMATRIX EviewMatrix;
	static ID3D11ShaderResourceView* Bazooka_Texture;
	int Count = 0;
	D3DXMATRIX world,boxworld;
	bool Effect[2] = { false };
	int BulletCount = 0;
public:
	CBullet() {}
	~CBullet() {}  
	void Init();
	void Uninit(); 
	void Update();
	void Draw();  
	void Transparent();
	static void Load();
	static void Unload();
	void SetEffect(int index) { Effect[index] = true; }
};
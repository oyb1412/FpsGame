#pragma once
#include "game_object.h"
enum
{
	ENEMY_BULLET,
	BOSS_BULLET,
	BOOM
};
#define ENEMY_BULLET_X 2
#define ENEMY_BULLET_Y 3

#define BOSS_BULLET_X 2
#define BOSS_BULLET_Y 2

class CEbullet : public CGameObject
{
private:
	class CBox* g_Box;
	static class CModel* EnemyBullet_Model;
	static class CModel* Boom_Model;

	static ID3D11ShaderResourceView* EnemyBullet_Texture;
	static ID3D11ShaderResourceView* BossBullet_Texture;
	static ID3D11ShaderResourceView* Boom_Texture;

	D3DXMATRIX view;
	D3DXMATRIX invView;
	D3DXMATRIX EviewMatrix;
	D3DXVECTOR3 Boom_Position = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	int Count=0;
	int m_Count=0;
	int m_sCount=0;
	int m_Length=0;
	int m_Height=0;
	D3DXVECTOR3 Bullet_Front = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	D3DXMATRIX world,boxworld;
	int Life = 0;
	bool BoomType = false;
public:
	CEbullet() {}
	~CEbullet() {}
	void Init();
	void Uninit();
	void Update();
	void Draw();
	void Transparent();

	bool GetLife() { return Life; }


	static void Load();
	static void Unload();

	D3DXVECTOR3 GetBulletFront() { return Bullet_Front; }

	void SetPosition_Scale_Vec(int type,int length,int height,D3DXVECTOR3 Position, D3DXVECTOR3 Scale,D3DXVECTOR3 Vec) {Type = type,m_Length = length,m_Height = height, m_Position = Position, m_Scale = Scale,Bullet_Front = Vec; }
	void SetPosition_Boom(int type, int length, int height, D3DXVECTOR3 Position, D3DXVECTOR3 Scale, D3DXVECTOR3 Vec,D3DXVECTOR3 boomposition) { Type = type, m_Length = length, m_Height = height, m_Position = Position, m_Scale = Scale, Bullet_Front = Vec,Boom_Position = boomposition;}

};
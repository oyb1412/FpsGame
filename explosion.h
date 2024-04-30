#pragma once
#include "game_object.h"
enum
{
	GUN_SHOT_EFFECT,
	SHOTGUN_SHOT_EFFECT,
	RIFLEGUN_SHOT_EFFECT,
	GUN_HIT,
	SHOTGUN_HIT,
	HEADSHOT_HIT,
	BOSS_DOOR,
	CREATE_EFFECT,
	ENEMY_DISTROY,
	SUMMON_SHORT,
	SUMMON_LONG,
	BOOM_EFFECT,
};
#define ENEMY_DESTROY_EFFECT_X 2
#define ENEMY_DESTROY_EFFECT_Y 6

#define GUN_SHOT_EFFECT_X 2
#define GUN_SHOT_EFFECT_Y 7

#define BOSS_DOOR_EFFECT_X 2
#define BOSS_DOOR_EFFECT_Y 3

#define CREATE_EFFECT_X 2
#define CREATE_EFFECT_Y 9

#define ENEMY_DISTROY_X 5
#define ENEMY_DISTROY_Y 3

#define BOOM_EFFECT_X 5
#define BOOM_EFFECT_Y 5

#define HEADSHOT_EFFECT_X 2
#define HEADSHOT_EFFECT_Y 4

#define SHOT_EFFECT_X 2
#define SHOT_EFFECT_Y 5
class CExplosion : public CGameObject
{
private:
	ID3D11Buffer* m_VertexBuffer = NULL;

	static ID3D11ShaderResourceView* Gun_Effect_Texture;

	static ID3D11ShaderResourceView* Gun_Hit_Texture;
	static ID3D11ShaderResourceView* ShotGun_Hit_Texture;
	static ID3D11ShaderResourceView* HeadShot_Hit_Texture;

	static ID3D11ShaderResourceView* Boss_Door_Texture;
	static ID3D11ShaderResourceView* Create_Effect_Texture;
	static ID3D11ShaderResourceView* Enemy_Distroy_Texture;
	static ID3D11ShaderResourceView* Boom_Effect_Texture;

	int m_Count=0;
	int s_Count=0;
	int m_Length=0;
	int m_Height=0;

public:
	CExplosion() {}
	~CExplosion() {}
	void Init();
	void Uninit();
	void Update();
	void Draw();
	void Transparent();

	void SetTexture(int TexID,int Length, int Height,D3DXVECTOR3 Position,D3DXVECTOR3 Scale) { Type = TexID,m_Length = Length, m_Height = Height,m_Position = Position,m_Scale = Scale;}
	 
	static void Load();
	static void Unload();

	
};
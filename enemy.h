#pragma once
#include "game_object.h"
#define WOLF_SPEED 0.15f
#define AIR_SPEED 0.1f

#define BOSS_SPEED 0.4f

enum
{
	TYPE_GOLEM,
	TYPE_WOLF,
	TYPE_AIRPLANE,

	TYPE_BOSS,
	TYPE_ITEM_BULLET,
	TYPE_ITEM_HEART,
	TYPE_ITEM_KEY,
	TYPE_HEAD,
	TYPE_BODY,
	TYPE_TREE,
	TYPE_TANK
};
class CEnemy : public CGameObject
{
private:
	class CBox* m_Body;
	class CBox* m_Head;
	D3DXMATRIX EviewMatrix;

	static class CModel* Golem_Model;
	static class CModel* Wolf_Model;
	static class CModel* Boss_Model;
	static class CModel* Airplane_Model;
	static class CModel* Tank_Model;


	static ID3D11ShaderResourceView* Golem_Texture;
	static ID3D11ShaderResourceView* Wolf_Texture;
	static ID3D11ShaderResourceView* Boss_Texture;
	static ID3D11ShaderResourceView* Tree_Texture;
	static ID3D11ShaderResourceView* Tank_Texture;
	D3DXMATRIX headworld, headscale, headtrans, golemheadworld, golemheadscale, golemheadtrans;
	D3DXMATRIX tankboxworld, tankboxscale, tankboxtrans, tankheadworld, tankheadscale, tankheadtrans;
	D3DXMATRIX airboxworld, airboxscale, airboxtrans, airheadboxworld, airheadboxscale, airheadboxtrans;
	D3DXMATRIX world, scale, rot, trans, golemboxworld, golemboxscale, wolfboxworld, wolfboxtrans, wolfboxscale, destroyrot, trans1, trans2, bossworld;
	D3DXMATRIX invView;
	D3DXMATRIX view;
	D3DXVECTOR3 EnemyRightVec = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	int Hp=0;
	bool StopEnemy=false;
	int StopCount=0;
	int AttackCount=0;
	bool StartFade=false;
	float EnemyFade=0.0f;
	int EnemyFadeCount=0;
	int Count=0;
	D3DXVECTOR3 Stop_FrontVec = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	D3DXVECTOR3 Stop_RightVec = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	D3DXVECTOR3 Stop_LeftVec = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

	D3DXVECTOR3 Stop_PlayerPosition = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	D3DXVECTOR3 Target_Position = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	
	int Create_Count=0;
	int Tank_Random=0;
	bool Tank_Pattern[5] = { false };
	bool Ult_Count=false;
	D3DXVECTOR3 Enemy_Player_Vec = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	int Attack_Count=0;
	float DestroyAngle=0.0f;
	bool SelectAngle=false;
	bool StartBilboard=false;
	bool AttackTurm=false;
	int PartType=0;
	bool Underattack=false;
	bool SoundAttack=false;
	bool LetBoss=false;
	bool BackMove=false;
	int BackMoveCount=0;
	D3DXVECTOR3 Body_Min = D3DXVECTOR3(0.0f, 0.0f, 0.0f), Body_Max = D3DXVECTOR3(0.0f, 0.0f, 0.0f), Head_Min = D3DXVECTOR3(0.0f, 0.0f, 0.0f), Head_Max = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
public:
	CEnemy() {}
	~CEnemy() {}
	void Init();
	void Uninit();
	void Update();
	void Draw();
	void Transparent();

	static void Load();
	static void Unload();
	D3DXVECTOR3 EnemyPlayerVec() { return Enemy_Player_Vec; }
	int GetAttackCount() { return Tank_Random; }
	D3DXVECTOR3 EnemyMin(int Type)
	{
		if (Type == TYPE_BODY)
		{
			return Body_Min;
		}
		else if (Type == TYPE_HEAD)
		{
			return Head_Min;
		}
		else
		{
			return D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		}
	}
	D3DXVECTOR3 EnemyMax(int Type)
	{
		if (Type == TYPE_BODY)
		{
			return Body_Max;

		}
		else if (Type == TYPE_HEAD)
		{
			return Head_Max;
		}
		else
		{
			return D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		}
	}

	bool GetEnemyLife() { return StartFade; }
	void MinusHp(int index) { Hp-=index; }
	
	int GetHp() { return Hp; }

	void StopBegin() { StopEnemy = true; }

	void SetTexture(int Texid,D3DXVECTOR3 Position, D3DXVECTOR3 Scale,int hp) { Type = Texid,m_Position = Position, m_Scale = Scale, Hp = hp; }

	void SetUnderattack() { Underattack = true; }

	void SetStopRight() 
	{ 
		
		if (Type == TYPE_WOLF)
		{
			m_Position.x -= WOLF_SPEED;
		}
		else if (Type == TYPE_TANK)
		{
			m_Position.x -= BOSS_SPEED;
		}
		else if (Type == TYPE_AIRPLANE)
		{
			m_Position.x -= WOLF_SPEED;
		}
	}
	void SetStopLeft()
	{
	
		if (Type == TYPE_WOLF)
		{
			m_Position.x += WOLF_SPEED;
		}
		else if (Type == TYPE_TANK)
		{
			m_Position.x += BOSS_SPEED;
		}
		else if (Type == TYPE_AIRPLANE)
		{
			m_Position.x += WOLF_SPEED;
		}
	}	
	void SetStopFront()
	{
		
		if (Type == TYPE_WOLF)
		{
			m_Position.z -= WOLF_SPEED;
		}
		else if (Type == TYPE_TANK)
		{
			m_Position.z -= BOSS_SPEED;
		}
		else if (Type == TYPE_AIRPLANE)
		{
			m_Position.z -= WOLF_SPEED;
		}
	}	
	void SetStopBehind()
	{
		
		if (Type == TYPE_WOLF)
		{
			m_Position.z += WOLF_SPEED;
		}
		else if (Type == TYPE_TANK)
		{
			m_Position.z += BOSS_SPEED;
		}
		else if (Type == TYPE_AIRPLANE)
		{
			m_Position.z += WOLF_SPEED;
		}
	}


};
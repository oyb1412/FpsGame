#pragma once
#include "game_object.h"
#define PLAYER_SPEED 0.4f

enum
{
	TYPE_NORMAL,
	TYPE_SETTING
};
class CCamera : public CGameObject
{
private:

	

	class CBox* g_Box;

	D3DXVECTOR3 m_Target = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	D3DXVECTOR3 m_Front = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	D3DXVECTOR3 g_vecFront= D3DXVECTOR3(0.0f,0.0f,0.0f);
	D3DXVECTOR3 g_vecRight= D3DXVECTOR3(0.0f,0.0f,0.0f);
	D3DXVECTOR3 g_vecUp = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	D3DXVECTOR3 vecDir = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	D3DXMATRIX viewMatrix;
	int StepCount = 0;
	bool SmallGun_Shot = false;
	bool ShotGun_Shot = false;
	bool RifleGun_Shot= false;
	bool Bazooka_Shot = false;
	bool CantRightMove = false;
	bool CantLeftMove = false;
	bool CantFrontMove = false;
	bool CantBackMove = false;
	
	int SmallGunShot_Turm = 0;
	int ShotGunShot_Turm = 0;
	int RifleGunShot_Turm = 0;
	int BazookaShot_Turm = 0;


	bool StopRightMove = false;
	bool StopLeftMove = false;
	bool StopFrontMove = false;
	bool StopBehindMove = false;

	bool BeginTeleport = false;

	
	bool BackPosition = false;
	int BackMoveCount = 0;


	bool StartJump = false;
	bool JumpDown = false;

	int JumpCount = 0;
	bool BossStart = false;
	float Gravity = 0.0f;
	int JumpCounting = 0;

public:
	CCamera() {}
	~CCamera() {}
	void Init();
	void Uninit();
	void Update();
	void Draw();
	void Transparent();
	void SetStopRight(bool param) { CantRightMove = param; }
	void SetStopLeft(bool param) { CantLeftMove = param; }
	void SetStopFront(bool param) { CantFrontMove = param; }
	void SetStopBack(bool param) { CantBackMove = param; }
	int GetSmallGunShotTurm() { return SmallGunShot_Turm; }
	int GetShotGunShotTurm() { return ShotGunShot_Turm; }
	int GetRifleGunShotTurm() { return RifleGunShot_Turm; }
	void BeginBoss() { BossStart = true; }
	void StartBoss() { BossStart = false; }
	void RailMove(D3DXVECTOR3 index) { m_Position += index; }
	void SetGravityPower() { m_Position.y += 0.1f; }
	void PlusPositionX(float index) { m_Position.x += index; }
	void PlusPositionZ(float index) { m_Position.z += index; }

	void SetJump() { StartJump = true; }

	bool GetSmallGunShot() 
	{ 
		return SmallGun_Shot;
	}
	bool GetShotGunShot()
	{
		return ShotGun_Shot;
	}
	bool GetRifleGunShot()
	{
		return RifleGun_Shot;
	}
	bool GetBazookaShot()
	{
		return Bazooka_Shot;
	}
	D3DXVECTOR3 GetFrontVec() { return g_vecFront; }
	D3DXVECTOR3 GetRightVec() { return g_vecRight; }
	D3DXMATRIX GetViewMatrix() { return viewMatrix; }


	void SetPosition(D3DXVECTOR3 index) { m_Position = index; }
	void BackMove() 
	{ 
		BackPosition = true; 
	}
	void SetTeleport() { BeginTeleport = true; }
	bool GetTeleport() { return BeginTeleport; }
	void FreeDoor() { StopFrontMove = false; }

	void StopWallLeft() { m_Position.x += PLAYER_SPEED, m_Target.x += PLAYER_SPEED; }

	void StopWallRight() { m_Position.x -= PLAYER_SPEED, m_Target.x -= PLAYER_SPEED; }

	void StopWallFront() { m_Position.z -= PLAYER_SPEED; }
	void StopWallBehind() { m_Position.z += PLAYER_SPEED; }

	void StopDoor() { StopFrontMove = true; }
	void StopBDoor() { StopBehindMove = true; }

	void SetCamera(D3DXVECTOR3 position, D3DXVECTOR3 scale,int type) { m_Position = position, m_Scale = scale,Type = type; }
};
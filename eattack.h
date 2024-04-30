#pragma once
#include "game_object.h"
enum
{
	ATTACK_BOOM,
	ATTACK_CLAW
};

class CEattack : public CGameObject
{
private:
	class CBox* g_Box;
	D3DXMATRIX world;
	int m_Count= 0;
	int m_sCount = 0;
public:
	CEattack() {}
	~CEattack() {}
	void Init();
	void Uninit();
	void Update();
	void Draw();
	void Transparent();






};
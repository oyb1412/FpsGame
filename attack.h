#pragma once
#include "game_object.h"

class CAttack : public CGameObject
{
private:
	class CBox* g_Box;
	D3DXMATRIX world;
	int m_Count = 0;
	int m_sCount = 0;
public:
	CAttack() {}
	~CAttack() {}
	void Init();
	void Uninit();
	void Update();
	void Draw();
	void Transparent();






};
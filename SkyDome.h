#pragma once
#include "game_object.h"
class CSkyDome : public CGameObject
{
private:
	class CModel* m_Sky;



public:
	CSkyDome() {}
	~CSkyDome() {}
	void Init();
	void Uninit();
	void Update();
	void Draw();
	void Transparent() {};
};
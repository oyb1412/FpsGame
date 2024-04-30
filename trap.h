#pragma once
#include "game_object.h"
enum
{
	X_TRAP,
	Z_TRAP,
	SPIKE,
	SKULL
};
#define SKULL_MOVE 0.5f
class CTrap : public CGameObject
{
private:
	static class CModel* Model_Shuriken;
	static class CModel* Model_Spike;
	static class CModel* Model_Skull;

	class CBox* m_Box;
	static ID3D11ShaderResourceView* Shuriken_Texture;
	static ID3D11ShaderResourceView* Skull_Texture;

	bool Trap_Move_X=false;
	bool Trap_Move_Z=false;
	bool SkullUp=false;
	float SkullMove=0.0f;
	D3DXMATRIX xboxworld, zboxworld,spikeboxworld,skullboxworld;

public:
	CTrap() {}
	~CTrap() {}
	void Init();
	void Uninit();
	void Update();
	void Draw();
	void Transparent();

	static void Load();
	static void Unload();
	float GetSkullMove() { return SkullMove; }
	void SetXTrapPlusMove() { Trap_Move_X = true; }
	void SetXTrapMinusMove() { Trap_Move_X = false; }

	void SetZTrapPlusMove() { Trap_Move_Z = true; }
	void SetZTrapMinusMove() { Trap_Move_Z = false; }
};
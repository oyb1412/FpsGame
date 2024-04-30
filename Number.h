#pragma once
#include "game_object.h"
enum
{
	BULLET_NUMBER,
	MAX_BULLET_NUMBER,
	HP_NUMBER,
	ENEMY_NUMBER,

};
class CNumber : public CGameObject
{
private:

	
	static ID3D11ShaderResourceView* Black_Number_Texture;
	static ID3D11ShaderResourceView* Red_Number_Texture;
	ID3D11Buffer* m_VertexBuffer = NULL;

	int m_Count =0;
	int Second_Count=0;
	int Max_Number=0;
	
public:
	CNumber() {}
	~CNumber() {}
	void Init();
	void Uninit();
	void Update();
	void Draw();
	void Transparent();

	
	void SetTexture(int TexID, int MaxNumber,D3DXVECTOR3 Position, D3DXVECTOR3 Scale) { Type = TexID, Max_Number = MaxNumber, m_Position = Position, m_Scale = Scale; }
	static void Load();
	static void Unload();

};
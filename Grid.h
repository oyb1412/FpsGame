#pragma once
#include "game_object.h"
class CGrid : public CGameObject
{
private:

	float m_Normal;
	ID3D11ShaderResourceView* Field_Texture = NULL;
	ID3D11Buffer* m_VertexBuffer = NULL;

public:
	CGrid() {}
	~CGrid() {}
	void Init();
	void Uninit();
	void Update();
	void Draw();
	void Transparent();


};
#pragma once
#include "game_object.h"


class CSkybox : public CGameObject
{
private:

	VERTEX_3D vertex[36] = { D3DXVECTOR3(0.0f, 0.0f, 0.0f) };
	;	ID3D11Buffer* m_VertexBuffer = NULL;

	ID3D11ShaderResourceView* Sky_Texture;
	ID3D11ShaderResourceView* Factory_Texture;

public:
	CSkybox() {}
	~CSkybox() {}
	void Init();
	void Uninit();
	void Update();
	void Draw();
	void Transparent();

	
};
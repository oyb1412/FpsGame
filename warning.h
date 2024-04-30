#pragma once
#include "game_object.h"

class CWarning : public CGameObject
{
private:

	static ID3D11ShaderResourceView* Warning_Texture;
	ID3D11Buffer* m_VertexBuffer = NULL;
	float Fade = 1.0f;
public:
	CWarning() {}
	~CWarning() {}
	void Init();
	void Uninit();
	void Update();
	void Draw();
	void Transparent();
	static void Load();
	static void Unload();
	

};
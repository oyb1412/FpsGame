#pragma once
#pragma once
#include "game_object.h"
class CItem : public CGameObject
{
private:
	bool Item_Shake = false;
	static ID3D11ShaderResourceView* Bullet;
	static ID3D11ShaderResourceView* Heart;
	static ID3D11ShaderResourceView* Key_Texture;
	ID3D11Buffer* m_VertexBuffer = NULL;

	

public:
	CItem() {}
	~CItem() {}
	void Init();
	void Uninit();
	void Update();
	void Draw();
	void Transparent();

	static void Load();
	static void Unload();

};
#pragma once
#include "game_object.h"
enum
{
	FADE_WHITE,
	FADE_BLACK,
	FADE_RED
};
class CFade : public CGameObject
{
private:
	ID3D11Buffer* m_VertexBuffer = NULL;

	static ID3D11ShaderResourceView* White_Texture;
	static ID3D11ShaderResourceView* Black_Texture;
	static ID3D11ShaderResourceView* Red_Texture;

	float Fade=0.0f;

	bool FadeOutType=false;
	bool FadeInType=false;

public:
	CFade() {}
	~CFade() {}
	void Init();
	void Uninit();
	void Update();
	void Draw();
	void Transparent();


	static void Load();
	static void Unload();

	void CaeateFade() { Fade = 0.99f, Type = FADE_BLACK, m_Position = D3DXVECTOR3(0.0f, 0.0f, 0.0f), m_Scale = D3DXVECTOR3(50.0f, 50.0f, 0.0f); }
	void SetFadeOut() 
	{ 
		if (!FadeOutType)
		{
			FadeOutType = true;
		}
	}
	
	void SetFadeIn() { FadeInType = true; }

	float GetFade() { return Fade; }
};
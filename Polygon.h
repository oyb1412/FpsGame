#pragma once
#include "game_object.h"
enum
{
	AIM_TEXTURE,
	GAGE_GREEN_TEXTURE,
	GAGE_GRAY_TEXTURE,
	SMALLGUN_UI_TEXTURE,
	SHOTGUN_UI_TEXTURE,
	RIPLEGUN_UI_TEXTURE,
	BAZOOKA_UI_TEXTURE,

	CURSOR_TEXTURE,
	TELEPORT_TEXTURE,
	GATE_TEXTURE,
	KEY_TEXTURE,
	SHOTGUN_IMPOSSIBLE_TEXTURE,
	RIFLEGUN_IMPOSSIBLE_TEXTURE,
	STAGE1CLEAR_LOGO_TEXTURE,
	STAGE2CLEAR_LOGO_TEXTURE,

	TITLE_LOGO1_TEXTURE,
	TITLE_LOGO2_TEXTURE,
	TITLE_LOGO3_TEXTURE,
	TITLE_NAME_TEXTURE,
	ARROW_TEXTURE,
	ENEMY_ATTACK_TEXTURE,
	HPGAGE_GRAY_TEXTURE,
	HPGAGE_RED_TEXTURE,
	TUTORIAL_LOGO1_TEXTURE,
	TUTORIAL_LOGO2_TEXTURE,
	TUTORIAL_LOGO3_TEXTURE,
	TUTORIAL_LOGO4_TEXTURE,
	TUTORIAL_LOGO5_TEXTURE,
	TUTORIAL_SPACE,
	BG_TEXTURE,
	CLEAR_LOGO1_TEXTURE,
	CLEAR_LOGO2_TEXTURE,
	CLEAR_BG_TEXTURE,
	PAUSE_TEXTURE,
	PAUSE2_TEXTURE

};
class CPolygon : public CGameObject
{
private:
	ID3D11Buffer* m_VertexBuffer = NULL;

	static ID3D11ShaderResourceView* Aim_Texture;
	static ID3D11ShaderResourceView* HPGage_Gray_Texture;
	static ID3D11ShaderResourceView* HPGage_Red_Texture;
	static ID3D11ShaderResourceView* GrayGage_Texture ;
	static ID3D11ShaderResourceView* GreenGage_Texture ;
	static ID3D11ShaderResourceView* GunUi_Texture ;
	static ID3D11ShaderResourceView* ShotGunUi_Texture;
	static ID3D11ShaderResourceView* RifleGunUi_Texture;
	static ID3D11ShaderResourceView* BazookaUi_Texture;

	static ID3D11ShaderResourceView* Cursor_Texture;
	static ID3D11ShaderResourceView* TeleportLogo_Texture;
	static ID3D11ShaderResourceView* GateLogo_Texture;
	static ID3D11ShaderResourceView* Stage1Clear_Logo_Texture;
	static ID3D11ShaderResourceView* Stage2Clear_Logo_Texture;
	static ID3D11ShaderResourceView* Title_Logo1_Texture;
	static ID3D11ShaderResourceView* Title_Logo2_Texture;
	static ID3D11ShaderResourceView* Title_Logo3_Texture;
	static ID3D11ShaderResourceView* Title_Name_Texture;

	static ID3D11ShaderResourceView* Arrow_Texture;
	static ID3D11ShaderResourceView* Enemy_Attack_Texture ;
	static ID3D11ShaderResourceView* Tutorial_Logo1_Texture;
	static ID3D11ShaderResourceView* Tutorial_Logo2_Texture;
	static ID3D11ShaderResourceView* Tutorial_Logo3_Texture;
	static ID3D11ShaderResourceView* Tutorial_Logo4_Texture;
	static ID3D11ShaderResourceView* Tutorial_Logo5_Texture;
	static ID3D11ShaderResourceView* Tutorial_Space_Texture;
	static ID3D11ShaderResourceView* Bg_Texture;
	static ID3D11ShaderResourceView* Clear_Logo1_Texture;
	static ID3D11ShaderResourceView* Clear_Logo2_Texture;
	static ID3D11ShaderResourceView* Clear_Bg_Texture;
	static ID3D11ShaderResourceView* Pause_Texture;
	static ID3D11ShaderResourceView* Pause2_Texture;

	float nagasa=0.0f;

	bool CursorMove[3] = { false };
	bool CursorMoveBegin=false;
	D3DXMATRIX world;
	float GageUV=0.0f;
	D3DXVECTOR3 GageScale = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	D3DXVECTOR3 GageTrans = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	class C2DBox* Box;
	D3DXVECTOR3 m_min = D3DXVECTOR3(0.0f, 0.0f, 0.0f), m_max = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	POINT position;
	float Fade=0.0f;
	int Count=0;
	bool FadeCount = false;
public:
	CPolygon() {}
	~CPolygon() {}
	void Init();
	void Uninit();
	void Update();
	void Draw();
	void Transparent();

	static void Load();
	static void Unload();

	bool GetCursor(int Number) { return CursorMove[Number]; }
	void SetCursor(int Number) { CursorMove[Number] = true; }
	void SetArrow(D3DXVECTOR3 position) { m_Position = position; }
	D3DXVECTOR3 getmin() { return m_min; }
	D3DXVECTOR3 getmax() { return m_max; }
	
};
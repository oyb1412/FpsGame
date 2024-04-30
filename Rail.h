#pragma once
enum
{
	RIGHTRAIL,
	LEFTRAIL,
	DOWNRAIL
};
class CRail : public CGameObject
{
private:
	class CBox* m_Box;
	ID3D11Buffer* m_VertexBuffer = NULL;

	static ID3D11ShaderResourceView* RightRail_Texture;
	static ID3D11ShaderResourceView* LeftRail_Texture;
	static ID3D11ShaderResourceView* DownRail_Texture;

	static class CModel* Soil_Model;


	float UVY=0.0f;
	float LeftX=0.0f, RightX=0.0f;
	D3DXMATRIX world,boxworld,boxtrans;
public:
	CRail() {}
	~CRail() {}
	void Init();
	void Uninit();
	void Update();
	void Draw();
	void Transparent();


	static void Load();
	static void Unload();


};
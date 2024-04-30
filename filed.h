#pragma once
#include "game_object.h"
enum
{
	FIELD,
	CEILING,
	BRIDGE,
	SMALLBRIDGE,
	SCAFFOLD,
	FLOOR
	

};
class CField : public CGameObject 
{
private:
	class CBox* m_Box;
	static class CModel* Bridge_Model;
	static class CModel* Soil_Model;
	int RailCount=0;
	float m_Normal=0.0f;
	int ModelType=0;
	bool BridgeMove=false;
	float BridgeMoveCount=0.0f;
	int RandomFade=0;
	float Fade=0.0f;
	float FadeCount=0.0f;
	bool FadeType=false;
	D3DXVECTOR3 SavePosition = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	D3DXMATRIX boxworld;
	static ID3D11ShaderResourceView* Field_Texture;
	static ID3D11ShaderResourceView* Ceiling_Texture;
	static ID3D11ShaderResourceView* Bridge_Texture;
	static ID3D11ShaderResourceView* SmallBridge_Texture ;
	static ID3D11ShaderResourceView* Grass_Texture;
	static ID3D11ShaderResourceView* Scaffold_Texture;
	static ID3D11ShaderResourceView* FactoryField_Texture;
	static ID3D11ShaderResourceView* FactoryFloor_Texture;
	static ID3D11ShaderResourceView* Brick_Texture;

	ID3D11Buffer* m_VertexBuffer = NULL;

public:
	CField() {}
	~CField() {}
	void Init();
	void Uninit();
	void Update();
	void Draw();
	void Transparent();
	static void Load();
	static void Unload();
	float GetBridgeMove() { return BridgeMoveCount; }

	void SetField(D3DXVECTOR3 Position, D3DXVECTOR3 Scale, D3DXVECTOR3 Rotation, float Normal, int type = 0,int modeltype = 0,float fade = 0.0f) {
		m_Position = Position, m_Scale = Scale, m_Rotation = Rotation, m_Normal = Normal;
		//if (type == CEILING)
		{
			Type = type;
		}
		ModelType = modeltype;
		Fade = fade;
	
		 }

};
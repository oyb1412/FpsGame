#pragma once
#include "game_object.h"

#define UV_X 5

enum
{
	RIGHT_WALL,
	LEFT_WALL,
	FRONT_WALL,
	BEHIND_WALL,
	PILLAR,
	GRASS,
	ROCK,
	TRANSPARENCY,
	BRICKWALL,
	
};
class CWall : public CGameObject
{
private:
	class CBox* g_Box;
	static class CModel* Grass_Model;
	static class CModel* Grass1_Model;
	static class CModel* Rock_Model;

	VERTEX_3D vertex[36] = {  D3DXVECTOR3(0.0f, 0.0f, 0.0f) };
	;ID3D11Buffer* m_VertexBuffer = NULL;

	static ID3D11ShaderResourceView* Wall_Texture;
	static ID3D11ShaderResourceView* Pillar_Texture;
	static ID3D11ShaderResourceView* Grass_Texture;
	static ID3D11ShaderResourceView* Rock_Texture;
	static ID3D11ShaderResourceView* Factory_Texture;
	static ID3D11ShaderResourceView* BrickWall_Texture;


	D3DXMATRIX world;
	D3DXVECTOR3 Wall_Position = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	int Texture_Type=0;
	int ModelType = 0;
public:
	CWall() {}
	~CWall() {}
	void Init();
	void Uninit();
	void Update();
	void Draw();
	void Transparent();

	static void Load();
	static void Unload();
	void SetBrickWall(int type, D3DXVECTOR3 Position, D3DXVECTOR3 Scale, int textype = 0, int modeltype = 0)
	{
		Type = type;
		ModelType = modeltype;
		if (textype > 0)
		{
			Texture_Type = textype;
		}
		if (type == RIGHT_WALL)
		{

			Wall_Position.y = Position.y;
			Wall_Position.x = Position.x;
			Wall_Position.z = Position.z - 0.5f;

			m_Scale = Scale;
			m_Position.x = Wall_Position.x - 0.8f;
			m_Position.y = Wall_Position.y;
			m_Position.z = Wall_Position.z;
			m_Scale.z = Scale.z + 0.5f;
			if (textype == PILLAR)
			{
				m_Position.x = Wall_Position.x - 0.7f;
			}
		}
		if (type == LEFT_WALL)
		{

			Wall_Position.y = Position.y;
			Wall_Position.x = Position.x;
			Wall_Position.z = Position.z - 0.5f;
			m_Scale = Scale;
			m_Position.x = Wall_Position.x + 0.8f;
			m_Position.y = Wall_Position.y;
			m_Position.z = Wall_Position.z;
			m_Scale.z = Scale.z + 0.5f;

			if (textype == PILLAR)
			{
				m_Position.x = Wall_Position.x + 0.9f;
			}
		}
		if (type == FRONT_WALL)
		{
			Wall_Position.y = Position.y;
			Wall_Position.x = Position.x - 0.5f;
			Wall_Position.z = Position.z ;
			m_Scale = Scale;
			m_Position.x = Wall_Position.x;
			m_Position.y = Wall_Position.y;
			m_Position.z = Wall_Position.z - 0.8f;
			m_Scale.x = Scale.x + 2.0f;
			if (textype == PILLAR)
			{
				m_Position.z = Wall_Position.z - 0.7f;
			}
		}
		if (type == BEHIND_WALL)
		{

			Wall_Position.y = Position.y;
			Wall_Position.x = Position.x - 0.5f;
			Wall_Position.z = Position.z - 1.5f;

			m_Scale = Scale;
			m_Position.x = Wall_Position.x;
			m_Position.y = Wall_Position.y;
			m_Position.z = Wall_Position.z + 0.8f;
			m_Scale.x = Scale.x + 2.0f;
			if (textype == PILLAR)
			{
				m_Position.z = Wall_Position.z + 0.7f;
			}
		}
	}

	void SetWall(int type,D3DXVECTOR3 Position, D3DXVECTOR3 Scale,int textype = 0,int modeltype = 0)
	{ 
		Type = type;
		ModelType = modeltype;
		if (textype > 0)
		{
			Texture_Type = textype;
		}
		if (type == RIGHT_WALL)
		{
			

			Wall_Position = Position;
			m_Scale = Scale;
			m_Position.x = Wall_Position.x - 0.8f;
			m_Position.y = Wall_Position.y;
			m_Position.z = Wall_Position.z;
			if (textype == PILLAR)
			{
				m_Position.x = Wall_Position.x - 0.7f;
			}
		}
		if (type == LEFT_WALL)
		{
		
			Wall_Position = Position;
			m_Scale = Scale;
			m_Position.x = Wall_Position.x + 0.8f;
			m_Position.y = Wall_Position.y;
			m_Position.z = Wall_Position.z;
			if (textype == PILLAR)
			{
				m_Position.x = Wall_Position.x + 0.9f;
			}
		}
		if (type == FRONT_WALL)
		{
		
			Wall_Position = Position;
			m_Scale = Scale;
			m_Position.x = Wall_Position.x;
			m_Position.y = Wall_Position.y;
			m_Position.z = Wall_Position.z -0.8f;
			
			if (textype == PILLAR)
			{
				m_Position.z = Wall_Position.z - 0.7f;
			}
		}
		if (type == BEHIND_WALL)
		{
		
			Wall_Position = Position;
			m_Scale = Scale;
			m_Position.x = Wall_Position.x;
			m_Position.y = Wall_Position.y;
			m_Position.z = Wall_Position.z+0.8f;
			if (textype == PILLAR)
			{
				m_Position.z = Wall_Position.z + 0.7f;
			}
		}
	}

};
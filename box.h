#pragma once
#include "renderer.h"
class CBox 
{
protected:
	D3DXVECTOR3 m_Position = D3DXVECTOR3(0.0f,0.0f,0.0f);
	D3DXVECTOR3 m_Rotation = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	D3DXVECTOR3 m_Scale = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	VERTEX_3D vertex[36] = { D3DXVECTOR3(0.0f,0.0f,0.0f) };
	D3DXVECTOR3 Save_Min = D3DXVECTOR3(0.0f, 0.0f, 0.0f), Save_Max = D3DXVECTOR3(0.0f, 0.0f, 0.0f), Save_Min2 = D3DXVECTOR3(0.0f, 0.0f, 0.0f), Save_Max2 = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	ID3D11Buffer* m_VertexBuffer = NULL;

public:
	CBox() {} 
	~CBox() {}
	void Init();
	void Uninit();
	void Update(D3DXVECTOR3 Position, D3DXVECTOR3& Min, D3DXVECTOR3& Max);
	void Draw( D3DXMATRIX* World,int Type = 0);

	
	bool Destroy()
	{
		Uninit();
		delete this;
		return true;
	}


};
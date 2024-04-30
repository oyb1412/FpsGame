#pragma once
#include "renderer.h"
#include "box.h"
class C2DBox 
{
private:
	D3DXVECTOR2 m_Position = D3DXVECTOR2(0.0f,0.0f);
	D3DXVECTOR2 m_Rotation = D3DXVECTOR2(0.0f, 0.0f);
	D3DXVECTOR2 m_Scale = D3DXVECTOR2(0.0f, 0.0f);;
	VERTEX_3D vertex[4] = { D3DXVECTOR3(0.0f,0.0f,0.0f) };
	D3DXVECTOR3 Save_Min= D3DXVECTOR3(0.0f, 0.0f, 0.0f), Save_Max = D3DXVECTOR3(0.0f, 0.0f, 0.0f), Save_Min2 = D3DXVECTOR3(0.0f, 0.0f, 0.0f), Save_Max2 = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	ID3D11Buffer* m_VertexBuffer = NULL;
	ID3D11ShaderResourceView* Cursor_Texture = NULL;

public:
	C2DBox() {}
	~C2DBox() {}
	void Init();
	void Uninit();
	void Update(POINT Position, D3DXVECTOR3& Min, D3DXVECTOR3& Max);
	void Draw(D3DXMATRIX* World,int Type = 0);


	
	

	

};
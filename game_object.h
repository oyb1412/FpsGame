#pragma once

class CGameObject
{
protected:
	D3DXVECTOR3 m_Position = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	D3DXVECTOR3 m_Rotation = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	D3DXVECTOR3 m_Scale = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

	bool m_Destroy = false;
	D3DXVECTOR3 m_Min = D3DXVECTOR3(0.0f, 0.0f, 0.0f), m_Max = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	float m_Normal=0.0f;
	int m_Priority=0;
	int Type=0;
public:
	CGameObject() {}
	virtual ~CGameObject() {}
	virtual void Transparent() = 0;
	virtual void Init() = 0;
	virtual void Uninit() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;

	D3DXVECTOR3 GetPosition() { return m_Position; }
	D3DXVECTOR3 GetRotation() { return m_Rotation; }
	D3DXVECTOR3 GetScale() { return m_Scale; }

	D3DXVECTOR3 GetMin() { return m_Min; }
	D3DXVECTOR3 GetMax() { return m_Max; }
	int GetType() { return Type; }
	void SetObject(D3DXVECTOR3 Position, D3DXVECTOR3 Scale,int type = 0, D3DXVECTOR3 Rotation = D3DXVECTOR3(0.0f, 0.0f, 0.0f))
	{
		Type = type;
		m_Position = Position;
		m_Scale = Scale;
		m_Rotation = Rotation;
	}

	void SetDestroy() { m_Destroy = true; }

	bool Destroy()
	{
		if (m_Destroy)
		{
			Uninit();
			delete this;
			return true;
		}
		else
		{
			return false;
		}

	}

	static bool TdCheckBoxCollision(D3DXVECTOR3 min1, D3DXVECTOR3 max1, D3DXVECTOR3 min2, D3DXVECTOR3 max2)
	{
	if (min1.x <= max2.x && max1.x >= min2.x &&
		min1.y <= max2.y && max1.y >= min2.y)
	{
		return true;
	}
	else
	{
		return false;
	}
}
};
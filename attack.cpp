#include "main.h"
#include "attack.h"

#include "manager.h"
#include "renderer.h"
#include "model.h"
#include "Player.h"
#include "Bullet.h"
#include "input.h"
#include "scene.h"
#include "box.h"
#include "camera.h"
#include "game_object.h"
#include "explosion.h"
#include "sound.h"
#include "enemy.h"

void CAttack::Init()
{

	m_Position = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	m_Rotation = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_Scale = D3DXVECTOR3(1.0f, 1.0f, 1.0f);
	g_Box = new CBox();
	g_Box->Init();
	m_Max = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_Min = D3DXVECTOR3(0.0f, 0.0f, 0.0f);


	m_Count = 0;
	m_sCount = 0;
}

void CAttack::Update()
{
	g_Box->Update(m_Position, m_Min, m_Max);
	m_Count++;
	if (m_Count > 25)
	{
		SetDestroy();
	}
	
}

void CAttack::Uninit()
{
	g_Box->Destroy();


}
void CAttack::Transparent()
{
	g_Box->Draw(&world);
}
void CAttack::Draw()
{
	LIGHT light;
	light.Enable = false;
	CRenderer::SetLight(light);






	D3DXMATRIX  scale, rot, trans;
	D3DXMatrixScaling(&scale, m_Scale.x, m_Scale.y, m_Scale.z);
	D3DXMatrixRotationYawPitchRoll(&rot, m_Rotation.y, m_Rotation.x, m_Rotation.z);
	D3DXMatrixTranslation(&trans, m_Position.x, m_Position.y, m_Position.z);
	world = scale * rot * trans;






}
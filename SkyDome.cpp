#include "main.h"
#include "manager.h"
#include "renderer.h"
#include "model.h"
#include "SkyDome.h"
#include "Player.h"
#include "input.h"
#include "scene.h"
#include "light.h"

void CSkyDome::Init()
{
	m_Position = D3DXVECTOR3(0.0f, -15.0f, 0.0f);
	m_Rotation = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_Scale = D3DXVECTOR3(3.5f,2.0f, 3.5f);

	m_Sky = new CModel();
	m_Sky->Load("asset\\model\\skybox3.obj");

	
}

void CSkyDome::Uninit()
{

	m_Sky->Unload();
	delete m_Sky;

}

void CSkyDome::Update()
{
	CCamera* Camera = CManager::GetScene()->GetGameObject<CCamera>(0);

	m_Position.x = Camera->GetPosition().x;
	m_Position.z = Camera->GetPosition().z;

}

void CSkyDome::Draw()
{
	LIGHT light;
	light.Enable = false;
	CRenderer::SetLight(light);

	D3DXMATRIX world, scale, rot, trans;
	D3DXMatrixScaling(&scale, m_Scale.x, m_Scale.y, m_Scale.z);
	D3DXMatrixRotationYawPitchRoll(&rot, m_Rotation.y, m_Rotation.x, m_Rotation.z);
	D3DXMatrixTranslation(&trans, m_Position.x, m_Position.y, m_Position.z);
	world = scale * rot * trans;

	CRenderer::SetWorldMatrix(&world);
	//マトリクス設定
	m_Sky->Draw();

	light.Enable = true;

}
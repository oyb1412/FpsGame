#include "main.h"
#include "manager.h"
#include "renderer.h"
#include "model.h"
#include "Player.h"
#include "enemy.h"
#include "box.h"
#include "2dbox.h"
#include "input.h"
#include "camera.h"
#include "scene.h"
#include "sound.h"
#include "ebullet.h"
#include "bullet.h"
#include "light.h"
#include "Number.h"
#include "3dpolygon.h"
#include "eattack.h"
#include <cstdlib>
#include <stdlib.h>
#include "item.h"
#include <time.h>
#include "Mouse.h"

ID3D11ShaderResourceView* CEnemy::Golem_Texture;
ID3D11ShaderResourceView* CEnemy::Wolf_Texture;
ID3D11ShaderResourceView* CEnemy::Boss_Texture;
ID3D11ShaderResourceView* CEnemy::Tree_Texture;
ID3D11ShaderResourceView* CEnemy::Tank_Texture;

CModel* CEnemy::Golem_Model;
CModel* CEnemy::Wolf_Model;
CModel* CEnemy::Boss_Model;
CModel* CEnemy::Airplane_Model;
CModel* CEnemy::Tank_Model;
void CEnemy::Load()
{
	D3DX11CreateShaderResourceViewFromFile(CRenderer::GetDevice(),
		"asset/texture/gun/SmallGun_Texture.jpg",
		NULL,
		NULL,
		&Golem_Texture,
		NULL);


	D3DX11CreateShaderResourceViewFromFile(CRenderer::GetDevice(),
		"asset/texture/enemy/Wolf_Texture.jpg",
		NULL,
		NULL,
		&Wolf_Texture,
		NULL);

	D3DX11CreateShaderResourceViewFromFile(CRenderer::GetDevice(),
		"asset/texture/enemy/Boss_Texture.jpg",
		NULL,
		NULL,
		&Boss_Texture,
		NULL);

	D3DX11CreateShaderResourceViewFromFile(CRenderer::GetDevice(),
		"asset/texture/enemy/Tree.png",
		NULL,
		NULL,
		&Tree_Texture,
		NULL);

	Golem_Model = new CModel();
	Golem_Model->Load("asset\\model\\enemy\\monster.obj");

	Wolf_Model = new CModel();
	Wolf_Model->Load("asset\\model\\enemy\\dog.obj");

	Boss_Model = new CModel();
	Boss_Model->Load("asset\\model\\enemy\\boss1.obj");

	Airplane_Model = new CModel();
	Airplane_Model->Load("asset\\model\\enemy\\airplane.obj");

	Tank_Model = new CModel();
	Tank_Model->Load("asset\\model\\enemy\\tank.obj");
}

void CEnemy::Unload()
{
	Golem_Texture->Release();
	Wolf_Texture->Release();
	Boss_Texture->Release();
	Tree_Texture->Release();

	Golem_Model->Unload();
	delete Golem_Model;
	Wolf_Model->Unload();
	delete Wolf_Model;
	Boss_Model->Unload();
	delete Boss_Model;
	Airplane_Model->Unload();
	delete Airplane_Model;
	Tank_Model->Unload();
	delete Tank_Model;
}
void CEnemy::Init()
{

	srand((unsigned int)time(NULL));
	Attack_Count = (rand() % 60) + 100;
	Tank_Random = rand() % 5;

	
	

	

	Hp = 2;
	m_Position = D3DXVECTOR3(-80.0f, 1.0f, -205.0f);
	m_Rotation = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_Scale = D3DXVECTOR3(3.5f, 4.5f, 3.5f);
	m_Max = D3DXVECTOR3(-111.0f, -10.0f, -10.0f);
	m_Min = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_Body = new CBox();
	m_Body->Init();

	m_Head = new CBox();
	m_Head->Init();
	Ult_Count = false;
	Underattack = false;
	BackMove = false;
	BackMoveCount = 0;
	SoundAttack = false;
	Create_Count = 0;
	StopEnemy = false;
	StopCount = 0;
	Count = 0;
	AttackCount = 0;
	EnemyFade = 1.0f;
	EnemyFadeCount = 0;
	LetBoss = false;
	StartFade = false;
	DestroyAngle = 0.0f;
	SelectAngle = false;
	StartBilboard = false;
	PartType = 0;
	AttackTurm = false;
	CCamera* camera = CManager::GetScene()->GetGameObject<CCamera>(0);
	D3DXVECTOR3 Camera = camera->GetPosition();
	D3DXVECTOR3 dir = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	D3DXMatrixLookAtLH(&EviewMatrix, &Camera, &m_Position
		, &dir);
	view = EviewMatrix;
	D3DXMatrixIdentity(&invView);

	invView._11 = view._11;
	invView._13 = view._13;
	invView._31 = view._31;
	invView._33 = view._33;
	D3DXMatrixInverse(&invView, NULL, &invView);
	
	for (int i = 0; i < 5; i++)
	{
		Tank_Pattern[i] = false;
	}
}

void CEnemy::Update()
{
	if (Type == TYPE_TREE)
	{
		StartBilboard = true;
	}
	
	if (Type != TYPE_TREE)
	{
		m_Body->Update(m_Position, Body_Min, Body_Max);
		m_Head->Update(m_Position, Head_Min, Head_Max);
	}
		CScene* scene = CManager::GetScene();
		CCamera* camera = CManager::GetScene()->GetGameObject<CCamera>(0);

		D3DXVECTOR3 CameraPosition = camera->GetPosition();
		D3DXVECTOR3 direction = m_Position - CameraPosition;
		Enemy_Player_Vec = -direction;
		D3DXVec3Normalize(&Enemy_Player_Vec, &Enemy_Player_Vec);
		Enemy_Player_Vec.y = 0;
		D3DXVec3Normalize(&Enemy_Player_Vec, &Enemy_Player_Vec);
		float length = D3DXVec3Length(&direction);
	

	if (Hp <= 0 && !StartFade)
	{
		if (Type == TYPE_GOLEM)
		{
			scene->AddGameObject<CExplosion>(9)->SetTexture(ENEMY_DISTROY, ENEMY_DISTROY_X, ENEMY_DISTROY_Y, D3DXVECTOR3(m_Position.x,m_Position.y+1.5f,m_Position.z), D3DXVECTOR3(2.0f, 2.0f, 0.0f));

			PlaySoundA(SOUND_LABEL_SE_ENEMY_DESTROY);
		}
		if (Type == TYPE_AIRPLANE)
		{
			scene->AddGameObject<CExplosion>(9)->SetTexture(ENEMY_DISTROY, ENEMY_DISTROY_X, ENEMY_DISTROY_Y, D3DXVECTOR3(m_Position.x, m_Position.y + 0.5f, m_Position.z), D3DXVECTOR3(1.0f, 1.0f, 0.0f));

			PlaySoundA(SOUND_LABEL_SE_ENEMY_DESTROY);
		}
		if (Type == TYPE_WOLF)
		{
			scene->AddGameObject<CExplosion>(9)->SetTexture(ENEMY_DISTROY, ENEMY_DISTROY_X, ENEMY_DISTROY_Y, D3DXVECTOR3(m_Position.x, m_Position.y + 0.5f, m_Position.z), D3DXVECTOR3(1.0f, 1.0f, 0.0f));

			PlaySoundA(SOUND_LABEL_SE_ENEMY_DESTROY);
			
		}
		if (Type == TYPE_TANK)
		{
			scene->AddGameObject<CExplosion>(9)->SetTexture(ENEMY_DISTROY, ENEMY_DISTROY_X, ENEMY_DISTROY_Y, D3DXVECTOR3(m_Position.x, m_Position.y + 2.5f, m_Position.z), D3DXVECTOR3(2.0f, 2.0f, 0.0f));

			PlaySoundA(SOUND_LABEL_SE_ENEMY_DESTROY);
			C3dpolygon* ClearTeleport = CManager::GetScene()->GetGameObject<C3dpolygon>(4);
			ClearTeleport->SetTeleport();

		}
		StartFade = true;
	}
	if (StartFade)
	{
		SelectAngle = true;

		if (Type == TYPE_GOLEM || Type == TYPE_WOLF ||Type == TYPE_AIRPLANE || Type == TYPE_TANK)
		{
			DestroyAngle += D3DXToRadian(1.3f);

			EnemyFadeCount++;

			if (EnemyFadeCount > 60)
			{
				if (Type == TYPE_TANK)
				{
					StopSound();
					PlaySoundA(SOUND_LABEL_SE_VICTORY);
				}
				EnemyFadeCount = 0;
				SetDestroy();
			}
		}
	}
	

	

		if (!StartFade)
		{
			if (StopEnemy)
			{
				StopCount++;
			}

			if (StopEnemy && StopCount > 20)
			{
				StopEnemy = false;
				StopCount = 0;
			}

			Enemy_Player_Vec = CameraPosition - m_Position;
			D3DXVec3Normalize(&Enemy_Player_Vec, &Enemy_Player_Vec);
			Enemy_Player_Vec.y = 0;
			CPlayer* Player = CManager::GetScene()->GetGameObject<CPlayer>(2);
			if (Type == TYPE_TANK)
			{
				if (m_Position.z > 485.0f)
				{
					m_Position.z -= 0.06f;
				}
				if (m_Position.y < 2.5f)
				{
					if (m_Position.y < 2.48f)
					{
						camera->BeginBoss();
					}
					if (m_Position.y >= 2.48f && m_Position.y <= 2.49f)
					{
						LetBoss = true;
						camera->StartBoss();
					}
					m_Position.y += 0.00025f;
				}
				
				if (m_Position.y > 2.5f)
				{
					Create_Count++;

				}
				if (LetBoss && m_Position.y > 2.5f)
				{
					
					if (Hp < 625 && Hp > 540 && !Ult_Count)
					{
						Tank_Pattern[0] = false;
						Tank_Pattern[1] = false;
						Tank_Pattern[2] = false;
						Tank_Pattern[3] = true;
						Tank_Pattern[4] = false;
						LetBoss = false;
						Tank_Random = 10;
					}
					if (Hp < 225 && Hp > 140 && Ult_Count)
					{
						Tank_Pattern[0] = false;
						Tank_Pattern[1] = false;
						Tank_Pattern[2] = false;
						Tank_Pattern[3] = false;
						Tank_Pattern[4] = true;
						LetBoss = false;
						Tank_Random = 10;
					}
					if (!Tank_Pattern[0] && !Tank_Pattern[1] && !Tank_Pattern[2])
					{
						if (Create_Count > 900)
						{
							if (Tank_Random == 0)
							{
								scene->AddGameObject<CExplosion>(9)->SetTexture(SUMMON_LONG, CREATE_EFFECT_X, CREATE_EFFECT_Y, D3DXVECTOR3(20.0f, 5.6f, 495.0f), D3DXVECTOR3(5.0f, 4.0f, 0.0f));
								PlaySoundA(SOUND_LABEL_SE_SUMMONING);

								Create_Count = 0;
							}
							if (Tank_Random == 1)
							{
								scene->AddGameObject<CExplosion>(9)->SetTexture(SUMMON_LONG, CREATE_EFFECT_X, CREATE_EFFECT_Y, D3DXVECTOR3(20.0f, 5.6f, 465.0f), D3DXVECTOR3(5.0f, 4.0f, 0.0f));
								PlaySoundA(SOUND_LABEL_SE_SUMMONING);

								Create_Count = 0;
							}
							if (Tank_Random == 2)
							{
								scene->AddGameObject<CExplosion>(9)->SetTexture(SUMMON_LONG, CREATE_EFFECT_X, CREATE_EFFECT_Y, D3DXVECTOR3(50.0f, 5.6f, 495.0f), D3DXVECTOR3(5.0f, 4.0f, 0.0f));
								PlaySoundA(SOUND_LABEL_SE_SUMMONING);

								Create_Count = 0;
							}
							if (Tank_Random > 2)
							{
								scene->AddGameObject<CExplosion>(9)->SetTexture(SUMMON_LONG, CREATE_EFFECT_X, CREATE_EFFECT_Y, D3DXVECTOR3(50.0f, 5.6f, 465.0f), D3DXVECTOR3(5.0f, 4.0f, 0.0f));
								PlaySoundA(SOUND_LABEL_SE_SUMMONING);

								Create_Count = 0;
							}
						}
						if (Tank_Random == 0 || Tank_Random == 1)
						{

							Tank_Pattern[0] = true;
							Tank_Pattern[1] = false;
							Tank_Pattern[2] = false;
							LetBoss = false;
						}


						if (Tank_Random == 2 || Tank_Random == 3)
						{
							PlaySoundA(SOUND_LABEL_SE_BOSS_WARNING);

							Tank_Pattern[0] = false;
							Tank_Pattern[1] = true;
							Tank_Pattern[2] = false;
							LetBoss = false;
						}

						if (Tank_Random == 4)
						{
							Tank_Pattern[0] = false;
							Tank_Pattern[1] = false;
							Tank_Pattern[2] = true;
							LetBoss = false;

						}
					}
				}


				if (Tank_Pattern[0] && !LetBoss)
				{
					AttackCount++;

					if (AttackCount == 30)
					{
						StartBilboard = true;
						Stop_FrontVec = Enemy_Player_Vec;
						Stop_RightVec = Enemy_Player_Vec;
						Stop_LeftVec = Enemy_Player_Vec;
						D3DXVec3Normalize(&Stop_FrontVec, &Stop_FrontVec);
						D3DXVec3Normalize(&Stop_RightVec, &Stop_RightVec);
						D3DXVec3Normalize(&Stop_LeftVec, &Stop_LeftVec);

						D3DXMATRIX rot,rot1;
						D3DXMatrixRotationY(&rot, D3DXToRadian(90));
						D3DXVec3TransformNormal(&Stop_RightVec, &Stop_FrontVec, &rot);
						D3DXMatrixRotationY(&rot1, D3DXToRadian(-90));
						D3DXVec3TransformNormal(&Stop_LeftVec, &Stop_FrontVec, &rot1);

					}
					if (AttackCount == 40 || AttackCount == 60 || AttackCount == 80)
					{
						//if (AttackCount == 40)
						{
							PlaySoundA(SOUND_LABEL_SE_BOSS_ATTACK);
						}
						scene->AddGameObject<CEbullet>(8)->SetPosition_Scale_Vec(BOSS_BULLET, ENEMY_BULLET_X, ENEMY_BULLET_Y, D3DXVECTOR3(m_Position.x  + Stop_RightVec.x*3.0f, m_Position.y + 1.5f, m_Position.z  + Stop_RightVec.z*3.0f), D3DXVECTOR3(1.5f, 1.5f, 0.7f), Enemy_Player_Vec);
						scene->AddGameObject<CEbullet>(8)->SetPosition_Scale_Vec(BOSS_BULLET, ENEMY_BULLET_X, ENEMY_BULLET_Y, D3DXVECTOR3(m_Position.x , m_Position.y + 1.5f, m_Position.z ), D3DXVECTOR3(0.5f, 0.5f, 0.7f), Stop_FrontVec);
						scene->AddGameObject<CEbullet>(8)->SetPosition_Scale_Vec(BOSS_BULLET, ENEMY_BULLET_X, ENEMY_BULLET_Y, D3DXVECTOR3(m_Position.x  + Stop_LeftVec.x*3.0f, m_Position.y + 1.5f, m_Position.z - Stop_LeftVec.z*3.0f), D3DXVECTOR3(1.5f, 1.5f, 0.7f), Enemy_Player_Vec);
					}
					if (AttackCount > 80)
					{
						StartBilboard = true;
						m_Position += Enemy_Player_Vec * 0.1f;
					}
					if (AttackCount > 120)
					{
						AttackCount = -50;
						Tank_Pattern[0] = false;
						LetBoss = true;
						Tank_Random = rand() % 5;
					}
				}
				if (Tank_Pattern[1] && !LetBoss)
				{
					AttackCount++;
					if (AttackCount == 10)
					{
						StartBilboard = true;

						Stop_PlayerPosition = camera->GetPosition();
						Stop_FrontVec = Enemy_Player_Vec;
					}
				
					if (AttackCount > 100 && AttackCount < 140)
					{
						StartBilboard = false;

						if (m_Position.x < 60.0f&& m_Position.x > 10.0f && m_Position.z < 505.0f&& m_Position.z > 455.0f)
						{
							m_Position += Stop_FrontVec * BOSS_SPEED;
						}
					}
					if (AttackCount > 140)
					{
						m_Position += Enemy_Player_Vec * 0.5f;
					}
					if (AttackCount > 160)
					{
						AttackCount = -50;
						Tank_Pattern[1] = false;
						LetBoss = true;
						Tank_Random = rand() % 5;
					}

				}
				if (Tank_Pattern[2] && !LetBoss)
				{
					AttackCount++;
					if (AttackCount == 10)
					{
						StartBilboard = true;
						Target_Position = camera->GetPosition();
						Stop_FrontVec = Target_Position - m_Position;
						D3DXVec3Normalize(&Stop_FrontVec, &Stop_FrontVec);
					}
					if (AttackCount == 30)
					{
						PlaySoundA(SOUND_LABEL_SE_BOSS_BOOMSHOT);
						scene->AddGameObject<CEbullet>(8)->SetPosition_Boom(BOOM, ENEMY_BULLET_X, ENEMY_BULLET_Y, D3DXVECTOR3(m_Position.x + Stop_FrontVec.x * 2, m_Position.y + 1.5f, m_Position.z + Stop_FrontVec.z * 2), D3DXVECTOR3(0.5f,0.5f,0.5f), Stop_FrontVec, Target_Position);
					}
					if (AttackCount > 40)
					{
						StartBilboard = false;
					}
					if (AttackCount > 60)
					{
						StartBilboard = true;

						m_Position += Enemy_Player_Vec * 0.1f;
					}
					if (AttackCount == 100)
					{
						AttackCount = -50;
						Tank_Pattern[2] = false;
						LetBoss = true;
						Tank_Random = rand() % 5;
					}
					
				}
				if (Tank_Pattern[3] && !LetBoss)
				{
					AttackCount++;
					if (AttackCount == 10)
					{
						PlaySoundA(SOUND_LABEL_SE_BOSS_ULT);

					}
					if (AttackCount == 50)
					{
						StartBilboard = true;
						Stop_FrontVec = Enemy_Player_Vec;
						Stop_RightVec = camera->GetRightVec();
					}
					if (AttackCount == 60)
					{
						PlaySoundA(SOUND_LABEL_SE_BOSS_ATTACK);

						scene->AddGameObject<CEbullet>(8)->SetPosition_Scale_Vec(BOSS_BULLET, ENEMY_BULLET_X, ENEMY_BULLET_Y, D3DXVECTOR3(m_Position.x + Stop_RightVec.x * 3, m_Position.y + 1.5f, m_Position.z + Stop_RightVec.z * 3), D3DXVECTOR3(1.5f, 1.5f, 0.7f), Enemy_Player_Vec);
						scene->AddGameObject<CEbullet>(8)->SetPosition_Scale_Vec(BOSS_BULLET, ENEMY_BULLET_X, ENEMY_BULLET_Y, D3DXVECTOR3(m_Position.x + Stop_RightVec.x * 4, m_Position.y + 1.5f, m_Position.z + Stop_RightVec.z * 4), D3DXVECTOR3(1.5f, 1.5f, 0.7f), Enemy_Player_Vec);
						scene->AddGameObject<CEbullet>(8)->SetPosition_Scale_Vec(BOSS_BULLET, ENEMY_BULLET_X, ENEMY_BULLET_Y, D3DXVECTOR3(m_Position.x + Stop_RightVec.x * 5, m_Position.y + 1.5f, m_Position.z + Stop_RightVec.z * 5), D3DXVECTOR3(1.5f, 1.5f, 0.7f), Enemy_Player_Vec);
																																																														  
						scene->AddGameObject<CEbullet>(8)->SetPosition_Scale_Vec(BOSS_BULLET, ENEMY_BULLET_X, ENEMY_BULLET_Y, D3DXVECTOR3(m_Position.x - Stop_RightVec.x * 3, m_Position.y + 1.5f, m_Position.z + Stop_RightVec.z - 3), D3DXVECTOR3(1.5f, 1.5f, 0.7f), Enemy_Player_Vec);
						scene->AddGameObject<CEbullet>(8)->SetPosition_Scale_Vec(BOSS_BULLET, ENEMY_BULLET_X, ENEMY_BULLET_Y, D3DXVECTOR3(m_Position.x - Stop_RightVec.x * 4, m_Position.y + 1.5f, m_Position.z + Stop_RightVec.z -4), D3DXVECTOR3(1.5f, 1.5f, 0.7f), Enemy_Player_Vec);
						scene->AddGameObject<CEbullet>(8)->SetPosition_Scale_Vec(BOSS_BULLET, ENEMY_BULLET_X, ENEMY_BULLET_Y, D3DXVECTOR3(m_Position.x - Stop_RightVec.x * 5, m_Position.y + 1.5f, m_Position.z + Stop_RightVec.z - 5), D3DXVECTOR3(1.5f, 1.5f, 0.7f), Enemy_Player_Vec);
					}
					if (AttackCount == 100)
					{
						PlaySoundA(SOUND_LABEL_SE_BOSS_ATTACK);

						scene->AddGameObject<CEbullet>(8)->SetPosition_Scale_Vec(BOSS_BULLET, ENEMY_BULLET_X, ENEMY_BULLET_Y, D3DXVECTOR3(m_Position.x + Stop_RightVec.x * 0.5f, m_Position.y + 1.5f, m_Position.z + Stop_RightVec.z * 0.5f), D3DXVECTOR3(1.5f, 1.5f, 0.7f), Enemy_Player_Vec);
						scene->AddGameObject<CEbullet>(8)->SetPosition_Scale_Vec(BOSS_BULLET, ENEMY_BULLET_X, ENEMY_BULLET_Y, D3DXVECTOR3(m_Position.x - Stop_RightVec.x * 0.5f, m_Position.y + 1.5f, m_Position.z - Stop_RightVec.z * 0.5f), D3DXVECTOR3(1.5f, 1.5f, 0.7f), Enemy_Player_Vec);
					}
					if (AttackCount == 140)
					{
						PlaySoundA(SOUND_LABEL_SE_BOSS_ATTACK);

						scene->AddGameObject<CEbullet>(8)->SetPosition_Scale_Vec(BOSS_BULLET, ENEMY_BULLET_X, ENEMY_BULLET_Y, D3DXVECTOR3(m_Position.x + Stop_RightVec.x * 3, m_Position.y + 1.5f, m_Position.z + Stop_RightVec.z * 3), D3DXVECTOR3(1.5f, 1.5f, 0.7f), Enemy_Player_Vec);
						scene->AddGameObject<CEbullet>(8)->SetPosition_Scale_Vec(BOSS_BULLET, ENEMY_BULLET_X, ENEMY_BULLET_Y, D3DXVECTOR3(m_Position.x + Stop_RightVec.x * 4, m_Position.y + 1.5f, m_Position.z + Stop_RightVec.z * 4), D3DXVECTOR3(1.5f, 1.5f, 0.7f), Enemy_Player_Vec);
																																																														  
						scene->AddGameObject<CEbullet>(8)->SetPosition_Scale_Vec(BOSS_BULLET, ENEMY_BULLET_X, ENEMY_BULLET_Y, D3DXVECTOR3(m_Position.x - Stop_RightVec.x * 3, m_Position.y + 1.5f, m_Position.z - Stop_RightVec.z * 3), D3DXVECTOR3(1.5f, 1.5f, 0.7f), Enemy_Player_Vec);
						scene->AddGameObject<CEbullet>(8)->SetPosition_Scale_Vec(BOSS_BULLET, ENEMY_BULLET_X, ENEMY_BULLET_Y, D3DXVECTOR3(m_Position.x - Stop_RightVec.x * 4, m_Position.y + 1.5f, m_Position.z - Stop_RightVec.z * 4), D3DXVECTOR3(1.5f, 1.5f, 0.7f), Enemy_Player_Vec);
					}
					if (AttackCount == 180)
					{
						PlaySoundA(SOUND_LABEL_SE_BOSS_ATTACK);

						scene->AddGameObject<CEbullet>(8)->SetPosition_Scale_Vec(BOSS_BULLET, ENEMY_BULLET_X, ENEMY_BULLET_Y, D3DXVECTOR3(m_Position.x , m_Position.y + 1.5f, m_Position.z ), D3DXVECTOR3(1.5f, 1.5f, 0.7f), Enemy_Player_Vec);

					}
					if (AttackCount == 200)
					{
						AttackCount = -50;
						LetBoss = true;
						Tank_Random = rand() % 5;
						Tank_Pattern[3] = false;
						Ult_Count = true;
					}
				}

				if (Tank_Pattern[4] && !LetBoss)
				{
					AttackCount++;
					if (AttackCount == 10)
					{
						PlaySoundA(SOUND_LABEL_SE_BOSS_ULT);

					}
					if (AttackCount == 50)
					{
						Stop_FrontVec = Enemy_Player_Vec;
						Stop_RightVec = Enemy_Player_Vec;
						Stop_LeftVec = Enemy_Player_Vec;
						D3DXVec3Normalize(&Stop_FrontVec, &Stop_FrontVec);
						D3DXVec3Normalize(&Stop_RightVec, &Stop_RightVec);
						D3DXVec3Normalize(&Stop_LeftVec, &Stop_LeftVec);

						D3DXMATRIX rot, rot1;
						D3DXMatrixRotationY(&rot, D3DXToRadian(90));
						D3DXVec3TransformNormal(&Stop_RightVec, &Stop_FrontVec, &rot);
						D3DXMatrixRotationY(&rot1, D3DXToRadian(-90));
						D3DXVec3TransformNormal(&Stop_LeftVec, &Stop_FrontVec, &rot1);
					}
					if (AttackCount == 60)
					{
						PlaySoundA(SOUND_LABEL_SE_BOSS_ATTACK);

						scene->AddGameObject<CEbullet>(8)->SetPosition_Scale_Vec(BOSS_BULLET, ENEMY_BULLET_X, ENEMY_BULLET_Y, D3DXVECTOR3(m_Position.x + Stop_RightVec.x * 3, m_Position.y + 1.5f, m_Position.z + Stop_RightVec.z * 3), D3DXVECTOR3(1.5f, 1.5f, 0.7f), Enemy_Player_Vec);
						scene->AddGameObject<CEbullet>(8)->SetPosition_Scale_Vec(BOSS_BULLET, ENEMY_BULLET_X, ENEMY_BULLET_Y, D3DXVECTOR3(m_Position.x + Stop_RightVec.x * 4, m_Position.y + 1.5f, m_Position.z + Stop_RightVec.z * 4), D3DXVECTOR3(1.5f, 1.5f, 0.7f), Enemy_Player_Vec);
						scene->AddGameObject<CEbullet>(8)->SetPosition_Scale_Vec(BOSS_BULLET, ENEMY_BULLET_X, ENEMY_BULLET_Y, D3DXVECTOR3(m_Position.x + Stop_RightVec.x * 5, m_Position.y + 1.5f, m_Position.z + Stop_RightVec.z * 5), D3DXVECTOR3(1.5f, 1.5f, 0.7f), Enemy_Player_Vec);
																																																														  
						scene->AddGameObject<CEbullet>(8)->SetPosition_Scale_Vec(BOSS_BULLET, ENEMY_BULLET_X, ENEMY_BULLET_Y, D3DXVECTOR3(m_Position.x + Stop_LeftVec.x * 3, m_Position.y + 1.5f, m_Position.z + Stop_LeftVec.z * 3), D3DXVECTOR3(1.5f, 1.5f, 0.7f), Enemy_Player_Vec);
						scene->AddGameObject<CEbullet>(8)->SetPosition_Scale_Vec(BOSS_BULLET, ENEMY_BULLET_X, ENEMY_BULLET_Y, D3DXVECTOR3(m_Position.x + Stop_LeftVec.x * 4, m_Position.y + 1.5f, m_Position.z + Stop_LeftVec.z * 4), D3DXVECTOR3(1.5f, 1.5f, 0.7f), Enemy_Player_Vec);
						scene->AddGameObject<CEbullet>(8)->SetPosition_Scale_Vec(BOSS_BULLET, ENEMY_BULLET_X, ENEMY_BULLET_Y, D3DXVECTOR3(m_Position.x + Stop_LeftVec.x * 5, m_Position.y + 1.5f, m_Position.z + Stop_LeftVec.z * 5), D3DXVECTOR3(1.5f, 1.5f, 0.7f), Enemy_Player_Vec);
					}
					if (AttackCount == 100)
					{
						PlaySoundA(SOUND_LABEL_SE_BOSS_ATTACK);

						scene->AddGameObject<CEbullet>(8)->SetPosition_Scale_Vec(BOSS_BULLET, ENEMY_BULLET_X, ENEMY_BULLET_Y, D3DXVECTOR3(m_Position.x + Stop_RightVec.x * 0.5f, m_Position.y + 1.5f, m_Position.z + Stop_RightVec.z * 0.5f), D3DXVECTOR3(1.5f, 1.5f, 0.7f), Enemy_Player_Vec);
						scene->AddGameObject<CEbullet>(8)->SetPosition_Scale_Vec(BOSS_BULLET, ENEMY_BULLET_X, ENEMY_BULLET_Y, D3DXVECTOR3(m_Position.x + Stop_LeftVec.x * 0.5f, m_Position.y + 1.5f, m_Position.z + Stop_LeftVec.z * 0.5f), D3DXVECTOR3(1.5f, 1.5f, 0.7f), Enemy_Player_Vec);
					}
					if (AttackCount == 140)
					{
						PlaySoundA(SOUND_LABEL_SE_BOSS_ATTACK);

						scene->AddGameObject<CEbullet>(8)->SetPosition_Scale_Vec(BOSS_BULLET, ENEMY_BULLET_X, ENEMY_BULLET_Y, D3DXVECTOR3(m_Position.x + Stop_RightVec.x * 3, m_Position.y + 1.5f, m_Position.z + Stop_RightVec.z * 3), D3DXVECTOR3(1.5f, 1.5f, 0.7f), Enemy_Player_Vec);
						scene->AddGameObject<CEbullet>(8)->SetPosition_Scale_Vec(BOSS_BULLET, ENEMY_BULLET_X, ENEMY_BULLET_Y, D3DXVECTOR3(m_Position.x + Stop_RightVec.x * 4, m_Position.y + 1.5f, m_Position.z + Stop_RightVec.z * 4), D3DXVECTOR3(1.5f, 1.5f, 0.7f), Enemy_Player_Vec);

						scene->AddGameObject<CEbullet>(8)->SetPosition_Scale_Vec(BOSS_BULLET, ENEMY_BULLET_X, ENEMY_BULLET_Y, D3DXVECTOR3(m_Position.x + Stop_LeftVec.x * 3, m_Position.y + 1.5f, m_Position.z + Stop_LeftVec.z * 3), D3DXVECTOR3(1.5f, 1.5f, 0.7f), Enemy_Player_Vec);
						scene->AddGameObject<CEbullet>(8)->SetPosition_Scale_Vec(BOSS_BULLET, ENEMY_BULLET_X, ENEMY_BULLET_Y, D3DXVECTOR3(m_Position.x + Stop_LeftVec.x * 4, m_Position.y + 1.5f, m_Position.z + Stop_LeftVec.z * 4), D3DXVECTOR3(1.5f, 1.5f, 0.7f), Enemy_Player_Vec);
					}
					if (AttackCount == 180)
					{
						PlaySoundA(SOUND_LABEL_SE_BOSS_ATTACK);

						scene->AddGameObject<CEbullet>(8)->SetPosition_Scale_Vec(BOSS_BULLET, ENEMY_BULLET_X, ENEMY_BULLET_Y, D3DXVECTOR3(m_Position.x, m_Position.y + 1.5f, m_Position.z), D3DXVECTOR3(1.5f, 1.5f, 0.7f), Enemy_Player_Vec);

					}
					if (AttackCount == 200)
					{
						AttackCount = -50;
						LetBoss = true;
						Tank_Random = rand() % 5;
						Tank_Pattern[4] = false;
						Ult_Count = false;
					}
				}
			}


			if ( Type == TYPE_WOLF && !StopEnemy)
			{
				Attack_Count++;
				if (!SoundAttack && length < 100.0f && length > 4.0f && Attack_Count >= 0 || Underattack && length > 4.0f)
				{
					StartBilboard = true;
					m_Position += Enemy_Player_Vec * WOLF_SPEED;
				}
				if (length >= 100.0f && !Underattack && !SoundAttack)
				{
					StartBilboard = false;
				}
				
				
				if (length <= 7.0f)
				{
					AttackCount++;
			
					if (AttackCount == 50)
					{
						scene->AddGameObject<CEattack>(8)->SetObject((m_Position + Enemy_Player_Vec *3), D3DXVECTOR3(3.0f,3.0f, 3.0f));
						AttackCount = -30;
						Attack_Count = -30;
						BackMove = true;
					}
					if (BackMove)
					{
						BackMoveCount++;
						if (BackMoveCount < 20)
						{
							m_Position.x += Enemy_Player_Vec.x*0.2f;
							m_Position.z += Enemy_Player_Vec.z*0.2f;

						}
						if (BackMoveCount >= 20 && BackMoveCount < 40)
						{
							m_Position.x -= Enemy_Player_Vec.x*0.2f;
							m_Position.z -= Enemy_Player_Vec.z*0.2f;
						}
						if (BackMoveCount >= 50)
						{
							BackMoveCount = 0;
							BackMove = false;
						}
					}
					
				}

			}


			if (Type == TYPE_GOLEM )
			{

				//if (length < 50.0f && length > 0.0f)
				{
					AttackCount++;

					//Attack_Count‚É100~130‚Ì‚¤‚¿ˆê‚Â‚ð•Û‘¶
					//AttackCount‚ªAttack_Count‚Æ“¯‚¶‚­‚È‚é‚Æ”­ŽË
					if (AttackCount == Attack_Count - 10)
					{
						StartBilboard = true;
					}
					if (AttackCount == Attack_Count)
					{
				
						//PlaySoundA(SOUND_LABEL_SE_BOSS_ATTACK);

						scene->AddGameObject<CEbullet>(8)->SetPosition_Scale_Vec(ENEMY_BULLET, ENEMY_BULLET_X, ENEMY_BULLET_Y,D3DXVECTOR3(m_Position.x+ Enemy_Player_Vec.x*2, m_Position.y+1.5f, m_Position.z+ Enemy_Player_Vec.z*2), D3DXVECTOR3(2.0f, 2.0f, 1.0f), Enemy_Player_Vec);
						AttackCount = 0;
						Attack_Count = (rand() % 60) + 100;
						StartBilboard = false;
					}
				}
			}

			if (Type == TYPE_AIRPLANE && !StopEnemy)
			{
				Attack_Count++;
				if (!SoundAttack && length < 50.0f && length > 4.0f && Attack_Count >= 0 || Underattack && length > 4.0f)
				{
					StartBilboard = true;
					m_Position += Enemy_Player_Vec * WOLF_SPEED;
				}
				if (length >= 50.0f && !Underattack && !SoundAttack)
				{
					StartBilboard = false;
				}
				if (length < 80.0f)
				{

					if (InputMouse::PushLeft() && Player->GetBulletNumber(SMALLGUN) > 0 && !Player->GetWeaponChange() && !Player->GetReroad() /*&& !camera->GetSmallGunShot()*/)
					{
						SoundAttack = true;
					}
					if (SoundAttack && length > 4.0f)
					{
						StartBilboard = true;
						m_Position += Enemy_Player_Vec * WOLF_SPEED;

					}
				}
				if (length >= 80.0f && SoundAttack)
				{
					StartBilboard = false;
				}
				if (length <= 7.0f)
				{
					AttackCount++;

					if (AttackCount == 50)
					{
						scene->AddGameObject<CEattack>(8)->SetObject((m_Position + Enemy_Player_Vec * 3), D3DXVECTOR3(1.0f, 1.0f, 1.0f));
						AttackCount = -30;
						Attack_Count = -30;
						BackMove = true;
					}
					if (BackMove)
					{
						BackMoveCount++;
						if (BackMoveCount < 20)
						{
							m_Position.x += Enemy_Player_Vec.x*0.2f;
							m_Position.z += Enemy_Player_Vec.z*0.2f;

						}
						if (BackMoveCount >= 20 && BackMoveCount < 40)
						{
							m_Position.x -= Enemy_Player_Vec.x*0.2f;
							m_Position.z -= Enemy_Player_Vec.z*0.2f;
						}
						if (BackMoveCount >= 50)
						{
							BackMoveCount = 0;
							BackMove = false;
						}
					}

				}

			}

		}
	}
	

void CEnemy::Uninit()
{
	m_Body->Destroy();
	m_Head->Destroy();

}
void CEnemy::Transparent()
{
	if (Type == TYPE_GOLEM)
	{
		m_Body->Draw(&golemboxworld);
		m_Head->Draw(&golemheadworld);
	}
	else if (Type == TYPE_WOLF)
	{
		
		m_Body->Draw(&wolfboxworld);
		m_Head->Draw(&headworld);
	}
	else if (Type == TYPE_AIRPLANE)
	{
		
		m_Body->Draw(&airboxworld);
		m_Head->Draw(&airheadboxworld);
	}
	else if (Type == TYPE_TANK)
	{
	
		m_Body->Draw(&tankboxworld);
		m_Head->Draw(&tankheadworld);
	}
}
void CEnemy::Draw()
{
	CCamera* camera = CManager::GetScene()->GetGameObject<CCamera>(0);

	CLight::SetLight(FIELD_LIGHT);

	
	


	D3DXMatrixScaling(&scale, m_Scale.x, m_Scale.y, m_Scale.z);
	D3DXMatrixRotationYawPitchRoll(&rot, m_Rotation.y, m_Rotation.x, m_Rotation.z);
	D3DXMatrixTranslation(&trans, m_Position.x, m_Position.y, m_Position.z);
	D3DXMatrixTranslation(&golemheadtrans, m_Position.x, m_Position.y + 2.7f, m_Position.z);
	D3DXMatrixScaling(&golemheadscale, m_Scale.x*3.0f, m_Scale.y*1.1f, m_Scale.z*3.0f);

	D3DXMatrixScaling(&wolfboxscale, m_Scale.x*6.5f, m_Scale.y*6.5f, m_Scale.z*6.5f);
	D3DXMatrixTranslation(&wolfboxtrans, m_Position.x- Enemy_Player_Vec.x*1.5f, m_Position.y, m_Position.z - Enemy_Player_Vec.z*1.5f);

	D3DXMatrixScaling(&headscale, m_Scale.x*2.5f, m_Scale.y*2.5f, m_Scale.z*2.5f);
	D3DXMatrixTranslation(&headtrans, m_Position.x + Enemy_Player_Vec.x*2.5f, m_Position.y+0.5f , m_Position.z + Enemy_Player_Vec.z*2.5f);

	D3DXMatrixScaling(&airboxscale, m_Scale.x*50.0f, m_Scale.y*45.0f, m_Scale.z*50.0f);
	D3DXMatrixTranslation(&airboxtrans, m_Position.x - Enemy_Player_Vec.x*1.0f, m_Position.y+0.2f , m_Position.z - Enemy_Player_Vec.z*1.0f);

	D3DXMatrixScaling(&airheadboxscale, m_Scale.x*50.0f, m_Scale.y*45.0f, m_Scale.z*50.0f);
	D3DXMatrixTranslation(&airheadboxtrans, m_Position.x + Enemy_Player_Vec.x*1.0f, m_Position.y + 0.2f, m_Position.z + Enemy_Player_Vec.z*1.0f);

	if (!SelectAngle)
	{
		EnemyRightVec = camera->GetRightVec();
	}

	D3DXMatrixRotationAxis(&destroyrot, &EnemyRightVec, DestroyAngle);
	D3DXMatrixScaling(&golemboxscale, m_Scale.x*3.0f, m_Scale.y*2.0f, m_Scale.z*3.0f);
	D3DXMatrixScaling(&tankboxscale, m_Scale.x*5.0f, m_Scale.y*3.0f, m_Scale.z*5.0f);
	D3DXMatrixTranslation(&tankboxtrans, m_Position.x , m_Position.y+0.3f, m_Position.z);

	D3DXMatrixScaling(&tankheadscale, m_Scale.x*2.5f, m_Scale.y*1.0f, m_Scale.z*2.5f);
	D3DXMatrixTranslation(&tankheadtrans, m_Position.x, m_Position.y + 5.0f, m_Position.z);

	D3DXMatrixTranslation(&trans1, 0.0f, 3.0f, 0.0f);
	D3DXMatrixTranslation(&trans2, 0.0f, -3.0f, 0.0f);



	if (!StartBilboard)
	{
		if (Count < 1)
		{
			D3DXVECTOR3 Camera = camera->GetPosition();
			D3DXVECTOR3 dir = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
			D3DXMatrixLookAtLH(&EviewMatrix, &Camera, &m_Position
				, &dir);
			view = EviewMatrix;
			
			D3DXMatrixIdentity(&invView);

			invView._11 = view._11;
			invView._13 = view._13;
			invView._31 = view._31;
			invView._33 = view._33;
			D3DXMatrixInverse(&invView, NULL, &invView);


			Count++;
		}
	}
	else if (StartBilboard)
	{
		D3DXVECTOR3 Camera = camera->GetPosition();
		D3DXVECTOR3 dir = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		D3DXMatrixLookAtLH(&EviewMatrix, &Camera, &m_Position
			, &dir);
		view = EviewMatrix;	
	
		D3DXMatrixIdentity(&invView);
		invView._11 = view._11;
		invView._13 = view._13;
		invView._31 = view._31;
		invView._33 = view._33;
		D3DXMatrixInverse(&invView, NULL, &invView);

	}
	world = scale * invView * trans1 * destroyrot * trans2 * trans;

	golemheadworld = golemheadscale * golemheadtrans;
	airheadboxworld = airheadboxscale * airheadboxtrans;
	bossworld = scale * invView  * destroyrot * trans;
	golemboxworld = golemboxscale * rot * trans;

	wolfboxworld = wolfboxscale * rot * wolfboxtrans;
	headworld = headscale * headtrans;

	tankboxworld = tankboxscale * rot * tankboxtrans;
	tankheadworld = tankheadscale * rot * tankheadtrans;
	airboxworld = airboxscale * airboxtrans;
	CRenderer::SetWorldMatrix(&world);
	


	
	//ƒeƒNƒX?ƒƒÝ’è
	CCamera* Camera = CManager::GetScene()->GetGameObject<CCamera>(0);
	D3DXVECTOR3 Savevec = m_Position - Camera->GetPosition();
	float length = D3DXVec3Length(&Savevec);
	if (length < 100.0f)
	{
		if (Type == TYPE_GOLEM)
		{
			assert(Golem_Texture);
			CRenderer::GetDeviceContext()->PSSetShaderResources(0, 1, &Golem_Texture);
			Golem_Model->Draw();


		}
		else if (Type == TYPE_WOLF)
		{
			assert(Wolf_Texture);
			CRenderer::GetDeviceContext()->PSSetShaderResources(0, 1, &Wolf_Texture);
			Wolf_Model->Draw();

		}
		else if (Type == TYPE_AIRPLANE)
		{
			assert(Wolf_Texture);
			CRenderer::GetDeviceContext()->PSSetShaderResources(0, 1, &Wolf_Texture);
			Airplane_Model->Draw();

		}
		else if (Type == TYPE_TANK)
		{
			CRenderer::SetWorldMatrix(&bossworld);
			assert(Wolf_Texture);
			CRenderer::GetDeviceContext()->PSSetShaderResources(0, 1, &Wolf_Texture);
			Tank_Model->Draw();

		}
	}



}


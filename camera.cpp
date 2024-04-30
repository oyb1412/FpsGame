#include "main.h"
#include "renderer.h"
#include "Player.h"
#include "manager.h"
#include "renderer.h"
#include "camera.h"
#include "scene.h"
#include "input.h"
#include "Mouse.h"
#include "sound.h"
#include "item.h"
#include "box.h"
#include "Fade.h"
#include "title.h"
#include "stage1.h"
#include "stage2.h"
#include "stage3.h"
#include "stage4.h"
#include "stage5.h"
#include <cstdlib>
#include <stdlib.h>
#include <time.h>
#include "pattern.h"
void CCamera::Init()
{
	m_Front = D3DXVECTOR3(0.0f, 0.0f, 1.0f);
	g_vecFront = D3DXVECTOR3(0.0f, 0.0f, 1.0f);
	g_vecRight = D3DXVECTOR3(1.0f, 0.0f, 0.0f);
	g_vecUp = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	vecDir = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_Position = D3DXVECTOR3(-80.0f, 4.5f, -275.0f);
	m_Target = m_Position + g_vecFront;
	g_Box = new CBox();
	g_Box->Init();
	SmallGunShot_Turm = 0;
	ShotGunShot_Turm = 0;
	RifleGunShot_Turm = 0;
	BazookaShot_Turm = 0;

	SmallGun_Shot = false;
	ShotGun_Shot = false;
	RifleGun_Shot = false;
	m_Scale = D3DXVECTOR3(1.0f, 1.0f, 1.0f);
	StopRightMove = false;
	StopLeftMove = false;
	StopFrontMove = false;
	StopBehindMove = false;
	BeginTeleport = false;
	StartJump = false;
	JumpDown = false;
	Gravity = 0.1f;
	JumpCount = 0;
	if (CManager::SceneGet<CStage2>())
	{
		D3DXMATRIX mtxRotation;
		D3DXMatrixRotationY(&mtxRotation, D3DXToRadian(90.0f));
		D3DXVec3TransformNormal(&g_vecFront, &g_vecFront, &mtxRotation);
		D3DXVec3TransformNormal(&g_vecRight, &g_vecRight, &mtxRotation);
	}
	BossStart = false;
}

void CCamera::Uninit()
{
	g_Box->Uninit();
	delete g_Box;
}

void CCamera::Update()
{
	CScene* scene = CManager::GetScene();
	CFade* Fade = CManager::GetScene()->GetGameObject<CFade>(19);
	
	StepCount--;

	if (Type == TYPE_SETTING)
	{
		if (!StartJump)
		{
			m_Position.y -= Gravity;
		}
		if (!BeginTeleport)
		{
			if (StartJump && CManager::SceneGet<CStage4>())
			{
				JumpCounting++;
				if (JumpCounting == 1)
				{
					PlaySoundA(SOUND_LABEL_SE_JUMPDAI);

				}
				if (m_Position.y < 13.0f)
				{
					m_Position.y += 0.4f;
				}
				if (m_Position.z < 455.0f)
				{
					m_Position.z += 0.7f;
				}
				if (m_Position.y >= 13.0f)
				{
					JumpDown = true;
				}
				if (JumpDown && m_Position.y > 4.5f)
				{
					m_Position.y -= 0.6f;
				}
				if (JumpDown && m_Position.y <= 4.5f && m_Position.z >= 455.0f)
				{
					m_Position.y = 4.5f;
					m_Position.z = 455.0f;
					StartJump = false;
					JumpDown = false;
				}
			}
			if (StartJump && CManager::SceneGet<CStage3>())
			{
				JumpCounting++;
				if (JumpCounting == 1)
				{
					PlaySoundA(SOUND_LABEL_SE_JUMPDAI);

				}
				if (m_Position.y < 11.0f)
				{
					m_Position.y += 0.3f;
				}
				if (m_Position.z < 243.0f)
				{
					m_Position.z += 0.5f;
				}
				if (m_Position.y >= 11.0f)
				{
					JumpDown = true;
				}
				if (JumpDown && m_Position.y > 9.5f)
				{
					m_Position.y -= 0.55f;
				}
				if (JumpDown && m_Position.y <= 9.5f && m_Position.z >= 243.0f)
				{
					StartJump = false;
					JumpDown = false;
				}
			}
			if (!StartJump)
			{
				D3DXMATRIX mtxRotation;
				D3DXVec3Normalize(&vecDir, &vecDir);
				D3DXVec3Normalize(&g_vecFront, &g_vecFront);
				D3DXVec3Normalize(&g_vecRight, &g_vecRight);

				std::vector<CItem*> ItemList = CManager::GetScene()->GetGameObjects<CItem>(9);
				CPlayer* Player = CManager::GetScene()->GetGameObject<CPlayer>(2);
				CPolygon* CursorPolygon = CManager::GetScene()->GetGameObject<CPolygon>(15);
				JumpCount++;


				if (Gravity < 0.1f)
				{
					Gravity += 0.07f;
					if (Gravity >= 0.1f)
					{
						Gravity = 0.1f;
					}
				}

				if (BackPosition)
				{
					BackMoveCount++;
				}

				if (BackPosition && BackMoveCount < 20)
				{
					m_Position.x += (-g_vecFront.x * 0.1f);
					m_Position.z += (-g_vecFront.z * 0.1f);

				}
				if (BackPosition && BackMoveCount >= 20)
				{
					BackPosition = false;
					BackMoveCount = 0;
				}
				{//アイテ?取得
					for (CItem* Item : ItemList)
					{
						D3DXVECTOR3 ItemVector = Item->GetPosition();
						D3DXVECTOR3 direction = m_Position - ItemVector;

						float length = D3DXVec3Length(&direction);

						if (length < 3.0f && Item->GetType() == TYPE_ITEM_BULLET)
						{

							Player->GetBullet();
							PlaySoundA(SOUND_LABEL_SE_GET_BULLET);
							Item->SetDestroy();
							scene->AddGameObject<CFade>(19)->SetObject(D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(50.0f, 50.0f, 0.0f), FADE_WHITE);
							return;
						}
						if (length < 3.0f && Item->GetType() == TYPE_ITEM_HEART)
						{
							if (Player->GetPlayerHp() < 100)
							{
								Player->GetHp();
							}
							PlaySoundA(SOUND_LABEL_SE_GET_HP);
							Item->SetDestroy();
							scene->AddGameObject<CFade>(19)->SetObject(D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(50.0f, 50.0f, 0.0f), FADE_WHITE);

							return;
						}
						if (length < 3.0f && Item->GetType() == TYPE_ITEM_KEY)
						{
							C3dpolygon* S3_Door1 = CManager::GetScene()->GetGameObject<C3dpolygon>(1);
							S3_Door1->SetOpenDoor();
							Player->SetKey();
							PlaySoundA(SOUND_LABEL_SE_GET_KEY);
							PlaySoundA(SOUND_LABEL_SE_PATTERNONE);
							Item->SetDestroy();
							scene->AddGameObject<CFade>(19)->SetObject(D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(50.0f, 50.0f, 0.0f), FADE_WHITE);

							return;
						}
					}
				}
				vecDir.y = 0.0f;
				vecDir = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
				
			
				{//武器変換
					if ((CInput::GetKeyPress('1')) && Player->GetWeaponType() != SMALLGUN && SmallGun_Shot == false && ShotGun_Shot == false && RifleGun_Shot == false &&Bazooka_Shot == false && !Player->GetReroad() && !Player->GetWeaponChange())
					{
						Player->ChangeWeapon(SMALLGUN);
						Player->SetWeaponChange();
						CursorPolygon->SetCursor(0);
					}
					if ((CInput::GetKeyPress('2')) && Player->GetWeaponType() != SHOTGUN && SmallGun_Shot == false && ShotGun_Shot == false && RifleGun_Shot == false && Bazooka_Shot == false && !Player->GetReroad() && !Player->GetWeaponChange() && Player->SetShotGun())
					{
						Player->ChangeWeapon(SHOTGUN);
						Player->SetWeaponChange();
						CursorPolygon->SetCursor(1);
					}
					if ((CInput::GetKeyPress('3')) && Player->GetWeaponType() != RIFLEGUN && SmallGun_Shot == false && ShotGun_Shot == false && RifleGun_Shot == false && Bazooka_Shot == false && !Player->GetReroad() && !Player->GetWeaponChange() && Player->SetRifleGun())
					{
						Player->ChangeWeapon(RIFLEGUN);
						Player->SetWeaponChange();
						CursorPolygon->SetCursor(2);
					}
					if ((CInput::GetKeyPress('4')) && Player->GetWeaponType() != BAZOOKA && SmallGun_Shot == false && ShotGun_Shot == false && RifleGun_Shot == false && Bazooka_Shot == false && !Player->GetReroad() && !Player->GetWeaponChange() && Player->SetBazooka())
					{
						Player->ChangeWeapon(BAZOOKA);
						Player->SetWeaponChange();
						CursorPolygon->SetCursor(3);
					}

					if ( InputMouse::WhillMouseUp() && Player->GetWeaponType() == SMALLGUN && SmallGun_Shot == false && ShotGun_Shot == false && RifleGun_Shot == false && Bazooka_Shot == false && !Player->GetReroad() && !Player->GetWeaponChange() && Player->SetShotGun())
					{
						Player->ChangeWeapon(SHOTGUN);
						Player->SetWeaponChange();
						CursorPolygon->SetCursor(1);
					}
					if (InputMouse::WhillMouseUp() && Player->GetWeaponType() == SHOTGUN && SmallGun_Shot == false && ShotGun_Shot == false && RifleGun_Shot == false && Bazooka_Shot == false && !Player->GetReroad() && !Player->GetWeaponChange() && Player->SetRifleGun())
					{
						Player->ChangeWeapon(RIFLEGUN);
						Player->SetWeaponChange();
						CursorPolygon->SetCursor(2);
					}
					if (InputMouse::WhillMouseDown() && Player->GetWeaponType() == SHOTGUN && SmallGun_Shot == false && ShotGun_Shot == false && RifleGun_Shot == false && Bazooka_Shot == false && !Player->GetReroad() && !Player->GetWeaponChange())
					{
						Player->ChangeWeapon(SMALLGUN);
						Player->SetWeaponChange();
						CursorPolygon->SetCursor(0);
					}
					if (InputMouse::WhillMouseDown() && Player->GetWeaponType() == RIFLEGUN && SmallGun_Shot == false && ShotGun_Shot == false && RifleGun_Shot == false && Bazooka_Shot == false && !Player->GetReroad() && !Player->GetWeaponChange() && Player->SetShotGun())
					{
						Player->ChangeWeapon(SHOTGUN);
						Player->SetWeaponChange();
						CursorPolygon->SetCursor(1);
					}
					if (InputMouse::WhillMouseUp() && Player->GetWeaponType() == RIFLEGUN && SmallGun_Shot == false && ShotGun_Shot == false && RifleGun_Shot == false && Bazooka_Shot == false && !Player->GetReroad() && !Player->GetWeaponChange() && Player->SetBazooka())
					{
						Player->ChangeWeapon(BAZOOKA);
						Player->SetWeaponChange();
						CursorPolygon->SetCursor(3);
					}
					if (InputMouse::WhillMouseDown() && Player->GetWeaponType() == BAZOOKA && SmallGun_Shot == false && ShotGun_Shot == false && RifleGun_Shot == false && Bazooka_Shot == false && !Player->GetReroad() && !Player->GetWeaponChange() )
					{
						Player->ChangeWeapon(RIFLEGUN);
						Player->SetWeaponChange();
						CursorPolygon->SetCursor(2);
					}
				}
				if (!GetPatternStopMove())
				{
					
						if (CInput::GetKeyPress(VK_SPACE) && JumpCount > 0 && m_Position.y >= 3.0f)
						{
							Gravity = -0.4f;
							JumpCount = -30;
							PlaySoundA(SOUND_LABEL_SE_JUMP);
						}
					
					if (CInput::GetKeyPress('A'))
					{
						vecDir = -g_vecRight;
						if (StepCount < 0)
						{
							PlaySoundA(SOUND_LABEL_SE_STEP);
							StepCount = 20;
						}

					}
					if (CInput::GetKeyPress('D'))
					{
						vecDir = g_vecRight;
						if (StepCount < 0)
						{
							PlaySoundA(SOUND_LABEL_SE_STEP);
							StepCount = 20;
						}
					}
					if (CInput::GetKeyPress('S'))
					{
						vecDir = -g_vecFront;
						if (StepCount < 0)
						{
							PlaySoundA(SOUND_LABEL_SE_STEP);
							StepCount = 20;
						}
					
					}

					if (CInput::GetKeyPress('W'))
					{
						vecDir = g_vecFront;
						if (StepCount < 0)
						{
							PlaySoundA(SOUND_LABEL_SE_STEP);
							StepCount = 20;
						}
					
					}
				}


				

				if (Player->GetWeaponType() == SMALLGUN)
				{
					if (SmallGun_Shot)
					{
						SmallGunShot_Turm++;
					}
					if (SmallGunShot_Turm > 25)
					{
						SmallGun_Shot = false;
						SmallGunShot_Turm = 0;
					}
					if (CInput::GetKeyPress('R') && Player->GetBulletNumber(SMALLGUN) < 20 && Player->GetMaxBulletNumber(SMALLGUN) > 0 && !Player->GetReroad() && !Player->GetWeaponChange())
					{
						PlaySoundA(SOUND_LABEL_SE_SMALLGUN_REROAD);
						Player->Begin_Reroad();
						scene->AddGameObject<CPolygon>(14)->SetObject(D3DXVECTOR3(SCREEN_WIDTH *0.5f - 50.0f, SCREEN_HEIGHT *0.8f, 0.0f), D3DXVECTOR3(1.5f, 0.2f, 1.5f), GAGE_GRAY_TEXTURE);
						scene->AddGameObject<CPolygon>(14)->SetObject(D3DXVECTOR3(SCREEN_WIDTH *0.5f - 50.0f, SCREEN_HEIGHT *0.8f, 0.0f), D3DXVECTOR3(1.5f, 0.2f, 1.5f), GAGE_GREEN_TEXTURE);

					}

					if (!BossStart &&InputMouse::PushLeft() && SmallGun_Shot == false && Player->GetBulletNumber(SMALLGUN) > 0 && !Player->GetReroad() && !Player->GetWeaponChange() && Player->SetSmallGun())
					{

						Player->MinusBulletNumber(SMALLGUN);
						Player->SetAngle();
						PlaySoundA(SOUND_LABEL_SE_SMALLGUN_SHOT);
						scene->AddGameObject<CBullet>(8)->SetObject(m_Position, D3DXVECTOR3(0.3f, 0.1f, 0.3f), SMALLGUN_BULLET);

						scene->AddGameObject<CExplosion>(9)->SetTexture(GUN_SHOT_EFFECT, GUN_SHOT_EFFECT_X, GUN_SHOT_EFFECT_Y, m_Position + (g_vecFront * 2), D3DXVECTOR3(0.35f, 0.35f, 0.0f));

						SmallGun_Shot = true;
					}
					if (InputMouse::PushLeft() && SmallGun_Shot == false && Player->GetBulletNumber(SMALLGUN) == 0 && !Player->GetReroad() && Player->GetMaxBulletNumber(SMALLGUN) > 0 && !Player->GetWeaponChange())
					{
						PlaySoundA(SOUND_LABEL_SE_SMALLGUN_REROAD);
						Player->Begin_Reroad();
						scene->AddGameObject<CPolygon>(14)->SetObject(D3DXVECTOR3(SCREEN_WIDTH *0.5f - 50.0f, SCREEN_HEIGHT *0.8f, 0.0f), D3DXVECTOR3(1.5f, 0.2f, 1.5f), GAGE_GRAY_TEXTURE);
						scene->AddGameObject<CPolygon>(14)->SetObject(D3DXVECTOR3(SCREEN_WIDTH *0.5f - 50.0f, SCREEN_HEIGHT *0.8f, 0.0f), D3DXVECTOR3(1.5f, 0.2f, 1.5f), GAGE_GREEN_TEXTURE);

						SmallGun_Shot = true;
					}
				}
				if (Player->GetWeaponType() == SHOTGUN)
				{
					if (ShotGun_Shot)
					{
						ShotGunShot_Turm++;
					}
					if (ShotGunShot_Turm > 50)
					{
						ShotGun_Shot = false;
						ShotGunShot_Turm = 0;
					}
					if (CInput::GetKeyPress('R') && Player->GetBulletNumber(SHOTGUN) < 10 && Player->GetMaxBulletNumber(SHOTGUN) > 0 && !Player->GetReroad() && !Player->GetWeaponChange())
					{
						PlaySoundA(SOUND_LABEL_SE_SHOTGUN_REROAD);
						Player->Begin_Reroad();
						scene->AddGameObject<CPolygon>(14)->SetObject(D3DXVECTOR3(SCREEN_WIDTH / 2 - 150, SCREEN_HEIGHT / 2 + 350, 0.0f), D3DXVECTOR3(1.5f, 0.2f, 1.5f), GAGE_GRAY_TEXTURE);
						scene->AddGameObject<CPolygon>(14)->SetObject(D3DXVECTOR3(SCREEN_WIDTH / 2 - 150, SCREEN_HEIGHT / 2 + 350, 0.0f), D3DXVECTOR3(1.5f, 0.2f, 1.5f), GAGE_GREEN_TEXTURE);
					}
					if (!BossStart &&InputMouse::PushLeft() && ShotGun_Shot == false && Player->GetBulletNumber(SHOTGUN) > 0 && !Player->GetReroad() && !Player->GetWeaponChange())
					{
						Player->SetAngle();

						Player->MinusBulletNumber(SHOTGUN);
						PlaySoundA(SOUND_LABEL_SE_SHOTGUN_SHOT);
						scene->AddGameObject<CBullet>(8)->SetObject(m_Position, D3DXVECTOR3(0.3f, 1.0f, 0.3f), SHOTGUN_BULLET);
						scene->AddGameObject<CBullet>(8)->SetObject(m_Position, D3DXVECTOR3(0.3f, 1.0f, 0.3f), SHOTGUN_BULLET2);
						scene->AddGameObject<CBullet>(8)->SetObject(m_Position, D3DXVECTOR3(0.3f, 1.0f, 0.3f), SHOTGUN_BULLET3);
						scene->AddGameObject<CBullet>(8)->SetObject(m_Position, D3DXVECTOR3(0.3f, 1.0f, 0.3f), SHOTGUN_BULLET4);



						scene->AddGameObject<CExplosion>(9)->SetTexture(SHOTGUN_SHOT_EFFECT, GUN_SHOT_EFFECT_X, GUN_SHOT_EFFECT_Y, D3DXVECTOR3(m_Position.x + (g_vecFront.x * 2), (m_Position.y + (g_vecFront.y) * 2), m_Position.z + (g_vecFront.z * 2)), D3DXVECTOR3(0.7f, 0.7f, 0.0f));

						ShotGun_Shot = true;
					}
					if (InputMouse::PushLeft() && ShotGun_Shot == false && Player->GetBulletNumber(SHOTGUN) == 0 && !Player->GetReroad() && Player->GetMaxBulletNumber(SHOTGUN) > 0 && !Player->GetWeaponChange())
					{
						PlaySoundA(SOUND_LABEL_SE_SHOTGUN_REROAD);
						Player->Begin_Reroad();
						scene->AddGameObject<CPolygon>(14)->SetObject(D3DXVECTOR3(SCREEN_WIDTH / 2 - 150, SCREEN_HEIGHT / 2 + 350, 0.0f), D3DXVECTOR3(1.5f, 0.2f, 1.5f), GAGE_GRAY_TEXTURE);
						scene->AddGameObject<CPolygon>(14)->SetObject(D3DXVECTOR3(SCREEN_WIDTH / 2 - 150, SCREEN_HEIGHT / 2 + 350, 0.0f), D3DXVECTOR3(1.5f, 0.2f, 1.5f), GAGE_GREEN_TEXTURE);
						ShotGun_Shot = true;
					}
				}
				if (Player->GetWeaponType() == RIFLEGUN)
				{
					if (RifleGun_Shot)
					{
						RifleGunShot_Turm++;
					}
					if (RifleGunShot_Turm > 8)
					{
						RifleGun_Shot = false;
						RifleGunShot_Turm = 0;
					}
					if (CInput::GetKeyPress('R') && Player->GetBulletNumber(RIFLEGUN) < 30 && Player->GetMaxBulletNumber(RIFLEGUN) > 0 && !Player->GetReroad() && !Player->GetWeaponChange())
					{
						PlaySoundA(SOUND_LABEL_SE_RIFLEGUN_REROAD);
						Player->Begin_Reroad();
						scene->AddGameObject<CPolygon>(14)->SetObject(D3DXVECTOR3(SCREEN_WIDTH / 2 - 150, SCREEN_HEIGHT / 2 + 350, 0.0f), D3DXVECTOR3(1.5f, 0.2f, 1.5f), GAGE_GRAY_TEXTURE);
						scene->AddGameObject<CPolygon>(14)->SetObject(D3DXVECTOR3(SCREEN_WIDTH / 2 - 150, SCREEN_HEIGHT / 2 + 350, 0.0f), D3DXVECTOR3(1.5f, 0.2f, 1.5f), GAGE_GREEN_TEXTURE);
					}
					if (!BossStart &&InputMouse::PushLeft() && RifleGun_Shot == false && Player->GetBulletNumber(RIFLEGUN) > 0 && !Player->GetReroad() && !Player->GetWeaponChange())
					{
						Player->MinusBulletNumber(RIFLEGUN);
						PlaySoundA(SOUND_LABEL_SE_RIFLEGUN_SHOT);
						scene->AddGameObject<CBullet>(8)->SetObject(m_Position, D3DXVECTOR3(0.3f, 1.0f, 0.3f), RIFLEGUN_BULLET);
						scene->AddGameObject<CExplosion>(9)->SetTexture(RIFLEGUN_SHOT_EFFECT, GUN_SHOT_EFFECT_X, GUN_SHOT_EFFECT_Y, m_Position + (g_vecFront * 2), D3DXVECTOR3(0.25f, 0.25f, 0.0f));
						RifleGun_Shot = true;
					}

				}
				if (Player->GetWeaponType() == BAZOOKA)
				{
					if (Bazooka_Shot)
					{
						BazookaShot_Turm++;
					}
					if (BazookaShot_Turm > 100)
					{
						Bazooka_Shot = false;
						BazookaShot_Turm = 0;
					}
					if (CInput::GetKeyPress('R') && Player->GetBulletNumber(BAZOOKA) < 5 && Player->GetMaxBulletNumber(BAZOOKA) > 0 && !Player->GetReroad() && !Player->GetWeaponChange())
					{
						PlaySoundA(SOUND_LABEL_SE_SHOTGUN_REROAD);
						Player->Begin_Reroad();
						scene->AddGameObject<CPolygon>(14)->SetObject(D3DXVECTOR3(SCREEN_WIDTH / 2 - 150, SCREEN_HEIGHT / 2 + 350, 0.0f), D3DXVECTOR3(1.5f, 0.2f, 1.5f), GAGE_GRAY_TEXTURE);
						scene->AddGameObject<CPolygon>(14)->SetObject(D3DXVECTOR3(SCREEN_WIDTH / 2 - 150, SCREEN_HEIGHT / 2 + 350, 0.0f), D3DXVECTOR3(1.5f, 0.2f, 1.5f), GAGE_GREEN_TEXTURE);
					}
					if (!BossStart &&InputMouse::PushLeft() && Bazooka_Shot == false && Player->GetBulletNumber(BAZOOKA) > 0 && !Player->GetReroad() && !Player->GetWeaponChange())
					{
						Player->SetAngle();

						Player->MinusBulletNumber(BAZOOKA);
						PlaySoundA(SOUND_LABEL_SE_BAZOOKA_SHOT);
						scene->AddGameObject<CBullet>(8)->SetObject(m_Position, D3DXVECTOR3(1.5f, 1.5f, 1.5f), BAZOOKA_BULLET);
					




						Bazooka_Shot = true;
					}
					if (InputMouse::PushLeft() && Bazooka_Shot == false && Player->GetBulletNumber(BAZOOKA) == 0 && !Player->GetReroad() && Player->GetMaxBulletNumber(BAZOOKA) > 0 && !Player->GetWeaponChange())
					{
						PlaySoundA(SOUND_LABEL_SE_SHOTGUN_REROAD);
						Player->Begin_Reroad();
						scene->AddGameObject<CPolygon>(14)->SetObject(D3DXVECTOR3(SCREEN_WIDTH / 2 - 150, SCREEN_HEIGHT / 2 + 350, 0.0f), D3DXVECTOR3(1.5f, 0.2f, 1.5f), GAGE_GRAY_TEXTURE);
						scene->AddGameObject<CPolygon>(14)->SetObject(D3DXVECTOR3(SCREEN_WIDTH / 2 - 150, SCREEN_HEIGHT / 2 + 350, 0.0f), D3DXVECTOR3(1.5f, 0.2f, 1.5f), GAGE_GREEN_TEXTURE);
						Bazooka_Shot = true;
					}
				}

				{//?ウス
					if (InputMouse::m_ptMouse.x > 0)
					{
						D3DXMatrixRotationY(&mtxRotation, D3DXToRadian(InputMouse::m_ptMouse.x / 4));
						D3DXVec3TransformNormal(&g_vecFront, &g_vecFront, &mtxRotation);
						D3DXVec3TransformNormal(&g_vecUp, &g_vecUp, &mtxRotation);
						D3DXVec3TransformNormal(&g_vecRight, &g_vecRight, &mtxRotation);
					}
					if (InputMouse::m_ptMouse.x < 0)
					{
						D3DXMatrixRotationY(&mtxRotation, D3DXToRadian(InputMouse::m_ptMouse.x / 4));
						D3DXVec3TransformNormal(&g_vecFront, &g_vecFront, &mtxRotation);
						D3DXVec3TransformNormal(&g_vecUp, &g_vecUp, &mtxRotation);
						D3DXVec3TransformNormal(&g_vecRight, &g_vecRight, &mtxRotation);
					}

					if (InputMouse::m_ptMouse.y < 0 && g_vecFront.y < 0.1f)
					{
						D3DXMatrixRotationAxis(&mtxRotation, &g_vecRight, D3DXToRadian(InputMouse::m_ptMouse.y / 4));
						D3DXVec3TransformNormal(&g_vecFront, &g_vecFront, &mtxRotation);
						D3DXVec3TransformNormal(&g_vecUp, &g_vecUp, &mtxRotation);
						D3DXVec3TransformNormal(&g_vecRight, &g_vecRight, &mtxRotation);
					}
					if (InputMouse::m_ptMouse.y > 0 && g_vecFront.y > -0.3f)
					{
						D3DXMatrixRotationAxis(&mtxRotation, &g_vecRight, D3DXToRadian(InputMouse::m_ptMouse.y / 4));
						D3DXVec3TransformNormal(&g_vecFront, &g_vecFront, &mtxRotation);
						D3DXVec3TransformNormal(&g_vecUp, &g_vecUp, &mtxRotation);
						D3DXVec3TransformNormal(&g_vecRight, &g_vecRight, &mtxRotation);
					}

				}
				if (CantRightMove)
				{
					if (vecDir.x > 0)
					{
						vecDir.x = 0;
					}
				}
				if (CantLeftMove)
				{
					if (vecDir.x < 0)
					{
						vecDir.x = 0;
					}
				}
				if (CantFrontMove)
				{
					if (vecDir.z > 0)
					{
						vecDir.z = 0;
					}
				}
				if (CantBackMove)
				{
					if (vecDir.z < 0)
					{
						vecDir.z = 0;
					}
				}


				m_Position.x += vecDir.x * PLAYER_SPEED;
				if (!StopFrontMove && !StopBehindMove )
				{
					m_Position.z += vecDir.z * PLAYER_SPEED;
				}
				if (StopFrontMove && vecDir.z > 0.0f)
				{
					m_Position.z += 0;
				}
				if (StopFrontMove && vecDir.z < 0.0f)
				{
					m_Position.z += vecDir.z * PLAYER_SPEED;
					StopFrontMove = false;
				}

			
				if (StopBehindMove && vecDir.z < 0.0f)
				{
					m_Position.z -= 0;
				}
				if (StopBehindMove && vecDir.z > 0.0f)
				{
					m_Position.z += vecDir.z * PLAYER_SPEED;
					StopBehindMove = false;
				}

			}
			m_Target = m_Position + (g_vecFront);
			g_Box->Update(m_Position, m_Min, m_Max);
		}
		}
	

	
}
void CCamera::Transparent()
{

}
void CCamera::Draw()
{

	D3DXVECTOR3 Pup = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	D3DXMatrixLookAtLH(&viewMatrix, &m_Position, &m_Target
		, &Pup);

	CRenderer::SetViewMatrix(&viewMatrix);

	D3DXMATRIX projectionMatrix;

	D3DXMatrixPerspectiveFovLH(&projectionMatrix, 1.0f,
	(float)SCREEN_WIDTH / SCREEN_HEIGHT, 0.1f, 500.0f);

	CRenderer::SetProjectionMatrix(&projectionMatrix);

	D3DXMATRIX world, scale, rot, trans;
	D3DXMatrixScaling(&scale, m_Scale.x, m_Scale.y, m_Scale.z);
	D3DXMatrixRotationYawPitchRoll(&rot, m_Rotation.y, m_Rotation.x, m_Rotation.z);
	D3DXMatrixTranslation(&trans, m_Position.x, m_Position.y, m_Position.z);
	world = scale * rot * trans;
	CRenderer::SetWorldMatrix(&world);
	g_Box->Draw(&world,1);

}

#include "main.h"
#include "manager.h"
#include "renderer.h"
#include "model.h"
#include "bullet.h"
#include "Player.h"
#include "box.h"
#include "input.h"
#include "scene.h"
#include "camera.h"
#include "sound.h"
#include "Mouse.h"
#include "Polygon.h"
#include "3dpolygon.h"
#include "stage1.h"
#include "stage2.h"
#include "stage3.h"
#include "stage4.h"
#include "stage5.h"
#include "Stage6.h"
#include "pattern.h"
#include "warning.h"
static int Pattern_Number = 0;
static int CreateEnemy_Count = 0;
static bool Tutorial_Move[5] = { false};
static bool Pattern_StopMove = false;
static int Count = 0;
static int EnemyCount = 0;
void PatternReset()
{
	Pattern_Number = 0;
	CreateEnemy_Count = 0;
	EnemyCount = 0;
	for (int i = 0; i < 5; i++)
	{
		Tutorial_Move[i] = false;
	}
	 Pattern_StopMove = false;
	Count = 0;
}
void Pattern_Update()
{
	CCamera* Camera = CManager::GetScene()->GetGameObject<CCamera>(0);
	CScene* scene = CManager::GetScene();
	CPlayer* Player = CManager::GetScene()->GetGameObject<CPlayer>(2);
	
	if (CManager::SceneGet<CStage3>())
	{
		switch (Pattern_Number)
		{
		case 0:
		{
			if (Camera->GetPosition().z < -90.0f)
			{
				StopSound();
				PlaySoundA(SOUND_LABEL_TUTORIAL_BGM);

				scene->AddGameObject<CPolygon>(10)->SetObject(D3DXVECTOR3(SCREEN_WIDTH * 0.55f, SCREEN_HEIGHT *0.3f, 0.0f), D3DXVECTOR3(6.0f, 2.0f, 0.0f), TUTORIAL_SPACE);

				scene->AddGameObject<CPolygon>(12)->SetObject(D3DXVECTOR3(SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT *0.3f, 0.0f), D3DXVECTOR3(5.0f, 2.0f, 0.0f), TUTORIAL_LOGO1_TEXTURE);

				Pattern_StopMove = true;
				Pattern_Number = 1;
			}
			break;
		}
		case 1:
		{
			if (InputMouse::PushLeft())
			{
				CPolygon* Tutorial_Logo1 = CManager::GetScene()->GetGameObject<CPolygon>(12);
				Tutorial_Logo1->SetDestroy();
				scene->AddGameObject<CPolygon>(13)->SetObject(D3DXVECTOR3(SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT *0.3f, 0.0f), D3DXVECTOR3(5.0f, 2.0f, 0.0f), TUTORIAL_LOGO2_TEXTURE);
				Pattern_StopMove = false;

				Pattern_Number = 2;

			}
			break;
		}
		case 2:
		{
			if (CInput::GetKeyPress('W'))
			{
				Tutorial_Move[0] = true;
			}
			if (CInput::GetKeyPress('S'))
			{
				Tutorial_Move[1] = true;

			}
			if (CInput::GetKeyPress('A'))
			{
				Tutorial_Move[2] = true;

			}
			if (CInput::GetKeyPress('D'))
			{
				Tutorial_Move[3] = true;
			}
			if (CInput::GetKeyPress(VK_SPACE))
			{
				Tutorial_Move[4] = true;
			}
			if (Tutorial_Move[0] == true && Tutorial_Move[1] == true && Tutorial_Move[2] == true && Tutorial_Move[3] == true && Tutorial_Move[4] == true)
			{
				PlaySoundA(SOUND_LABEL_SE_PATTERNONE);
				Pattern_Number = 3;
			}
			break;
		}
		case 3:
		{
			CPolygon* Tutorial_Logo2 = CManager::GetScene()->GetGameObject<CPolygon>(13);
			Tutorial_Logo2->SetDestroy();
			scene->AddGameObject<CPolygon>(14)->SetObject(D3DXVECTOR3(SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT *0.3f, 0.0f), D3DXVECTOR3(5.0f, 1.0f, 0.0f), TUTORIAL_LOGO3_TEXTURE);
			Pattern_Number = 4;
			break;
		}
		case 4:
		{
			C3dpolygon* Tutorial_Door1 = CManager::GetScene()->GetGameObject<C3dpolygon>(5);
			Tutorial_Door1->SetOpenDoor();
			Pattern_Number = 5;
			break;
		}
		case 5:
		{
			if (Camera->GetPosition().z > -55.0f)
			{
				CPolygon* Tutorial_Logo3 = CManager::GetScene()->GetGameObject<CPolygon>(14);
				Tutorial_Logo3->SetDestroy();
				scene->AddGameObject<CPolygon>(15)->SetObject(D3DXVECTOR3(SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT *0.3f, 0.0f), D3DXVECTOR3(5.0f, 2.0f, 0.0f), TUTORIAL_LOGO4_TEXTURE);
				Pattern_StopMove = true;
				Pattern_Number = 6;
			}
			break;
		}
		case 6:
		{
			if (InputMouse::PushLeft())
			{
				CPolygon* Tutorial_Logo4 = CManager::GetScene()->GetGameObject<CPolygon>(15);
				Tutorial_Logo4->SetDestroy();
				scene->AddGameObject<CExplosion>(9)->SetTexture(SUMMON_LONG, CREATE_EFFECT_X, CREATE_EFFECT_Y, D3DXVECTOR3(55.0f, 5.6f, -25.0f), D3DXVECTOR3(5.0f, 4.0f, 0.0f));


				CPolygon* Tutorial_Space = CManager::GetScene()->GetGameObject<CPolygon>(10);
				Tutorial_Space->SetDestroy();
				Pattern_StopMove = false;
				Pattern_Number = 7;
			}
			break;
		}
		case 7:
		{
			CreateEnemy_Count++;
			if (CreateEnemy_Count > 150)
			{
				Pattern_Number = 8;
			}
			break;
		}
		case 8:
		{
			std::vector<CEnemy*> EnemyList = CManager::GetScene()->GetGameObjects<CEnemy>(8);
			if (EnemyList.size() < 2)
			{
				C3dpolygon* Tutorial_Door2 = CManager::GetScene()->GetGameObject<C3dpolygon>(6);
				scene->AddGameObject<CPolygon>(16)->SetObject(D3DXVECTOR3(SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT *0.3f, 0.0f), D3DXVECTOR3(5.0f, 1.0f, 0.0f), TUTORIAL_LOGO5_TEXTURE);
				scene->AddGameObject<CPolygon>(10)->SetObject(D3DXVECTOR3(SCREEN_WIDTH * 0.55f, SCREEN_HEIGHT *0.3f, 0.0f), D3DXVECTOR3(6.0f, 2.0f, 0.0f), TUTORIAL_SPACE);
				PlaySoundA(SOUND_LABEL_SE_PATTERNONE);
				Tutorial_Door2->SetOpenDoor();
				Pattern_Number = 9;

			}
			break;
		}
		case 9:
		{
			if (Camera->GetPosition().z > 0)
			{
				CPolygon* Tutorial_Logo5 = CManager::GetScene()->GetGameObject<CPolygon>(16);
				Tutorial_Logo5->SetDestroy();
				CPolygon* Tutorial_Space = CManager::GetScene()->GetGameObject<CPolygon>(10);
				Tutorial_Space->SetDestroy();
				StopSound();
				PlaySoundA(SOUND_LABEL_STAGE1_BGM);
				Pattern_Number = 10;
			}
			break;
		}
		case 10:
		{
			if (Camera->GetPosition().z >= 20.0f)
			{
				scene->AddGameObject<CExplosion>(9)->SetTexture(SUMMON_LONG, CREATE_EFFECT_X, CREATE_EFFECT_Y, D3DXVECTOR3(45.0f, 5.6f, 90.0f), D3DXVECTOR3(5.0f, 4.0f, 0.0f));
				scene->AddGameObject<CExplosion>(9)->SetTexture(SUMMON_LONG, CREATE_EFFECT_X, CREATE_EFFECT_Y, D3DXVECTOR3(65.0f, 5.6f, 90.0f), D3DXVECTOR3(5.0f, 4.0f, 0.0f));
				scene->AddGameObject<CExplosion>(9)->SetTexture(SUMMON_LONG, CREATE_EFFECT_X, CREATE_EFFECT_Y, D3DXVECTOR3(55.0f, 5.6f, 80.0f), D3DXVECTOR3(5.0f, 4.0f, 0.0f));


				scene->AddGameObject<CExplosion>(9)->SetTexture(SUMMON_SHORT, CREATE_EFFECT_X, CREATE_EFFECT_Y, D3DXVECTOR3(45.0f, 5.6f, 60.0f), D3DXVECTOR3(5.0f, 4.0f, 0.0f));
				scene->AddGameObject<CExplosion>(9)->SetTexture(SUMMON_SHORT, CREATE_EFFECT_X, CREATE_EFFECT_Y, D3DXVECTOR3(65.0f, 5.6f, 60.0f), D3DXVECTOR3(5.0f, 4.0f, 0.0f));
				

				Pattern_Number = 11;
				break;

			}
		}
		break;
		case 11:
		{
			if (Camera->GetPosition().z >= 90.0f)
			{

				scene->AddGameObject<CExplosion>(9)->SetTexture(SUMMON_LONG, CREATE_EFFECT_X, CREATE_EFFECT_Y, D3DXVECTOR3(15.0f, 5.6f, 205.0f), D3DXVECTOR3(5.0f, 4.0f, 0.0f));
				scene->AddGameObject<CExplosion>(9)->SetTexture(SUMMON_LONG, CREATE_EFFECT_X, CREATE_EFFECT_Y, D3DXVECTOR3(95.0f, 5.6f, 205.0f), D3DXVECTOR3(5.0f, 4.0f, 0.0f));
				scene->AddGameObject<CExplosion>(9)->SetTexture(SUMMON_SHORT, CREATE_EFFECT_X, CREATE_EFFECT_Y, D3DXVECTOR3(45.0f, 5.6f, 135.0f), D3DXVECTOR3(5.0f, 4.0f, 0.0f));
				scene->AddGameObject<CExplosion>(9)->SetTexture(SUMMON_SHORT, CREATE_EFFECT_X, CREATE_EFFECT_Y, D3DXVECTOR3(65.0f, 5.6f, 135.0f), D3DXVECTOR3(5.0f, 4.0f, 0.0f));



				Pattern_Number = 12;
				break;

			}
		}
		break;
		case 12:
		{
			if (Camera->GetPosition().z >= 150.0f && Camera->GetPosition().x > 40.0f && Camera->GetPosition().x < 70.0f)
			{

				scene->AddGameObject<CExplosion>(9)->SetTexture(SUMMON_LONG, CREATE_EFFECT_X, CREATE_EFFECT_Y, D3DXVECTOR3(40.0f, 5.6f, 205.0f), D3DXVECTOR3(5.0f, 4.0f, 0.0f));
				scene->AddGameObject<CExplosion>(9)->SetTexture(SUMMON_LONG, CREATE_EFFECT_X, CREATE_EFFECT_Y, D3DXVECTOR3(70.0f, 5.6f, 205.0f), D3DXVECTOR3(5.0f, 4.0f, 0.0f));

				scene->AddGameObject<CExplosion>(9)->SetTexture(SUMMON_SHORT, CREATE_EFFECT_X, CREATE_EFFECT_Y, D3DXVECTOR3(35.0f, 5.6f, 180.0f), D3DXVECTOR3(5.0f, 4.0f, 0.0f));
				scene->AddGameObject<CExplosion>(9)->SetTexture(SUMMON_SHORT, CREATE_EFFECT_X, CREATE_EFFECT_Y, D3DXVECTOR3(75.0f, 5.6f, 180.0f), D3DXVECTOR3(5.0f, 4.0f, 0.0f));



				Pattern_Number = 13;
				break;

			}
		}
		break;
		case 13:
		{
			if (Camera->GetPosition().z >= 300.0f && Camera->GetPosition().z < 305.0f)
			{
				scene->AddGameObject<CExplosion>(9)->SetTexture(SUMMON_LONG, CREATE_EFFECT_X, CREATE_EFFECT_Y, D3DXVECTOR3(95.0f, 10.6f, 405.0f), D3DXVECTOR3(5.0f, 4.0f, 0.0f));
				scene->AddGameObject<CExplosion>(9)->SetTexture(SUMMON_LONG, CREATE_EFFECT_X, CREATE_EFFECT_Y, D3DXVECTOR3(55.0f, 10.6f, 385.0f), D3DXVECTOR3(5.0f, 4.0f, 0.0f));

				scene->AddGameObject<CExplosion>(9)->SetTexture(SUMMON_LONG, CREATE_EFFECT_X, CREATE_EFFECT_Y, D3DXVECTOR3(15.0f, 10.6f, 365.0f), D3DXVECTOR3(5.0f, 4.0f, 0.0f));
				scene->AddGameObject<CExplosion>(9)->SetTexture(SUMMON_LONG, CREATE_EFFECT_X, CREATE_EFFECT_Y, D3DXVECTOR3(95.0f, 10.6f, 365.0f), D3DXVECTOR3(5.0f, 4.0f, 0.0f));
				Pattern_Number = 14;
			}
			break;
		}
		default:
			break;
		}
	}
	

	if (CManager::SceneGet<CStage4>())
	{
		if (Camera->GetPosition().z < 110.0f && Camera->GetPosition().y < -5.0f)
		{
			scene->AddGameObject<CFade>(19)->SetObject(D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(50.0f, 50.0f, 0.0f), FADE_RED);
			Player->MinusHP(20);
			Camera->SetPosition(D3DXVECTOR3(35.0f, 4.5f, 9.0f));
			PlaySoundA(SOUND_LABEL_SE_PLAYER_DAMAGE);
		}
		if (Camera->GetPosition().z > 110.0f && Camera->GetPosition().z < 170.0f&& Camera->GetPosition().y < -5.0f )
		{
			scene->AddGameObject<CFade>(19)->SetObject(D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(50.0f, 50.0f, 0.0f), FADE_RED);
			Player->MinusHP(20);
			Camera->SetPosition(D3DXVECTOR3(35.0f, 4.5f, 135.0f));
			PlaySoundA(SOUND_LABEL_SE_PLAYER_DAMAGE);
		}
		if (Camera->GetPosition().z > 200.0f && Camera->GetPosition().z < 310.0f&& Camera->GetPosition().y < -5.0f )
		{
			scene->AddGameObject<CFade>(19)->SetObject(D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(50.0f, 50.0f, 0.0f), FADE_RED);
			Player->MinusHP(20);
			Camera->SetPosition(D3DXVECTOR3(35.0f, 4.5f, 205.0f));
			PlaySoundA(SOUND_LABEL_SE_PLAYER_DAMAGE);
		}
		if (Camera->GetPosition().z > 340.0f  && Camera->GetPosition().z < 415.0f&& Camera->GetPosition().y < -5.0f)
		{
			scene->AddGameObject<CFade>(19)->SetObject(D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(50.0f, 50.0f, 0.0f), FADE_RED);
			Player->MinusHP(20);
			Camera->SetPosition(D3DXVECTOR3(35.0f, 4.5f, 340.0f));
			PlaySoundA(SOUND_LABEL_SE_PLAYER_DAMAGE);
		}
		if (Camera->GetPosition().z > 430.0f && Camera->GetPosition().y < -5.0f)
		{
			scene->AddGameObject<CFade>(19)->SetObject(D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(50.0f, 50.0f, 0.0f), FADE_RED);
			Player->MinusHP(20);
			Camera->SetPosition(D3DXVECTOR3(35.0f, 4.5f, 455.0f));
			PlaySoundA(SOUND_LABEL_SE_PLAYER_DAMAGE);
		}
		switch (Pattern_Number)
		{
			case 0:
			{
			if (Camera->GetPosition().z > 80.0f)
			{
				scene->AddGameObject<CExplosion>(9)->SetTexture(SUMMON_LONG, CREATE_EFFECT_X, CREATE_EFFECT_Y, D3DXVECTOR3(15.0f, 5.6f, 115.0f), D3DXVECTOR3(5.0f, 4.0f, 0.0f));
				scene->AddGameObject<CExplosion>(9)->SetTexture(SUMMON_LONG, CREATE_EFFECT_X, CREATE_EFFECT_Y, D3DXVECTOR3(25.0f, 5.6f, 115.0f), D3DXVECTOR3(5.0f, 4.0f, 0.0f));
				scene->AddGameObject<CExplosion>(9)->SetTexture(SUMMON_SHORT, CREATE_EFFECT_X, CREATE_EFFECT_Y, D3DXVECTOR3(35.0f, 5.6f, 115.0f), D3DXVECTOR3(5.0f, 4.0f, 0.0f));
				scene->AddGameObject<CExplosion>(9)->SetTexture(SUMMON_LONG, CREATE_EFFECT_X, CREATE_EFFECT_Y, D3DXVECTOR3(45.0f, 5.6f, 115.0f), D3DXVECTOR3(5.0f, 4.0f, 0.0f));
				scene->AddGameObject<CExplosion>(9)->SetTexture(SUMMON_LONG, CREATE_EFFECT_X, CREATE_EFFECT_Y, D3DXVECTOR3(55.0f, 5.6f, 115.0f), D3DXVECTOR3(5.0f, 4.0f, 0.0f));
				PlaySoundA(SOUND_LABEL_SE_SUMMONING);
				Pattern_Number = 1;	
				break;

			}
			}
			break;
			case 1:
			{
				if (Camera->GetPosition().z > 160.0f)
				{
					scene->AddGameObject<CExplosion>(9)->SetTexture(SUMMON_LONG, CREATE_EFFECT_X, CREATE_EFFECT_Y, D3DXVECTOR3(25.0f, 5.6f, 205.0f), D3DXVECTOR3(5.0f, 4.0f, 0.0f));
					scene->AddGameObject<CExplosion>(9)->SetTexture(SUMMON_LONG, CREATE_EFFECT_X, CREATE_EFFECT_Y, D3DXVECTOR3(45.0f, 5.6f, 205.0f), D3DXVECTOR3(5.0f, 4.0f, 0.0f));

					scene->AddGameObject<CExplosion>(9)->SetTexture(SUMMON_SHORT, CREATE_EFFECT_X, CREATE_EFFECT_Y, D3DXVECTOR3(25.0f, 5.6f, 195.0f), D3DXVECTOR3(5.0f, 4.0f, 0.0f));
					scene->AddGameObject<CExplosion>(9)->SetTexture(SUMMON_SHORT, CREATE_EFFECT_X, CREATE_EFFECT_Y, D3DXVECTOR3(45.0f, 5.6f, 195.0f), D3DXVECTOR3(5.0f, 4.0f, 0.0f));

					scene->AddGameObject<CExplosion>(9)->SetTexture(SUMMON_LONG, CREATE_EFFECT_X, CREATE_EFFECT_Y, D3DXVECTOR3(5.0f, 5.6f, 185.0f), D3DXVECTOR3(5.0f, 4.0f, 0.0f));
					scene->AddGameObject<CExplosion>(9)->SetTexture(SUMMON_LONG, CREATE_EFFECT_X, CREATE_EFFECT_Y, D3DXVECTOR3(65.0f, 5.6f, 185.0f), D3DXVECTOR3(5.0f, 4.0f, 0.0f));
					PlaySoundA(SOUND_LABEL_SE_SUMMONING);
					Pattern_Number = 2;
					break;

				}
			}
			break;

			case 2:
			{
				if (Camera->GetPosition().z > 340)
				{
					scene->AddGameObject<CExplosion>(9)->SetTexture(SUMMON_LONG, CREATE_EFFECT_X, CREATE_EFFECT_Y, D3DXVECTOR3(25.0f, 5.6f, 375.0f), D3DXVECTOR3(5.0f, 4.0f, 0.0f));

					scene->AddGameObject<CExplosion>(9)->SetTexture(SUMMON_LONG, CREATE_EFFECT_X, CREATE_EFFECT_Y, D3DXVECTOR3(35.0f, 5.6f, 375.0f), D3DXVECTOR3(5.0f, 4.0f, 0.0f));

					scene->AddGameObject<CExplosion>(9)->SetTexture(SUMMON_LONG, CREATE_EFFECT_X, CREATE_EFFECT_Y, D3DXVECTOR3(45.0f, 5.6f, 375.0f), D3DXVECTOR3(5.0f, 4.0f, 0.0f));
					PlaySoundA(SOUND_LABEL_SE_SUMMONING);

					Pattern_Number = 3;
					break;

				}
			}
			break;

			case 3:
			{
				if (Camera->GetPosition().z> 380.0f )
				{
					scene->AddGameObject<CExplosion>(9)->SetTexture(SUMMON_LONG, CREATE_EFFECT_X, CREATE_EFFECT_Y, D3DXVECTOR3(15.0f, 5.6f, 415.0f), D3DXVECTOR3(5.0f, 4.0f, 0.0f));
					scene->AddGameObject<CExplosion>(9)->SetTexture(SUMMON_LONG, CREATE_EFFECT_X, CREATE_EFFECT_Y, D3DXVECTOR3(35.0f, 5.6f, 415.0f), D3DXVECTOR3(5.0f, 4.0f, 0.0f));
					scene->AddGameObject<CExplosion>(9)->SetTexture(SUMMON_LONG, CREATE_EFFECT_X, CREATE_EFFECT_Y, D3DXVECTOR3(55.0f, 5.6f, 415.0f), D3DXVECTOR3(5.0f, 4.0f, 0.0f));
					PlaySoundA(SOUND_LABEL_SE_SUMMONING);

					Pattern_Number = 4;
				}

			}
			break;
			case 4:
			{
				if (Camera->GetPosition().z > 450.0f)
				{
					scene->AddGameObject<CExplosion>(9)->SetTexture(BOSS_DOOR, BOSS_DOOR_EFFECT_X, BOSS_DOOR_EFFECT_Y, D3DXVECTOR3(35.0f, 5.9f, 490.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f));
					Pattern_Number = 5;

				}
			}
			break;
			case 5:
			{
				Count++;
				if (Count > 150)
				{
					StopSound();
					PlaySoundA(SOUND_LABEL_BOSS_BGM);
					scene->AddGameObject<CEnemy>(8)->SetTexture(TYPE_TANK, D3DXVECTOR3(35.0f, 2.4f, 500.0f), D3DXVECTOR3(1.6f, 2.0f, 1.6f), 1000);
					Pattern_Number = 6;
				}
			}
			break;

		}
	}

	if (CManager::SceneGet<CStage5>())
	{
		if (Camera->GetPosition().z < 50.0f && Camera->GetPosition().y < 0.2f && Camera->GetPosition().x < 140.0f)
		{
			scene->AddGameObject<CFade>(19)->SetObject(D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(50.0f, 50.0f, 0.0f), FADE_RED);
			Player->MinusHP(20);
			Camera->SetPosition(D3DXVECTOR3(55.0f, 4.5f, 15.0f));
			PlaySoundA(SOUND_LABEL_SE_PLAYER_DAMAGE);
		}
		if (Camera->GetPosition().z > 50.0f && Camera->GetPosition().z < 240.0f && Camera->GetPosition().y < 0.2f && Camera->GetPosition().x < 140.0f)
		{
			scene->AddGameObject<CFade>(19)->SetObject(D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(50.0f, 50.0f, 0.0f), FADE_RED);
			Player->MinusHP(20);
			Camera->SetPosition(D3DXVECTOR3(55.0f, 4.5f, 60.0f));
			PlaySoundA(SOUND_LABEL_SE_PLAYER_DAMAGE);
		}
		if (Camera->GetPosition().z > 240.0f && Camera->GetPosition().y < 0.2f && Camera->GetPosition().x < 150.0f)
		{
			scene->AddGameObject<CFade>(19)->SetObject(D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(50.0f, 50.0f, 0.0f), FADE_RED);
			Player->MinusHP(20);
			Camera->SetPosition(D3DXVECTOR3(55.0f, 4.5f, 245.0f));
			PlaySoundA(SOUND_LABEL_SE_PLAYER_DAMAGE);
		}
		if (Camera->GetPosition().z > 180.0f && Camera->GetPosition().y < 0.2f && Camera->GetPosition().x > 150.0f)
		{
			scene->AddGameObject<CFade>(19)->SetObject(D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(50.0f, 50.0f, 0.0f), FADE_RED);
			Player->MinusHP(20);
			Camera->SetPosition(D3DXVECTOR3(160.0f, 4.5f, 340.0f));
			PlaySoundA(SOUND_LABEL_SE_PLAYER_DAMAGE);
		}
		C3dpolygon* S5_Door1 = CManager::GetScene()->GetGameObject<C3dpolygon>(1);
		C3dpolygon* S5_Door2 = CManager::GetScene()->GetGameObject<C3dpolygon>(2);
		if (Camera->GetPosition().z > 0.0f && Camera->GetPosition().z < 240.0f && Camera->GetPosition().x < 150.0f)
		{
			Count++;
			if (Count == 500)
			{
				scene->AddGameObject<CWarning>(9)->SetObject(D3DXVECTOR3(Camera->GetPosition().x - 5.0f + Camera->GetFrontVec().x*5.0f, 2.6f, Camera->GetPosition().z - 5.0f + Camera->GetFrontVec().z*5.0f), D3DXVECTOR3(10.0f, 0.1f, 10.0f));
				Count = 0;
			}
		}
		if (Camera->GetPosition().z < 180.0f && Camera->GetPosition().x > 150.0f)
		{
			Count++;
			if (Count == 300)
			{
				scene->AddGameObject<CWarning>(9)->SetObject(D3DXVECTOR3(Camera->GetPosition().x - 5.0f + Camera->GetFrontVec().x*5.0f, 2.6f, Camera->GetPosition().z - 5.0f + Camera->GetFrontVec().z*5.0f), D3DXVECTOR3(10.0f, 0.1f, 10.0f));
				Count = 0;
			}
		}
		switch (Pattern_Number)
		{
			
		case 0:
		{
			if (Camera->GetPosition().z >= 60.0f)
			{
				PlaySoundA(SOUND_LABEL_SE_PATTERNONE);
				S5_Door1->SetCloseDoor();
				S5_Door2->SetCloseDoor();

				Pattern_Number = 1;

			}
		}
		break;
		case 1:
		{
			if (Camera->GetPosition().z > 61.0f)
			{

				scene->AddGameObject<CExplosion>(9)->SetTexture(SUMMON_LONG, CREATE_EFFECT_X, CREATE_EFFECT_Y, D3DXVECTOR3(45.0f, 5.6f, 105.0f), D3DXVECTOR3(5.0f, 4.0f, 0.0f));
				scene->AddGameObject<CExplosion>(9)->SetTexture(SUMMON_LONG, CREATE_EFFECT_X, CREATE_EFFECT_Y, D3DXVECTOR3(75.0f, 5.6f, 105.0f), D3DXVECTOR3(5.0f, 4.0f, 0.0f));

				scene->AddGameObject<CExplosion>(9)->SetTexture(SUMMON_SHORT, CREATE_EFFECT_X, CREATE_EFFECT_Y, D3DXVECTOR3(15.0f, 5.6f, 95.0f), D3DXVECTOR3(5.0f, 4.0f, 0.0f));
				scene->AddGameObject<CExplosion>(9)->SetTexture(SUMMON_SHORT, CREATE_EFFECT_X, CREATE_EFFECT_Y, D3DXVECTOR3(35.0f, 5.6f, 95.0f), D3DXVECTOR3(5.0f, 4.0f, 0.0f));
				scene->AddGameObject<CExplosion>(9)->SetTexture(SUMMON_SHORT, CREATE_EFFECT_X, CREATE_EFFECT_Y, D3DXVECTOR3(85.0f, 5.6f, 95.0f), D3DXVECTOR3(5.0f, 4.0f, 0.0f));
				scene->AddGameObject<CExplosion>(9)->SetTexture(SUMMON_SHORT, CREATE_EFFECT_X, CREATE_EFFECT_Y, D3DXVECTOR3(105.0f, 5.6f, 95.0f), D3DXVECTOR3(5.0f, 4.0f, 0.0f));
				scene->AddGameObject<CExplosion>(9)->SetTexture(SUMMON_SHORT, CREATE_EFFECT_X, CREATE_EFFECT_Y, D3DXVECTOR3(55.0f, 5.6f, 95.0f), D3DXVECTOR3(5.0f, 4.0f, 0.0f));
				scene->AddGameObject<CExplosion>(9)->SetTexture(SUMMON_SHORT, CREATE_EFFECT_X, CREATE_EFFECT_Y, D3DXVECTOR3(65.0f, 5.6f, 95.0f), D3DXVECTOR3(5.0f, 4.0f, 0.0f));
				scene->AddGameObject<CExplosion>(9)->SetTexture(SUMMON_LONG, CREATE_EFFECT_X, CREATE_EFFECT_Y, D3DXVECTOR3(15.0f, 5.6f, 85.0f), D3DXVECTOR3(5.0f, 4.0f, 0.0f));
				scene->AddGameObject<CExplosion>(9)->SetTexture(SUMMON_LONG, CREATE_EFFECT_X, CREATE_EFFECT_Y, D3DXVECTOR3(35.0f, 5.6f, 85.0f), D3DXVECTOR3(5.0f, 4.0f, 0.0f));
				scene->AddGameObject<CExplosion>(9)->SetTexture(SUMMON_LONG, CREATE_EFFECT_X, CREATE_EFFECT_Y, D3DXVECTOR3(85.0f, 5.6f, 85.0f), D3DXVECTOR3(5.0f, 4.0f, 0.0f));
				scene->AddGameObject<CExplosion>(9)->SetTexture(SUMMON_LONG, CREATE_EFFECT_X, CREATE_EFFECT_Y, D3DXVECTOR3(105.0f, 5.6f, 85.0f), D3DXVECTOR3(5.0f, 4.0f, 0.0f));
				scene->AddGameObject<CExplosion>(9)->SetTexture(SUMMON_SHORT, CREATE_EFFECT_X, CREATE_EFFECT_Y, D3DXVECTOR3(55.0f, 5.6f, 85.0f), D3DXVECTOR3(5.0f, 4.0f, 0.0f));
				scene->AddGameObject<CExplosion>(9)->SetTexture(SUMMON_SHORT, CREATE_EFFECT_X, CREATE_EFFECT_Y, D3DXVECTOR3(65.0f, 5.6f, 85.0f), D3DXVECTOR3(5.0f, 4.0f, 0.0f));


				Pattern_Number = 2;

			}
		}
		break;
		case 2:
		{
			if (Camera->GetPosition().z > 130.0f)
			{

				scene->AddGameObject<CExplosion>(9)->SetTexture(SUMMON_SHORT, CREATE_EFFECT_X, CREATE_EFFECT_Y, D3DXVECTOR3(5.0f, 5.6f, 185.0f), D3DXVECTOR3(5.0f, 4.0f, 0.0f));
				scene->AddGameObject<CExplosion>(9)->SetTexture(SUMMON_SHORT, CREATE_EFFECT_X, CREATE_EFFECT_Y, D3DXVECTOR3(15.0f, 5.6f, 185.0f), D3DXVECTOR3(5.0f, 4.0f, 0.0f));
				scene->AddGameObject<CExplosion>(9)->SetTexture(SUMMON_SHORT, CREATE_EFFECT_X, CREATE_EFFECT_Y, D3DXVECTOR3(25.0f, 5.6f, 185.0f), D3DXVECTOR3(5.0f, 4.0f, 0.0f));
				scene->AddGameObject<CExplosion>(9)->SetTexture(SUMMON_SHORT, CREATE_EFFECT_X, CREATE_EFFECT_Y, D3DXVECTOR3(35.0f, 5.6f, 185.0f), D3DXVECTOR3(5.0f, 4.0f, 0.0f));
				scene->AddGameObject<CExplosion>(9)->SetTexture(SUMMON_SHORT, CREATE_EFFECT_X, CREATE_EFFECT_Y, D3DXVECTOR3(45.0f, 5.6f, 185.0f), D3DXVECTOR3(5.0f, 4.0f, 0.0f));
				scene->AddGameObject<CExplosion>(9)->SetTexture(SUMMON_SHORT, CREATE_EFFECT_X, CREATE_EFFECT_Y, D3DXVECTOR3(65.0f, 5.6f, 185.0f), D3DXVECTOR3(5.0f, 4.0f, 0.0f));
				scene->AddGameObject<CExplosion>(9)->SetTexture(SUMMON_SHORT, CREATE_EFFECT_X, CREATE_EFFECT_Y, D3DXVECTOR3(75.0f, 5.6f, 185.0f), D3DXVECTOR3(5.0f, 4.0f, 0.0f));
				scene->AddGameObject<CExplosion>(9)->SetTexture(SUMMON_SHORT, CREATE_EFFECT_X, CREATE_EFFECT_Y, D3DXVECTOR3(85.0f, 5.6f, 185.0f), D3DXVECTOR3(5.0f, 4.0f, 0.0f));
				scene->AddGameObject<CExplosion>(9)->SetTexture(SUMMON_SHORT, CREATE_EFFECT_X, CREATE_EFFECT_Y, D3DXVECTOR3(95.0f, 5.6f, 185.0f), D3DXVECTOR3(5.0f, 4.0f, 0.0f));
				scene->AddGameObject<CExplosion>(9)->SetTexture(SUMMON_SHORT, CREATE_EFFECT_X, CREATE_EFFECT_Y, D3DXVECTOR3(105.0f, 5.6f, 185.0f), D3DXVECTOR3(5.0f, 4.0f, 0.0f));

				scene->AddGameObject<CExplosion>(9)->SetTexture(SUMMON_LONG, CREATE_EFFECT_X, CREATE_EFFECT_Y, D3DXVECTOR3(15.0f, 5.6f, 175.0f), D3DXVECTOR3(5.0f, 4.0f, 0.0f));
				scene->AddGameObject<CExplosion>(9)->SetTexture(SUMMON_LONG, CREATE_EFFECT_X, CREATE_EFFECT_Y, D3DXVECTOR3(35.0f, 5.6f, 175.0f), D3DXVECTOR3(5.0f, 4.0f, 0.0f));
				scene->AddGameObject<CExplosion>(9)->SetTexture(SUMMON_LONG, CREATE_EFFECT_X, CREATE_EFFECT_Y, D3DXVECTOR3(55.0f, 5.6f, 175.0f), D3DXVECTOR3(5.0f, 4.0f, 0.0f));
				scene->AddGameObject<CExplosion>(9)->SetTexture(SUMMON_LONG, CREATE_EFFECT_X, CREATE_EFFECT_Y, D3DXVECTOR3(75.0f, 5.6f, 175.0f), D3DXVECTOR3(5.0f, 4.0f, 0.0f));
				scene->AddGameObject<CExplosion>(9)->SetTexture(SUMMON_LONG, CREATE_EFFECT_X, CREATE_EFFECT_Y, D3DXVECTOR3(95.0f, 5.6f, 175.0f), D3DXVECTOR3(5.0f, 4.0f, 0.0f));



				Pattern_Number = 3;

			}
		}
		break;
		case 3:
		{
			if (Camera->GetPosition().x > 150.0f && Camera->GetPosition().z < 185.0f)
			{
				scene->AddGameObject<CExplosion>(9)->SetTexture(BOSS_DOOR, BOSS_DOOR_EFFECT_X, BOSS_DOOR_EFFECT_Y, D3DXVECTOR3(170.0f, 5.5f, 90.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f));
				scene->AddGameObject<CExplosion>(9)->SetTexture(BOSS_DOOR, BOSS_DOOR_EFFECT_X, BOSS_DOOR_EFFECT_Y, D3DXVECTOR3(210.0f, 5.5f, 90.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f));
				scene->AddGameObject<CExplosion>(9)->SetTexture(BOSS_DOOR, BOSS_DOOR_EFFECT_X, BOSS_DOOR_EFFECT_Y, D3DXVECTOR3(250.0f, 5.5f, 90.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f));

				Pattern_Number = 4;

			}

		}
		break;
		}
	}

	if (CManager::SceneGet<CStage6>())
	{
		C3dpolygon* S6_Door1 = CManager::GetScene()->GetGameObject<C3dpolygon>(1);
		C3dpolygon* S6_Door2 = CManager::GetScene()->GetGameObject<C3dpolygon>(2);
		if (Camera->GetPosition().z < 90.0f )
		{
			Count++;
			if (Count == 1000)
			{
				scene->AddGameObject<CWarning>(9)->SetObject(D3DXVECTOR3(Camera->GetPosition().x - 5.0f + Camera->GetFrontVec().x*5.0f, 2.6f, Camera->GetPosition().z - 5.0f + Camera->GetFrontVec().z*5.0f), D3DXVECTOR3(5.0f, 0.1f, 5.0f));
				Count = 0;
			}
		}
		switch (Pattern_Number)
		{
		case 0:
		{
			if (Camera->GetPosition().x < 110.0f)
			{
				Pattern_Number = 1;
			}
			if (Camera->GetPosition().x > 180.0f)
			{
				Pattern_Number = 10;
			}
		}
		break;
		case 1:
		{
			scene->AddGameObject<CExplosion>(9)->SetTexture(SUMMON_LONG, CREATE_EFFECT_X, CREATE_EFFECT_Y, D3DXVECTOR3(85.0f, 5.6f, 55.0f), D3DXVECTOR3(5.0f, 4.0f, 0.0f));
			scene->AddGameObject<CExplosion>(9)->SetTexture(SUMMON_LONG, CREATE_EFFECT_X, CREATE_EFFECT_Y, D3DXVECTOR3(85.0f, 5.6f, 50.0f), D3DXVECTOR3(5.0f, 4.0f, 0.0f));

			scene->AddGameObject<CExplosion>(9)->SetTexture(SUMMON_SHORT, CREATE_EFFECT_X, CREATE_EFFECT_Y, D3DXVECTOR3(90.0f, 5.6f, 50.0f), D3DXVECTOR3(5.0f, 4.0f, 0.0f));


			scene->AddGameObject<CExplosion>(9)->SetTexture(SUMMON_LONG, CREATE_EFFECT_X, CREATE_EFFECT_Y, D3DXVECTOR3(85.0f, 5.6f, 35.0f), D3DXVECTOR3(5.0f, 4.0f, 0.0f));
			scene->AddGameObject<CExplosion>(9)->SetTexture(SUMMON_LONG, CREATE_EFFECT_X, CREATE_EFFECT_Y, D3DXVECTOR3(85.0f, 5.6f, 40.0f), D3DXVECTOR3(5.0f, 4.0f, 0.0f));

			scene->AddGameObject<CExplosion>(9)->SetTexture(SUMMON_SHORT, CREATE_EFFECT_X, CREATE_EFFECT_Y, D3DXVECTOR3(90.0f, 5.6f, 40.0f), D3DXVECTOR3(5.0f, 4.0f, 0.0f));

			Pattern_Number = 2;
		}
		break;
		case 2:
		{
			if (Camera->GetPosition().x < 60.0f)
			{
				scene->AddGameObject<CExplosion>(9)->SetTexture(BOSS_DOOR, BOSS_DOOR_EFFECT_X, BOSS_DOOR_EFFECT_Y, D3DXVECTOR3(30.0f, 5.0f, 30.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f));
				scene->AddGameObject<CExplosion>(9)->SetTexture(BOSS_DOOR, BOSS_DOOR_EFFECT_X, BOSS_DOOR_EFFECT_Y, D3DXVECTOR3(30.0f, 5.0f, 60.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f));
				S6_Door1->SetOpenDoor();
				PlaySoundA(SOUND_LABEL_SE_PATTERNONE);

				Pattern_Number = 3;
			}
		}
		case 3:
		{
			if (Camera->GetPosition().x > 180.0f)
			{
				Pattern_Number = 4;
			}
		}
		break;
		case 4:
		{
			scene->AddGameObject<CExplosion>(9)->SetTexture(SUMMON_LONG, CREATE_EFFECT_X, CREATE_EFFECT_Y, D3DXVECTOR3(205.0f, 5.6f, 55.0f), D3DXVECTOR3(5.0f, 4.0f, 0.0f));
			scene->AddGameObject<CExplosion>(9)->SetTexture(SUMMON_LONG, CREATE_EFFECT_X, CREATE_EFFECT_Y, D3DXVECTOR3(205.0f, 5.6f, 50.0f), D3DXVECTOR3(5.0f, 4.0f, 0.0f));

			scene->AddGameObject<CExplosion>(9)->SetTexture(SUMMON_SHORT, CREATE_EFFECT_X, CREATE_EFFECT_Y, D3DXVECTOR3(200.0f, 5.6f, 50.0f), D3DXVECTOR3(5.0f, 4.0f, 0.0f));


			scene->AddGameObject<CExplosion>(9)->SetTexture(SUMMON_LONG, CREATE_EFFECT_X, CREATE_EFFECT_Y, D3DXVECTOR3(205.0f, 5.6f, 35.0f), D3DXVECTOR3(5.0f, 4.0f, 0.0f));
			scene->AddGameObject<CExplosion>(9)->SetTexture(SUMMON_LONG, CREATE_EFFECT_X, CREATE_EFFECT_Y, D3DXVECTOR3(205.0f, 5.6f, 40.0f), D3DXVECTOR3(5.0f, 4.0f, 0.0f));

			scene->AddGameObject<CExplosion>(9)->SetTexture(SUMMON_SHORT, CREATE_EFFECT_X, CREATE_EFFECT_Y, D3DXVECTOR3(200.0f, 5.6f, 40.0f), D3DXVECTOR3(5.0f, 4.0f, 0.0f));
			Pattern_Number = 5;

		}
		break;
		case 5:
		{
			if (Camera->GetPosition().x > 230.0f)
			{
				S6_Door2->SetOpenDoor();
				PlaySoundA(SOUND_LABEL_SE_PATTERNONE);
				scene->AddGameObject<CExplosion>(9)->SetTexture(BOSS_DOOR, BOSS_DOOR_EFFECT_X, BOSS_DOOR_EFFECT_Y, D3DXVECTOR3(260.0f, 5.0f, 30.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f));
				scene->AddGameObject<CExplosion>(9)->SetTexture(BOSS_DOOR, BOSS_DOOR_EFFECT_X, BOSS_DOOR_EFFECT_Y, D3DXVECTOR3(260.0f, 5.0f, 60.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f));
				Pattern_Number = 6;

			}
		}
		break;
		case 6:
		{
			if (Camera->GetPosition().z > 80.0f)
			{
				//Boss
				Pattern_Number = 7;
			}
		}
		break;

		case 10:
		{
			if (Camera->GetPosition().x > 180.0f)
			{
				Pattern_Number = 11;
			}
		}
		break;
		case 11:
		{
			scene->AddGameObject<CExplosion>(9)->SetTexture(SUMMON_LONG, CREATE_EFFECT_X, CREATE_EFFECT_Y, D3DXVECTOR3(205.0f, 5.6f, 55.0f), D3DXVECTOR3(5.0f, 4.0f, 0.0f));
			scene->AddGameObject<CExplosion>(9)->SetTexture(SUMMON_LONG, CREATE_EFFECT_X, CREATE_EFFECT_Y, D3DXVECTOR3(205.0f, 5.6f, 50.0f), D3DXVECTOR3(5.0f, 4.0f, 0.0f));

			scene->AddGameObject<CExplosion>(9)->SetTexture(SUMMON_SHORT, CREATE_EFFECT_X, CREATE_EFFECT_Y, D3DXVECTOR3(200.0f, 5.6f, 50.0f), D3DXVECTOR3(5.0f, 4.0f, 0.0f));


			scene->AddGameObject<CExplosion>(9)->SetTexture(SUMMON_LONG, CREATE_EFFECT_X, CREATE_EFFECT_Y, D3DXVECTOR3(205.0f, 5.6f, 35.0f), D3DXVECTOR3(5.0f, 4.0f, 0.0f));
			scene->AddGameObject<CExplosion>(9)->SetTexture(SUMMON_LONG, CREATE_EFFECT_X, CREATE_EFFECT_Y, D3DXVECTOR3(205.0f, 5.6f, 40.0f), D3DXVECTOR3(5.0f, 4.0f, 0.0f));

			scene->AddGameObject<CExplosion>(9)->SetTexture(SUMMON_SHORT, CREATE_EFFECT_X, CREATE_EFFECT_Y, D3DXVECTOR3(200.0f, 5.6f, 40.0f), D3DXVECTOR3(5.0f, 4.0f, 0.0f));
			Pattern_Number = 12;
		}
		break;

		case 12:
		{
			if (Camera->GetPosition().x > 230.0f)
			{
				S6_Door2->SetOpenDoor();
				PlaySoundA(SOUND_LABEL_SE_PATTERNONE);
				scene->AddGameObject<CExplosion>(9)->SetTexture(BOSS_DOOR, BOSS_DOOR_EFFECT_X, BOSS_DOOR_EFFECT_Y, D3DXVECTOR3(260.0f, 5.0f, 30.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f));
				scene->AddGameObject<CExplosion>(9)->SetTexture(BOSS_DOOR, BOSS_DOOR_EFFECT_X, BOSS_DOOR_EFFECT_Y, D3DXVECTOR3(260.0f, 5.0f, 60.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f));
				Pattern_Number = 13;

			}
		}
		break;
		case 13:
		{
			if (Camera->GetPosition().x < 110.0f)
			{
				scene->AddGameObject<CExplosion>(9)->SetTexture(SUMMON_LONG, CREATE_EFFECT_X, CREATE_EFFECT_Y, D3DXVECTOR3(85.0f, 5.6f, 55.0f), D3DXVECTOR3(5.0f, 4.0f, 0.0f));
				scene->AddGameObject<CExplosion>(9)->SetTexture(SUMMON_LONG, CREATE_EFFECT_X, CREATE_EFFECT_Y, D3DXVECTOR3(85.0f, 5.6f, 50.0f), D3DXVECTOR3(5.0f, 4.0f, 0.0f));

				scene->AddGameObject<CExplosion>(9)->SetTexture(SUMMON_SHORT, CREATE_EFFECT_X, CREATE_EFFECT_Y, D3DXVECTOR3(90.0f, 5.6f, 50.0f), D3DXVECTOR3(5.0f, 4.0f, 0.0f));


				scene->AddGameObject<CExplosion>(9)->SetTexture(SUMMON_LONG, CREATE_EFFECT_X, CREATE_EFFECT_Y, D3DXVECTOR3(85.0f, 5.6f, 35.0f), D3DXVECTOR3(5.0f, 4.0f, 0.0f));
				scene->AddGameObject<CExplosion>(9)->SetTexture(SUMMON_LONG, CREATE_EFFECT_X, CREATE_EFFECT_Y, D3DXVECTOR3(85.0f, 5.6f, 40.0f), D3DXVECTOR3(5.0f, 4.0f, 0.0f));

				scene->AddGameObject<CExplosion>(9)->SetTexture(SUMMON_SHORT, CREATE_EFFECT_X, CREATE_EFFECT_Y, D3DXVECTOR3(90.0f, 5.6f, 40.0f), D3DXVECTOR3(5.0f, 4.0f, 0.0f));

				Pattern_Number = 14;
			}
		}
		break;

		case 14:
		{
			if (Camera->GetPosition().x < 60.0f)
			{
				scene->AddGameObject<CExplosion>(9)->SetTexture(BOSS_DOOR, BOSS_DOOR_EFFECT_X, BOSS_DOOR_EFFECT_Y, D3DXVECTOR3(30.0f, 5.0f, 30.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f));
				scene->AddGameObject<CExplosion>(9)->SetTexture(BOSS_DOOR, BOSS_DOOR_EFFECT_X, BOSS_DOOR_EFFECT_Y, D3DXVECTOR3(30.0f, 5.0f, 60.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f));
				S6_Door1->SetOpenDoor();
				PlaySoundA(SOUND_LABEL_SE_PATTERNONE);

				Pattern_Number = 15;
			}
		}
		break;

		case 15:
		{
			if (Camera->GetPosition().z > 80.0f)
			{
				//Boss
				Pattern_Number = 7;
			}
		}

		break;
		}
	}

}

bool GetPatternStopMove()
{
	return Pattern_StopMove;
}
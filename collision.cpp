#include "main.h"
#include "collision.h"
#include "Player.h"
#include "enemy.h"
#include "manager.h"
#include "scene.h"
#include "explosion.h"
#include "ebullet.h"
#include "3dpolygon.h"
#include "Polygon.h"
#include "attack.h"
#include "trap.h"
#include "sound.h"
#include "filed.h"
#include "pattern.h"
#include "stage1.h"
#include "stage2.h"
#include "stage3.h"
#include "stage4.h"
#include "stage5.h"
#include "Stage6.h"
#include "Rail.h"
#include "eattack.h"
static int Normal_Count = 0;
static int EnemyDamage_Count = 0;
static int TeleportLogo_Count = 0;
static int Gate_Count = 0;
static int DeleteGate_Count = 0;

static bool Colision[4] = { false };

void ResetCollision()
{
	Normal_Count = 0;
	EnemyDamage_Count = 0;
	TeleportLogo_Count = 0;
	Gate_Count = 0;
	DeleteGate_Count = 0;
}
void Collision_Update()
{
	
	CScene* scene = CManager::GetScene();
	CCamera* Camera = CManager::GetScene()->GetGameObject<CCamera>(0);
	CPlayer* Player = CManager::GetScene()->GetGameObject<CPlayer>(2);

	std::vector<CWall*> RightWallList = CManager::GetScene()->GetGameObjects<CWall>(3);
	std::vector<CWall*> LeftWallList = CManager::GetScene()->GetGameObjects<CWall>(4);
	std::vector<CWall*> FrontWallList = CManager::GetScene()->GetGameObjects<CWall>(5);
	std::vector<CWall*> BehindWallList = CManager::GetScene()->GetGameObjects<CWall>(6);
	std::vector<CEbullet*> EbulletList = CManager::GetScene()->GetGameObjects<CEbullet>(8);
	std::vector<CEattack*> EnemyAttackList = CManager::GetScene()->GetGameObjects<CEattack>(8);
	std::vector<CField*> FieldList = CManager::GetScene()->GetGameObjects<CField>(8);
	std::vector<CBullet*> BulletList = CManager::GetScene()->GetGameObjects<CBullet>(8);
	std::vector<CEnemy*> EnemyList = CManager::GetScene()->GetGameObjects<CEnemy>(8);




	



	EnemyDamage_Count++;

	if (CManager::SceneGet<CStage3>())
	{
		C3dpolygon* S3_Door1 = CManager::GetScene()->GetGameObject<C3dpolygon>(1);
		C3dpolygon* S3_Door2 = CManager::GetScene()->GetGameObject<C3dpolygon>(2);
		C3dpolygon* S3_Jump = CManager::GetScene()->GetGameObject<C3dpolygon>(3);
		C3dpolygon* S3_Clear = CManager::GetScene()->GetGameObject<C3dpolygon>(4);
		C3dpolygon* Tutorial_Door1 = CManager::GetScene()->GetGameObject<C3dpolygon>(5);
		C3dpolygon* Tutorial_Door2 = CManager::GetScene()->GetGameObject<C3dpolygon>(6);
		std::vector<CTrap*> XTrapList = CManager::GetScene()->GetGameObjects<CTrap>(8);

	
		if (CheckBoxCollision(S3_Clear->GetMin(), S3_Clear->GetMax(), Camera->GetMin(), Camera->GetMax()) && Normal_Count > 0)
		{
			if (S3_Clear->GetMin().x != -0.5f)
			{
				Camera->SetTeleport();
			}
		}
		for (CField* Field : FieldList)
		{
		
			if (CheckBoxCollision(Field->GetMin(), Field->GetMax(), Camera->GetMin(), Camera->GetMax()) && Normal_Count > 0)
			{
				if (Field->GetMin().x != -0.5f)
				{
					Camera->SetGravityPower();
				}
			}
		}
		if (CheckBoxCollision(S3_Clear->GetMin(), S3_Clear->GetMax(), Camera->GetMin(), Camera->GetMax()) && Normal_Count > 0)
		{
			if (S3_Jump->GetMin().x != -0.5f)
			{
				Camera->SetJump();
			}
		}
		if (CheckBoxCollision(Tutorial_Door1->GetMin(), Tutorial_Door1->GetMax(), Camera->GetMin(), Camera->GetMax()) && Normal_Count > 0)
		{
			if (Tutorial_Door1->GetMin().x != -0.5f)
			{
				Camera->StopDoor();
			}
		}
	
		if (CheckBoxCollision(Tutorial_Door2->GetMin(), Tutorial_Door2->GetMax(), Camera->GetMin(), Camera->GetMax()) && Normal_Count > 0)
		{
			if (Tutorial_Door2->GetMin().x != -0.5f)
			{
				Camera->StopDoor();
			}
		}
	
			if (CheckBoxCollision(S3_Door1->GetMin(), S3_Door1->GetMax(), Camera->GetMin(), Camera->GetMax()) && Normal_Count > 0)
			{
				if (S3_Door1->GetMin().x != -0.5f)
				{
					Camera->StopDoor();
				}
			}
		
			if (CheckBoxCollision(S3_Door2->GetMin(), S3_Door2->GetMax(), Camera->GetMin(), Camera->GetMax()) && Normal_Count > 0)
			{
				if (S3_Door2->GetMin().x != -0.5f)
				{
					Camera->StopDoor();
				}
				for (CEnemy* Enemy : EnemyList)
				{
						if (EnemyList.size() < 2 && Gate_Count == 0 && Camera->GetPosition().z >= 215.0f && Camera->GetPosition().x > 30.0f && Camera->GetPosition().x < 80.0f)
						{
							S3_Door2->SetOpenDoor();
							PlaySoundA(SOUND_LABEL_SE_PATTERNONE);
							Gate_Count++;
						}
					

				}
			}
		
	
		for (CEattack* Eattack : EnemyAttackList)
		{

			if (CheckBoxCollision(Eattack->GetMin(), Eattack->GetMax(), Camera->GetMin(), Camera->GetMax()) && Normal_Count > 0)
			{
				if (EnemyDamage_Count > 60)
				{
					Camera->BackMove();
					scene->AddGameObject<CFade>(19)->SetObject(D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(50.0f, 50.0f, 0.0f), FADE_RED);
					Player->MinusHP();
					EnemyDamage_Count = 0;
					PlaySoundA(SOUND_LABEL_SE_PLAYER_DAMAGE);
					Eattack->SetDestroy();

				}
			}
		}
		for (CEnemy* Enemy : EnemyList)
		{
			for (CBullet* Bullet : BulletList)
			{
				if (CheckBoxCollision(Enemy->EnemyMin(TYPE_HEAD), Enemy->EnemyMax(TYPE_HEAD), Bullet->GetMin(), Bullet->GetMax()) && Normal_Count > 0)
				{
					if (!Enemy->GetEnemyLife())
					{
						
							PlaySoundA(SOUND_LABEL_SE_ENEMY_HEADSHOT);
						
					
						Bullet->SetEffect(0);
						Enemy->StopBegin();
						Bullet->SetDestroy();
						Enemy->MinusHp(20);
						Enemy->SetUnderattack();
						return;
					}
				}

				if (CheckBoxCollision(Enemy->EnemyMin(TYPE_BODY), Enemy->EnemyMax(TYPE_BODY), Bullet->GetMin(), Bullet->GetMax()) && Normal_Count > 0)
				{
					if (!Enemy->GetEnemyLife())
					{
						
							PlaySoundA(SOUND_LABEL_SE_ENEMY_HIT);
					
							Bullet->SetEffect(1);
						
						Enemy->StopBegin();
						Bullet->SetDestroy();
						Enemy->MinusHp(10);
						Enemy->SetUnderattack();

						return;
					}
				}
			
			}
		}
		for (CWall* RightWall : RightWallList)
		{
			for (CEbullet* EBullet : EbulletList)
			{

				if (CheckBoxCollision(RightWall->GetMin(), RightWall->GetMax(), EBullet->GetMin(), EBullet->GetMax()) && Normal_Count > 0)
				{
					EBullet->SetDestroy();
				}

				if (CheckBoxCollision(Camera->GetMin(), Camera->GetMax(), EBullet->GetMin(), EBullet->GetMax()) && Normal_Count > 0)
				{
					if (EnemyDamage_Count > 60)
					{
						Camera->BackMove();
						scene->AddGameObject<CFade>(19)->SetObject(D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(50.0f, 50.0f, 0.0f), FADE_RED);
						EBullet->SetDestroy();
						EnemyDamage_Count = 0;
						Player->MinusHP();
						PlaySoundA(SOUND_LABEL_SE_PLAYER_DAMAGE);


					}
				}
			}
			for (CTrap* XTrap : XTrapList)
			{

				if (CheckBoxCollision(Camera->GetMin(), Camera->GetMax(), XTrap->GetMin(), XTrap->GetMax()) && Normal_Count > 0)
				{
					if (EnemyDamage_Count > 60)
					{
						Camera->BackMove();
						scene->AddGameObject<CFade>(19)->SetObject(D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(50.0f, 50.0f, 0.0f), FADE_RED);
						Player->MinusHP();
						EnemyDamage_Count = 0;
						PlaySoundA(SOUND_LABEL_SE_PLAYER_DAMAGE);

					}
				}

				if (CheckBoxCollision(RightWall->GetMin(), RightWall->GetMax(), XTrap->GetMin(), XTrap->GetMax()) && Normal_Count > 0)
				{
					XTrap->SetXTrapMinusMove();
				}
			}
			for (CEnemy* Enemy : EnemyList)
			{
				if (CheckBoxCollision(RightWall->GetMin(), RightWall->GetMax(), Enemy->EnemyMin(TYPE_BODY), Enemy->EnemyMax(TYPE_BODY)) && Normal_Count > 0)
				{
					Enemy->SetStopRight();
				}
			}

			Colision[0] = CheckBoxCollision(RightWall->GetMin(), RightWall->GetMax(), Camera->GetMin(), Camera->GetMax());
			if (Colision[0])
			{
				Camera->SetStopRight(true);
				break;
			}
			else
			{
				Camera->SetStopRight(false);
			}
			

	
			for (CBullet* Bullet : BulletList)
			{
				if (CheckBoxCollision(RightWall->GetMin(), RightWall->GetMax(), Bullet->GetMin(), Bullet->GetMax()) && Normal_Count > 0)
				{

					Bullet->SetDestroy();
				}
			}
		}
		for (CWall* LeftWall : LeftWallList)
		{
			for (CEbullet* EBullet : EbulletList)
			{

				if (CheckBoxCollision(LeftWall->GetMin(), LeftWall->GetMax(), EBullet->GetMin(), EBullet->GetMax()) && Normal_Count > 0)
				{
					EBullet->SetDestroy();
				}
			}
			for (CTrap* XTrap : XTrapList)
			{

				if (CheckBoxCollision(LeftWall->GetMin(), LeftWall->GetMax(), XTrap->GetMin(), XTrap->GetMax()) && Normal_Count > 0)
				{
					XTrap->SetXTrapPlusMove();
				}
			}
			for (CEnemy* Enemy : EnemyList)
			{
				
				if (CheckBoxCollision(LeftWall->GetMin(), LeftWall->GetMax(), Enemy->EnemyMin(TYPE_BODY), Enemy->EnemyMax(TYPE_BODY)) && Normal_Count > 0)
				{
					Enemy->SetStopLeft();
				}
			}

			Colision[1] = CheckBoxCollision(LeftWall->GetMin(), LeftWall->GetMax(), Camera->GetMin(), Camera->GetMax());
			if (Colision[1])
			{
				Camera->SetStopLeft(true);
				break;
			}
			else
			{
				Camera->SetStopLeft(false);
			}
		
			for (CBullet* Bullet : BulletList)
			{
				
				if (CheckBoxCollision(LeftWall->GetMin(), LeftWall->GetMax(), Bullet->GetMin(), Bullet->GetMax()) && Normal_Count > 0)
				{
				
					Bullet->SetDestroy();
				}
			}
		}
		for (CWall* FrontWall : FrontWallList)
		{
			for (CEbullet* EBullet : EbulletList)
			{
				
				if (CheckBoxCollision(FrontWall->GetMin(), FrontWall->GetMax(), EBullet->GetMin(), EBullet->GetMax()) && Normal_Count > 0)
				{
					EBullet->SetDestroy();
				}
			}
			for (CEnemy* Enemy : EnemyList)
			{
				
				if (CheckBoxCollision(FrontWall->GetMin(), FrontWall->GetMax(), Enemy->EnemyMin(TYPE_BODY), Enemy->EnemyMax(TYPE_BODY)) && Normal_Count > 0)
				{
					Enemy->SetStopFront();
				}
			}
			
			Colision[2] = CheckBoxCollision(FrontWall->GetMin(), FrontWall->GetMax(), Camera->GetMin(), Camera->GetMax());
			if (Colision[2])
			{
				Camera->SetStopFront(true);
				break;
			}
			else
			{
				Camera->SetStopFront(false);
			}
		
			for (CBullet* Bullet : BulletList)
			{
				
				if (CheckBoxCollision(FrontWall->GetMin(), FrontWall->GetMax(), Bullet->GetMin(), Bullet->GetMax()) && Normal_Count > 0)
				{
					
					Bullet->SetDestroy();
				}
			}
		}
		for (CWall* BehindWall : BehindWallList)
		{
			for (CEbullet* EBullet : EbulletList)
			{
				
				if (CheckBoxCollision(BehindWall->GetMin(), BehindWall->GetMax(), EBullet->GetMin(), EBullet->GetMax()) && Normal_Count > 0)
				{
					EBullet->SetDestroy();
				}
			}
			for (CEnemy* Enemy : EnemyList)
			{
				
				if (CheckBoxCollision(BehindWall->GetMin(), BehindWall->GetMax(), Enemy->EnemyMin(TYPE_BODY), Enemy->EnemyMax(TYPE_BODY)) && Normal_Count > 0)
				{
					Enemy->SetStopBehind();
				}
			}
			Colision[3] = CheckBoxCollision(BehindWall->GetMin(), BehindWall->GetMax(), Camera->GetMin(), Camera->GetMax());
			if (Colision[3])
			{
				Camera->SetStopBack(true);
				break;
			}
			else
			{
				Camera->SetStopBack(false);
			}
		
			for (CBullet* Bullet : BulletList)
			{
				if (CheckBoxCollision(BehindWall->GetMin(), BehindWall->GetMax(), Bullet->GetMin(), Bullet->GetMax()) && Normal_Count > 0)
				{
					
					Bullet->SetDestroy();
				}
			}
		}
	}

	if (CManager::SceneGet<CStage4>())
	{
		C3dpolygon* S4_Door1 = CManager::GetScene()->GetGameObject<C3dpolygon>(1);
		C3dpolygon* S4_Door2 = CManager::GetScene()->GetGameObject<C3dpolygon>(2);
		C3dpolygon* S4_Jump = CManager::GetScene()->GetGameObject<C3dpolygon>(3);
		C3dpolygon* S4_Clear = CManager::GetScene()->GetGameObject<C3dpolygon>(4);

		std::vector<CField*> BridgeList = CManager::GetScene()->GetGameObjects<CField>(9);
		std::vector<CTrap*> ZTrapList = CManager::GetScene()->GetGameObjects<CTrap>(8);
		std::vector<CTrap*> SpikeList = CManager::GetScene()->GetGameObjects<CTrap>(9);
		if (CheckBoxCollision(S4_Clear->GetMin(), S4_Clear->GetMax(), Camera->GetMin(), Camera->GetMax()) && Normal_Count > 0)
		{
			if (S4_Clear->GetMin().x != -0.5f)
			{
				Camera->SetTeleport();
			}
		}
		for (CTrap* Trap : SpikeList)
		{
			if (CheckBoxCollision(Trap->GetMin(), Trap->GetMax(), Camera->GetMin(), Camera->GetMax()) && Normal_Count > 0)
			{
				if (EnemyDamage_Count > 60)
				{
					Camera->BackMove();
					scene->AddGameObject<CFade>(19)->SetObject(D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(50.0f, 50.0f, 0.0f), FADE_RED);
					Player->MinusHP();
					EnemyDamage_Count = 0;
					PlaySoundA(SOUND_LABEL_SE_PLAYER_DAMAGE);

				}
			}
		}
	
		for (CTrap* Trap : ZTrapList)
		{
			if (CheckBoxCollision(Trap->GetMin(), Trap->GetMax(), Camera->GetMin(), Camera->GetMax()) && Normal_Count > 0)
			{
				Camera->PlusPositionZ(Trap->GetSkullMove());
			}
		}
		for (CEattack* Eattack : EnemyAttackList)
		{
			if (CheckBoxCollision(Eattack->GetMin(), Eattack->GetMax(), Camera->GetMin(), Camera->GetMax()) && Normal_Count > 0)
			{
				if (EnemyDamage_Count > 60)
				{
					Camera->BackMove();
					scene->AddGameObject<CFade>(19)->SetObject(D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(50.0f, 50.0f, 0.0f), FADE_RED);
					if (Eattack->GetType() == ATTACK_BOOM)
					{
						Player->MinusHP(20);
					}
					else
					{
						Player->MinusHP();

					}
					EnemyDamage_Count = 0;
					PlaySoundA(SOUND_LABEL_SE_PLAYER_DAMAGE);
					Eattack->SetDestroy();

				}
			}
		}
		
		for (CEnemy* Enemy : EnemyList)
		{
			if (CheckBoxCollision(Enemy->EnemyMin(TYPE_BODY), Enemy->EnemyMax(TYPE_BODY), Camera->GetMin(), Camera->GetMax()) && Normal_Count > 0)
			{
				if (EnemyDamage_Count > 60)
				{
					Camera->BackMove();
					scene->AddGameObject<CFade>(19)->SetObject(D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(50.0f, 50.0f, 0.0f), FADE_RED);
					if (Enemy->GetType() == TYPE_TANK)
					{
						Player->MinusHP(20);
					}
					else
					{
						Player->MinusHP();

					}
					EnemyDamage_Count = 0;
					PlaySoundA(SOUND_LABEL_SE_PLAYER_DAMAGE);

				}
			}
			for (CBullet* Bullet : BulletList)
			{
				if (CheckBoxCollision(Enemy->EnemyMin(TYPE_HEAD), Enemy->EnemyMax(TYPE_HEAD), Bullet->GetMin(), Bullet->GetMax()) && Normal_Count > 0)
				{
					if (!Enemy->GetEnemyLife())
					{
						
							PlaySoundA(SOUND_LABEL_SE_ENEMY_HEADSHOT);
						
						
						Bullet->SetEffect(0);
						if (Enemy->GetType() != TYPE_TANK)
						{
							Enemy->StopBegin();
						}
						Bullet->SetDestroy();
						Enemy->MinusHp(20);
						Enemy->SetUnderattack();
					}
				}
				if (CheckBoxCollision(Enemy->EnemyMin(TYPE_BODY), Enemy->EnemyMax(TYPE_BODY), Bullet->GetMin(), Bullet->GetMax()) && Normal_Count > 0)
				{
					if (!Enemy->GetEnemyLife())
					{
						
							PlaySoundA(SOUND_LABEL_SE_ENEMY_HIT);
						

						Bullet->SetEffect(1);

						if (Enemy->GetType() != TYPE_TANK)
						{
							Enemy->StopBegin();
						}
						Bullet->SetDestroy();
						Enemy->MinusHp(10);
						Enemy->SetUnderattack();

					}
				}
			}
		}
		if (CheckBoxCollision(S4_Jump->GetMin(), S4_Jump->GetMax(), Camera->GetMin(), Camera->GetMax()) && Normal_Count > 0)
		{
			if (S4_Jump->GetMin().x != -0.5f)
			{
				Camera->SetJump();
			}
		}
		if (CheckBoxCollision(S4_Door1->GetMin(), S4_Door1->GetMax(), Camera->GetMin(), Camera->GetMax()) && Normal_Count > 0 && Camera->GetPosition().z < 165.0f)
		{
				if (S4_Door1->GetMin().x != -0.5f)
				{
					Camera->StopDoor();
					
						if (Camera->GetPosition().z >= 150.0f && Gate_Count == 0)
						{
							PlaySoundA(SOUND_LABEL_SE_PATTERNONE);

							S4_Door1->SetOpenDoor();
							Gate_Count++;
						}
					

				}
		}
		if (CheckBoxCollision(S4_Door2->GetMin(), S4_Door2->GetMax(), Camera->GetMin(), Camera->GetMax()) && Normal_Count > 0)
		{
			if (S4_Door2->GetMin().x != -0.5f)
			{
				Camera->StopDoor();
				for (CEnemy* Enemy : EnemyList)
				{
					if (Camera->GetPosition().z >= 415.0f && EnemyList.size() < 2 && Gate_Count == 1)
					{
						PlaySoundA(SOUND_LABEL_SE_PATTERNONE);

						S4_Door2->SetOpenDoor();
						Gate_Count++;
					}
				}
			}
		}
		for (CField* Bridge : BridgeList)
		{
			if (CheckBoxCollision(Bridge->GetMin(), Bridge->GetMax(), Camera->GetMin(), Camera->GetMax()) && Normal_Count > 0)
			{
				if (Bridge->GetMin().x != -0.5f)
				{
					Camera->SetGravityPower();
					Camera->PlusPositionX(Bridge->GetBridgeMove());
				}

			}
		}
		for (CField* Field : FieldList)
		{
			if (CheckBoxCollision(Field->GetMin(), Field->GetMax(), Camera->GetMin(), Camera->GetMax()) && Normal_Count > 0)
			{
				if (Field->GetMin().x != -0.5f)
				{
					Camera->SetGravityPower();
					break;
				}
			}
		}
		for (CWall* RightWall : RightWallList)
		{
			
			Colision[0] = CheckBoxCollision(RightWall->GetMin(), RightWall->GetMax(), Camera->GetMin(), Camera->GetMax());
			if (Colision[0])
			{
				Camera->SetStopRight(true);
				break;
			}
			else
			{
				Camera->SetStopRight(false);
			}
		
			for (CEnemy* Enemy : EnemyList)
			{
				if (CheckBoxCollision(RightWall->GetMin(), RightWall->GetMax(), Enemy->EnemyMin(TYPE_BODY), Enemy->EnemyMax(TYPE_BODY)) && Normal_Count > 0)
				{
					Enemy->SetStopRight();
				}
			}
			for (CEbullet* EBullet : EbulletList)
			{
				if (CheckBoxCollision(Camera->GetMin(), Camera->GetMax(), EBullet->GetMin(), EBullet->GetMax()) && Normal_Count > 0)
				{
					if (EnemyDamage_Count > 60)
					{
						Camera->BackMove();
						scene->AddGameObject<CFade>(19)->SetObject(D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(50.0f, 50.0f, 0.0f), FADE_RED);
						EBullet->SetDestroy();
						EnemyDamage_Count = 0;
						Player->MinusHP();
						PlaySoundA(SOUND_LABEL_SE_PLAYER_DAMAGE);


					}
				}
				if (CheckBoxCollision(RightWall->GetMin(), RightWall->GetMax(), EBullet->GetMin(), EBullet->GetMax()) && Normal_Count > 0)
				{
					EBullet->SetDestroy();
				}
			}
			for (CBullet* Bullet : BulletList)
			{
				if (CheckBoxCollision(RightWall->GetMin(), RightWall->GetMax(), Bullet->GetMin(), Bullet->GetMax()) && Normal_Count > 0)
				{
					
					scene->AddGameObject<CExplosion>(8)->SetTexture(GUN_HIT, SHOT_EFFECT_X, SHOT_EFFECT_Y, (Bullet->GetPosition() - Camera->GetFrontVec() * 1), D3DXVECTOR3(0.5f, 0.5f, 0.0f));
					Bullet->SetDestroy();
				}
			
			}
		
			
			
		}
		for (CWall* LeftWall : LeftWallList)
		{
			
			for (CEnemy* Enemy : EnemyList)
			{
				if (CheckBoxCollision(LeftWall->GetMin(), LeftWall->GetMax(), Enemy->EnemyMin(TYPE_BODY), Enemy->EnemyMax(TYPE_BODY)) && Normal_Count > 0)
				{
					Enemy->SetStopLeft();
				}
			}
			Colision[1] = CheckBoxCollision(LeftWall->GetMin(), LeftWall->GetMax(), Camera->GetMin(), Camera->GetMax());
			if (Colision[1])
			{
				Camera->SetStopLeft(true);
				break;
			}
			else
			{
				Camera->SetStopLeft(false);
			}
		
			for (CEbullet* EBullet : EbulletList)
			{
				if (CheckBoxCollision(LeftWall->GetMin(), LeftWall->GetMax(), EBullet->GetMin(), EBullet->GetMax()) && Normal_Count > 0)
				{
					EBullet->SetDestroy();
				}
			}
			for (CBullet* Bullet : BulletList)
			{
				if (CheckBoxCollision(LeftWall->GetMin(), LeftWall->GetMax(), Bullet->GetMin(), Bullet->GetMax()) && Normal_Count > 0)
				{
					
						scene->AddGameObject<CExplosion>(8)->SetTexture(GUN_HIT, SHOT_EFFECT_X, SHOT_EFFECT_Y, (Bullet->GetPosition() - Camera->GetFrontVec() * 1), D3DXVECTOR3(0.5f, 0.5f, 0.0f));
					
					Bullet->SetDestroy();
				}
			}
			
		}
		for (CWall* FrontWall : FrontWallList)
		{
			for (CEnemy* Enemy : EnemyList)
			{
				if (CheckBoxCollision(FrontWall->GetMin(), FrontWall->GetMax(), Enemy->EnemyMin(TYPE_BODY), Enemy->EnemyMax(TYPE_BODY)) && Normal_Count > 0)
				{
					Enemy->SetStopFront();
				}
			}
			Colision[2] = CheckBoxCollision(FrontWall->GetMin(), FrontWall->GetMax(), Camera->GetMin(), Camera->GetMax());
			if (Colision[2])
			{
				Camera->SetStopFront(true);
				break;
			}
			else
			{
				Camera->SetStopFront(false);
			}
		
			for (CEbullet* EBullet : EbulletList)
			{
				if (CheckBoxCollision(FrontWall->GetMin(), FrontWall->GetMax(), EBullet->GetMin(), EBullet->GetMax()) && Normal_Count > 0)
				{
					EBullet->SetDestroy();
				}
			}
			for (CBullet* Bullet : BulletList)
			{
				if (CheckBoxCollision(FrontWall->GetMin(), FrontWall->GetMax(), Bullet->GetMin(), Bullet->GetMax()) && Normal_Count > 0)
				{
					
						scene->AddGameObject<CExplosion>(8)->SetTexture(GUN_HIT, SHOT_EFFECT_X, SHOT_EFFECT_Y, (Bullet->GetPosition() - Camera->GetFrontVec() * 1), D3DXVECTOR3(0.5f, 0.5f, 0.0f));
					
					Bullet->SetDestroy();
				}
			}
			
		}
		for (CWall* BehindWall : BehindWallList)
		{
			for (CEnemy* Enemy : EnemyList)
			{
				if (CheckBoxCollision(BehindWall->GetMin(), BehindWall->GetMax(), Enemy->EnemyMin(TYPE_BODY), Enemy->EnemyMax(TYPE_BODY)) && Normal_Count > 0)
				{
					Enemy->SetStopBehind();
				}
			}
			Colision[3] = CheckBoxCollision(BehindWall->GetMin(), BehindWall->GetMax(), Camera->GetMin(), Camera->GetMax());
			if (Colision[3])
			{
				Camera->SetStopBack(true);
				break;
			}
			else
			{
				Camera->SetStopBack(false);
			}
		
			for (CEbullet* EBullet : EbulletList)
			{
				if (CheckBoxCollision(BehindWall->GetMin(), BehindWall->GetMax(), EBullet->GetMin(), EBullet->GetMax()) && Normal_Count > 0)
				{
					EBullet->SetDestroy();
				}
			}
			for (CBullet* Bullet : BulletList)
			{
				if (CheckBoxCollision(BehindWall->GetMin(), BehindWall->GetMax(), Bullet->GetMin(), Bullet->GetMax()) && Normal_Count > 0)
				{
					
					scene->AddGameObject<CExplosion>(8)->SetTexture(GUN_HIT, SHOT_EFFECT_X, SHOT_EFFECT_Y, (Bullet->GetPosition() - Camera->GetFrontVec() * 1), D3DXVECTOR3(0.5f, 0.5f, 0.0f));
					
					Bullet->SetDestroy();
				}
			}
			
		}
	}

	if (CManager::SceneGet<CStage5>())
	{
		std::vector<CRail*> RailList = CManager::GetScene()->GetGameObjects<CRail>(8);
		std::vector<CField*> BridgeList = CManager::GetScene()->GetGameObjects<CField>(9);

		C3dpolygon* S5_Door1 = CManager::GetScene()->GetGameObject<C3dpolygon>(1);
		C3dpolygon* S5_Door2 = CManager::GetScene()->GetGameObject<C3dpolygon>(2);
		C3dpolygon* S5_Clear = CManager::GetScene()->GetGameObject<C3dpolygon>(4);

		std::vector<CTrap*> ZTrapList = CManager::GetScene()->GetGameObjects<CTrap>(8);
		if (CheckBoxCollision(S5_Clear->GetMin(), S5_Clear->GetMax(), Camera->GetMin(), Camera->GetMax()) && Normal_Count > 0)
		{
			if (S5_Clear->GetMin().x != -0.5f)
			{
				Camera->SetTeleport();
			}
		}
		for (CWall* RightWall : RightWallList)
		{
			Colision[0] = CheckBoxCollision(RightWall->GetMin(), RightWall->GetMax(), Camera->GetMin(), Camera->GetMax());
			if (Colision[0])
			{
				Camera->SetStopRight(true);
				break;
			}
			else
			{
				Camera->SetStopRight(false);
			}
	
			for (CEnemy* Enemy : EnemyList)
			{
				if (CheckBoxCollision(RightWall->GetMin(), RightWall->GetMax(), Enemy->EnemyMin(TYPE_BODY), Enemy->EnemyMax(TYPE_BODY)) && Normal_Count > 0)
				{
					Enemy->SetStopRight();
				}
			}
			for (CEbullet* EBullet : EbulletList)
			{
				if (CheckBoxCollision(Camera->GetMin(), Camera->GetMax(), EBullet->GetMin(), EBullet->GetMax()) && Normal_Count > 0)
				{
					if (EnemyDamage_Count > 60)
					{
						Camera->BackMove();
						scene->AddGameObject<CFade>(19)->SetObject(D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(50.0f, 50.0f, 0.0f), FADE_RED);
						EBullet->SetDestroy();
						EnemyDamage_Count = 0;
						Player->MinusHP();
						PlaySoundA(SOUND_LABEL_SE_PLAYER_DAMAGE);


					}
				}
				if (CheckBoxCollision(RightWall->GetMin(), RightWall->GetMax(), EBullet->GetMin(), EBullet->GetMax()) && Normal_Count > 0)
				{
					EBullet->SetDestroy();
				}
			}
			for (CBullet* Bullet : BulletList)
			{
				if (CheckBoxCollision(RightWall->GetMin(), RightWall->GetMax(), Bullet->GetMin(), Bullet->GetMax()) && Normal_Count > 0)
				{

					scene->AddGameObject<CExplosion>(8)->SetTexture(GUN_HIT, SHOT_EFFECT_X, SHOT_EFFECT_Y, (Bullet->GetPosition() - Camera->GetFrontVec() * 1), D3DXVECTOR3(0.5f, 0.5f, 0.0f));
					Bullet->SetDestroy();
				}

			}



		}
		for (CWall* LeftWall : LeftWallList)
		{

			for (CEnemy* Enemy : EnemyList)
			{
				if (CheckBoxCollision(LeftWall->GetMin(), LeftWall->GetMax(), Enemy->EnemyMin(TYPE_BODY), Enemy->EnemyMax(TYPE_BODY)) && Normal_Count > 0)
				{
					Enemy->SetStopLeft();
				}
			}
			Colision[1] = CheckBoxCollision(LeftWall->GetMin(), LeftWall->GetMax(), Camera->GetMin(), Camera->GetMax());
			if (Colision[1])
			{
				Camera->SetStopLeft(true);
				break;
			}
			else
			{
				Camera->SetStopLeft(false);
			}
	
			for (CEbullet* EBullet : EbulletList)
			{
				if (CheckBoxCollision(LeftWall->GetMin(), LeftWall->GetMax(), EBullet->GetMin(), EBullet->GetMax()) && Normal_Count > 0)
				{
					EBullet->SetDestroy();
				}
			}
			for (CBullet* Bullet : BulletList)
			{
				if (CheckBoxCollision(LeftWall->GetMin(), LeftWall->GetMax(), Bullet->GetMin(), Bullet->GetMax()) && Normal_Count > 0)
				{

					scene->AddGameObject<CExplosion>(8)->SetTexture(GUN_HIT, SHOT_EFFECT_X, SHOT_EFFECT_Y, (Bullet->GetPosition() - Camera->GetFrontVec() * 1), D3DXVECTOR3(0.5f, 0.5f, 0.0f));

					Bullet->SetDestroy();
				}
			}

		}
		for (CWall* FrontWall : FrontWallList)
		{
			for (CEnemy* Enemy : EnemyList)
			{
				if (CheckBoxCollision(FrontWall->GetMin(), FrontWall->GetMax(), Enemy->EnemyMin(TYPE_BODY), Enemy->EnemyMax(TYPE_BODY)) && Normal_Count > 0)
				{
					Enemy->SetStopFront();
				}
			}
			Colision[2] = CheckBoxCollision(FrontWall->GetMin(), FrontWall->GetMax(), Camera->GetMin(), Camera->GetMax());
			if (Colision[2])
			{
				Camera->SetStopFront(true);
				break;
			}
			else
			{
				Camera->SetStopFront(false);
			}
	
			for (CEbullet* EBullet : EbulletList)
			{
				if (CheckBoxCollision(FrontWall->GetMin(), FrontWall->GetMax(), EBullet->GetMin(), EBullet->GetMax()) && Normal_Count > 0)
				{
					EBullet->SetDestroy();
				}
			}
			for (CBullet* Bullet : BulletList)
			{
				if (CheckBoxCollision(FrontWall->GetMin(), FrontWall->GetMax(), Bullet->GetMin(), Bullet->GetMax()) && Normal_Count > 0)
				{

					scene->AddGameObject<CExplosion>(8)->SetTexture(GUN_HIT, SHOT_EFFECT_X, SHOT_EFFECT_Y, (Bullet->GetPosition() - Camera->GetFrontVec() * 1), D3DXVECTOR3(0.5f, 0.5f, 0.0f));

					Bullet->SetDestroy();
				}
			}

		}
		for (CWall* BehindWall : BehindWallList)
		{
			for (CEnemy* Enemy : EnemyList)
			{
				if (CheckBoxCollision(BehindWall->GetMin(), BehindWall->GetMax(), Enemy->EnemyMin(TYPE_BODY), Enemy->EnemyMax(TYPE_BODY)) && Normal_Count > 0)
				{
					Enemy->SetStopBehind();
				}
			}
			Colision[2] = CheckBoxCollision(BehindWall->GetMin(), BehindWall->GetMax(), Camera->GetMin(), Camera->GetMax());
			if (Colision[2])
			{
				Camera->SetStopBack(true);
				break;
			}
			else
			{
				Camera->SetStopBack(false);
			}
		
			for (CEbullet* EBullet : EbulletList)
			{
				if (CheckBoxCollision(BehindWall->GetMin(), BehindWall->GetMax(), EBullet->GetMin(), EBullet->GetMax()) && Normal_Count > 0)
				{
					EBullet->SetDestroy();
				}
			}
			for (CBullet* Bullet : BulletList)
			{
				if (CheckBoxCollision(BehindWall->GetMin(), BehindWall->GetMax(), Bullet->GetMin(), Bullet->GetMax()) && Normal_Count > 0)
				{

					scene->AddGameObject<CExplosion>(8)->SetTexture(GUN_HIT, SHOT_EFFECT_X, SHOT_EFFECT_Y, (Bullet->GetPosition() - Camera->GetFrontVec() * 1), D3DXVECTOR3(0.5f, 0.5f, 0.0f));

					Bullet->SetDestroy();
				}
			}

		}
		for (CTrap* Trap : ZTrapList)
		{
			if (CheckBoxCollision(Trap->GetMin(), Trap->GetMax(), Camera->GetMin(), Camera->GetMax()) && Normal_Count > 0)
			{
				Camera->PlusPositionZ(Trap->GetSkullMove());
			}
		}
		if (CheckBoxCollision(S5_Door1->GetMin(), S5_Door1->GetMax(), Camera->GetMin(), Camera->GetMax()) && Normal_Count > 0 )
		{
			if (S5_Door1->GetMin().x != -0.5f)
			{
				Camera->StopBDoor();
			}
		}
		if (CheckBoxCollision(S5_Door2->GetMin(), S5_Door2->GetMax(), Camera->GetMin(), Camera->GetMax()) && Normal_Count > 0 )
		{
			if (S5_Door2->GetMin().x != -0.5f)
			{
				Camera->StopDoor();

				if (Camera->GetPosition().z >= 185.0f && Gate_Count == 0)
				{
					PlaySoundA(SOUND_LABEL_SE_PATTERNONE);
					S5_Door1->SetOpenDoor();
					S5_Door2->SetOpenDoor();
					Gate_Count++;
				}


			}
		}
		for (CEattack* Eattack : EnemyAttackList)
		{
			if (CheckBoxCollision(Eattack->GetMin(), Eattack->GetMax(), Camera->GetMin(), Camera->GetMax()) && Normal_Count > 0)
			{
				if (EnemyDamage_Count > 60)
				{
					Camera->BackMove();
					scene->AddGameObject<CFade>(19)->SetObject(D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(50.0f, 50.0f, 0.0f), FADE_RED);
					if (Eattack->GetType() == ATTACK_BOOM)
					{
						Player->MinusHP(20);
					}
					else
					{
						Player->MinusHP();

					}
					EnemyDamage_Count = 0;
					PlaySoundA(SOUND_LABEL_SE_PLAYER_DAMAGE);
					Eattack->SetDestroy();

				}
			}
		}
		for (CRail* Rail : RailList)
		{
			if (CheckBoxCollision(Rail->GetMin(), Rail->GetMax(), Camera->GetMin(), Camera->GetMax()) && Normal_Count > 0)
			{
				if (Rail->GetMin().x != -0.5f)
				{

					if (Rail->GetType() == RIGHTRAIL)
					{
						Camera->RailMove(D3DXVECTOR3(0.3f, 0.0f, 0.0f));
					}
					else if (Rail->GetType() == LEFTRAIL)
					{
						Camera->RailMove(D3DXVECTOR3(-0.3f, 0.0f, 0.0f));

					}
					else if (Rail->GetType() == DOWNRAIL)
					{
						Camera->RailMove(D3DXVECTOR3(0.0f, 0.0f, -0.2f));

					}
					Camera->SetGravityPower();
					break;
				}

			}
		}
		for (CEnemy* Enemy : EnemyList)
		{
			if (CheckBoxCollision(Enemy->EnemyMin(TYPE_BODY), Enemy->EnemyMax(TYPE_BODY), Camera->GetMin(), Camera->GetMax()) && Normal_Count > 0)
			{
				if (EnemyDamage_Count > 60)
				{
					Camera->BackMove();
					scene->AddGameObject<CFade>(19)->SetObject(D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(50.0f, 50.0f, 0.0f), FADE_RED);
					if (Enemy->GetType() == TYPE_TANK)
					{
						Player->MinusHP(20);
					}
					else
					{
						Player->MinusHP();

					}
					EnemyDamage_Count = 0;
					PlaySoundA(SOUND_LABEL_SE_PLAYER_DAMAGE);

				}
			}
			for (CBullet* Bullet : BulletList)
			{
				if (CheckBoxCollision(Enemy->EnemyMin(TYPE_HEAD), Enemy->EnemyMax(TYPE_HEAD), Bullet->GetMin(), Bullet->GetMax()) && Normal_Count > 0)
				{
					if (!Enemy->GetEnemyLife())
					{

						PlaySoundA(SOUND_LABEL_SE_ENEMY_HEADSHOT);


						Bullet->SetEffect(0);
						if (Enemy->GetType() != TYPE_TANK)
						{
							Enemy->StopBegin();
						}
						Bullet->SetDestroy();
						Enemy->MinusHp(20);
						Enemy->SetUnderattack();
					}
				}
				if (CheckBoxCollision(Enemy->EnemyMin(TYPE_BODY), Enemy->EnemyMax(TYPE_BODY), Bullet->GetMin(), Bullet->GetMax()) && Normal_Count > 0)
				{
					if (!Enemy->GetEnemyLife())
					{

						PlaySoundA(SOUND_LABEL_SE_ENEMY_HIT);


						Bullet->SetEffect(1);

						if (Enemy->GetType() != TYPE_TANK)
						{
							Enemy->StopBegin();
						}
						Bullet->SetDestroy();
						Enemy->MinusHp(10);
						Enemy->SetUnderattack();

					}
				}
			}
		}
		
	
		for (CField* Bridge : BridgeList)
		{
			if (CheckBoxCollision(Bridge->GetMin(), Bridge->GetMax(), Camera->GetMin(), Camera->GetMax()) && Normal_Count > 0)
			{
				if (Bridge->GetMin().x != -0.5f)
				{
					Camera->SetGravityPower();
					break;
				}
			}
		}
		for (CField* Field : FieldList)
		{
			if (CheckBoxCollision(Field->GetMin(), Field->GetMax(), Camera->GetMin(), Camera->GetMax()) && Normal_Count > 0)
			{
				if (Field->GetMin().x != -0.5f)
				{
					Camera->SetGravityPower();
					break;
				}
			}
		}
	
			for (CEbullet* EBullet : EbulletList)
			{
				if (CheckBoxCollision(Camera->GetMin(), Camera->GetMax(), EBullet->GetMin(), EBullet->GetMax()) && Normal_Count > 0)
				{
					if (EnemyDamage_Count > 60)
					{
						Camera->BackMove();
						scene->AddGameObject<CFade>(19)->SetObject(D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(50.0f, 50.0f, 0.0f), FADE_RED);
						EBullet->SetDestroy();
						EnemyDamage_Count = 0;
						Player->MinusHP();
						PlaySoundA(SOUND_LABEL_SE_PLAYER_DAMAGE);


					}
				}
				
			}
			



		
		
	}

	if (CManager::SceneGet<CStage6>())
	{
		std::vector<CAttack*> AttackList = CManager::GetScene()->GetGameObjects<CAttack>(8);
		std::vector<CTrap*> SpikeList = CManager::GetScene()->GetGameObjects<CTrap>(5);
		std::vector<CTrap*> ZTrapList = CManager::GetScene()->GetGameObjects<CTrap>(6);
		C3dpolygon* S6_Door1 = CManager::GetScene()->GetGameObject<C3dpolygon>(1);
		C3dpolygon* S6_Door2 = CManager::GetScene()->GetGameObject<C3dpolygon>(2);
		
		for (CEnemy* Enemy : EnemyList)
		{
			for (CAttack* Attack : AttackList)
			{
				if (CheckBoxCollision(Enemy->EnemyMin(TYPE_BODY), Enemy->EnemyMax(TYPE_BODY), Attack->GetMin(), Attack->GetMax()) && Normal_Count > 0)
				{
					Enemy->MinusHp(1);
				}
				if (CheckBoxCollision(Enemy->EnemyMin(TYPE_HEAD), Enemy->EnemyMax(TYPE_HEAD), Attack->GetMin(), Attack->GetMax()) && Normal_Count > 0)
				{
					Enemy->MinusHp(1);
				}
			}
			if (CheckBoxCollision(Enemy->EnemyMin(TYPE_BODY), Enemy->EnemyMax(TYPE_BODY), Camera->GetMin(), Camera->GetMax()) && Normal_Count > 0)
			{
				if (EnemyDamage_Count > 60)
				{
					Camera->BackMove();
					scene->AddGameObject<CFade>(19)->SetObject(D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(50.0f, 50.0f, 0.0f), FADE_RED);
					if (Enemy->GetType() == TYPE_TANK)
					{
						Player->MinusHP(20);
					}
					else
					{
						Player->MinusHP();
					}
					EnemyDamage_Count = 0;
					PlaySoundA(SOUND_LABEL_SE_PLAYER_DAMAGE);

				}
			}
			for (CBullet* Bullet : BulletList)
			{
				if (CheckBoxCollision(Enemy->EnemyMin(TYPE_HEAD), Enemy->EnemyMax(TYPE_HEAD), Bullet->GetMin(), Bullet->GetMax()) && Normal_Count > 0)
				{
					if (!Enemy->GetEnemyLife())
					{

			
						if (Enemy->GetType() != TYPE_TANK)
						{
							Enemy->StopBegin();
						}
						if (Bullet->GetType() != BAZOOKA_BULLET)
						{
							PlaySoundA(SOUND_LABEL_SE_ENEMY_HEADSHOT);
							Bullet->SetEffect(0);
							Enemy->MinusHp(20);
							Enemy->SetUnderattack();
						}
						if (Bullet->GetType() == BAZOOKA_BULLET)
						{
							scene->AddGameObject<CAttack>(8)->SetObject(D3DXVECTOR3(Bullet->GetPosition() - Camera->GetFrontVec() * 3), D3DXVECTOR3(15.0f, 5.0f, 15.0f));
							scene->AddGameObject<CExplosion>(8)->SetTexture(BOOM_EFFECT, BOOM_EFFECT_X, BOOM_EFFECT_Y, D3DXVECTOR3(Bullet->GetPosition() - Camera->GetFrontVec() * 3), D3DXVECTOR3(10.0f, 5.0f, 0.0f));
							PlaySoundA(SOUND_LABEL_SE_BOSS_BOOM);

						}
						Bullet->SetDestroy();

					}
				}
				if (CheckBoxCollision(Enemy->EnemyMin(TYPE_BODY), Enemy->EnemyMax(TYPE_BODY), Bullet->GetMin(), Bullet->GetMax()) && Normal_Count > 0)
				{
					if (!Enemy->GetEnemyLife())
					{




						if (Enemy->GetType() != TYPE_TANK)
						{
							Enemy->StopBegin();
						}
						if (Bullet->GetType() != BAZOOKA_BULLET)
						{
							Bullet->SetEffect(1);
							PlaySoundA(SOUND_LABEL_SE_ENEMY_HIT);
							Enemy->MinusHp(10);
							Enemy->SetUnderattack();
						}
						if (Bullet->GetType() == BAZOOKA_BULLET)
						{
							scene->AddGameObject<CAttack>(8)->SetObject(D3DXVECTOR3(Bullet->GetPosition() - Camera->GetFrontVec() * 3), D3DXVECTOR3(15.0f, 5.0f, 15.0f));
							PlaySoundA(SOUND_LABEL_SE_BOSS_BOOM);

							scene->AddGameObject<CExplosion>(8)->SetTexture(BOOM_EFFECT, BOOM_EFFECT_X, BOOM_EFFECT_Y, D3DXVECTOR3(Bullet->GetPosition() - Camera->GetFrontVec() * 3), D3DXVECTOR3(10.0f, 5.0f, 0.0f));
						}
						Bullet->SetDestroy();

					}
				}
			}
		}
		if (CheckBoxCollision(S6_Door1->GetMin(), S6_Door1->GetMax(), Camera->GetMin(), Camera->GetMax()) && Normal_Count > 0)
		{
			if (S6_Door1->GetMin().x != -0.5f)
			{
				Camera->StopDoor();
			}
		}


		if (CheckBoxCollision(S6_Door2->GetMin(), S6_Door2->GetMax(), Camera->GetMin(), Camera->GetMax()) && Normal_Count > 0)
		{
			if (S6_Door2->GetMin().x != -0.5f)
			{
				Camera->StopDoor();
			}
		}
		for (CTrap* Trap : SpikeList)
		{
			if (CheckBoxCollision(Trap->GetMin(), Trap->GetMax(), Camera->GetMin(), Camera->GetMax()) && Normal_Count > 0)
			{
				if (EnemyDamage_Count > 60)
				{
					Camera->BackMove();
					scene->AddGameObject<CFade>(19)->SetObject(D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(50.0f, 50.0f, 0.0f), FADE_RED);
					Player->MinusHP();
					EnemyDamage_Count = 0;
					PlaySoundA(SOUND_LABEL_SE_PLAYER_DAMAGE);

				}
			}
		}
		for (CWall* RightWall : RightWallList)
		{
			Colision[0] = CheckBoxCollision(RightWall->GetMin(), RightWall->GetMax(), Camera->GetMin(), Camera->GetMax());
			if (Colision[0])
			{
				Camera->SetStopRight(true);
				break;
			}
			else
			{
				Camera->SetStopRight(false);
			}
		
			for (CEnemy* Enemy : EnemyList)
			{
				if (CheckBoxCollision(RightWall->GetMin(), RightWall->GetMax(), Enemy->EnemyMin(TYPE_BODY), Enemy->EnemyMax(TYPE_BODY)) && Normal_Count > 0)
				{
					Enemy->SetStopRight();
				}
			}
			for (CEbullet* EBullet : EbulletList)
			{
				if (CheckBoxCollision(Camera->GetMin(), Camera->GetMax(), EBullet->GetMin(), EBullet->GetMax()) && Normal_Count > 0)
				{
					if (EnemyDamage_Count > 60)
					{
						Camera->BackMove();
						scene->AddGameObject<CFade>(19)->SetObject(D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(50.0f, 50.0f, 0.0f), FADE_RED);
						EBullet->SetDestroy();
						EnemyDamage_Count = 0;
						Player->MinusHP();
						PlaySoundA(SOUND_LABEL_SE_PLAYER_DAMAGE);


					}
				}
				if (CheckBoxCollision(RightWall->GetMin(), RightWall->GetMax(), EBullet->GetMin(), EBullet->GetMax()) && Normal_Count > 0)
				{
					EBullet->SetDestroy();
				}
			}
			for (CBullet* Bullet : BulletList)
			{
				if (CheckBoxCollision(RightWall->GetMin(), RightWall->GetMax(), Bullet->GetMin(), Bullet->GetMax()) && Normal_Count > 0)
				{
					if (Bullet->GetType() != BAZOOKA_BULLET)
					{
						scene->AddGameObject<CExplosion>(8)->SetTexture(GUN_HIT, SHOT_EFFECT_X, SHOT_EFFECT_Y, (Bullet->GetPosition() - Camera->GetFrontVec() * 1), D3DXVECTOR3(0.5f, 0.5f, 0.0f));
					}
					else if (Bullet->GetType() == BAZOOKA_BULLET)
					{
						scene->AddGameObject<CAttack>(8)->SetObject(D3DXVECTOR3(Bullet->GetPosition() - Camera->GetFrontVec() * 3), D3DXVECTOR3(15.0f, 5.0f, 15.0f));
						PlaySoundA(SOUND_LABEL_SE_BOSS_BOOM);

						scene->AddGameObject<CExplosion>(8)->SetTexture(BOOM_EFFECT, BOOM_EFFECT_X, BOOM_EFFECT_Y, D3DXVECTOR3(Bullet->GetPosition() - Camera->GetFrontVec() * 3), D3DXVECTOR3(10.0f, 5.0f, 0.0f));
					}
					Bullet->SetDestroy();
				}

			}



		}
		for (CWall* LeftWall : LeftWallList)
		{

			for (CEnemy* Enemy : EnemyList)
			{
				if (CheckBoxCollision(LeftWall->GetMin(), LeftWall->GetMax(), Enemy->EnemyMin(TYPE_BODY), Enemy->EnemyMax(TYPE_BODY)) && Normal_Count > 0)
				{
					Enemy->SetStopLeft();
				}
			}

			Colision[1] = CheckBoxCollision(LeftWall->GetMin(), LeftWall->GetMax(), Camera->GetMin(), Camera->GetMax());
			if (Colision[1])
			{
				Camera->SetStopLeft(true);
				break;
			}
			else
			{
				Camera->SetStopLeft(false);
			}

			for (CEbullet* EBullet : EbulletList)
			{
				if (CheckBoxCollision(LeftWall->GetMin(), LeftWall->GetMax(), EBullet->GetMin(), EBullet->GetMax()) && Normal_Count > 0)
				{
					EBullet->SetDestroy();
				}
			}
			for (CBullet* Bullet : BulletList)
			{
				if (CheckBoxCollision(LeftWall->GetMin(), LeftWall->GetMax(), Bullet->GetMin(), Bullet->GetMax()) && Normal_Count > 0)
				{

					if (Bullet->GetType() != BAZOOKA_BULLET)
					{
						scene->AddGameObject<CExplosion>(8)->SetTexture(GUN_HIT, SHOT_EFFECT_X, SHOT_EFFECT_Y, (Bullet->GetPosition() - Camera->GetFrontVec() * 1), D3DXVECTOR3(0.5f, 0.5f, 0.0f));
					}
					else if (Bullet->GetType() == BAZOOKA_BULLET)
					{
						scene->AddGameObject<CAttack>(8)->SetObject(D3DXVECTOR3(Bullet->GetPosition() - Camera->GetFrontVec() * 3), D3DXVECTOR3(15.0f, 5.0f, 15.0f));
						PlaySoundA(SOUND_LABEL_SE_BOSS_BOOM);

						scene->AddGameObject<CExplosion>(8)->SetTexture(BOOM_EFFECT, BOOM_EFFECT_X, BOOM_EFFECT_Y, D3DXVECTOR3(Bullet->GetPosition() - Camera->GetFrontVec() * 3), D3DXVECTOR3(10.0f, 5.0f, 0.0f));
					}
					Bullet->SetDestroy();
				}
			}

		}
		for (CWall* FrontWall : FrontWallList)
		{
			for (CTrap* ZTrap : ZTrapList)
			{
				if (CheckBoxCollision(Camera->GetMin(), Camera->GetMax(), ZTrap->GetMin(), ZTrap->GetMax()) && Normal_Count > 0)
				{
					if (EnemyDamage_Count > 60)
					{
						Camera->BackMove();
						scene->AddGameObject<CFade>(19)->SetObject(D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(50.0f, 50.0f, 0.0f), FADE_RED);
						Player->MinusHP();
						EnemyDamage_Count = 0;
						PlaySoundA(SOUND_LABEL_SE_PLAYER_DAMAGE);

					}
				}
				if (CheckBoxCollision(FrontWall->GetMin(), FrontWall->GetMax(), ZTrap->GetMin(), ZTrap->GetMax()) && Normal_Count > 0)
				{
					ZTrap->SetZTrapMinusMove();
				}
			}
			for (CEnemy* Enemy : EnemyList)
			{
				if (CheckBoxCollision(FrontWall->GetMin(), FrontWall->GetMax(), Enemy->EnemyMin(TYPE_BODY), Enemy->EnemyMax(TYPE_BODY)) && Normal_Count > 0)
				{
					Enemy->SetStopFront();
				}
			}
			Colision[2] = CheckBoxCollision(FrontWall->GetMin(), FrontWall->GetMax(), Camera->GetMin(), Camera->GetMax());
			if (Colision[2])
			{
				Camera->SetStopFront(true);
				break;
			}
			else
			{
				Camera->SetStopFront(false);
			}
		
			for (CEbullet* EBullet : EbulletList)
			{
				if (CheckBoxCollision(FrontWall->GetMin(), FrontWall->GetMax(), EBullet->GetMin(), EBullet->GetMax()) && Normal_Count > 0)
				{
					EBullet->SetDestroy();
				}
			}
			for (CBullet* Bullet : BulletList)
			{
				if (CheckBoxCollision(FrontWall->GetMin(), FrontWall->GetMax(), Bullet->GetMin(), Bullet->GetMax()) && Normal_Count > 0)
				{

					if (Bullet->GetType() != BAZOOKA_BULLET)
					{
						scene->AddGameObject<CExplosion>(8)->SetTexture(GUN_HIT, SHOT_EFFECT_X, SHOT_EFFECT_Y, (Bullet->GetPosition() - Camera->GetFrontVec() * 1), D3DXVECTOR3(0.5f, 0.5f, 0.0f));
					}
					else if (Bullet->GetType() == BAZOOKA_BULLET)
					{
						scene->AddGameObject<CAttack>(8)->SetObject(D3DXVECTOR3(Bullet->GetPosition() - Camera->GetFrontVec() * 3), D3DXVECTOR3(15.0f, 5.0f, 15.0f));
						PlaySoundA(SOUND_LABEL_SE_BOSS_BOOM);

						scene->AddGameObject<CExplosion>(8)->SetTexture(BOOM_EFFECT, BOOM_EFFECT_X, BOOM_EFFECT_Y, D3DXVECTOR3(Bullet->GetPosition() - Camera->GetFrontVec() * 3), D3DXVECTOR3(10.0f, 5.0f, 0.0f));
					}
					Bullet->SetDestroy();
				}
			}

		}
		for (CWall* BehindWall : BehindWallList)
		{
			for (CTrap* ZTrap : ZTrapList)
			{
				if (CheckBoxCollision(Camera->GetMin(), Camera->GetMax(), ZTrap->GetMin(), ZTrap->GetMax()) && Normal_Count > 0)
				{
					if (EnemyDamage_Count > 60)
					{
						Camera->BackMove();
						scene->AddGameObject<CFade>(19)->SetObject(D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(50.0f, 50.0f, 0.0f), FADE_RED);
						Player->MinusHP();
						EnemyDamage_Count = 0;
						PlaySoundA(SOUND_LABEL_SE_PLAYER_DAMAGE);

					}
				}
				if (CheckBoxCollision(BehindWall->GetMin(), BehindWall->GetMax(), ZTrap->GetMin(), ZTrap->GetMax()) && Normal_Count > 0)
				{
					if (BehindWall->GetMin().x != -1.0f)
					ZTrap->SetZTrapPlusMove();
				}
			}
			for (CEnemy* Enemy : EnemyList)
			{
				if (CheckBoxCollision(BehindWall->GetMin(), BehindWall->GetMax(), Enemy->EnemyMin(TYPE_BODY), Enemy->EnemyMax(TYPE_BODY)) && Normal_Count > 0)
				{
					Enemy->SetStopBehind();
				}
			}
			Colision[3] = CheckBoxCollision(BehindWall->GetMin(), BehindWall->GetMax(), Camera->GetMin(), Camera->GetMax());
			if (Colision[3])
			{
				Camera->SetStopBack(true);
				break;
			}
			else
			{
				Camera->SetStopBack(false);
			}
	
			for (CEbullet* EBullet : EbulletList)
			{
				if (CheckBoxCollision(BehindWall->GetMin(), BehindWall->GetMax(), EBullet->GetMin(), EBullet->GetMax()) && Normal_Count > 0)
				{
					EBullet->SetDestroy();
				}
			}
			for (CBullet* Bullet : BulletList)
			{
				if (CheckBoxCollision(BehindWall->GetMin(), BehindWall->GetMax(), Bullet->GetMin(), Bullet->GetMax()) && Normal_Count > 0)
				{

					if (Bullet->GetType() != BAZOOKA_BULLET)
					{
						scene->AddGameObject<CExplosion>(8)->SetTexture(GUN_HIT, SHOT_EFFECT_X, SHOT_EFFECT_Y, (Bullet->GetPosition() - Camera->GetFrontVec() * 1), D3DXVECTOR3(0.5f, 0.5f, 0.0f));
					}
					else if (Bullet->GetType() == BAZOOKA_BULLET)
					{
						scene->AddGameObject<CAttack>(8)->SetObject(D3DXVECTOR3(Bullet->GetPosition() - Camera->GetFrontVec() * 3), D3DXVECTOR3(15.0f, 5.0f, 15.0f));
						PlaySoundA(SOUND_LABEL_SE_BOSS_BOOM);

						scene->AddGameObject<CExplosion>(8)->SetTexture(BOOM_EFFECT, BOOM_EFFECT_X, BOOM_EFFECT_Y, D3DXVECTOR3(Bullet->GetPosition() - Camera->GetFrontVec() * 3), D3DXVECTOR3(10.0f, 5.0f, 0.0f));
					}
					Bullet->SetDestroy();
				}
			}

		}
		for (CField* Field : FieldList)
		{
			
			if (CheckBoxCollision(Field->GetMin(), Field->GetMax(), Camera->GetMin(), Camera->GetMax()) && Normal_Count > 0)
			{
				if (Field->GetMin().x != -0.5f)
				{
					Camera->SetGravityPower();
					break;
				}
			}
		}
	}
	Normal_Count++;
}

bool CheckBoxCollision(D3DXVECTOR3 vMin1, D3DXVECTOR3 vMax1, D3DXVECTOR3 vMin2, D3DXVECTOR3 vMax2)
{
	if (vMin1.x <= vMax2.x && vMax1.x >= vMin2.x &&
		vMin1.y <= vMax2.y && vMax1.y >= vMin2.y &&
		vMin1.z >= vMax2.z && vMax1.z <= vMin2.z)
	{
		return true;
	}
	else
	{
		return false;
	}
}


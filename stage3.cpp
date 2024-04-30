#include "stage1.h"
#include "stage2.h"
#include "stage3.h"
#include "stage4.h"
#include "Player.h"
#include "filed.h"
#include "camera.h"
#include "light.h"
#include "scene.h"
#include "input.h"
#include "manager.h"
#include "title.h"
#include "collision.h"
#include "stagebreak.h"
#include "sound.h"
#include "Grid.h"
#include "Polygon.h"
#include "Number.h"
#include "3dpolygon.h"
#include "SkyDome.h"
void CStage3::Init()
{
	PatternReset();

	AddGameObject<CPlayer>(2);
	AddGameObject<CCamera>(0)->SetObject(D3DXVECTOR3(55.0f, 4.5f, -95.0f), D3DXVECTOR3(1.0f, 1.0f, 1.0f), TYPE_SETTING);

	AddGameObject<CPolygon>(11)->SetObject(D3DXVECTOR3(SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT *0.5f, 0.0f), D3DXVECTOR3(0.5f, 0.5f, 0.0f), AIM_TEXTURE);
	AddGameObject<CPolygon>(11)->SetObject(D3DXVECTOR3(SCREEN_WIDTH * 0.07f, SCREEN_HEIGHT *0.75f, 0.0f), D3DXVECTOR3(0.2f, 1.5f, 0.0f), HPGAGE_GRAY_TEXTURE);
	AddGameObject<CPolygon>(11)->SetObject(D3DXVECTOR3(SCREEN_WIDTH * 0.07f, SCREEN_HEIGHT *0.75f, 0.0f), D3DXVECTOR3(0.2f, 1.5f, 0.0f), HPGAGE_RED_TEXTURE);
	AddGameObject<CPolygon>(11)->SetObject(D3DXVECTOR3(SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT *0.05f, 0.0f), D3DXVECTOR3(1.0f, 0.5f, 0.0f), PAUSE_TEXTURE);




	AddGameObject<CNumber>(10)->SetTexture(HP_NUMBER, 3, D3DXVECTOR3(SCREEN_WIDTH * 0.0f, SCREEN_HEIGHT *0.825, 0.0f), D3DXVECTOR3(0.3f, 0.3f, 0.0f));
	{//Floor 1

		{//Tutorial


			{//•Ç

				AddGameObject<CWall>(4)->SetWall(LEFT_WALL, D3DXVECTOR3(40.0f, 5.0f, -50.0f), D3DXVECTOR3(1.0f, 5.0f, 50.0f));
				AddGameObject<CWall>(3)->SetWall(RIGHT_WALL, D3DXVECTOR3(70.0f, 5.0f, -50.0f), D3DXVECTOR3(1.0f, 5.0f, 50.0f));
			
				AddGameObject<CWall>(6)->SetWall(BEHIND_WALL, D3DXVECTOR3(40.0f, 5.0f, -50.0f), D3DXVECTOR3(10.0f, 5.0f, 1.0f));
				AddGameObject<CWall>(6)->SetWall(BEHIND_WALL, D3DXVECTOR3(60.0f, 5.0f, -50.0f), D3DXVECTOR3(10.0f, 5.0f, 1.0f));

				AddGameObject<CWall>(4)->SetWall(LEFT_WALL, D3DXVECTOR3(50.0f, 5.0f, -60.0f), D3DXVECTOR3(1.0f, 5.0f, 10.0f));
				AddGameObject<CWall>(3)->SetWall(RIGHT_WALL, D3DXVECTOR3(60.0f, 5.0f, -60.0f), D3DXVECTOR3(1.0f, 5.0f, 10.0f));

				AddGameObject<CWall>(5)->SetWall(FRONT_WALL, D3DXVECTOR3(40.0f, 5.0f, -60.0f), D3DXVECTOR3(10.0f, 5.0f, 1.0f));
				AddGameObject<CWall>(5)->SetWall(FRONT_WALL, D3DXVECTOR3(60.0f, 5.0f, -60.0f), D3DXVECTOR3(10.0f, 5.0f, 1.0f));

				AddGameObject<CWall>(3)->SetWall(RIGHT_WALL, D3DXVECTOR3(70.0f, 5.0f, -90.0f), D3DXVECTOR3(1.0f, 5.0f, 30.0f));
				AddGameObject<CWall>(4)->SetWall(LEFT_WALL, D3DXVECTOR3(40.0f, 5.0f, -90.0f), D3DXVECTOR3(1.0f, 5.0f, 30.0f));
			
				AddGameObject<CWall>(6)->SetWall(BEHIND_WALL, D3DXVECTOR3(40.0f, 5.0f, -90.0f), D3DXVECTOR3(10.0f, 5.0f, 1.0f));
				AddGameObject<CWall>(6)->SetWall(BEHIND_WALL, D3DXVECTOR3(60.0f, 5.0f, -90.0f), D3DXVECTOR3(10.0f, 5.0f, 1.0f));

				AddGameObject<CWall>(3)->SetWall(RIGHT_WALL, D3DXVECTOR3(60.0f, 5.0f, -100.0f), D3DXVECTOR3(1.0f, 5.0f, 10.0f));
				AddGameObject<CWall>(4)->SetWall(LEFT_WALL, D3DXVECTOR3(50.0f, 5.0f, -100.0f), D3DXVECTOR3(1.0f, 5.0f, 10.0f));

				AddGameObject<CWall>(6)->SetWall(BEHIND_WALL, D3DXVECTOR3(50.0f, 5.0f, -100.0f), D3DXVECTOR3(10.0f, 5.0f, 1.0f));

			}

		}
	{//•Ç

		AddGameObject<CWall>(3)->SetWall(RIGHT_WALL, D3DXVECTOR3(70.0f, 5.0f, 0.0f), D3DXVECTOR3(1.0f, 5.0f, 20.0f));

		AddGameObject<CWall>(4)->SetWall(LEFT_WALL, D3DXVECTOR3(40.0f, 5.0f, 0.0f), D3DXVECTOR3(1.0f, 5.0f, 20.0f));

		AddGameObject<CWall>(6)->SetWall(BEHIND_WALL, D3DXVECTOR3(20.0f, 5.0f, 20.0f), D3DXVECTOR3(20.0f, 5.0f, 1.0f));

		AddGameObject<CWall>(6)->SetWall(BEHIND_WALL, D3DXVECTOR3(70.0f, 5.0f, 20.0f), D3DXVECTOR3(20.0f, 5.0f, 1.0f));

		AddGameObject<CWall>(4)->SetWall(LEFT_WALL, D3DXVECTOR3(20.0f, 5.0f, 20.0f), D3DXVECTOR3(1.0f, 5.0f, 60.0f));

		AddGameObject<CWall>(3)->SetWall(RIGHT_WALL, D3DXVECTOR3(90.0f, 5.0f, 20.0f), D3DXVECTOR3(1.0f, 5.0f, 60.0f));

		AddGameObject<CWall>(5)->SetWall(FRONT_WALL, D3DXVECTOR3(20.0f, 5.0f, 80.0f), D3DXVECTOR3(20.0f, 5.0f, 1.0f));
		AddGameObject<CWall>(5)->SetWall(FRONT_WALL, D3DXVECTOR3(70.0f, 5.0f, 80.0f), D3DXVECTOR3(20.0f, 5.0f, 1.0f));

		AddGameObject<CWall>(3)->SetWall(RIGHT_WALL, D3DXVECTOR3(70.0f, 5.0f, 80.0f), D3DXVECTOR3(1.0f, 5.0f, 40.0f));
		AddGameObject<CWall>(4)->SetWall(LEFT_WALL, D3DXVECTOR3(40.0f, 5.0f, 80.0f), D3DXVECTOR3(1.0f, 5.0f, 40.0f));

		AddGameObject<CWall>(6)->SetWall(BEHIND_WALL, D3DXVECTOR3(10.0f, 5.0f, 120.0f), D3DXVECTOR3(30.0f, 5.0f, 1.0f));
		AddGameObject<CWall>(6)->SetWall(BEHIND_WALL, D3DXVECTOR3(70.0f, 5.0f, 120.0f), D3DXVECTOR3(30.0f, 5.0f, 1.0f));

		AddGameObject<CWall>(4)->SetWall(LEFT_WALL, D3DXVECTOR3(10.0f, 5.0f, 120.0f), D3DXVECTOR3(1.0f, 5.0f, 100.0f));
		AddGameObject<CWall>(3)->SetWall(RIGHT_WALL, D3DXVECTOR3(100.0f, 5.0f, 120.0f), D3DXVECTOR3(1.0f, 5.0f, 100.0f));

		AddGameObject<CWall>(5)->SetWall(FRONT_WALL, D3DXVECTOR3(10.0f, 5.0f, 220.0f), D3DXVECTOR3(30.0f, 5.0f, 1.0f));
		AddGameObject<CWall>(5)->SetWall(FRONT_WALL, D3DXVECTOR3(70.0f, 5.0f, 220.0f), D3DXVECTOR3(30.0f, 5.0f, 1.0f));

		AddGameObject<CWall>(4)->SetWall(LEFT_WALL, D3DXVECTOR3(40.0f, 5.0f, 220.0f), D3DXVECTOR3(1.0f, 5.0f, 20.0f));
		AddGameObject<CWall>(3)->SetWall(RIGHT_WALL, D3DXVECTOR3(70.0f, 5.0f, 220.0f), D3DXVECTOR3(1.0f, 5.0f, 20.0f));

		AddGameObject<CWall>(5)->SetWall(FRONT_WALL, D3DXVECTOR3(40.0f, 5.0f, 240.0f), D3DXVECTOR3(30.0f, 5.0f, 1.0f));
	}
		{//Pillar
			AddGameObject<CWall>(5)->SetWall(FRONT_WALL, D3DXVECTOR3(30.0f, 5.0f, 60.0f), D3DXVECTOR3(5.0f, 5.0f, 1.0f), PILLAR);
			AddGameObject<CWall>(3)->SetWall(RIGHT_WALL, D3DXVECTOR3(30.0f, 5.0f, 60.0f), D3DXVECTOR3(1.0f, 5.0f, 5.0f), PILLAR);
			AddGameObject<CWall>(4)->SetWall(LEFT_WALL, D3DXVECTOR3(35.0f, 5.0f, 60.0f), D3DXVECTOR3(1.0f, 5.0f, 5.0f), PILLAR);
			AddGameObject<CWall>(6)->SetWall(BEHIND_WALL, D3DXVECTOR3(30.0f, 5.0f, 65.0f), D3DXVECTOR3(5.0f, 5.0f, 1.0f), PILLAR);

			AddGameObject<CWall>(5)->SetWall(FRONT_WALL, D3DXVECTOR3(30.0f, 5.0f, 30.0f), D3DXVECTOR3(5.0f, 5.0f, 1.0f), PILLAR);
			AddGameObject<CWall>(3)->SetWall(RIGHT_WALL, D3DXVECTOR3(30.0f, 5.0f, 30.0f), D3DXVECTOR3(1.0f, 5.0f, 5.0f), PILLAR);
			AddGameObject<CWall>(4)->SetWall(LEFT_WALL, D3DXVECTOR3(35.0f, 5.0f, 30.0f), D3DXVECTOR3(1.0f, 5.0f, 5.0f), PILLAR);
			AddGameObject<CWall>(6)->SetWall(BEHIND_WALL, D3DXVECTOR3(30.0f, 5.0f, 35.0f), D3DXVECTOR3(5.0f, 5.0f, 1.0f), PILLAR);

			AddGameObject<CWall>(5)->SetWall(FRONT_WALL, D3DXVECTOR3(70.0f, 5.0f, 30.0f), D3DXVECTOR3(5.0f, 5.0f, 1.0f), PILLAR);
			AddGameObject<CWall>(3)->SetWall(RIGHT_WALL, D3DXVECTOR3(70.0f, 5.0f, 30.0f), D3DXVECTOR3(1.0f, 5.0f, 5.0f), PILLAR);
			AddGameObject<CWall>(4)->SetWall(LEFT_WALL, D3DXVECTOR3(75.0f, 5.0f, 30.0f), D3DXVECTOR3(1.0f, 5.0f, 5.0f), PILLAR);
			AddGameObject<CWall>(6)->SetWall(BEHIND_WALL, D3DXVECTOR3(70.0f, 5.0f, 35.0f), D3DXVECTOR3(5.0f, 5.0f, 1.0f), PILLAR);

			AddGameObject<CWall>(5)->SetWall(FRONT_WALL, D3DXVECTOR3(70.0f, 5.0f, 60.0f), D3DXVECTOR3(5.0f, 5.0f, 1.0f), PILLAR);
			AddGameObject<CWall>(3)->SetWall(RIGHT_WALL, D3DXVECTOR3(70.0f, 5.0f, 60.0f), D3DXVECTOR3(1.0f, 5.0f, 5.0f), PILLAR);
			AddGameObject<CWall>(4)->SetWall(LEFT_WALL, D3DXVECTOR3(75.0f, 5.0f, 60.0f), D3DXVECTOR3(1.0f, 5.0f, 5.0f), PILLAR);
			AddGameObject<CWall>(6)->SetWall(BEHIND_WALL, D3DXVECTOR3(70.0f, 5.0f, 65.0f), D3DXVECTOR3(5.0f, 5.0f, 1.0f), PILLAR);

			AddGameObject<CWall>(5)->SetWall(FRONT_WALL, D3DXVECTOR3(20.0f, 5.0f, 140.0f), D3DXVECTOR3(10.0f, 5.0f, 1.0f), PILLAR);
			AddGameObject<CWall>(3)->SetWall(RIGHT_WALL, D3DXVECTOR3(20.0f, 5.0f, 140.0f), D3DXVECTOR3(1.0f, 5.0f, 80.0f), PILLAR);
			AddGameObject<CWall>(4)->SetWall(LEFT_WALL, D3DXVECTOR3(30.0f, 5.0f, 140.0f), D3DXVECTOR3(1.0f, 5.0f, 80.0f), PILLAR);

			AddGameObject<CWall>(5)->SetWall(FRONT_WALL, D3DXVECTOR3(80.0f, 5.0f, 140.0f), D3DXVECTOR3(10.0f, 5.0f, 1.0f), PILLAR);
			AddGameObject<CWall>(3)->SetWall(RIGHT_WALL, D3DXVECTOR3(80.0f, 5.0f, 140.0f), D3DXVECTOR3(1.0f, 5.0f, 80.0f), PILLAR);
			AddGameObject<CWall>(4)->SetWall(LEFT_WALL, D3DXVECTOR3(90.0f, 5.0f, 140.0f), D3DXVECTOR3(1.0f, 5.0f, 80.0f), PILLAR);

			AddGameObject<CWall>(5)->SetWall(FRONT_WALL, D3DXVECTOR3(30.0f, 5.0f, 140.0f), D3DXVECTOR3(20.0f, 5.0f, 1.0f), PILLAR);
			AddGameObject<CWall>(6)->SetWall(BEHIND_WALL, D3DXVECTOR3(30.0f, 5.0f, 150.0f), D3DXVECTOR3(20.0f, 5.0f, 1.0f), PILLAR);
			AddGameObject<CWall>(4)->SetWall(LEFT_WALL, D3DXVECTOR3(50.0f, 5.0f, 140.0f), D3DXVECTOR3(1.0f, 5.0f, 10.0f), PILLAR);

			AddGameObject<CWall>(5)->SetWall(FRONT_WALL, D3DXVECTOR3(60.0f, 5.0f, 140.0f), D3DXVECTOR3(20.0f, 5.0f, 1.0f), PILLAR);
			AddGameObject<CWall>(6)->SetWall(BEHIND_WALL, D3DXVECTOR3(60.0f, 5.0f, 150.0f), D3DXVECTOR3(20.0f, 5.0f, 1.0f), PILLAR);
			AddGameObject<CWall>(3)->SetWall(RIGHT_WALL, D3DXVECTOR3(60.0f, 5.0f, 140.0f), D3DXVECTOR3(1.0f, 5.0f, 10.0f), PILLAR);
		}
		{//Field
			AddGameObject<CField>(8)->SetField(D3DXVECTOR3(10.0f, 2.5f, -100.0f), D3DXVECTOR3(91.0f, 0.5f, 341.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 1.0f);
		}
		{//Ceiling

			AddGameObject<CField>(1)->SetField(D3DXVECTOR3(100.0f, 7.5f, -100.0f), D3DXVECTOR3(91.0f, 0.5f, 321.0f), D3DXVECTOR3(0.0f, 0.0f, D3DXToRadian(180.0f)), -1.0f,CEILING);
		}
		{//Pattern
			AddGameObject<C3dpolygon>(1)->SetObject(D3DXVECTOR3(55.5f, 4.5f, 145.0f), D3DXVECTOR3(4.0f, 2.0f, 2.0f), DOOR_1);
			AddGameObject<C3dpolygon>(2)->SetObject(D3DXVECTOR3(55.0f, 4.5f, 220.0f), D3DXVECTOR3(12.0f, 2.0f, 2.0f), DOOR_2);
			AddGameObject<C3dpolygon>(3)->SetObject(D3DXVECTOR3(55.0f, 3.0f, 230.0f), D3DXVECTOR3(1.5f, 0.2f, 1.5f), TELEPORT);
			AddGameObject<C3dpolygon>(4)->SetObject(D3DXVECTOR3(55.0f, 7.5f, 430.0f), D3DXVECTOR3(1.5f, 0.2f, 1.5f), TELEPORT);
			
			AddGameObject<C3dpolygon>(5)->SetObject(D3DXVECTOR3(55.0f, 4.5f, -60.0f), D3DXVECTOR3(4.0f, 2.0f, 2.0f), TUTORIALDOOR_1);
			AddGameObject<C3dpolygon>(6)->SetObject(D3DXVECTOR3(55.0f, 4.5f, -20.0f), D3DXVECTOR3(12.0f, 2.0f, 2.0f), TUTORIALDOOR_2);
			AddGameObject<C3dpolygon>(7)->SetObject(D3DXVECTOR3(55.0f, 3.0f, -50.0f), D3DXVECTOR3(0.3f, 0.3f, 0.3f), SMALLGUN_POLYGON);

		}
		{//Item
			AddGameObject<CItem>(9)->SetObject(D3DXVECTOR3(35.0f, 3.0f, 215.0f), D3DXVECTOR3(0.5f, 0.5f, 1.2f), TYPE_ITEM_BULLET);
			AddGameObject<CItem>(9)->SetObject(D3DXVECTOR3(75.0f, 3.0f, 215.0f), D3DXVECTOR3(0.5f, 0.5f, 1.2f), TYPE_ITEM_BULLET);
			AddGameObject<CItem>(9)->SetObject(D3DXVECTOR3(95.0f, 3.0f, 215.0f), D3DXVECTOR3(0.5f, 0.5f, 1.2f), TYPE_ITEM_KEY);

		}

		{//dummy
			AddGameObject<CEnemy>(8)->SetTexture(TYPE_WOLF, D3DXVECTOR3(0.0f, -230.5f, 42.0f), D3DXVECTOR3(2.0f, 1.0f, 2.0f), 40);
		}
	



	//{//Floor 2
	
		{//•Ç
			AddGameObject<CWall>(6)->SetWall(BEHIND_WALL, D3DXVECTOR3(40.0f, 10.0f, 220.0f), D3DXVECTOR3(30.0f, 5.0f, 1.0f));

			AddGameObject<CWall>(4)->SetWall(LEFT_WALL, D3DXVECTOR3(40.0f, 10.0f, 220.0f), D3DXVECTOR3(1.0f, 5.0f, 140.0f));
			AddGameObject<CWall>(3)->SetWall(RIGHT_WALL, D3DXVECTOR3(70.0f, 10.0f,220.0f), D3DXVECTOR3(1.0f, 5.0f, 140.0f));


			AddGameObject<CWall>(6)->SetWall(BEHIND_WALL, D3DXVECTOR3(10.0f, 10.0f, 360.0f), D3DXVECTOR3(30.0f, 5.0f, 1.0f));
			AddGameObject<CWall>(6)->SetWall(BEHIND_WALL, D3DXVECTOR3(70.0f, 10.0f, 360.0f), D3DXVECTOR3(30.0f, 5.0f, 1.0f));

			AddGameObject<CWall>(4)->SetWall(LEFT_WALL, D3DXVECTOR3(10.0f, 10.0f, 360.0f), D3DXVECTOR3(1.0f, 5.0f, 60.0f));
			AddGameObject<CWall>(3)->SetWall(RIGHT_WALL, D3DXVECTOR3(100.0f, 10.0f, 360.0f), D3DXVECTOR3(1.0f, 5.0f, 60.0f));

			AddGameObject<CWall>(5)->SetWall(FRONT_WALL, D3DXVECTOR3(10.0f, 10.0f, 420.0f), D3DXVECTOR3(30.0f, 5.0f, 1.0f));
			AddGameObject<CWall>(5)->SetWall(FRONT_WALL, D3DXVECTOR3(70.0f, 10.0f, 420.0f), D3DXVECTOR3(30.0f, 5.0f, 1.0f));

			AddGameObject<CWall>(3)->SetWall(RIGHT_WALL, D3DXVECTOR3(40.0f, 10.0f, 420.0f), D3DXVECTOR3(1.0f, 5.0f, 20.0f));
			AddGameObject<CWall>(4)->SetWall(LEFT_WALL, D3DXVECTOR3(70.0f, 10.0f, 420.0f), D3DXVECTOR3(1.0f, 5.0f, 20.0f));

			AddGameObject<CWall>(5)->SetWall(FRONT_WALL, D3DXVECTOR3(40.0f, 10.0f, 440.0f), D3DXVECTOR3(30.0f, 5.0f, 1.0f));
		}
		{//Pillar
			AddGameObject<CWall>(5)->SetWall(FRONT_WALL, D3DXVECTOR3(50.0f, 10.0f, 360.0f), D3DXVECTOR3(10.0f, 5.0f, 1.0f), PILLAR);
			AddGameObject<CWall>(3)->SetWall(RIGHT_WALL, D3DXVECTOR3(50.0f, 10.0f, 360.0f), D3DXVECTOR3(1.0f, 5.0f, 10.0f), PILLAR);
			AddGameObject<CWall>(4)->SetWall(LEFT_WALL, D3DXVECTOR3(60.0f, 10.0f, 360.0f), D3DXVECTOR3(1.0f, 5.0f, 10.0f), PILLAR);

			AddGameObject<CWall>(5)->SetWall(FRONT_WALL, D3DXVECTOR3(20.0f, 10.0f, 370.0f), D3DXVECTOR3(70.0f, 5.0f, 1.0f), PILLAR);
			AddGameObject<CWall>(3)->SetWall(RIGHT_WALL, D3DXVECTOR3(20.0f, 10.0f, 370.0f), D3DXVECTOR3(1.0f, 5.0f, 10.0f), PILLAR);
			AddGameObject<CWall>(4)->SetWall(LEFT_WALL, D3DXVECTOR3(90.0f, 10.0f, 370.0f), D3DXVECTOR3(1.0f, 5.0f, 10.0f), PILLAR);
			AddGameObject<CWall>(6)->SetWall(BEHIND_WALL, D3DXVECTOR3(20.0f, 10.0f, 380.0f), D3DXVECTOR3(70.0f, 5.0f, 1.0f), PILLAR);
		
			AddGameObject<CWall>(5)->SetWall(FRONT_WALL, D3DXVECTOR3(20.0f, 10.0f, 390.0f), D3DXVECTOR3(80.0f, 5.0f, 1.0f), PILLAR);
			AddGameObject<CWall>(3)->SetWall(RIGHT_WALL, D3DXVECTOR3(20.0f, 10.0f, 390.0f), D3DXVECTOR3(1.0f, 5.0f, 10.0f), PILLAR);
			AddGameObject<CWall>(6)->SetWall(BEHIND_WALL, D3DXVECTOR3(20.0f, 10.0f, 400.0f), D3DXVECTOR3(80.0f, 5.0f, 1.0f), PILLAR);

			AddGameObject<CWall>(5)->SetWall(FRONT_WALL, D3DXVECTOR3(10.0f, 10.0f, 410.0f), D3DXVECTOR3(50.0f, 5.0f, 1.0f), PILLAR);
			AddGameObject<CWall>(4)->SetWall(LEFT_WALL, D3DXVECTOR3(60.0f, 10.0f, 410.0f), D3DXVECTOR3(1.0f, 5.0f, 10.0f), PILLAR);
			AddGameObject<CWall>(6)->SetWall(BEHIND_WALL, D3DXVECTOR3(40.0f, 10.0f, 420.0f), D3DXVECTOR3(20.0f, 5.0f, 1.0f), PILLAR);
		}
		{//Field
			AddGameObject<CField>(8)->SetField(D3DXVECTOR3(10.0f, 7.5f, 241.5f), D3DXVECTOR3(91.0f, 0.5f, 221.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 1.0f);

		}
		{//Ceiling
			AddGameObject<CField>(1)->SetField(D3DXVECTOR3(100.0f, 12.5f, 221.5f), D3DXVECTOR3(91.0f, 0.5f, 241.0f), D3DXVECTOR3(0.0f, 0.0f, D3DXToRadian(180.0f)), -1.0f, CEILING);
		}
		{//Trap
			AddGameObject<CTrap>(8)->SetObject(D3DXVECTOR3(45.0f, 9.0f, 260.0f), D3DXVECTOR3(3.0f, 1.0f, 1.0f), SPIKE, D3DXVECTOR3(0.0f, 0.0f, 0.0f));
			AddGameObject<CTrap>(8)->SetObject(D3DXVECTOR3(48.0f, 9.0f, 260.0f), D3DXVECTOR3(3.0f, 1.0f, 1.0f), SPIKE, D3DXVECTOR3(0.0f, 0.0f, 0.0f));
			AddGameObject<CTrap>(8)->SetObject(D3DXVECTOR3(51.0f, 9.0f, 260.0f), D3DXVECTOR3(3.0f, 1.0f, 1.0f), SPIKE, D3DXVECTOR3(0.0f, 0.0f, 0.0f));
			AddGameObject<CTrap>(8)->SetObject(D3DXVECTOR3(54.0f, 9.0f, 260.0f), D3DXVECTOR3(3.0f, 1.0f, 1.0f), SPIKE, D3DXVECTOR3(0.0f, 0.0f, 0.0f));
			AddGameObject<CTrap>(8)->SetObject(D3DXVECTOR3(57.0f, 9.0f, 260.0f), D3DXVECTOR3(3.0f, 1.0f, 1.0f), SPIKE, D3DXVECTOR3(0.0f, 0.0f, 0.0f));
			AddGameObject<CTrap>(8)->SetObject(D3DXVECTOR3(60.0f, 9.0f, 260.0f), D3DXVECTOR3(3.0f, 1.0f, 1.0f), SPIKE, D3DXVECTOR3(0.0f, 0.0f, 0.0f));
			AddGameObject<CTrap>(8)->SetObject(D3DXVECTOR3(63.0f, 9.0f, 260.0f), D3DXVECTOR3(3.0f, 1.0f, 1.0f), SPIKE, D3DXVECTOR3(0.0f, 0.0f, 0.0f));
			
			AddGameObject<CTrap>(8)->SetObject(D3DXVECTOR3(68.0f, 9.0f, 270.0f), D3DXVECTOR3(3.0f, 1.0f, 1.0f), SPIKE, D3DXVECTOR3(0.0f, 0.0f, 0.0f));
			AddGameObject<CTrap>(8)->SetObject(D3DXVECTOR3(65.0f, 9.0f, 270.0f), D3DXVECTOR3(3.0f, 1.0f, 1.0f), SPIKE, D3DXVECTOR3(0.0f, 0.0f, 0.0f));
			AddGameObject<CTrap>(8)->SetObject(D3DXVECTOR3(62.0f, 9.0f, 270.0f), D3DXVECTOR3(3.0f, 1.0f, 1.0f), SPIKE, D3DXVECTOR3(0.0f, 0.0f, 0.0f));
			AddGameObject<CTrap>(8)->SetObject(D3DXVECTOR3(59.0f, 9.0f, 270.0f), D3DXVECTOR3(3.0f, 1.0f, 1.0f), SPIKE, D3DXVECTOR3(0.0f, 0.0f, 0.0f));
			AddGameObject<CTrap>(8)->SetObject(D3DXVECTOR3(56.0f, 9.0f, 270.0f), D3DXVECTOR3(3.0f, 1.0f, 1.0f), SPIKE, D3DXVECTOR3(0.0f, 0.0f, 0.0f));
			AddGameObject<CTrap>(8)->SetObject(D3DXVECTOR3(53.0f, 9.0f, 270.0f), D3DXVECTOR3(3.0f, 1.0f, 1.0f), SPIKE, D3DXVECTOR3(0.0f, 0.0f, 0.0f));
			AddGameObject<CTrap>(8)->SetObject(D3DXVECTOR3(50.0f, 9.0f, 270.0f), D3DXVECTOR3(3.0f, 1.0f, 1.0f), SPIKE, D3DXVECTOR3(0.0f, 0.0f, 0.0f));
			AddGameObject<CTrap>(8)->SetObject(D3DXVECTOR3(47.0f, 9.0f, 270.0f), D3DXVECTOR3(3.0f, 1.0f, 1.0f), SPIKE, D3DXVECTOR3(0.0f, 0.0f, 0.0f));

			AddGameObject<CTrap>(8)->SetObject(D3DXVECTOR3(45.0f, 9.0f, 290.0f), D3DXVECTOR3(1.0f, 0.3f, 0.3f), X_TRAP, D3DXVECTOR3(0.0f, D3DXToRadian(90.0f), 0.0f));
			AddGameObject<CTrap>(8)->SetObject(D3DXVECTOR3(45.0f, 9.0f, 296.0f), D3DXVECTOR3(1.0f, 0.3f, 0.3f), X_TRAP, D3DXVECTOR3(0.0f, D3DXToRadian(90.0f), 0.0f));

			AddGameObject<CTrap>(8)->SetObject(D3DXVECTOR3(68.0f, 9.0f, 310.0f), D3DXVECTOR3(1.0f, 0.3f, 0.3f), X_TRAP, D3DXVECTOR3(0.0f, D3DXToRadian(90.0f), 0.0f));
			AddGameObject<CTrap>(8)->SetObject(D3DXVECTOR3(68.0f, 9.0f, 316.0f), D3DXVECTOR3(1.0f, 0.3f, 0.3f), X_TRAP, D3DXVECTOR3(0.0f, D3DXToRadian(90.0f), 0.0f));
		

		}
		{//Item
			AddGameObject<CItem>(9)->SetObject(D3DXVECTOR3(54.0f, 8.0f, 265.0f), D3DXVECTOR3(0.5f, 0.5f, 1.2f), TYPE_ITEM_BULLET);
			AddGameObject<CItem>(9)->SetObject(D3DXVECTOR3(54.0f, 8.0f, 313.0f), D3DXVECTOR3(0.5f, 0.5f, 1.2f), TYPE_ITEM_BULLET);
			AddGameObject<CItem>(9)->SetObject(D3DXVECTOR3(54.0f, 8.0f, 333.0f), D3DXVECTOR3(0.5f, 0.5f, 1.2f), TYPE_ITEM_HEART);

			AddGameObject<CItem>(9)->SetObject(D3DXVECTOR3(15.0f, 8.0f, 385.0f), D3DXVECTOR3(0.5f, 0.5f, 1.2f), TYPE_ITEM_BULLET);
			AddGameObject<CItem>(9)->SetObject(D3DXVECTOR3(95.0f, 8.0f, 385.0f), D3DXVECTOR3(0.5f, 0.5f, 1.2f), TYPE_ITEM_BULLET);

			AddGameObject<CItem>(9)->SetObject(D3DXVECTOR3(75.0f, 8.0f, 415.0f), D3DXVECTOR3(0.5f, 0.5f, 1.2f), TYPE_ITEM_HEART);
		}
	
	}
	AddGameObject<CFade>(19)->CaeateFade();

}

void CStage3::Update()
{
	Collision_Update();

	CScene::Update();

	Pattern_Update();

	CFade* Fade = CManager::GetScene()->GetGameObject<CFade>(19);
	Fade->SetFadeOut();
	ShowCursor(false);
	SetCursorPos(1920 / 2, 1080 / 2);
	CCamera* Camera = CManager::GetScene()->GetGameObject<CCamera>(0);
	CScene* scene = CManager::GetScene();
	CPlayer* Player = CManager::GetScene()->GetGameObject<CPlayer>(2);

	if (Player->GetPlayerHp() <= 0)
	{
		Fade->SetFadeIn();
		if (Fade->GetFade() >= 1.0f)
		{
			CManager::SetScene<CStagebreak>();
			CStagebreak::SaveStage(STAGE3);

		}
	}
	if (Camera->GetTeleport() && Player->GetPlayerHp() > 0)
	{
		TeleportCount++;
		if (TeleportCount == 1)
		{
			scene->AddGameObject<CExplosion>(8)->SetTexture(CREATE_EFFECT, CREATE_EFFECT_X, CREATE_EFFECT_Y, Camera->GetPosition() + (Camera->GetFrontVec() * 2.0f), D3DXVECTOR3(15.0f, 10.0f, 0.0f));
			PlaySoundA(SOUND_LABEL_SE_SUMMONING);

		}
		if (TeleportCount == 70)
		{
			Fade->SetFadeIn();
		}
		if (Fade->GetFade() >= 1.0f)
		{
			ResetCollision();

			CManager::SetScene<CStage4>();
		}
	}

}

void CStage3::Uninit()
{
	CScene::Uninit();
	
}
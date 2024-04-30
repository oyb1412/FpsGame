#include "stage4.h"
#include "stage5.h"
#include "Player.h"
#include "filed.h"
#include "camera.h"
#include "light.h"
#include "scene.h"
#include "input.h"
#include "manager.h"
#include "title.h"
#include "collision.h"
#include "sound.h"
#include "Grid.h"
#include "Polygon.h"
#include "Number.h"
#include "3dpolygon.h"
#include "stagebreak.h"
#include "skybox.h"
#include "SkyDome.h"
void CStage4::Init()
{
	PatternReset();

	AddGameObject<CSkybox>(7)->SetObject(D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(25.0f, 5.0f, 25.0f));
	AddGameObject<CPlayer>(2);
	AddGameObject<CCamera>(0)->SetObject(D3DXVECTOR3(35.0f, 4.5f, 15.0f), D3DXVECTOR3(1.0f, 1.0f, 1.0f), TYPE_SETTING);

	AddGameObject<CPolygon>(12)->SetObject(D3DXVECTOR3(SCREEN_WIDTH *0.9f, SCREEN_HEIGHT *0.75f, 0.0f), D3DXVECTOR3(1.5f, 0.4f, 0.0f), SMALLGUN_UI_TEXTURE);
	AddGameObject<CPolygon>(15)->SetObject(D3DXVECTOR3(SCREEN_WIDTH *0.87f, SCREEN_HEIGHT *0.77f, 0.0f), D3DXVECTOR3(3.0f, 1.3f, 0.0f), CURSOR_TEXTURE);
	AddGameObject<CPolygon>(11)->SetObject(D3DXVECTOR3(SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT *0.5f, 0.0f), D3DXVECTOR3(0.5f, 0.5f, 0.0f), AIM_TEXTURE);
	AddGameObject<CPolygon>(11)->SetObject(D3DXVECTOR3(SCREEN_WIDTH * 0.07f, SCREEN_HEIGHT *0.75f, 0.0f), D3DXVECTOR3(0.2f, 1.5f, 0.0f), HPGAGE_GRAY_TEXTURE);
	AddGameObject<CPolygon>(11)->SetObject(D3DXVECTOR3(SCREEN_WIDTH * 0.07f, SCREEN_HEIGHT *0.75f, 0.0f), D3DXVECTOR3(0.2f, 1.5f, 0.0f), HPGAGE_RED_TEXTURE);
	AddGameObject<CPolygon>(11)->SetObject(D3DXVECTOR3(SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT *0.05f, 0.0f), D3DXVECTOR3(1.0f, 0.5f, 0.0f), PAUSE_TEXTURE);

	AddGameObject<CNumber>(10)->SetTexture(HP_NUMBER, 3, D3DXVECTOR3(SCREEN_WIDTH * 0.0f, SCREEN_HEIGHT *0.825, 0.0f), D3DXVECTOR3(0.3f, 0.3f, 0.0f));

	AddGameObject<CNumber>(10)->SetTexture(BULLET_NUMBER, 2, D3DXVECTOR3(SCREEN_WIDTH *0.75f, SCREEN_HEIGHT *0.8f, 0.0f), D3DXVECTOR3(0.3f, 0.3f, 0.0f));
	AddGameObject<CNumber>(10)->SetTexture(MAX_BULLET_NUMBER, 3, D3DXVECTOR3(SCREEN_WIDTH *0.85f, SCREEN_HEIGHT *0.85f, 0.0f), D3DXVECTOR3(0.3f, 0.3f, 0.0f));


		{//Wall
			AddGameObject<CWall>(4)->SetWall(LEFT_WALL, D3DXVECTOR3(10.0f, 5.0f, 0.0f), D3DXVECTOR3(1.0f, 5.0f, 30.0f), 0, GRASS);
			AddGameObject<CWall>(3)->SetWall(RIGHT_WALL, D3DXVECTOR3(60.0f, 5.0f, 0.0f), D3DXVECTOR3(1.0f, 5.0f, 30.0f), 0, GRASS);
			AddGameObject<CWall>(6)->SetWall(BEHIND_WALL, D3DXVECTOR3(10.0f, 5.0f, 0.0f), D3DXVECTOR3(50.0f, 5.0f, 1.0f), 0, GRASS);

			AddGameObject<CWall>(4)->SetWall(LEFT_WALL, D3DXVECTOR3(10.0f, 5.0f, 110.0f), D3DXVECTOR3(1.0f, 5.0f, 30.0f), 0, GRASS);
			AddGameObject<CWall>(3)->SetWall(RIGHT_WALL, D3DXVECTOR3(60.0f, 5.0f, 110.0f), D3DXVECTOR3(1.0f, 5.0f, 30.0f), 0, GRASS);
			AddGameObject<CWall>(5)->SetWall(FRONT_WALL, D3DXVECTOR3(10.0f, 5.0f, 140.0f), D3DXVECTOR3(20.0f, 5.0f, 1.0f), 0, GRASS);
			AddGameObject<CWall>(5)->SetWall(FRONT_WALL, D3DXVECTOR3(40.0f, 5.0f, 140.0f), D3DXVECTOR3(20.0f, 5.0f, 1.0f), 0, GRASS);

			AddGameObject<CWall>(6)->SetWall(BEHIND_WALL, D3DXVECTOR3(0.0f, 5.0f, 160.0f), D3DXVECTOR3(30.0f, 5.0f, 1.0f), 0, GRASS);
			AddGameObject<CWall>(6)->SetWall(BEHIND_WALL, D3DXVECTOR3(40.0f, 5.0f, 160.0f), D3DXVECTOR3(30.0f, 5.0f, 1.0f), 0, GRASS);

			AddGameObject<CWall>(4)->SetWall(LEFT_WALL, D3DXVECTOR3(0.0f, 5.0f, 160.0f), D3DXVECTOR3(1.0f, 5.0f, 50.0f), 0, GRASS);
			AddGameObject<CWall>(3)->SetWall(RIGHT_WALL, D3DXVECTOR3(70.0f, 5.0f, 160.0f), D3DXVECTOR3(1.0f, 5.0f, 50.0f), 0, GRASS);

			AddGameObject<CWall>(4)->SetWall(LEFT_WALL, D3DXVECTOR3(30.0f, 5.0f, 305.0f), D3DXVECTOR3(1.0f, 5.0f, 35.0f), 0, GRASS);
			AddGameObject<CWall>(3)->SetWall(RIGHT_WALL, D3DXVECTOR3(40.0f, 5.0f, 305.0f), D3DXVECTOR3(1.0f, 5.0f, 35.0f), 0, GRASS);

			AddGameObject<CWall>(6)->SetWall(BEHIND_WALL, D3DXVECTOR3(10.0f, 5.0f, 340.0f), D3DXVECTOR3(20.0f, 5.0f, 1.0f), 0, GRASS);
			AddGameObject<CWall>(6)->SetWall(BEHIND_WALL, D3DXVECTOR3(40.0f, 5.0f, 340.0f), D3DXVECTOR3(20.0f, 5.0f, 1.0f), 0, GRASS);

			AddGameObject<CWall>(4)->SetWall(LEFT_WALL, D3DXVECTOR3(10.0f, 5.0f, 340.0f), D3DXVECTOR3(1.0f, 5.0f, 5.0f), 0, GRASS);
			AddGameObject<CWall>(3)->SetWall(RIGHT_WALL, D3DXVECTOR3(60.0f, 5.0f, 340.0f), D3DXVECTOR3(1.0f, 5.0f, 5.0f), 0, GRASS);
	
			AddGameObject<CWall>(4)->SetWall(LEFT_WALL, D3DXVECTOR3(10.0f, 5.0f, 350.0f), D3DXVECTOR3(1.0f, 5.0f, 25.0f), 0, GRASS);
			AddGameObject<CWall>(3)->SetWall(RIGHT_WALL, D3DXVECTOR3(60.0f, 5.0f, 350.0f), D3DXVECTOR3(1.0f, 5.0f, 25.0f), 0, GRASS);
		
			AddGameObject<CWall>(4)->SetWall(LEFT_WALL, D3DXVECTOR3(10.0f, 5.0f, 380.0f), D3DXVECTOR3(1.0f, 5.0f, 25.0f), 0, GRASS);
			AddGameObject<CWall>(3)->SetWall(RIGHT_WALL, D3DXVECTOR3(60.0f, 5.0f, 380.0f), D3DXVECTOR3(1.0f, 5.0f, 25.0f), 0, GRASS);
	
			AddGameObject<CWall>(4)->SetWall(LEFT_WALL, D3DXVECTOR3(10.0f, 5.0f, 410.0f), D3DXVECTOR3(1.0f, 5.0f, 10.0f), 0, GRASS);
			AddGameObject<CWall>(3)->SetWall(RIGHT_WALL, D3DXVECTOR3(60.0f, 5.0f, 410.0f), D3DXVECTOR3(1.0f, 5.0f, 10.0f), 0, GRASS);
	
			AddGameObject<CWall>(5)->SetWall(FRONT_WALL, D3DXVECTOR3(10.0f, 5.0f, 420.0f), D3DXVECTOR3(20.0f, 5.0f, 1.0f), 0, GRASS);
			AddGameObject<CWall>(5)->SetWall(FRONT_WALL, D3DXVECTOR3(40.0f, 5.0f, 420.0f), D3DXVECTOR3(20.0f, 5.0f, 1.0f), 0, GRASS);
	
			AddGameObject<CWall>(4)->SetWall(LEFT_WALL, D3DXVECTOR3(30.0f, 5.0f, 420.0f), D3DXVECTOR3(1.0f, 5.0f, 10.0f), 0, GRASS);
			AddGameObject<CWall>(3)->SetWall(RIGHT_WALL, D3DXVECTOR3(40.0f, 5.0f, 420.0f), D3DXVECTOR3(1.0f, 5.0f, 10.0f), 0, GRASS);
	
			AddGameObject<CWall>(5)->SetWall(FRONT_WALL, D3DXVECTOR3(30.0f, 5.0f, 430.0f), D3DXVECTOR3(10.0f, 5.0f, 1.0f), 0, GRASS);

			AddGameObject<CWall>(5)->SetWall(FRONT_WALL, D3DXVECTOR3(5.0f, 5.0f, 510.0f), D3DXVECTOR3(60.0f, 5.0f, 1.0f), 0, GRASS);
			AddGameObject<CWall>(4)->SetWall(LEFT_WALL, D3DXVECTOR3(5.0f, 5.0f, 450.0f), D3DXVECTOR3(1.0f, 5.0f, 60.0f), 0, GRASS);
			AddGameObject<CWall>(3)->SetWall(RIGHT_WALL, D3DXVECTOR3(65.0f, 5.0f, 450.0f), D3DXVECTOR3(1.0f, 5.0f, 60.0f), 0, GRASS);
			AddGameObject<CWall>(6)->SetWall(BEHIND_WALL, D3DXVECTOR3(5.0f, 5.0f, 450.0f), D3DXVECTOR3(60.0f, 5.0f, 1.0f), 0, GRASS);

	}
		{//Field
			AddGameObject<CField>(8)->SetField(D3DXVECTOR3(10.0f, 2.5f, 0.0f), D3DXVECTOR3(50.0f, 0.5f, 30.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 1.0f);
			AddGameObject<CField>(8)->SetField(D3DXVECTOR3(10.0f, 2.5f, 110.0f), D3DXVECTOR3(50.0f, 0.5f, 30.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 1.0f);
			AddGameObject<CField>(8)->SetField(D3DXVECTOR3(30.0f, 2.5f, 140.0f), D3DXVECTOR3(10.0f, 0.5f, 20.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 1.0f);
			AddGameObject<CField>(8)->SetField(D3DXVECTOR3(0.0f, 2.5f, 160.0f), D3DXVECTOR3(70.0f, 0.5f, 50.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 1.0f);
			AddGameObject<CField>(8)->SetField(D3DXVECTOR3(30.0f, 2.5f, 305.0f), D3DXVECTOR3(10.0f, 0.5f, 35.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 1.0f);
			AddGameObject<CField>(8)->SetField(D3DXVECTOR3(10.0f, 2.5f, 340.0f), D3DXVECTOR3(50.0f, 0.5f, 5.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 1.0f);
			AddGameObject<CField>(8)->SetField(D3DXVECTOR3(10.0f, 2.5f, 350.0f), D3DXVECTOR3(50.0f, 0.5f, 25.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 1.0f);
			AddGameObject<CField>(8)->SetField(D3DXVECTOR3(10.0f, 2.5f, 380.0f), D3DXVECTOR3(50.0f, 0.5f, 25.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 1.0f);
			AddGameObject<CField>(8)->SetField(D3DXVECTOR3(10.0f, 2.5f, 410.0f), D3DXVECTOR3(50.0f, 0.5f, 10.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 1.0f);
			AddGameObject<CField>(8)->SetField(D3DXVECTOR3(30.0f, 2.5f, 420.0f), D3DXVECTOR3(10.0f, 0.5f, 10.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 1.0f);
			AddGameObject<CField>(8)->SetField(D3DXVECTOR3(5.0f, 2.5f, 450.0f), D3DXVECTOR3(60.0f, 0.5f, 60.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 1.0f);
		}
		{//Bridge
			AddGameObject<CField>(8)->SetField(D3DXVECTOR3(50.0f, 2.5f, 30.0f), D3DXVECTOR3(10.0f, 0.5f, 20.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 1.0f, 0, BRIDGE);
			AddGameObject<CField>(8)->SetField(D3DXVECTOR3(10.0f, 2.5f, 40.0f), D3DXVECTOR3(40.0f, 0.5f, 10.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 1.0f, 0, BRIDGE);
			AddGameObject<CField>(8)->SetField(D3DXVECTOR3(10.0f, 2.5f, 50.0f), D3DXVECTOR3(10.0f, 0.5f, 20.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 1.0f, 0, BRIDGE);
			AddGameObject<CField>(8)->SetField(D3DXVECTOR3(20.0f, 2.5f, 60.0f), D3DXVECTOR3(40.0f, 0.5f, 10.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 1.0f, 0, BRIDGE);
			AddGameObject<CField>(8)->SetField(D3DXVECTOR3(50.0f, 2.5f, 70.0f), D3DXVECTOR3(10.0f, 0.5f, 20.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 1.0f, 0, BRIDGE);
			AddGameObject<CField>(8)->SetField(D3DXVECTOR3(10.0f, 2.5f, 80.0f), D3DXVECTOR3(40.0f, 0.5f, 10.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 1.0f, 0, BRIDGE);
			AddGameObject<CField>(8)->SetField(D3DXVECTOR3(10.0f, 2.5f, 90.0f), D3DXVECTOR3(10.0f, 0.5f, 20.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 1.0f, 0, BRIDGE);
		}
		{//SmallBridge
			AddGameObject<CField>(9)->SetField(D3DXVECTOR3(60.0f, 2.5f, 215.0f), D3DXVECTOR3(10.0f, 0.5f, 10.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 1.0f,0,SMALLBRIDGE);
			AddGameObject<CField>(9)->SetField(D3DXVECTOR3(0.0f, 2.5f, 230.0f), D3DXVECTOR3(10.0f, 0.5f, 10.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 1.0f, 0, SMALLBRIDGE);
			AddGameObject<CField>(9)->SetField(D3DXVECTOR3(60.0f, 2.5f, 245.0f), D3DXVECTOR3(10.0f, 0.5f, 10.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 1.0f, 0, SMALLBRIDGE);
			AddGameObject<CField>(9)->SetField(D3DXVECTOR3(0.0f, 2.5f, 260.0f), D3DXVECTOR3(10.0f, 0.5f, 10.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 1.0f, 0, SMALLBRIDGE);
			AddGameObject<CField>(9)->SetField(D3DXVECTOR3(60.0f, 2.5f, 275.0f), D3DXVECTOR3(10.0f, 0.5f, 10.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 1.0f, 0, SMALLBRIDGE);
			AddGameObject<CField>(9)->SetField(D3DXVECTOR3(0.0f, 2.5f, 290.0f), D3DXVECTOR3(10.0f, 0.5f, 10.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 1.0f, 0, SMALLBRIDGE);
		}
		{//Trap
			AddGameObject<CTrap>(8)->SetObject(D3DXVECTOR3(25.0f, 5.0f, 35.0f), D3DXVECTOR3(2.0f, 2.0f, 2.0f), SKULL, D3DXVECTOR3(0.0f, D3DXToRadian(180.0f), 0.0f));
			AddGameObject<CTrap>(8)->SetObject(D3DXVECTOR3(45.0f, 5.0f, 95.0f), D3DXVECTOR3(2.0f, 2.0f, 2.0f), SKULL, D3DXVECTOR3(0.0f, 0.0f, 0.0f));
		
			AddGameObject<CTrap>(9)->SetObject(D3DXVECTOR3(13.0f, 3.5f, 125.0f), D3DXVECTOR3(3.0f, 1.0f, 1.0f), SPIKE, D3DXVECTOR3(0.0f, 0.0f, 0.0f));
			AddGameObject<CTrap>(9)->SetObject(D3DXVECTOR3(16.0f, 3.5f, 125.0f), D3DXVECTOR3(3.0f, 1.0f, 1.0f), SPIKE, D3DXVECTOR3(0.0f, 0.0f, 0.0f));
			AddGameObject<CTrap>(9)->SetObject(D3DXVECTOR3(19.0f, 3.5f, 125.0f), D3DXVECTOR3(3.0f, 1.0f, 1.0f), SPIKE, D3DXVECTOR3(0.0f, 0.0f, 0.0f));
			AddGameObject<CTrap>(9)->SetObject(D3DXVECTOR3(22.0f, 3.5f, 125.0f), D3DXVECTOR3(3.0f, 1.0f, 1.0f), SPIKE, D3DXVECTOR3(0.0f, 0.0f, 0.0f));
			AddGameObject<CTrap>(9)->SetObject(D3DXVECTOR3(25.0f, 3.5f, 125.0f), D3DXVECTOR3(3.0f, 1.0f, 1.0f), SPIKE, D3DXVECTOR3(0.0f, 0.0f, 0.0f));
			AddGameObject<CTrap>(9)->SetObject(D3DXVECTOR3(28.0f, 3.5f, 125.0f), D3DXVECTOR3(3.0f, 1.0f, 1.0f), SPIKE, D3DXVECTOR3(0.0f, 0.0f, 0.0f));
			AddGameObject<CTrap>(9)->SetObject(D3DXVECTOR3(31.0f, 3.5f, 125.0f), D3DXVECTOR3(3.0f, 1.0f, 1.0f), SPIKE, D3DXVECTOR3(0.0f, 0.0f, 0.0f));
			AddGameObject<CTrap>(9)->SetObject(D3DXVECTOR3(33.0f, 3.5f, 125.0f), D3DXVECTOR3(3.0f, 1.0f, 1.0f), SPIKE, D3DXVECTOR3(0.0f, 0.0f, 0.0f));
			AddGameObject<CTrap>(9)->SetObject(D3DXVECTOR3(36.0f, 3.5f, 125.0f), D3DXVECTOR3(3.0f, 1.0f, 1.0f), SPIKE, D3DXVECTOR3(0.0f, 0.0f, 0.0f));
			AddGameObject<CTrap>(9)->SetObject(D3DXVECTOR3(39.0f, 3.5f, 125.0f), D3DXVECTOR3(3.0f, 1.0f, 1.0f), SPIKE, D3DXVECTOR3(0.0f, 0.0f, 0.0f));
			AddGameObject<CTrap>(9)->SetObject(D3DXVECTOR3(42.0f, 3.5f, 125.0f), D3DXVECTOR3(3.0f, 1.0f, 1.0f), SPIKE, D3DXVECTOR3(0.0f, 0.0f, 0.0f));
			AddGameObject<CTrap>(9)->SetObject(D3DXVECTOR3(45.0f, 3.5f, 125.0f), D3DXVECTOR3(3.0f, 1.0f, 1.0f), SPIKE, D3DXVECTOR3(0.0f, 0.0f, 0.0f));
			AddGameObject<CTrap>(9)->SetObject(D3DXVECTOR3(48.0f, 3.5f, 125.0f), D3DXVECTOR3(3.0f, 1.0f, 1.0f), SPIKE, D3DXVECTOR3(0.0f, 0.0f, 0.0f));
			AddGameObject<CTrap>(9)->SetObject(D3DXVECTOR3(51.0f, 3.5f, 125.0f), D3DXVECTOR3(3.0f, 1.0f, 1.0f), SPIKE, D3DXVECTOR3(0.0f, 0.0f, 0.0f));
			AddGameObject<CTrap>(9)->SetObject(D3DXVECTOR3(54.0f, 3.5f, 125.0f), D3DXVECTOR3(3.0f, 1.0f, 1.0f), SPIKE, D3DXVECTOR3(0.0f, 0.0f, 0.0f));
			AddGameObject<CTrap>(9)->SetObject(D3DXVECTOR3(57.0f, 3.5f, 125.0f), D3DXVECTOR3(3.0f, 1.0f, 1.0f), SPIKE, D3DXVECTOR3(0.0f, 0.0f, 0.0f));
			AddGameObject<CTrap>(9)->SetObject(D3DXVECTOR3(60.0f, 3.5f, 125.0f), D3DXVECTOR3(3.0f, 1.0f, 1.0f), SPIKE, D3DXVECTOR3(0.0f, 0.0f, 0.0f));


		}
		{//Pillar
			AddGameObject<CWall>(5)->SetWall(FRONT_WALL, D3DXVECTOR3(10.0f, 5.0f, 170.0f), D3DXVECTOR3(10.0f, 5.0f, 1.0f), 0, ROCK);
			AddGameObject<CWall>(3)->SetWall(RIGHT_WALL, D3DXVECTOR3(10.0f, 5.0f, 170.0f), D3DXVECTOR3(1.0f, 5.0f, 10.0f), 0, ROCK);
			AddGameObject<CWall>(4)->SetWall(LEFT_WALL, D3DXVECTOR3(20.0f, 5.0f, 170.0f), D3DXVECTOR3(1.0f, 5.0f, 10.0f), 0, ROCK);
			AddGameObject<CWall>(6)->SetWall(BEHIND_WALL, D3DXVECTOR3(10.0f, 5.0f, 180.0f), D3DXVECTOR3(10.0f, 5.0f, 1.0f), 0, ROCK);
		
			AddGameObject<CWall>(5)->SetWall(FRONT_WALL, D3DXVECTOR3(10.0f, 5.0f, 190.0f), D3DXVECTOR3(10.0f, 5.0f, 1.0f), 0, ROCK);
			AddGameObject<CWall>(3)->SetWall(RIGHT_WALL, D3DXVECTOR3(10.0f, 5.0f, 190.0f), D3DXVECTOR3(1.0f, 5.0f, 10.0f), 0, ROCK);
			AddGameObject<CWall>(4)->SetWall(LEFT_WALL, D3DXVECTOR3(20.0f, 5.0f, 190.0f), D3DXVECTOR3(1.0f, 5.0f, 10.0f), 0, ROCK);
			AddGameObject<CWall>(6)->SetWall(BEHIND_WALL, D3DXVECTOR3(10.0f, 5.0f, 200.0f), D3DXVECTOR3(10.0f, 5.0f, 1.0f), 0, ROCK);
		
			AddGameObject<CWall>(5)->SetWall(FRONT_WALL, D3DXVECTOR3(50.0f, 5.0f, 170.0f), D3DXVECTOR3(10.0f, 5.0f, 1.0f), 0, ROCK);
			AddGameObject<CWall>(3)->SetWall(RIGHT_WALL, D3DXVECTOR3(50.0f, 5.0f, 170.0f), D3DXVECTOR3(1.0f, 5.0f, 10.0f), 0, ROCK);
			AddGameObject<CWall>(4)->SetWall(LEFT_WALL, D3DXVECTOR3(60.0f, 5.0f, 170.0f), D3DXVECTOR3(1.0f, 5.0f, 10.0f), 0, ROCK);
			AddGameObject<CWall>(6)->SetWall(BEHIND_WALL, D3DXVECTOR3(50.0f, 5.0f, 180.0f), D3DXVECTOR3(10.0f, 5.0f, 1.0f), 0, ROCK);
		
			AddGameObject<CWall>(5)->SetWall(FRONT_WALL, D3DXVECTOR3(50.0f, 5.0f, 190.0f), D3DXVECTOR3(10.0f, 5.0f, 1.0f), 0, ROCK);
			AddGameObject<CWall>(3)->SetWall(RIGHT_WALL, D3DXVECTOR3(50.0f, 5.0f, 190.0f), D3DXVECTOR3(1.0f, 5.0f, 10.0f), 0, ROCK);
			AddGameObject<CWall>(4)->SetWall(LEFT_WALL, D3DXVECTOR3(60.0f, 5.0f, 190.0f), D3DXVECTOR3(1.0f, 5.0f, 10.0f), 0, ROCK);
			AddGameObject<CWall>(6)->SetWall(BEHIND_WALL, D3DXVECTOR3(50.0f, 5.0f, 200.0f), D3DXVECTOR3(10.0f, 5.0f, 1.0f), 0, ROCK);
		}
		{//Pattern
			AddGameObject<C3dpolygon>(7)->SetObject(D3DXVECTOR3(35.0f, 3.0f, 150.0f), D3DXVECTOR3(0.35f, 0.35f, 0.35f), SHOTGUN_POLYGON);
			AddGameObject<C3dpolygon>(1)->SetObject(D3DXVECTOR3(35.5f, 4.5f, 160.0f), D3DXVECTOR3(4.0f, 2.0f, 2.0f), DOOR_1);
			AddGameObject<C3dpolygon>(2)->SetObject(D3DXVECTOR3(35.0f, 4.5f, 420.0f), D3DXVECTOR3(4.0f, 2.0f, 2.0f), DOOR_2);
			AddGameObject<C3dpolygon>(3)->SetObject(D3DXVECTOR3(35.0f, 2.5f, 425.0f), D3DXVECTOR3(1.5f, 0.2f, 1.5f), TELEPORT);
			AddGameObject<C3dpolygon>(4)->SetObject(D3DXVECTOR3(35.0f, 20.0f, 480.0f), D3DXVECTOR3(3.0f, 0.4f, 3.0f), TELEPORT);

		}
		{//Item
			AddGameObject<CItem>(9)->SetObject(D3DXVECTOR3(55.0f, 4.0f, 85.0f), D3DXVECTOR3(0.5f, 0.5f, 1.2f), TYPE_ITEM_BULLET);
			AddGameObject<CItem>(9)->SetObject(D3DXVECTOR3(15.0f, 4.0f, 135.0f), D3DXVECTOR3(0.5f, 0.5f, 1.2f), TYPE_ITEM_BULLET);
			AddGameObject<CItem>(9)->SetObject(D3DXVECTOR3(55.0f, 4.0f, 135.0f), D3DXVECTOR3(0.5f, 0.5f, 1.2f), TYPE_ITEM_BULLET);
			AddGameObject<CItem>(9)->SetObject(D3DXVECTOR3(35.0f, 4.0f, 135.0f), D3DXVECTOR3(0.5f, 0.5f, 1.2f), TYPE_ITEM_HEART);
			AddGameObject<CItem>(9)->SetObject(D3DXVECTOR3(5.0f, 4.0f, 205.0f), D3DXVECTOR3(0.5f, 0.5f, 1.2f), TYPE_ITEM_BULLET);
			AddGameObject<CItem>(9)->SetObject(D3DXVECTOR3(65.0f, 4.0f, 205.0f), D3DXVECTOR3(0.5f, 0.5f, 1.2f), TYPE_ITEM_BULLET);
			AddGameObject<CItem>(9)->SetObject(D3DXVECTOR3(35.0f, 4.0f, 325.0f), D3DXVECTOR3(0.5f, 0.5f, 1.2f), TYPE_ITEM_BULLET);
			AddGameObject<CItem>(9)->SetObject(D3DXVECTOR3(55.0f, 4.0f, 365.0f), D3DXVECTOR3(0.5f, 0.5f, 1.2f), TYPE_ITEM_BULLET);
			AddGameObject<CItem>(9)->SetObject(D3DXVECTOR3(15.0f, 4.0f, 395.0f), D3DXVECTOR3(0.5f, 0.5f, 1.2f), TYPE_ITEM_BULLET);
			AddGameObject<CItem>(9)->SetObject(D3DXVECTOR3(35.0f, 4.0f, 405.0f), D3DXVECTOR3(0.5f, 0.5f, 1.2f), TYPE_ITEM_HEART);

		}
		{//Dummy
			AddGameObject<CEnemy>(8)->SetTexture(TYPE_GOLEM, D3DXVECTOR3(0.0f, -230.5f, 42.0f), D3DXVECTOR3(2.0f, 1.0f, 2.0f), 40);
		}
	

	AddGameObject<CFade>(19)->CaeateFade();
	StopSound();
	PlaySoundA(SOUND_LABEL_STAGE4_BGM);
}

void CStage4::Update()
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
				CStagebreak::SaveStage(STAGE4);
			
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

			CManager::SetScene<CStage5>();
		}
	}

}

void CStage4::Uninit()
{
	CScene::Uninit();

}
#include "stage5.h"
#include "Stage6.h"
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
#include "Rail.h"
#include "Grid.h"
#include "Polygon.h"
#include "Number.h"
#include "3dpolygon.h"
#include "stagebreak.h"
#include "skybox.h"
#include "warning.h"
void CStage5::Init()
{
	

	PatternReset();

	AddGameObject<CPlayer>(2); 
	AddGameObject<CCamera>(0)->SetObject(D3DXVECTOR3(55.0f, 4.5f,15.0f), D3DXVECTOR3(1.0f, 1.0f, 1.0f), TYPE_SETTING);
	AddGameObject<CPolygon>(12)->SetObject(D3DXVECTOR3(SCREEN_WIDTH *0.9f, SCREEN_HEIGHT *0.75f, 0.0f), D3DXVECTOR3(1.5f, 0.4f, 0.0f), SMALLGUN_UI_TEXTURE);
	AddGameObject<CPolygon>(12)->SetObject(D3DXVECTOR3(SCREEN_WIDTH *0.88f, SCREEN_HEIGHT *0.65f, 0.0f), D3DXVECTOR3(1.5f, 0.4f, 0.0f), SHOTGUN_UI_TEXTURE);

	AddGameObject<CPolygon>(15)->SetObject(D3DXVECTOR3(SCREEN_WIDTH *0.87f, SCREEN_HEIGHT *0.77f, 0.0f), D3DXVECTOR3(3.0f, 1.3f, 0.0f), CURSOR_TEXTURE);
	AddGameObject<CPolygon>(11)->SetObject(D3DXVECTOR3(SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT *0.5f, 0.0f), D3DXVECTOR3(0.5f, 0.5f, 0.0f), AIM_TEXTURE);
	AddGameObject<CPolygon>(11)->SetObject(D3DXVECTOR3(SCREEN_WIDTH * 0.07f, SCREEN_HEIGHT *0.75f, 0.0f), D3DXVECTOR3(0.2f, 1.5f, 0.0f), HPGAGE_GRAY_TEXTURE);
	AddGameObject<CPolygon>(11)->SetObject(D3DXVECTOR3(SCREEN_WIDTH * 0.07f, SCREEN_HEIGHT *0.75f, 0.0f), D3DXVECTOR3(0.2f, 1.5f, 0.0f), HPGAGE_RED_TEXTURE);
	AddGameObject<CPolygon>(11)->SetObject(D3DXVECTOR3(SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT *0.05f, 0.0f), D3DXVECTOR3(1.0f, 0.5f, 0.0f), PAUSE_TEXTURE);

	AddGameObject<CNumber>(10)->SetTexture(HP_NUMBER, 3, D3DXVECTOR3(SCREEN_WIDTH * 0.0f, SCREEN_HEIGHT *0.825, 0.0f), D3DXVECTOR3(0.3f, 0.3f, 0.0f));

	AddGameObject<CNumber>(10)->SetTexture(BULLET_NUMBER, 2, D3DXVECTOR3(SCREEN_WIDTH *0.75f, SCREEN_HEIGHT *0.8f, 0.0f), D3DXVECTOR3(0.3f, 0.3f, 0.0f));
	AddGameObject<CNumber>(10)->SetTexture(MAX_BULLET_NUMBER, 3, D3DXVECTOR3(SCREEN_WIDTH *0.85f, SCREEN_HEIGHT *0.85f, 0.0f), D3DXVECTOR3(0.3f, 0.3f, 0.0f));
	{//floor1
		AddGameObject<CField>(8)->SetField(D3DXVECTOR3(40.0f, 2.5f, 0.0f), D3DXVECTOR3(30.0f, 0.5f, 30.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 1.0f);
		AddGameObject<CField>(8)->SetField(D3DXVECTOR3(30.0f, 2.5f, 30.0f), D3DXVECTOR3(50.0f, 0.5f, 10.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 1.0f);
		AddGameObject<CField>(8)->SetField(D3DXVECTOR3(20.0f, 2.5f, 40.0f), D3DXVECTOR3(70.0f, 0.5f, 10.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 1.0f);
		AddGameObject<CField>(8)->SetField(D3DXVECTOR3(10.0f, 2.5f, 50.0f), D3DXVECTOR3(90.0f, 0.5f, 10.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 1.0f);
		AddGameObject<CField>(8)->SetField(D3DXVECTOR3(0.0f, 2.5f, 60.0f), D3DXVECTOR3(110.0f, 0.5f, 130.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 1.0f);
		AddGameObject<CField>(8)->SetField(D3DXVECTOR3(10.0f, 2.5f, 190.0f), D3DXVECTOR3(90.0f, 0.5f, 10.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 1.0f);
		AddGameObject<CField>(8)->SetField(D3DXVECTOR3(20.0f, 2.5f, 200.0f), D3DXVECTOR3(70.0f, 0.5f, 10.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 1.0f);
		AddGameObject<CField>(8)->SetField(D3DXVECTOR3(30.0f, 2.5f, 210.0f), D3DXVECTOR3(50.0f, 0.5f, 10.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 1.0f);
		AddGameObject<CField>(8)->SetField(D3DXVECTOR3(40.0f, 2.5f, 220.0f), D3DXVECTOR3(30.0f, 0.5f, 20.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 1.0f);
		AddGameObject<CField>(8)->SetField(D3DXVECTOR3(50.0f, 2.5f, 240.0f), D3DXVECTOR3(10.0f, 0.5f, 10.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 1.0f);
	}
	{//floor2
		AddGameObject<CField>(9)->SetField(D3DXVECTOR3(50.0f, 2.5f,255.0f),  D3DXVECTOR3(20.0f, 0.5f, 20.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 1.0f,SCAFFOLD,0,0.0f);
		AddGameObject<CField>(9)->SetField(D3DXVECTOR3(75.0f, 2.5f, 255.0f), D3DXVECTOR3(20.0f, 0.5f, 20.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 1.0f,SCAFFOLD,0,1.0f);
		AddGameObject<CField>(9)->SetField(D3DXVECTOR3(50.0f, 2.5f, 280.0f), D3DXVECTOR3(20.0f, 0.5f, 20.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 1.0f,SCAFFOLD,0,1.0f);
		AddGameObject<CField>(9)->SetField(D3DXVECTOR3(75.0f, 2.5f, 280.0f), D3DXVECTOR3(20.0f, 0.5f, 20.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 1.0f,SCAFFOLD,0,0.0f);
		AddGameObject<CField>(9)->SetField(D3DXVECTOR3(100.0f, 2.5f,280.0f),  D3DXVECTOR3(20.0f, 0.5f, 20.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 1.0f,SCAFFOLD,0,1.0f);
		AddGameObject<CField>(9)->SetField(D3DXVECTOR3(50.0f, 2.5f,  305.0f), D3DXVECTOR3(20.0f, 0.5f, 20.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 1.0f,SCAFFOLD,0,0.0f);
		AddGameObject<CField>(9)->SetField(D3DXVECTOR3(75.0f, 2.5f,  305.0f), D3DXVECTOR3(20.0f, 0.5f, 20.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 1.0f,SCAFFOLD,0,1.0f);
		AddGameObject<CField>(9)->SetField(D3DXVECTOR3(100.0f, 2.5f, 305.0f), D3DXVECTOR3(20.0f, 0.5f, 20.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 1.0f,SCAFFOLD,0,0.0f);
		AddGameObject<CField>(9)->SetField(D3DXVECTOR3(125.0f, 2.5f, 305.0f), D3DXVECTOR3(20.0f, 0.5f, 20.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 1.0f,SCAFFOLD,0,1.0f);
		AddGameObject<CField>(9)->SetField(D3DXVECTOR3(75.0f, 2.5f,  330.0f), D3DXVECTOR3(20.0f, 0.5f, 20.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 1.0f,SCAFFOLD,0,0.0f);
		AddGameObject<CField>(9)->SetField(D3DXVECTOR3(100.0f, 2.5f, 330.0f), D3DXVECTOR3(20.0f, 0.5f, 20.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 1.0f,SCAFFOLD,0,1.0f);
		AddGameObject<CField>(9)->SetField(D3DXVECTOR3(125.0f, 2.5f, 330.0f), D3DXVECTOR3(20.0f, 0.5f, 20.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 1.0f,SCAFFOLD,0,0.0f);
	}
	{//floor3
		AddGameObject<CField>(8)->SetField(D3DXVECTOR3(150.0f, 2.5f, 330.0f), D3DXVECTOR3(20.0f, 0.5f, 20.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 1.0f);
		AddGameObject<CRail>(8)->SetObject(D3DXVECTOR3(170.0f, 2.5f, 335.0f), D3DXVECTOR3(90.0f, 0.5f, 10.0f),RIGHTRAIL);
		AddGameObject<CRail>(8)->SetObject(D3DXVECTOR3(250.0f, 2.5f, 310.0f), D3DXVECTOR3(10.0f, 0.5f, 25.0f), DOWNRAIL);
		AddGameObject<CRail>(8)->SetObject(D3DXVECTOR3(160.0f, 2.5f, 310.0f), D3DXVECTOR3(90.0f, 0.5f, 10.0f), LEFTRAIL);
		AddGameObject<CRail>(8)->SetObject(D3DXVECTOR3(160.0f, 2.5f, 285.0f), D3DXVECTOR3(10.0f, 0.5f, 25.0f), DOWNRAIL);
		AddGameObject<CRail>(8)->SetObject(D3DXVECTOR3(170.0f, 2.5f, 285.0f), D3DXVECTOR3(90.0f, 0.5f, 10.0f), RIGHTRAIL);
		AddGameObject<CRail>(8)->SetObject(D3DXVECTOR3(250.0f, 2.5f, 260.0f), D3DXVECTOR3(10.0f, 0.5f, 25.0f), DOWNRAIL);
		AddGameObject<CRail>(8)->SetObject(D3DXVECTOR3(160.0f, 2.5f, 260.0f), D3DXVECTOR3(90.0f, 0.5f, 10.0f), LEFTRAIL);
		AddGameObject<CRail>(8)->SetObject(D3DXVECTOR3(160.0f, 2.5f, 235.0f), D3DXVECTOR3(10.0f, 0.5f, 25.0f), DOWNRAIL);
		AddGameObject<CRail>(8)->SetObject(D3DXVECTOR3(170.0f, 2.5f, 235.0f), D3DXVECTOR3(90.0f, 0.5f, 10.0f), RIGHTRAIL);
		AddGameObject<CRail>(8)->SetObject(D3DXVECTOR3(250.0f, 2.5f, 210.0f), D3DXVECTOR3(10.0f, 0.5f, 25.0f), DOWNRAIL);
		AddGameObject<CRail>(8)->SetObject(D3DXVECTOR3(200.0f, 2.5f,210.0f), D3DXVECTOR3(50.0f, 0.5f, 10.0f), LEFTRAIL);
		AddGameObject<CRail>(8)->SetObject(D3DXVECTOR3(205.0f, 2.5f, 190.0f), D3DXVECTOR3(10.0f, 0.5f, 20.0f), DOWNRAIL);

	}
	{//bossfloor
		AddGameObject<CField>(8)->SetField(D3DXVECTOR3(190.0f, 2.5f, 170.0f), D3DXVECTOR3(40.0f, 0.5f, 10.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 1.0f);
		AddGameObject<CField>(8)->SetField(D3DXVECTOR3(180.0f, 2.5f, 160.0f), D3DXVECTOR3(60.0f, 0.5f, 10.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 1.0f);
		AddGameObject<CField>(8)->SetField(D3DXVECTOR3(170.0f, 2.5f, 150.0f), D3DXVECTOR3(80.0f, 0.5f, 10.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 1.0f);
		AddGameObject<CField>(8)->SetField(D3DXVECTOR3(160.0f, 2.5f, 140.0f), D3DXVECTOR3(100.0f, 0.5f, 10.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 1.0f);
		AddGameObject<CField>(8)->SetField(D3DXVECTOR3(150.0f, 2.5f, 80.0f), D3DXVECTOR3(120.0f, 0.5f, 60.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 1.0f);
		AddGameObject<CField>(8)->SetField(D3DXVECTOR3(160.0f, 2.5f, 70.0f), D3DXVECTOR3(100.0f, 0.5f, 10.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 1.0f);
		AddGameObject<CField>(8)->SetField(D3DXVECTOR3(170.0f, 2.5f, 60.0f), D3DXVECTOR3(80.0f, 0.5f, 10.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 1.0f);
		AddGameObject<CField>(8)->SetField(D3DXVECTOR3(180.0f, 2.5f, 50.0f), D3DXVECTOR3(60.0f, 0.5f, 10.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 1.0f);
		AddGameObject<CField>(8)->SetField(D3DXVECTOR3(190.0f, 2.5f, 40.0f), D3DXVECTOR3(40.0f, 0.5f, 10.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 1.0f);

	}
	{//skybox
		AddGameObject<CWall>(4)->SetWall(LEFT_WALL, D3DXVECTOR3(-20.0f, 5.0f, -20.0f), D3DXVECTOR3(1.0f, 15.0f, 405.0f));
		AddGameObject<CWall>(6)->SetWall(BEHIND_WALL, D3DXVECTOR3(-20.0f, 5.0f, -20.0f), D3DXVECTOR3(420.0f, 15.0f, 1.0f));
		AddGameObject<CWall>(5)->SetWall(FRONT_WALL, D3DXVECTOR3(-20.0f, 5.0f, 380.0f), D3DXVECTOR3(340.0f, 15.0f, 1.0f));
		AddGameObject<CWall>(3)->SetWall(RIGHT_WALL, D3DXVECTOR3(300.0f, 5.0f, -20.0f), D3DXVECTOR3(1.0f, 15.0f, 420.0f));
		AddGameObject<CField>(8)->SetField(D3DXVECTOR3(-20.0f, -2.0f, -20.0f), D3DXVECTOR3(340.0f, 0.5f, 420.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 1.0f,FLOOR);
		AddGameObject<CField>(1)->SetField(D3DXVECTOR3(300.0f, 10.5f, -20.0f), D3DXVECTOR3(340.0f, 0.5f, 420.0f), D3DXVECTOR3(0.0f, 0.0f, D3DXToRadian(180.0f)), -1.0f, CEILING);
	}
	{//Pillar
		AddGameObject<CWall>(5)->SetWall(FRONT_WALL, D3DXVECTOR3(30.0f, 5.0f, 60.0f), D3DXVECTOR3(5.0f, 5.0f, 1.0f), PILLAR);
		AddGameObject<CWall>(3)->SetWall(RIGHT_WALL, D3DXVECTOR3(30.0f, 5.0f, 60.0f), D3DXVECTOR3(1.0f, 5.0f, 5.0f), PILLAR);
		AddGameObject<CWall>(4)->SetWall(LEFT_WALL, D3DXVECTOR3(35.0f, 5.0f, 60.0f), D3DXVECTOR3(1.0f, 5.0f, 5.0f), PILLAR);
		AddGameObject<CWall>(6)->SetWall(BEHIND_WALL, D3DXVECTOR3(30.0f, 5.0f, 65.0f), D3DXVECTOR3(5.0f, 5.0f, 1.0f), PILLAR);
	
		AddGameObject<CWall>(5)->SetWall(FRONT_WALL, D3DXVECTOR3(55.0f, 5.0f, 60.0f), D3DXVECTOR3(5.0f, 5.0f, 1.0f), PILLAR);
		AddGameObject<CWall>(3)->SetWall(RIGHT_WALL, D3DXVECTOR3(55.0f, 5.0f, 60.0f), D3DXVECTOR3(1.0f, 5.0f, 5.0f), PILLAR);
		AddGameObject<CWall>(4)->SetWall(LEFT_WALL, D3DXVECTOR3(60.0f, 5.0f, 60.0f), D3DXVECTOR3(1.0f, 5.0f, 5.0f), PILLAR);
		AddGameObject<CWall>(6)->SetWall(BEHIND_WALL, D3DXVECTOR3(55.0f, 5.0f, 65.0f), D3DXVECTOR3(5.0f, 5.0f, 1.0f), PILLAR);

		AddGameObject<CWall>(5)->SetWall(FRONT_WALL, D3DXVECTOR3(80.0f, 5.0f, 60.0f), D3DXVECTOR3(5.0f, 5.0f, 1.0f), PILLAR);
		AddGameObject<CWall>(3)->SetWall(RIGHT_WALL, D3DXVECTOR3(80.0f, 5.0f, 60.0f), D3DXVECTOR3(1.0f, 5.0f, 5.0f), PILLAR);
		AddGameObject<CWall>(4)->SetWall(LEFT_WALL, D3DXVECTOR3(85.0f, 5.0f, 60.0f), D3DXVECTOR3(1.0f, 5.0f, 5.0f), PILLAR);
		AddGameObject<CWall>(6)->SetWall(BEHIND_WALL, D3DXVECTOR3(80.0f, 5.0f, 65.0f), D3DXVECTOR3(5.0f, 5.0f, 1.0f), PILLAR);

		AddGameObject<CWall>(5)->SetWall(FRONT_WALL, D3DXVECTOR3(30.0f, 5.0f, 100.0f), D3DXVECTOR3(5.0f, 5.0f, 1.0f), PILLAR);
		AddGameObject<CWall>(3)->SetWall(RIGHT_WALL, D3DXVECTOR3(30.0f, 5.0f, 100.0f), D3DXVECTOR3(1.0f, 5.0f, 5.0f), PILLAR);
		AddGameObject<CWall>(4)->SetWall(LEFT_WALL,  D3DXVECTOR3(35.0f, 5.0f, 100.0f), D3DXVECTOR3(1.0f, 5.0f, 5.0f), PILLAR);
		AddGameObject<CWall>(6)->SetWall(BEHIND_WALL,D3DXVECTOR3(30.0f, 5.0f, 105.0f), D3DXVECTOR3(5.0f, 5.0f, 1.0f), PILLAR);

		AddGameObject<CWall>(5)->SetWall(FRONT_WALL, D3DXVECTOR3(55.0f, 5.0f, 100.0f), D3DXVECTOR3(5.0f, 5.0f, 1.0f), PILLAR);
		AddGameObject<CWall>(3)->SetWall(RIGHT_WALL, D3DXVECTOR3(55.0f, 5.0f, 100.0f), D3DXVECTOR3(1.0f, 5.0f, 5.0f), PILLAR);
		AddGameObject<CWall>(4)->SetWall(LEFT_WALL,  D3DXVECTOR3(60.0f, 5.0f, 100.0f), D3DXVECTOR3(1.0f, 5.0f, 5.0f), PILLAR);
		AddGameObject<CWall>(6)->SetWall(BEHIND_WALL,D3DXVECTOR3(55.0f, 5.0f, 105.0f), D3DXVECTOR3(5.0f, 5.0f, 1.0f), PILLAR);

		AddGameObject<CWall>(5)->SetWall(FRONT_WALL, D3DXVECTOR3(80.0f, 5.0f, 100.0f), D3DXVECTOR3(5.0f, 5.0f, 1.0f), PILLAR);
		AddGameObject<CWall>(3)->SetWall(RIGHT_WALL, D3DXVECTOR3(80.0f, 5.0f, 100.0f), D3DXVECTOR3(1.0f, 5.0f, 5.0f), PILLAR);
		AddGameObject<CWall>(4)->SetWall(LEFT_WALL,  D3DXVECTOR3(85.0f, 5.0f, 100.0f), D3DXVECTOR3(1.0f, 5.0f, 5.0f), PILLAR);
		AddGameObject<CWall>(6)->SetWall(BEHIND_WALL,D3DXVECTOR3(80.0f, 5.0f, 105.0f), D3DXVECTOR3(5.0f, 5.0f, 1.0f), PILLAR);

		AddGameObject<CWall>(5)->SetWall(FRONT_WALL, D3DXVECTOR3(30.0f, 5.0f, 140.0f), D3DXVECTOR3(5.0f, 5.0f, 1.0f), PILLAR);
		AddGameObject<CWall>(3)->SetWall(RIGHT_WALL, D3DXVECTOR3(30.0f, 5.0f, 140.0f), D3DXVECTOR3(1.0f, 5.0f, 5.0f), PILLAR);
		AddGameObject<CWall>(4)->SetWall(LEFT_WALL,  D3DXVECTOR3(35.0f, 5.0f, 140.0f), D3DXVECTOR3(1.0f, 5.0f, 5.0f), PILLAR);
		AddGameObject<CWall>(6)->SetWall(BEHIND_WALL,D3DXVECTOR3(30.0f, 5.0f, 145.0f), D3DXVECTOR3(5.0f, 5.0f, 1.0f), PILLAR);

		AddGameObject<CWall>(5)->SetWall(FRONT_WALL, D3DXVECTOR3(55.0f, 5.0f, 140.0f), D3DXVECTOR3(5.0f, 5.0f, 1.0f), PILLAR);
		AddGameObject<CWall>(3)->SetWall(RIGHT_WALL, D3DXVECTOR3(55.0f, 5.0f, 140.0f), D3DXVECTOR3(1.0f, 5.0f, 5.0f), PILLAR);
		AddGameObject<CWall>(4)->SetWall(LEFT_WALL,  D3DXVECTOR3(60.0f, 5.0f, 140.0f), D3DXVECTOR3(1.0f, 5.0f, 5.0f), PILLAR);
		AddGameObject<CWall>(6)->SetWall(BEHIND_WALL,D3DXVECTOR3(55.0f, 5.0f, 145.0f), D3DXVECTOR3(5.0f, 5.0f, 1.0f), PILLAR);

		AddGameObject<CWall>(5)->SetWall(FRONT_WALL, D3DXVECTOR3(80.0f, 5.0f, 140.0f), D3DXVECTOR3(5.0f, 5.0f, 1.0f), PILLAR);
		AddGameObject<CWall>(3)->SetWall(RIGHT_WALL, D3DXVECTOR3(80.0f, 5.0f, 140.0f), D3DXVECTOR3(1.0f, 5.0f, 5.0f), PILLAR);
		AddGameObject<CWall>(4)->SetWall(LEFT_WALL,  D3DXVECTOR3(85.0f, 5.0f, 140.0f), D3DXVECTOR3(1.0f, 5.0f, 5.0f), PILLAR);
		AddGameObject<CWall>(6)->SetWall(BEHIND_WALL,D3DXVECTOR3(80.0f, 5.0f, 145.0f), D3DXVECTOR3(5.0f, 5.0f, 1.0f), PILLAR);
	}
	{//Skull
		AddGameObject<CTrap>(8)->SetObject(D3DXVECTOR3(173.0f, 5.0f, 355.0f), D3DXVECTOR3(2.0f, 2.0f, 2.0f), SKULL, D3DXVECTOR3(0.0f, 0.0f, 0.0f));
		AddGameObject<CTrap>(8)->SetObject(D3DXVECTOR3(176.0f, 5.0f, 355.0f), D3DXVECTOR3(2.0f, 2.0f, 2.0f), SKULL, D3DXVECTOR3(0.0f, 0.0f, 0.0f));

		AddGameObject<CTrap>(8)->SetObject(D3DXVECTOR3(193.0f, 5.0f, 355.0f), D3DXVECTOR3(2.0f, 2.0f, 2.0f), SKULL, D3DXVECTOR3(0.0f, 0.0f, 0.0f));
		AddGameObject<CTrap>(8)->SetObject(D3DXVECTOR3(196.0f, 5.0f, 355.0f), D3DXVECTOR3(2.0f, 2.0f, 2.0f), SKULL, D3DXVECTOR3(0.0f, 0.0f, 0.0f));

		AddGameObject<CTrap>(8)->SetObject(D3DXVECTOR3(213.0f, 5.0f, 355.0f), D3DXVECTOR3(2.0f, 2.0f, 2.0f), SKULL, D3DXVECTOR3(0.0f, 0.0f, 0.0f));
		AddGameObject<CTrap>(8)->SetObject(D3DXVECTOR3(216.0f, 5.0f, 355.0f), D3DXVECTOR3(2.0f, 2.0f, 2.0f), SKULL, D3DXVECTOR3(0.0f, 0.0f, 0.0f));

		AddGameObject<CTrap>(8)->SetObject(D3DXVECTOR3(233.0f, 5.0f, 355.0f), D3DXVECTOR3(2.0f, 2.0f, 2.0f), SKULL, D3DXVECTOR3(0.0f, 0.0f, 0.0f));
		AddGameObject<CTrap>(8)->SetObject(D3DXVECTOR3(236.0f, 5.0f, 355.0f), D3DXVECTOR3(2.0f, 2.0f, 2.0f), SKULL, D3DXVECTOR3(0.0f, 0.0f, 0.0f));

		AddGameObject<CTrap>(8)->SetObject(D3DXVECTOR3(173.0f, 5.0f, 225.0f), D3DXVECTOR3(2.0f, 2.0f, 2.0f), SKULL, D3DXVECTOR3(0.0f, D3DXToRadian(180.0f), 0.0f));
		AddGameObject<CTrap>(8)->SetObject(D3DXVECTOR3(176.0f, 5.0f, 225.0f), D3DXVECTOR3(2.0f, 2.0f, 2.0f), SKULL, D3DXVECTOR3(0.0f, D3DXToRadian(180.0f), 0.0f));

		AddGameObject<CTrap>(8)->SetObject(D3DXVECTOR3(193.0f, 5.0f, 225.0f), D3DXVECTOR3(2.0f, 2.0f, 2.0f), SKULL, D3DXVECTOR3(0.0f, D3DXToRadian(180.0f), 0.0f));
		AddGameObject<CTrap>(8)->SetObject(D3DXVECTOR3(196.0f, 5.0f, 225.0f), D3DXVECTOR3(2.0f, 2.0f, 2.0f), SKULL, D3DXVECTOR3(0.0f, D3DXToRadian(180.0f), 0.0f));

		AddGameObject<CTrap>(8)->SetObject(D3DXVECTOR3(213.0f, 5.0f, 225.0f), D3DXVECTOR3(2.0f, 2.0f, 2.0f), SKULL, D3DXVECTOR3(0.0f, D3DXToRadian(180.0f), 0.0f));
		AddGameObject<CTrap>(8)->SetObject(D3DXVECTOR3(216.0f, 5.0f, 225.0f), D3DXVECTOR3(2.0f, 2.0f, 2.0f), SKULL, D3DXVECTOR3(0.0f, D3DXToRadian(180.0f), 0.0f));

		AddGameObject<CTrap>(8)->SetObject(D3DXVECTOR3(233.0f, 5.0f, 225.0f), D3DXVECTOR3(2.0f, 2.0f, 2.0f), SKULL, D3DXVECTOR3(0.0f, D3DXToRadian(180.0f), 0.0f));
		AddGameObject<CTrap>(8)->SetObject(D3DXVECTOR3(236.0f, 5.0f, 225.0f), D3DXVECTOR3(2.0f, 2.0f, 2.0f), SKULL, D3DXVECTOR3(0.0f, D3DXToRadian(180.0f), 0.0f));
	}
	{//Pattern
		AddGameObject<C3dpolygon>(7)->SetObject(D3DXVECTOR3(55.0f, 4.0f, 25.0f), D3DXVECTOR3(0.35f, 0.35f, 0.35f), RIFLEGUN_POLYGON);
		AddGameObject<C3dpolygon>(1)->SetObject(D3DXVECTOR3(55.5f, -0.5f, 50.0f), D3DXVECTOR3(36.0f, 2.0f, 2.0f), DOOR_1);
		AddGameObject<C3dpolygon>(2)->SetObject(D3DXVECTOR3(55.0f, -0.5f, 190.0f), D3DXVECTOR3(36.0f, 2.0f, 2.0f), DOOR_2);
		AddGameObject<C3dpolygon>(4)->SetObject(D3DXVECTOR3(210.0f, 20.0f, 110.0f), D3DXVECTOR3(3.0f, 0.4f, 3.0f), TELEPORT);

	}
	{//Item
		AddGameObject<CItem>(9)->SetObject(D3DXVECTOR3(25.0f, 4.0f, 85.0f), D3DXVECTOR3(0.5f, 0.5f, 1.2f), TYPE_ITEM_BULLET);
		AddGameObject<CItem>(9)->SetObject(D3DXVECTOR3(95.0f, 4.0f, 85.0f), D3DXVECTOR3(0.5f, 0.5f, 1.2f), TYPE_ITEM_BULLET);
		AddGameObject<CItem>(9)->SetObject(D3DXVECTOR3(25.0f, 4.0f, 165.0f), D3DXVECTOR3(0.5f, 0.5f, 1.2f), TYPE_ITEM_BULLET);
		AddGameObject<CItem>(9)->SetObject(D3DXVECTOR3(95.0f, 4.0f, 165.0f), D3DXVECTOR3(0.5f, 0.5f, 1.2f), TYPE_ITEM_BULLET);

		AddGameObject<CItem>(9)->SetObject(D3DXVECTOR3(55.0f, 4.0f, 215.0f), D3DXVECTOR3(0.5f, 0.5f, 1.2f), TYPE_ITEM_HEART);

		AddGameObject<CItem>(9)->SetObject(D3DXVECTOR3(60.0f, 4.0f, 315.0f), D3DXVECTOR3(0.5f, 0.5f, 1.2f), TYPE_ITEM_BULLET);
		AddGameObject<CItem>(9)->SetObject(D3DXVECTOR3(85.0f, 4.0f, 340.0f), D3DXVECTOR3(0.5f, 0.5f, 1.2f), TYPE_ITEM_BULLET);
		AddGameObject<CItem>(9)->SetObject(D3DXVECTOR3(110.0f, 4.0f, 290.0f), D3DXVECTOR3(0.5f, 0.5f, 1.2f), TYPE_ITEM_BULLET);

	}
	AddGameObject<CFade>(19)->CaeateFade();
	StopSound();
	PlaySoundA(SOUND_LABEL_STAGE5_BGM);
}

void CStage5::Update()
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
			CStagebreak::SaveStage(STAGE5);

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

			CManager::SetScene<CStage6>();
		}
	}


}

void CStage5::Uninit()
{
	CScene::Uninit();
	
}
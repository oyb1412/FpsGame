#pragma once

#include "game_object.h"
#define PATTERNCYCLE1 10
#define PATTERNCYCLEBOSS 100
#define PATTERNCYCLEBOSSMOVE 350

#define PATTERNCYCLE2 450

enum
{
	TELEPORT,
	SHOTGUN_POLYGON,
	SMALLGUN_POLYGON,
	BAZOOKA_POLYGON,
	EXIT_DOOR,
	TOOL_DOOR,
	PATTERNONE_POLYGON,
	RIFLEGUN_POLYGON,
	DOOR_1,
	DOOR_2,
	TUTORIALDOOR_1,
	TUTORIALDOOR_2,
	ROCK_POLYGON,
	CROWN_POLYGON
	
};
class C3dpolygon : public CGameObject
{
private:
	static class CModel* Teleport_Model;
	static class CModel* Gate_Model;
	static class CModel* ShotGun_Model;
	static class CModel* SmallGun_Model;

	static class CModel* RifleGun_Model;
	static class CModel* Bazooka_Model;

	static class CModel* Rock_Model;
	static class CModel* Crown_Model;


	class CBox* m_Box;
	float Teleport_y = 0.0f;

	static ID3D11ShaderResourceView* Black_Texture;
	static ID3D11ShaderResourceView* Blue_Texture;
	static ID3D11ShaderResourceView* ShotGun_Texture;
	static ID3D11ShaderResourceView* SmallGun_Texture;
	static ID3D11ShaderResourceView* Rock_Texture;
	static ID3D11ShaderResourceView* Crown_Texture;

	static ID3D11ShaderResourceView* RifleGun_Texture;
	D3DXMATRIX Teleport_World, Door_World,world;
	bool OpenDoor = false;
	bool CloseDoor = false;

	bool PatternBegin = false;
	int PatternCount = 0;
	bool UpDoor = false;
	bool UpTeleport = false;
	
public:
	C3dpolygon() {}
	~C3dpolygon() {}
	void Init();
	void Uninit();
	void Update();
	void Draw();
	void Transparent();
	void SetTeleport() { UpTeleport = true; }
	void SetCloseDoor() { CloseDoor = true; }

	bool GetOpenDoor() { return OpenDoor; }
	void SetOpenDoor() { OpenDoor = true; }
	void StartPattern() { PatternBegin = true; }
	void StopPattern() { PatternBegin = false; }
	bool GetPattern() { return PatternBegin ; }
	int GetPatternCount() { return PatternCount; }
	void SetUpDoor() { UpDoor = true; }
	static void Load();
	static void Unload();
};
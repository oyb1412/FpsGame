#pragma once
enum
{
	FIELD_LIGHT,
	WALL_LIGHT,
	ENEMY_LIGHT
};
class CLight
{
private:
	static int Type;
public:
	static void SetLight(int type = 0);

}; 
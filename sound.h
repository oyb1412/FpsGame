//=============================================================================
//
// サウンド処理 [sound.h]
//
//=============================================================================
#ifndef _SOUND_H_
#define _SOUND_H_

#include <Windows.h>

//*****************************************************************************
// サウンドファイル
//*****************************************************************************
typedef enum
{
	SOUND_LABEL_STAGE1_BGM ,		// BGM0
	SOUND_LABEL_BOSS_BGM,		// BGM0
	SOUND_LABEL_STAGE2_BGM,
	SOUND_LABEL_TUTORIAL_BGM,
	SOUND_LABEL_TITLE_BGM,
	SOUND_LABEL_STAGE4_BGM,		// BGM0
	SOUND_LABEL_STAGE5_BGM,		// BGM0
	SOUND_LABEL_STAGE6_BGM,		// BGM0
	SOUND_LABEL_CLEAR_BGM,		// BGM0

//	SOUND_LABEL_STAGE3_BGM,
//	SOUND_LABEL_SE_VICTORY,

	SOUND_LABEL_SE_SMALLGUN_SHOT,
	SOUND_LABEL_SE_SHOTGUN_SHOT,
	SOUND_LABEL_SE_RIFLEGUN_SHOT,
	SOUND_LABEL_SE_BAZOOKA_SHOT,

	SOUND_LABEL_SE_WOLF_DESTROY,
	SOUND_LABEL_SE_GOLEM_DESTROY,
	SOUND_LABEL_SE_BOSS_DESTROY,
	SOUND_LABEL_SE_ENEMY_DESTROY,
	SOUND_LABEL_SE_BOSS_WARNING,
	SOUND_LABEL_SE_BOSS_ULT,
	SOUND_LABEL_SE_BOSS_BOOM,
	SOUND_LABEL_SE_BOSS_ATTACK,
	SOUND_LABEL_SE_BOSS_BOOMSHOT,

	SOUND_LABEL_SE_SMALLGUN_REROAD,
	SOUND_LABEL_SE_SHOTGUN_REROAD,
	SOUND_LABEL_SE_RIFLEGUN_REROAD,
	SOUND_LABEL_SE_GET_BULLET,
	SOUND_LABEL_SE_GET_HP,
	SOUND_LABEL_SE_GET_KEY,
	SOUND_LABEL_SE_GET_GUN,

	SOUND_LABEL_SE_PLAYER_DAMAGE,
	SOUND_LABEL_SE_WOLF_HIT,
	SOUND_LABEL_SE_GOLEM_HIT,
	SOUND_LABEL_SE_BOSS_HIT,
	SOUND_LABEL_SE_ENEMY_HIT,
	SOUND_LABEL_SE_ENEMY_HEADSHOT,

	SOUND_LABEL_SE_PATTERNONE,
	SOUND_LABEL_SE_SUMMONING,
	SOUND_LABEL_SE_JUMP,
	SOUND_LABEL_SE_JUMPDAI,
	SOUND_LABEL_SE_STEP,
	SOUND_LABEL_SE_VICTORY,
	SOUND_LABEL_SE_CHOICE,

	SOUND_LABEL_MAX,
} SOUND_LABEL;

//*****************************************************************************
// プロトタイプ宣言
//*****************************************************************************
HRESULT InitSound(HWND hWnd);
void UninitSound(void);
HRESULT PlaySoundA(SOUND_LABEL label);
void StopSound(SOUND_LABEL label);
void StopSound(void);

#endif

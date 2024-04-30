#pragma once


class CInput
{
private:
	static BYTE m_OldKeyState[256];
	static BYTE m_KeyState[256];

public:
	CInput() {}
	~CInput(){}
	static void Init();
	static void Uninit();
	static void Update();

	static bool GetKeyPress( BYTE KeyCode );
	static bool GetKeyTrigger( BYTE KeyCode );

};

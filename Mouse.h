#pragma once
#include "2dbox.h"
#include "box.h"
#include <dinput.h>

#define SAFE_RELEASE(x) {if(x) x->Release(); x = NULL;}
class InputMouse
{
private:
	static LPDIRECTINPUT8 m_pDI ;
	static LPDIRECTINPUTDEVICE8 m_pMouse;
	static DIMOUSESTATE2 m_MouseState2;
	static float Sensitivity;
	static HWND m_hWnd;

	static D3DXVECTOR3 m_min, m_max;
	static class C2DBox* Box;
public:
	InputMouse() {}
	~InputMouse() {}
	static POINT m_ptMouse;
	static POINT MouseTrans;
	static D3DXVECTOR3 getmin() { return m_min; }
	static D3DXVECTOR3 getmax() { return m_max; }

	static HRESULT CreateDevice(HWND hWnd);
	static HRESULT ReadDate();
	static void DrawMouse();
	static VOID FreeDirectInput();
	static void OnActivate(WPARAM wParam);
	static BOOL PushLeft();

	static BOOL PushRight();
	static BOOL PushMiddle();
	static bool MouseMove();

	static bool WhillMouseUp();
	static bool WhillMouseDown();

	static void SetMouseSenser(float index);
};

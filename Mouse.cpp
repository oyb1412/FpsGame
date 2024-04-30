#include "main.h"
#include "Mouse.h"
#include "manager.h"
#include "title.h"
#include "game_object.h"
#include "2dbox.h"
LPDIRECTINPUT8 InputMouse::m_pDI;
LPDIRECTINPUTDEVICE8 InputMouse::m_pMouse;
DIMOUSESTATE2 InputMouse::m_MouseState2;
D3DXVECTOR3 InputMouse::m_min;
D3DXVECTOR3 InputMouse::m_max;
C2DBox* InputMouse::Box;
float InputMouse::Sensitivity;
HWND InputMouse::m_hWnd;
POINT InputMouse::MouseTrans;
POINT InputMouse::m_ptMouse;
HRESULT InputMouse::CreateDevice(HWND hWnd)
{
	HRESULT hr;
	m_hWnd = hWnd;
	 
	if (FAILED(hr = DirectInput8Create(GetModuleHandle(NULL), DIRECTINPUT_VERSION
		, IID_IDirectInput8, (VOID**)&m_pDI, NULL)))
		return hr;

	if (FAILED(hr = m_pDI->CreateDevice(GUID_SysMouse, &m_pMouse, NULL)))
		return hr;

	if (FAILED(hr = m_pMouse->SetDataFormat(&c_dfDIMouse2)))
		return hr;

	hr = m_pMouse->SetCooperativeLevel(m_hWnd, DISCL_NONEXCLUSIVE | DISCL_FOREGROUND);

	if (FAILED(hr))
		return hr;

	Box = new C2DBox();
	Box->Init();

	MouseTrans.x = SCREEN_WIDTH/2;
	MouseTrans.y = SCREEN_HEIGHT/2;
	Sensitivity = 0.7f;
	SetCursorPos(1920 / 2, 1080 / 2);
	m_pMouse->Acquire();

	return S_OK;
}

HRESULT InputMouse::ReadDate()
{
	HRESULT hr;

	if (NULL == m_pMouse)
		return S_OK;

	ZeroMemory(&m_MouseState2, sizeof(m_MouseState2));
	hr = m_pMouse->GetDeviceState(sizeof(DIMOUSESTATE2), &m_MouseState2);

	if (FAILED(hr))
	{
		hr = m_pMouse->Acquire();
		while (hr == DIERR_INPUTLOST)
			hr = m_pMouse->Acquire();

		return S_OK;
	}
	
		m_ptMouse.x = m_MouseState2.lX*Sensitivity;
		m_ptMouse.y = m_MouseState2.lY*Sensitivity;
	
	ShowCursor(false);

	MouseTrans.x += (m_ptMouse.x);
	MouseTrans.y += (m_ptMouse.y);
	Box->Update(MouseTrans,m_min,m_max);

	return S_OK;
}

void InputMouse::DrawMouse()
{

	D3DXMATRIX world, trans,scale;

	D3DXMatrixTranslation(&trans, MouseTrans.x-25.0f, MouseTrans.y-45.0f, 0.0f);
	D3DXMatrixScaling(&scale, 0.2f,0.2f, 0.0f);
	world = scale * trans;
	Box->Draw(&world,1);
}
bool InputMouse::MouseMove()
{
	MouseTrans.x = SCREEN_WIDTH / 2;
	MouseTrans.y = SCREEN_HEIGHT / 2;
	return true;
}

BOOL InputMouse::PushLeft()
{
		return (m_MouseState2.rgbButtons[0] & 0x80) ? TRUE : FALSE;
}

BOOL InputMouse::PushRight()
{
	return (m_MouseState2.rgbButtons[1] & 0x80) ? TRUE : FALSE;
}

BOOL InputMouse::PushMiddle()
{
	return (m_MouseState2.rgbButtons[2] & 0x80) ? TRUE : FALSE;
}

bool InputMouse::WhillMouseUp()
{
	if (m_MouseState2.lZ > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool InputMouse::WhillMouseDown()
{
	if (m_MouseState2.lZ < 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void InputMouse::OnActivate(WPARAM wParam)
{
	if (WA_INACTIVE != wParam && m_pMouse)
	{
		m_pMouse->Acquire();
	}
}

VOID InputMouse::FreeDirectInput()
{
	if (m_pMouse)
		m_pMouse->Unacquire();

	SAFE_RELEASE(m_pMouse);
	SAFE_RELEASE(m_pDI);

}

void InputMouse::SetMouseSenser(float index)
{
	if (Sensitivity >= 0.0f && Sensitivity < 1.5f)
	{
		Sensitivity += index;
	}
}

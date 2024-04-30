#include "main.h"
#include "light.h"
#include "renderer.h"
int CLight::Type = 0;
void CLight::SetLight(int type)
{
	if (type == FIELD_LIGHT)
	{
		LIGHT light;
		light.Enable = true;
		light.Direction = D3DXVECTOR4(1.0f, -1.0f, 1.0f, 0.0f);
		D3DXVec4Normalize(&light.Direction, &light.Direction);
		light.Ambient = D3DXCOLOR(0.1f, 0.1f, 0.1f, 1.0f);
		light.Diffuse = D3DXCOLOR(0.5f, 0.5f, 0.5f, 0.5f);
		CRenderer::SetLight(light);
	}
	if (type == WALL_LIGHT)
	{
		LIGHT light;
		light.Enable = true;
		light.Direction = D3DXVECTOR4(1.0f, -1.0f, 1.0f, 0.0f);
		D3DXVec4Normalize(&light.Direction, &light.Direction);
		light.Ambient = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		light.Diffuse = D3DXCOLOR(0.7f, 0.7f, 0.7f, 0.7f);
		CRenderer::SetLight(light);
	}
	if ( type == ENEMY_LIGHT)
	{
		LIGHT light;
		light.Enable = true;
		light.Direction = D3DXVECTOR4(1.0f, -1.0f, 1.0f, 0.0f);
		D3DXVec4Normalize(&light.Direction, &light.Direction);
		light.Ambient = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		light.Diffuse = D3DXCOLOR(0.6f, 0.6f, 0.6f, 0.6f);
		CRenderer::SetLight(light);
	}
}

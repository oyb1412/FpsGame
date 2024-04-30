#pragma once
#include "scene.h"

class CStage1 : public CScene
{
private:
	static int m_Score;//値が保存できる

	//シーン間の情報を受け取っておく専用クラスを作る
public:
	void Init();
	void Update();
	void Uninit();
	
};
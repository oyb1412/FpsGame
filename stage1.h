#pragma once
#include "scene.h"

class CStage1 : public CScene
{
private:
	static int m_Score;//�l���ۑ��ł���

	//�V�[���Ԃ̏����󂯎���Ă�����p�N���X�����
public:
	void Init();
	void Update();
	void Uninit();
	
};
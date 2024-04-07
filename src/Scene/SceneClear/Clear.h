#pragma once

#include "../../Common.h"

#define CLEAR_IMAGE_PATH	"Data/ClearImage/GameClear.png"
#define CLEAR_BUTTON_PATH	"Data/ClearImage/Please Click.png"

class SceneClear
{
private:
	int ClearImagehndl;	//�^�C�g����ʂ̃n���h��
	int ClearButtonhndl;	//�{�^���摜�̃n���h��
	int m_fg_alpha;
	int m_fg_color;
	bool m_next_flag;

	int m_button_alpha;
	int m_button_alpha_add;
	bool m_IsUse_button_alpha;

public:
	SceneClear();
	~SceneClear();

	void InitClear();
	bool StepClear();
	void DrawClear();
	void FinClear();
};

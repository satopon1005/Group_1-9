#include "DxLib.h"
#include "Clear.h"
#include "../SceneTitle/SceneTitle.h"
#include "../../Input/Input.h"
#include "../SceneManager.h"

SceneClear::SceneClear()
{
	ClearImagehndl = 0;
	ClearButtonhndl = 0;
	m_fg_alpha = 0;
	m_fg_color = 0;
	m_next_flag = false;

	m_button_alpha = 0;
	m_button_alpha_add = 0;
	m_IsUse_button_alpha = false;
}

SceneClear::~SceneClear()
{
	FinClear();
}

void SceneClear::InitClear()
{
	ClearImagehndl = LoadGraph(CLEAR_IMAGE_PATH);  //�N���A�摜�̓ǂݍ���
	ClearButtonhndl = LoadGraph(CLEAR_BUTTON_PATH);//�{�^���摜�̓ǂݍ���
	m_fg_alpha = 255;
	m_fg_color = GetColor(255, 255, 255);
	m_next_flag = false;

	m_button_alpha = 0;
	m_button_alpha_add = FG_ALPHA_ADD_NUM;
	m_IsUse_button_alpha = false;

	SetMouseDispFlag(true);
}

bool SceneClear::StepClear()
{
	//�{�^������������X�^�[�g
	if (Input::IsClickInArea(MOUSE_INPUT_LEFT,
							BUTTON_X,
							BUTTON_Y,
							BUTTON_X + BUTTON_W,
							BUTTON_Y + BUTTON_H)) {
		m_next_flag = true;
	}
	//�{�^���̓_��
	if (m_IsUse_button_alpha) {
		m_button_alpha += m_button_alpha_add;
		if (m_button_alpha <= 0 || m_button_alpha >= 255)
			m_button_alpha_add *= -1;
	}

	if (!m_next_flag) {
		if (m_fg_alpha > 0)
			m_fg_alpha -= FG_ALPHA_ADD_NUM;
		else
			m_IsUse_button_alpha = true;
	}
	else {
		m_fg_alpha += FG_ALPHA_ADD_NUM;
	}

	if (m_next_flag && m_fg_alpha >= 255)
		return true;
	return false;

}

void SceneClear::DrawClear()
{
	//�N���A��ʂ̕\��
	DrawGraph(0, 0, ClearImagehndl, true);
	//�{�^���摜�̕\��
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, m_button_alpha);
	DrawGraph(BUTTON_X, BUTTON_Y, ClearButtonhndl, true);

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, m_fg_alpha);
	DrawBox(0, 0, SCREEN_SIZE_X, SCREEN_SIZE_Y, m_fg_color, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
}

void SceneClear::FinClear()
{
	DeleteGraph(ClearImagehndl);
	DeleteGraph(ClearButtonhndl);
}
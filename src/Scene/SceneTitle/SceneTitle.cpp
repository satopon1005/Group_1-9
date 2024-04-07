#include "DxLib.h"
#include "SceneTitle.h"
#include "../../Input/Input.h"
#include "../SceneManager.h"

SceneTitle::SceneTitle()
{
	TitleImagehandle = 0;
	TitleButtonhandle = 0;
	m_fg_alpha = 0;
	m_fg_color = 0;
	m_next_flag = false;

	m_button_alpha = 0;
	m_button_alpha_add = 0;
	m_IsUse_button_alpha = false;
}

SceneTitle::~SceneTitle()
{
	FinTitle();
}

void SceneTitle::InitTitle()
{
	TitleImagehandle = LoadGraph(TITLE_IMAGE_PATH);  //タイトル画像の読み込み
	TitleButtonhandle = LoadGraph(TITLE_BUTTON_PATH);//ボタン画像の読み込み
	m_fg_alpha = 255;
	m_fg_color = GetColor(255, 255, 255);
	m_next_flag = false;

	m_button_alpha = 0;
	m_button_alpha_add = FG_ALPHA_ADD_NUM;
	m_IsUse_button_alpha = false;

	SetMouseDispFlag(true);
}

bool SceneTitle::StepTitle()
{
	//ボタンを押したらスタート
	if (Input::IsClickInArea(MOUSE_INPUT_LEFT,
							BUTTON_X,
							BUTTON_Y,
							BUTTON_X + BUTTON_W,
							BUTTON_Y + BUTTON_H)) {
		m_next_flag = true;
	}
	//ボタンの点滅
	if (m_IsUse_button_alpha) {
		m_button_alpha += m_button_alpha_add;
		if (m_button_alpha <= 0 || m_button_alpha>=255)
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

void SceneTitle::DrawTitle()
{
	//タイトル画面の表示
	DrawGraph(0, 0, TitleImagehandle,true);
	//ボタン画像の表示
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, m_button_alpha);
	DrawGraph(BUTTON_X, BUTTON_Y, TitleButtonhandle, true);

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, m_fg_alpha);
	DrawBox(0, 0, SCREEN_SIZE_X, SCREEN_SIZE_Y, m_fg_color, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
}

void SceneTitle::FinTitle()
{
	DeleteGraph(TitleImagehandle);
	DeleteGraph(TitleButtonhandle);
}

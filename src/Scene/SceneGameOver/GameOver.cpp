#include "DxLib.h"
#include "GameOver.h"
#include "../SceneTitle/SceneTitle.h"
#include "../SceneManager.h"
#include "../../Input/Input.h"

SceneGameOver::SceneGameOver()
{
	GameOverImagehndl = 0;
	GameOverButtonhndl = 0;
	m_fg_alpha = 0;
	m_fg_color = 0;
	m_next_flag = false;

	m_button_alpha = 0;
	m_button_alpha_add = 0;
	m_IsUse_button_alpha = false;
}

SceneGameOver::~SceneGameOver()
{
	FinGameOver();
}

void SceneGameOver::InitGameOver()
{
	GameOverImagehndl = LoadGraph(GAMEOVER_IMAGE_PATH);  //クリア画像の読み込み
	GameOverButtonhndl = LoadGraph(GAMEOVER_BUTTON_PATH);//ボタン画像の読み込み
	m_fg_alpha = 255;
	m_fg_color = GetColor(0, 0, 0);
	m_next_flag = false;

	m_button_alpha = 0;
	m_button_alpha_add = FG_ALPHA_ADD_NUM;
	m_IsUse_button_alpha = false;

	SetMouseDispFlag(true);
}

bool SceneGameOver::StepGameOver()
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

void SceneGameOver::DrawGameOver()
{
	//クリア画面の表示
	DrawGraph(0, 0, GameOverImagehndl, true);
	//ボタン画像の表示
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, m_button_alpha);
	DrawGraph(BUTTON_X, BUTTON_Y, GameOverButtonhndl, true);

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, m_fg_alpha);
	DrawBox(0, 0, SCREEN_SIZE_X, SCREEN_SIZE_Y, m_fg_color, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
}

void SceneGameOver::FinGameOver()
{
	DeleteGraph(GameOverImagehndl);
	DeleteGraph(GameOverButtonhndl);
}


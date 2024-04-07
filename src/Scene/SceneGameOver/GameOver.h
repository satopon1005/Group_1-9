#pragma once

#include "../../Common.h"

#define GAMEOVER_IMAGE_PATH		"Data/GameOverImage/GameOverpng.png"
#define GAMEOVER_BUTTON_PATH	"Data/GameOverImage/PleaseClick.png"

class SceneGameOver
{
private:
	int GameOverImagehndl;	//ゲームオーバー画面のハンドル
	int GameOverButtonhndl;	//ボタン画像のハンドル
	int m_fg_alpha;
	int m_fg_color;
	bool m_next_flag;

	int m_button_alpha;
	int m_button_alpha_add;
	bool m_IsUse_button_alpha;

public:
	SceneGameOver();
	~SceneGameOver();

	void InitGameOver();
	bool StepGameOver();
	void DrawGameOver();
	void FinGameOver();
};

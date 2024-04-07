#pragma once

#include "../../Common.h"

#define GAMEOVER_IMAGE_PATH		"Data/GameOverImage/GameOverpng.png"
#define GAMEOVER_BUTTON_PATH	"Data/GameOverImage/PleaseClick.png"

class SceneGameOver
{
private:
	int GameOverImagehndl;	//ゲームオーバー画面のハンドル
	int GameOverButtonhndl;	//ボタン画像のハンドル

public:
	SceneGameOver();
	~SceneGameOver();

	void InitGameOver();
	bool StepGameOver();
	void DrawGameOver();
	void FinGameOver();
};

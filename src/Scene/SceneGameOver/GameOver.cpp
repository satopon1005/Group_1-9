#include "DxLib.h"
#include "GameOver.h"
#include "../SceneTitle/SceneTitle.h"
#include "../SceneManager.h"
#include "../../Input/Input.h"

SceneGameOver::SceneGameOver()
{
	GameOverImagehndl = 0;
	GameOverButtonhndl = 0;
}

SceneGameOver::~SceneGameOver()
{
	FinGameOver();
}

void SceneGameOver::InitGameOver()
{
	GameOverImagehndl = LoadGraph(GAMEOVER_IMAGE_PATH);  //クリア画像の読み込み
	GameOverButtonhndl = LoadGraph(GAMEOVER_BUTTON_PATH);//ボタン画像の読み込み

	SetMouseDispFlag(true);
}

bool SceneGameOver::StepGameOver()
{
	//ボタンを押したらスタート
	if (Input::IsClickInArea(MOUSE_INPUT_LEFT,
		BUTTON_X,
		BUTTON_Y,
		BUTTON_X + BUTTON_W,
		BUTTON_Y + BUTTON_H))
		return true;
	return false;

}

void SceneGameOver::DrawGameOver()
{
	//クリア画面の表示
	DrawGraph(0, 0, GameOverImagehndl, true);
	//ボタン画像の表示
	DrawGraph(BUTTON_X, BUTTON_Y, GameOverButtonhndl, true);

}

void SceneGameOver::FinGameOver()
{
	DeleteGraph(GameOverImagehndl);
	DeleteGraph(GameOverButtonhndl);
}


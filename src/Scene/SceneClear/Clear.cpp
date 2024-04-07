#include "DxLib.h"
#include "Clear.h"
#include "../SceneTitle/SceneTitle.h"
#include "../../Input/Input.h"
#include "../SceneManager.h"

SceneClear::SceneClear()
{
	ClearImagehndl = 0;
	ClearButtonhndl = 0;
}

SceneClear::~SceneClear()
{
	FinClear();
}

void SceneClear::InitClear()
{
	ClearImagehndl = LoadGraph(CLEAR_IMAGE_PATH);  //クリア画像の読み込み
	ClearButtonhndl = LoadGraph(CLEAR_BUTTON_PATH);//ボタン画像の読み込み

	SetMouseDispFlag(true);
}

bool SceneClear::StepClear()
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

void SceneClear::DrawClear()
{
	//クリア画面の表示
	DrawGraph(0, 0, ClearImagehndl, true);
	//ボタン画像の表示
	DrawGraph(BUTTON_X, BUTTON_Y, ClearButtonhndl, true);

}

void SceneClear::FinClear()
{
	DeleteGraph(ClearImagehndl);
	DeleteGraph(ClearButtonhndl);
}
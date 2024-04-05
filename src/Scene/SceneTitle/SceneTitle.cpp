#include "DxLib.h"
#include "SceneTitle.h"
#include "../../Input/Input.h"
#include "../SceneManager.h"

SceneTitle::SceneTitle()
{
	TitleImagehandle = 0;
	TitleButtonhandle = 0;
}

SceneTitle::~SceneTitle()
{

}

void SceneTitle::InitTitle()
{
	TitleImagehandle = LoadGraph(TITLE_IMAGE_PATH);  //タイトル画像の読み込み
	TitleButtonhandle = LoadGraph(TITLE_BUTTON_PATH);//ボタン画像の読み込み

	SetMouseDispFlag(true);
}

bool SceneTitle::StepTitle()
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

void SceneTitle::DrawTitle()
{
	//タイトル画面の表示
	DrawGraph(0, 0, TitleImagehandle,true);
	//ボタン画像の表示
	DrawGraph(BUTTON_X, BUTTON_Y, TitleButtonhandle, true);

}

void SceneTitle::FinTitle()
{
	DeleteGraph(TitleImagehandle);
	DeleteGraph(TitleButtonhandle);
}

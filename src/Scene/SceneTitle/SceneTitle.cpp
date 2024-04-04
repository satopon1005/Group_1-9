#include "DxLib.h"
#include "SceneTitle.h"
#include "../../Input/Input.h"
#include "../SceneManager.h"

void SceneTitle::InitTitle()
{
	scenetitle.TitleImagehandle = LoadGraph(TITLE_IMAGE_PATH);  //タイトル画像の読み込み
	scenetitle.TitleButtonhandle = LoadGraph(TITLE_BUTTON_PATH);//ボタン画像の読み込み

	scenetitle.Title_x = 0, scenetitle.Title_y = 0;      //タイトルの座標
	scenetitle.Button_x = 400, scenetitle.Button_y = 500;//ボタンの座標

}

void SceneTitle::StepTitle()
{
	//ボタンを押したらスタート
	if (Input::IsClickInArea(MOUSE_INPUT_LEFT, 400, 500, 800, 900))
	{


	}

}

void SceneTitle::DrawTitle()
{
	//タイトル画面の表示
	DrawRotaGraph(scenetitle.Title_x, scenetitle.Title_y, 1.0, 0.0, scenetitle.TitleImagehandle,true);
	//ボタン画像の表示
	DrawRotaGraph(scenetitle.Button_x, scenetitle.Button_y, 1.0, 0.0, scenetitle.TitleButtonhandle, true);

}

void SceneTitle::FinTitle()
{
	
}

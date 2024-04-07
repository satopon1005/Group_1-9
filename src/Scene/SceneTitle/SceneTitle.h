#pragma once

#include "../../Common.h"

#define TITLE_IMAGE_PATH "Data/TitleImage/Title Image.png"        //タイトル
#define TITLE_BUTTON_PATH "Data/TitleImage/Start Button.png"//ボタン

constexpr int BUTTON_W = 400;
constexpr int BUTTON_H = 100;
constexpr int BUTTON_X = SCREEN_SIZE_X / 2 - BUTTON_W / 2;
constexpr int BUTTON_Y = SCREEN_SIZE_Y - BUTTON_H - 100;

class SceneTitle
{
private:
	int TitleImagehandle;	//タイトル画面のハンドル
	int TitleButtonhandle;	//ボタン画像のハンドル

public:
	SceneTitle();
	~SceneTitle();

	void InitTitle();
	bool StepTitle();
	void DrawTitle();
	void FinTitle();

};
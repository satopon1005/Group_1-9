#pragma once

#include "../../Common.h"

#define CLEAR_IMAGE_PATH	"Data/ClearImage/GameClear.png"
#define CLEAR_BUTTON_PATH	"Data/ClearImage/Please Click.png"

class SceneClear
{
private:
	int ClearImagehndl;	//タイトル画面のハンドル
	int ClearButtonhndl;	//ボタン画像のハンドル

public:
	SceneClear();
	~SceneClear();

	void InitClear();
	bool StepClear();
	void DrawClear();
	void FinClear();
};

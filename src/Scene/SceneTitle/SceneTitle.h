#pragma once


#define TITLE_IMAGE_PATH "Data/TitleImage.png"        //タイトル
#define TITLE_BUTTON_PATH "Data/TitlebuttonImage.jfif"//ボタン

class SceneTitle
{
private:
	

	int TitleImagehandle,TitleButtonhandle;//タイトル画面とボタン画像のハンドル
	int Title_x, Title_y;
	int Button_x, Button_y;

public:

	void InitTitle();
	void StepTitle();
	void DrawTitle();
	void FinTitle();

};

SceneTitle scenetitle;
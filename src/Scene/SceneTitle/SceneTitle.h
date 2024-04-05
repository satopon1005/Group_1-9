#pragma once


#define TITLE_IMAGE_PATH "Data/TitleImage/TitleImage.png"        //タイトル
#define TITLE_BUTTON_PATH "Data/TitleImage/TitlebuttonImage.png"//ボタン

constexpr int BUTTON_X = 400;
constexpr int BUTTON_Y = 400;
constexpr int BUTTON_W = 400;
constexpr int BUTTON_H = 100;

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
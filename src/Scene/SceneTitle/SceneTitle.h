#pragma once


#define TITLE_IMAGE_PATH "Data/TitleImage/TitleImage.png"        //�^�C�g��
#define TITLE_BUTTON_PATH "Data/TitleImage/TitlebuttonImage.png"//�{�^��

constexpr int BUTTON_X = 400;
constexpr int BUTTON_Y = 400;
constexpr int BUTTON_W = 400;
constexpr int BUTTON_H = 100;

class SceneTitle
{
private:
	int TitleImagehandle;	//�^�C�g����ʂ̃n���h��
	int TitleButtonhandle;	//�{�^���摜�̃n���h��

public:
	SceneTitle();
	~SceneTitle();

	void InitTitle();
	bool StepTitle();
	void DrawTitle();
	void FinTitle();

};
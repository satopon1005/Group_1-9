#pragma once


#define TITLE_IMAGE_PATH "Data/TitleImage.png"        //�^�C�g��
#define TITLE_BUTTON_PATH "Data/TitlebuttonImage.jfif"//�{�^��

class SceneTitle
{
private:
	

	int TitleImagehandle,TitleButtonhandle;//�^�C�g����ʂƃ{�^���摜�̃n���h��
	int Title_x, Title_y;
	int Button_x, Button_y;

public:

	void InitTitle();
	void StepTitle();
	void DrawTitle();
	void FinTitle();

};

SceneTitle scenetitle;
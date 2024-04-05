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
	TitleImagehandle = LoadGraph(TITLE_IMAGE_PATH);  //�^�C�g���摜�̓ǂݍ���
	TitleButtonhandle = LoadGraph(TITLE_BUTTON_PATH);//�{�^���摜�̓ǂݍ���

	SetMouseDispFlag(true);
}

bool SceneTitle::StepTitle()
{
	//�{�^������������X�^�[�g
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
	//�^�C�g����ʂ̕\��
	DrawGraph(0, 0, TitleImagehandle,true);
	//�{�^���摜�̕\��
	DrawGraph(BUTTON_X, BUTTON_Y, TitleButtonhandle, true);

}

void SceneTitle::FinTitle()
{
	DeleteGraph(TitleImagehandle);
	DeleteGraph(TitleButtonhandle);
}

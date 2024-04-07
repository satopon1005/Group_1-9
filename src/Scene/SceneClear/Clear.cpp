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
	ClearImagehndl = LoadGraph(CLEAR_IMAGE_PATH);  //�N���A�摜�̓ǂݍ���
	ClearButtonhndl = LoadGraph(CLEAR_BUTTON_PATH);//�{�^���摜�̓ǂݍ���

	SetMouseDispFlag(true);
}

bool SceneClear::StepClear()
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

void SceneClear::DrawClear()
{
	//�N���A��ʂ̕\��
	DrawGraph(0, 0, ClearImagehndl, true);
	//�{�^���摜�̕\��
	DrawGraph(BUTTON_X, BUTTON_Y, ClearButtonhndl, true);

}

void SceneClear::FinClear()
{
	DeleteGraph(ClearImagehndl);
	DeleteGraph(ClearButtonhndl);
}
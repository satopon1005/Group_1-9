#include "DxLib.h"
#include "GameOver.h"
#include "../SceneTitle/SceneTitle.h"
#include "../SceneManager.h"
#include "../../Input/Input.h"

SceneGameOver::SceneGameOver()
{
	GameOverImagehndl = 0;
	GameOverButtonhndl = 0;
}

SceneGameOver::~SceneGameOver()
{
	FinGameOver();
}

void SceneGameOver::InitGameOver()
{
	GameOverImagehndl = LoadGraph(GAMEOVER_IMAGE_PATH);  //�N���A�摜�̓ǂݍ���
	GameOverButtonhndl = LoadGraph(GAMEOVER_BUTTON_PATH);//�{�^���摜�̓ǂݍ���

	SetMouseDispFlag(true);
}

bool SceneGameOver::StepGameOver()
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

void SceneGameOver::DrawGameOver()
{
	//�N���A��ʂ̕\��
	DrawGraph(0, 0, GameOverImagehndl, true);
	//�{�^���摜�̕\��
	DrawGraph(BUTTON_X, BUTTON_Y, GameOverButtonhndl, true);

}

void SceneGameOver::FinGameOver()
{
	DeleteGraph(GameOverImagehndl);
	DeleteGraph(GameOverButtonhndl);
}


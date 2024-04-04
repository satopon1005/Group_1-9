#include "DxLib.h"
#include "SceneTitle.h"
#include "../../Input/Input.h"
#include "../SceneManager.h"

void SceneTitle::InitTitle()
{
	scenetitle.TitleImagehandle = LoadGraph(TITLE_IMAGE_PATH);  //�^�C�g���摜�̓ǂݍ���
	scenetitle.TitleButtonhandle = LoadGraph(TITLE_BUTTON_PATH);//�{�^���摜�̓ǂݍ���

	scenetitle.Title_x = 0, scenetitle.Title_y = 0;      //�^�C�g���̍��W
	scenetitle.Button_x = 400, scenetitle.Button_y = 500;//�{�^���̍��W

}

void SceneTitle::StepTitle()
{
	//�{�^������������X�^�[�g
	if (Input::IsClickInArea(MOUSE_INPUT_LEFT, 400, 500, 800, 900))
	{


	}

}

void SceneTitle::DrawTitle()
{
	//�^�C�g����ʂ̕\��
	DrawRotaGraph(scenetitle.Title_x, scenetitle.Title_y, 1.0, 0.0, scenetitle.TitleImagehandle,true);
	//�{�^���摜�̕\��
	DrawRotaGraph(scenetitle.Button_x, scenetitle.Button_y, 1.0, 0.0, scenetitle.TitleButtonhandle, true);

}

void SceneTitle::FinTitle()
{
	
}

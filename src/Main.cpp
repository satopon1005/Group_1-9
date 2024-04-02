#include "DxLib.h"	//DX���C�u�����̃C���N���[�h
#include "Common.h"
#include "Input/Input.h"
#include "Frame/Frame.h"
#include "Objects/Player/Player.h"

// Win32�A�v���P�[�V������ WinMain�֐� ����n�܂�
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	//-----------------------------------------
	//��ԍŏ��ɂP�񂾂���鏈���������ɏ���
	//�E�B���h�E�̏�Ԃ�ݒ肷��
	ChangeWindowMode(true);

	//DX���C�u�����̏�����
	if (DxLib_Init() == -1) {
		return true;
	}

	InitGame();
	Player player;
	player.InitPlayer();

	//-----------------------------------------

	//�Q�[�����C�����[�v
	while (ProcessMessage() != -1)
	{
		Sleep(1);	//�V�X�e���ɏ�����Ԃ�

		//���݂̎��Ԃ��擾
		frameRateInfo.currentTime = GetNowCount();

		//�ŏ��̃��[�v�Ȃ�A
		//���݂̎��Ԃ��AFPS�̌v�Z���������Ԃɐݒ�
		if (frameRateInfo.calcFpsTime == 0.0f)
		{
			frameRateInfo.calcFpsTime = frameRateInfo.currentTime;
			frameRateInfo.fps = (float)FRAME_RATE;
		}

		// ���݂̎��Ԃ��A�O��̃t���[�������
		// 100/60�~���b�i1/60�b�j�ȏ�o�߂��Ă����珈�������s����
		if (frameRateInfo.currentTime - frameRateInfo.LastFrameTime >= FRAME_TIME)
		{
			//�t���[�����s���̎��Ԃ��X�V
			frameRateInfo.LastFrameTime = frameRateInfo.currentTime;

			//�t���[�������J�E���g
			frameRateInfo.count++;

			if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)
			{
				//�G�X�P�[�v�L�[�������ꂽ��I��
				return true;
			}

			//��ʂɕ\�����ꂽ���̂�������
			ClearDrawScreen();

			Input::StepInput();

			// ��������������������������������������������������������������
			//�����ɃQ�[���̖{�̂��������ƂɂȂ�
			//-----------------------------------------

			player.MovePlayer();
			player.DrawPlayer();

			// ��������������������������������������������������������������
			//���[�v�̏I����
			
			//FPS�v�Z
			CalcFPS();

			//FPS�\��
			DrawFPS();

			//�t���b�v�֐�
			ScreenFlip();
		}
	}

	//-----------------------------------------
	//�Ō�ɂP�񂾂���鏈���������ɏ���

	FinGame();

	return 0;
}

void InitGame()
{
	// ��ʃT�C�Y��ύX
	SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, 32);

	SetDrawScreen(DX_SCREEN_BACK);	//�`�悷��X�N���[����ݒ肷��

	SetMouseDispFlag(false);

	Input::InitInput();
}

void FinGame()
{
	//DX���C�u�����̌㏈��
	DxLib_End();
}
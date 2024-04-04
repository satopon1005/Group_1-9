#include "DxLib.h"
#include "../../Common.h"
#include "ScenePlay.h"

void ScenePlay::InitPlay()
{
	player.InitPlayer();
	count_time.InitCountTime(1, 30);
}

void ScenePlay::LoopPlay()
{
	if (CheckHitKey(KEY_INPUT_RETURN) == 1) {
		if (!count_time.GetCountTimeFlag()) {
			count_time.StartCountTime();
		}
	}

	if (count_time.GetCountTimeFlag()) {
		count_time.StepCountTimeDown();
	}

	count_time.CheckEndCountTimeDown();

	player.MovePlayer();

	DrawBox(0, 0, SCREEN_SIZE_X, SCREEN_SIZE_Y, GetColor(255, 255, 255), true);

	count_time.DrawCountTime();

	player.DrawPlayer();
}
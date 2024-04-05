#include "DxLib.h"
#include "../../Common.h"
#include "ScenePlay.h"
#include "../../Input/Input.h"

void ScenePlay::InitPlay()
{
	player.InitPlayer();
	for (int i = 0; i < ENEMY_MAX_NUM; i++)
		enemy[i].InitEnemy();
	count_time[0].InitCountTime(1, 30);
	count_time[1].InitCountTime(0, 3);

	SetMouseDispFlag(false);
}

void ScenePlay::LoopPlay()
{
	//ŽžŠÔŒo‰ßˆ—
	//================================================

	if (Input::IsKeyPush(KEY_INPUT_RETURN) == 1) {
		if (!count_time[1].GetCountTimeFlag()) {
			count_time[1].StartCountTime();
		}
	}

	if (count_time[1].GetCountTimeFlag()) {
		count_time[1].StepCountTimeDown();
	}


	if (count_time[1].CheckEndCountTimeDown()) {
		if (!count_time[0].GetCountTimeFlag()) {
			count_time[0].StartCountTime();
		}
	}

	if (count_time[0].GetCountTimeFlag()) {
		count_time[0].StepCountTimeDown();
	}

	count_time[0].CheckEndCountTimeDown();
	//================================================

	player.CheckPlayerMousePoint();

	if (count_time[1].CheckEndCountTimeDown()) {
		player.MovePlayer();
		if (count_time[0].GetNowTime() == count_time[0].GetStartTime())
		{
			for (int i = 0; i < ENEMY_MAX_NUM; i++)
			{
				if (!enemy[i].GetUseFlag())
				{
					enemy[i].SpawnEnemy(player.GetPos());
					break;
				}
			}
		}
	}

	for (int i = 0; i < ENEMY_MAX_NUM; i++)
	{
		enemy[i].MoveEnemy();
	}

	//•`‰æ
	DrawBox(0, 0, SCREEN_SIZE_X, SCREEN_SIZE_Y, GetColor(255, 255, 255), true);

	if (count_time[1].GetCountTimeFlag())
		count_time[1].DrawCountTimeStart();

	count_time[0].DrawCountTime();

	for (int i = 0; i < ENEMY_MAX_NUM; i++)
	{
		enemy[i].DrawEnemy();
	}

	player.DrawPlayer();
}
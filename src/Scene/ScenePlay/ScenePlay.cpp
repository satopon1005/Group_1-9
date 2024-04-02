#include "DxLib.h"
#include "../../Common.h"
#include "ScenePlay.h"

void ScenePlay::InitPlay()
{
	player.InitPlayer();
}

void ScenePlay::LoopPlay()
{
	DrawBox(0, 0, SCREEN_SIZE_X, SCREEN_SIZE_Y, GetColor(255, 255, 255), true);

	player.MovePlayer();
	player.DrawPlayer();
}
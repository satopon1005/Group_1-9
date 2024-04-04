#pragma once

#include "../../Objects/Player/Player.h"
#include "../../Objects/Enemy/Enemy.h"
#include "../../CountTime/CountTime.h"

constexpr int ENEMY_MAX_NUM = 10;

class ScenePlay
{
private:
	Player player;
	Enemy enemy[ENEMY_MAX_NUM];
	CountTime count_time[2];

public:
	void InitPlay();
	void LoopPlay();
};
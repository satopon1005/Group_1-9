#pragma once

#include "../../Objects/Player/Player.h"
#include "../../Objects/Enemy/Enemy.h"
#include "../../CountTime/CountTime.h"

constexpr int ENEMY_MAX_NUM = 30;

class ScenePlay
{
private:
	Player player;
	Enemy enemy[ENEMY_MAX_NUM];
	CountTime count_time[2];
	int m_fg_alpha;
	bool m_next_flag;
	bool m_player_death_flag;
	int m_fg_color;

public:
	void InitPlay();
	bool StepPlay();
	void DrawPlay();
	void FinPlay();

	bool GetPlayerDeayhFlag() { return m_player_death_flag; }
};
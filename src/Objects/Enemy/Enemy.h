#pragma once

#include "../Objects.h"
#include "../../Common.h"
#include "../Player/Player.h"

constexpr int ENEMY_SPAWN_AREA_X = SCREEN_SIZE_X - PLAYER_MOVE_LIMIT_X * 2;
constexpr int ENEMY_SPAWN_AREA_Y = SCREEN_SIZE_Y - PLAYER_MOVE_LIMIT_Y * 2;

constexpr float ENEMY_SPEED = 2.0;

class Enemy :public Objects
{
private:
	VECTOR e_pos;
	VECTOR e_vec;
	double e_angle;

	bool Arrow_Flag;
	

public:
	Enemy();
	~Enemy();

	void InitEnemy();
	void FinEnemy();

	void SpawnEnemy();
	void MoveEnemy();
	void DrawEnemy();

	bool GetUseFlag() { return Arrow_Flag; }
};
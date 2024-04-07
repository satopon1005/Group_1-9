#pragma once

#include "../Objects.h"
#include "../../Common.h"
#include "../Player/Player.h"

constexpr int ENEMY_SPAWN_AREA_X = SCREEN_SIZE_X - PLAYER_MOVE_LIMIT_X * 2;
constexpr int ENEMY_SPAWN_AREA_Y = SCREEN_SIZE_Y - PLAYER_MOVE_LIMIT_Y * 2;

constexpr int ENEMY_COLLISION_X = 100;
constexpr int ENEMY_COLLISION_Y = 10;

constexpr float ENEMY_SPEED = 2.0;

class Enemy :public Objects
{
private:
	VECTOR m_enemy_vec;
	double m_enemy_angle;

	bool Arrow_Flag;

	int m_random_spawn_num;
	

public:
	Enemy();
	~Enemy();

	void InitEnemy();
	void FinEnemy();

	void SpawnEnemy();
	void DeathEnemy();

	void DrawCollision();

	void MoveEnemy();
	void DrawEnemy();

	bool GetUseFlag() { return Arrow_Flag; }

	int GetRandomSpawnNum() { return m_random_spawn_num; }
};
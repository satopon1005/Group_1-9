#pragma once

#include "../Objects.h"

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

	void SpawnEnemy(VECTOR player_pos);
	void MoveEnemy();
	void DrawEnemy();

	bool GetUseFlag() { return Arrow_Flag; }
};
#pragma once

#include "../Objects.h"

class Enemy :public Objects
{
private:
	VECTOR e_pos;
	VECTOR e_vec;
	double e_angle;

	int Arrowhndl;

	bool Arrow_Flag;
	

public:
	Enemy();
	~Enemy();

	void InitEnemy();
	void SpawnEnemy(VECTOR player_pos);
	void MoveEnemy();
	void DrawEnemy();
};
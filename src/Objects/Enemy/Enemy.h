#pragma once

#include "../Objects.h"

class Enemy :public Objects
{
private:
	VECTOR e_pos;

	int Arrowhndl;

	bool Arrow_Flag;
	

public:
	Enemy();
	~Enemy();

	void InitEnemy();
	void SpawnEnemy();
	void MoveEnemy();
	void DrawEnemy();
};
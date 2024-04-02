#pragma once

#include "../Objects.h"

class Player :public Objects
{
private:
	VECTOR m_move_vec;
	VECTOR mouse_pos;

public:
	Player();
	~Player();

	void InitPlayer();

	void MovePlayer();
	void DrawPlayer();
};
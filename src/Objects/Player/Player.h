#pragma once

#include "../Objects.h"

//ƒvƒŒƒCƒ„[‚ÌˆÚ“®”ÍˆÍ
constexpr int PLAYER_MOVE_LIMIT_X = 300;
constexpr int PLAYER_MOVE_LIMIT_Y = 150;

constexpr int PLAYER_COLLISION_R = 5;

class Player :public Objects
{
private:
	VECTOR m_move_vec;
	VECTOR mouse_pos;

public:
	Player();
	~Player();

	void InitPlayer();

	void CheckPlayerMousePoint();

	void MovePlayer();
	void DrawPlayer();
};
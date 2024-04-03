#pragma once

#include "../Objects.h"

//ƒvƒŒƒCƒ„[‚ÌˆÚ“®”ÍˆÍ
constexpr int move_limit_Lx = 300;
constexpr int move_limit_Rx = 980;
constexpr int move_limit_Uy = 150;
constexpr int move_limit_Dy = 570;

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
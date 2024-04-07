#pragma once

#include "../Objects.h"

#define PLAYER_HANDLE_PATH	"Data/PlayerImage/Player.png"

//ÉvÉåÉCÉÑÅ[ÇÃà⁄ìÆîÕàÕ
constexpr int PLAYER_MOVE_LIMIT_X = 300;
constexpr int PLAYER_MOVE_LIMIT_Y = 150;


constexpr int PLAYER_DISPLAY_R = 16;
constexpr int PLAYER_COLLISION_R = PLAYER_DISPLAY_R - 4;

constexpr int PLAYER_MOVE_SPEED = 300;

class Player :public Objects
{
private:
	VECTOR m_move_vec;
	VECTOR mouse_pos;

public:
	Player();
	~Player();

	void InitPlayer();
	void FinPlayer();

	void CheckPlayerMousePoint();

	void MovePlayer();
	void DrawPlayer();
};
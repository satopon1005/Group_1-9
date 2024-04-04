#include "DxLib.h"
#include "../../Common.h"
#include "Player.h"
#include "../../MyMath/MyMath.h"
#include "../../Input/Input.h"

Player::Player()
{
	m_move_vec = { 0 };
	mouse_pos = { 0 };
}
Player::~Player()
{

}

void Player::InitPlayer() {
	m_pos = { SCREEN_SIZE_X / 2,SCREEN_SIZE_Y / 2,0 };
}

void Player::CheckPlayerMousePoint()
{
	//マウスのポジション
	int mouse_pos_x, mouse_pos_y;

	GetMousePoint(&mouse_pos_x, &mouse_pos_y);

	mouse_pos = VGet((float)mouse_pos_x, (float)mouse_pos_y, 0);
}

void Player::MovePlayer()
{
	//動く向きと速さ
	m_move_vec = GetVector(mouse_pos, m_pos, 3);

	m_pos.x += m_move_vec.x;
	m_pos.y += m_move_vec.y;
	m_pos.z += m_move_vec.z;

	//プレイヤーが範囲外に行かない
	if (m_pos.x <= PLAYER_MOVE_LIMIT_X)
	{
		m_pos.x = PLAYER_MOVE_LIMIT_X;
	}
	if (m_pos.x >= SCREEN_SIZE_X - PLAYER_MOVE_LIMIT_X)
	{
		m_pos.x = SCREEN_SIZE_X - PLAYER_MOVE_LIMIT_X;
	}
	if (m_pos.y <= PLAYER_MOVE_LIMIT_Y)
	{
		m_pos.y = PLAYER_MOVE_LIMIT_Y;
	}
	if (m_pos.y >= SCREEN_SIZE_Y - PLAYER_MOVE_LIMIT_Y)
	{
		m_pos.y = SCREEN_SIZE_Y - PLAYER_MOVE_LIMIT_Y;
	}

}

void Player::DrawPlayer()
{
	DrawCircle((int)m_pos.x, (int)m_pos.y, 5, GetColor(0, 0, 0), false);

	DrawCircle((int)mouse_pos.x, (int)mouse_pos.y, 5, GetColor(0, 255, 0), true);

	//プレイヤーの移動範囲仮置き
	//横
	DrawLine(PLAYER_MOVE_LIMIT_X - PLAYER_COLLISION_R,
		PLAYER_MOVE_LIMIT_Y - PLAYER_COLLISION_R,
		SCREEN_SIZE_X - PLAYER_MOVE_LIMIT_X + PLAYER_COLLISION_R,
		PLAYER_MOVE_LIMIT_Y - PLAYER_COLLISION_R,
		GetColor(0, 0, 5));

	DrawLine(PLAYER_MOVE_LIMIT_X - PLAYER_COLLISION_R,
		SCREEN_SIZE_Y - PLAYER_MOVE_LIMIT_Y + PLAYER_COLLISION_R,
		SCREEN_SIZE_X - PLAYER_MOVE_LIMIT_X + PLAYER_COLLISION_R,
		SCREEN_SIZE_Y - PLAYER_MOVE_LIMIT_Y + PLAYER_COLLISION_R,
		GetColor(0, 0, 5));

	//縦
	DrawLine(PLAYER_MOVE_LIMIT_X - PLAYER_COLLISION_R,
		PLAYER_MOVE_LIMIT_Y - PLAYER_COLLISION_R,
		PLAYER_MOVE_LIMIT_X - PLAYER_COLLISION_R,
		SCREEN_SIZE_Y - PLAYER_MOVE_LIMIT_Y + PLAYER_COLLISION_R,
		GetColor(0, 0, 5));
	DrawLine(SCREEN_SIZE_X - PLAYER_MOVE_LIMIT_X + PLAYER_COLLISION_R,
		PLAYER_MOVE_LIMIT_Y - PLAYER_COLLISION_R,
		SCREEN_SIZE_X - PLAYER_MOVE_LIMIT_X + PLAYER_COLLISION_R,
		SCREEN_SIZE_Y - PLAYER_MOVE_LIMIT_Y + PLAYER_COLLISION_R,
		GetColor(0, 0, 5));

}
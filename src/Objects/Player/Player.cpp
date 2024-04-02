#include "DxLib.h"
#include "Player.h"

void Player::MovePlayer()
{
	int mouse_pos_x, mouse_pos_y;

	GetMousePoint(&mouse_pos_x, &mouse_pos_y);

	VECTOR mouse_pos = VGet((float)mouse_pos_x, (float)mouse_pos_y, 0);
}

void Player::DrawPlayer()
{
	DrawCircle(m_pos.x, m_pos.y, 5, GetColor(255, 255, 255), false);
}
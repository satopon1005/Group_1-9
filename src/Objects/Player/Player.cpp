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

void Player::MovePlayer()
{
	//マウスのポジション
	int mouse_pos_x, mouse_pos_y;

	GetMousePoint(&mouse_pos_x, &mouse_pos_y);

	mouse_pos = VGet((float)mouse_pos_x, (float)mouse_pos_y, 0);

	//動く向きと速さ
	m_move_vec = GetVector(mouse_pos, m_pos, 3);

	m_pos.x += m_move_vec.x;
	m_pos.y += m_move_vec.y;
	m_pos.z += m_move_vec.z;

	/*if (Input::IsKeyDown(KEY_INPUT_UP))
		m_pos.y -= 3;
	if (Input::IsKeyDown(KEY_INPUT_DOWN))
		m_pos.y += 3;
	if (Input::IsKeyDown(KEY_INPUT_LEFT))
		m_pos.x -= 3;
	if (Input::IsKeyDown(KEY_INPUT_RIGHT))
		m_pos.x += 3;*/
}

void Player::DrawPlayer()
{
	DrawCircle((int)m_pos.x, (int)m_pos.y, 5, GetColor(255, 255, 255), false);

	DrawCircle((int)mouse_pos.x, (int)mouse_pos.y, 5, GetColor(0, 255, 0), true);
}
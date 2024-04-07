#include "DxLib.h"
#include "Enemy.h"
#include "../../MyMath/MyMath.h"
#include "../../Common.h"
#include "../../Input/Input.h"

Enemy::Enemy()
{
	m_pos.x = 0;
	m_pos.y = 0;
	m_pos.z = 0;
	m_enemy_vec = { 0 };
	m_enemy_angle = 0;
	Arrow_Flag = false;

	m_random_spawn_num = 0;
}

Enemy::~Enemy()
{
	FinEnemy();
}

void Enemy::InitEnemy()
{
	m_pos.x = 0;
	m_pos.y = 0;
	m_pos.z = 0;
	m_enemy_vec = { 0 };
	m_enemy_angle = 0;
	Arrow_Flag = false;
	m_handle = LoadGraph("Data/EnemyImage/yajirushi-illust13(1).png");
}

void Enemy::FinEnemy()
{
	DeleteGraph(m_handle);
}

void Enemy::SpawnEnemy()
{
	if (Arrow_Flag == false) {
		m_random_spawn_num = GetRand(2);

		//ランダムスポーン処理
		switch (m_random_spawn_num)
		{
		case 0:
		{
			//右側矢印スポーン処理
			m_pos.x = SCREEN_SIZE_X;
			m_pos.y = (float)GetRand(ENEMY_SPAWN_AREA_Y) + PLAYER_MOVE_LIMIT_Y;
			m_enemy_vec = VGet(-ENEMY_SPEED, 0.0f, 0.0f);
			m_enemy_angle = AngleOf2Vector(VGet(1, 0, 0), m_enemy_vec);
			Arrow_Flag = true;
		}
		break;
		case 1:
		{
			//左側矢印スポーン処理
			m_pos.x = 0;
			m_pos.y = (float)GetRand(ENEMY_SPAWN_AREA_Y) + PLAYER_MOVE_LIMIT_Y;
			m_enemy_vec = VGet(ENEMY_SPEED, 0.0f, 0.0f);
			m_enemy_angle = AngleOf2Vector(VGet(1, 0, 0), m_enemy_vec);
			Arrow_Flag = true;
		}
		break;
		case 2:
		{
			//上側矢印スポーン処理
			m_pos.x = (float)GetRand(ENEMY_SPAWN_AREA_X) + PLAYER_MOVE_LIMIT_X;
			m_pos.y = 0;
			m_enemy_vec = VGet(0.0f, ENEMY_SPEED, 0.0f);
			m_enemy_angle = AngleOf2Vector(VGet(1, 0, 0), m_enemy_vec);
			Arrow_Flag = true;
		}
		break;
		}
	}
}

void Enemy::DeathEnemy()
{
	if (m_pos.x<0 ||
		m_pos.x>SCREEN_SIZE_X ||
		m_pos.y<0 ||
		m_pos.y>SCREEN_SIZE_Y) {
		Arrow_Flag = false;
	}
}

void Enemy::MoveEnemy()
{
	if (Arrow_Flag == true) {
		m_pos.x += m_enemy_vec.x;
		m_pos.y += m_enemy_vec.y;
	}
}

void Enemy::DrawEnemy()
{
	if (Arrow_Flag == true) {
		DrawRotaGraph((int)m_pos.x, (int)m_pos.y, 1.0, m_enemy_angle, m_handle, true);

		//DrawCollision();
	}
}

void Enemy::DrawCollision(){
	int collision_x, collision_y;

	if (m_random_spawn_num == 2) {
		collision_x = ENEMY_COLLISION_Y;
		collision_y = ENEMY_COLLISION_X;
	}
	else {
		collision_x = ENEMY_COLLISION_X;
		collision_y = ENEMY_COLLISION_Y;
	}

	DrawBox((int)(m_pos.x - collision_x / 2),
		(int)(m_pos.y - collision_y / 2),
		(int)(m_pos.x + collision_x / 2),
		(int)(m_pos.y + collision_y / 2),
		GetColor(255, 0, 0), false);
}

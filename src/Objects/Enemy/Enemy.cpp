#include "DxLib.h"
#include "Enemy.h"
#include "../Player/Player.h"
#include "../../MyMath/MyMath.h"
#include "../../Common.h"
#include "../../Input/Input.h"

Enemy::Enemy()
{
	e_pos.x = 0;
	e_pos.y = 0;
	e_pos.z = 0;
	e_vec = { 0 };
	e_angle = 0;
	Arrow_Flag = false;
}

Enemy::~Enemy()
{
	FinEnemy();
}

void Enemy::InitEnemy()
{
	e_pos.x = 1300;
	e_pos.y = GetRand(720);
	e_pos.z = 0;
	e_vec = { 0 };
	e_angle = 0;
	Arrow_Flag = false;
	m_handle = LoadGraph("Data/EnemyImage/yajirushi-illust13(1).png");
}

void Enemy::FinEnemy()
{
	DeleteGraph(m_handle);
}

void Enemy::SpawnEnemy(VECTOR player_pos)
{
	int random_spawn = GetRand(2);

	//ランダムスポーン処理
	switch (random_spawn)
	{
		case 0:
		{
			//右側矢印スポーン処理
			if (Arrow_Flag == false)
			{
				e_pos.x = 1300;
				e_pos.y = GetRand(720);
				e_vec = GetVector(e_pos, player_pos);
				e_angle = AngleOf2Vector(VGet(1, 0, 0), e_vec,5);
				Arrow_Flag = true;
			}
		}
		break;
		case 1:
		{
			//左側矢印スポーン処理
			if (Arrow_Flag == false)
			{
				e_pos.x = 0;
				e_pos.y = GetRand(720);
				Arrow_Flag = true;
			}
		}
		break;
		case 2:
		{
			//上側矢印スポーン処理
			if (Arrow_Flag == false)
			{
				e_pos.x = GetRand(720);
				e_pos.y = 0;
				Arrow_Flag = true;
			}
		}
		break;
	}
}

void Enemy::MoveEnemy()
{
	if (Arrow_Flag == true) {
		e_pos.x += e_vec.x;
		e_pos.y += e_vec.y;
	}
}

void Enemy::DrawEnemy()
{
	if (Arrow_Flag == true)
		DrawRotaGraph(e_pos.x, e_pos.y, 1.0, e_angle, m_handle, true);
}

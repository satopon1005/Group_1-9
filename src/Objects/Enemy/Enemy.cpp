#include "DxLib.h"
#include "Enemy.h"
#include "../../MyMath/MyMath.h"
#include "../../Common.h"
#include "../../Input/Input.h"

Enemy::Enemy()
{
	e_pos.x = 1300;
	e_pos.y = GetRand(720);
	Arrow_Flag = false;
}

Enemy::~Enemy()
{

}

void Enemy::InitEnemy()
{
	e_pos.x = 1300;
	e_pos.y = GetRand(720);
	Arrow_Flag = false;
}

void Enemy::SpawnEnemy()
{
	int random_spawn = GetRand(2);

	//�����_���X�|�[������
	switch (random_spawn)
	{
		case 0:
		{
			//�E�����X�|�[������
			if (Arrow_Flag == false)
			{
				e_pos.x = 1300;
				e_pos.y = GetRand(720);
				Arrow_Flag = true;
			}
		}
		break;
		case 1:
		{
			//�������X�|�[������
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
			//�㑤���X�|�[������
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
	//��󔭎ˏ���
	if (Arrow_Flag == true)
	{
		e_pos.x++;
		if (e_pos.x <= -50)
		{
			Arrow_Flag = false;
		}
	}
}

void Enemy::DrawEnemy()
{

}

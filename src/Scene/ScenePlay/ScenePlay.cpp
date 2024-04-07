#include "DxLib.h"
#include "../../Common.h"
#include "ScenePlay.h"
#include "../../Input/Input.h"
#include "../SceneTitle/SceneTitle.h"
#include "../../Collision/Collision.h"

void ScenePlay::InitPlay()
{
	player.InitPlayer();
	for (int i = 0; i < ENEMY_MAX_NUM; i++)
		enemy[i].InitEnemy();
	count_time[0].InitCountTime(1, 30);
	count_time[1].InitCountTime(0, 3);

	m_fg_alpha = 255;
	m_fg_color = GetColor(255, 255, 255);

	m_next_flag = false;
	m_player_death_flag = false;

	SetMouseDispFlag(false);
}

bool ScenePlay::StepPlay()
{
	//時間経過処理
	//================================================
	//開始タイマー作動
	if (m_fg_alpha <= 0) {
		if (!count_time[1].GetCountTimeFlag()) {
			count_time[1].StartCountTime();
		}
	}
	//開始タイマーの処理
	if (count_time[1].GetCountTimeFlag()) {
		count_time[1].StepCountTimeDown();
	}

	//開始タイマーが終了したらプレイタイマー作動
	if (count_time[1].CheckEndCountTimeDown()) {
		if (!count_time[0].GetCountTimeFlag()) {
			count_time[0].StartCountTime();
		}
	}
	//プレイタイマーの処理
	if (m_next_flag == false && count_time[0].GetCountTimeFlag()) {
		count_time[0].StepCountTimeDown();
	}

	//開始タイマーが終了したらプレイシーン終了フラグを立てる
	if (count_time[0].CheckEndCountTimeDown()) {
		m_next_flag = true;
	}
	//================================================

	player.CheckPlayerMousePoint();

	//開始タイマーが終了したらプレイ開始
	if (m_next_flag == false && count_time[1].CheckEndCountTimeDown()) {

		player.MovePlayer();
		for (int i = 0; i < ENEMY_MAX_NUM; i++){
			//敵(矢印)の移動処理
			enemy[i].MoveEnemy();
			//画面外に行ったら消す
			enemy[i].DeathEnemy();
		}
		//１秒毎に敵(矢印)を出す
		if (count_time[0].GetNowTime() == count_time[0].GetStartTime()){
			for (int i = 0; i < ENEMY_MAX_NUM; i++)
			{
				if (!enemy[i].GetUseFlag())
				{
					enemy[i].SpawnEnemy();
					break;
				}
			}
		}

		//プレイヤーと敵の当たり判定
		for (int i = 0; i < ENEMY_MAX_NUM; i++) {

			int collision_x, collision_y;

			if (enemy[i].GetRandomSpawnNum() == 2) {
				collision_x = ENEMY_COLLISION_Y;
				collision_y = ENEMY_COLLISION_X;
			}
			else {
				collision_x = ENEMY_COLLISION_X;
				collision_y = ENEMY_COLLISION_Y;
			}

			if (Collision::IsHitRectCircle(player.GetPos().x,
				player.GetPos().y,
				PLAYER_COLLISION_R,
				enemy[i].GetPos().x - collision_x / 2,
				enemy[i].GetPos().y - collision_y / 2,
				collision_x,
				collision_y)) {
				m_next_flag = true;
				m_player_death_flag = true;
			}
		}
	}

	if (!m_next_flag) {
		if (m_fg_alpha > 0)
			m_fg_alpha -= FG_ALPHA_ADD_NUM;
	}
	else {
		m_fg_alpha += FG_ALPHA_ADD_NUM;
	}

	if (m_next_flag == true && m_fg_alpha >= 255)
		return true;

	return false;
}

void ScenePlay::DrawPlay()
{
	//描画
	DrawBox(0, 0, SCREEN_SIZE_X, SCREEN_SIZE_Y, GetColor(255, 255, 255), true);

	count_time[0].DrawCountTime();

	for (int i = 0; i < ENEMY_MAX_NUM; i++)
	{
		enemy[i].DrawEnemy();
	}

	player.DrawPlayer();

	if (count_time[1].GetCountTimeFlag())
		count_time[1].DrawCountTimeStart();

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, m_fg_alpha);
	DrawBox(0, 0, SCREEN_SIZE_X, SCREEN_SIZE_Y, m_fg_color, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
}

void ScenePlay::FinPlay()
{
	player.FinPlayer();
	for (int i = 0; i < ENEMY_MAX_NUM; i++)
	{
		enemy[i].FinEnemy();
	}
}
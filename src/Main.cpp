#include "DxLib.h"	//DXライブラリのインクルード
#include "Common.h"
#include "Input/Input.h"
#include "Frame/Frame.h"
#include "Scene/SceneManager.h"

// Win32アプリケーションは WinMain関数 から始まる
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	//-----------------------------------------
	//一番最初に１回だけやる処理をここに書く
	//ウィンドウの状態を設定する
	ChangeWindowMode(false);

	//DXライブラリの初期化
	if (DxLib_Init() == -1) {
		return true;
	}

	InitGame();
	SceneManager scene;

	//-----------------------------------------

	//ゲームメインループ
	while (ProcessMessage() != -1)
	{
		Sleep(1);	//システムに処理を返す

		//現在の時間を取得
		frameRateInfo.currentTime = GetNowCount();

		//最初のループなら、
		//現在の時間を、FPSの計算をした時間に設定
		if (frameRateInfo.calcFpsTime == 0.0f)
		{
			frameRateInfo.calcFpsTime = frameRateInfo.currentTime;
			frameRateInfo.fps = (float)FRAME_RATE;
		}

		// 現在の時間が、前回のフレーム時より
		// 100/60ミリ秒（1/60秒）以上経過していたら処理を実行する
		if (frameRateInfo.currentTime - frameRateInfo.LastFrameTime >= FRAME_TIME)
		{
			//フレーム実行時の時間を更新
			frameRateInfo.LastFrameTime = frameRateInfo.currentTime;

			//フレーム数をカウント
			frameRateInfo.count++;

			if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)
			{
				//エスケープキーが押されたら終了
				return true;
			}

			//画面に表示されたものを初期化
			ClearDrawScreen();

			Input::StepInput();

			// ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
			//ここにゲームの本体を書くことになる
			//-----------------------------------------

			scene.Main();

			// ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
			//ループの終わりに
			
			//FPS計算
			CalcFPS();

			//FPS表示
			DrawFPS();

			//フリップ関数
			ScreenFlip();
		}
	}

	//-----------------------------------------
	//最後に１回だけやる処理をここに書く

	FinGame();

	return 0;
}

void InitGame()
{
	// 画面サイズを変更
	SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, 32);

	SetDrawScreen(DX_SCREEN_BACK);	//描画するスクリーンを設定する

	Input::InitInput();
}

void FinGame()
{
	//DXライブラリの後処理
	DxLib_End();
}
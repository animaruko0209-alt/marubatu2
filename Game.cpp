#include "DxLib.h"
#include"Game.h"
#include"SceneBase.h"
#include <memory>
#include <ctime>

/// <summary>
/// ゲームループ
/// </summary>

void Game::Game_loop()
{

	scene_no = 0;

	// シーンベース型へのスマートポインタ変数に各シーン型のインスタンスをセット
	switch (this->scene_no) {

	case 0:
		// オープニング


		break;

	case 1:
		// テストシーン

		break;

	case 2:
		// エンディング

		break;
	case 3:

		break;
	}
	//SceneBase* curret_scene_ptr = new SceneTest();


	while (ProcessMessage() == 0)
	{

		// リフレッシュレートを設定するための処理

		clock_t check_fps = clock() + CLOCKS_PER_SEC / 60;

		// マウスカーソル表示設定

		SetMouseDispFlag(TRUE);

		// 画面上の描画を初期化（画面を消去）

		ClearDrawScreen();

		// =======================================
		//  入力処理
		// =======================================

		current_scene_ptr->Input();
		// =======================================
		//  更新処理
		// =======================================
		current_scene_ptr->Update();


		int next = current_scene_ptr->GetNextScene();
		if (next != -1)
		{
			// shared_ptr に置き換えたので delete は不要
			scene_no = next;

			InitGraph();

			switch (scene_no)
			{
			case 0:

				break;
			case 1:

				break;
			case 2:

				break;
			case 3:

				break;
			}


			continue;  // ← 新しいシーンのループを最初から実行
		}

		// =======================================
		//  描画処理
		// =======================================

		current_scene_ptr->Draw();

		// =======================================
		//  音声再生処理
		// =======================================

		current_scene_ptr->Sound_play();

		// リフレッシュレートが一定になるまで待つ処理

		while (clock() < check_fps) {}

		// 裏画面の描画を表に反映

		ScreenFlip();

	}

}


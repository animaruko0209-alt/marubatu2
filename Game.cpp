#include "DxLib.h"
#include"Game.h"
#include"SceneBase.h"
#include "CircleMove.h"
#include "Title.h"
#include"GameScene.h"
#include"Result.h"
#include <memory>
#include <ctime>

/// <summary>
/// ゲームループ
/// </summary>
void Game::Game_loop()
{
    // 最初にタイトル画面を作る
    current_scene_ptr = new SceneOp(this);
    current_scene_ptr->Init();
    scene_no = 0;
    while (ProcessMessage() == 0)
    {
        // 入力
        current_scene_ptr->Input();
        // 更新
        current_scene_ptr->Update();
        // シーン変更
        int next = current_scene_ptr->GetNextScene();
        if (next != -1)
        {
            delete current_scene_ptr;
            current_scene_ptr = nullptr;
            scene_no = next;
            switch (scene_no)
            {
            case 0:
                current_scene_ptr = new SceneOp(this);
                break;
            case 1:
                current_scene_ptr = new GameScene(this);
                break;
            case 2:
                current_scene_ptr = new Result(this);
                break;
            }
            if (current_scene_ptr != nullptr)
            {
                current_scene_ptr->Init();
            }
        }
        // 描画
        ClearDrawScreen();
        if (current_scene_ptr != nullptr)
        {
            current_scene_ptr->Draw();
        }
        ScreenFlip();
    }
    delete current_scene_ptr;
    current_scene_ptr = nullptr;
}

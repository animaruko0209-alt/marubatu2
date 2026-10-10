#include "Title.h"
#include "Game.h"
#include "SceneBase.h"
#include "DxLib.h"


void SceneOp::Init()
{
	
	next_scene = -1;

    // 決定SEを読み込む
    se_handle = LoadSoundMem("start.mp3");

    // キー入力状態を初期化
    space_prev = false;

    

}

/// <summary>
/// 入力処理
/// </summary>
void SceneOp::Input()
{
	
}

/// <summary>
/// 更新処理
/// </summary>
void SceneOp::Update()
{
    
    // 現在のスペースキー状態
    bool space_now = CheckHitKey(KEY_INPUT_SPACE);

    // 押した瞬間だけ処理する
    if (space_now && !space_prev)
    {
        // 決定SEを再生
        if (se_handle != -1)
        {
            // 音量を最大にする
            ChangeVolumeSoundMem(255, se_handle);

            PlaySoundMem(se_handle, DX_PLAYTYPE_NORMAL);

         

        }

        // ゲーム本編へ移動
       next_scene = 1;
    }

    // キー状態を保存
    space_prev = space_now;
	
	
}

/// <summary>
/// 描画処理
/// </summary>
void SceneOp::Draw()
{

    // 背景
    DrawBox(0, 0, 1200, 1000, GetColor(10, 15, 45), TRUE);

    // 背景の格子模様
    for (int i = 0; i < 1200; i += 80)
    {
        DrawLine(i, 0, i, 1000, GetColor(20, 30, 65), 1);
    }

    for (int i = 0; i < 1000; i += 80)
    {
        DrawLine(0, i, 1200, i, GetColor(20, 30, 65), 1);
    }

    // 上下の装飾ライン
    DrawBox(0, 0, 1200, 8, GetColor(0, 180, 255), TRUE);
    DrawBox(0, 992, 1200, 1000, GetColor(0, 180, 255), TRUE);

    // ○の装飾
    DrawCircle(180, 450, 65, GetColor(255, 0, 0), FALSE, 8);

    // ×の装飾
    DrawLine(960, 385, 1080, 505,
        GetColor(0, 0, 255), 8);
    DrawLine(1080, 385, 960, 505,
        GetColor(0, 0, 255), 8);


 
    // タイトルの影
    SetFontSize(102);
    DrawString(352, 257, "○×ゲーム",
        GetColor(0, 0, 255));

    //タイトル文字
    DrawString(340, 255, "○×ゲーム",
        GetColor(255, 255, 255));


    // タイトル下のライン
    DrawBox(350, 380, 850, 385,
        GetColor(0, 180, 255), TRUE);

    // サブタイトル
   SetFontSize(48);
    DrawString(475, 420, "TIC TAC TOE",
        GetColor(150, 200, 255));

    // スタート案内（点滅）
    if ((GetNowCount() / 500) % 2 == 0)
    {
        

        DrawString(407, 777, "Press SPACE Key!!",
            GetColor(255, 255, 255));

        DrawString(405, 775, "Press SPACE Key!!",
            GetColor(255, 220, 50));
    }
   
    SetFontSize(32);
}

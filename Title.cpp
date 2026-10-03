#include "Title.h"
#include "Game.h"
#include "SceneBase.h"
#include "DxLib.h"


void SceneOp::Init()
{
	
	next_scene = -1;
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
	
	
	
	if (CheckHitKey(KEY_INPUT_SPACE)) {
		
		next_scene = 1;
		//ゲーム本編へ
	}
	

	
	
}

/// <summary>
/// 描画処理
/// </summary>
void SceneOp::Draw()
{
	

	//SetFontSize(102);
	//DrawString(352, 92, "○×ゲーム", GetColor(220, 220, 220));
	//DrawString(350, 90, "○×ゲーム", GetColor(0, 0, 255));

	//SetFontSize(32);
	//DrawString(472, 602, "Press  SPACE Key!!", GetColor(220, 220, 220));
	//DrawString(470, 600, "Press  SPACE Key!!", GetColor(255, 0, 0));

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

    // タイトル文字
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
        SetFontSize(32);

        DrawString(457, 777, "Press SPACE Key!!",
            GetColor(255, 255, 255));

        DrawString(455, 775, "Press SPACE Key!!",
            GetColor(255, 220, 50));
    }

}

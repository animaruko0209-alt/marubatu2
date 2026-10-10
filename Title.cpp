#include "Title.h"
#include "Game.h"
#include "SceneBase.h"
#include "DxLib.h"
#include "ExplanationScene.h"


void SceneOp::Init()
{
    next_scene = -1;
    m_prevMouseLeft = (GetMouseInput() & MOUSE_INPUT_LEFT) != 0;
    m_prevHelpKey = CheckHitKey(KEY_INPUT_H) != 0;

    // 開始SEとキーの状態を初期化
    se_handle = LoadSoundMem("start.mp3");
    space_prev = false;
}

/// <summary>
/// 入力処理
/// </summary>
void SceneOp::Resume(int pauseTime)
{
    SceneBase::Resume(pauseTime);
    m_prevMouseLeft = (GetMouseInput() & MOUSE_INPUT_LEFT) != 0;
    m_prevHelpKey = CheckHitKey(KEY_INPUT_H) != 0;
    space_prev = CheckHitKey(KEY_INPUT_SPACE) != 0;
}
void SceneOp::Input()
{
	
}

/// <summary>
/// 更新処理
/// </summary>
void SceneOp::Update()
{
    int helpMouseX, helpMouseY;
    GetMousePoint(&helpMouseX, &helpMouseY);
    bool helpMouseLeft = (GetMouseInput() & MOUSE_INPUT_LEFT) != 0;
    bool helpKey = CheckHitKey(KEY_INPUT_H) != 0;
    bool space_now = CheckHitKey(KEY_INPUT_SPACE) != 0;
    bool helpClick = helpMouseLeft && !m_prevMouseLeft &&
        ExplanationScene::IsHelpButtonHit(helpMouseX, helpMouseY);
    bool openHelp = (helpKey && !m_prevHelpKey) || helpClick;
    m_prevHelpKey = helpKey;
    m_prevMouseLeft = helpMouseLeft;

    if (openHelp)
    {
        space_prev = space_now;
        next_scene = 3;
        return;
    }

    // スペースキーを押した瞬間にSEを鳴らしてゲームを開始
    if (space_now && !space_prev)
    {
        if (se_handle != -1)
        {
            ChangeVolumeSoundMem(255, se_handle);
            PlaySoundMem(se_handle, DX_PLAYTYPE_NORMAL);
        }
        next_scene = 1;
    }
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
    ExplanationScene::DrawHelpButton();
}

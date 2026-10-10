#include "ExplanationScene.h"
#include "DxLib.h"

ExplanationScene::ExplanationScene(int returnScene)
{
    m_returnScene = returnScene;
}

void ExplanationScene::Init()
{
    next_scene = -1;
    m_prevMouseLeft = (GetMouseInput() & MOUSE_INPUT_LEFT) != 0;
    m_prevBackKey = CheckHitKey(KEY_INPUT_ESCAPE) || CheckHitKey(KEY_INPUT_H);
}

void ExplanationScene::Input()
{
}

void ExplanationScene::Update()
{
    int mouseX, mouseY;
    GetMousePoint(&mouseX, &mouseY);
    bool mouseLeft = (GetMouseInput() & MOUSE_INPUT_LEFT) != 0;
    bool backKey = CheckHitKey(KEY_INPUT_ESCAPE) || CheckHitKey(KEY_INPUT_H);
    bool backClick = mouseLeft && !m_prevMouseLeft &&
        mouseX >= 400 && mouseX < 800 && mouseY >= 880 && mouseY < 945;

    if ((backKey && !m_prevBackKey) || backClick)
    {
        next_scene = m_returnScene;
    }

    m_prevMouseLeft = mouseLeft;
    m_prevBackKey = backKey;
}

bool ExplanationScene::IsHelpButtonHit(int x, int y)
{
    return x >= 970 && x < 1170 && y >= 30 && y < 95;
}

void ExplanationScene::DrawHelpButton()
{
    int mouseX, mouseY;
    GetMousePoint(&mouseX, &mouseY);
    int color = IsHelpButtonHit(mouseX, mouseY)
        ? GetColor(35, 100, 155) : GetColor(25, 55, 95);

    DrawBox(970, 30, 1170, 95, color, TRUE);
    DrawBox(970, 30, 1170, 95, GetColor(80, 200, 255), FALSE);
    SetFontSize(28);
    DrawString(990, 48, "遊び方 [H]", GetColor(255, 255, 255));
    SetFontSize(32);
}

void ExplanationScene::Draw()
{
    int white = GetColor(240, 245, 255);
    int blue = GetColor(80, 200, 255);
    int yellow = GetColor(255, 230, 80);
    int green = GetColor(50, 200, 70);
    int orange = GetColor(250, 120, 30);
    int card = GetColor(20, 32, 60);

    DrawBox(0, 0, 1200, 1000, GetColor(10, 15, 45), TRUE);
    DrawBox(0, 0, 1200, 8, blue, TRUE);
    DrawBox(0, 992, 1200, 1000, blue, TRUE);
    SetFontSize(56);
    DrawString(60, 50, "遊び方", white);
    SetFontSize(26);
    DrawString(62, 120, "○と×が交互に、駒を置くか動かすゲームです。", blue);

    DrawBox(60, 180, 650, 465, card, TRUE);
    DrawBox(680, 180, 1140, 465, card, TRUE);
    DrawBox(60, 485, 650, 835, card, TRUE);
    DrawBox(680, 485, 1140, 835, card, TRUE);

    SetFontSize(32);
    DrawString(85, 200, "01  駒を置く", blue);
    SetFontSize(26);
    DrawString(85, 255, "空いているマスをクリックして配置。", white);
    DrawString(85, 300, "駒は○・×それぞれ最大5個です。", white);
    DrawString(85, 345, "直前に置いた3×3のエリアには、", white);
    DrawString(85, 380, "続けて新しい駒を置けません。", white);
    DrawString(85, 425, "1ターン30秒。時間切れで交代します。", yellow);

    SetFontSize(32);
    DrawString(705, 200, "02  勝利条件", blue);
    SetFontSize(24);
    DrawString(705, 250, "4つの3×3エリアのどれかで", white);
    DrawString(705, 285, "自分の駒を縦・横・斜めに", white);
    DrawString(705, 320, "3個そろえれば勝ち！", yellow);
    DrawString(705, 365, "GとOを混ぜてもOK。", white);
    DrawString(705, 405, "赤い線がエリアの境目です。", white);

    SetFontSize(32);
    DrawString(85, 505, "03  駒を動かす", blue);
    SetFontSize(26);
    DrawString(85, 560, "自分の駒をクリックして選択。", white);
    DrawString(85, 605, "水色のマスをクリックして移動します。", white);
    DrawString(85, 650, "駒のあるマスや、その先へは進めません。", white);
    DrawString(85, 695, "同じ駒をもう一度クリックすると取消。", white);
    DrawString(85, 740, "別の自分の駒で選び直せます。", white);
    SetFontSize(24);
    DrawString(85, 790, "黄色：置けるマス・選択できる自分の駒", yellow);

    SetFontSize(32);
    DrawString(705, 505, "04  駒の種類と操作", blue);
    SetFontSize(26);
    DrawString(705, 560, "上キー：G（緑）を置く", green);
    DrawString(705, 600, "Gの移動方向：縦・横", white);
    DrawString(705, 655, "下キー：O（オレンジ）を置く", orange);
    DrawString(705, 695, "Oの移動方向：斜め", white);
    SetFontSize(24);
    DrawString(705, 750, "どちらも空きマスを何マスでも移動。", white);
    DrawString(705, 790, "説明中は制限時間が止まります。", blue);

    int mouseX, mouseY;
    GetMousePoint(&mouseX, &mouseY);
    bool hover = mouseX >= 400 && mouseX < 800 && mouseY >= 880 && mouseY < 945;
    DrawBox(400, 880, 800, 945, hover ? GetColor(35, 100, 155) : GetColor(25, 55, 95), TRUE);
    DrawBox(400, 880, 800, 945, blue, FALSE);
    SetFontSize(26);
    DrawString(430, 900, "元の画面へ戻る [Esc / H]", white);
    SetFontSize(32);
}
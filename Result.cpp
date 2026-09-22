#include "Result.h"
#include "Game.h"
#include "DxLib.h"

Result::Result(Game* game)
{
    m_game = game;
}

void Result::Init()
{
    maru_win.image = LoadGraph("maru_win.png");
    batu_win.image = LoadGraph("batu_win.png");

    maru_win.x = 0;
    maru_win.y = 250;

    batu_win.x = 0;
    batu_win.y = 250;
}

void Result::Input()
{
    if (CheckHitKey(KEY_INPUT_RETURN)) {
        next_scene = 0;
    }

}

void Result::Update()
{
}

void Result::Draw()
{
    Player winner = m_game->GetWinner();

    DrawFillBox(0, 0, 1200, 1000, GetColor(0,0,0));

    if (winner == PLAYER_MARU)
    {
        DrawGraph(maru_win.x, maru_win.y, maru_win.image, true);
    }
    else
    {
        DrawGraph(batu_win.x, batu_win.y, batu_win.image, true);
    }
}
void Result::Sound_play()
{
}
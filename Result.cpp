#include "Result.h"
#include "Game.h"
#include "DxLib.h"

Result::Result(Game* game)
{
    m_game = game;
}

void Result::Init()
{
}

void Result::Input()
{
}

void Result::Update()
{
}

void Result::Draw()
{
    Player winner = m_game->GetWinner();

    if (winner == PLAYER_MARU)
    {
        DrawString(
            500,
            300,
            "MARU WIN",
            GetColor(255, 255, 255)
        );
    }
    else
    {
        DrawString(
            500,
            300,
            "BATU WIN",
            GetColor(255, 255, 255)
        );
    }
}
void Result::Sound_play()
{
}
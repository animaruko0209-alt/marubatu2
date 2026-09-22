#pragma once

#include "SceneBase.h"

class Game;

class Result : public SceneBase
{
public:
    Result(Game* game);

    void Init() override;
    void Input() override;
    void Update() override;
    void Draw() override;
    void Sound_play() override;

private:
    Game* m_game;

    struct MARU_WIN
    {
        int image;
        float x;
        float y;
    };

    struct BATU_WIN
    {
        int image;
        float x;
        float y;
    };

    MARU_WIN maru_win;
    BATU_WIN batu_win;
};
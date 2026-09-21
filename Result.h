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
};
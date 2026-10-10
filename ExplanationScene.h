#pragma once
#include "SceneBase.h"

class ExplanationScene : public SceneBase
{
private:
    int m_returnScene;
    bool m_prevMouseLeft;
    bool m_prevBackKey;

public:
    ExplanationScene(int returnScene);
    void Init() override;
    void Input() override;
    void Update() override;
    void Draw() override;
    void Sound_play() override {};

    static bool IsHelpButtonHit(int x, int y);
    static void DrawHelpButton();
};
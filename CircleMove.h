#pragma once

#include "SceneBase.h"
#include "Dxlib.h"

class CircleMove : public SceneBase
{
public:

    int circle_image;

    struct Circle_g {
        int image;
        float x;
		float y;
    };

    struct Circle_o {
        int image;
        float x;
        float y;
    };

    Circle_g g_circle;
    Circle_o o_circle;

		CircleMove(){}

    void Init() override;
    void Input() override;
    void Update() override;
    void Draw() override;
	void Sound_play() override;
};
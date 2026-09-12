#pragma once

#include "SceneBase.h"
#include "Dxlib.h"

class CircleMove : public SceneBase
{

private:
    float x;
    float y;

    float speed;

public:
		CircleMove(){}
    void Init() override;
    void Input() override;
    void Update() override;
    void Draw() override;
	void Sound_play() override;
};
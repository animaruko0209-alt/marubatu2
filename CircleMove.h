#pragma once

#include "Dxlib.h"

class CircleMove
{
	public:
 
    void Update();
    void Draw();

private:
    float x;
    float y;

    float speed;
};
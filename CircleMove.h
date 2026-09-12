#pragma once

#include "SceneBase.h"
#include "Dxlib.h"

class CircleMove : public SceneBase
{
public:

    enum CircleState {
        STATE_AVAILABLE,
        STATE_NOT_AVAILABLE
    };

    //enum CircleMoveType {
    //    CROSS,    // ècÅEâ°
    //    DIAGONAL  // éŒÇﬂ
    //};


    int circle_image;

    struct Circle_g {
        int image;
        float x;
		float y;
		//CircleMoveType move_type;
    };

    struct Circle_o {
        int image;
        float x;
        float y;
		//CircleMoveType move_type;
    };


    Circle_g g_circle;
    Circle_o o_circle;


    bool CanMoveCross(int dx, int dy);
	bool CanMoveDiagonal(int dx, int dy);
    void Init() override;
    void Input() override;
    void Update() override;
    void Draw() override;
	void DrawG(int x, int y);
	void DrawO(int x, int y);
	void Sound_play() override;
};
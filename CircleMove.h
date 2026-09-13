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

	struct Batu_g {
		int image;
		float x;
		float y;
	};

	struct Batu_o {
		int image;
		float x;
		float y;
	};


    Circle_g g_circle;
    Circle_o o_circle;
	Batu_g g_batu;
    Batu_o o_batu;


    bool CanMoveCross(int dx, int dy);
	bool CanMoveDiagonal(int dx, int dy);
    void Init() override;
    void Input() override;
    void Update() override;
    void Draw() override;
	void DrawMaruG(int x, int y);
	void DrawMaruO(int x, int y);
    void DrawBatuG(int x, int y);
	void DrawBatuO(int x, int y);
	void Sound_play() override;
};
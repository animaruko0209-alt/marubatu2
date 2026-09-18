#pragma once

#include "SceneBase.h"
#include "Dxlib.h"
#include"Piece.h"

class CircleMove : public SceneBase
{
public:

    enum CircleState {
        STATE_AVAILABLE,
        STATE_NOT_AVAILABLE
    };

    //enum CircleMoveType {
    //    CROSS,    // cE‰¡
    //    DIAGONAL  // Î‚ß
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


    void Init() override;
    void Input() override;
    void Update() override;
    void Draw() override;
	

    // ‹î‚Ìí—Ş‚É‚æ‚Á‚ÄˆÚ“®‚Å‚«‚é•ûŒü‚©”»’è
    bool CanMove(PieceType piece, int dx, int dy);

    // ‹î‚ğ•`‰æ
    void DrawPiece(PieceType piece, int x, int y);

	void Sound_play() override;
};
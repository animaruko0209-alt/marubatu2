#pragma once
#include "SceneBase.h"
#include "CircleMove.h"

class GameScene : public SceneBase
{


	CircleMove circlemove;

public:


#define LINE_NUM	7
#define LINE_WIDTH	110


	enum PieceType
	{
		NONE,
		G_PIECE,	// ècâ°Ç…ìÆÇ≠ãÓ
		O_PIECE		// éŒÇﬂÇ…ìÆÇ≠ãÓ
	};

	PieceType m_cell[6][6];

	struct Line_color {
		int r;
		int g;
		int b;
	};

	struct Line_position {
		int x1;
		int y1;
		int x2;
		int y2;
	};

	struct Line_position2 {
		int x1;
		int y1;
		int x2;
		int y2;
	};


	Line_color m_lineColor;

	Line_position m_linePosition[LINE_NUM];

	Line_position m_linePosition2[LINE_NUM];



	void Init() override;
	void Input() override;
	void Update() override;
	void Draw() override;
	void Sound_play() override;

};
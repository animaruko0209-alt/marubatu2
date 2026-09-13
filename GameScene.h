#pragma once
#include "SceneBase.h"
#include "CircleMove.h"

class GameScene : public SceneBase
{


	CircleMove circlemove;

	bool m_prevMouseLeft;

public:


#define LINE_NUM	7
#define LINE_WIDTH	110


	enum PieceType
	{
		NONE,
		MARU_G,		// ‚Ü‚é‚Ìc‰¡‚É“®‚­‹î
		MARU_O,		// ‚Ü‚é‚ÌÎ‚ß‚É“®‚­‹î
		BATU_G,		// ‚Î‚Â‚Ìc‰¡‚É“®‚­‹î
		BATU_O		// ‚Î‚Â‚ÌÎ‚ß‚É“®‚­‹î
	};

	PieceType m_cell[6][6];
	PieceType m_selectedPiace;

	enum Player {
		PLAYER_MARU,
		PLAYER_BATU
	};

	Player m_currentPlayer;


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
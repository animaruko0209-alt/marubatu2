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
		MARU_G,		// まるの縦横に動く駒
		MARU_O,		// まるの斜めに動く駒
		BATU_G,		// ばつの縦横に動く駒
		BATU_O		// ばつの斜めに動く駒
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

	//　線の色を格納する変数
	Line_color m_lineColor;

	//　線の位置を格納する配列
	Line_position m_linePosition[LINE_NUM];
	Line_position m_linePosition2[LINE_NUM];

	//　マルとバツの駒の数をカウントする変数
	int m_maruCount;
	int m_batuCount;

	//　選択中の駒の座標を格納する変数
	int m_selectedX;
	int m_selectedY;
	//　駒が移動中かどうかを判定する変数
	bool m_pieceMoving;

	void Init() override;
	void Input() override;
	void Update() override;
	void Draw() override;
	void Sound_play() override;

};
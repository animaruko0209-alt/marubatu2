#pragma once

#include "SceneBase.h"
#include "Board.h"
#include "CircleMove.h"

#define LINE_NUM 7
#define LINE_WIDTH 110

enum Player
{
	PLAYER_MARU,
	PLAYER_BATU
};

class GameScene : public SceneBase
{
private:

	int m_lineColor;

	Board m_board;
	CircleMove m_circleMove;

	Player m_currentPlayer;

	PieceType m_selectedPiece;

	bool m_prevMouseLeft;

	int m_maruCount;
	int m_batuCount;

	int m_selectedX;
	int m_selectedY;

	bool m_pieceMoving;

public:

	void Init() override;
	void Input() override;
	void Update() override;
	void Draw() override;
	void Sound_play() override;
};
#pragma once

#include "SceneBase.h"
#include "Board.h"
#include "CircleMove.h"
#include"GameUI.h"

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
	GameUI m_ui;

	bool m_prevMouseLeft;

	int m_maruCount;
	int m_batuCount;

	int m_selectedX;
	int m_selectedY;

	bool m_pieceMoving;

	bool CheckWin(Player player);
	bool m_gameEnd;
	Player m_winner;

	//Ç‹ÇÈÇ∆ÇŒÇ¬ÇÃêFÇé¶Ç∑
	int m_pieceColor[2];

public:

	void Init() override;
	void Input() override;
	void Update() override;
	void Draw() override;
	void Sound_play() override;
};
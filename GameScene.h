#pragma once

#include "SceneBase.h"
#include "Board.h"
#include "CircleMove.h"
#include"GameUI.h"
#include"Player.h"

#define LINE_NUM 7
#define LINE_WIDTH 110

class Game;

class GameScene : public SceneBase
{

public:

	
	GameScene(Game* game);
	void Init() override;
	void Input() override;
	void Update() override;
	void Draw() override;
	void Sound_play() override;

private:

	Game* game_ptr;
	Board m_board;
	CircleMove m_circleMove;
	Player m_currentPlayer;
	PieceType m_selectedPiece;
	GameUI m_ui;
	Player m_winner;
	//　線の色
	int m_lineColor;
	//　マルの置ける数を数える
	int m_maruCount;
	//　バツの置ける数を数える
	int m_batuCount;
	//　X軸の選んでいるマス
	int m_selectedX;
	//　Y軸の選んでいるマス
	int m_selectedY;
	//　時間制限
	int m_turnStartTime;
	//まるとばつの色を示す
	int m_pieceColor[2];
	//　1ターン前にマルが置いた場所を調べる
	int m_maruLastPlaceArea;
	//　1ターン前にバツが置いた場所を調べる
	int m_batuLastPlaceArea;
	//　左クリック
	bool m_prevMouseLeft;
	bool m_pieceMoving;
	bool CheckWin(Player player);
	bool m_gameEnd;
	

	


};
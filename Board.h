#pragma once

#include "Piece.h"

#define BOARD_SIZE 6

class Board
{
private:

	PieceType m_cell[BOARD_SIZE][BOARD_SIZE];

public:

	void Init();

	// 指定マスが空いているか
	bool IsEmpty(int x, int y);

	// 駒を取得
	PieceType GetPiece(int x, int y);

	// 駒を置く
	bool PlacePiece(int x, int y, PieceType piece);

	// 駒を移動する
	bool MovePiece(int fromX, int fromY, int toX, int toY);

	// 実際に移動できる場所を取得
	bool GetMovePosition(
		int fromX,
		int fromY,
		int toX,
		int toY,
		int& resultX,
		int& resultY,
		class CircleMove& circleMove
	);
};
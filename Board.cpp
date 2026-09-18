#include "Board.h"
#include "CircleMove.h"

void Board::Init()
{
	for (int y = 0; y < BOARD_SIZE; y++)
	{
		for (int x = 0; x < BOARD_SIZE; x++)
		{
			m_cell[y][x] = NONE;
		}
	}
}

//--------------------------------------------------
// 空いているか
//--------------------------------------------------
bool Board::IsEmpty(int x, int y)
{
	if (x < 0 || x >= BOARD_SIZE ||
		y < 0 || y >= BOARD_SIZE)
	{
		return false;
	}

	return m_cell[y][x] == NONE;
}

//--------------------------------------------------
// 駒を取得
//--------------------------------------------------
PieceType Board::GetPiece(int x, int y)
{
	if (x < 0 || x >= BOARD_SIZE ||
		y < 0 || y >= BOARD_SIZE)
	{
		return NONE;
	}

	return m_cell[y][x];
}

//--------------------------------------------------
// 駒を置く
//--------------------------------------------------
bool Board::PlacePiece(int x, int y, PieceType piece)
{
	if (x < 0 || x >= BOARD_SIZE ||
		y < 0 || y >= BOARD_SIZE)
	{
		return false;
	}

	if (m_cell[y][x] != NONE)
	{
		return false;
	}

	m_cell[y][x] = piece;

	return true;
}

//--------------------------------------------------
// 駒を移動
//--------------------------------------------------
bool Board::MovePiece(
	int fromX,
	int fromY,
	int toX,
	int toY)
{
	if (fromX < 0 || fromX >= BOARD_SIZE ||
		fromY < 0 || fromY >= BOARD_SIZE)
	{
		return false;
	}

	if (toX < 0 || toX >= BOARD_SIZE ||
		toY < 0 || toY >= BOARD_SIZE)
	{
		return false;
	}

	if (m_cell[fromY][fromX] == NONE)
	{
		return false;
	}

	if (m_cell[toY][toX] != NONE)
	{
		return false;
	}

	m_cell[toY][toX] = m_cell[fromY][fromX];

	m_cell[fromY][fromX] = NONE;

	return true;
}

bool Board::GetMovePosition(
	int fromX,
	int fromY,
	int toX,
	int toY,
	int& resultX,
	int& resultY,
	CircleMove& circleMove)
{
	if (fromX < 0 || fromX >= BOARD_SIZE ||
		fromY < 0 || fromY >= BOARD_SIZE)
	{
		return false;
	}

	PieceType piece = m_cell[fromY][fromX];

	if (piece == NONE)
	{
		return false;
	}

	// 移動方向
	int dx = 0;
	int dy = 0;

	if (toX > fromX)
	{
		dx = 1;
	}
	else if (toX < fromX)
	{
		dx = -1;
	}

	if (toY > fromY)
	{
		dy = 1;
	}
	else if (toY < fromY)
	{
		dy = -1;
	}

	// その駒がその方向に動けるか
	if (!circleMove.CanMove(piece, dx, dy))
	{
		return false;
	}

	// 移動先
	int x = fromX;
	int y = fromY;

	while (true)
	{
		int nextX = x + dx;
		int nextY = y + dy;

		// 盤外
		if (nextX < 0 || nextX >= BOARD_SIZE ||
			nextY < 0 || nextY >= BOARD_SIZE)
		{
			break;
		}

		// 他の駒がある
		if (m_cell[nextY][nextX] != NONE)
		{
			break;
		}

		x = nextX;
		y = nextY;

		// クリックした場所まで来た
		if (x == toX && y == toY)
		{
			break;
		}
	}

	// 移動していない
	if (x == fromX && y == fromY)
	{
		return false;
	}

	resultX = x;
	resultY = y;

	return true;
}
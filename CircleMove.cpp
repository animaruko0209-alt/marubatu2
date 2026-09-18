#include "CircleMove.h"



void CircleMove::Init()
{
    o_circle.image = LoadGraph("o_maru.png");
    g_circle.image = LoadGraph("g_maru.png");
	o_batu.image = LoadGraph("o_batu.png");
	g_batu.image = LoadGraph("g_batu.png");
}

bool CircleMove::CanMove(PieceType piece, int dx, int dy)
{
	// ›G / ~G
	// c‚Ü‚½‚Í‰¡‚ÉˆÚ“®
	if (piece == MARU_G || piece == BATU_G)
	{
		// ‰¡ˆÚ“®
		if (dx != 0 && dy == 0)
		{
			return true;
		}

		// cˆÚ“®
		if (dx == 0 && dy != 0)
		{
			return true;
		}

		return false;
	}

	// ›O / ~O
	// Î‚ß‚ÉˆÚ“®
	if (piece == MARU_O || piece == BATU_O)
	{
		if (dx != 0 && dy != 0)
		{
			return true;
		}

		return false;
	}

	return false;
}

void CircleMove::DrawPiece(PieceType piece, int x, int y)
{
	switch (piece)
	{
	case MARU_G:
		// ›G‚Ì•`‰æ
		DrawGraph(x, y, g_circle.image, true);
		break;

	case MARU_O:
		// ›O‚Ì•`‰æ
		DrawGraph(x, y, o_circle.image, true);
		break;

	case BATU_G:
		DrawGraph(x, y, g_batu.image, true);
		break;

	case BATU_O:
		DrawGraph(x, y, o_batu.image, true);
		break;
	}
}

void CircleMove::Input()
{
    
}

void CircleMove::Update()
{

}


void CircleMove::Draw()
{

}


void CircleMove::Sound_play()
{
}
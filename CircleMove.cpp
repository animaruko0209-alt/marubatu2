#include "CircleMove.h"


bool CircleMove::CanMoveCross(int dx, int dy)
{
		if (dx != 0 && dy != 0)
		{
			return false;
		}
		return true;

}

bool CircleMove::CanMoveDiagonal(int dx, int dy) {
	// o_circle Å® éŒÇﬂ
	if (dx == 0 || dy == 0)
	{
		return false;
	}

	return true;
}


void CircleMove::Init()
{
    o_circle.image = LoadGraph("o_maru.png");
    g_circle.image = LoadGraph("g_maru.png");
	o_batu.image = LoadGraph("o_batu.png");
	g_batu.image = LoadGraph("g_batu.png");
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

void CircleMove::DrawMaruG(int x, int y)
{
	DrawGraph(x, y, g_circle.image, true);
}

void CircleMove::DrawMaruO(int x, int y)
{
	DrawGraph(x, y, o_circle.image, true);
}

void CircleMove::DrawBatuG(int x, int y)
{
	DrawGraph(x, y, g_batu.image, true);
}

void CircleMove::DrawBatuO(int x, int y)
{
	DrawGraph(x, y, o_batu.image, true);
}

void CircleMove::Sound_play()
{
}
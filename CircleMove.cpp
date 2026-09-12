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

  /*  g_circle.x = 175;
    g_circle.y = 175;
    o_circle.x = 395;
    o_circle.y = 175;*/
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

void CircleMove::DrawG(int x, int y)
{
	DrawGraph(x, y, g_circle.image, true);
}

void CircleMove::DrawO(int x, int y)
{
	DrawGraph(x, y, o_circle.image, true);
}

void CircleMove::Sound_play()
{
}
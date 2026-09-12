#include "CircleMove.h"

void CircleMove::Init()
{
	o_circle.image = LoadGraph("o_maru.png");
	g_circle.image = LoadGraph("g_maru.png");

	g_circle.x = 175;
	g_circle.y = 175;
}

void CircleMove::Input()
{
	if(CheckHitKey(KEY_INPUT_RIGHT))
	{
		g_circle.x += 50;
	}

}

void CircleMove::Update()
{
}

void CircleMove::Draw()
{
	DrawGraph(o_circle.x, o_circle.y, o_circle.image, true);
	DrawGraph(g_circle.x, g_circle.y, g_circle.image, true);

}

void CircleMove::Sound_play()
{
}
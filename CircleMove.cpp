#include "CircleMove.h"

void CircleMove::Init()
{
	o_circle.image = LoadGraph("o_maru.png");
	g_circle.image = LoadGraph("g_maru.png");

}

void CircleMove::Input()
{


}

void CircleMove::Update()
{
}

void CircleMove::Draw()
{
	DrawGraph(g_circle.x, g_circle.y, g_circle.image, true);
	DrawGraph(o_circle.x, o_circle.y, o_circle.image, true);

}

void CircleMove::Sound_play()
{
}
#pragma once
#include "SceneBase.h"
#include "CircleMove.h"

class GameScene : public SceneBase
{
#define LINE_NUM	7

	CircleMove circlemove;

	struct Line_color {
		int r;
		int g;
		int b;
	};

	Line_color m_lineColor;

	public:


	GameScene() {}

	void Init() override;
	void Input() override;
	void Update() override;
	void Draw() override;
	void Sound_play() override;

};
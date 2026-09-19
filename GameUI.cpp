#include "GameUI.h"

void GameUI::Init() {
	maru_ui.image = LoadGraph("maru.png");
	maru_ui.x = 75.0f;
	maru_ui.y = 500.0f;
	batu_ui.image = LoadGraph("batu.png");
	batu_ui.x = 1030.0f;
	batu_ui.y = 500.0f;
	move_ui.image = LoadGraph("direction.png");
	move_ui.x = 0;
	move_ui.y = 0;
}

void GameUI::Input() {

}

void GameUI::Update() {

}

void GameUI::Draw() {
	for (int i = 0; i < 2; i++) {
		DrawFillBox(45+i*955, 480, 205+i*955, 830, GetColor(255,255,255));
	}

	DrawGraph(maru_ui.x, maru_ui.y, maru_ui.image, true);
	DrawGraph(batu_ui.x, batu_ui.y, batu_ui.image, true);
	DrawGraph(move_ui.x,move_ui.y, move_ui.image, true);
}
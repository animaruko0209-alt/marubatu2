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
	MaruCount = 0;
	BatuCount = 0;
}

void GameUI::Input() {

}

void GameUI::SetPieceCount(int maruCount, int batuCount) {
	MaruCount = maruCount;
	BatuCount = batuCount;
}


void GameUI::Update() {

}


void GameUI::Draw() {
	for (int i = 0; i < 2; i++) {
		DrawFillBox(45+i*955, 480, 205+i*955, 830, GetColor(255,255,255));
	}

	char maruText[32];
	char batuText[32];

	sprintf_s(maruText, sizeof(maruText),
		"Žc‚è : %d", 5 - MaruCount);

	sprintf_s(batuText, sizeof(batuText),
		"Žc‚è : %d", 5 - BatuCount);

	DrawString(55, 630, maruText, GetColor(0, 0, 0));
	DrawString(1005, 630, batuText, GetColor(0, 0, 0));

	DrawGraph(maru_ui.x, maru_ui.y, maru_ui.image, true);
	DrawGraph(batu_ui.x, batu_ui.y, batu_ui.image, true);
	DrawGraph(move_ui.x,move_ui.y, move_ui.image, true);
}
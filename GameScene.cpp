#include "GameScene.h"
#include "DxLib.h"

void GameScene::Init()
{
	// ‰Šú‰»ˆ—
	m_lineColor = { 255, 255, 255 };
}
void GameScene::Input()
{
	// “ü—Íˆ—
}

void GameScene::Update()
{
	// XVˆ—
}

void GameScene::Draw()
{
	// •`‰æˆ—

	for (int i = 0; i < LINE_NUM; i++)
	{
		int r = m_lineColor.r;
		int g = m_lineColor.g;
		int b = m_lineColor.b;

		// 4‚Â–Ú‚ğÔ‚É‚·‚é
		if (i == 3) {
			r = 255; g = 0; b = 0;
		}

		// ‰¡ü
		DrawLine(170, 170 + i * 110, 830, 170 + i * 110, GetColor(r, g, b), 2);

		
		DrawLine(170 + i * 110, 170, 170 + i * 110, 830, GetColor(r, g, b), 2);
	}

}

void GameScene::Sound_play()
{
	// ‰¹ºÄ¶ˆ—
}

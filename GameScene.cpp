#include "GameScene.h"
#include "DxLib.h"

void GameScene::Init()
{
	// 初期化処理
	m_lineColor = { 255, 255, 255 };
	
	for (int i = 0; i < LINE_NUM; i++)
	{
		m_linePosition[i] = { 170, 170, 830, 170 };
		m_linePosition2[i] = { 170, 170, 170, 830 };
	}

	for (int y = 0; y < LINE_NUM - 1; y++)
	{
		for (int x = 0; x < LINE_NUM - 1; x++)
		{
			m_cell[y][x] = NONE;
		}
	}

	circlemove.Init();

}
void GameScene::Input()
{
	// 入力処理
	circlemove.Input();
}

void GameScene::Update()
{
	// 更新処理
	circlemove.Update();	
	int mouseX;
	int mouseY;

	GetMousePoint(&mouseX, &mouseY);

	// 左クリック
	if (GetMouseInput() & MOUSE_INPUT_LEFT)
	{
		// 格子の中にいるか
		if (mouseX >= 170 && mouseX < 830 &&
			mouseY >= 170 && mouseY < 830)
		{
			// 何列目か
			int cellX = (mouseX - 170) / LINE_WIDTH;

			// 何行目か
			int cellY = (mouseY - 170) / LINE_WIDTH;

			//// そのマスに画像を置く
			m_cell[cellY][cellX] = O_PIECE;
		}
	}
}

void GameScene::Draw()
{
	// 描画処理
	circlemove.Draw();

	for (int i = 0; i < LINE_NUM; i++)
	{
		int r = m_lineColor.r;
		int g = m_lineColor.g;
		int b = m_lineColor.b;

		// 4つ目を赤にする
		if (i == 3) {
			r = 255; g = 0; b = 0;
		}

		// 横線
		DrawLine(m_linePosition[i].x1, m_linePosition[i].y1 + i * LINE_WIDTH ,m_linePosition[i].x2, m_linePosition[i].y2 + i * LINE_WIDTH, GetColor(r, g, b));

		
		DrawLine(m_linePosition2[i].x1 + i * LINE_WIDTH, m_linePosition2[i].y1, m_linePosition2[i].x2 + i * LINE_WIDTH, m_linePosition2[i].y2, GetColor(r, g, b));
	}

	for (int y = 0; y < 6; y++)
	{
		for (int x = 0; x < 6; x++)
		{
			
				int drawX = 170 + x * LINE_WIDTH;
				int drawY = 170 + y * LINE_WIDTH;

				if (m_cell[y][x] == G_PIECE) {
					circlemove.DrawG(drawX, drawY);
				}
				else if (m_cell[y][x] == O_PIECE) {
					circlemove.DrawO(drawX, drawY);
				}
			
		}
	}

}

void GameScene::Sound_play()
{
	// 音声再生処理
}

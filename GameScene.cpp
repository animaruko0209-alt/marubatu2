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

	m_selectedPiace = MARU_G;

	m_currentPlayer = PLAYER_MARU;

	m_prevMouseLeft = false;

	circlemove.Init();

}
void GameScene::Input()
{

	//　駒の種類の変更処理
	if (m_currentPlayer == PLAYER_MARU) {
		if (CheckHitKey(KEY_INPUT_G))
		{
			m_selectedPiace = MARU_G;
		}
		else if (CheckHitKey(KEY_INPUT_O))
		{
			m_selectedPiace = MARU_O;
		}
	}
	else if (m_currentPlayer == PLAYER_BATU) {
		if (CheckHitKey(KEY_INPUT_G))
		{
			m_selectedPiace = BATU_G;
		}
		else if (CheckHitKey(KEY_INPUT_O))
		{
			m_selectedPiace = BATU_O;
		}
	}


	// 入力処理
	circlemove.Input();
}

void GameScene::Update()
{
	// 更新処理
	circlemove.Update();	

	bool mouseLeft = (GetMouseInput() & MOUSE_INPUT_LEFT) != 0;
	int mouseX;
	int mouseY;

	GetMousePoint(&mouseX, &mouseY);

	// 左クリック
	if (mouseLeft && !m_prevMouseLeft )
	{
		// 格子の中にいるか
		if (mouseX >= 170 && mouseX < 830 &&
			mouseY >= 170 && mouseY < 830)
		{
			// 何列目か
			int cellX = (mouseX - 170) / LINE_WIDTH;

			// 何行目か
			int cellY = (mouseY - 170) / LINE_WIDTH;


			if (m_cell[cellY][cellX] == NONE) {
				// そのマスに画像を置く
				m_cell[cellY][cellX] = m_selectedPiace;

				if (m_currentPlayer == PLAYER_MARU)
				{

					m_currentPlayer = PLAYER_BATU;

				}
				else if (m_currentPlayer == PLAYER_BATU)
				{
					m_currentPlayer = PLAYER_MARU;

				}
			}


		}

	}
	m_prevMouseLeft = mouseLeft;

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
			
				int drawX = 175 + x * LINE_WIDTH;
				int drawY = 175 + y * LINE_WIDTH;

				if (m_cell[y][x] == MARU_G) {
					circlemove.DrawMaruG(drawX, drawY);
				}
				else if (m_cell[y][x] == MARU_O) {
					circlemove.DrawMaruO(drawX, drawY);
				}
				else if (m_cell[y][x] == BATU_G) {
					circlemove.DrawBatuG(drawX, drawY);
				}
				else if (m_cell[y][x] == BATU_O) {
					circlemove.DrawBatuO(drawX, drawY);
				}
			
		}
	}

}

void GameScene::Sound_play()
{
	// 音声再生処理
}

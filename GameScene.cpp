#include "GameScene.h"
#include "DxLib.h"
#include"Mouse.h"

void GameScene::Init()
{
	// 初期化処理
	m_lineColor = { 255, 255, 255 };
	
	for (int i = 0; i < LINE_NUM; i++)
	{
		//　線の位置を設定
		m_linePosition[i] = { 170, 170, 830, 170 };
		m_linePosition2[i] = { 170, 170, 170, 830 };
	}

	for (int y = 0; y < LINE_NUM - 1; y++)
	{
		for (int x = 0; x < LINE_NUM - 1; x++)
		{
			//　駒の種類を初期化
			m_cell[y][x] = NONE;
		}
	}
	//　初期選択駒をマルの縦横に動く駒に設定
	m_selectedPiace = MARU_G;
	//　初期プレイヤーをマルに設定
	m_currentPlayer = PLAYER_MARU;
	//　マウスの左クリックの状態を初期化
	m_prevMouseLeft = false;

	//　マルとバツの駒の数を初期化
	m_maruCount = 0;
	m_batuCount = 0;

	m_selectedX = -1;
	m_selectedY = -1;

	m_pieceMoving = false;

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

bool GameScene::CanMove(int destX, int destY)
{
	if (destX < 0 || destX >= 6 ||
		destY < 0 || destY >= 6) {
		return false;
	}


	if (m_cell[destY][destX] != NONE) {
		return false;
	}

	int dx = destX - m_selectedX;
	int dy = destY - m_selectedY;

	int piece = m_cell[m_selectedY][m_selectedX];


	if (piece == MARU_G || piece == BATU_G) {

		if (dx != 0 && dy != 0) {
			return false;
		}

		return true;
	}

	if (piece == MARU_O || piece == BATU_O) {
		if (abs(dx) != abs(dy)) {
			return false;
		}

		if (dx == 0)
		{
			return false;
		}

		return true;
	}

	return false;
}


void GameScene::Update()
{
	// 更新処理
	circlemove.Update();	

	// マウスの左クリックを取得
	bool mouseLeft = (GetMouseInput() & MOUSE_INPUT_LEFT) != 0;
	int mouseX;
	int mouseY;
	// マウスの座標を取得
	GetMousePoint(&mouseX, &mouseY);

	// 左クリック
	// 左クリック
	if (mouseLeft && !m_prevMouseLeft)
	{
		// 格子の中にいるか
		if (mouseX >= 170 && mouseX < 830 &&
			mouseY >= 170 && mouseY < 830)
		{
			// 何列目か
			int cellX = (mouseX - 170) / LINE_WIDTH;

			// 何行目か
			int cellY = (mouseY - 170) / LINE_WIDTH;


			// =================================
			// 駒を選択していない場合
			// =================================
			if (!m_pieceMoving)
			{
				// -----------------------------
				// 空いているなら新しく置く
				// -----------------------------
				if (m_cell[cellY][cellX] == NONE &&
					((m_currentPlayer == PLAYER_MARU && m_maruCount < 5) ||
						(m_currentPlayer == PLAYER_BATU && m_batuCount < 5)))
				{
					// 駒を置く
					m_cell[cellY][cellX] = m_selectedPiace;


					// 駒の数を増やす
					if (m_currentPlayer == PLAYER_MARU)
					{
						m_maruCount++;
					}
					else
					{
						m_batuCount++;
					}


					// プレイヤー交代
					if (m_currentPlayer == PLAYER_MARU)
					{
						m_currentPlayer = PLAYER_BATU;

						if (m_selectedPiace == MARU_G)
						{
							m_selectedPiace = BATU_G;
						}
						else if (m_selectedPiace == MARU_O)
						{
							m_selectedPiace = BATU_O;
						}
					}
					else
					{
						m_currentPlayer = PLAYER_MARU;

						if (m_selectedPiace == BATU_G)
						{
							m_selectedPiace = MARU_G;
						}
						else if (m_selectedPiace == BATU_O)
						{
							m_selectedPiace = MARU_O;
						}
					}
				}


				// -----------------------------
				// 駒があるなら選択する
				// -----------------------------
				else if (m_cell[cellY][cellX] != NONE)
				{
					// マルの駒
					if (m_currentPlayer == PLAYER_MARU &&
						(m_cell[cellY][cellX] == MARU_G ||
							m_cell[cellY][cellX] == MARU_O))
					{
						m_selectedX = cellX;
						m_selectedY = cellY;
						m_pieceMoving = true;
					}

					// バツの駒
					else if (m_currentPlayer == PLAYER_BATU &&
						(m_cell[cellY][cellX] == BATU_G ||
							m_cell[cellY][cellX] == BATU_O))
					{
						m_selectedX = cellX;
						m_selectedY = cellY;
						m_pieceMoving = true;
					}
				}
			}


			// =================================
			// 駒を選択中の場合
			// =================================
			else
			{
				// 移動先が空いているか
				if (CanMove(cellX,cellY))
				{
					// 駒を移動
					m_cell[cellY][cellX] =
						m_cell[m_selectedY][m_selectedX];

					// 元の場所を空にする
					m_cell[m_selectedY][m_selectedX] = NONE;


					// 選択解除
					m_selectedX = -1;
					m_selectedY = -1;
					m_pieceMoving = false;


					// プレイヤー交代
					if (m_currentPlayer == PLAYER_MARU)
					{
						m_currentPlayer = PLAYER_BATU;

						if (m_selectedPiace == MARU_G)
						{
							m_selectedPiace = BATU_G;
						}
						else if (m_selectedPiace == MARU_O)
						{
							m_selectedPiace = BATU_O;
						}
					}
					else
					{
						m_currentPlayer = PLAYER_MARU;

						if (m_selectedPiace == BATU_G)
						{
							m_selectedPiace = MARU_G;
						}
						else if (m_selectedPiace == BATU_O)
						{
							m_selectedPiace = MARU_O;
						}
					}
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

	//　格子状の線を描画する
	for (int i = 0; i < LINE_NUM; i++)
	{
		//　線の色を取得
		int r = m_lineColor.r;
		int g = m_lineColor.g;
		int b = m_lineColor.b;

		// 4つ目を赤にする
		if (i == 3) {
			r = 255; g = 0; b = 0;
		}

		// 横線
		DrawLine(m_linePosition[i].x1, m_linePosition[i].y1 + i * LINE_WIDTH ,m_linePosition[i].x2, m_linePosition[i].y2 + i * LINE_WIDTH, GetColor(r, g, b));

		// 縦線
		DrawLine(m_linePosition2[i].x1 + i * LINE_WIDTH, m_linePosition2[i].y1, m_linePosition2[i].x2 + i * LINE_WIDTH, m_linePosition2[i].y2, GetColor(r, g, b));
	}

	for (int y = 0; y < 6; y++)
	{
		for (int x = 0; x < 6; x++)
		{
			//　駒の描画位置を計算
				int drawX = 175 + x * LINE_WIDTH;
				int drawY = 175 + y * LINE_WIDTH;

				//　駒の種類に応じて描画する
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

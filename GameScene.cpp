#include "GameScene.h"
#include "DxLib.h"

void GameScene::Init()
{
	m_lineColor = GetColor(255, 255, 255);

	// 盤面初期化
	m_board.Init();

	// 駒初期化
	m_circleMove.Init();

	// プレイヤー
	m_currentPlayer = PLAYER_MARU;

	// 最初に選択されている駒
	m_selectedPiece = MARU_G;

	// マウス
	m_prevMouseLeft = false;

	// 駒数
	m_maruCount = 0;
	m_batuCount = 0;

	// 選択位置
	m_selectedX = -1;
	m_selectedY = -1;

	// 移動中か
	m_pieceMoving = false;

	// 勝利状態
	m_gameEnd = false;
	m_winner = PLAYER_MARU;


	m_ui.Init();
}

void GameScene::Input()
{
	// G / Oの選択
	if (m_currentPlayer == PLAYER_MARU)
	{
		if (CheckHitKey(KEY_INPUT_UP))
		{
			m_selectedPiece = MARU_G;
		}

		if (CheckHitKey(KEY_INPUT_DOWN))
		{
			m_selectedPiece = MARU_O;
		}
	}
	else
	{
		if (CheckHitKey(KEY_INPUT_UP))
		{
			m_selectedPiece = BATU_G;
		}

		if (CheckHitKey(KEY_INPUT_DOWN))
		{
			m_selectedPiece = BATU_O;
		}
	}

	m_ui.Input();
}
bool GameScene::CheckWin(Player player)
{
	// 4つの3×3エリアを調べる
	for (int areaY = 0; areaY < 6; areaY += 3)
	{
		for (int areaX = 0; areaX < 6; areaX += 3)
		{
			// 横3つ
			for (int y = 0; y < 3; y++)
			{
				bool win = true;

				for (int x = 0; x < 3; x++)
				{
					PieceType piece =
						m_board.GetPiece(areaX + x, areaY + y);

					if (player == PLAYER_MARU)
					{
						if (piece != MARU_G &&
							piece != MARU_O)
						{
							win = false;
						}
					}
					else
					{
						if (piece != BATU_G &&
							piece != BATU_O)
						{
							win = false;
						}
					}
				}

				if (win)
				{
					return true;
				}
			}

			// 縦3つ
			for (int x = 0; x < 3; x++)
			{
				bool win = true;

				for (int y = 0; y < 3; y++)
				{
					PieceType piece =
						m_board.GetPiece(areaX + x, areaY + y);

					if (player == PLAYER_MARU)
					{
						if (piece != MARU_G &&
							piece != MARU_O)
						{
							win = false;
						}
					}
					else
					{
						if (piece != BATU_G &&
							piece != BATU_O)
						{
							win = false;
						}
					}
				}

				if (win)
				{
					return true;
				}
			}

			// 左上 → 右下
			bool win = true;

			for (int i = 0; i < 3; i++)
			{
				PieceType piece =
					m_board.GetPiece(areaX + i, areaY + i);

				if (player == PLAYER_MARU)
				{
					if (piece != MARU_G &&
						piece != MARU_O)
					{
						win = false;
					}
				}
				else
				{
					if (piece != BATU_G &&
						piece != BATU_O)
					{
						win = false;
					}
				}
			}

			if (win)
			{
				return true;
			}

			// 右上 → 左下
			win = true;

			for (int i = 0; i < 3; i++)
			{
				PieceType piece =
					m_board.GetPiece(areaX + (2 - i), areaY + i);

				if (player == PLAYER_MARU)
				{
					if (piece != MARU_G &&
						piece != MARU_O)
					{
						win = false;
					}
				}
				else
				{
					if (piece != BATU_G &&
						piece != BATU_O)
					{
						win = false;
					}
				}
			}

			if (win)
			{
				return true;
			}

		}
	}

	return false;
}

void GameScene::Update()
{
	if (m_gameEnd)
	{
		return;
	}


	m_ui.Update();

	int mouseX;
	int mouseY;

	GetMousePoint(&mouseX, &mouseY);

	bool mouseLeft =
		(GetMouseInput() & MOUSE_INPUT_LEFT) != 0;

	// クリックした瞬間だけ処理
	bool click =
		mouseLeft && !m_prevMouseLeft;

	//--------------------------------------------------
	// クリックされていない
	//--------------------------------------------------
	if (click)
	{
		// 170～830の範囲
		if (mouseX >= 270 && mouseX < 930 &&
			mouseY >= 170 && mouseY < 830)
		{
			int cellX = (mouseX - 270) / LINE_WIDTH;
			int cellY = (mouseY - 170) / LINE_WIDTH;

			//--------------------------------------------------
			// 駒を移動中ではない
			//--------------------------------------------------
			if (!m_pieceMoving)
			{
				PieceType clickedPiece =
					m_board.GetPiece(cellX, cellY);

				//--------------------------------------------------
				// 空いている → 駒を置く
				//--------------------------------------------------
				if (clickedPiece == NONE)
				{
					bool canPlace = false;

					if (m_currentPlayer == PLAYER_MARU)
					{
						if (m_maruCount < 7)
						{
							canPlace = true;
						}
					}
					else
					{
						if (m_batuCount < 7)
						{
							canPlace = true;
						}
					}

					if (canPlace)
					{
						if (m_board.PlacePiece(
							cellX,
							cellY,
							m_selectedPiece))
						{
							// 駒を置いたので勝利判定
							if (CheckWin(m_currentPlayer))
							{
								m_gameEnd = true;
								m_winner = m_currentPlayer;
								return;
							}

							if (m_currentPlayer == PLAYER_MARU)
							{
								m_maruCount++;
								m_currentPlayer =PLAYER_BATU;

								// 次のプレイヤー用に×へ
								if (m_selectedPiece == MARU_G)
								{
									m_selectedPiece = BATU_G;
								}
								else
								{
									m_selectedPiece = BATU_O;
								}
							}
							else
							{
								m_batuCount++;
								m_currentPlayer =PLAYER_MARU;

								// 次のプレイヤー用に○へ
								if (m_selectedPiece == BATU_G)
								{
									m_selectedPiece = MARU_G;
								}
								else
								{
									m_selectedPiece = MARU_O;
								}
							}
						}
					}
				}

				//--------------------------------------------------
				// 自分の駒をクリック → 移動開始
				//--------------------------------------------------
				else
				{
					bool isOwnPiece = false;

					if (m_currentPlayer == PLAYER_MARU)
					{
						if (clickedPiece == MARU_G ||
							clickedPiece == MARU_O)
						{
							isOwnPiece = true;
						}
					}
					else
					{
						if (clickedPiece == BATU_G ||
							clickedPiece == BATU_O)
						{
							isOwnPiece = true;
						}
					}

					if (isOwnPiece)
					{
						m_selectedX = cellX;
						m_selectedY = cellY;

						m_pieceMoving = true;
					}
				}
			}

			//--------------------------------------------------
			// 駒を移動中
			//--------------------------------------------------
			else
			{
				PieceType clickedPiece =
				m_board.GetPiece(cellX, cellY);

				bool isOwnPiece = false;

				// クリックしたのが自分の駒か確認
				if (m_currentPlayer == PLAYER_MARU)
				{
					if (clickedPiece == MARU_G ||
						clickedPiece == MARU_O)
					{
						isOwnPiece = true;
					}
				}
				else
				{
					if (clickedPiece == BATU_G ||
						clickedPiece == BATU_O)
					{
						isOwnPiece = true;
					}
				}

				//--------------------------------------------------
				// 自分の別の駒をクリック
				// → 選択する駒を変更
				//--------------------------------------------------
				if (isOwnPiece)
				{
					m_selectedX = cellX;
					m_selectedY = cellY;

					// 移動中のまま
					m_pieceMoving = true;
				}

				//--------------------------------------------------
				// 自分の駒ではない
				// → 移動先として処理
				//--------------------------------------------------
				else
				{
					int resultX;
					int resultY;

					if (m_board.GetMovePosition(
						m_selectedX,
						m_selectedY,
						cellX,
						cellY,
						resultX,
						resultY,
						m_circleMove))
					{
						if (m_board.MovePiece(
							m_selectedX,
							m_selectedY,
							resultX,
							resultY))
						{
							m_selectedX = -1;
							m_selectedY = -1;

							m_pieceMoving = false;

							// 移動した後に勝利判定
							if (CheckWin(m_currentPlayer))
							{
								m_gameEnd = true;
								m_winner = m_currentPlayer;
								return;
							}



							// ターン変更
							if (m_currentPlayer == PLAYER_MARU)
							{
								m_currentPlayer = PLAYER_BATU;
								m_selectedPiece = BATU_G;
							}
							else
							{
								m_currentPlayer = PLAYER_MARU;
								m_selectedPiece = MARU_G;
							}
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

	m_ui.Draw();

	//--------------------------------------------------
	// 6×6の盤面を描画
	//--------------------------------------------------

	for (int i = 0; i < LINE_NUM; i++)
	{
		int lineColor = m_lineColor;

		// 真ん中の線だけ赤色
		if (i == 3)
		{
			lineColor = GetColor(255, 0, 0);
		}

		// 横線
		DrawLine(
			270,
			170 + i * LINE_WIDTH,
			930,
			170 + i * LINE_WIDTH,
			lineColor,
			3);

		// 縦線
		DrawLine(
			270 + i * LINE_WIDTH,
			170,
			270 + i * LINE_WIDTH,
			830,
			lineColor,
			3);
	}

	//--------------------------------------------------
	// 駒を描画
	//--------------------------------------------------

	for (int y = 0; y < BOARD_SIZE; y++)
	{
		for (int x = 0; x < BOARD_SIZE; x++)
		{
			PieceType piece =
				m_board.GetPiece(x, y);

			if (piece != NONE)
			{
				int drawX =
					220 + x * LINE_WIDTH + LINE_WIDTH/ 2;

				int drawY =
					120 + y * LINE_WIDTH + LINE_WIDTH / 2;

				m_circleMove.DrawPiece(
					piece,
					drawX,
					drawY);
			}
		}
	}

	if (m_gameEnd) {
		if (m_winner == PLAYER_MARU) {
			DrawString(
				500,
				50,
				"〇勝ち",
				GetColor(255, 255, 255));
		}
		else {
			DrawString(
				500,
				50,
				"×勝ち",
				GetColor(255, 255, 255));
		}

	}

}

void GameScene::Sound_play()
{
}
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

void GameScene::Update()
{

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

						// ターン変更
						if (m_currentPlayer == PLAYER_MARU)
						{
							m_currentPlayer =PLAYER_BATU;

							m_selectedPiece = BATU_G;
						}
						else
						{
							m_currentPlayer =PLAYER_MARU;

							m_selectedPiece = MARU_G;
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
}

void GameScene::Sound_play()
{
}
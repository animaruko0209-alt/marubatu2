#pragma once
#include "GameScene.h"
#include "SceneBase.h"
#include"Player.h"
#include <memory>
#include"Dxlib.h"

class Game
{
	int scene_no = 0;

	int NowMouseX = 0;
	int NowMouseY = 0;
	//std::shared_ptr<SceneBase> current_scene_ptr = nullptr;

	//GameScene* current_scene_ptr = nullptr;
	SceneBase* current_scene_ptr = nullptr;

	Player m_winner = PLAYER_MARU;

	
public:
	void SetWinner(Player winner)
	{
		m_winner = winner;
	}

	Player GetWinner() const
	{
		return m_winner;
	}

	Game() {}

	void Game_loop();

};
#pragma once
#include "GameScene.h"
#include "SceneBase.h"
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
public:

	Game() {}

	void Game_loop();

};
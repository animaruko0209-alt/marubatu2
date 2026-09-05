#pragma once

#include <memory>
#include"Dxlib.h"

class Game
{
	int scene_no = 0;

	std::shared_ptr<SceneBase> current_scene_ptr = nullptr;



public:

	Game() {}

	void Game_loop();

};
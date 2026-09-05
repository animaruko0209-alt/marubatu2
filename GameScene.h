#pragma once
#include "SceneBase.h"

class GameScene : public SceneBase
{
public:
	GameScene() {}

	void Init() override;
	void Input() override;
	void Update() override;
	void Draw() override;
	void Sound_play() override;
};
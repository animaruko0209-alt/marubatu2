#pragma once
#include "SceneBase.h"
#include "Game.h"			// ゲームクラス



/// <summary>
/// オープニング（シーン）
/// </summary>
class SceneOp : public SceneBase
{
	/// <summary>
	/// Gameインスタンスのポインター
	/// </summary>
	Game* game_ptr;
	bool m_prevMouseLeft;
	bool m_prevHelpKey;



public:
	/// <summary>
	/// コンストラクター
	/// </summary>
	/// <param name="arg_game_ptr">Gameインスタンスのポインター</param>
	SceneOp(Game* arg_game_ptr)
	{
		// Gameインスタンスのポインターを保持
		this->game_ptr = arg_game_ptr;
	}

	/// <summary>
	/// 初期化処理
	/// </summary>
	void Init() override;
	void Resume(int pauseTime) override;

	/// <summary>
	/// 入力処理
	/// </summary>
	void Input() override;

	/// <summary>
	/// 更新処理
	/// </summary>
	void Update() override;

	/// <summary>
	/// 描画処理
	/// </summary>
	void Draw() override;

	/// <summary>
	/// 音声再生処理
	/// </summary>
	void Sound_play() override {};

};



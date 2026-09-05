#pragma once

class SceneBase {
protected:

	int next_scene = -1;   // -1 = シーンはまだ続く

public:

	/// <summary>
	/// 初期化処理
	/// </summary>
	virtual void Init() = 0;

	/// <summary>
	/// 入力処理
	/// </summary>
	virtual void Input() = 0;

	/// <summary>
	/// 更新処理
	/// </summary>
	virtual void Update() = 0;

	/// <summary>
	/// 描画処理
	/// </summary>
	virtual void Draw() = 0;

	/// <summary>
	/// 音声再生処理
	/// </summary>
	virtual void Sound_play() = 0;

	int GetNextScene() const { return next_scene; }
};


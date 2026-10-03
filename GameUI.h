#pragma once
#include"DxLib.h"

class GameUI
{


public:

	struct MARU_UI {
		int image;
		float x;
		float y;
	};

	struct BATU_UI {
		int image;
		float x;
		float y;
	};

	struct MOVE_UI {
		int image;
		float x;
		float y;
	};

	//ëÄçÏ
	struct OPERATION_UI
	{
		int image;
		float x;
		float y;
	};


	MARU_UI maru_ui;
	BATU_UI batu_ui;
	MOVE_UI move_ui;
	int MaruCount;
	int BatuCount;

	//ëÄçÏ
	OPERATION_UI mouse_ui;
	OPERATION_UI ud_ui;

	
	void Init();
	void Input();
	void SetPieceCount(int maruCount, int batuCount);
	void Update();
	void Draw();

};


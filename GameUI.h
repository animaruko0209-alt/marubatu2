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

	//操作
	struct OPERATION_UI
	{
		int image;
		float x;
		float y;
	};

	//選択内訳表示(色別)
	struct SELECT_UI
	{
		int image;
		float x;
		float y;
		//いくつ選択した
		int m_num;
		int b_num;
	};

	MARU_UI maru_ui;
	BATU_UI batu_ui;
	MOVE_UI move_ui;
	int MaruCount;
	int BatuCount;

	//操作
	OPERATION_UI mouse_ui;
	OPERATION_UI ud_ui;

	//移動方向ごとの選択数
	SELECT_UI g_ui;
	SELECT_UI o_ui;

	void Init();
	void Input();
	void SetPieceCount(int maruCount, int batuCount);
	void Update();
	void Draw();

	//選択数を数える(g1,o2,m1,b2)
	void GOSelectCount(int go, int mb);

};


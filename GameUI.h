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
	//選択方向表示（Rect用）
	//１つだけ
	int sd_image;
	int sd_now;
	struct SELECT_DIR_UI
	{
		int start_x;
		int start_y;
		int size;
		int now;
		int frame;
		//動きが終わったか
		bool move_end;
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

	//選択方向表示の部分別情報
	SELECT_DIR_UI sd_ui[3];

	void Init();
	void Input();
	void SetPieceCount(int maruCount, int batuCount);
	void Update();
	void Draw();

	//選択数を数える(g1,o2,m1,b2)
	void GOSelectCount(int go, int mb);
	//選択方向をアニメーション（n0,g1,o2,動作の向きを逆にするか）
	void MoveSelectDir(int go, bool mov_rev);
	//選択方向の固定セット
	void MoveSelectDir(int go, int a3);
	//動作状況
	bool JudgeSD();

};


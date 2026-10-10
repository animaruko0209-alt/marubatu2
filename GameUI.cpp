#include "GameUI.h"

void GameUI::Init() {
	maru_ui.image = LoadGraph("maru.png");
	maru_ui.x = 75.0f;
	maru_ui.y = 500.0f;
	batu_ui.image = LoadGraph("batu.png");
	batu_ui.x = 1030.0f;
	batu_ui.y = 500.0f;
	move_ui.image = LoadGraph("direction.png");
	move_ui.x = 0;
	move_ui.y = 0;
	MaruCount = 0;
	BatuCount = 0;

	//操作表示
	mouse_ui.image = LoadGraph("mouse.png");
	mouse_ui.x = 0.0f;
	mouse_ui.y = 200.0f;
	ud_ui.image = LoadGraph("updown.png");
	ud_ui.x = 100.0f;
	ud_ui.y = 200.0f;

	//選択数表示
	g_ui.image = LoadGraph("dir(1).png");
	g_ui.x = 100.0f;
	g_ui.y = 800.0f;
	g_ui.m_num = 0;
	g_ui.b_num = 0;
	o_ui.image = LoadGraph("dir(2).png");
	o_ui.x = 100.0f;
	o_ui.y = 850.0f;
	o_ui.m_num = 0;
	o_ui.b_num = 0;

	//選択方向表示（Rect用）
	//※画像の名前は元の駒数のなごり
	sd_image = LoadGraph("seven_icon3x3.png");
	sd_now = 0;
	for (int sd = 0; sd < 3; sd++)
	{
		sd_ui[sd].size = 100;
		sd_ui[sd].start_x = sd_ui[sd].size * sd;
		sd_ui[sd].start_y = 0;
		sd_ui[sd].now = 0;
		sd_ui[sd].frame = 0;
		sd_ui[sd].move_end = true;
	}

	//タイトルのフォントサイズ変更が残っているのでそろえる
	SetFontSize(32);
}

void GameUI::Input() {

}

void GameUI::SetPieceCount(int maruCount, int batuCount) {
	MaruCount = maruCount;
	BatuCount = batuCount;
}

void GameUI::GOSelectCount(int go, int mb)
{
	//g
	if (go == 1)
	{
		//m
		if (mb == 1)
		{
			g_ui.m_num++;
		}
		//b
		else if (mb == 2)
		{
			g_ui.b_num++;
		}
	}
	//o
	if (go == 2)
	{
		//m
		if (mb == 1)
		{
			o_ui.m_num++;
		}
		//b
		else if (mb == 2)
		{
			o_ui.b_num++;
		}
	}
}

void GameUI::Update() {
	//選択方向画像の内部座標更新
	for (int sd = 0; sd < 3; sd++)
	{
		sd_ui[sd].start_y = sd_ui[sd].size * sd_ui[sd].now;
	}
}


void GameUI::Draw() {
	for (int i = 0; i < 2; i++) {
		DrawFillBox(45+i*955, 480, 205+i*955, 830, GetColor(255,255,255));
	}

	//　移動変更のUI描画（変更してもらって大丈夫です）
	/*DrawFillBox(0, 0, 200,300, GetColor(255, 255, 255));
	DrawString(10, 200, "上下キーで", GetColor(0, 0, 0));
	DrawString(10, 250, "移動を変更", GetColor(0, 0, 0));*/

	DrawFillBox(0, 0, 200, 350, GetColor(255, 255, 255));
	DrawString(mouse_ui.x + 10.0f, mouse_ui.y + 100.0f, "Put/Select", GetColor(0, 0, 0));

	char maruText[32];
	char batuText[32]; 

	sprintf_s(maruText, sizeof(maruText),
		"残り : %d", 5 - MaruCount);

	sprintf_s(batuText, sizeof(batuText),
		"残り : %d", 5 - BatuCount);

	DrawString(55, 630, maruText, GetColor(0, 0, 0));
	DrawString(1005, 630, batuText, GetColor(0, 0, 0));

	DrawGraph(maru_ui.x, maru_ui.y, maru_ui.image, true);
	DrawGraph(batu_ui.x, batu_ui.y, batu_ui.image, true);
	DrawGraph(move_ui.x,move_ui.y, move_ui.image, true);

	//移動変更、設置操作表示
	DrawGraph(mouse_ui.x, mouse_ui.y, mouse_ui.image, true);
	DrawGraph(ud_ui.x, ud_ui.y, ud_ui.image, true);

	//サイズ
	const float MINI_DIR = 200.0f * 0.3f;
	const int FONT_HALF = 32 / 2;
	DrawRotaGraph(55+(int)MINI_DIR/2, 700+ FONT_HALF, 0.3, 0.0, g_ui.image, true);
	DrawRotaGraph(55+(int)MINI_DIR/2, 770+ FONT_HALF, 0.3, 0.0, o_ui.image, true);
	DrawRotaGraph(1005+(int)MINI_DIR/2, 700+ FONT_HALF, 0.3, 0.0, g_ui.image, true);
	DrawRotaGraph(1005+(int)MINI_DIR/2, 770+ FONT_HALF, 0.3, 0.0, o_ui.image, true);
	//色
	const int MB_GREEN = GetColor(50, 200, 70);
	const int MB_ORANGE = GetColor(255, 150, 0);
	DrawFormatString(55, 700, MB_GREEN, "　　   %d", g_ui.m_num);
	DrawFormatString(55, 770, MB_ORANGE, "　　   %d", o_ui.m_num);

	DrawFormatString(1005, 700, MB_GREEN, "　　   %d", g_ui.b_num);
	DrawFormatString(1005, 770, MB_ORANGE, "　　   %d", o_ui.b_num);

	//
	DrawRectRotaGraph(20, 900, sd_ui[sd_now].start_x, sd_ui[sd_now].start_y, sd_ui[sd_now].size, sd_ui[sd_now].size, 0.5, 0.0, sd_image, true);

	////test
	//DrawFormatString(20, 900, GetColor(255, 255, 0),
	//	"test\nmaru:G %d,O %d\nbatu:G %d,O %d", g_ui.m_num, o_ui.m_num, g_ui.b_num, o_ui.b_num);
	
}

//選択方向をアニメーション（g1,o2,動作の向きを逆にするか）
void GameUI::MoveSelectDir(int go, bool mov_rev)
{
	const int frame_max = 10;
	if (go >= 0 && go < 3)
	{
		//セット
		sd_now = go;
		//反対の挙動
		if (mov_rev)
		{
			//動かすタイミングのカウント
			sd_ui[go].frame++;
			if (sd_ui[go].frame >= frame_max)
			{
				sd_ui[go].frame = 0;
				//減る
				sd_ui[go].now--;
				if (sd_ui[go].now <= 0)
				{
					//停止
					sd_ui[go].now = 0;
					sd_ui[go].move_end = true;
				}
			}
			else
			{
				sd_ui[go].move_end = false;
			}
		}
		//通常
		else
		{
			//動かすタイミングのカウント
			sd_ui[go].frame++;
			if (sd_ui[go].frame >= frame_max)
			{
				sd_ui[go].frame = 0;
				//増える
				sd_ui[go].now++;
				if (sd_ui[go].now >= 3 - 1)
				{
					//停止
					sd_ui[go].now = 3 - 1;
					sd_ui[go].move_end = true;
				}
				else
				{
					sd_ui[go].move_end = false;
				}
			}
		}
	}
}
void GameUI::MoveSelectDir(int go, int a3)
{
	if (go >= 0 && go < 3)
	{
		sd_now = go;
		sd_ui[go].now = a3;
	}
}

//動作状況
bool GameUI::JudgeSD()
{
	return sd_ui[sd_now].move_end;
}
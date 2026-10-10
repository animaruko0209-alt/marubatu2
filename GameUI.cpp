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

	//色
	const int MB_GREEN = GetColor(50, 200, 70);
	const int MB_ORANGE = GetColor(255, 150, 0);
	DrawFormatString(55, 700, MB_GREEN, "　　   %d", g_ui.m_num);
	DrawFormatString(55, 770, MB_ORANGE, "　　   %d", o_ui.m_num);

	DrawFormatString(1005, 700, MB_GREEN, "　　   %d", g_ui.b_num);
	DrawFormatString(1005, 770, MB_ORANGE, "　　   %d", o_ui.b_num);

	////test
	//DrawFormatString(20, 900, GetColor(255, 255, 0),
	//	"test\nmaru:G %d,O %d\nbatu:G %d,O %d", g_ui.m_num, o_ui.m_num, g_ui.b_num, o_ui.b_num);
	
}
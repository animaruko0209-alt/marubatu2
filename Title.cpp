#include "Title.h"
#include "Game.h"
#include "SceneBase.h"
#include "DxLib.h"


void SceneOp::Init()
{
	
	next_scene = -1;
}

/// <summary>
/// “ü—Íˆ—
/// </summary>
void SceneOp::Input()
{
	
}

/// <summary>
/// XVˆ—
/// </summary>
void SceneOp::Update()
{
	
	
	
	if (CheckHitKey(KEY_INPUT_SPACE)) {
		
		next_scene = 1;
		//ƒQ[ƒ€–{•Ò‚Ö
	}
	

	
	
}

/// <summary>
/// •`‰æˆ—
/// </summary>
void SceneOp::Draw()
{
	

	SetFontSize(102);
	DrawString(352, 92, "›~ƒQ[ƒ€", GetColor(220, 220, 220));
	DrawString(350, 90, "›~ƒQ[ƒ€", GetColor(0, 0, 255));

	SetFontSize(32);
	DrawString(472, 602, "Press  SPACE Key!!", GetColor(220, 220, 220));
	DrawString(470, 600, "Press  SPACE Key!!", GetColor(255, 0, 0));

}

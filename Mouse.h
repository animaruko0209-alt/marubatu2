#pragma once
#include"DxLib.h"

bool m_prevMouseLeft;


bool IsMouseAuto()
{
	bool mouseLeft = (GetMouseInput() & MOUSE_INPUT_LEFT) != 0;
	bool clicked=false;
	if (mouseLeft && !m_prevMouseLeft) {
		return clicked;

	}

	
}
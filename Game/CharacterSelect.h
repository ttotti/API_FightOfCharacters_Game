#pragma once

#include <Windows.h>

#include "Bitmap.h"

class CharacterSelect
{
public:
	int M_x, M_y;

	HWND hWnd;

	Bitmap BG_bitmap;

public:
	CharacterSelect();
	~CharacterSelect();

	void init(HINSTANCE g_hInst, HWND hWnd);

	void DrawBitmap();
	void MousePoint(int x, int y);
};
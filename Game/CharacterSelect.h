#pragma once

#include <Windows.h>

#include "Bitmap.h"

class CharacterSelect
{
public:
	int M_x, M_y;

	gBitmap BG_bitmap;
	gBitmap Home_bitmap;
	gBitmap ClickHome_bitmap;

	gBitmap chirnoface;

public:
	CharacterSelect();
	CharacterSelect(HINSTANCE g_hInst, HWND hWnd);
	~CharacterSelect();

	void init(HINSTANCE g_hInst, HWND hWnd);

	void DrawBitmap();
	void MousePoint(int x, int y);
};
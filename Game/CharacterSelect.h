#pragma once

#include <Windows.h>

#include "Bitmap.h"

#include "GdiDraw.h"

class CharacterSelect
{
public:
	int M_x, M_y;

	gBitmap BG_bitmap;
	gBitmap Home_bitmap;
	gBitmap ClickHome_bitmap;

	GDIplus chirnoface;

public:
	CharacterSelect();
	CharacterSelect(HINSTANCE g_hInst, HWND hWnd);
	~CharacterSelect();

	void init(HINSTANCE g_hInst, HWND hWnd);

	void DrawBitmap();
	void MousePoint(int x, int y);
};
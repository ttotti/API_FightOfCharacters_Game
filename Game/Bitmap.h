#pragma once

#include <Windows.h>
#include <stdio.h>

#include "resource.h"

//</gdiplus.h>

#define WIN_WIGHT 1250
#define WIN_HEIGHT 795

class gBitmap
{
public:
	int bmWidth, bmHeight;

	HWND hWnd;
	HDC hdc, MemDC, BackDC;

	BITMAP bit;

	HBITMAP map;
	HBITMAP Backmap;
	HBITMAP hPreBit;

public:
	gBitmap();
	~gBitmap();

	void SetBitmap(HWND hWnd, HINSTANCE hInstance, int IpBitmapName);


	void DrawBitmap(int x, int y);
	void Double_DrawBitmap(int x, int y);

	void DrawBitmap(int x, int y, int w, int h);
	void Double_DrawBitmap(int x, int y, int w, int h);

	void DrawTransparentBlt(int x, int y, int r, int g, int b);
	void Double_DrawTransparentBlt(int x, int y, int r, int g, int b);

	int GetWight();
	int GetHeight();
};
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
	HWND hWnd;
	HDC hdc;

	BITMAP bit;

	HBITMAP map;

public:
	gBitmap();
	~gBitmap();

	void SetBitmap(HWND hWnd, HINSTANCE hInstance, int IpBitmapName);

	void DramBitmap(int x, int y);
	void DramBitmap(int x, int y, int w, int h);

	void DramBitmap(HDC hdc, int x, int y);
	void DramBitmap(HDC hdc, int x, int y, int w, int h);

	void Double_DramBitmap(HDC hdc, int x, int y);
	void Double_DramBitmap(HDC hdc, int x, int y, int w, int h);

	int GetWight();
	int GetHeight();
};
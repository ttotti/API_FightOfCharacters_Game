#pragma once

#include <Windows.h>
#include <stdio.h>

#define WIN_WIGHT 1250
#define WIN_HEIGHT 795

class Bitmap
{
public:
	HBITMAP map;

public:
	Bitmap();
	//Bitmap(HINSTANCE hInstance, LPCWSTR IpBitmapName);
	~Bitmap();

	void SetBitmap(HINSTANCE hInstance, int IpBitmapName);
	void DramBitmap(HDC hdc, int x, int y);
	void DramBitmap(HDC hdc, int x, int y, int w, int h);
	void Double_DramBitmap(HDC hdc, int x, int y);
	void Double_DramBitmap(HDC hdc, int x, int y, int w, int h);
};
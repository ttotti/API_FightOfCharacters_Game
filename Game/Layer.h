#pragma once

#include <Windows.h>
#include "Bitmap.h"

class Layer
{
private:
	HDC hdc, MemDC, BackDC;
	HWND hWnd;

	HBITMAP Image;
	HBITMAP BackImage;
	HBITMAP hPreBit;

public:
	Layer();
	Layer(HWND hWnd);
	~Layer();

	void Init();
	void DeleteImage();

	void Draw();

	void Draw_BitBlt(gBitmap* bitmap);
	void Draw_StretchBit(gBitmap* bitmap);
	void Draw_TransparentBlt(gBitmap* bitmap, int r, int g, int b);

	virtual void DrawBitmap() = 0;
};
#pragma once

#include <Windows.h>
#include "Bitmap.h"
#include "PNG_Image.h"

class Layer
{
private:
	HDC hdc, MemDC, BackDC;
	HWND hWnd;
	HINSTANCE g_hInst;

	HBITMAP b_Image;
	HBITMAP b_BackImage;
	HBITMAP b_hPreBit;

public:
	Layer();
	Layer(HINSTANCE g_hInst, HWND hWnd);
	~Layer();

	void Init();
	void DeleteImage();

	void Draw();

	void Draw_BitBlt(gBitmap* bitmap);
	void Draw_StretchBit(gBitmap* bitmap);
	void Draw_TransparentBlt(gBitmap* bitmap, int r, int g, int b);

	void Draw_PNGImage(PNG_Image* image);

	HWND Get_hWnd();
	HINSTANCE Get_g_hInst();
};
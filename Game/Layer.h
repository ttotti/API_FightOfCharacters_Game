#pragma once

#include <Windows.h>
#include "Bitmap.h"
#include "PNG_Image.h"

class Layer
{
private:
	HDC hdc, MemDC, BackDC;
	HWND hWnd;

	HBITMAP b_Image;
	HBITMAP b_BackImage;
	HBITMAP b_hPreBit;

	Image* p_Image;

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

	void Draw_PNGImage(PNG_Image* image);
};
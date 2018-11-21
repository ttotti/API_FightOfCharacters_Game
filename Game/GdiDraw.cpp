#include "GdiDraw.h"

GDIplus::GDIplus()
{
	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);
}

GDIplus::GDIplus(HWND hWnd)
{
	this->hWnd = hWnd;
}

GDIplus::~GDIplus()
{
	delete image;
	GdiplusShutdown(gdiplusToken);
	printf("GDIplus ÇØÁ¦!\n");
}

void GDIplus::setImage(HWND hWnd, const WCHAR* Filename)
{
	this->hWnd = hWnd;
	image = Image::FromFile(Filename);
}

void GDIplus::DrawImage(int x, int y, const WCHAR* Filename)
{
	HDC hdc = GetDC(hWnd);

	HDC MenDC, BackDC;

	HBITMAP hBitmap;

	BackDC = CreateCompatibleDC(hdc);
	hBitmap = (HBITMAP)SelectObject(BackDC, image);

	Graphics g(hdc);
	
	image = Image::FromFile(Filename);

	g.DrawImage(image, x, y);

	BitBlt(hdc, 0, 0, x, y, BackDC, 0, 0, SRCCOPY);

	SelectObject(BackDC, hBitmap);
	ReleaseDC(hWnd, hdc);
}



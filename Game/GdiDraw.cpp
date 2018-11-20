#include "GdiDraw.h"

GDIplus::GDIplus()
{
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

void GDIplus::DrawImage(int x, int y)
{
	HDC hdc = GetDC(hWnd);

	Graphics g(hdc);
	
	g.DrawImage(image, x, y);

	ReleaseDC(hWnd, hdc);
}



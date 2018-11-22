#include "Bitmap.h"

gBitmap::gBitmap()
{
	hWnd = NULL;
	hdc = NULL;
	map = NULL;

	//GdiplusStartup(&m_GdiplusToken, &m_GdiplusStartupInput, NULL);
}

gBitmap::~gBitmap()
{
	DeleteObject(BackDC);
	DeleteObject(Backmap);
	DeleteDC(MemDC);

	DeleteObject(map);

	ReleaseDC(hWnd, hdc);

	printf("Bitmap 클래스 소멸!\n");
	//system("pause");
}

void gBitmap::SetBitmap(HWND hWnd, HINSTANCE hInstance, int IpBitmapName)
{
	this->hWnd = hWnd;
	map = LoadBitmap(hInstance, MAKEINTRESOURCE(IpBitmapName));

	// GetObject는 핸들로부터 펜, 브러시, 비트맵 등의 GDI 오브젝트 정보를 조사하는 함수인데
	// BITMAP 구조체의 bmWidth, bmHeight 멤버를 읽으면 비트맵 크기를 구할 수 있다
	GetObject(map, sizeof(BITMAP), &bit);
	bmWidth = bit.bmWidth;
	bmHeight = bit.bmHeight;

	hdc = GetDC(hWnd);
	MemDC = CreateCompatibleDC(hdc);
	BackDC = CreateCompatibleDC(hdc);
	Backmap = CreateCompatibleBitmap(hdc, WIN_WIGHT, WIN_HEIGHT);
}

void gBitmap::DrawBitmap(int x, int y)
{
	hPreBit = (HBITMAP)SelectObject(MemDC, map);

	BitBlt(hdc, x, y, bmWidth, bmHeight, MemDC, 0, 0, SRCCOPY);

	SelectObject(MemDC, hPreBit);
}

void gBitmap::DrawBitmap(int x, int y, int w, int h)
{
	hPreBit = (HBITMAP)SelectObject(MemDC, map);

	StretchBlt(hdc, 0, 0, w, h, MemDC, x, y, bmWidth, bmHeight, SRCCOPY);

	SelectObject(MemDC, hPreBit);
}

void gBitmap::Double_DrawBitmap(int x, int y)
{
	hPreBit = (HBITMAP)SelectObject(MemDC, Backmap);

	SelectObject(BackDC, map);

	BitBlt(MemDC, 0, 0, bmWidth, bmHeight, BackDC, 0, 0, SRCCOPY);

	BitBlt(hdc, x, y, bmWidth, bmHeight, MemDC, 0, 0, SRCCOPY);

	SelectObject(MemDC, hPreBit);
}

void gBitmap::Double_DrawBitmap(int x, int y, int w, int h)
{
	hPreBit = (HBITMAP)SelectObject(MemDC, Backmap);

	SelectObject(BackDC, map);

	//BitBlt(MemDC, x, y, bmWidth, bmHeight, BackDC, 0, 0, SRCCOPY);

	//BitBlt(hdc, x, y, bmWidth, bmHeight, MemDC, 0, 0, SRCCOPY);
	StretchBlt(MemDC, 0, 0, w, h, BackDC, x, y, bmWidth, bmHeight, SRCCOPY);
	//StretchBlt(MemDC, 0, 0, bmWidth, bmHeight, BackDC, x, y, w, h, SRCCOPY);

	BitBlt(hdc, x, y, WIN_WIGHT, WIN_HEIGHT, MemDC, 0, 0, SRCCOPY);
	//StretchBlt(hdc, 0, 0, w, h, MemDC, x, y, bmWidth, bmHeight, SRCCOPY);

	SelectObject(MemDC, hPreBit);
}

void gBitmap::DrawTransparentBlt(int x, int y, int r, int g, int b)
{
	hPreBit = (HBITMAP)SelectObject(MemDC, map);

	TransparentBlt(hdc, x, y, bmWidth, bmHeight, MemDC, 0, 0, bmWidth, bmHeight, RGB(r, g, b));

	SelectObject(MemDC, hPreBit);
}

void gBitmap::Double_DrawTransparentBlt(int x, int y, int r, int g, int b)
{
	hPreBit = (HBITMAP)SelectObject(MemDC, Backmap);

	SelectObject(BackDC, map);

	TransparentBlt(MemDC, x, y, bmWidth, bmHeight, BackDC, 0, 0, bmWidth, bmHeight, RGB(r, g, b));

	BitBlt(hdc, x, y, WIN_WIGHT, WIN_HEIGHT, MemDC, 0, 0, SRCCOPY);

	SelectObject(MemDC, hPreBit);
}

int gBitmap::GetWight()
{
	GetObject(map, sizeof(BITMAP), &bit);
	return bit.bmWidth;
}

int gBitmap::GetHeight()
{
	GetObject(map, sizeof(BITMAP), &bit);
	return bit.bmHeight;
}

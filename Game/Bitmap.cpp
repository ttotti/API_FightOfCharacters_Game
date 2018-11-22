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

	printf("Bitmap Ŭ���� �Ҹ�!\n");
	//system("pause");
}

void gBitmap::SetBitmap(HWND hWnd, HINSTANCE hInstance, int IpBitmapName)
{
	this->hWnd = hWnd;
	map = LoadBitmap(hInstance, MAKEINTRESOURCE(IpBitmapName));

	// GetObject�� �ڵ�κ��� ��, �귯��, ��Ʈ�� ���� GDI ������Ʈ ������ �����ϴ� �Լ��ε�
	// BITMAP ����ü�� bmWidth, bmHeight ����� ������ ��Ʈ�� ũ�⸦ ���� �� �ִ�
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

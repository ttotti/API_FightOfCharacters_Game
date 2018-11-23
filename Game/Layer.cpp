#include "Layer.h"

Layer::Layer()
{
	Init();
}

Layer::Layer(HWND hWnd)
{
	this->hWnd = hWnd;
	Init();
}

Layer::~Layer()
{
	DeleteImage();
}

void Layer::Init()
{
	hdc = GetDC(hWnd);
	MemDC = CreateCompatibleDC(hdc);
	BackDC = CreateCompatibleDC(hdc);
	BackImage = CreateCompatibleBitmap(hdc, WIN_WIGHT, WIN_HEIGHT);

	hPreBit = (HBITMAP)SelectObject(MemDC, BackImage);
}

void Layer::DeleteImage()
{
	SelectObject(MemDC, hPreBit);

	DeleteObject(BackDC);
	DeleteObject(BackImage);
	DeleteDC(MemDC);

	DeleteObject(Image);

	ReleaseDC(hWnd, hdc);
}

void Layer::Draw()
{
	BitBlt(hdc, 0, 0, WIN_WIGHT, WIN_HEIGHT, MemDC, 0, 0, SRCCOPY);

	DeleteImage();

	Init();
}

void Layer::Draw_BitBlt(gBitmap* bitmap)
{
	SelectObject(BackDC, bitmap->Getbitmap());

	BitBlt(MemDC, bitmap->get_X(), bitmap->get_Y(), bitmap->GetWidth(), bitmap->GetHeight(), BackDC, 0, 0, SRCCOPY);
}

void Layer::Draw_StretchBit(gBitmap* bitmap)
{
	SelectObject(BackDC, bitmap->Getbitmap());

	StretchBlt(MemDC, 0, 0, bitmap->get_W(), bitmap->get_H(), BackDC, bitmap->get_X(), bitmap->get_Y(), bitmap->GetWidth(), bitmap->GetHeight(), SRCCOPY);
}

void Layer::Draw_TransparentBlt(gBitmap* bitmap, int r, int g, int b)
{
	SelectObject(BackDC, bitmap->Getbitmap());

	TransparentBlt(MemDC, bitmap->get_X(), bitmap->get_Y(), bitmap->GetWidth(), bitmap->GetHeight(), BackDC, 0, 0, bitmap->GetWidth(), bitmap->GetHeight(), RGB(r, g, b));
}

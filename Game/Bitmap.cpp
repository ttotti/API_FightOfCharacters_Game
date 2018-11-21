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
	DeleteObject(map);
	printf("Bitmap Ŭ���� �Ҹ�!\n");
	//system("pause");
}

void gBitmap::SetBitmap(HWND hWnd, HINSTANCE hInstance, int IpBitmapName)
{
	this->hWnd = hWnd;
	map = LoadBitmap(hInstance, MAKEINTRESOURCE(IpBitmapName));
}

void gBitmap::DrawBitmap(int x, int y)
{
	hdc = GetDC(hWnd);

	DrawBitmap(hdc, x, y);

	ReleaseDC(hWnd, hdc);
}

void gBitmap::DrawBitmap(int x, int y, int w, int h)
{
	hdc = GetDC(hWnd);

	DrawBitmap(hdc, x, y, w, h);

	ReleaseDC(hWnd, hdc);
}

void gBitmap::DrawBitmap(HDC hdc, int x, int y)
{
	HDC MemDC;		    // �޸� DC
	HBITMAP oldBitmap;  // ������ ����
	int bx, by;         // ��Ʈ���� ũ�⸦ ������ ����

	MemDC = CreateCompatibleDC(hdc);
	oldBitmap = (HBITMAP)SelectObject(MemDC, map);

	// GetObject�� �ڵ�κ��� ��, �귯��, ��Ʈ�� ���� GDI ������Ʈ ������ �����ϴ� �Լ��ε�
	// BITMAP ����ü�� bmWidth, bmHeight ����� ������ ��Ʈ�� ũ�⸦ ���� �� �ִ�
	GetObject(map, sizeof(BITMAP), &bit);
	bx = bit.bmWidth;
	by = bit.bmHeight;

	BitBlt(hdc, x, y, bx, by, MemDC, 0, 0, SRCCOPY);

	SelectObject(MemDC, oldBitmap);
	DeleteDC(MemDC);
}

void gBitmap::DrawBitmap(HDC hdc, int x, int y, int w, int h)
{
	HDC MemDC;		    // �޸� DC
	HBITMAP oldBitmap;  // ������ ����
	int bx, by;         // ��Ʈ���� ũ�⸦ ������ ����

	MemDC = CreateCompatibleDC(hdc);
	oldBitmap = (HBITMAP)SelectObject(MemDC, map);

	// GetObject�� �ڵ�κ��� ��, �귯��, ��Ʈ�� ���� GDI ������Ʈ ������ �����ϴ� �Լ��ε�
	// BITMAP ����ü�� bmWidth, bmHeight ����� ������ ��Ʈ�� ũ�⸦ ���� �� �ִ�
	GetObject(map, sizeof(BITMAP), &bit);
	bx = bit.bmWidth;
	by = bit.bmHeight;

	StretchBlt(hdc, 0, 0, w, h, MemDC, x, y, bx, by, SRCCOPY);

	SelectObject(MemDC, oldBitmap);
	DeleteDC(MemDC);
}

void gBitmap::Double_DramBitmap(HDC hdc, int x, int y)
{
	HDC MemDC, BackDC;  // �޸� DC
	HBITMAP oldBitmap;  // ������ ����

	HBITMAP BackBitmap;

	int bx, by;         // ��Ʈ���� ũ�⸦ ������ ����

	GetObject(map, sizeof(BITMAP), &bit);
	bx = bit.bmWidth;
	by = bit.bmHeight;

	// hdc�� �׷� �ֱ� ���� �ʿ��� MemDC
	MemDC = CreateCompatibleDC(hdc);

	// �ӽ÷� �׸��� �׸��� ���� BackBitmap�� �����Ѵ�
	BackBitmap = CreateCompatibleBitmap(hdc, WIN_WIGHT, WIN_HEIGHT);
	// BackBitmap�� MemDC�� �־��ش�
	oldBitmap = (HBITMAP)SelectObject(MemDC, BackBitmap);

	// ���������� BackDC�� ������ �ش�
	BackDC = CreateCompatibleDC(hdc);
	// BackDC�� ���� �̹����� �����Ѵ�
	SelectObject(BackDC, map);

	// BackDC�� �ִ� �̹����� MemDC�� �ű��
	BitBlt(MemDC, 0, 0, bx, by, BackDC, 0, 0, SRCCOPY);

	// �� �� BackDC�� ����
	DeleteDC(BackDC);

	// ���������� MemDC�� �ִ� ���� hdc�� �ű��
	BitBlt(hdc, x, y, bx, by, MemDC, 0, 0, SRCCOPY);

	// �� �� MemDC ���������� ����
	SelectObject(MemDC, oldBitmap);

	// ���� ������ ����
	DeleteObject(BackBitmap);
	DeleteDC(MemDC);
}

void gBitmap::Double_DramBitmap(HDC hdc, int x, int y, int w, int h)
{
	HDC MemDC, BackDC;		    // �޸� DC
	HBITMAP oldBitmap;  // ������ ����

	HBITMAP BackBitmap;

	int bx, by;         // ��Ʈ���� ũ�⸦ ������ ����

	GetObject(map, sizeof(BITMAP), &bit);
	bx = bit.bmWidth;
	by = bit.bmHeight;

	MemDC = CreateCompatibleDC(hdc);

	BackBitmap = CreateCompatibleBitmap(hdc, WIN_WIGHT, WIN_HEIGHT);
	oldBitmap = (HBITMAP)SelectObject(MemDC, BackBitmap);

	BackDC = CreateCompatibleDC(hdc);
	SelectObject(BackDC, map);

	//StretchBlt(MemDC, 0, 0, bx, by, BackDC, x, y, w, h, SRCCOPY);
	BitBlt(MemDC, 0, 0, bx, by, BackDC, 0, 0, SRCCOPY);

	DeleteDC(BackDC);

	StretchBlt(hdc, 0, 0, w, h, MemDC, x, y, bx, by, SRCCOPY);

	SelectObject(MemDC, oldBitmap);

	DeleteObject(BackBitmap);
	DeleteDC(MemDC);
}

void gBitmap::DrawTransparentBlt(int x, int y, int r, int g, int b)
{
	hdc = GetDC(hWnd);

	DrawTransparentBlt(hdc, x, y, r, g, b);

	ReleaseDC(hWnd, hdc);
}

void gBitmap::DrawTransparentBlt(HDC hdc, int x, int y, int r, int g, int b)
{
	HDC MemDC;		    // �޸� DC
	HBITMAP oldBitmap;  // ������ ����
	int bx, by;         // ��Ʈ���� ũ�⸦ ������ ����

	MemDC = CreateCompatibleDC(hdc);
	oldBitmap = (HBITMAP)SelectObject(MemDC, map);

	// GetObject�� �ڵ�κ��� ��, �귯��, ��Ʈ�� ���� GDI ������Ʈ ������ �����ϴ� �Լ��ε�
	// BITMAP ����ü�� bmWidth, bmHeight ����� ������ ��Ʈ�� ũ�⸦ ���� �� �ִ�
	GetObject(map, sizeof(BITMAP), &bit);
	bx = bit.bmWidth;
	by = bit.bmHeight;

	TransparentBlt(hdc, x, y, bx, by, MemDC, 0, 0, bx, by, RGB(r, g, b));

	SelectObject(MemDC, oldBitmap);
	DeleteDC(MemDC);
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

#include "Bitmap.h"

Bitmap::Bitmap()
{
	hWnd = NULL;
	hdc = NULL;
	map = NULL;
}

Bitmap::~Bitmap()
{
	DeleteObject(map);
	printf("Bitmap Ŭ���� �Ҹ�!\n");
	system("pause");
}

void Bitmap::SetBitmap(HWND hWnd, HINSTANCE hInstance, int IpBitmapName)
{
	this->hWnd = hWnd;
	map = LoadBitmap(hInstance, MAKEINTRESOURCE(IpBitmapName));
}

void Bitmap::DramBitmap(int x, int y)
{
	hdc = GetDC(hWnd);

	DramBitmap(hdc, x, y);

	ReleaseDC(hWnd, hdc);
}

void Bitmap::DramBitmap(int x, int y, int w, int h)
{
	hdc = GetDC(hWnd);

	DramBitmap(hdc, x, y, w, h);

	ReleaseDC(hWnd, hdc);
}

void Bitmap::DramBitmap(HDC hdc, int x, int y)
{
	HDC MemDC;		    // �޸� DC
	HBITMAP oldBitmap;  // ������ ����
	int bx, by;         // ��Ʈ���� ũ�⸦ ������ ����
	BITMAP bit;         // BITMAP ����ü

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

void Bitmap::DramBitmap(HDC hdc, int x, int y, int w, int h)
{
	HDC MemDC;		    // �޸� DC
	HBITMAP oldBitmap;  // ������ ����
	int bx, by;         // ��Ʈ���� ũ�⸦ ������ ����
	BITMAP bit;         // BITMAP ����ü

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

void Bitmap::Double_DramBitmap(HDC hdc, int x, int y)
{
	HDC MemDC, BackDC;  // �޸� DC
	HBITMAP oldBitmap;  // ������ ����

	HBITMAP BackBitmap;

	int bx, by;         // ��Ʈ���� ũ�⸦ ������ ����
	BITMAP bit;         // BITMAP ����ü

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

void Bitmap::Double_DramBitmap(HDC hdc, int x, int y, int w, int h)
{
	HDC MemDC, BackDC;		    // �޸� DC
	HBITMAP oldBitmap;  // ������ ����

	HBITMAP BackBitmap;

	int bx, by;         // ��Ʈ���� ũ�⸦ ������ ����
	BITMAP bit;         // BITMAP ����ü

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

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
	printf("Bitmap 클래스 소멸!\n");
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
	HDC MemDC;		    // 메모리 DC
	HBITMAP oldBitmap;  // 해제용 변수
	int bx, by;         // 비트맵의 크기를 저장할 변수
	BITMAP bit;         // BITMAP 구조체

	MemDC = CreateCompatibleDC(hdc);
	oldBitmap = (HBITMAP)SelectObject(MemDC, map);

	// GetObject는 핸들로부터 펜, 브러시, 비트맵 등의 GDI 오브젝트 정보를 조사하는 함수인데
	// BITMAP 구조체의 bmWidth, bmHeight 멤버를 읽으면 비트맵 크기를 구할 수 있다
	GetObject(map, sizeof(BITMAP), &bit);
	bx = bit.bmWidth;
	by = bit.bmHeight;

	BitBlt(hdc, x, y, bx, by, MemDC, 0, 0, SRCCOPY);

	SelectObject(MemDC, oldBitmap);
	DeleteDC(MemDC);
}

void Bitmap::DramBitmap(HDC hdc, int x, int y, int w, int h)
{
	HDC MemDC;		    // 메모리 DC
	HBITMAP oldBitmap;  // 해제용 변수
	int bx, by;         // 비트맵의 크기를 저장할 변수
	BITMAP bit;         // BITMAP 구조체

	MemDC = CreateCompatibleDC(hdc);
	oldBitmap = (HBITMAP)SelectObject(MemDC, map);

	// GetObject는 핸들로부터 펜, 브러시, 비트맵 등의 GDI 오브젝트 정보를 조사하는 함수인데
	// BITMAP 구조체의 bmWidth, bmHeight 멤버를 읽으면 비트맵 크기를 구할 수 있다
	GetObject(map, sizeof(BITMAP), &bit);
	bx = bit.bmWidth;
	by = bit.bmHeight;

	StretchBlt(hdc, 0, 0, w, h, MemDC, x, y, bx, by, SRCCOPY);

	SelectObject(MemDC, oldBitmap);
	DeleteDC(MemDC);
}

void Bitmap::Double_DramBitmap(HDC hdc, int x, int y)
{
	HDC MemDC, BackDC;  // 메모리 DC
	HBITMAP oldBitmap;  // 해제용 변수

	HBITMAP BackBitmap;

	int bx, by;         // 비트맵의 크기를 저장할 변수
	BITMAP bit;         // BITMAP 구조체

	GetObject(map, sizeof(BITMAP), &bit);
	bx = bit.bmWidth;
	by = bit.bmHeight;

	// hdc에 그려 주기 위해 필요한 MemDC
	MemDC = CreateCompatibleDC(hdc);

	// 임시로 그림을 그리기 위해 BackBitmap을 생성한다
	BackBitmap = CreateCompatibleBitmap(hdc, WIN_WIGHT, WIN_HEIGHT);
	// BackBitmap을 MemDC에 넣어준다
	oldBitmap = (HBITMAP)SelectObject(MemDC, BackBitmap);

	// 마찬가지로 BackDC도 생성해 준다
	BackDC = CreateCompatibleDC(hdc);
	// BackDC에 실제 이미지를 삽입한다
	SelectObject(BackDC, map);

	// BackDC에 있는 이미지를 MemDC로 옮긴다
	BitBlt(MemDC, 0, 0, bx, by, BackDC, 0, 0, SRCCOPY);

	// 그 후 BackDC를 삭제
	DeleteDC(BackDC);

	// 마지막으로 MemDC에 있는 것을 hdc로 옮긴다
	BitBlt(hdc, x, y, bx, by, MemDC, 0, 0, SRCCOPY);

	// 그 후 MemDC 이전값으로 복원
	SelectObject(MemDC, oldBitmap);

	// 관련 데이터 삭제
	DeleteObject(BackBitmap);
	DeleteDC(MemDC);
}

void Bitmap::Double_DramBitmap(HDC hdc, int x, int y, int w, int h)
{
	HDC MemDC, BackDC;		    // 메모리 DC
	HBITMAP oldBitmap;  // 해제용 변수

	HBITMAP BackBitmap;

	int bx, by;         // 비트맵의 크기를 저장할 변수
	BITMAP bit;         // BITMAP 구조체

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

#pragma once

#include "Bitmap.h"

class MainScene
{
public:
	int M_x, M_y;

	Bitmap mainbitmap;
	Bitmap startbitmap,startbitmap2;

public:
	MainScene();
	MainScene(HINSTANCE g_hInst, HWND hWnd);
	~MainScene();

	void init(HINSTANCE g_hInst, HWND hWnd);

	void DrawBitmap();
	void MousePoint(int x, int y);
};
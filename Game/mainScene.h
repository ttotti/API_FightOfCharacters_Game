#pragma once

#include "Bitmap.h"

class mainScene
{
public:
	int M_x, M_y;

	Bitmap mainbitmap;
	Bitmap startbitmap,startbitmap2;

public:
	mainScene();
	~mainScene();

	void init(HINSTANCE g_hInst, HWND hWnd);

	void DrawBitmap();
	void MousePoint(int x, int y);
};
#pragma once

#include "Bitmap.h"
#include "Layer.h"

class MainScene :public Layer
{
public:
	int M_x, M_y;

	gBitmap* mainbitmap;
	gBitmap* startbitmap;
	gBitmap* startbitmap2;

public:
	MainScene();
	MainScene(HINSTANCE g_hInst, HWND hWnd);
	~MainScene();

	void init(HINSTANCE g_hInst, HWND hWnd);

	void DrawBitmap();
	void MousePoint(int x, int y);
};
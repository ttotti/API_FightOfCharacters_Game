#pragma once

#include "GameLoop.h"

#include "Layer.h"

class MainScene :public Layer
{
public:
	gBitmap* mainbitmap;
	gBitmap* startbitmap;
	gBitmap* startbitmap2;

public:
	MainScene();
	MainScene(HINSTANCE g_hInst, HWND hWnd);
	~MainScene();

	void init(HINSTANCE g_hInst, HWND hWnd);

	void DrawBitmap();
};
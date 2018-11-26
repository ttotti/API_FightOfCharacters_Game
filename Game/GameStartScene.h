#pragma once

//#include <Windows.h>

#include "Layer.h";

class GameStart :public Layer
{
public:
	gBitmap* gamemap;

public:
	GameStart();
	GameStart(HINSTANCE g_hInst, HWND hWnd);
	~GameStart();

	void DrawBitmap();
};

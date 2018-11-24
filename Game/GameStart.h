#pragma once

#include "Layer.h";

class GameStart :public Layer
{
public:
	GameStart();
	GameStart(HINSTANCE g_hInst, HWND hWnd);
	~GameStart();

	void DrawBitmap();
};

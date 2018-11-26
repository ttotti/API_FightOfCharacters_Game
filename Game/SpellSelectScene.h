#pragma once

#include "Layer.h"

class SpellSelectScene :public Layer
{
public:
	gBitmap* background;

public:
	SpellSelectScene();
	SpellSelectScene(HINSTANCE g_hInst,HWND hWnd);
	~SpellSelectScene();

	void DrawBitmap();
};
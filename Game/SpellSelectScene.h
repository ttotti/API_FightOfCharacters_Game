#pragma once

#include "Layer.h"
#include "GameLoop.h"

//template <typename T_Character>

class SpellSelectScene :public Layer
{
public:
	gBitmap* background;
	//T_Character d;

public:
	SpellSelectScene();
	SpellSelectScene(HINSTANCE g_hInst,HWND hWnd);
	~SpellSelectScene();

	void DrawBitmap();
};
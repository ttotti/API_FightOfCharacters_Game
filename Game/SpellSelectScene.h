#pragma once

#include "Layer.h"
#include "GameLoop.h"
#include "macro.h"

#include "Chirno.h"

class SpellSelectScene :public Layer
{
public:
	gBitmap* background;

	Chirno* chirno;

	int selectCharacter;

public:
	SpellSelectScene();
	SpellSelectScene(HINSTANCE g_hInst,HWND hWnd);
	~SpellSelectScene();

	void DrawBitmap();

	void setCharacter(int select);
};
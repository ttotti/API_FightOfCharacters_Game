#pragma once

#include "Layer.h"
#include "GameLoop.h"
#include "macro.h"

#include "Chirno.h"

class SpellSelectScene :public Layer
{
public:
	gBitmap* Home_bitmap;

	PNG_Image* background;

	PNG_Image* MovingUp;
	PNG_Image* MovingDown;
	PNG_Image* MovingLeft;
	PNG_Image* MovingRight;

	PNG_Image* LifeBar;
	PNG_Image* HPLife;
	PNG_Image* MPLife;

	Chirno* chirno;

	int selectCharacter;

public:
	SpellSelectScene();
	SpellSelectScene(HINSTANCE g_hInst,HWND hWnd);
	~SpellSelectScene();

	void DrawBitmap();

	void setCharacter(int select);
};
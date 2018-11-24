#pragma once

#include <Windows.h>

#include "Bitmap.h"
#include "Layer.h"
#include "GameLoop.h"

class CharacterSelect :public Layer
{
public:
	int selectCharacter;

	gBitmap* BG_bitmap;
	gBitmap* Home_bitmap;
	gBitmap* ClickHome_bitmap;

	gBitmap* chirnoface;
	gBitmap* hong_meiling;

public:
	CharacterSelect();
	CharacterSelect(HINSTANCE g_hInst, HWND hWnd);
	~CharacterSelect();

	void init(HINSTANCE g_hInst, HWND hWnd);

	void DrawBitmap();

	bool ClickCharacter();
};
#pragma once

#include "Layer.h"
#include "GameLoop.h"
#include "macro.h"

class CharacterSelect :public Layer
{
public:
	int selectCharacter;

	gBitmap* BG_bitmap;
	gBitmap* Home_bitmap;
	gBitmap* ClickHome_bitmap;

	gBitmap* hong_meiling;

	PNG_Image* p_chirnoface;

public:
	CharacterSelect();
	CharacterSelect(HINSTANCE g_hInst, HWND hWnd);
	~CharacterSelect();

	void init(HINSTANCE g_hInst, HWND hWnd);

	void DrawBitmap();

	bool ClickCharacter();
};
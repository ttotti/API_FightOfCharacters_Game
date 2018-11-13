#pragma once

#include <Windows.h>

#include "Bitmap.h"

class CharacterSelect
{
public:
	Bitmap BG_bitmap;

public:
	CharacterSelect();
	~CharacterSelect();

	void init(HINSTANCE g_hInst);
};
#pragma once

#include <Windows.h>
#include "Bitmap.h"

class CharacterSelect
{
public:
	Bitmap bitmap;

public:
	CharacterSelect();
	~CharacterSelect();

	void init();
};
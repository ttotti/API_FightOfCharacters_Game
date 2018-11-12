#pragma once

#include "Bitmap.h"

class mainScene
{
public:
	Bitmap mainbitmap;
	Bitmap startbitmap,startbitmap2;

public:
	mainScene();
	~mainScene();

	void init();
};
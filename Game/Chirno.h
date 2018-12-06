#pragma once

#include "Layer.h"

#define MAX_Card 4

class Chirno :public Layer
{
public:
	PNG_Image* ChirnoCard[MAX_Card];
	PNG_Image* ChirnoCard2;

public:
	Chirno();
	Chirno(HINSTANCE g_hInst, HWND hWnd);
	~Chirno();

	void init();
	void DrawBitmap();

	//void GetImage();
};
#pragma once

#include <Windows.h>
#include "Bitmap.h"
#include "CharacterSelect.h"
#include "mainScene.h"

#include "resource.h"

//#define WIN_WIGHT 1250
//#define WIN_HEIGHT 795

#define MAINSCENE 100
#define SELECTSCENE 101

class GameLoop
{
public:
	bool mousePoint;
	bool mouseClick;

	int selectMenu;

public:
	CharacterSelect Selectmap;
	mainScene mainScene;

public:
	Bitmap map; // Bitmap 클래스 변수

public:
	GameLoop();
	~GameLoop();

	void init(HINSTANCE g_hInst);
	void Loop(HDC hdc);
	void DrawStartBitmap(HDC hdc);
};
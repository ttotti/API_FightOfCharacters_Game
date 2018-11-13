#pragma once

#include <Windows.h>
#include "Bitmap.h"
#include "CharacterSelect.h"
#include "mainScene.h"

enum { MAINSCENE = 100, SELECTSCENE };

class GameLoop
{
public:
	bool mousePoint;
	bool mouseClick;

	int selectMenu;

	int M_x, M_y;

public:
	mainScene mainScene;
	CharacterSelect CharacterSelect;

public:
	Bitmap map; // Bitmap 클래스 변수

public:
	GameLoop();
	~GameLoop();

	void init(HINSTANCE g_hInst);
	void Loop();
	void DrawBitmap(HDC hdc);
};
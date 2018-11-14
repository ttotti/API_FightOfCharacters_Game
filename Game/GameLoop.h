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

	// 마우스 좌표 및 클릭 좌표
	int M_x, M_y, C_x, C_y;

public:
	mainScene mainScene;
	CharacterSelect CharacterSelect;

public:
	Bitmap map; // Bitmap 클래스 변수

public:
	GameLoop();
	~GameLoop();

	void init(HINSTANCE g_hInst,HWND hWnd);
	void Loop();
	void DrawBitmap(HDC hdc);
	void updata();
};
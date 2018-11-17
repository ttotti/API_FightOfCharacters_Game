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

	// ���콺 ��ǥ �� Ŭ�� ��ǥ
	int M_x, M_y, C_x, C_y;

public:
	MainScene* mainScene;
	CharacterSelect* characterSelect;

public:
	Bitmap map; // Bitmap Ŭ���� ����

public:
	GameLoop();
	~GameLoop();

	void init();
	//void Loop();
	void Loop(HINSTANCE g_hInst, HWND hWnd);
	//void DrawBitmap(HDC hdc);
	void updata();
};
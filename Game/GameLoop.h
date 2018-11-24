#pragma once

#include <Windows.h>
#include "Bitmap.h"
#include "mainScene.h"
#include "CharacterSelect.h"

// error C2143: ���� ���� : ';'��(��) '*' �տ� �����ϴ�
// �ذ�� ������ ���� class �� �������ش�
class MainScene;
class CharacterSelect;

enum { MAINSCENE = 100, SELECTSCENE };

class GameLoop
{
public:
	bool mousePoint;
	bool mouseClick;

	int selectMenu;

	static int M_x, M_y, C_x, C_y;

public:
	MainScene* mainScene;
	CharacterSelect* characterSelect;

public:
	gBitmap map; // Bitmap Ŭ���� ����

public:
	GameLoop();
	~GameLoop();

	void init();
	void Loop(HINSTANCE g_hInst, HWND hWnd);
};
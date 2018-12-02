#pragma once

#include <Windows.h>
#include "Bitmap.h"
#include "mainScene.h"
#include "CharacterSelect.h"
#include "GameStartScene.h"
#include "SpellSelectScene.h"

#include "macro.h"

//template <typename T_Character>

// error C2143: ���� ���� : ';'��(��) '*' �տ� �����ϴ�
// �ذ�� ������ ���� class �� �������ش�
class MainScene;
class CharacterSelect;
class GameStart;
class SpellSelectScene;

enum { MAINSCENE = 10000, SELECTSCENE, GAMESTARTSCENE, SPELLSELECTSCENE };

class GameLoop
{
public:
	bool mousePoint;
	bool mouseClick;

	int selectMenu;
	int character_number;

	static int M_x, M_y, C_x, C_y;

public:
	MainScene* mainScene;
	CharacterSelect* characterSelectScene;
	GameStart* gameStartScene;
	SpellSelectScene* spellSelectScene;

public:
	gBitmap map; // Bitmap Ŭ���� ����

public:
	GameLoop();
	~GameLoop();

	void init();
	void Loop(HINSTANCE g_hInst, HWND hWnd);
};
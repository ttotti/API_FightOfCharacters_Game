#pragma once

#include <Windows.h>
#include "Bitmap.h"
#include "mainScene.h"
#include "CharacterSelect.h"
#include "GameStartScene.h"
#include "SpellSelectScene.h"

#include "macro.h"

//template <typename T_Character>

// error C2143: 구문 오류 : ';'이(가) '*' 앞에 없습니다
// 해결법 다음과 같이 class 로 정의해준다
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
	gBitmap map; // Bitmap 클래스 변수

public:
	GameLoop();
	~GameLoop();

	void init();
	void Loop(HINSTANCE g_hInst, HWND hWnd);
};
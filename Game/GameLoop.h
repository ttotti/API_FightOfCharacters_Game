#pragma once

#include <Windows.h>
#include "Bitmap.h"
#include "mainScene.h"
#include "CharacterSelect.h"
#include "GameStart.h"

// error C2143: 구문 오류 : ';'이(가) '*' 앞에 없습니다
// 해결법 다음과 같이 class 로 정의해준다
class MainScene;
class CharacterSelect;
class GameStart;

enum { MAINSCENE = 100, SELECTSCENE, GAMESTART };

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
	GameStart* gameStart;

public:
	gBitmap map; // Bitmap 클래스 변수

public:
	GameLoop();
	~GameLoop();

	void init();
	void Loop(HINSTANCE g_hInst, HWND hWnd);
};
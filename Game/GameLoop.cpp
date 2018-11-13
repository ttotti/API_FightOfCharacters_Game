#include "GameLoop.h"

GameLoop::GameLoop()
{
	selectMenu = MAINSCENE;
}

GameLoop::~GameLoop()
{
}

void GameLoop::init(HINSTANCE g_hInst)
{
	map.SetBitmap(g_hInst, IDB_MAP);

	mainScene.init(g_hInst);
	CharacterSelect.init(g_hInst);
}

void GameLoop::Loop()
{
	switch (selectMenu)
	{
	case MAINSCENE:
		return;

	case SELECTSCENE:
		return;

	default:
		break;
	}
}

void GameLoop::DrawBitmap(HDC hdc)
{
	mainScene.mainbitmap.DramBitmap(hdc, 0, 0, WIN_WIGHT, WIN_HEIGHT);

	if (M_x >= 485 && M_x <= 752 && M_y >= 496 && M_y <= 629)
	{
		mainScene.startbitmap2.DramBitmap(hdc, WIN_WIGHT / 2 - 140, WIN_HEIGHT / 2 + 100);
	}
	else
	{
		mainScene.startbitmap.DramBitmap(hdc, WIN_WIGHT / 2 - 140, WIN_HEIGHT / 2 + 100);
	}
}

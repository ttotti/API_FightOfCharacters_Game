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

	mainScene.mainbitmap.SetBitmap(g_hInst, IDB_MAINSCENE);
	mainScene.startbitmap.SetBitmap(g_hInst, IDB_GAMESTART);
	mainScene.startbitmap2.SetBitmap(g_hInst, IDB_GAMESTART2);

	Selectmap.bitmap.SetBitmap(g_hInst, IDB_SELECT);
}

void GameLoop::Loop(HDC hdc)
{
	mainScene.mainbitmap.DramBitmap(hdc, 0, 0, WIN_WIGHT, WIN_HEIGHT);

	if (mousePoint)
	{
		mainScene.startbitmap2.DramBitmap(hdc, WIN_WIGHT / 2 - 140, WIN_HEIGHT / 2 + 100);
	}
	else
	{
		mainScene.startbitmap.DramBitmap(hdc, WIN_WIGHT / 2 - 140, WIN_HEIGHT / 2 + 100);
	}
}

void GameLoop::DrawStartBitmap(HDC hdc)
{
}

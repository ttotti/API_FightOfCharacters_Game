#include "mainScene.h"

mainScene::mainScene()
{
}

mainScene::~mainScene()
{
}

void mainScene::init(HINSTANCE g_hInst, HWND hWnd)
{
	mainbitmap.SetBitmap(hWnd, g_hInst, IDB_MAINSCENE);
	startbitmap.SetBitmap(hWnd, g_hInst, IDB_GAMESTART);
	startbitmap2.SetBitmap(hWnd, g_hInst, IDB_GAMESTART2);
}

void mainScene::DrawBitmap()
{
	mainbitmap.DramBitmap(0, 0, WIN_WIGHT, WIN_HEIGHT);

	if (M_x >= 485 && M_x <= 752 && M_y >= 496 && M_y <= 629)
	{
		startbitmap2.DramBitmap(WIN_WIGHT / 2 - 140, WIN_HEIGHT / 2 + 100);
	}
	else
	{
		startbitmap.DramBitmap(WIN_WIGHT / 2 - 140, WIN_HEIGHT / 2 + 100);
	}
}

void mainScene::MousePoint(int x, int y)
{
	M_x = x;
	M_y = y;
}

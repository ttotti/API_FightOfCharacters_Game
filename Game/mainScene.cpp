#include "mainScene.h"

MainScene::MainScene()
{
}

MainScene::MainScene(HINSTANCE g_hInst, HWND hWnd)
{
	mainbitmap.SetBitmap(hWnd, g_hInst, IDB_MAINSCENE);
	startbitmap.SetBitmap(hWnd, g_hInst, IDB_GAMESTART);
	startbitmap2.SetBitmap(hWnd, g_hInst, IDB_GAMESTART2);
}

MainScene::~MainScene()
{
}

void MainScene::init(HINSTANCE g_hInst, HWND hWnd)
{
	mainbitmap.SetBitmap(hWnd, g_hInst, IDB_MAINSCENE);
	startbitmap.SetBitmap(hWnd, g_hInst, IDB_GAMESTART);
	startbitmap2.SetBitmap(hWnd, g_hInst, IDB_GAMESTART2);
}

void MainScene::DrawBitmap()
{
	mainbitmap.DrawBitmap(0, 0, WIN_WIGHT, WIN_HEIGHT);

	if (M_x >= 485 && M_x <= 752 && M_y >= 496 && M_y <= 629)
	{
		startbitmap2.DrawBitmap(WIN_WIGHT / 2 - 140, WIN_HEIGHT / 2 + 100);
	}
	else
	{
		startbitmap.DrawBitmap(WIN_WIGHT / 2 - 140, WIN_HEIGHT / 2 + 100);
	}
}

void MainScene::MousePoint(int x, int y)
{
	M_x = x;
	M_y = y;
}

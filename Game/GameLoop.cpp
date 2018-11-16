#include "GameLoop.h"

GameLoop::GameLoop()
{
	selectMenu = MAINSCENE;
}

GameLoop::~GameLoop()
{
	delete mainScene;
	delete characterSelect;
}

void GameLoop::init(HINSTANCE g_hInst, HWND hWnd)
{
	//mainScene = new MainScene(g_hInst, hWnd);
	characterSelect = new CharacterSelect(g_hInst, hWnd);
	//mainScene->init(g_hInst, hWnd);
	//characterSelect->init(g_hInst, hWnd);
}

//void GameLoop::Loop()
//{
//	switch (selectMenu)
//	{
//	case MAINSCENE:
//		mainScene->DrawBitmap();
//
//		if (C_x >= 485 && C_x <= 752 && C_y >= 496 && C_y <= 629)
//		{
//			selectMenu = SELECTSCENE;
//		}
//
//		return;
//
//	case SELECTSCENE:
//		characterSelect->DrawBitmap();
//		printf("SELECTSCENE\n");
//		return;
//
//	default:
//		break;
//	}
//}

void GameLoop::Loop(HINSTANCE g_hInst, HWND hWnd)
{
	switch (selectMenu)
	{
	case MAINSCENE:
		mainScene = new MainScene(g_hInst, hWnd);

		mainScene->DrawBitmap();

		if (C_x >= 485 && C_x <= 752 && C_y >= 496 && C_y <= 629)
		{
			selectMenu = SELECTSCENE;
			delete mainScene;
		}

		return;

	case SELECTSCENE:
		characterSelect->DrawBitmap();
		printf("SELECTSCENE\n");
		return;

	default:
		break;
	}
}

//void GameLoop::DrawBitmap(HDC hdc)
//{
//	if (selectMenu == MAINSCENE)
//	{
//		mainScene->mainbitmap.DramBitmap(hdc, 0, 0, WIN_WIGHT, WIN_HEIGHT);
//
//		if (M_x >= 485 && M_x <= 752 && M_y >= 496 && M_y <= 629)
//		{
//			mainScene->startbitmap2.DramBitmap(hdc, WIN_WIGHT / 2 - 140, WIN_HEIGHT / 2 + 100);
//		}
//		else
//		{
//			mainScene.startbitmap.DramBitmap(hdc, WIN_WIGHT / 2 - 140, WIN_HEIGHT / 2 + 100);
//
//		}
//	}
//	else
//	{
//
//	}
//}

void GameLoop::updata()
{
	mainScene->MousePoint(M_x, M_y);
	characterSelect->MousePoint(M_x, M_y);
}

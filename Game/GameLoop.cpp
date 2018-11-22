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

void GameLoop::init()
{
	mainScene = NULL;
	characterSelect = NULL;

	//mainScene = new MainScene(g_hInst, hWnd);
	//characterSelect = new CharacterSelect(g_hInst, hWnd);
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
		if (mainScene == NULL)
		{
			mainScene = new MainScene(g_hInst, hWnd);
		}

		mainScene->MousePoint(M_x, M_y);

		mainScene->DrawBitmap();

		if (C_x >= 485 && C_x <= 752 && C_y >= 496 && C_y <= 629)
		{
			selectMenu = SELECTSCENE;
			delete mainScene;
			mainScene = NULL;
		}

		break;

	case SELECTSCENE:
		if (characterSelect == NULL)
		{
			characterSelect = new CharacterSelect(g_hInst, hWnd);
		}

		characterSelect->MousePoint(M_x, M_y);

		characterSelect->DrawBitmap();

		if (C_x >= 50 && C_x <= characterSelect->Home_bitmap.GetWight() + 50 && C_y >= 666 && C_y <= characterSelect->Home_bitmap.GetHeight() + 666)
		{
			selectMenu = MAINSCENE;
			delete characterSelect;
			characterSelect = NULL;
		}

		printf("SELECTSCENE\n");
		break;

	default:
		return;
	}

	//printf("switch Å»Ãâ!!\n");
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

//void GameLoop::updata()
//{
//}

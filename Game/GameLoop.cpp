#include "GameLoop.h"

int GameLoop::M_x = 0;
int GameLoop::M_y = 0;
int GameLoop::C_x = 0;
int GameLoop::C_y = 0;

GameLoop::GameLoop()
{
	selectMenu = MAINSCENE;
}

GameLoop::~GameLoop()
{
	delete mainScene;
	delete characterSelect;
	delete gameStart;
}

void GameLoop::init()
{
	mainScene = NULL;
	characterSelect = NULL;
	gameStart = NULL;
}

void GameLoop::Loop(HINSTANCE g_hInst, HWND hWnd)
{
	switch (selectMenu)
	{
	case MAINSCENE:
		if (mainScene == NULL)
		{
			mainScene = new MainScene(g_hInst, hWnd);
		}

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

		characterSelect->DrawBitmap();

		if (characterSelect->ClickCharacter())
		{
			selectMenu = GAMESTART;
			break;
		}

		if (C_x >= 50 && C_x <= characterSelect->Home_bitmap->GetWidth() + 50 && C_y >= 666 && C_y <= characterSelect->Home_bitmap->GetHeight() + 666)
		{
			selectMenu = MAINSCENE;
			delete characterSelect;
			characterSelect = NULL;
		}

		//printf("SELECTSCENE\n");
		break;

	case GAMESTART:
		if (gameStart == NULL)
		{
			gameStart = new GameStart(g_hInst, hWnd);
		}

		gameStart->DrawBitmap();

		break;

	default:
		return;
	}

	//printf("switch ≈ª√‚!!\n");
}
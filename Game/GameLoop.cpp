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
	delete characterSelectScene;
	delete gameStartScene;
	delete spellSelectScene;

	printf("GameLoop ≈¨∑°Ω∫ º“∏Í!\n");
}

void GameLoop::init()
{
	mainScene = NULL;
	characterSelectScene = NULL;
	gameStartScene = NULL;
	spellSelectScene = NULL;
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
		if (characterSelectScene == NULL)
		{
			characterSelectScene = new CharacterSelect(g_hInst, hWnd);
		}

		characterSelectScene->DrawBitmap();

		if (characterSelectScene->ClickCharacter())
		{
			selectMenu = SPELLSELECTSCENE;

			character_number = characterSelectScene->selectCharacter;

			delete characterSelectScene;
			characterSelectScene = NULL;

			break;
		}

		if (C_x >= 50 && C_x <= characterSelectScene->Home_bitmap->GetWidth() + 50 && C_y >= 666 && C_y <= characterSelectScene->Home_bitmap->GetHeight() + 666)
		{
			selectMenu = MAINSCENE;

			delete characterSelectScene;
			characterSelectScene = NULL;
		}

		//printf("SELECTSCENE\n");
		break;

	case SPELLSELECTSCENE:
		if (spellSelectScene == NULL)
		{
			spellSelectScene = new SpellSelectScene(g_hInst, hWnd);
		}

		spellSelectScene->setCharacter(character_number);
		spellSelectScene->DrawBitmap();

		break;

	case GAMESTARTSCENE:
		if (gameStartScene == NULL)
		{
			gameStartScene = new GameStart(g_hInst, hWnd);
		}

		gameStartScene->DrawBitmap();

		break;

	default:
		return;
	}

	//printf("switch ≈ª√‚!!\n");
}
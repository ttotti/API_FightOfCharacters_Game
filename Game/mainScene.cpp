#include "mainScene.h"

MainScene::MainScene()
{
}

MainScene::MainScene(HINSTANCE g_hInst, HWND hWnd)
	:Layer(g_hInst, hWnd)
{
	mainbitmap = new gBitmap;
	startbitmap = new gBitmap;
	startbitmap2 = new gBitmap;

	mainbitmap->SetBitmap(hWnd, g_hInst, IDB_MAINSCENE);
	startbitmap->SetBitmap(hWnd, g_hInst, IDB_GAMESTART);
	startbitmap2->SetBitmap(hWnd, g_hInst, IDB_GAMESTART2);
}

MainScene::~MainScene()
{
	delete mainbitmap;
	delete startbitmap;
	delete startbitmap2;

	mainbitmap = NULL;
	startbitmap = NULL;
	startbitmap2 = NULL;

	printf("MainScene Å¬·¡½º ¼Ò¸ê!\n");
}

void MainScene::init(HINSTANCE g_hInst, HWND hWnd)
{
}

void MainScene::DrawBitmap()
{
	mainbitmap->set_AllPoint(0, 0, WIN_WIGHT, WIN_HEIGHT);
	this->Draw_StretchBit(mainbitmap);

	if (GameLoop::M_x >= 485 && GameLoop::M_x <= 752 && GameLoop::M_y >= 496 && GameLoop::M_y <= 629)
	{
		startbitmap2->set_X(WIN_WIGHT / 2 - 140);
		startbitmap2->set_Y(WIN_HEIGHT / 2 + 100);
		this->Draw_BitBlt(startbitmap2);
	}
	else
	{
		startbitmap->set_X(WIN_WIGHT / 2 - 140);
		startbitmap->set_Y(WIN_HEIGHT / 2 + 100);
		this->Draw_BitBlt(startbitmap);
	}

	this->Draw();
}
